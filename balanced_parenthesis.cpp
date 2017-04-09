#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack <char> s;
	char data;
	int n, i;

	cin >> n;
	vector <char> a(n);

	for (i=0;i<n;i++) {
		cin >> a[i];
	}

	for (i=0;i<n;i++) {
		//cout << a[i] << endl;
		if (a[i] == '(' || a[i] == '{' || a[i] == '[') {
			s.push(a[i]);
		}
		else if (a[i] == ')' || a[i] == '}' || a[i] == ']') {
			if (s.empty()) {
				cout << "Empty: Not balanced" << endl;				
			}
			else if (s.top() == '(' && a[i] == ')'){
				s.pop();
			} 
			else if (s.top() == '{' && a[i] == '}'){
				s.pop();
			} 
			else if (s.top() == '[' && a[i] == ']'){
				s.pop();
			} 
			else {
				cout << "Not balanced" << endl;
			}
		}
	}
	return 0;
}
