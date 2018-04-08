// 1～nまでの乱数を重複せずに配列に格納
// アルゴリズム改良版、しかし満点ではない

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

	printf("nをいくつにしますか？");
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof(int));

	InitArray(a, n);

	// シャッフルしている部分
	// どういうアルゴリズムなのか考えてみよう
	for (i = 0; i<shuffleMax; i++){
		x = rand() % n;
		y = rand() % n;

		// x番目の要素をy番目の要素と入れ替えている
		// xとyはrand()により選ばれた値
		temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}

	ShowArray(a, n);

	free(a);

	return 0;
}

// n個の要素を持つdataに1～nを代入する関数
void InitArray(int *data, int n)
{
	int i;
	
	for (i = 0; i<n; i++){
		data[i] = i + 1;
	}
}

// n個の要素を持つdataを表示する関数
// 10個ごとに改行する
void ShowArray(int *data, int n)
{
	int i;
	
	for (i = 0; i<n; i++){
		printf("%3d ", data[i]);
		// 単純に10個出力するたびに改行しているだけ
		if (i % 10 == 9){
			putchar('\n');
		}
	}
}
