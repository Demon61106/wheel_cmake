/*
 * debug.c
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */

#include "../data_structure/List.h"
#include "debug.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _DebugElem {
	ListNode node;
	int testValue1;
	int testValue2;
}DebugElem;

void TestList()
{
	ListNode head;
	ListHeadInit(&head);

	for(int i = 0; i < 5; ++i) {
		DebugElem* elem = (DebugElem*)malloc(sizeof(DebugElem));
		elem->testValue1 = i;
		elem->testValue2 = i + 10;
		ListInsert(&head, &(elem->node));
	}

	ListTrace(&head);

	DebugElem* elem;
	ListForEachEntry(elem, &head, node) {
		printf("elem = %d , %d\n", elem->testValue1, elem->testValue2);
	}
}

void TestHash()
{

}
