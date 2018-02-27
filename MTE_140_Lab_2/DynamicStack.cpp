#include "DynamicStack.hpp"
#include <cstdlib>
#include <iostream>
//using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	capacity_ = 16;
	init_capacity_ = 16;
	size_ = 0;
	items_ = new StackItem[size_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	capacity_ = capacity;
	init_capacity_ = capacity;
	size_ = 0;
	items_ = new StackItem[size_];
}

DynamicStack::~DynamicStack()
{
	delete[] items_;
	items_ = nullptr;
}

bool DynamicStack::empty() const
{
	return size_ == 0;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ == capacity_)
		capacity_ *= 2;
	items_[size_] = value;
	size_ ++;
}

StackItem DynamicStack::pop()
{
	if (size_ == 0)
	{
		std::cout << "Nothing to pop" << std::endl;
		return EMPTY_STACK;
	}
	size_--;
	if ((size_ <= 0.25* capacity_) && (0.5* capacity_ >= init_capacity_))
	{
		capacity_ *= 0.5;
	}
	return items_[size_];


}

StackItem DynamicStack::peek() const
{
	if (size_ == 0)
		return EMPTY_STACK;
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	for(int i = size_ - 1; i >= 0; i--)
	{
		std::cout << items_[i] << std::endl;
	}
}
