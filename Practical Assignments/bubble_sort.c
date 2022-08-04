#include<stdio.h>
void input_array(int n, int a[]){
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
}

void bubble_sort(int n, int a[]){
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            //swap if current element is greater than next element
            if (a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void print_array(int n, int a[]){
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}

void main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);//input of size of array
    int a[n];

    input_array(n,a);//input of array

    printf("Before Sorting : \n");
    print_array(n,a);
    printf("\n");

    bubble_sort(n,a);//sorting array using Bubble Sort Algorithm
    
    printf("After Sorting : \n");
    print_array(n,a);
    printf("\n");
}