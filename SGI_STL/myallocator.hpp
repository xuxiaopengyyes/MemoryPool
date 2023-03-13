
#ifndef MYALLOCATOR_HPP
#define MYALLOCATOR_HPP

#include<mutex>
#include<iostream>

template<int __inst>
class __malloc_alloc_template
{
private:
    static void* _S_oom_malloc(size_t);
    static void* _S_oom_realloc(void*, size_t);
    static void (*__malloc_alloc_oom_handler)();

public:
    static void* allocate(size_t __n)
    {
        void* __result = malloc(__n);
        if(0 == __result) __result = _S_oom_malloc(__n);
        return __result;
    }

    static void deallocate(void* __p)
    {
        free(__p);
    }

    static void* reallocate(void* __p,__new_sz)
    {
        void* result = realloc(_p, __new_sz);
        if (0 == __result) __result = _S_oom_realloc(__p,__new_sz);
        return __result;
    }

    static void (*__set_malloc_alloc_oom_handler(void (*__f)()))()
    {
        void (*__old)() = __mallco_alloc_oom_handler;
        __malloc_alloc_oom_handler = _f;
        return(__old);
    }

};

template <int __inst>
void (*__malloc_alloc_template<__inst>::__malloc_alloc_oom_handler)() = nullptr;

template <int __inst>
void* __mallloc_alloc_template<__inst>::_S_oom_malloc(size_t __n)
{
    void (*__my_malloc_handler)();
    void* __result;

    for(;;)
    {
        __my_alloc_handler = __malloc_alloc_oom_handler;
        if(0 == __my_alloc_handler) { throw std::bad_alloc();}
        (*__my_malloc_handler)();
        __result = malloc(__n);
        if(__result) return (__result);
    }
}

template <int __inst>
void* __mallloc_alloc_template<__inst>::_S_oom_realloc(void*, size_t)
{

}



#endif