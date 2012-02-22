/*
 * LinkedListTester.c
 *
 *  Created on: Aug 16, 2010
 *      Author: kpgwinnup
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct pack{
	int num;
}pack;

void print_list(ll_node *head);

int main(){
	int i;
	ll_node *head;
	pack *obj;
	
	head = ll_linkedlist_init();
	for(i=0; i<11; i++){
		obj = malloc(sizeof(pack));
		obj->num = 14 * i;
		ll_add_first(head, (void *)obj);
	}

	print_list(head);
	ll_remove_index(head,2);
	ll_reverse(head);
	print_list(head);

	ll_free_list(head);
	return 0;
}


void print_list(ll_node *head){
	int i;
	pack *ret;

	for(i=0; i<head->size; i++){
		ret = ll_get_index(head, i);
		printf("%d ", ret->num);
	}

	printf("\n");
}
