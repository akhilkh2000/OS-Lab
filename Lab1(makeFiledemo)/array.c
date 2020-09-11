#include<stdio.h>
#include "array.h"

void printReverse(int arr[], int n) {
	for (int i = n - 1; i >= 0 ; i--)
		printf("%d ", arr[i]);

}