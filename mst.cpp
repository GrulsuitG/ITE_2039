#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int rank;
	struct node* p;
}node;

typedef struct edge{
	int s;
	int d;
	int w;
}edge;
typedef struct{
	int Capacity;
	int Size;
	edge *Elements;
}HeapStruct;

node **v;

int vnum, edgenum;

int find_min(int a, int b, int c, int d){
	if(a > c || (a == c && b > d ))
		return 1;
	
	return 0;

}

void swap(edge *a, edge *b){
	edge tmp1 = *a;
	edge tmp2 = *b;
	*a = tmp2;
	*b = tmp1;
}

HeapStruct* CreateHeap(int heapsize){
	HeapStruct* Heap = (HeapStruct*) malloc(sizeof(HeapStruct));
	Heap->Capacity = heapsize;
	Heap->Size = 0;
	Heap->Elements = (edge*)malloc(sizeof(edge)*(heapsize+1));
  
	return Heap;
}

void Insert(HeapStruct *heap, edge item){

	heap->Elements[++heap->Size]= item;
	
	int child = heap->Size;
	int parent = child/2;

	while(child>1 && heap->Elements[child].w > heap->Elements[parent].w){
		
	
			swap(&heap->Elements[child], &heap->Elements[parent]);

		child = parent;
		parent = child/2;
	}
}

edge DeleteMax(HeapStruct *heap){

	edge result = heap->Elements[1];

	swap(&heap->Elements[1], &heap->Elements[heap->Size--]);

	
	int parent = 1;
	int child = 2;

	if(child +1 <= heap->Size)
		child = (heap->Elements[child].w > heap->Elements[child+1].w) ? child : child+1;

	while(child<= heap->Size && heap->Elements[parent].w <heap->Elements[child].w){
		
			swap(&heap->Elements[parent], &heap->Elements[child]);

		parent =child;
		child *= 2;

		if(child +1 <= heap->Size)
			child = (heap->Elements[child].w > heap->Elements[child+1].w) ? child : child+1;

	}
   
	return result;
}

void make_set(node* x){
	x->p = x;
	x->rank =0;
}

node* find(node* x){
	if(x == x->p)
		return x;
	else
		return find(x->p);
}

void link(node *x, node* y){
	if(x->rank >y->rank)
		y->p =x;
	else{
		x->p = y;
		if(x->rank == y->rank)
			y->rank++;
	}
}

void unionset(node* x, node* y){
	link(find(x), find(y));
}

void Merge(edge arr[],edge tmp[], int p, int q, int r){
	int i = p, j =q+1, k =p;

	while(i<=q && j<=r){
		if(arr[i].s < arr[j].s || (arr[i].s == arr[j].s && arr[i].d < arr[j].d))
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
	
void MergeSort(edge arr[],edge tmp[] ,int p, int r){
	if(p<r){
		int q = (p+r)/2;
		MergeSort(arr, tmp, p, q);
		MergeSort(arr, tmp, q+1, r);
		Merge(arr, tmp, p, q, r);
	}
}


int main(){
	int i, j,num =0;
	int s, d;
	edge *c, tmp;
	
	scanf("%d %d", &vnum, &edgenum);
	HeapStruct *h = CreateHeap(edgenum);
	v =(node**)malloc(sizeof(node*)* (vnum+1));
	for(i=0; i<=vnum; i++){
		v[i] =(node*)malloc(sizeof(node));
		make_set(v[i]);
	}
	c = (edge*)malloc(sizeof(edge)*edgenum);
	
	for(i=0; i<edgenum ;i++){
		scanf("%d %d %d", &tmp.s, &tmp.d, &tmp.w);
		if(tmp.s > tmp.d){
			num = tmp.s;
			tmp.s = tmp.d;
			tmp.d = num; 
		}
		Insert(h,tmp);
		
	}

	
	for(i=0; i<edgenum; i++){
		DeleteMax(h);
	}
	for(j =1; j<edgenum;){
		s = h->Elements[j].w;
		for(i=j+1; i<=edgenum ; i++){
				if(s != h->Elements[i].w)
					break;
		}
		if(s == h->Elements[i].w)
			MergeSort(h->Elements, c, j, i);
		else 
			MergeSort(h->Elements, c, j, i-1);

		j =i;
	}
	/*printf("\n");
	for(j=1; j<=h->Capacity; j++){
			printf("%d %d %d\n", h->Elements[j].s, h->Elements[j].d, h->Elements[j].w);
		}
	printf("\n");
	printf("\n");
	for(i=0; i<edgenum; i++){
		printf("%d %d %d\n", e[i].s, e[i].d, e[i].w);
	}*/
	num =0;
	for(i=1; i<=h->Capacity; i++){
		s = h->Elements[i].s;
		d = h->Elements[i].d;
		if(find(v[s]) != find(v[d])){
			unionset(v[s], v[d]);
			c[num++] = h->Elements[i];
		}
	}
	printf("%d\n", num);
	for(i=0; i<num; i++){
		printf("%d %d %d\n", c[i].s, c[i].d, c[i].w);
		
		
	}


	return 0;
}
