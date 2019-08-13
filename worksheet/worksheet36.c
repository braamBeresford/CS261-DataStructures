#ifndef DYARRAYDICTH
#define DYARRAYDICTH

/*
   dynamic array dictionary interface file
*/

#ifndef KEYTYPE
#define KEYTYPE char *
#endif

#ifndef VALUETYPE
#define VALUETYPE double
#endif

struct association
{
    KEYTYPE key;
    VALUETYPE value;
};

#define TYPE struct association *

#include "dynamicArray.h"

/* dictionary */
void dyArrayDictionaryGet(struct dynArray *da, KEYTYPE key, VALUETYPE *valptr);
void dyArrayDictionaryPut(struct dynArray *da, KEYTYPE key, VALUETYPE val);
int dyArrayDictionaryContainsKey(struct dynArray *da, KEYTYPE key);
void dyArrayDictionaryRemoveKey(struct dynArray *da, KEYTYPE key);

#endif

#include "dyArrayDictionary.h"
#include "dyArrayDictionary.c"

/*finds and places the value associated with key in valptr */
void dyArrayDictionaryGet(struct dynArray *da, KEYTYPE key, VALUETYPE *valptr)
{
    for(int i = 0; i < da->size; i++){
        if(compare(da->data[i]->key, key) == 0){
            valptr = &(da->data[i]);
        }
    }
}

void dyArrayDictionaryPut(struct dynArray *da, KEYTYPE key, VALUETYPE val)
{
    struct association *ap;
    if (dyArrayDictionaryContainsKey(da, key))
        dyArrayDictionaryRemove(da, key);
    ap = (struct association *)malloc(sizeof(struct association));
    assert(ap != 0);
    ap->key = key;
    ap->value = val;
    dyArrayAdd(da, ap);
}

int dyArrayDictionaryContainsKey(struct dynArray *da, KEYTYPE key)
{
    for(int i = 0; i < da->size; i++){
        if(compare(da->data[i]->key, key) == 0){
            return 1;
        }
    }
    return 0;
}

void dyArrayDictionaryRemoveKey (struct  dynArray *da, KEYTYPE key) {

     for(int i = 0; i < da->size; i++){
        if(compare(da->data[i]->key, key) == 0){
            removeAtDynArr(da, i);
        }
    }
    
}
