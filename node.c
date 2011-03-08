/*
 * node.c
 *
 *  Created on: Mar 7, 2011
 *      Author: posixninja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "node_list.h"

void node_destroy(node_t* node) {
	if(node) {
		free(node);
	}
}

node_t* node_create(node_t* parent) {
	node_t* node = (node_t*) malloc(sizeof(node_t));
	if(node == NULL) {
		return NULL;
	}
	memset(node, '\0', sizeof(node_t));

	// Pass NULL to create a root node
	if(parent == NULL) {
		// This is a root node

	} else {
		// This is a leaf node
		node->parent = parent;
		node->depth = parent->depth + 1;
		node->children = node_list_create(node);
	}

	return node;
}

int node_attach(node_t* parent, node_t* child) {
	return 0;
}

int node_detach(node_t* parent, node_t* child) {
	return 0;
}
