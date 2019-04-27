/*
 * Hash.h
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */

#ifndef HASH_H_
#define HASH_H_

#include "List.h"
#include "types.h"

typedef int (*HashFunc)(void* );
typedef void* (*CompareFunc)(ListNode* head, void* hashKey);

typedef struct bucket {
	ListNode head;
}HashBucket;

typedef struct _Hash {
	HashFunc hashFunc;
	CompareFunc compareFunc;
	HashBucket ** buckets;
	int bucketNodeOffset;
	int maxSize;
}Hash;

Hash* HashCreate(int maxSize, int bucketNodeOffset, HashFunc hashFunc, CompareFunc compareFunc);
int HashInsert(Hash* hash, void* hashKey, ListNode* entry);
void* HashEntry(Hash* hash, void* hashKey);




#endif /* HASH_H_ */
