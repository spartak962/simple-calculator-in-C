#include "stdio.h"
#include "string.h"

int main(){
	
	int k;
	char A[5];
	float m;
	
	int *p = &k;
	char *j = A;
	float *l = &m;
	
	printf("%x-integer, %x-string, %x-float",p,j,l);
	*p=98;
	strcpy(j,"sabir");
	*l=34.21;
	
	printf("%d-int,%s- string,%f- float",k,A,m);
	return 0;
}
