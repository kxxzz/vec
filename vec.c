#include "vec.h"




void vec_realloc_(void** pData, u32 size)
{
    *pData = realloc(*pData, size);
}





void vec_sort_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, int(*fn)(const void*, const void*))
{
    qsort(*pData, *pLength, elmSize, fn);
}



void vec_reserve_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 n)
{
    if (n > *pCapacity)
    {
        vec_realloc_(pData, n * elmSize);
        *pCapacity = n;
    }
}



void vec_resize_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 n)
{
    if (n > *pCapacity)
    {
        vec_realloc_(pData, n * elmSize);
        *pCapacity = n;
    }
    *pLength = n;
}



void vec_push_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize)
{
    if (*pLength + 1 > *pCapacity)
    {
        int n = !*pCapacity ? 1 : *pCapacity << 1;
        vec_realloc_(pData, n * elmSize);
        *pCapacity = n;
    }
    ++pLength;
}



void vec_dup_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, const void* srcData, u32 srcLength)
{
    if (srcLength > *pCapacity)
    {
        *pCapacity = srcLength;
        vec_realloc_(pData, *pCapacity * elmSize);
    }
    memcpy(*pData, srcData, srcLength * elmSize);
    *pLength = srcLength;
}



void vec_pusharr_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, const void* srcData, u32 srcLength)
{
    u32 capacity0 = *pCapacity;
    while (*pLength + srcLength > *pCapacity)
    {
        u32 n = !*pCapacity ? 1 : *pCapacity << 1;
        *pCapacity = n;
    }
    if (*pCapacity != capacity0)
    {
        vec_realloc_(pData, *pCapacity*elmSize);
    }
    memcpy((char*)*pData + *pLength*elmSize, srcData, srcLength*elmSize);
    *pLength += srcLength;
}



void vec_insert_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 p)
{
    if (*pLength + 1 > *pCapacity)
    {
        u32 n = !*pCapacity ? 1 : *pCapacity << 1;
        vec_realloc_(pData, n*elmSize);
        *pCapacity = n;
    }
    char* t = (char*)*pData + p * elmSize;
    memmove(t + elmSize, t, (*pLength - p) * elmSize);
    ++*pLength;
}



void vec_insertarr_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 p, const void* srcData, u32 srcLength)
{
    u32 capacity0 = *pCapacity;
    while (*pLength + srcLength > *pCapacity)
    {
        u32 n = !*pCapacity ? 1 : *pCapacity << 1;
        *pCapacity = n;
    }
    if (*pCapacity != capacity0)
    {
        vec_realloc_(pData, *pCapacity*elmSize);
    }
    char* t = (char*)*pData + p * elmSize;
    memmove(t + srcLength * elmSize, t, (*pLength - p) * elmSize);
    memcpy(t, srcData, srcLength*elmSize);
    *pLength += srcLength;
}



void vec_shrink_to_fit_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize)
{
    if (*pLength > 0)
    {
        vec_realloc_(pData, *pLength * elmSize);
    }
    else
    {
        free(*pData);
        *pData = NULL;
    }
    *pCapacity = *pLength;
}
















































































