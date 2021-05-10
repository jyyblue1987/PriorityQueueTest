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

	while (!queue.isEmpty())
	{		
		cout << "Value: " << queue.front() << " Priority: " << queue.getFrontPtr()->getPriority() << endl;
		queue.dequeue();
	}


	return 0;
}