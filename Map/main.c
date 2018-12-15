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


int main() {
    
    Map * test = createMap(kStringMapHashCallBack, kStringMapEqualCallBack);
    
    insertMap(test, "Hola", NULL);
    insertMap(test, "Como", "Como");
    insertMap(test, "Test", "Test");
    insertMap(test, "Si", NULL);
    
    insertMap(test, "Hola", "Hola");
    
    printf("Cantidad de datos: %ld\n", mapCount(test));
    
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
    
    eraseKeyMap(test, "Test");
    
    printf("Cantidad de datos: %ld\n", mapCount(test));
    
    insertMap(test, "Si", "Si");
    
    data = firstMap(test);
    
    while (data != NULL) {
        printf("%s\n", data);
        data = nextMap(test);
    }
    
    return 0;
}
