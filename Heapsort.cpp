#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *element;
	int size;
}HeapStruct;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void MAX_HEAPIFY(HeapStruct* heap,int num){
	int child = 2*num;
	
	if(heap->size > child+1)
		child = heap->element[child] > heap->element[child+1] ? child : child+1;
		
	while(child<heap->size && heap->element[num] < heap->element[child]){
		swap(&heap->element[num], &heap->element[child]);
		num = child;
		child *=2;
		
		if(heap->size > child+1)
			child = heap->element[child] > heap->element[child+1] ? child : child+1;		
		}
	}


void build_max_heap(HeapStruct* heap){
	for(int i = heap->size/2; i>0; i--)
		MAX_HEAPIFY(heap, i);
}


int delete_max(HeapStruct* heap){
	int result = heap->element[1];
	swap(&heap->element[1], &heap->element[heap->size--]);
	MAX_HEAPIFY(heap,1);


	return result;
}

int main (void){
	int size, times;
	HeapStruct *heap =(HeapStruct*)malloc(sizeof(HeapStruct));

	scanf("%d%d", &size, &times);
	
	heap->size = size;
	heap->element = (int*)malloc(sizeof(int)*size+1);
	for(int i =1; i<=size; i++){
		scanf("%d", &heap->element[i]);
	}
	build_max_heap(heap);
	
	for(int i =0; i<times; i++){
		printf("%d ", delete_max(heap));
	}
	printf("\n");
	for(int i =1; i<=heap->size; i++){
		printf("%d ", heap->element[i]);
	}
	printf("\n");
}
