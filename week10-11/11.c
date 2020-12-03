#include<stdio.h>
 
int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
 
int main() {
    int nof, nop, frames[10], pages[30], count = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

	printf("Enter the length of reference string: ");
	scanf("%d", &nop);
	
	printf("Enter the reference string: ");
	
    for(i = 0; i < nop; ++i){
    	scanf("%d", &pages[i]);
    }
    
	printf("Enter the number of frames: ");
	scanf("%d", &nof);
	

	for(i = 0; i < nof; ++i){
    	frames[i] = -1;
    }
    
    for(i = 0; i < nop; ++i){
    	flag1 = flag2 = 0;
    	for(j = 0; j < nof; ++j){
    		if(frames[j] == pages[i]){
	    		count++;
	    		time[j] = count;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	if(flag1 == 0){
			for(j = 0; j < nof; ++j){
	    		if(frames[j] == -1){
	    			count++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = count;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	if(flag2 == 0){
    		pos = findLRU(time, nof);
    		count++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = count;
    	}
    	printf("\n");
    	for(j = 0; j < nof; ++j){
    		printf("%d\t", frames[j]);
    	}
	}
	
	printf("\n\nThe number of page faults using LRU = %d\n", faults);
    return 0;
}

