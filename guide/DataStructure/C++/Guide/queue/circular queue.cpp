// circular queue

#include <iostream>

using namespace std;

int front = -1;
int rear = -1;
const int capacity = 3;
int size  = 0;
int arr[capacity];

void enqueue(int item) {

    //	cout << " front " << front << " rear " << rear << " size " << size  << endl;
    // overflow
	if(size == capacity) return;
	
    if(front == -1) front = 0;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	size ++;
}


void dequeue() {
    //	cout << " front " << front << " rear " << rear << " size " << size  << endl;
	
    // underflow
    if(size == 0) return;
	
    front = (front + 1) % capacity;
	size --;
}


void printQueue() {

	// underflow
	if(front == -1) return;

	while(front != rear) {

		cout << arr[front] << " ";
		front = (front + 1) % capacity;

	}
	cout << arr[front] << endl;

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

// 30 40 50