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
#include "node_iterator.h"

void node_destroy(node_t* node) {
	if(node) {
		free(node);
	}
}

node_t* node_create(node_t* parent) {
	int error = 0;

	node_t* node = (node_t*) malloc(sizeof(node_t));
	if(node == NULL) {
		return NULL;
	}
	memset(node, '\0', sizeof(node_t));

	node->depth = 0;
	node->next = NULL;
	node->prev = NULL;
	node->isLeaf = TRUE;
	node->isRoot = TRUE;
	node->parent = NULL;
	node->children = node_list_create(node);

	// Pass NULL to create a root node
	if(parent != NULL) {
		// This is a child node so attach it to it's parent
		error = node_attach(parent, node);
		if(error < 0) {
			// Unable to attach nodes
			printf("ERROR: %d \"Unable to attach nodes\"\n", error);
			node_destroy(node);
			return NULL;
		}
	}

	return node;
}

int node_attach(node_t* parent, node_t* child) {
	child->isLeaf = TRUE;
	child->isRoot = FALSE;
	child->parent = parent;
	child->depth = parent->depth + 1;
	return node_list_add(parent->children, child);
}

int node_detach(node_t* parent, node_t* child) {
	return 0;
}

void node_debug(node_t* node) {
	node_t* current = NULL;
	node_iterator_t* iter = NULL;
	if(node->isRoot) {
		printf("ROOT\n");

	} else {
		if(node->isLeaf) {
			printf("LEAF\n");

		} else {
			printf("NODE\n");
			iter = node_iterator_create(node->children);
			for(current = iter->begin; current != NULL; current = iter->next(iter)) {
				node_debug(current);
			}
		}
	}
}
