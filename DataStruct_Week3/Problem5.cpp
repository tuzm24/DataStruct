#include <stdio.h>
#pragma warning(disable:4996)

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) { // 원반이 하나밖에 없는경우. 원반을 목적막대로 옮긴후 return.
		printf("%c %c\n", from, to);
		return;
	}
	rHanoi(n - 1, from, to, aux); // n-1개의 원반을 rHanoi 재귀 호출로 aux로 이동
	printf("%c %c\n", from, to); // n번째 원반을 목적막대로 이동
	rHanoi(n - 1, aux, from, to); // n-1개의 원반을 rHanoi 호출로 to로 이동
	return;
}


int main() {
	int n;
	scanf("%d", &n);
	rHanoi(n, 'A', 'B', 'C');
	return 0;
}