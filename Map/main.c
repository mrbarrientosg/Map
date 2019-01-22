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
#include "map.h"

int main() {
    
    map *test = map_init (kStringMapHashCallBack, kStringMapEqualCallBack, NULL);
    
    map_insert (test, "Hola", NULL);
    map_insert (test, "Como", "Como");
    map_insert (test, "Test", "Test");
    map_insert (test, "Si", NULL);
    
    map_insert (test, "Hola", "Hola");
    
    printf ("Cantidad de datos: %ld\n", map_size (test));
    
    pair *data = map_first (test);
    
    while (data != NULL) {
        printf ("%s\n", (char *) data->value);
        data = map_next (test);
    }
    
    map_release (&test);
    
    test = map_init (kStringMapHashCallBack, kStringMapEqualCallBack, NULL);
    
    printf ("\n");
    
    map_insert (test, "Hola", "Hola");
    map_insert (test, "Como", "Como");
    map_insert (test, "Test", "Test");
    
    map_remove_key (test, "Test");
    
    printf ("Cantidad de datos: %ld\n", map_size (test));
    
    map_insert (test, "Si", "Si");
    
    data = map_first (test);
    
    while (data != NULL) {
        printf ("%s\n", (char *) data->value);
        data = map_next (test);
    }
    
    return 0;
}
