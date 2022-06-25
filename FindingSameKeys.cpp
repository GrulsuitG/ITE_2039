#include<stdio.h>
#include<stdlib.h>

int main(void){
	int num1, num2, cnt;
	int *arr1, *arr2;
	scanf("%d %d", &num1, &num2);
	
	arr1 = (int*) malloc(sizeof(int)* num1);
	arr2 = (int*) malloc(sizeof(int)* num2);

	for(int i =0; i<num1; i++){
		scanf("%d", &arr1[i]);
	}
	for(int i=0; i<num2; i++){
		scanf("%d", &arr2[i]);
	}
	cnt = 0;
	for(int i=0; i<num1; i++){
		for(int j =0; j<num2; j++){
			if(arr1[i] == arr2[j])
				cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}
