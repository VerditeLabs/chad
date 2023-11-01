#include "chad.h"



#define T int
#define ARRDEF

#define TV int
#define TK int
#define MAPDEF

#include "chad_templates.h"



void test_arr(void){
    int _asdf [] ={0, 1, 2, 3, 4,5,6,7,8,9};
    auto asdf = newarrint();
    for(int i = 0; i < 10; i++)asdf = push(asdf,_asdf[i]);
    assert(len(asdf) == 10);
    assert(asdf->cap == 16);
    assert(at(asdf,0) == 0);
    assert(at(asdf,1) == 1);
    assert(at(asdf,2) == 2);
    assert(at(asdf,3) == 3);
    assert(at(asdf,4) == 4);
    assert(at(asdf,5) == 5);
    assert(at(asdf,6) == 6);
    assert(at(asdf,7) == 7);
    assert(at(asdf,8) == 8);
    assert(at(asdf,9) == 9);
}


void test_map(void){
    int _asdf[] = {0,1,2,3,4,5,6,7,8,9};
    int _asdf2[] = {9,8,7,6,5,4,3,2,1,0};
    auto asdf = newmapint_int();
    for(int i = 0; i < 10; i++) asdf = addkey(asdf,_asdf[i],_asdf2[i]);
    assert(at(asdf,0) == 9);
    assert(at(asdf,1) == 8);
    assert(at(asdf,2) == 7);
    assert(at(asdf,3) == 6);
    assert(at(asdf,4) == 5);
    assert(at(asdf,5) == 4);
    assert(at(asdf,6) == 3);
    assert(at(asdf,7) == 2);
    assert(at(asdf,8) == 1);
    assert(at(asdf,9) == 0);

}

int main(int argc, char** argv){
    int top;
    chadinit(&top);
    test_arr();
    test_map();
    chadfini();

    printf("asdf!\n");
    return 0;
}