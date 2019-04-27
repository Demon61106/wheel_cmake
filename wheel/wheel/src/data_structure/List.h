/*
 * List.h
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */

#ifndef LIST_H_
#define LIST_H_

#define OffsetOf(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)


#define ContainerOf(ptr, type, member) ({ \
		const typeof(((type *)0)->member ) *__mptr = (ptr); \
		(type *)( (char *)__mptr - OffsetOf(type, member) );})


/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer. 业务结构体成员链表结点的指针
 * @type:	the type of the struct this is embedded in. 业务结构体类�?
 * @member:	the name of the list_head within the struct. 业务结构体成员链表结点的成员
 */
#define ListEntry(ptr, type, member) \
	ContainerOf(ptr, type, member)

/**
 * list_first_entry - get the first element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define ListFirstEntry(ptr, type, member) \
	ListEntry((ptr)->next, type, member)

/**
 * list_next_entry - get the next element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
#define ListNextEntry(pos, member) \
	ListEntry((pos)->member.next, typeof(*(pos)), member)

/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop cursor.
 * @head:	the head for your list.
 */
#define ListForEach(head, pos) \
	for (pos = (head)->next; pos != NULL; pos = pos->next)

/**
 * list_for_each_entry	-	iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
#define ListForEachEntry(pos, head, member) \
	for (pos = ListFirstEntry(head, typeof(*pos), member);	\
	     &pos->member != NULL;					\
	     pos = ListNextEntry(pos, member))


typedef struct _ListHead {
	struct _ListHead* prev;
	struct _ListHead* next;
}ListNode;

void ListHeadInit(ListNode* node);

void ListInsert(ListNode* head, ListNode* node);

void ListDelete(ListNode* node);

void ListTrace(ListNode* head);


#endif /* LIST_H_ */
