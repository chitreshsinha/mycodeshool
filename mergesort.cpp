#include <iostream>
#include <vector>

using namespace std;


void print(const vector <int> &V) {
    int i, v_size=V.size();
    for(i=0;i<v_size;i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

void swap(vector <int> &V, int i, int j) {
    int temp = V[i];
    V[i] = V[j];
    V[j] = temp;
}

void merge(vector <int> &V, int min, int mid, int max) {
    cout << "Merge: " << endl;
    int i=min, j=mid+1;
    int k=min;
    vector <int> temp (V);
    while(i<mid+1 && j<max+1) {
        if(V[i] <= V[j]) {
            temp[k] = V[i];
            i++;
            k++;
        } else {
            temp[k] = V[j];
            j++;
            k++;
        }
    }
    if (i == mid+1) {
        while(j<max+1) {
            temp[k] = V[j];
            j++;
            k++;
        }
    } else if (j == max+1) {
        while(i<mid+1) {
            temp[k] = V[i];
            i++;
            k++;
        }
    }
    /*i = max+1;
    while(i<V.size()) {
        temp[k] = V[i];
        i++;
        k++;
    }*/
    //print(V);
    V = temp;
}

void mergeSort(vector <int> &V, int min, int max) {
    cout << "min: " << min << " max: " << max << endl;
    if(max == min+1 || max == min) {
        if(V[min]>V[max]) {
            cout << "swap: " << V[min] << ", " << V[max] << endl;
            swap(V, min, max);
        }
        return;
    }
    print(V);
    int mid = (min+max)/2;
    mergeSort(V, min, mid);
    mergeSort(V, mid+1, max);
    cout << "!!!min: " << min << ", mid: " << mid << " max: " << max << endl;
    print(V);
    merge(V, min, mid, max);
    print(V);
}


int main () {
    //vector <int> V {14, 33, 27, 10, 35, 19, 42, 44};
    //vector <int> V {2, 4, 1, 6, 8, 5, 3, 7};
    vector <int> V {2, 7, 4, 1, 5, 3};
    print(V);
    mergeSort(V, 0, V.size()-1);
    print(V);
}