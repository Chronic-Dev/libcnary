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
	if(list) {
		list_free(list);
		free(list);
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
