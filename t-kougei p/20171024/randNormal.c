// 1�`n�܂ł̗������d�������ɔz��Ɋi�[
// �m���ɏd�������ɗ������i�[�ł�����̂́A�A���S���Y���ɖ�肠��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �v���v���Z�b�T���߂̗��p
// #define DEBUG

int main(void)
{
	int i, j, n, breakFlag;
	int *a;

	srand((unsigned int)time(NULL));

	printf("n�������ɂ��܂����H");
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof(int));

	// 1�ڂ̗v�f��1��Ō��߂���
	a[0] = rand() % n + 1;
#ifdef DEBUG
	printf("  a[%2d]��%3d�Ɍ���\n\n", 0, a[0]);
#endif

	// 2�ڈȍ~�͏d�����Ă��邩�ǂ����̊m�F���K�v
	for (i = 1; i<n; i++){
#ifdef DEBUG
		printf("a[%d]�����蒆�E�E�E\n", i);
#endif
		// �����̃A���S���Y�������܂�ɂ�������I
		do{
			a[i] = rand() % n + 1;

			breakFlag = 0;
			for (j = 0; j<i; j++){
				if (a[i] == a[j]){
					breakFlag = 1; // breakFlag��1�Ȃ�d������A0�Ȃ�d���Ȃ�
					break;
				}
			}

#ifdef DEBUG
			if (breakFlag){
				printf("    %3d��a[%2d]�Əd��\n", a[i], j);
			}
			else{
				printf("    %3d��OK\n", a[i]);
			}
#endif
		} while (breakFlag != 0);

#ifdef DEBUG
		printf("��a[%2d]��%3d�Ɍ���\n\n", i, a[i]);
#endif
	}

	for (i = 0; i<n; i++){
		printf("%3d ", a[i]);
		// �P����10�o�͂��邽�тɉ��s���Ă��邾��
		if (i % 10 == 9){
			putchar('\n');
		}
	}

	free(a);
	return 0;
}
