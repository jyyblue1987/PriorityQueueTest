#include "PriorityNode.hpp"

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
	back_ = front_ = NULL;
	item_count = 0;
}

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& a_priority_queue)
{
	back_ = front_ = NULL;
	item_count = 0;

	PriorityNode<ItemType> *p = a_priority_queue._front;

	while (p != NULL)
	{
		PriorityNode<ItemType> *n = new PriorityNode(p.item_, p.pri);
		if (back_ == NULL)
			front_ = n;						
		else
			back_->next_ = n;			
		
		back_ = n;
		item_count++;

		p = p->getNext();
	}
}

template<typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
	PriorityNode<ItemType> *p = front_;
	while (p != NULL)
	{
		PriorityNode<ItemType> *next = p->getNext();
		delete p;
		p = next;
	}

	front_ = back_ = 0;
	item_count = 0;
}

template<typename ItemType>
void PriorityQueue<ItemType>::enqueue(const ItemType& new_entry, int priority) //adds by priority
{
	PriorityNode<ItemType> *p = front_;
	PriorityNode<ItemType> *prev = NULL;

	while (p != NULL)
	{
		PriorityNode<ItemType> *next = p->getNext();
		
		if (p->getPriority() < priority)
			break;

		prev = p;
		p = next;
	}

	PriorityNode<ItemType> *n = new PriorityNode<ItemType>(new_entry, priority);

	if (prev == NULL)
	{
		// insert header
		n->setNext(front_);
		front_ = n;
	}
	else
	{
		n->setNext(prev->getNext());
		prev->setNext(n);
		if (n->getNext() == NULL) // if tailed
			back_ = n;
	}

	item_count++;
}

template<typename ItemType>
void PriorityQueue<ItemType>::dequeue() // removes element from front of the queue
{
	// remove front
	if (isEmpty())
		return;

	PriorityNode<ItemType> *next = front_->getNext();
	delete front_;
	front_ = next;
	item_count--;
	
	if (isEmpty())
		back_ = NULL;
}

template<typename ItemType>
ItemType PriorityQueue<ItemType>::front() const // returns a copy of the front element
{
	if (front_ == NULL)
		return ItemType();

	return front_->getItem();
}

template<typename ItemType>
PriorityNode<ItemType>* PriorityQueue<ItemType>::getFrontPtr() const //returns front_ pointer
{
	return front_;
}

template<typename ItemType>
int PriorityQueue<ItemType>::size() const // returns the number of elements in the queue
{
	return item_count;
}

template<typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const // returns true if no elements in the queue
{
	return item_count == 0;
}
