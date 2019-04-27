#include "TimingWheel.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int TimerHash(void* p);
static void* Compare(ListNode* head, void* hashKey);

TimerWheel* TimerWheelCreate(int maxSize, int scale)
{
	TimerWheel* timerWheel = (TimerWheel*) malloc(sizeof(TimerWheel));
	if (NULL == timerWheel) {
		return NULL;
	}

	timerWheel->chain = HashCreate(8, 0 , TimerHash, Compare);

	timerWheel->rollingIdx = 0;
	timerWheel->maxSize = maxSize;
	timerWheel->scale = scale;
	timerWheel->entryIdx = 0;
	return timerWheel;
}

Timer* TimerCreate(TimerWheel* timerWheel, int interval, TimerCbFunc cb,
		void* param)
{
	Timer* timer = (Timer*) malloc(sizeof(Timer));
	timer->cbFunc = cb;
	timer->cbParam = param;
	timer->interval = interval;
	timer->id = timerWheel->entryIdx++;
	return timer;

}

int TimerAdd(TimerWheel* timerWheel, Timer* timer)
{
	int scaleCount = timer->interval/timerWheel->scale;
	int afterWholeCycle = scaleCount/timerWheel->maxSize;
	int afterScaleCount = scaleCount%timerWheel->maxSize;
	timer->afterCycle = afterWholeCycle;

//	ListNode* head = HashEntryChain(timerWheel->chain, afterScaleCount + timerWheel->rollingIdx);

	HashInsert(timerWheel->chain, (void*)&afterScaleCount, timer->node);
}

int TimerDelete()
{
	return 0;
}

int TimerHash(void* p)
{
	return *(int *) p;
}

void* Compare(ListNode* head, void* hashKey)
{
	return NULL;
}

