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

#ifndef map_h
#define map_h

typedef struct map map;

typedef struct pair pair;

struct pair {
    const void *key;
    void *value;
};

/**
 @typedef
 Prototipo de funcion para eliminar de memoria el objeto que se guarda dentro del mapa.
 
 @param object Puntero al objecto guardado.
 */
typedef void (*map_release_object_callback)(void *object);

/**
 @typedef
 Prototipo de la funcion hash.

 @param key Llave para poder obtener el valor del hash.
 @return El valor hash de la llave.
 */
typedef long long (*map_hash_callback)(const void *key);

/**
 @typedef
 Prototipo de funcion Equal, la cual comparar dos llaves para saber si son iguales.
 
 @param key_1 Primera llave.
 @param key_2 Segunda llave.
 @return Retorna 1 si las dos llaves son iguales; 0 lo contrario.
 */
typedef int (*map_equal_callback)(const void *key_1, const void *key_2);

/**
 @constant kStringMapHashCallBack
 
 Funcion hash predefinida para cadenas.
 */
extern const map_hash_callback kStringMapHashCallBack;

/**
 @constant kStringMapEqualCallBack
 
 Funcion equal predefinida para cadenas.
 */
extern const map_equal_callback kStringMapEqualCallBack;

/**
 Crea un nuevo puntero de tipo Map.

 @param hash Funcion hash.
 @param equal Funcion equal.
 @return Puntero al nuevo Map creado.
 */
extern map *map_init (map_hash_callback hash, map_equal_callback equal, map_release_object_callback release);

/**
 Inserta un nuevo elemento en el Map.
 
 Esta función tiene como complejidad:
 
 - Mejor caso: O(1)
 
 - Peor caso: O(n)

 @param map Puntero al Map.
 @param key Puntero a la llave del elemento que se va a insertar.
 @param value Puntero al valor que se va a insertar.
 */
extern void map_insert (map *map, const void *key, void *value);

/**
 Retorna la cantidad de elementos no nulos del Map.
 
 Complejidad: O(1)

 @param map Puntero al Map.
 @return La cantidad de elemntos del Map.
 */
extern long map_size (map *map);

/**
 Prueba si el Map está vacio.
 
 Complejidad: O(1)

 @param map Puntero al Map.
 @return 1 (true) si y solo si el Map no contiene elementos; 0 (false) lo contrario.
 */
extern int map_empty (map *map);

/**
 Elimina un elemento con la llave del Map, pero no lo libera de la memoria.
 
 Si la funcion release esta activa, la funcion eliminara de la memoria
 el dato guardado en la struct pair.
 
 Esta función tiene como complejidad:
 
 - Mejor caso: O(1)
 
 - Peor caso: O(n)

 @param map Puntero al Map.
 @param key Llave del elemento a eliminar.
 @return Puntero al dato eliminado del Map, retorna NULL en caso que el valor no exisista.
 */
extern void *map_remove_key (map *map, const void *key);

/**
 Busca un elemento en el Map con la llave.
 
 Esta función tiene como complejidad:
 
 - Mejor caso: O(1)
 
 - Peor caso: O(n)

 @param map Puntero al Map.
 @param key Llave del elemento a buscar.
 @return Puntero al dato encontrado del Map.
 */
extern void *map_search_key (map *map, const void *key);

/**
 Retorna el primero elemento no nulo del Map.
 
 Complejidad: O(n)

 @param map Puntero al Map.
 @return Puntero al primero elemento encontrado del Map.
 */
extern pair *map_first (map *map);

/**
 Retorna el siguiente elemento no nulo del Map.
 
 Complejidad: O(n)
 
 @param map Puntero al Map.
 @return Puntero al siguiente elemento encontrado del Map.
 */
extern pair *map_next (map *map);

/**
 Elimina todos los elementos del Map, pero sin liberar la memoria de los datos contentidos.
 
 Complejidad: O(n)
 
 @param map Puntero al Map.
 */
extern void map_release (map **map);

#endif /* map_h */

