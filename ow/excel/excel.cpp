#include "excel.h"
#include <assert.h>
#include <memory.h>

using namespace ow;

namespace ow
{
	namespace excel
	{
		owBufferRef ReadBufferLine( owBuffer * _pTableBuffer)
		{
			owBYTE * pSet = _pTableBuffer->GetCurr();
			owCHAR * pEnd = (owCHAR*)pSet;
			owCHAR * pBuffeEnd = (owCHAR*)_pTableBuffer->GetBuffer() + _pTableBuffer->Size();
			while(pEnd < pBuffeEnd)
			{
				if(*pEnd == '\r' && *(pEnd+1)=='\n')
				{
					owINT32 length = (owBYTE*)pEnd - pSet;
					_pTableBuffer->Seek( SEEK_CUR, length + 2);
					return owBufferRef( pSet, length);
				}
				pEnd++;
			}
			owINT32 length = (owBYTE*)pEnd - pSet;
			_pTableBuffer->Seek( SEEK_CUR, length);
			return owBufferRef(pSet, length);
		}
		
		owBufferRef ReadBufferCell( owBufferRef * _pLine )
		{
			owBYTE * pSet = _pLine->GetCurr();
			owCHAR * pEnd = (owCHAR*)pSet;
			owCHAR * pBufferEnd = (owCHAR*)_pLine->GetBuffer() + _pLine->Size();
			while(pEnd < pBufferEnd)
			{
				if( *pEnd == '\t')
				{
					owINT32 length = (owBYTE *)pEnd - pSet;
					_pLine->Seek(SEEK_CUR, length + 1);
					return owBufferRef( pSet, length);
				}
				pEnd++;
			}
			owINT32 length = (owBYTE*)pEnd - pSet;
			_pLine->Seek( SEEK_CUR, length);
			return owBufferRef(pSet, length);
		}
		
		owINT32 ExcelHeap::CELL_SIZE_MIN = 8;
		owINT32 ExcelHeap::CELL_SIZE_MAX = 2048;
		
		owVOID ExcelHeap::InitHeap()
		{
			owINT32 nUnitSize = CELL_SIZE_MIN;
			while(nUnitSize <= CELL_SIZE_MAX)
			{
				SMemPool * pNewPool = new SMemPool( 64, nUnitSize);
				nUnitSize*=2;
				m_vec_pool.push_back( pNewPool);
			}
		}
		
		owVOID ExcelHeap::ReleaseHeap()
		{
			for( auto pool : m_vec_pool)
			{
				delete pool;
				m_vec_pool.clear();
			}
		}
		
		owVOID * ExcelHeap::alloc( owUINT32 _nSize )
		{
			owVOID * pAlloc = NULL;
			for( auto pool : m_vec_pool )
			{
				pAlloc = pool->Alloc( _nSize );
				if( pAlloc )
				{
					break;
				}
			}
			return pAlloc;
		}
		
		owVOID ExcelHeap::dealloc( owVOID * _pPtr )
		{
			for( auto pool : m_vec_pool )
			{
				bool ret = pool->Recycle( _pPtr);
				if( ret == true )
				{
					break;
				}
			}
			return;
		}
		
		std::vector< ow::SMemPool* > ExcelHeap::m_vec_pool;
		
		
		excel_manager::excel_manager()
		{
		}
		
		owBOOL excel_manager::Init()
		{
			init_excel_manager();
			for( auto &p : m_tableMap)
			{
				p.second->m_init_func( p.second );
			}
			return owTRUE;
		}
		
		owBOOL excel_manager::PushTable( ow::owBuffer * _pBuffer, const char * _szName )
		{
			excel_table_info * pTableInfo = this->m_tableMap[_szName];
			if(pTableInfo == NULL)
			{
				return owFALSE;
			}
			_pBuffer->Seek( SEEK_CUR, 0);
			// 跳过表头
			// 先不验证表头了
			ReadBufferLine( _pBuffer );
			// 读取内容数据
			owCHAR valueBuff[512];
			while( _pBuffer->Eof() == owFALSE )
			{
				ow::owBufferRef lineBuffer = ReadBufferLine( _pBuffer );
				void * lineObject = pTableInfo->m_insert_func( pTableInfo->m_pTable);
				for( value_info& vInfo : pTableInfo->m_typeInfo)
				{
					ow::owBufferRef cellBuffer = ReadBufferCell( &lineBuffer );
					switch(vInfo.vType)
					{
						case type_int:
						{
							assert( cellBuffer.Size() < 512 );
							int value = 0;
							if(cellBuffer.Eof() == owFALSE)
							{
								memcpy( valueBuff, cellBuffer.GetBuffer(), cellBuffer.Size() );
								valueBuff[cellBuffer.Size()] = 0;
								sscanf(valueBuff,"%d", &value);
							}
							memdata_set(lineObject, vInfo.vOffset, value );
							break;
						}
						case type_float:
						{
							assert( cellBuffer.Size() < 512 );
							float value = 0.0f;
							if(cellBuffer.Eof() == owFALSE)
							{
								memcpy( valueBuff, cellBuffer.GetBuffer(), cellBuffer.Size() );
								valueBuff[cellBuffer.Size()] = 0;
								sscanf(valueBuff,"%f", &value);
							}
							memdata_set(lineObject, vInfo.vOffset, value );
							break;
						}
						case type_string:
						{
							// if it's string, alloc from excel string heap~
							owVOID * szValue = NULL;
							if(cellBuffer.Eof() == owFALSE)
							{
#ifdef EXCEL_USE_UNICODE
								owUINT16 * szUnicodeBuff = (owUINT16 *)ExcelHeap::alloc( cellBuffer.Size() * 2);
								owUINT32 nConv = UTF82Unicode(
												(owUINT16*)cellBuffer.GetBuffer(),
												cellBuffer.Size(),
												(owUINT16*)szUnicodeBuff,
												cellBuffer.Size()*2
												);
								szValue = ExcelHeap::alloc( (nConv + 1) * 2);
								memset( szValue, 0, (nConv+1) * 2);
								memcpy( szValue, szUnicodeBuff, nConv * 2 );
								ExcelHeap::dealloc( szUnicodeBuff);
#else
								szValue = ExcelHeap::alloc( cellBuffer.Size() + 2);
								memset(szValue, 0, cellBuffer.Size() + 2);
								memcpy( szValue, cellBuffer.GetBuffer(), cellBuffer.Size() );
								//printf("%s",cellBuffer.GetBuffer());
#endif
							}
							memdata_set(lineObject, vInfo.vOffset, szValue);
							break;
						}
					}
				}
			}
			return owTRUE;
		}
		
		owBOOL excel_manager::Clear()
		{
			clear_excel_manager();
			return owTRUE;
		}
		
		excel_manager::~excel_manager()
		{
		}
	}
}
