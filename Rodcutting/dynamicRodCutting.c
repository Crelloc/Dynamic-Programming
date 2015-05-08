#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define negInf -9999999 
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
     
#define c 1

int Memoized_Cut_Rod_Aux(int*, int, int*);     
int Memoized_Cut_Rod(int* p, int n){
    int *r = malloc(sizeof(int) * (n+1));
    int i;
    for(i=0; i < (n+1); i++){
	r[i] = negInf;
    }
   
    return Memoized_Cut_Rod_Aux(p,n,r);
//     printf("r=[");
//       for(i=0; i < n+1; i++){
// 	if(i == n)
// 	    printf("%d", r[i]);
// 	else if(i > 0)
// 	    printf("%d, ", r[i]);
// 	
//     }
//     printf("]\n");
    
}

int Memoized_Cut_Rod_Aux(int *p, int n, int *r){
    int i, q, val;
    if (r[n] >= 0)
	return r[n];
    
    if(n==0)
	q=0;
    else{
	q = negInf;
	for(i=1; i<n+1; i++){
	    if(i == n)
		val = p[i-1]+Memoized_Cut_Rod_Aux(p, n-i,r);
	    else
		val = p[i-1]+Memoized_Cut_Rod_Aux(p, n-i,r) - c;
	    if (q < val){
		q = val;
	    }
	    
	}
    }
    r[n] = q;
    return q;
}
int main(void){
    
    int p[] = {1, 4, 5, 9, 10, 12, 15, 18, 19, 20};
    int i, q;
    //printf("sizeof(len) is %d\n", len);
      for(i=1; i <= (sizeof(p)/sizeof(int)); i++){
         q= Memoized_Cut_Rod(p,i);
	printf("max revenue length %d is %d\n", i, q);
	  
    }
   
    return 0;
}