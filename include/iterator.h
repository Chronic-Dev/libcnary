/*
 * iterator.h
 *
 *  Created on: Mar 8, 2011
 *      Author: posixninja
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

struct list_t;
typedef struct iterator_t {
	void*(*create)(void);
	int(*free)(struct iterator_t* iterator);
	int(*next)(struct iterator_t* iterator);
	int(*bind)(struct iterator_t* iterator, struct list_t* list);

	unsigned int count;
	unsigned int position;

	struct list_t* list;
	struct object_t* end;
	struct object_t* begin;
	struct object_t* value;
} iterator_t;

#endif /* ITERATOR_H_ */
