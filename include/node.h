/*
 * node.h
 *
 *  Created on: Mar 7, 2011
 *      Author: posixninja
 */

#ifndef NODE_H_
#define NODE_H_

struct list_t;

typedef struct node_t {
	unsigned int depth;
	struct node_t* parent;
	struct list_t* children;
} node_t;

void node_destroy(node_t* node);
node_t* node_create(node_t* parent);

#endif /* NODE_H_ */
