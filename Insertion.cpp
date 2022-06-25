#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	int num, i , j,key;

	//input the number
	scanf("%d", &num);


	int *arr = (int*)malloc(sizeof(int)*num);
	
	//input array
	for(i =0; i<num; i++){
		scanf("%d", arr+i);
	}
	
	//insertion sort
	for(i=1; i<num; i++){
		key = *(arr+i);
		
		j = i-1;
		while(j>=0 && arr[j] <key){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
	}

	for(i =0; i<num; i++)
		printf("%d\n", *(arr+i));


	return 0;
}
