#include<stdio.h>
#include<stdlib.h>

#define MAXELEMENT 100001

typedef struct{
	int element[MAXELEMENT];
	int size;
}PQueue;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Insert(PQueue *S , int x){
	S->element[++S->size] =x;

	int parent = S->size/2;
	int child = S->size;

	while(child >1 && S->element[child] > S->element[parent]){
		swap(&S->element[child], &S->element[parent]);
		child = parent;
		parent /=2;
	}
}

int Maximum(PQueue *S){
	return S->element[1];
}

int ExtractMax(PQueue *S){
	if( S->size <1){
		return 0;
	}
	int result = S->element[1];
	swap(&S->element[1], &S->element[S->size--]);

	int parent = 1;
	int child = 2;

	if(child+1 <= S->size)
		child = S->element[child] > S->element[child+1] ?  child :child+1;

	while(child <=S->size && S->element[child] > S->element[parent]){
		swap(&S->element[child], &S->element[parent]);
		parent = child;
		child *= 2;

		if(child+1 <= S->size)
			child = S->element[child] > S->element[child+1] ? child :child+1;
	}
	
	return result;
}

void changeKey(PQueue *S, int x, int index){
	/*if( index> S->size || index<1){
		printf("wrong index\n");
		return;
	}*/

	int origin = S->element[index];
	int parent, child;
	S->element[index] = x;

	if(origin > x){
		parent = index;
		child = index*2;

		if(child+1 <= S->size)
			child = S->element[child] > S->element[child+1] ? child :child+1;
	
		while(child<=S->size && S->element[child] > S->element[parent]){
			swap(&S->element[child], &S->element[parent]);
			parent = child;
			child *= 2;
	
			if(child+1 <= S->size)
				child = S->element[child] > S->element[child+1] ? child :child+1;
		}
	}
	else{
		parent = index/2;
		child = index;
		while(child >1 && S->element[child] > S->element[parent]){
			swap(&S->element[child], &S->element[parent]);
			child = parent;
			parent /=2;
		}
	}
}

PQueue* init(){
	PQueue *S = (PQueue*) malloc(sizeof(PQueue));
	S->size =0;
	return S;
}

int main (void){
	PQueue *S;
	int select, num, index, cnt;
	int extract[MAXELEMENT];
	S= init();
	cnt = 0;
	do{
		scanf("%d", &select);
		switch(select){
			case 1:
				scanf("%d", &num);
				Insert(S, num);
				break;
			case 2:
				extract[cnt++] = ExtractMax(S);
				break;
			case 3:
				scanf("%d %d", &index, &num);
				changeKey(S, num, index);
				break;
		}
	
	}while(select!=0);
	for(int i =0; i<cnt; i++)
		printf("%d ", extract[i]);
	printf("\n");
	for(int i =1; i<=S->size; i++)
		printf("%d ", S->element[i]);
	printf("\n");

	return 0;
}
