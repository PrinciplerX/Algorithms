/*
** Moudle: DataStruct
** Author: YiChao Yang
** Date: 2017-10-16
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "List.h"

#define list_malloc_element() (ListElement*)malloc(sizeof(ListElement))
#define list_free_element(element) free(element);

void
list_init(List *list, ListDestroyElement destroy)
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void
list_destroy(List *list)
{
    void* data;
    while (list_size(list) > 0) {
        if (list_remove_next(list, NULL, (void**)&data) == 0 && list->destroy) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(List));
}

int
list_insert_next(List *list, ListElement *element, const void *data)
{
    ListElement* new_element;

    if ( (new_element = list_malloc_element()) ) {
        /* Out of memory. */
        return -1;
    }

    new_element->data = (void*)data;
    if (element) {
        if (list_is_tail(list, element))
            list->tail = new_element;

        new_element->next = element->next;
        element->next = new_element;
    } else {
        if (!list_tail(list))
            list->tail = new_element;

        new_element->next = list->head;
        list->head = new_element;
    }

    list->size++;

    return 0;
}

int
list_remove_next(List *list, ListElement *element, void **data)
{
    ListElement* removed_element;

    if (list->size == 0) {
        return -1;
    }

    assert(list_head(list));
    assert(list_tail(list));

    if (element) {
        if (list_is_tail(list, element))
            return -1;

        removed_element = element->next;
        element->next = removed_element->next;

        if (!element->next) {
            list->tail = element;
        }
    } else {
        removed_element = list->head;
        list->head = removed_element->next;

        if (!list->head->next) {
            list->tail = NULL;
        }
    }

    *data = removed_element->data;

    list->size--;
    list_free_element(removed_element);

    return 0;
}


