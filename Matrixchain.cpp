#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **m, **s, n;

void print_optimal(int i,int j){
	if ( i== j)
			printf(" %d ",i);
	else{
		printf("( ");
		print_optimal(i, s[i][j]);
		print_optimal(s[i][j]+1, j);
		printf(" )");
	}
}


int main(){
	int *p, i, j, k, l, q;
	//int **m, **s;

	scanf("%d", &n);
	p = (int*) malloc(sizeof(int) *(n+1));

	for(i = 0; i<=n; i++){
		scanf("%d",&p[i]);
	}
	
	m =(int**) malloc(sizeof(int*) * (n+1));
	s = (int**) malloc(sizeof(int*) * (n+1));
	for(i = 1; i <=n; i++){
		m[i] = (int*)malloc(sizeof(int) * (n+1));
	}
	for( i = 1; i<=n; i++){
		s[i] = (int*) malloc(sizeof(int) *(n+1));
	}

	for(i = 1; i<=n; i++){
		m[i][i] = 0;
	}
	for( l =2; l<=n; l++){
		for(i = 1; i<= n-l+1; i++){
			j = i+ l -1;
			m[i][j] = INT_MAX;
			for( k = i; k<=j-1; k++){
				q = m[i][k]+ m[k+1][j]+p[i-1]*p[k]*p[j];
				if( q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", m[1][n]);

	print_optimal(1, n);

	return 0;
}
