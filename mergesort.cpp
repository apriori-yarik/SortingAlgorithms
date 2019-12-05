#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int left, int mid, int right){
    // creating iterators in order to know which is the current element in the left/right part
    int it1 = 0;
    int it2 = 0;

    int result[right - left];

    // sorting method
    while(left + it1 < mid && mid + it2 < right){
        if(a[left + it1] < a[mid + it2]){
            result[it1 + it2] = a[left + it1];
            it1++;
        }
        else{
            result[it1 + it2] = a[mid + it2];
            it2++;
        }
    }

    // if there are any elements left in one of the parts(left/right)
    while(left + it1 < mid){
        result[it1 + it2] = a[left + it1];
        it1++;
    }
    while(mid + it2 < right){
        result[it1 + it2] = a[mid + it2];
        it2++;
    }

    for(int i = 0; i < it1 + it2; i++){
        a[left + i] = result[i];
    }
}

void mergeSortRecursive(int a[], int left, int right){
    // base of recursion
    if(left + 1 >= right){
        return;
    }

    // setting the middle index 
    int mid = (left + right) / 2;

    mergeSortRecursive(a, left, mid);
    mergeSortRecursive(a, mid, right);
    merge(a, left, mid, right);
}

void printArray(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {8, 9, 3, 2, 6, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSortRecursive(a, 0, n);
    printArray(a, n);
    return 0;
}
