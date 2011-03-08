/*
 * list.h
 *
 *  Created on: Mar 8, 2011
 *      Author: posixninja
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct list_t {
	void* next;
	void* prev;
} list_t;

#endif /* LIST_H_ */
