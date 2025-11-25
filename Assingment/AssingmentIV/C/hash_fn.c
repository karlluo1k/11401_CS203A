/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
   

   Development History:
    - 2025/11/22: Initial commit: Add template files
    - 2025/11/25: Implement myHashInt & myHashString in C

   Developer: Yi-Kai Lo <s1133304@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int pow(int n, int i) {    //calculating powers
    int res = 1;
    for(int j = 0; j < i; ++j) {
        res *= n;
    }
    return res;
}

int myHashInt(int key, int m) {
    return key % 97;    //deviding by a large enough prime number
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    const int p = 10;
    for (int i = 0; str[i] != '\0'; ++i) {  //hashing
        hash += (int)str[i] * pow_int(p, i);
    }
    return (int)(hash % 97); //deviding by a prime number
}
