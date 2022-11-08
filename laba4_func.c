#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "laba4_head.h"

keyvalue *create_keyvalue(char *key, void *value, size_t size, types type){
    keyvalue *new_kw = (keyvalue *)malloc(sizeof(keyvalue));
    new_kw->key = strdup(key);
    //keyvalue *new_kw = (keyvalue *)malloc(sizeof(keyvalue));
    //new_kw->key = key;
    new_kw->value = malloc(size);
    memcpy(new_kw->value, value, size);
    new_kw->size = size;
    new_kw->type = type;
    return new_kw;
}

void delete_keyvalue(keyvalue *need_del){
    free(need_del->value);
    free(need_del->key);
    free(need_del);
}

int match_keyvalue(keyvalue *kv1, keyvalue *kv2){
    if(kv1->size != kv2->size){
        return 0;
    }
    return memcmp(kv1->value, kv2->value, kv1->size) ? 0 : 1;
}

void copy_keyvalue(keyvalue *where, keyvalue *from){
    where->value = realloc(where->value, from->size);
    memcpy(where->value, from->value, from->size);
    where->size = from->size;
    where->type = from->type;
}

dictionary *create_dictionary(void){
    dictionary *new_dict = (dictionary *)malloc(sizeof(dictionary));
    new_dict->array = NULL;
    new_dict->len = 0;
    return new_dict;
}

void delete_dictionary(dictionary* dict){
    if(dict->len){
        for(int i = 0; i < dict->len; i++){
            delete_keyvalue(dict->array[i]);
        }
        free(dict->array);
    }
    free(dict);
}

void add_elem(dictionary *dict, char *key, void *value, size_t size, types type){
    dict->len++;
    dict->array = (keyvalue **)realloc(dict->array, dict->len * sizeof(keyvalue *));
    dict->array[dict->len - 1] = create_keyvalue(key, value, size, type);
}

void delete_elem(dictionary *dict, char *key){
    int elem_deleted = 0;
    for(int i = 0; i < dict->len; i++){
        if(elem_deleted){
            dict->array[i - 1] = dict->array[i];
        }
        if(!strcmp(dict->array[i]->key, key)){
            delete_keyvalue(dict->array[i]);
            elem_deleted = 1;
        }
    }
    dict->len--;
    dict->array = (keyvalue **)realloc(dict->array, dict->len * sizeof(keyvalue *));
}

keyvalue *find_elem(dictionary *dict, char *key){
    for(int i = 0; i < dict->len; i++){
        if(!strcmp(dict->array[i]->key, key)){
            return dict->array[i];
        }
    }
    return NULL;
}

void print_dictionary(dictionary *dict){
    for(int i = 0; i < dict->len; i++){
        printf("%s: ", dict->array[i]->key);
        switch(dict->array[i]->type){
            case FLOAT:
                printf("%f\n", *(float *)(dict->array[i]->value));
                break;
            case INT:
                printf("%d\n", *(int *)(dict->array[i]->value));
                break;
            case CHAR:
                printf("%c\n", *(char *)(dict->array[i]->value));
                break;
            case STRING:
                printf("%s\n", *(char **)(dict->array[i]->value));
                break;
            case POINTER:
                printf("%p\n", dict->array[i]->value);
                break;
        }
    }
}