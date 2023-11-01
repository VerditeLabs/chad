#include "chad.h"

#include "tgc.h"

struct _chad {
    tgc_t gc;
    int a;
};

static struct _chad _chad;

struct _chad* chad(){
    return &_chad;
}

void chadinit(void* stk){
    auto chad_ = chad();
    tgc_start(&chad_->gc, stk);
}

void chadfini(void){
    auto chad_ = chad();
    tgc_stop(&chad_->gc);
}

overload void* new(sint sz){
    auto chad_ = chad();
    //return malloc(sz);
    return tgc_alloc(&chad_->gc, sz);
}

overload void* new(sint sz, int flags, void(*dtor)(void*)){
    auto chad_ = chad();
    //return malloc(sz);
    return tgc_alloc_opt(&chad_->gc, sz, flags, dtor);
}

overload void* renew(void* p, sint sz){
    auto chad_ = chad();
    //return realloc(p,sz);
    return tgc_realloc(&chad_->gc, p, sz);
}

overload void del(void* p){
    auto chad_ = chad();
    //free(p);
    return tgc_free(&chad_->gc, p);
}