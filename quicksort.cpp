// C++ QuickSort Algorithm
// -----------------------
// Asymptotic runtime complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n^2)
// -----------------------
// Space: 0(log n)
// -----------------------
// NOT stable
// -----------------------
// Resources - GeeksforGeeks
//

#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// -------------------------

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end){
    // Let the pivot be the last element
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

void quickSort(int arr[], int start, int end){
    if(start < end){
        // Setting the right index for the pivot element
        int piv = partition(arr, start, end);

        // Sorting the parts before and after the pivot
        quickSort(arr, start, piv - 1);
        quickSort(arr, piv + 1, end);
    }
}

// -------------------------

int main(){
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
