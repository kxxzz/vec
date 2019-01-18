#pragma once


#include <stdbool.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>


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


#define vec_t(T) struct { T* data; u32 length, capacity; }


#define vec_free(a) (free((a)->data)) 
#define vec_clear(a) ((a)->length = 0)


#define vec_sort(a, fn)\
    qsort((a)->data, (a)->length, sizeof(*(a)->data), fn)


#define vec_reserve(a, n)\
    do {\
        if (n > (a)->capacity)\
        {\
            vec_realloc_((void**)&(a)->data, n*sizeof((a)->data[0]));\
            (a)->capacity = n;\
        }\
    } while (0)


#define vec_resize(a, n)\
    do {\
        if (n > (a)->capacity)\
        {\
            vec_realloc_((void**)&(a)->data, n*sizeof((a)->data[0]));\
            (a)->capacity = n;\
        }\
        (a)->length = n;\
    } while (0)


#define vec_push(a, e)\
    do {\
        if ((a)->length + 1 > (a)->capacity)\
        {\
            int n = !(a)->capacity ? 1 : (a)->capacity << 1;\
            vec_realloc_((void**)&(a)->data, n*sizeof((a)->data[0]));\
            (a)->capacity = n;\
        }\
        (a)->data[(a)->length] = (e);\
        ++(a)->length;\
    } while (0)


#define vec_pop(a)\
    vec_resize((a), (a)->length - 1)


#define vec_last(a)\
    (a)->data[(a)->length - 1]


#define vec_dup(a, b)\
    do {\
        if ((b)->length > (a)->capacity)\
        {\
            (a)->capacity = (b)->length;\
            vec_realloc_((void**)&(a)->data, (a)->capacity*sizeof((a)->data[0]));\
        }\
        memcpy((a)->data, (b)->data, (b)->length*sizeof((a)->data[0]));\
        (a)->length = (b)->length;\
    } while (0)


#define vec_pusharr(a, arr, count)\
    do {\
        u32 c = (count);\
        u32 capacity0 = (a)->capacity;\
        while ((a)->length + c > (a)->capacity)\
        {\
            (a)->capacity = !(a)->capacity ? 1 : (a)->capacity << 1;\
        }\
        if ((a)->capacity != capacity0)\
        {\
            vec_realloc_((void**)&(a)->data, (a)->capacity*sizeof((a)->data[0]));\
        }\
        for (u32 i = 0; i < c; ++i)\
        {\
            (a)->data[(a)->length + i] = (arr)[i];\
        }\
        (a)->length += c;\
    } while (0)


#define vec_concat(a, b) vec_pusharr((a), (b)->data, (b)->length)



#define vec_insert(a, p, e)\
    do {\
        u32 esize = sizeof((a)->data[0]);\
        if ((a)->length + 1 > (a)->capacity)\
        {\
            int n = !(a)->capacity ? 1 : (a)->capacity << 1;\
            vec_realloc_((void**)&(a)->data, n*esize);\
            (a)->capacity = n;\
        }\
        memmove((a)->data + ((p) + 1), (a)->data + (p), ((a)->length - (p)) * esize);\
        (a)->data[(p)] = (e);\
        ++(a)->length;\
    } while (0)







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






































































