#include <stdio.h>

int func(int x);

int main(void)
{
	int a=1;

	printf("a�̃A�h���X:%p\n", &a);
	printf("a:%d\n", a);
	func(a);
	printf("a:%d\n", a);
	return 0;
}

int func(int x)
{
	x=10;
	printf("�֐�����x�̃A�h���X:%p\n", &x);
	printf("x:%d\n", x);
	
	return x;
}
