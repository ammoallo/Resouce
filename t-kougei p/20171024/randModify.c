// 1�`n�܂ł̗������d�������ɔz��Ɋi�[
// �A���S���Y�����ǔŁA���������_�ł͂Ȃ�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArray(int *data, int n);
void ShowArray(int *data, int n);

int main(void)
{
	int i, x, y, n, shuffleMax = 100;
	int temp;
	int *a;

	srand((unsigned int)time(NULL));

	printf("n�������ɂ��܂����H");
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof(int));

	InitArray(a, n);

	// �V���b�t�����Ă��镔��
	// �ǂ������A���S���Y���Ȃ̂��l���Ă݂悤
	for (i = 0; i<shuffleMax; i++){
		x = rand() % n;
		y = rand() % n;

		// x�Ԗڂ̗v�f��y�Ԗڂ̗v�f�Ɠ���ւ��Ă���
		// x��y��rand()�ɂ��I�΂ꂽ�l
		temp = a[x];
		a[x] = a[y];
		a[y] = temp;
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

// n�̗v�f������data��\������֐�
// 10���Ƃɉ��s����
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
