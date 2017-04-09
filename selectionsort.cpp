#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &V, int i, int j) {
    int temp;
    temp = V[i];
    V[i] = V[j];
    V[j] = temp;
}

void print(const vector <int> &V) {
    for(int i=0;i<V.size();i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &V) {
    int i, j, max_pos;
    for(i=0;i<V.size();i++) {
        max_pos = 0;
        for(j=0;j<V.size()-i;j++) {
            if(V[j] > V[max_pos]) {
                //cout << "max_pos = " << j<< endl;
                max_pos = j;
            }
        }
        //cout << "max_pos: " << max_pos << " j-1: " << j-1 << endl;
        swap(V, max_pos, j-1);
        print(V);
    }
}


void selectionSort2(vector<int> &V) {
    int i, j, min_pos;
    for(i=0;i<V.size()-1;i++) {
        min_pos = i;
        for(j=i+1;j<V.size();j++) {
            if(V[j] < V[min_pos]) {
                min_pos = j;
            }
        }
        swap(V, min_pos, i);
        print(V);
    }
}


int main () {
    //vector <int> V {14, 33, 27, 10, 35, 19, 42, 44};
    vector <int> V {2, 7, 4, 1, 5, 3};
    print(V);
    //selectionSort(V);
    selectionSort2(V);
    print(V);
}