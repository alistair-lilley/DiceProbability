//#ifndef MERGESORT_H
//#define MERGESORT_H

#include <iostream>
#include <time.h>

using namespace std;	

/* Merge sort file
 * 
 * Fuckin hell... i HATE CODING MERGE SORT FROM SCRATCH DX
 * might be borked but will test
 * should sort low to high
 * 
 * quick lookups while my keyboard is borked
 * 7 8 9 0 & () *
 */
 
 
 void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 +j);
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            *(arr + k) = L[i];
            i++;
        }
        else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        *(arr + k) = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        *(arr + k) = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int *arr,int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(A+i) << " ";
}

// Driver code
int main()
{
	srand(time(NULL));
    int *arr = new int[20];
	int a[20];
	for(int i=0;i<20;i++){
		a[i] = rand()%4+1;
	}
	/*for(int i=0;i<6;i++){
		cout << a[i] << endl;
	}*/	
	arr = a;
    int arr_size = sizeof(a) / sizeof(a[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
	cout << endl;
	
	bool sorted = true;
	for(int i=0;i<19;i++){
		if(*arr>*arr+i){
			sorted = false;
		}
	}
	cout << "sorted correctly: ";
	if(sorted){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
    return 0;
}


// #endif