#pragma once

#define ARRDEF(T) \
struct arr##T { \
    sint len, cap; \
    T* a; \
}; \
void arr##T##dtor(void* p){printf("arr dtor %08x\n",(uint)p);}\
void arr##T##dtorT(void* p){printf("arr dtorT %08x\n",(uint)p);}\
struct arr##T* newarr##T(void){\
    struct arr##T* ret = new(sizeof(struct arr##T), 0, arr##T##dtor); \
    ret->len = 0;  \
    ret->cap = 8;\
    ret->a = new(ret->cap*sizeof(T), 0, arr##T##dtorT); \
    return ret; \
}                 \
overload struct arr##T* push(struct arr##T* arr, T v){                      \
    if(arr->len == arr->cap){                                  \
        arr->cap = arr->cap*2;                                \
        arr->a = renew(arr->a, arr->cap * sizeof(T));\
    }             \
    arr->a[arr->len] = v;              \
    arr->len++;    \
    return arr;\
}                 \
overload struct arr##T* pop(struct arr##T* arr){                      \
    assert(arr->len > 0);              \
    if(arr->len < arr->cap/2){                                  \
        arr->cap = arr->cap/2;                                \
        arr->a = renew(arr->a, arr->cap * sizeof(T));\
    }                    \
    arr->len--;    \
    return arr;\
}                 \
overload sint len(struct arr##T* arr){                               \
    return arr->len;                      \
} \
overload T at(struct arr##T* arr, sint i){                    \
    assert(i >= 0);              \
    assert(i < arr->len);                                      \
    return arr->a[i];\
}

#define MAPDEF(TK, TV) \
struct map##TK##_##TV {\
    sint len, cap;           \
    TK* k;             \
    TV* v;\
};                     \
void map##TK##_##TV##dtor(void* p){printf("map dtor %08x\n",(uint)p);}\
void map##TK##_##TV##dtorTK(void* p){printf("map dtorTK %08x\n",(uint)p);}\
void map##TK##_##TV##dtorTV(void* p){printf("map dtorTV %08x\n",(uint)p);}\
struct map##TK##_##TV* new##map##TK##_##TV(){   \
    struct map##TK##_##TV* ret = new(sizeof(struct map##TK##_##TV*), 0, map##TK##_##TV##dtor); \
    ret->len = 0;       \
    ret->cap = 8;      \
    ret->k = new(sizeof(TK)* ret->cap, 0,  map##TK##_##TV##dtorTK);   \
    assert(ret->k != NULL);                   \
    ret->v = new(sizeof(TV)* ret->cap, 0,  map##TK##_##TV##dtorTV);   \
    assert(ret->v != NULL); \
    return ret;\
}                      \
sint len(struct map##TK##_##TV* map){return map->len;}\
struct map##TK##_##TV* addkey(struct map##TK##_##TV* map, TK k, TV v){  \
    if(len(map) == map->cap){\
        map->cap = map->cap*2;                                        \
        map->k = renew(map->k, sizeof(TK)*map->cap);                  \
        assert(map->k != NULL);\
        map->v = renew(map->v, sizeof(TV)*map->cap);                  \
        assert(map->v != NULL);  \
    }                  \
    map->k[map->len] = k;\
    map->v[map->len] = v;    \
    map->len++;        \
    return map;\
}
