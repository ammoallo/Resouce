#include <stdio.h>

int main(void)
{
	int i;
	int a[]={1, 2, 3};

	printf("a�̃A�h���X:%p\n", a);
	for(i=0; i<sizeof(a)/sizeof(a[0]); i++){
		printf("a[%d]:%d (�A�h���X:%p)\n", i, a[i], &a[i]);
	}
	
	return 0;
}
