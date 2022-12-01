	#include <stdio.h>
	void inputArray(int n, int a[]){
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	}

	void insertion_sort(int n, int a[]){
	for (int i = 1; i < n; i++){
		int key = a[i], j=i-1;
		while (j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = key;
	}
	}

	int binary_search(int n, int a[], int key){
	int low=0;
	int high=n-1;

	if (key==a[low]){
		return low;
	}
	else if(key==a[high]){
		return high;
	}
	
	while (high>low){
		int mid = low+(high-low)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(key<a[mid]){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return 0;
	}

	void print_array(int n, int a[]){
	for (int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	}

	int main(int argc, char **argv){
	int size;
	printf("Enter the size of array : ");//input of size of array
	scanf("%d", &size);
	int a[size],key;

	printf("Enter elements of array : \n");
	inputArray(size,a);//input of element of array

	//sorting of elements in array as it is necessary in binary search
	insertion_sort(size,a);
	printf("Array after sorting : \n");
	print_array(size,a);

	printf("Enter the element to be found : ");
	scanf("%d", &key);//input of element to be found

	//binary_search function call to find element in sorted array
	int pos=binary_search(size,a,key);//returns index of array if element found else return 0
	pos?printf("Element found at index : %d\n", pos):printf("Element not found!\n");
	printf("(According to 0 indexing)");
	}