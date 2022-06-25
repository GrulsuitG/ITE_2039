#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    unsigned long long distance;
    int num;
}node;

typedef struct{
    int *adj;
    unsigned long long *weight;
    int num;
}list;

typedef struct{
	int Capacity;
	int Size;
	node *Elements;
}HeapStruct;

typedef struct{
    int s;
    int d;
    unsigned long long w;
}edge;

int *found;
int *num;
list *adjList;
HeapStruct *h;
edge *e;

void swap(node* a, node* b){
	node tmp1 = *a; 
    node tmp2 = *b;
    *b = tmp1;
    *a = tmp2;
    
}

HeapStruct* CreateHeap(int heapsize){
	HeapStruct* Heap = (HeapStruct*) malloc(sizeof(HeapStruct));
	Heap->Capacity = heapsize;
	Heap->Size = 0;
	Heap->Elements = (node*)malloc(sizeof(node)*(heapsize+1));
  
	return Heap;
}

void Insert(HeapStruct *heap, unsigned long long value, int num){

	heap->Elements[++heap->Size].distance = value;
    heap->Elements[heap->Size].num =num;
	
	int child = heap->Size;
	int parent = child/2;

	while(child>1 && heap->Elements[child].distance < heap->Elements[parent].distance){
		swap(&heap->Elements[child], &heap->Elements[parent]);
		child = parent;
		parent = child/2;
	}
}

node DeleteMin(HeapStruct *heap){
	
  
	node result = heap->Elements[1];

	swap(&heap->Elements[1], &heap->Elements[heap->Size--]);

	
	int parent = 1;
	int child = 2;

	if(child +1 <= heap->Size)
		child = (heap->Elements[child].distance<heap->Elements[child+1].distance) ? child : child+1;

	while(child<= heap->Size && heap->Elements[parent].distance > heap->Elements[child].distance){
		swap(&heap->Elements[parent], &heap->Elements[child]);
		parent =child;
		child *= 2;

		if(child +1 <= heap->Size)
			child = (heap->Elements[child].distance<heap->Elements[child+1].distance) ? child : child+1;

	}
   
	return result;
}

void relax(int u, int v, unsigned long long weight){
    int i;
    int parent, child;
    for( i =1; i <= h->Size; i++){
        if(h->Elements[i].num == v ){
            h->Elements[i].distance = (h->Elements[i].distance < weight) ? h->Elements[i].distance : weight;
    
            child = i;
            parent = i/2;

            while(child >1 && h->Elements[parent].distance > h->Elements[child].distance){
                swap(&h->Elements[parent], &h->Elements[child]);

                child = parent;
                parent /= 2;
            } 
            break;
        }  
    }
}



void shortest_path(int n, int edgenum){
	int i;
    unsigned long long w;
    node u;

	h->Elements[1].distance = 0;
  
    while(h->Size >0){
       
        u = DeleteMin(h);

        for(i= 0; i<num[u.num]; i++){
                w = u.distance + adjList[u.num].weight[i];
                relax(u.num,adjList[u.num].adj[i],w);
        }
        
    }
}

int main(){
    int vertex, edgenum, n;
    int i,s;
    
    scanf("%d %d", &vertex, &edgenum);
   
    h = CreateHeap(vertex);
    num = (int*) malloc(sizeof(int) * (vertex+1));
    e = (edge*) malloc(sizeof(edge) * edgenum);
    for(i=0; i<edgenum; i++){
        scanf("%d %d %llu", &e[i].s, &e[i].d, &e[i].w);
        n = e[i].s;
        num[n]++;
    }
    adjList = (list*) malloc(sizeof(list)* (vertex+1));
    for(i=1; i<=vertex; i++){
        adjList[i].adj = (int*) malloc(sizeof(int)*(num[i]));
        adjList[i].weight = (unsigned long long*) malloc(sizeof(unsigned long long)*(num[i]));
        adjList[i].num =0;
        Insert(h,ULLONG_MAX,i);
    }
    for(i=0; i<edgenum; i++){
        s = e[i].s;
        n = adjList[s].num++;
        adjList[s].adj[n] = e[i].d;
        adjList[s].weight[n] = e[i].w;
        
    }
    
	shortest_path(vertex, edgenum);
    printf("%llu\n", h->Elements[1].distance);


    return 0;
}

