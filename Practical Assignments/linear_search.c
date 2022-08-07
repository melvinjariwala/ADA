#include<stdio.h>

void input_array(int n, int a[]){
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}

int linear_search(int n, int a[], int key){
	for (int i = 0; i < n; i++){
		if (a[i] == key){
			return i+1;
		}
	}
	return -1;
}

int main(){
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n], key;

	printf("Enter the elements of array : \n");
	input_array(n,a);
	printf("\n");

	printf("Enter key : ");
	scanf("%d", &key);

	int pos = linear_search(n,a,key);

	if(pos>=0){
		printf("\nElement Position : %d\nElement Index : %d\n",pos,pos-1);
	}
	else{
		printf("\nElement not found!\n");
	}
	return 0;
}