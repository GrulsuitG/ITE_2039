#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **graph;
int *visit;
int *finish;

unsigned time;
bool cycle =false;

void DFS(int v, int size){
	int i;
	visit[v] =1;

	for(i =1; i<=size; i++){
		if(graph[v][i] == 1){
			switch (visit[i]){
				case 0:
					DFS(i, size);
					break;
				case 1:
					cycle = true;
					break;
				case 2:
					break;
				default:
					break;
			}
		}
	}
	finish[size-(time++)] = v;
	visit[v] =2;

}


int main(){
	int edgenum, size;
	int x, y;
	int i,j;
	scanf("%d %d", &size, &edgenum);
	
	graph = (int**)malloc(sizeof(int*) *(size+1));
	visit = (int*)malloc(sizeof(int) * (size+1));
	finish = (int*) malloc(sizeof(int) * size);
	
	for(i =1; i<=size; i++){
		graph[i] =(int*)malloc(sizeof(int)*(size+1));
	}
	for(i=1; i<=size; i++){
		visit[i] = 0;
		for(j=1; j<=size; j++){
			graph[i][j] = 0;
		}
	}

	for(i = 0; i<edgenum; i++){
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
	}
	time =1;
	for(i =1; i<=size; i++){
		if(visit[i] == 0)
			DFS(i, size);
	}


	if(cycle)
		printf("0\n");
	else{
		printf("1\n");

		for(i = 0; i<size; i++)
			printf("%d ", finish[i]);
	}
	return 0;
}
/*
#define WHITE 0 
#define GRAY 1 
#define BLACK 2 

#define TRUE 1 
#define FALSE 0 
typedef struct _vertex{ 
	int color; 
	int f; 
	int d; 
} Vertex; 
typedef struct _VertexInfo{ 
	int out_degree; 
	int * list; 
} VertexInfo; 

Vertex * vertex; 
VertexInfo * vertexInfo; 
int numV, time; 
int * topoList; 
int topo_num=0; 
int isDAG = TRUE; 

void addEdge(int fromV, int toV){ 
	int i=0; 
	int cur=0; 
	for(i=0; i < numV; i++) { 
		if(vertexInfo[fromV].list[i] == 0) 
			break; 
			cur ++; 
		} 
		vertexInfo[fromV].list[cur] = toV; 
	} 

void DFS_Visit(int fromV){ 
	int i=0, toV; 
	
	time++; 
	vertex[fromV].color = GRAY; 
	vertex[fromV].d = time; 
	for(i=0; i < vertexInfo[fromV].out_degree; i++){ 
		toV = vertexInfo[fromV].list[i]; 
		switch(vertex[toV].color) { 
			case WHITE: 	
				DFS_Visit(toV); 
				break; 
			case GRAY: 
				isDAG = FALSE; 
				break; 
			case BLACK: 
				break; 
			default: 
				break; 
			} 
		} 
	
	vertex[fromV].color = BLACK; 
	topoList[numV-(topo_num++)] = fromV; 
	time ++; 
	vertex[fromV].f = time; 
} 

void Sort(int * list, int num) { 
	int i=0, j=0, tmp; 
	for(i=0; i < num; i++) { 
			for(j=i+1; j < num; j++) { 
				if(list[i] > list[j]) { 
					tmp = list[i]; 
					list[i] = list[j]; 
					list[j] = tmp; 
				} 
			} 
		} 
	} 

void DFS(void) { 
	int i; 
	for(i=1; i <=numV; i++) { 
		vertex[i].d = 0; 
		vertex[i].f = 0; 
		vertex[i].color = WHITE; 
		Sort(vertexInfo[i].list, vertexInfo[i].out_degree); 
	} 
	time = 0; 
	for(i=1; i <=numV; i++) { 
		if(vertex[i].color == WHITE) { 
			DFS_Visit(i); 
		} 
	} 	
} 
	
int main(void) { 
	int i=0, j=0; 
	int fromV, toV; 
	int edge;
	scanf("%d %d", &numV, &edge); 
	
	
	vertexInfo = (VertexInfo*)malloc(sizeof(VertexInfo)*(edge+1)); 
	for(i=1; i <=edge; i++){ 
		vertexInfo[i].list = (int*)malloc(sizeof(int) * numV); 
		vertexInfo[i].out_degree = 0; 
	} 
	for(i=1; i <= numV; i++){ 
		for(j=0; j < numV; j++){ 
			vertexInfo[i].list[j] = 0; 
		} 
	}
	vertex = (Vertex*)malloc(sizeof(Vertex)*(numV+1)); 
	topoList = (int*)malloc(sizeof(int)*(numV+1)); 
	
	
	 // INPUT 
	 
	for(i=0; i<edge; i++){
		 scanf("%d %d", &fromV, &toV);
		 addEdge(fromV, toV); vertexInfo[fromV].out_degree ++; 
	} 
		 DFS(); 
		 
	// OUTPUT 

	printf("%d\n", isDAG); 
	if(isDAG) { 
		for(i=1; i <=numV; i++) 
			printf("%d ", topoList[i]); 
		} 
	return 0; 
}

*/
