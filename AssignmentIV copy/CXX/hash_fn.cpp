/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    -2025/11/20:revise myhashint Make negative numbers applicable as well
                myhashstring use polypolynomial rolling hash

   Developer: eircchen <ericchen9411@gmail.com>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // Integer hash based on division method with non-negative normalization
    if (m <= 0) return 0;

    long long k = key;
    if (k < 0) k = -k;  // avoid negative remainder

    return static_cast<int>(k % m);
}

int myHashString(const std::string& str, int m) {
    if (m <= 0) return 0;

    // Polynomial rolling hash: h = (h * base + ch) mod m
    unsigned long long h = 0;
    const unsigned int base = 31;  // a common prime-ish base for string hashing

    for (unsigned char ch : str) {
        h = h * base + ch;
        h %= static_cast<unsigned long long>(m);
    }

    return static_cast<int>(h % m);
}
