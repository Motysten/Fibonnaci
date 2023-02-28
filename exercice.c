#include <stdio.h>
#include <stdlib.h>

#include <string.h>

char* mystrstr(const char* str1, const char* str2) {
    if (*str2 == '\0') {
        return (char*)str1;
    }
    
    size_t len1 = mystrlen(str1);
    size_t len2 = mystrlen(str2);
    
    for (size_t i = 0; i <= len1 - len2; i++) {
        size_t j = 0;
        while (j < len2 && str1[i + j] == str2[j]) {
            j++;
        }
        if (j == len2) {
            return (char*)(str1 + i);
        }
    }
    
    return NULL;
}

size_t mystrlen(const char* str) {
    const char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

char* mystrcpy(char* destination, const char* source) {
    char* ptr = destination;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char* mystrpbrk(const char* str, const char* chars) {
    const char* p = str;
    while (*p != '\0') {
        const char* q = chars;
        while (*q != '\0') {
            if (*p == *q) {
                return (char*)p;
            }
            q++;
        }
        p++;
    }
    return NULL;
}

int main() {
    
}