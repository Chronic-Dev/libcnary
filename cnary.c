/*
 * cnary.c
 *
 *  Created on: Mar 9, 2011
 *      Author: posixninja
 */

#include <stdio.h>

#include "node.h"

int main(int argc, char* argv[]) {
	puts("Creating root node");
	node_t* root = node_create(NULL);

	puts("Creating child 1 node");
	node_t* one = node_create(root);
	puts("Creating child 2 node");
	node_t* two = node_create(root);

	puts("Debugging root node");
	node_debug(root);

	puts("Destroying root node");
	node_destroy(root);
	return 0;
}
