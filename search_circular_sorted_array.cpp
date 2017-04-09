#include <iostream>
#include <vector>

using namespace std;

void print(const vector <int> &V) {
	int v_size = V.size();
	int i;
	for(i=0;i<v_size;i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}

int searchCircularSortedArray(vector <int> &V, int num) {
	int left = 0;
	int right = V.size()-1;
	int v_size = right+1;
	int mid;

	while(left<=right) {
		mid = left + (right-left)/2;
		if(V[mid] == num) {
			return mid;
		} else if(V[mid] <= V[right]) {
			if(num > V[mid] && num <= V[right]) {
				left = mid+1;
			} else {
				right = mid-1;
			}
		} else if(V[mid] >= V[left]) {
			if(num < V[mid] && V[left] <= num) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
	}
	return -1;

}

int main() {
   	//vector <int> V {42, 44, 10, 14, 19, 27, 33, 35};
    vector <int> V {27, 33, 35, 42, 44, 10, 14, 19};
    //vector <int> V {95, 10, 14, 19, 27, 33, 35, 42, 44};
    print(V);
    cout << "pos: " << searchCircularSortedArray(V, 10) << endl;
    print(V);
    cout << "pos: " << searchCircularSortedArray(V, 33) << endl;
    return 0;
}