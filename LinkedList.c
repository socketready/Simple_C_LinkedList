/*
 * LinkedList.c
 *
 *  Created on: Aug 16, 2010
 *      Author: kpgwinnup
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void* ll_linkedlist_init(){
	ll_node *head;
	head = (ll_node *)malloc(sizeof(ll_node));
	head->data = NULL;
	head->next = head;
	head->prev = head;
	head->size = 0;
	return head;
}



/**
 * if the list is empty set next and prev to head and
 * head next and prev to new node
 */
void push(ll_node *head, void *d){ ll_add_first(head, d); }
void enqueue(ll_node *head, void *d){ ll_add_first(head, d); }

void ll_add_first(ll_node *head, void *d){
	ll_node *temp;
	temp = (ll_node *)malloc(sizeof(ll_node));
	temp->data = d;
	
	if(head->next == head){ /* list is empty */
		temp->next = head;
		temp->prev = head;
		head->next = temp;
		head->prev = temp;
	}else{ 					/* items in list */
		temp->next = head->next;
		temp->prev = head;
		head->next->prev = temp;
		head->next = temp;
	}
	
	head->size++;
}


/**
 * this returns a void pointer to head's prev node
 */
void ll_add_last(ll_node *head, void *d){
	ll_node *temp;
	temp = (ll_node *)malloc(sizeof(ll_node));
	temp->data = d;
	
	if(head->next == head){ /* list is empty */
		temp->next = head;
		temp->prev = head;
		head->next = temp;
		head->prev = temp;
	}else{
		temp->next = head;
		temp->prev = head->prev;
		head->prev->next = temp;
		head->prev = temp;
	}
	
	head->size++;
}


/**
 * swaps front with back then moves inward and continues swap
 * only data pointers of the ll_node are swapped. node links
 * stay the same
 */
void ll_reverse(ll_node *head){
	ll_node *front, *back, *temp;
	
	front = head->next;
	back = head->prev;
	
	while(front != back){
		temp = front->data;
		front->data = back->data;
		back->data = temp;
		
		if(front->next == back)
			break;
		front = front->next;
		back = back->prev;
	}
	
}

/**
 *  removes an item at a certain index.  Loops through with a counter
 *  and removes the item that mactches the index to counter
 */
void ll_remove_index(ll_node *head, int index){
	ll_node *cur;
	int i;
	
	if(index > head->size || index < 0)
		return;
	
	cur = head->next;
	for(i=0; i<index; i++){
		cur = cur->next;
	}
	
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	
	free(cur->data);
	free(cur);
	head->size--;
}




/**
 * this starts with the next of head node and hops nodes
 * until it reaches the index specified.  Returns a void
 * pointer to that data.
 */
void* ll_get_index(ll_node *head, int index){
	int i;
	ll_node *cur;
	
	cur = head->next;
	
	for(i=0; i<index; i++){
		cur = cur->next;
	}
	
	return (void *)cur->data;
}


/**
 * this function gets the first node after the head then
 * returns a type casted struct of the data
 */
void* ll_get_first(ll_node *head){
	ll_node *temp;
	temp = head->next;
	return (void *)temp->data;
}

/**
 *	Pop
 *
 *	This will retrive and remove first item in the list.  This acts in the stack method call
 */
void* pop(ll_node *head){
	ll_node *temp;
	temp = ll_get_first(head);
	
	//remove first link
	head->next->next->prev = head;
	head->next = head->next->next;
	
	head->size--;
	
	return temp;
}



/**
 * this will return the last node.  return type is
 * a void pointer to the data object in the node.
 */
void* ll_get_last(ll_node *head){
	ll_node *temp;
	temp = head->prev;
	return (void *)temp->data;
}

void* dequeue(ll_node *head){
	ll_node *temp;
	
	temp = ll_get_last(head);
	
	head->prev->prev->next = head;
	head->prev = head->prev->prev;
	
	head->size--;
	
	return temp;
}



/**
 * loops through each node starting with head->next and frees
 * the data object then frees the node.  Moves to the next node
 * and repeats.  After the loop is finished head is freed.
 */
void ll_free_list(ll_node *head){
	ll_node *cur, *temp;
	cur = ((ll_node *)head)->next;
	while(cur->data != NULL){
		temp = (ll_node *)cur->next;
		free(cur->data);
		free(cur);
		cur = temp;
	}
	
	free(head);
}

/**
 *	adds a node to the linked list in order based on the passed 
 *	comparison function.
 */
void ll_add_ordered(ll_node *head, void *d, ll_comp_func comparison){
	ll_node *cur;
	ll_node *temp;
	
	if(head->size == 0){
		ll_add_first(head, d);
	}else{
		temp = (ll_node *)malloc(sizeof(ll_node));
		temp->data = d;
		
		for(cur = head->next; cur->data != NULL && comparison(temp->data, cur->data) > 0; cur = cur->next)
			;
		
		temp->next = cur;
		temp->prev = cur->prev;
		cur->prev->next = temp;
		cur->prev = temp;
		
		head->size++;
	}
}

/**
 *	will remove a node based on the passed equals function
 */
void ll_remove_item(ll_node *head, void *d, ll_comp_func equals){
	ll_node *cur, *temp;
	
	for(cur = head->next; cur->data != NULL && equals(d, cur->data) > 0; cur = cur->next)
		;
	
	if(cur->data != NULL){
		temp = (ll_node *)malloc(sizeof(ll_node));
		temp->next = cur->next;
		temp->prev = cur->prev;
		
		cur->prev->next = temp->next;
		cur->next->prev = temp->prev;
		
		free(cur->data);
		free(cur);
		free(temp);
		head->size--;
	}
}
