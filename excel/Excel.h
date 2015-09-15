#ifndef __EXCEL_H__
#define __EXCEL_H__

#include <stdint.h>
#include <buffer.h>

namespace excel
{
	struct Excel
	{
		uint32_t Init( iBuffer * _pBuffer);
	};
}

#endif // __EXCEL_H__
