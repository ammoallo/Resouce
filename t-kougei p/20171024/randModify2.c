// 1�`n�܂ł̗������d�������ɔz��Ɋi�[
// �ŏI������

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArray(int *data, int n);
void ShowArray(int *data, int n);

int main(void)
{
	int i, x, n;
	int temp;
	int *a;

	srand((unsigned int)time(NULL));

	printf("n�������ɂ��܂����H");
	scanf("%d", &n);
	a=(int*)malloc(n*sizeof(int));

	InitArray(a, n);

	// �V���b�t�����Ă��镔��
	// �Ⴆ��n=5�Ȃ�A
	// [4]��[0]�`[4]�̂ǂꂩ�ƌ���
	// [3]��[0]�`[3]�̂ǂꂩ�ƌ���
	// [2]��[0]�`[2]�̂ǂꂩ�ƌ���
	// [1]��[0]�`[1]�̂ǂꂩ�ƌ���

	for(i=n-1; i>=1; i--){
		x=rand()%(i+1);

		// i�Ԗڂ̗v�f��x�Ԗڂ̗v�f�Ɠ���ւ��Ă���
		// x��rand()�ɂ��I�΂ꂽ�l
		temp=a[x];
		a[x]=a[i];
		a[i]=temp;
	}

	ShowArray(a, n);

	free(a);

	return 0;
}

// n�̗v�f������data��1�`n��������֐�
void InitArray(int *data, int n)
{
	int i;
	
	for (i = 0; i<n; i++){
		data[i] = i + 1;
	}
}
// n�̗v�f������data��\������֐��A10���Ƃɉ��s����
void ShowArray(int *data, int n)
{
	int i;
	
	for (i = 0; i<n; i++){
		printf("%3d ", data[i]);
		// �P����10�o�͂��邽�тɉ��s���Ă��邾��
		if (i % 10 == 9){
			putchar('\n');
		}
	}
}
