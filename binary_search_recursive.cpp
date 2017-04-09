#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &V, int min, int max, int num) {
	int mid = (min+max)/2;
	if(min>max) {
		return -1;
	} else if(V[mid] == num) {
		return mid;
	}

	if(num < V[mid]) {
		binarySearch(V, min, mid-1, num);
	} else {
		binarySearch(V, mid+1, max, num);
	}
}

int main() {
    vector <int> V {10, 14, 19, 27, 33, 35, 42, 44};
    //vector <int> V {1, 2, 3, 4, 5, 7};
    int num = 19;
    cout << "pos: " << binarySearch(V, 0, V.size(), num) << endl;
    num = 15;
    cout << "pos: " << binarySearch(V, 0, V.size(), num) << endl;
}