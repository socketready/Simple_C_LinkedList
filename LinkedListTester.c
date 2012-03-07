/*
 * LinkedListTester.c
 *
 *  Created on: Aug 16, 2010
 *      Author: socketready.com
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct pack{
	int num;
}pack;

void print_list(ll_node *head);
int comp(void *one, void *two);

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
	
	pack *temp = malloc(sizeof(pack));
	pack *t;
	temp->num = 15;
	t = (pack *)ll_search(head, (void *)temp, comp);
	
	if(t != NULL)
		printf("%d\n", t->num);
	else
		printf("not found\n");

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

int comp(void *one, void *two){
	pack *item1 = (pack *)one;
	pack *item2 = (pack *)two;
	
	if(item1->num > item2->num){
		return 1;
	}else if(item1->num < item2->num){
		return -1;
	}else{
		return 0;
	}
}
