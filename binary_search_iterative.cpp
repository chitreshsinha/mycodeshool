#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &V, int num) {
	int v_size = V.size();
	int max = v_size;
	int min = 0;
	int mid;

	while(min<=max) {
		mid = (min+max)/2;
		if(V[mid] == num) {
			return mid;
		} else if (num > V[mid]) {
			min = mid+1;
		} else if (num < V[mid]) {
			max = mid-1;
		}
	}
	return -1;
}

int main() {
    vector <int> V {10, 14, 19, 27, 33, 35, 42, 44};
    //vector <int> V {1, 2, 3, 4, 5, 7};
    int num = 19;
    cout << "pos: " << binarySearch(V, num) << endl;
    num = 15;
    cout << "pos: " << binarySearch(V, num) << endl;
}