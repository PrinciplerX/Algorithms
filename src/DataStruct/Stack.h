/*
** Moudle: DataStruct
** Author: YiChao Yang
** Date: 2017-10-17
*/

#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

#define stack_push(stack, data) list_insert_next(stack, NULL, data)
#define stack_pop(stack, data) list_remove_next(stack, NULL, data)

#define stack_peek(stack) (list_head(stack) ? list_head(stack)->data : NULL)
#define stack_size list_size

#endif /* STACK_H */
