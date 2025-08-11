#include<stdio.h>

int main(){

	int a[6], i, j, n, min;
	n = sizeof(a)/sizeof(a[0]);
	
	printf("Enter the elements of the array");
	for(i = 0; i < n; i++)
	    scanf("%d", &a[i]);
	
	for(i = 0; i < n-1; i++){
	    min = i;
	    for(j = i+1; j < n; j++){
	        if(a[min] > a[j])
	          min = j;
	    }
	    
	    if(min != i){
	       int temp = a[min];
	       a[min] = a[i];
	       a[i] = temp;
	    }
	}
	
	for(i = 0; i < n; i++)
	    printf("%d ", a[i]);
      return 0;
}
