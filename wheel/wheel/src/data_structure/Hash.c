/*
 * Hash.c
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */
#include "Hash.h"

#include <stdlib.h>


Hash* HashCreate(int maxSize, int bucketNodeOffset, HashFunc hashFunc, CompareFunc compareFunc)
{
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	hash->hashFunc = hashFunc;
	hash->maxSize = maxSize;
	hash->bucketNodeOffset = bucketNodeOffset;
	hash->buckets = (HashBucket**)malloc(maxSize*sizeof(HashBucket));
	hash->compareFunc = compareFunc;
	return hash;
}

int HashInsert(Hash* hash, void* hashKey, ListNode* entry)
{
	int idx = hash->hashFunc(hashKey);
	if(idx >= hash->maxSize) {
		return -1;
	}
	HashBucket* bucket = hash->buckets[idx];
	ListInsert(&bucket->head, entry);
	return 0;
}

void* HashEntry(Hash* hash, void* hashKey)
{
	int idx = hash->hashFunc(hashKey);

	HashBucket* bucket = hash->buckets[idx];
	return hash->compareFunc(&bucket->head, hashKey);
}

void* HashEntryChain(Hash* hash, void* hashKey)
{
	int idx = hash->hashFunc(hashKey);
	return (void*)&hash->buckets[idx]->head;
}

