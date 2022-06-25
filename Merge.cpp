
#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[],int tmp[], int p, int q, int r){
	int i = p, j =q+1, k =p;

	while(i<=q && j<=r){
		if(arr[i] >= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while(i<=q)
		tmp[k++] = arr[i++];
	while(j<=r)
		tmp[k++] = arr[j++];

	for(int a = p; a<=r; a++)
		arr[a] = tmp[a];
	}
	
void MergeSort(int arr[],int tmp[] ,int p, int r){
	if(p<r){
		int q = (p+r)/2;
		MergeSort(arr, tmp, p, q);
		MergeSort(arr, tmp, q+1, r);
		Merge(arr, tmp, p, q, r);
	}
}
int main(void){
	int num = 10;
	scanf("%d", &num);

	int arr[num], tmp[num];
	for(int i = 0; i<num; i++){
		scanf("%d", &arr[i]);
	}

	MergeSort(arr, tmp, 0, num-1);

	for(int i=0; i<num; i++){
		printf("%d\n", arr[i]);
	}

	return 0;
}
