#include<stdio.h>
#include "array.h"
int main() {

	int n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements of array\n");
	for(int i = 0; i<n; i++)
		scanf("%d",&arr[i]);
	printReverse(arr, n);
	return 0;
}