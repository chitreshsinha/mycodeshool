#include <iostream>
#include <vector>

using namespace std;

void print(const vector <int> &V) {
	int i;
	for(i=0;i<V.size();i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}

void swap(vector <int> &V, int i, int j) {
	int temp = V[i];
	V[i] = V[j];
	V[j] = temp;
}

void insertionSort(vector <int> &V) {
	int i, j, v_size = V.size(), pos;

	for(i=1;i<v_size;i++) {
		pos = i;
		for(j=pos;j>=0;j--) {
			if(V[pos] < V[j]) {
				swap(V, pos, j);
				pos = j;
			}
			//print(V);
		}
		print(V);
	}
}

int main() {
    vector <int> V {14, 33, 27, 10, 35, 19, 42, 44};
    //vector <int> V {2, 7, 4, 1, 5, 3};
    print(V);
    insertionSort(V);
    print(V);
}