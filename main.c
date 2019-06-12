#include <stdlib.h>
#ifdef _WIN32
# include <crtdbg.h>
#endif



#include <stdio.h>
#include <assert.h>

#include "vec.h"




#ifdef ARYLEN
# undef ARYLEN
#endif
#define ARYLEN(a) (sizeof(a) / sizeof((a)[0]))




static void test(void)
{
    vec_t(int) a = { 0 };

    for (int i = 0; i < 100; ++i)
    {
        vec_push(&a, i);
    }
    assert(100 == a.length);
    assert(128 == a.capacity);
    for (int i = 0; i < 100; ++i)
    {
        assert(a.data[i] == i);
    }
    vec_resize(&a, 0);
    assert(0 == a.length);
    assert(128 == a.capacity);
    int arr[] = { 1, 2, 3, 4, 5 };
    vec_pusharr(&a, arr, ARYLEN(arr));
    assert(5 == a.length);
    assert(128 == a.capacity);
    int arr1[] = { 11, 22, 33 };
    vec_insertarr(&a, 0, arr1, ARYLEN(arr1));
    assert(8 == a.length);
    assert(11 == a.data[0]);
    assert(22 == a.data[1]);
    assert(33 == a.data[2]);
    assert(1 == a.data[3]);
    assert(5 == a.data[7]);
    assert(128 == a.capacity);
    vec_shrinkToFit(&a);
    assert(8 == a.capacity);

    vec_free(&a);
}





static int mainReturn(int r)
{
#if !defined(NDEBUG) && defined(_WIN32)
    system("pause");
#endif
    return r;
}


int main(int argc, char* argv[])
{
    for (u32 i = 0; i < 1024*64; ++i)
    {
        test();
    }
    mainReturn(0);
}



















































































