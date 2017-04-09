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

void print_reverse_recursive(Node *temp) {
	if(temp == NULL) {
		return;
	}

	print_reverse_recursive(temp->next);
	cout << temp->data << "-";
}


int main () {
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
	insert(4, 4);
	print();
	cout << "Print Reversed: "; 
	print_reverse_recursive(head);
	cout << "\n";
	print();
	return 0;

}