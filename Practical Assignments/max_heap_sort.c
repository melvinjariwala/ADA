#include <stdio.h>
 
// Function to swap the position of two elements
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i){
	// Find largest among root, left child and right child
	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// Swap and continue heapifying if root is not largest
	// If largest is not root
	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}
 
// Main function to do heap sort
void heapSort(int arr[], int N){
	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}
 
// Function to print array of size n
void printArray(int arr[], int N){
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
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

	printf("Unsorted Array:\n");
	printArray(arr,arr_size);

	// Function call
	heapSort(arr, arr_size);
	printf("Sorted Array:\n");
	printArray(arr, arr_size);
	return 0;
}