// 1～nまでの乱数を重複せずに配列に格納
// 確かに重複せずに乱数を格納できるものの、アルゴリズムに問題あり

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// プリプロセッサ命令の利用
// #define DEBUG

int main(void)
{
	int i, j, n, breakFlag;
	int *a;

	srand((unsigned int)time(NULL));

	printf("nをいくつにしますか？");
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof(int));

	// 1個目の要素は1回で決められる
	a[0] = rand() % n + 1;
#ifdef DEBUG
	printf("  a[%2d]は%3dに決定\n\n", 0, a[0]);
#endif

	// 2個目以降は重複しているかどうかの確認が必要
	for (i = 1; i<n; i++){
#ifdef DEBUG
		printf("a[%d]を決定中・・・\n", i);
#endif
		// ここのアルゴリズムがあまりにも非効率的
		do{
			a[i] = rand() % n + 1;

			breakFlag = 0;
			for (j = 0; j<i; j++){
				if (a[i] == a[j]){
					breakFlag = 1; // breakFlagが1なら重複あり、0なら重複なし
					break;
				}
			}

#ifdef DEBUG
			if (breakFlag){
				printf("    %3dはa[%2d]と重複\n", a[i], j);
			}
			else{
				printf("    %3dはOK\n", a[i]);
			}
#endif
		} while (breakFlag != 0);

#ifdef DEBUG
		printf("→a[%2d]は%3dに決定\n\n", i, a[i]);
#endif
	}

	for (i = 0; i<n; i++){
		printf("%3d ", a[i]);
		// 単純に10個出力するたびに改行しているだけ
		if (i % 10 == 9){
			putchar('\n');
		}
	}

	free(a);
	return 0;
}
