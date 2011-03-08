/*
 * list.c
 *
 *  Created on: Mar 8, 2011
 *      Author: posixninja
 */

#include <stdio.h>

#include "list.h"

void list_init(list_t* list) {
	list->next = NULL;
	list->prev = list;
}
