/*
 * node.h
 *
 *  Created on: Mar 7, 2011
 *      Author: posixninja
 */

#ifndef NODE_H_
#define NODE_H_

struct node_list_t;

typedef struct node_t {
	unsigned int depth;
	struct node_t* parent;
	struct node_list_t* children;
} node_t;

static void node_destroy(node_t* node);
static node_t* node_create(node_t* parent);

static int node_attach(node_t* parent, node_t* child);
static int node_detach(node_t* parent, node_t* child);

#endif /* NODE_H_ */
