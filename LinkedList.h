/*
 * LinkedList.h
 *
 *  Created on: Aug 16, 2010
 *      Author: kpgwinnup
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int (*ll_comp_func)(void *, void *);

typedef struct ll_node{
	void *data;
	struct ll_node *next;
	struct ll_node *prev;
	int size;
}ll_node;

void* ll_linkedlist_init();

/**
 *	Stack Methods
 *	the following methods integrate with the linked list methods but have standard stack names
 *	and custom code if needed.
 */
void ll_push(ll_node *head, void *d);  //stack method name
void* ll_pop(ll_node *head);

/**
 *	Queue methods
 */
void ll_enqueue(ll_node *head, void *d);


/**
 * Method
 * 		ll_get_first(node *head)
 * 		insert a node at the front of the list
 * Parameter
 * 		pointer to your list
 * Return
 * 		returns the data portion of the first node
 */
void ll_add_first(ll_node *head, void *d);

/**
 * Method
 * 		ll_add_last(node *head)
 * 		insert a node at the front of the list
 * Parameter
 * 		pointer to your list
 * Return
 * 		returns the data portion of the first node
 */
void ll_add_last(ll_node *head, void *d);


/**
 * Method
 * 		ll_reverse(ll_node *head)
 * 		this will reverse the linked list
 * Parameter
 * 		pointer to your list head
 * Return
 * 		nothing is returned
 */
void ll_reverse(ll_node *head);
void ll_remove_index(ll_node *head, int index);

/**
 *	Added Nov 2, 2010
 *	Method
 *		ll_remove_item(ll_node *head, void *d, ll_comp_func comparison)
 *		this will remove an item based on the function passed
 *	Parameters
 *		pointer to head, element you want to remove, function that compares two elements
 *	Return
 *		nothing is returned
 */
void ll_remove_item(ll_node *head, void *d, ll_comp_func comparison);

/**
 *	Method
 *		the three methods below
 *	Return
 *		a void pointer to the first, last or indexed node
 */
void* ll_get_first(ll_node *head);
void* ll_get_last(ll_node *head);
void* ll_get_index(ll_node *head, int index);


/**
 * Method
 * 		ll_free_list(ll_node *head)
 * 		frees every object in your list and the list nodes
 * Parameter
 * 		pointer to your list head
 * Return
 * 		nothing is returned
 */
void ll_free_list(ll_node *head);


/**
 *	Added Nov, 2 2010
 *	Method
 *		ll_add_ordered(ll_node *head, void *d, ll_comp_func comparison)
 *	Parameters
 *		pointer to head, element to add, function which compares
 *	Return
 *		nothing is returned
 */
void ll_add_ordered(ll_node *head, void *d, ll_comp_func comparison);

/**
 * Added Feb 20, 2012
 * Method
 *		ll_search(ll_node *head, void *d, ll_comp_func comparison)
 * Parameters
 *		pointer to head, element to match, function which compares
 * Return
 * 		void pointer to data element of the first item matching your query
 */
void* ll_search(ll_node *head, void *d, ll_comp_func comparison);

#endif
