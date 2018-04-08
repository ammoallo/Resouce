#include <stdio.h>
#include <malloc.h>

int * myAlloc(int n);

int main(void)
{
	int i, n=3;
	int *a;
	
	printf("aのアドレス:%p\n", &a);
	//printf("a（アドレスが入っている、確保前は不定）:%p\n", a);

	a=myAlloc(n);
	
	printf("aのアドレス:%p\n", &a);
	printf("a（アドレスが入っている、確保後）:%p\n", a);
	
	for(i=0; i<n; i++){
		a[i]=i;
	}
	for(i=0; i<n; i++){
		printf("a[%d]:%d、アドレス：%p\n", i, a[i], &a[i]);
	}
	
	free(a);
	return 0;
}

int * myAlloc(int n)
{
	int *x;
	
	x=(int*)malloc(n*sizeof(int));
	printf("myAlloc内、xのアドレス:%p\n", &x);
	printf("myAlloc内、x（アドレスが入っている、確保後）:%p\n", x);
	return x;
}
