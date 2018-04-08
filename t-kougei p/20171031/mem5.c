#include <stdio.h>
#include <malloc.h>

int * myAlloc(int n);

int main(void)
{
	int i, n=3;
	int *a;
	
	printf("a�̃A�h���X:%p\n", &a);
	//printf("a�i�A�h���X�������Ă���A�m�ۑO�͕s��j:%p\n", a);

	a=myAlloc(n);
	
	printf("a�̃A�h���X:%p\n", &a);
	printf("a�i�A�h���X�������Ă���A�m�ی�j:%p\n", a);
	
	for(i=0; i<n; i++){
		a[i]=i;
	}
	for(i=0; i<n; i++){
		printf("a[%d]:%d�A�A�h���X�F%p\n", i, a[i], &a[i]);
	}
	
	free(a);
	return 0;
}

int * myAlloc(int n)
{
	int *x;
	
	x=(int*)malloc(n*sizeof(int));
	printf("myAlloc���Ax�̃A�h���X:%p\n", &x);
	printf("myAlloc���Ax�i�A�h���X�������Ă���A�m�ی�j:%p\n", x);
	return x;
}
