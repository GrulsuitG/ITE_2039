#include<stdio.h>
#include<stdlib.h>

int **s, **l, last_l, last_s;

void fastway(int **a, int **t, int *e, int *x, int n){
	int i;
	s[0][1] = e[0] + a[0][1];
	s[1][1] = e[1] + a[1][1];

	for(i = 2; i<=n; i++){
		if(s[0][i-1] <= s[1][i-1] + t[1][i-1]){
			s[0][i] = s[0][i-1] + a[0][i];
			l[0][i] = 1;
		}
		else{
			s[0][i] = s[1][i-1] + t[1][i-1] + a[0][i];
			l[0][i] = 2;
		}
		if(s[1][i-1] <= s[0][i-1] + t[0][i-1]){
			s[1][i] = s[1][i-1] + a[1][i];
			l[1][i] = 2;
		}
		else{
			s[1][i] = s[0][i-1] + t[0][i-1] + a[1][i];
			l[1][i] = 1;
		}
	}
	if(s[0][n] +x[0] <= s[1][n] + x[1]){
		last_s = s[0][n]+x[0];
		last_l = 1;
	}
	else{
		last_s = s[1][n] +x[1];
		last_l = 2;
	}
}	

void print_stations(int **l, int last_l, int n){
	int arr[n+1];
	int i = last_l;
	arr[n] = last_l;
//	printf("%d %d\n", i, n);
	for(int j =n; j>=2; j--){
		i = l[i-1][j];
		arr[j-1] = i;
//		printf("%d %d\n", i, j-1);
	}

	for(int i =1; i<=n; i++){
		printf("%d %d\n", arr[i], i);
	}
}


int main(){
	int **a, **t;
	int e[2], x[2];
	int n;
	scanf("%d", &n);
	
	a = (int**)malloc(sizeof(int) *2);
	s = (int**)malloc(sizeof(int) *2);
	l = (int**)malloc(sizeof(int) *2);
	t = (int**)malloc(sizeof(int) *2);

	a[0] = (int*) malloc(sizeof(int) * (n+1));
	a[1] = (int*) malloc(sizeof(int) * (n+1));
	s[0] = (int*) malloc(sizeof(int) * (n+1));
	s[1] = (int*) malloc(sizeof(int) * (n+1));
	l[0] = (int*) malloc(sizeof(int) * (n+1));
	l[1] = (int*) malloc(sizeof(int) * (n+1));
	t[0] = (int*) malloc(sizeof(int) * (n));
	t[1] = (int*) malloc(sizeof(int) * (n));
	scanf("%d %d", &e[0], &e[1]);
	scanf("%d %d", &x[0], &x[1]);

	for(int i =1; i<=n; i++){
		scanf("%d", &a[0][i]);
	}
	for(int i =1; i<=n; i++){
		scanf("%d", &a[1][i]);
	}
	for(int i =1; i<n; i++){
		scanf("%d", &t[0][i]);
	}
	for(int i =1; i<n; i++){
		scanf("%d", &t[1][i]);
	}
	
	fastway(a,t,e,x,n);
	printf("%d\n", last_s);
	print_stations(l,last_l,n);



	return 0;
}
