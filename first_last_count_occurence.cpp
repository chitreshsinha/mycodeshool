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

int binarySearch(vector <int> &V, int num, bool searchFirst) {
	int min = 0;
	int max = V.size()-1;
	int mid, result = -1;

	while(min <= max) {
		mid = min + (max-min)/2;
		if(V[mid] == num) {
			result = mid;
			if (searchFirst) {
				max -= 1;
			} else {
				min += 1;
			}
		} else if (num < V[mid]) {
			max = mid-1;
		} else if (num > V[mid]) {
			min = mid+1;
		}
	}
	return result;
}

int main() {
	vector <int> V {2, 4, 10, 10, 10, 18, 20};
	//vector <int> V {2, 4, 10, 10, 10, 18, 20};
	print(V);
	int num;
	cin >> num;
	int first = binarySearch(V, num, true);
	int last = binarySearch(V, num, false);
	cout << "first occurence: " << first << endl;
	cout << "last occurence: " << last << endl;
	cout << "total count: " << last - first + 1 << endl;
	return 0;
}