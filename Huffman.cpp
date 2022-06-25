#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct tree{
	char ch[5];
	int quantity;
	int height;
	int is_leaf;
	struct tree* left;
	struct tree* right;
}tree;

typedef struct node{
	tree* ptr;
	int key;
}node;

typedef struct{
	node *element;
	int size;
}HeapStruct;

void swap(node *a, node *b){
	int num = a->key;
	a->key =b->key;
	b->key = num;

	tree* temp = a->ptr;
	a->ptr = b->ptr;
	b->ptr = temp;
}


void MIN_HEAPIFY(HeapStruct* heap,int num){
	int child = 2*num;
	if(heap->size >= (child+1)){
		child = heap->element[child].key < heap->element[child+1].key ? child : child+1;
	}
	while(child<=heap->size && heap->element[num].key > heap->element[child].key){
		swap(&heap->element[num], &heap->element[child]);
		num = child;
		child *=2;

		if(heap->size >= (child+1))
			child = heap->element[child].key < heap->element[child+1].key ? child : child+1;
		}

	}


void build_min_heap(HeapStruct* heap){
	for(int i = heap->size/2; i>0; i--)
		MIN_HEAPIFY(heap, i);
}
void insert(HeapStruct* heap, node item){
	heap->size++;
	heap->element[heap->size] = item;
	int child = heap->size;
	int parent = child/2;

	while(child>1 && heap->element[child].key < heap->element[parent].key){
		swap(&heap->element[child], &heap->element[parent]);
		child = parent;
		parent = child/2;
	}	
}

node delete_min(HeapStruct* heap){

	node result = heap->element[1];
	swap(&heap->element[1], &heap->element[heap->size--]);
	MIN_HEAPIFY(heap,1);
	return result;
}

int howmanybit(int x){
	int num =2;
	int i=1;
	while(x>num){
		num = pow(2,++i);
	}
	return i;
}
tree* make_tree(tree* left, tree* right){
	tree* t = (tree*)malloc(sizeof(tree));
	t->quantity = left->quantity+right->quantity;
	if(left->height < right->height){
		left->height = right->height;
	}
	else
		right->height = left->height;
	t->height = (left->height)+1;
	t->left = left;
	t->right = right;
	return t;
}
int totalnum(tree* root, int height){
	int code = 0;
	int total = 0;
	
	if(root == NULL )
		return 0;
	else{
		total += totalnum(root->left, height);
		if(root->is_leaf ==1){
			code = height - root->height;
			total += code*(root->quantity);
		//	printf("%d\n", total);
		}
		total += totalnum(root->right, height);
		return total;
	}
	return 0;
}
void inorder(tree* t, int height){
	if(t== NULL)
		return;
	else{
		t->height = height-1;
		
		inorder(t->left, t->height);
		inorder(t->right, t->height);
	}
}

tree* make_huffman(HeapStruct *heap){
	node t1,t2, p;
	tree *parent;
	int size = heap->size;

	for(int i=1; i<size; i++){
		t1 = delete_min(heap);
		t2 = delete_min(heap);
	//	printf("%d %d\n", t1.ptr->quantity, t2.ptr->quantity);
		parent = make_tree(t1.ptr,t2.ptr);
		p.ptr = parent;
		p.key = t1.ptr->quantity+t2.ptr->quantity;
		insert(heap, p);
	}
	p = delete_min(heap);
	return p.ptr;
	
}

int main(){
	int size,  total;
	tree* h;
	char* ch;
	HeapStruct *heap = (HeapStruct*)malloc(sizeof(HeapStruct));
	
	scanf("%d", &size);
	heap->size = size;
	heap->element = (node*) malloc(sizeof(node)*(size+1));
	for(int i =1; i<=size; i++){
		heap->element[i].ptr = (tree*)malloc(sizeof(tree));
		h = heap->element[i].ptr;
		h->height = 0;
		h->is_leaf =1;
		h->left = h->right = NULL;
		scanf("%s %d", h->ch , &h->quantity);
		heap->element[i].key = h->quantity;
	}
	scanf("%d", &total);
	size = howmanybit(size);
	total = total*size;
	printf("%d\n", total);

	build_min_heap(heap);
	h = make_huffman(heap);
//	printf("asdf:%d\n", h->right->height);
	inorder(h, h->height);


	total = totalnum(h, h->height);
	printf("%d\n", total);
	return 0;
}
