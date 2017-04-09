#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *head;

void insert(int data, int pos) {
	Node *temp = new Node;
	Node *temp1 = head;

	if (pos == 1) {
		temp->data = data;
		temp->next = head;
		head = temp;
		return;
	}

	int count_pos=1;
	while(count_pos != pos-1) {
		++count_pos;
		temp1 = temp1->next;
	}

	temp->data = data;
	temp->next = temp1->next;
	temp1->next = temp;	
	return;
}

void print() {
	Node *temp = head;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return;
}

void reverse_recursive1(Node *temp, Node *prev) {
	if (temp == NULL || temp->next == NULL) {
		if(temp == NULL) {
			return;
		} else {
			temp->next = prev;
			head = temp;
		}
		return;
	}

	Node *next = NULL;
	next = temp->next;
	temp->next = prev;
	prev = temp;
	temp = next;

	reverse_recursive1(temp, prev);
}

void reverse_recursive2(Node *temp) {
	if(temp->next == NULL) {
		head = temp;
		return;
	}

	reverse_recursive2(temp->next);
	Node *curr = temp->next;
	curr->next = temp;
	temp->next = NULL;
}


int main() {
	head = NULL;
	print();
	insert(3, 1);
	print();
	insert(2, 2);
	print();
	insert(1, 3);
	print();
	insert(6, 1);
	print();
	insert(7, 1);
	print();
	insert(5, 3);
	print();
	cout << "Reversed: "; 
	reverse_recursive1(head, NULL);
	print();
	insert(4, 4);
	print();
	cout << "Reversed: "; 
	reverse_recursive2(head);
	print();
	return 0;
}