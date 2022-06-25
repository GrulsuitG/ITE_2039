#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *edge;
}node;

node *vertex;
int *visit;

void DFS(int v){
	node *temp;
	temp = vertex[v-1].edge;
	visit[v-1] =1;
	while(temp != NULL){
		if (visit[temp->num-1] == 0){
			DFS(temp->num);
		}
		temp = temp->edge;
	}
}

int main(){
	int num1, num2, num3, size;
	int count =0;
	node *n, *temp;
	scanf("%d %d", &size, &num1);
	vertex = (node*)malloc(sizeof(node)* size);
	visit = (int*)malloc(sizeof(int)* size);
	for(int i=0; i<num1; i++){
		scanf("%d %d", &num2, &num3);
		n = (node*)malloc(sizeof(node));
		n->num = num3;
		temp =&vertex[num2-1];
		while(temp->edge != NULL)
			temp = temp->edge; 
		temp->edge = n;
		n = (node*)malloc(sizeof(node));
		n->num = num2;
		temp = &vertex[num3-1];
		while(temp->edge != NULL)
			temp = temp->edge;
		temp->edge = n;
	}
	for(int i=1; i<=size; i++){
		if(visit[i-1] == 0){
			DFS(i);
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
