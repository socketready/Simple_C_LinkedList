/*
 * LinkedListTester.c
 *
 *  Created on: Aug 16, 2010
 *      Author: socketready.com
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
	int i;
	ll_node *head;
	ll_node *temp;
	int array[10];
	void *ptr;
	
	ptr = (void *)&array[6];
	
	head = ll_linkedlist_init();
	for(i=0; i<10; i++)
	{
		printf("%d added to index %d\n", i, i);
		ll_add_last(head, (void *)&array[i]);
	}
	
	for(temp = head->next; temp != head; temp = temp->next)
	{
		printf("%p\n", temp->data);
	}
	
	printf("#####\n");
	
	for(i=0; i<10; i++)
	{
		void *ptr;
		ptr = (void *)ll_pop(head);
		//ptr = ll_get_first(head);
		printf("%d\n", (int *)ptr);
	}
	
	*((int *)ptr) = 100;
	printf("%d\n", array[6]);

	//ll_free_list(head);
	
	return 0;
}