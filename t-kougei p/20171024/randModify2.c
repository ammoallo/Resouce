// 1～nまでの乱数を重複せずに配列に格納
// 最終完成版

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

	printf("nをいくつにしますか？");
	scanf("%d", &n);
	a=(int*)malloc(n*sizeof(int));

	InitArray(a, n);

	// シャッフルしている部分
	// 例えばn=5なら、
	// [4]は[0]～[4]のどれかと交換
	// [3]は[0]～[3]のどれかと交換
	// [2]は[0]～[2]のどれかと交換
	// [1]は[0]～[1]のどれかと交換

	for(i=n-1; i>=1; i--){
		x=rand()%(i+1);

		// i番目の要素をx番目の要素と入れ替えている
		// xはrand()により選ばれた値
		temp=a[x];
		a[x]=a[i];
		a[i]=temp;
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
// n個の要素を持つdataを表示する関数、10個ごとに改行する
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
