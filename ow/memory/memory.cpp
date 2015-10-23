#include "memory.h"
#include <cassert>

namespace ow
{
    MemoryBlock * SMemPool::CreateMemoryBlock(unsigned short _nUnitCount,unsigned short _nUnitSize)
    {
        MemoryBlock * pBlock = (MemoryBlock*)::operator new(sizeof(MemoryBlock)+_nUnitCount * _nUnitSize);
        pBlock->m_nFree = _nUnitCount;
        pBlock->m_nHead = 0;
        pBlock->m_pNext = NULL;
        pBlock->m_pEnd = &pBlock->m_data[0];
        for(unsigned short i = 0;i<_nUnitCount-1;i++)
        {
            *(unsigned short*)pBlock->m_pEnd = i+1;
            pBlock->m_pEnd += _nUnitSize;
        }
        pBlock->m_pEnd  = &pBlock->m_data[0]+_nUnitCount * _nUnitSize;
        return pBlock;
    }

    void SMemPool::DestroyMemoryBlock(MemoryBlock * p)
    {
        ::operator delete(p);
    }

    SMemPool::SMemPool(unsigned short nUnitCount,unsigned short nUnitSize)
    {
        this->m_nUnitCount = nUnitCount;
        this->m_pHeadNode = NULL;
        //this->m_nUnitSize  = nUnitSize;
        if(nUnitSize > 4)
        {
            m_nUnitSize = (nUnitSize + MEM_POOL_ALIGN -1)&~(MEM_POOL_ALIGN-1);
        }
        else if(nUnitSize == 4)
        {
            m_nUnitSize = 4;
        }
        else
        {
            m_nUnitSize = 2;
        }
    }

    SMemPool::~SMemPool()
    {
        MemoryBlock * pEnum = NULL;
        while(this->m_pHeadNode)
        {
            pEnum = this->m_pHeadNode;
            this->m_pHeadNode = pEnum->m_pNext;
            SMemPool::DestroyMemoryBlock(pEnum);
        }
    }

    void * SMemPool::Alloc(size_t _size)
    {
        if(_size> this->m_nUnitSize)
        {
            return NULL;
        }
        else
        {
            char * pAlloc = NULL;
            MemoryBlock * pEnum = this->m_pHeadNode;
            if(!pEnum)
            {
                pEnum = this->m_pHeadNode = SMemPool::CreateMemoryBlock(m_nUnitCount,m_nUnitSize);
            }
            while(!pAlloc)
            {
                if(pEnum->m_nFree > 0)
                {
                    pAlloc = &pEnum->m_data[0] + m_nUnitSize * pEnum->m_nHead;
                    --pEnum->m_nFree;
                    pEnum->m_nHead = *(unsigned short *)pAlloc;
                    return pAlloc;
                }
                else
                {
                    if(!pEnum->m_pNext)
                    {
                        break;
                    }
                    pEnum = pEnum->m_pNext;
                }
            }
            pEnum->m_pNext = SMemPool::CreateMemoryBlock(this->m_nUnitCount,this->m_nUnitSize);
            pEnum->m_pNext->m_nFree--;
            pEnum->m_pNext->m_nHead = 1;
            return &pEnum->m_pNext->m_data[0];
        }
    }

    bool SMemPool::Recycle(void * p)
    {
        assert(m_pHeadNode);
        if(!m_pHeadNode)
        {
            return false;
        }
        MemoryBlock * pLast = NULL;
        MemoryBlock * pEnum = m_pHeadNode;
        while(pEnum)
        {
            // ÅÐ¶ÏµØÖ·ÔÚ²»ÔÚ·¶Î§ÄÚ
            if(p >= &pEnum->m_data[0] && p<pEnum->m_pEnd )
            {
                unsigned int diff = (char *)p - &pEnum->m_data[0];
                unsigned short nIndex = diff / m_nUnitSize;
                *(unsigned short *) p = pEnum->m_nHead;
                pEnum->m_nHead = nIndex;
                pEnum->m_nFree++;
                //»ØÊÕÕâ¿éÄÚ´æBlock
                if(pEnum->m_nFree == this->m_nUnitCount)
                {
                    if(pLast)
                    {
                        pLast->m_pNext = pEnum->m_pNext;
                    }
                    else
                    {
                        this->m_pHeadNode = pEnum->m_pNext;
                    }
                    SMemPool::DestroyMemoryBlock(pEnum);
                }
                return true;
            }
            pLast = pEnum;
            pEnum = pEnum->m_pNext;
        }
        return false;
    }
}
