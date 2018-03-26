#include <stdio.h>
#pragma warning(disable:4996)

void PrintHighest(int n) {
	if (n == 0)
		return;
	PrintHighest(n / 10);
	printf("%d\n", n % 10);
	return;
}


int main() {
	int n;
	scanf("%d", &n);
	PrintHighest(n);
	return 0;
}