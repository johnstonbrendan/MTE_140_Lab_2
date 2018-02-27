#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = 16;
	items_ = new QueueItem[size_];

}

CircularQueue::CircularQueue(unsigned int capacity)
{
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = capacity;
	items_ = new QueueItem[size_];
}

CircularQueue::~CircularQueue()
{
	delete[] items_;
}

bool CircularQueue::empty() const
{    
	return size_ == 0;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (size_ == capacity_)
		return false;
	if (size_ == 0)
	{
		head_ = 0;
		tail_ = head_;
	}
	items_[size_] = value;
	size_++;
	if (tail_ == capacity_)
		tail_ = 0;
	else
		tail_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if (size_ == 0)
	{
		return EMPTY_QUEUE;
	}
	int temp = head_;
	if (head_ == 0)
		head_ = capacity_;
	else
		head_++;
	size_--;
	return items_[temp];
}

QueueItem CircularQueue::peek() const
{
	if (size_ == 0)
		return EMPTY_QUEUE;
	return items_[0];
}

void CircularQueue::print() const
{
	for (int i = head_; i < size_; i++)
	{
		std::cout << items_[i] << std::endl;
	}
}
