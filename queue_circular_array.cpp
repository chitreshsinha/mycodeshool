#include <iostream>

using namespace std;

int front;
int rear;


void print(int *&a, int size) {
	for(int i=0;i<size;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void isEmpty(int *&a) {
	if 
}

void enqueue(int *&a, int num) {


	a[rear+1] = num;
	rear++;
}

void dequeue(int *&a) {
	front = front+1;
} 

int front(int *&a) {
	return a[front];
}


int main () {
	int size;
	cout << "Enter size of queue: ";
	cin >> size;
	
	int *a = new int[size];
	front = -1;
	rear = -1;

	for(int i=0;i<size;i++) {
		enqueue(a, i+1);
	}

	print(a, size);

	dequeue(a);
	//dequeue(a);
	//dequeue(a);
	//dequeue(a);
	//dequeue(a);
	return 0;

}