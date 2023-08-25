#include "include/list.h"

list_T* init_list(size_t item_size){
    list_T* list = calloc(1, sizeof(struct LIST_STRUCT));
    list->size = 0;
    list->item_size = item_size;
    list->items = 0;

    return list;
}

void list_push(list_T* list, void* item){
    list->size++;
    if(!list->items){
        list->items = malloc(1*sizeof(list->item_size));
    }else{
        list->items = realloc(list->items,  (list->size * list->item_size));
        list->items[list->size] = item;
    }
}
