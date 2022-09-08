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
    while (high>low){
        int mid = low+(high-low)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(key>a[low] && key<a[mid]){
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
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int a[size],key;

    printf("Enter elements of array : \n");
    inputArray(size,a);

    insertion_sort(size,a);
    printf("Array after sorting : \n");
    print_array(size,a);

    printf("Enter the element to be found : ");
    scanf("%d", &key);

    int pos=binary_search(size,a,key);
    pos?printf("Element found at index : %d\n", pos):printf("Element not found!\n");
}