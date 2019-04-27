/*
 * List.c
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ListHeadInit(ListNode* node)
{
	node->next = NULL;
	node->prev = NULL;
}

// head next指向一下元素，prev指针指向最后一个元�?
void ListInsert(ListNode* head, ListNode* node)
{
	if(head->next == NULL) {
		head->next = node;
		head->prev = node;
		node->prev = head;
		node->next = NULL;
		return ;
	}

	node->prev = head->prev;
	node->next = NULL;

	head->prev->next = node;
	head->prev = node;
	return ;
}

void ListDelete(ListNode* node)
{
	if(NULL == node->prev) {
		return ;
	}

	node->prev->next = node->next;
	if(NULL == node->next) {
		return ;
	}
	node->next->prev = node->prev;
	return ;
}

void ListTrace(ListNode* head)
{
	printf("List Head addr = %p \n", head);
	ListNode* node = head->next;
	while(node != NULL) {
		printf(" %p<-%p->%p \n", node->prev, node, node->next);
		node = node->next;
	}
}
