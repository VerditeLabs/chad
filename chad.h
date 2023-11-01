#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define auto __auto_type
#define overload __attribute__((overloadable))


#define die(...)do{printf(__VA_ARGS__); exit(1);}while(0)
#define die_if(cond, ...)do{if(cond){printf(__VA_ARGS__); exit(1);}}while(0)

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef __uint128_t u128;
typedef __int128_t s128;
typedef __fp16 float16;
typedef float float32;
typedef double float64;

typedef s32 sint;
typedef u32 uint;

void chadinit(void* stk);
void chadfini(void);

overload void* new(sint sz);
overload void* new(sint sz, int flags, void(*dtor)(void*));
overload void* renew(void* p, sint sz);
overload void del(void* p);