	#include <stdio.h>
void input_coins(int n, int* a){
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}

void print_array(int n, int* a){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int make_a_change(int n, int a, int diff){
	int A[n+1][diff+1];
	for (int i = 0; i < n+1; i++){
		for(int j = 0; j < n; j++){
			
		}
	}
	

}

int main(int argc, char **argv){
	int unique_coins, total, paid;

	printf("Enter the number of unique coins : ");
	scanf("%d", &unique_coins);

	int set_of_coins[unique_coins+1];
	set_of_coins[0]=0;

	printf("Enter the coins every value availabe : \n");
	input_coins(unique_coins, &set_of_coins[0]);

	print_array(unique_coins,&set_of_coins[0]);

	printf("Amount to be paid : ");
	scanf("%d", &total);

	printf("Amount paid : ");
	scanf("%d", &paid);

	if(paid>total){
		int change = make_a_change(unique_coins, &set_of_coins[0], (paid-total));
	}
}