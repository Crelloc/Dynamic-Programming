#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Weight 15

void Knapsack01(int* v, int* w, int n, int W){
	int** c = malloc(sizeof(int*) * (n + 1));
	int* temp = malloc(sizeof(int) * (n+1) * (W+1));
	int i, j;
	for(i=0; i < n+1; i++) //for loop used to set up multidemensional array
		c[i] = temp + (i * (W+1));
		


	for(i=0; i<=n; i++){
		for(j=0; j<=W; j++){
				if(i==0 || j==0)
					c[i][j] =0;
				else if(w[i-1] <= j){
					if(v[i-1] + c[i-1][j-w[i-1]] > c[i-1][j]){
						c[i][j] = v[i-1] + c[i-1][j-w[i-1]];
					} 
					else
						c[i][j]=c[i-1][j];
			
				}
				else
					c[i][j]=c[i-1][j];
		
		}
	}
	for(i=0; i<=n; i++){
		for(j=0; j<=W; j++){
			printf("%d,", c[i][j]);
			if(j==W){
				printf("\n");	
			}
		}
	}
	
	printf("Optimal Value c[%d][%d] is %d\n", n, W, c[n][W]);


}
int main(void){
	int v[] = {2,3,3,4,4,5,7,8,8};
	int w[] = {3,5,7,4,3,9,2,11,5};
	int W = Weight;
	int n = (sizeof(v)/sizeof(int)) ;
	Knapsack01(v,w,n, W);
	return 0;
}



