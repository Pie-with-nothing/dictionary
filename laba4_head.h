#pragma once
#include <string.h>

typedef enum{
    FLOAT,
    INT,
    CHAR,
    STRING,
    POINTER
} types;

typedef struct{
    char *key;
    void *value;
    size_t size;
    types type;
} keyvalue;

typedef struct{
    keyvalue **array;
    unsigned int len;
} dictionary;

keyvalue *create_keyvalue(char *key, void *value, size_t size, types type);

void delete_keyvalue(keyvalue *need_del);

int match_keyvalue(keyvalue *kv1, keyvalue *kv2);

void copy_keyvalue(keyvalue *where, keyvalue *from);

dictionary *create_dictionary(void);

void delete_dictionary(dictionary* dict);

void add_elem(dictionary *dict, char *key, void *value, size_t size, types type);

void delete_elem(dictionary *dict, char *key);

keyvalue *find_elem(dictionary *dict, char *key);

void print_dictionary(dictionary *dict);