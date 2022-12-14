#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int l, int m, int r){
	// Merges two subarrays of arr[].
	// First subarray is arr[l..m]
	// Second subarray is arr[m+1..r]
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // create temp arrays 
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 

// Function to print an array
void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// function to take input for array
void input_array(int n, int arr[]){
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
}

int main(){
	int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);//input of size of array
    int arr[n];

    int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Enter elements of array : \n");
    input_array(arr_size,arr);//input of array
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}