#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int i, n=3;
	int *a;
	
	a=(int *)malloc(n*sizeof(int));

	for(i=0; i<n; i++){
		a[i]=i;
	}

	printf("&a:%p\n", &a);
	printf("a:%p\n", a);
	for(i=0; i<n; i++){
		printf("a[%d]:%d、アドレス：%p\n", i, a[i], &a[i]);
	}
	
	free(a);
	return 0;
}
