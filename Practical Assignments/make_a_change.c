#include <stdio.h>
#include<limits.h>
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

int make_a_change(int n, int* coins, int diff){
	
	int table[n+1][diff+1];
	
	for (int i = 1; i <= n; i++){
		table[i][0] = 0;
	}
	for (int i = 1; i <= diff; i++){
		table[0][i] = INT_MAX;
	}
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= diff; j++){
			
			if (j<coins[i-1]){
				table[i][j] = table[i-1][j];
			}
			else {
				int v1 = table[i-1][j];
				int v2 = 1 + table[i][j-coins[i-1]];
				table[i][j]=(v1<v2)?v1:v2;
			}
		}
	}
	return table[n][diff];
}

int main(int argc, char **argv){
	int unique_coins, sum;

	printf("Enter the number of unique coins : ");
	scanf("%d", &unique_coins);

	int set_of_coins[unique_coins+1];
	set_of_coins[0]=0;

	printf("Enter the coins every value availabe : \n");
	input_coins(unique_coins, set_of_coins);

	print_array(unique_coins,set_of_coins);

	printf("Total amount to be paid : ");
	scanf("%d", &sum);
	
	printf("Total no. of coins : %d\n",make_a_change(unique_coins, set_of_coins, sum));
}