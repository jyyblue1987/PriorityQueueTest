#include <iostream>

using namespace std;

#include "PriorityNode.hpp"
#include "PriorityQueue.hpp"


int main()
{
	PriorityQueue<int> queue;

	queue.enqueue(100, 2);
	queue.enqueue(50, 3);
	queue.enqueue(40, 4);

	PriorityQueue<int> queue2 = queue;
	queue.enqueue(70, 6);

	cout << "Queue1" << endl;
	while (!queue.isEmpty())
	{
		cout << "Value: " << queue.front() << " Priority: " << queue.getFrontPtr()->getPriority() << endl;
		queue.dequeue();
	}

	cout << "Queue2" << endl;
	while (!queue2.isEmpty())
	{
		cout << "Value: " << queue2.front() << " Priority: " << queue2.getFrontPtr()->getPriority() << endl;
		queue2.dequeue();
	}

	return 0;
}