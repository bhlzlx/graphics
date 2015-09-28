#ifndef MEMORYPOOL_H_INCLUDED
#define MEMORYPOOL_H_INCLUDED

#define MEM_POOL_ALIGN 4

#include <cstdlib>
#include <cstdio>

namespace ow
{
    struct MemoryBlock
    {
        unsigned short  m_nFree;
        unsigned short  m_nHead;
        MemoryBlock *   m_pNext;
        char        *   m_pEnd;
        char            m_data[0];
    };

    struct SMemPool
    {
        unsigned short                 m_nUnitCount;
        unsigned short                 m_nUnitSize;
        ow::MemoryBlock*           m_pHeadNode;

        SMemPool(unsigned short nUnitCount,unsigned short nUnitSize);
        ~SMemPool();

        static MemoryBlock * CreateMemoryBlock(unsigned short _nUnitCount,unsigned short _nUnitSize);
        static void DestroyMemoryBlock(MemoryBlock * p);

        void * Alloc(size_t _size);
        void   Recycle(void *p);
    };
};

#endif // MEMORYPOOL_H_INCLUDED
