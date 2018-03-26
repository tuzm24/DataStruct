#include <stdio.h>
#pragma warning(disable:4996)


#define SMALLEST_NUM 1


int sumation(int n) {
	if (n == SMALLEST_NUM) // 재귀를 그만할 조건
		return n; // 처음 값을 반환한다.
	return sumation(n - 1) + n; // 재귀적 호출
	
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", sumation(n));
	return 0;
}