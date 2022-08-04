#include <stdio.h>
void input_array(int n, int a[]){
    for (int i = 0; i < n; i++){
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

void print_array(int n, int a[]){
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}

void main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);//input of size of array
    int a[n];

    input_array(n, a);//input of array

    printf("Before Sorting : \n");
    print_array(n, a);
    printf("\n");

    insertion_sort(n,a);//sorting array using Selection Sort Algorithm

    printf("After Sorting : \n");
    print_array(n, a);
    printf("\n");
}