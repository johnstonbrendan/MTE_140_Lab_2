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
	items_ = new QueueItem[capacity_];

}

CircularQueue::CircularQueue(unsigned int capacity)
{
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	if (capacity == 0)
		capacity_ = 16;
	else
		capacity_ = capacity;
	items_ = new QueueItem[capacity_];
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
//	if (size_ == 0)
//	{
//		head_ = 0;
//		tail_ = 0;
//	}
	items_[tail_] = value;
	size_++;
	if (tail_ == capacity_ - 1)
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
//	int temp = head_;
	QueueItem prev = items_[head_];
	if (head_ == capacity_ - 1)
			head_ = 0;
	else
		head_++;
//	for (int i = 0; i < size_; i++)
//	{
//		items_[i] = items_[i+1];
//	}
	size_--;
	return prev;
}

QueueItem CircularQueue::peek() const
{
//	print();
//	std::cout << endl << items_[head_] << endl;
	if (size_ == 0)
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{ //may need to change case for tail_ > head> has to print in other direction
//	if (head_ >= tail_)
//	{
//		for(int i = tail_; i < size_; i++)
//		{
//			std::cout << items_[i] << std::endl;
//		}
//	}
//	else
//	{
		for (int i = head_; i < size_; i++)
		{
			std::cout << items_[i%capacity_] << std::endl;
		}
//	}
}
