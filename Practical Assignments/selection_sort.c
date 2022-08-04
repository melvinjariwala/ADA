#include <stdio.h>
void input_array(int n, int a[]){
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
}

void swap(int *x, int *y){
	int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int n, int a[]){
    int temp,min;
    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (a[min]>a[j]){
                min=j;
            }
			swap(&a[j],&a[min]);
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
    printf("Enter size of array : ");
    scanf("%d", &n);//input of size of array
    int a[n];

    input_array(n, a);//input of array

    printf("Before Sorting : \n");
    print_array(n, a);
    printf("\n");

    selection_sort(n,a);//sorting array using Selection Sort Algorithm

    printf("After Sorting : \n");
    print_array(n, a);
    printf("\n");
}