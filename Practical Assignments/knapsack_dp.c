#include <stdio.h>
 
// Function that returns maximum of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	int K[n + 1][W + 1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max((val[i - 1] + K[i - 1][w - wt[i - 1]]), K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}
 
void printData(int val[], int wt[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("For Item-%d :\nValue : %d\nWeight : %d\n",i+1,val[i],wt[i]);
	}
	printf("\n");
}

void inputData(int n, int val[], int wt[]){
    for (int i = 0; i < n; i++){
		printf("For Item-%d :\nValue : ",i+1);
        scanf("%d",&val[i]);
		printf("Weight : ");
		scanf("%d",&wt[i]);
    }
}

int main(){
	int n;
	printf("Enter the total no. of items : ");
	scanf("%d",&n);//input of size of array
	
	int W;
	printf("Enter the max capacity of knapsack : ");
	scanf("%d",&W);//input of capacity of Knapsack

	int val[n], wt[n];

	printf("Enter data for items : \n");
	inputData(n,val,wt);//input of array

	printf("List of  items : \n");
	printData(val,wt,n);//print list of items

	printf("Profit : %d\n", knapSack(W, wt, val, n));
	return 0;
}