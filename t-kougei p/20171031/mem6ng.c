#include <stdio.h>
#include <malloc.h>

void myAlloc2(int n, int *x);

int main(void)
{
	int i, n=3;
	int *a;
	
	a=NULL;

	printf("a�̃A�h���X:%p\n", &a);
	printf("a�i�A�h���X�������Ă���j:%p\n", a);
	myAlloc2(n, a);
	
	printf("a�̃A�h���X:%p\n", &a);
	printf("a�i�A�h���X�������Ă���j:%p\n", a);
	for(i=0; i<n; i++){
		a[i]=i;
	}
	
	for(i=0; i<n; i++){
		printf("a[%d]:%d�A�A�h���X�F%p\n", i, a[i], &a[i]);
	}
	
	free(a);
	return 0;
}

void myAlloc2(int n, int *x)
{
	x=(int*)malloc(n*sizeof(int));
	printf("   x:%p\n", x);
	printf("  &x:%p\n", &x);
	printf("  *x:%p\n", *x);
}
