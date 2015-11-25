#include "loop_queue.h"

LoopQueue::LoopQueue(int size)
{
	len = size + 1;
	data = (uint8_t*)malloc(len * sizeof(uint8_t));

	start = end = 0;
}

LoopQueue::~LoopQueue()
{
	if (NULL != data)
		free(data);
}

/************************************************************************/
/* 得到 下标 长度 和 小标对应的值                                                                     */
/************************************************************************/
int LoopQueue::get_start()
{
	return start;
}
int LoopQueue::get_end()
{
	return end;
}
int LoopQueue::get_len()
{
	return len;
}
uint8_t LoopQueue::get_byte(int index)
{
	return data[index];
}

/************************************************************************/
/* 是否为空                                                                     */
/************************************************************************/
bool LoopQueue::empty()
{
	return start == end;
}

/************************************************************************/
/* 队列是否已满                                                                     */
/************************************************************************/
bool LoopQueue::full()
{
	return start == ((end + 1) % len);
}

/************************************************************************/
/* 存储的数据的个数 byte的个数                                                                     */
/************************************************************************/
int LoopQueue::size()
{
	return (end - start + len) % len;
}

/**
 * 返回第一个byte
 */
uint8_t LoopQueue::front()
{
    return data[start];
}

/************************************************************************/
/* 压入 一个数据 如果当前队列是满的 直接返回false                                                                     */
/************************************************************************/
bool LoopQueue::push(uint8_t val)
{
	if (full())	return false;

	data[end] = val;
	end = (end + 1) % len;

	return true;
}

/************************************************************************/
/* 弹出一个 数据 当前队列是空的 返回false                                                                     */
/************************************************************************/
bool LoopQueue::pop()
{
	if (empty())	return false;

	start = (start + 1) % len;

	return true;
}

/************************************************************************/
/* 清空队列                                                                     */
/************************************************************************/
void LoopQueue::clear()
{
	start = end = 0;
}

