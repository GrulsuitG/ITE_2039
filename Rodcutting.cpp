#include <stdio.h>
#include <stdlib.h>

int main(){
	int length;
	int *r, *p, *s;
	int i, j, tmp;
	
	scanf("%d", &length);

	r = (int*) malloc(sizeof(int)*((length) + 1));
	s = (int*) malloc(sizeof(int)*((length) + 1));
	p = (int*) malloc(sizeof(int)*length);
	
	for(i = 0; i<length; i++){
		scanf("%d", &p[i]);
		 
	}
	r[0] = 0;
	for( i=1; i<=length; i++){
		tmp = -1;
		for(j =1; j <= i; j++){
			if(tmp < p[j-1]+ r[i-j]){
				tmp = p[j-1] +r[i-j];
				s[i] = j;
			}
		}
	//	printf("asdf : %d\n", tmp);
		r[i] = tmp;
	}

	printf("%d\n", r[length]);
	tmp = length;
	while(tmp >0){
		printf("%d ", s[tmp]);
		tmp = tmp- s[tmp];
	}
/*	for(i= 1; i<= length; i++){
		printf("s[%d] : %d\n", i, s[i]);
	}
	printf("\n");*/
}
