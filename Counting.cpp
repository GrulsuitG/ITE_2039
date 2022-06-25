#define MAX 100000

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n, m, k, num, cnt;
	int *arr, *standard;
	scanf("%d %d %d", &n, &m, &k);
	
	arr = (int*)malloc(sizeof(int)*(m+1));
	standard = (int*)malloc(sizeof(int)*2*k);
	for(int i =0; i<2*k; i+=2){
		scanf("%d %d", &standard[i],&standard[i+1]);
	}
	for(int i = 0; i<n; i++){
		scanf("%d", &num);
		arr[num]++;
	}
	for(int i =0; i<2*k; i+=2){
		cnt =0;
		for(int j=standard[i]; j<=standard[i+1]; j++){
			cnt += arr[j];
		}
		printf("%d\n", cnt);
	}

	return 0;
}
