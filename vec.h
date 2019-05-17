#pragma once



#include <stdbool.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>



typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef float f32;
typedef double f64;





void vec_realloc_(void** pBuf, u32 size);
void vec_sort_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, int(*fn)(const void*, const void*));
void vec_reserve_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 n);
void vec_resize_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 n);
void vec_push_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize);
void vec_dup_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, const void* srcData, u32 srcLength);
void vec_pusharr_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, const void* srcData, u32 srcLength);
void vec_insert_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 p);
void vec_insertarr_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize, u32 p, const void* srcData, u32 srcLength);
void vec_shrink_to_fit_(void** pData, u32* pLength, u32* pCapacity, u32 elmSize);




#define vec_t(T) struct { T* data; u32 length, capacity; }


#define vec_free(a) (free((a)->data)) 
#define vec_clear(a) ((a)->length = 0)


#define vec_sort(a, fn)\
    vec_sort_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (fn))


#define vec_reserve(a, n)\
    vec_reserve_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (n))


#define vec_resize(a, n)\
    vec_resize_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (n))


#define vec_push(a, e)\
    do {\
        vec_push_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data));\
        (a)->data[(a)->length - 1] = (e);\
    } while (0)


#define vec_pop(a)\
    vec_resize((a), (a)->length - 1)


#define vec_last(a)\
    (a)->data[(a)->length - 1]


#define vec_dup(a, b)\
    vec_dup_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (b)->data, (b)->length)


#define vec_pusharr(a, arr, count)\
    vec_pusharr_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (arr), (count))


#define vec_concat(a, b) vec_pusharr((a), (b)->data, (b)->length)


#define vec_insert(a, p, e)\
    do {\
        vec_insert_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (p)); \
        (a)->data[(p)] = (e);\
    } while (0)



#define vec_insertarr(a, p, arr, count)\
    vec_insertarr_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data), (p), (arr), (count))



#define vec_shrink_to_fit(a)\
    vec_shrink_to_fit_((void**)&(a)->data, &(a)->length, &(a)->capacity, sizeof(*(a)->data))







typedef vec_t(s8) vec_s8;
typedef vec_t(s16) vec_s16;
typedef vec_t(s32) vec_s32;
typedef vec_t(s64) vec_s64;
typedef vec_t(u8) vec_u8;
typedef vec_t(u16) vec_u16;
typedef vec_t(u32) vec_u32;
typedef vec_t(u64) vec_u64;

typedef vec_t(f32) vec_f32;
typedef vec_t(f64) vec_f64;

typedef vec_t(char) vec_char;
typedef vec_t(void*) vec_ptr;






































































