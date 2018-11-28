#include <stdlib.h>
#ifdef _WIN32
# include <crtdbg.h>
#endif



#include <stdio.h>
#include <assert.h>

#include "vec.h"




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
    test();
    mainReturn(0);
}



















































































