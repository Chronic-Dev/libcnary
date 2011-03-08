/*
 * node.c
 *
 *  Created on: Mar 7, 2011
 *      Author: posixninja
 */
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

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
	return node;
}
