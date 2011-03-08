/*
 * list.h
 *
 *  Created on: Mar 8, 2011
 *      Author: posixninja
 */

#ifndef LIST_H_
#define LIST_H_

#include "object.h"

typedef struct list_t {
	void* next;
	void* prev;
} list_t;

void list_init(list_t* list);

#endif /* LIST_H_ */
