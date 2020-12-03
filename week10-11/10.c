#include<stdio.h>

void main() {
	int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest=9999;
	static int barray[20], parray[20];
	char* st[20];
	printf("Enter the number of memory segments: ");
	scanf("%d", &nb);
		
	printf("\nEnter the values\n");
	for(i = 1; i <= nb; ++i) {
		printf("Enter the partition size of the block %d: ", i);
        scanf("%d", &b[i]);
        st[i] = "free";
    }
	
	printf("Enter the number of processes to assign the memory: ");
	scanf("%d", &np);

	for(i = 1; i <= np; ++i) {
        printf("Enter the size of process %d: ", i);
        scanf("%d", &p[i]);
    }
	
	for(i = 1; i <= np; ++i) {
		for(j = 1; j <= nb; ++j) {
			if(barray[j] != 1) {
				temp = b[j] - p[i];
				if(temp >= 0)
					if(lowest > temp) {
						parray[i] = j;
						st[i] = "assigned";
						lowest = temp;
					}
			}
		}
		fragment[i] = lowest;
		barray[parray[i]] = 1;
		lowest = 10000;
	}
	
	printf("\nProcess no\tProcess size\tPartition no\tPartition size\tFragment size");
	for(i = 1; i <= np && parray[i] != 0; ++i) {
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
	}
	printf("\n\nPartition status\n");
	for(i = 1; i <= nb; ++i){
		printf("%d - %s\n", b[i], st[i]);
	}
}


