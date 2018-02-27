#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
}

CircularQueue::CircularQueue(unsigned int capacity)
{
}

CircularQueue::~CircularQueue()
{
}

bool CircularQueue::empty() const
{    
}

bool CircularQueue::full() const
{
}

int CircularQueue::size() const
{  
}

bool CircularQueue::enqueue(QueueItem value)
{
}

QueueItem CircularQueue::dequeue()
{
}

QueueItem CircularQueue::peek() const
{
}

void CircularQueue::print() const
{
}
