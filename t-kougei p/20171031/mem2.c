#include <stdio.h>

int main(void)
{
	int i;
	int a[]={1, 2, 3};

	printf("aのアドレス:%p\n", a);
	for(i=0; i<sizeof(a)/sizeof(a[0]); i++){
		printf("a[%d]:%d (アドレス:%p)\n", i, a[i], &a[i]);
	}
	
	return 0;
}
