
#define _CAT2(a,b) a##b
#define CAT2(a,b) _CAT2(a,b)
#define _CAT3(a,b,c) a##b##c
#define CAT3(a,b,c) _CAT3(a,b,c)
#define _CAT4(a,b,c,d) a##b##c##d
#define CAT4(a,b,c,d) _CAT4(a,b,c,d)
#define _CAT5(a,b,c,d,e) a##b##c##d##e
#define CAT5(a,b,c,d,e) _CAT5(a,b,c,d,e)

#ifdef ARRDEF
#ifndef T
#error define T
#endif

struct CAT2(arr,T) {
    sint len, cap;
    T* a;
};
noinline void CAT3(arr, T, dtor)(void* p){printf("arr dtor %08x\n",(uint)p);}
noinline void CAT3(arr, T, dtorT)(void* p){printf("arr dtorT %08x\n",(uint)p);}
noinline CAT2(struct arr, T)* CAT2(newarr, T)(void){
    CAT2(struct arr, T*) ret = new(sizeof(struct CAT2(arr,T)), 0, CAT3(arr,T,dtor));
    ret->len = 0;
    ret->cap = 8;
    ret->a = new(ret->cap*sizeof(T), 0, CAT3(arr,T,dtor));
    return ret;
}
noinline overload struct CAT2(arr,T)* push(struct CAT2(arr, T)* arr, T v){
    if(arr->len == arr->cap){
        arr->cap = arr->cap*2;
        arr->a = renew(arr->a, arr->cap * sizeof(T));
    }
    arr->a[arr->len] = v;
    arr->len++;
    return arr;
}
noinline overload struct CAT2(arr,T)* pop(struct CAT2(arr, T)* arr){
    assert(arr->len > 0);
    if(arr->len < arr->cap/2){
        arr->cap = arr->cap/2;
        arr->a = renew(arr->a, arr->cap * sizeof(T));
    }
    arr->len--;
    return arr;
}
noinline overload sint len(struct CAT2(arr,T)* arr){
    return arr->len;
}
noinline overload T at(struct CAT2(arr,T)* arr, sint i){
    assert(i >= 0);
    assert(i < arr->len);
    return arr->a[i];
}
#endif

#ifdef true
#ifndef TK
#error define TK
#endif
#ifndef TV
#error define TV
#endif

struct CAT4(map,TK,_,TV) {
    sint len, cap;
    TK* k;
    TV* v;
};
noinline void CAT5(map,TK,_,TV,dtor)(void* p){printf("map dtor %08xn",(uint)p);}
noinline void CAT5(map,TK,_,TV,dtorTK)(void* p){printf("map dtorTK %08xn",(uint)p);}
noinline void CAT5(map,TK,_,TV,dtorTV)(void* p){printf("map dtorTV %08xn",(uint)p);}
noinline struct CAT4(map,TK,_,TV)* CAT4(newmap,TK,_,TV)(){
    struct CAT4(map,TK,_,TV)* ret = new(sizeof(struct CAT4(map,TK,_,TV)*), 0, CAT5(map,TK,_,TV,dtor));
    ret->len = 0;
    ret->cap = 8;
    ret->k = new(sizeof(TK)* ret->cap, 0,  CAT5(map,TK,_,TV,dtorTK));
    assert(ret->k != NULL);
    ret->v = new(sizeof(TV)* ret->cap, 0,  CAT5(map,TK,_,TV,dtorTV));
    assert(ret->v != NULL);
    return ret;
}
noinline overload sint len(struct CAT4(map,TK,_,TV)* map){return map->len;}
noinline overload struct CAT4(map,TK,_,TV)* addkey(struct CAT4(map,TK,_,TV)* map, TK k, TV v){
    if(len(map) == map->cap){
        map->cap = map->cap*2;
        map->k = renew(map->k, sizeof(TK)*map->cap);
        assert(map->k != NULL);
        map->v = renew(map->v, sizeof(TV)*map->cap);
        assert(map->v != NULL);
    }
    map->k[map->len] = k;
    map->v[map->len] = v;
    map->len++;
    return map;
}
noinline overload TV at(struct CAT4(map,TK,_,TV)* map, TK k){
    for(int i = 0; i < map->cap; i++){
        if (eq(map->k[i], k)) return map->v[i];
    }
    assert(false);
    return 0;
}
#endif