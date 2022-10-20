#include <iostream>

using namespace std;

int front = -1;
int rear = -1;
const int capacity = 3;
int size = 0;
int arr[capacity];

void enqueue(int item) {

	// overflow
	if(rear == capacity - 1) return;

	// first item
	if(front == -1) front = 0;

	rear ++;
	arr[rear] = item;
	size ++;
}


void dequeue() {

	// empty and all deleted
	if(front == -1 || front > rear) return;
	
	
	front ++;
	size --;
}


void printQueue() {
	for (int i = front; i <= rear && rear != -1; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	enqueue(10);
	enqueue(20);
	enqueue(30);

	dequeue();
	dequeue();
	enqueue(40);
	enqueue(50);
	printQueue();

	return 0;
}
