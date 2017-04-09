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

int countSortedRotation(const vector<int> &V) {
	int left = 0;
	int right = V.size()-1;
	int v_size = right + 1;
	int mid;

	while(left<=right) {
		mid = left + (right-left)/2;
		if (V[left] <= V[right]) {
			return left;
		} else if(V[mid] <= V[(mid+1)%v_size] && V[mid] <= V[(mid-1)%v_size]) {
			return mid;
		} else if(V[mid] <= V[right]) {
			right = mid - 1;
		} else if (V[left] <= V[mid]) {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
    /*vector <int> V {42, 44, 10, 14, 19, 27, 33, 35};
    print(V);
    cout << "count: " << countSortedRotation(V) << endl;*/
    /*vector <int> V {27, 33, 35, 42, 44, 10, 14, 19};
    print(V);
    cout << "count: " << countSortedRotation(V) << endl;*/
    vector <int> V {95, 10, 14, 19, 27, 33, 35, 42, 44};
    print(V);
    cout << "count: " << countSortedRotation(V) << endl;
    return 0;
}