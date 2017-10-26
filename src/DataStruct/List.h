/*
** Moudle: DataStruct
** Author: YiChao Yang
** Date: 2017-10-16
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h> /* for NULL */

#include "DataStructGlobal.h"

typedef struct ListElement {
    void* data;
    struct ListElement* next;
} ListElement;

typedef void (*ListDestroyElement)(void*);
typedef int (*ListMatchElement)(void*, void*);

typedef struct List {
    int size;
    ListMatchElement match;
    ListDestroyElement destroy;
    ListElement* head;
    ListElement* tail;
} List;

void DATA_STRUCT_EXPORT list_init(List* list, ListDestroyElement destroy);
void DATA_STRUCT_EXPORT list_destroy(List* list);
int DATA_STRUCT_EXPORT list_insert_next(List* list, ListElement* element, const void* data);
int DATA_STRUCT_EXPORT list_remove_next(List* list, ListElement* element, void** data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == list_head(list))
#define list_is_tail(list, element) ((element) == list_tail(list))
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#define list_push_back(list, data) list_insert_next(list, list_tail(list), data)
#define list_push_front(list, data) list_insert_next(list, NULL, data)

#endif /* LIST_H */
