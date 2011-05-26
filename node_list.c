/*
 * node_list.c
 *
 *  Created on: Mar 8, 2011
 *      Author: posixninja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "node.h"
#include "node_list.h"

void node_list_destroy(node_list_t* list) {
	if(list != NULL) {
		list_destroy((list_t*) list);
	}
}

node_list_t* node_list_create(node_t* node) {
	node_list_t* list = (node_list_t*) malloc(sizeof(node_list_t));
	if(list == NULL) {
		return NULL;
	}
	memset(list, '\0', sizeof(node_list_t));

	// Initialize structure
	list_init((list_t*) list);
	list->count = 0;
	return list;
}

int node_list_add(node_list_t* list, node_t* node) {
	if (!list || !node) return -1;

	// Find the last element in the list
	node_t* last = list->end;

	// Setup our new node as the new last element
	node->next = NULL;
	node->prev = last;

	// Set the next element of our old "last" element
	last->next = node;

	// Set the lists prev to the new last element
	list->end = node;

	// Increment our node count for this list
	list->count++;
	return 0;
}

int node_list_remove(node_list_t* list, node_t* node) {
	return -1;
}

