/**
 MIT License
 
 Copyright (c) 2018 Matias Barrientos.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Map.h"

long long stringHash(const void * key) {
    long long hash = 5381;
    
    const char * ptr;
    
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash = ((hash << 5) + hash) + tolower(*ptr); /* hash * 33 + c */
    }
    
    return hash;
}

int stringEqual(const void * key1, const void * key2) {
    const char * A = key1;
    const char * B = key2;
    
    return strcmp(A, B) == 0;
}

int main() {
    
    Map * test = createMap(stringHash, stringEqual);
    
    insertMap(test, "Hola", "Hola");
    insertMap(test, "Como", "Como");
    insertMap(test, "Test", "Test");
    insertMap(test, "Si", "Si");
    
    char * data = firstMap(test);
    
    while (data != NULL) {
        printf("%s\n", data);
        data = nextMap(test);
    }
    
    removeAllMap(test);
    
    printf("\n");
    
    insertMap(test, "Hola", "Hola");
    insertMap(test, "Como", "Como");
    insertMap(test, "Test", "Test");
    insertMap(test, "Si", "Si");
    
    data = firstMap(test);
    
    while (data != NULL) {
        printf("%s\n", data);
        data = nextMap(test);
    }
    
    return 0;
}
