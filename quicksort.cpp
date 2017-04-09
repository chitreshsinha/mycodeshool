#include <iostream>
#include <vector>

using namespace std;

void print(const vector <int> &V) {
	int v_size = V.size();
	int i;
	for(i=0;i<v_size;i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

void swap(vector <int> &V, int a, int b) {
	int temp = V[a];
	V[a] = V[b];
	V[b] = temp;
}

int partition(vector <int> &V, int min, int max) {
	int pivot = V[max];
	int pIndex = min;
	int i;
	for(i=min;i<max;i++){
		if(V[i] <= pivot) {
			swap(V, i, pIndex);
			pIndex++;
		}
	}
	swap(V, max, pIndex);
	return pIndex;
}

void quickSort(vector <int> &V, int min, int max) {
	cout << "QuickSort - Min: " << min << " Max: " << max << endl;
	if (min < max) {
		cout << "Before Partition: ";
		print(V);
		int pIndex = partition(V, min, max);
		cout << "After Partition: ";
		print(V);
		quickSort(V, min, pIndex-1);
		quickSort(V, pIndex+1, max);
	}
}

int main() {
    //vector <int> V {14, 33, 27, 10, 35, 19, 42, 44};
    vector <int> V {2, 4, 1, 6, 8, 5, 3, 7};
    //vector <int> V {2, 7, 4, 1, 5, 3};
    print(V);
    quickSort(V, 0, V.size()-1);
    print(V);	
}