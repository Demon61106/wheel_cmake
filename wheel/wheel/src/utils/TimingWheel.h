/*
 * TimingWheel.h
 *
 *  Created on: 2019-3-9
 *      Author: 46631
 */

#ifndef TIMINGWHEEL_H_
#define TIMINGWHEEL_H_

#include "../data_structure/Hash.h"

typedef void (*TimerCbFunc)(void* );

typedef struct _Timer {
	ListNode* node;
	int id;
	int interval;
	int afterCycle;
	TimerCbFunc cbFunc;
	void* cbParam;
}Timer;


typedef struct _TimerWheel {
	int maxSize;
	int rollingIdx;
	int entryIdx;
	int scale;
	Hash* chain;
}TimerWheel;


#endif /* TIMINGWHEEL_H_ */
