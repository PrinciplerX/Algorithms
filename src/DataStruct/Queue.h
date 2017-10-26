/*
** Moudle: DataStruct
** Author: YiChao Yang
** Date: 2017-10-18
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "List.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

#define queue_enqueue(stack, data) list_insert_next(stack, list_tail(stack), data)
#define queue_dequeue(stack, p_data) list_remove_next(stack, NULL, p_data)

#define queue_peek(queue) (list_head(queue) ? list_head(queue)->data : NULL)
#define queue_size list_size

#endif /* QUEUE_H */
