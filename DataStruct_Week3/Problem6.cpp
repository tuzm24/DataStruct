#include <stdio.h>
#pragma warning(disable:4996)



int rUclidGCD(int a, int b) {
	if (b == 0) // 몫이 0이 될때, 즉 최소공약수를 찾았으면 그 수를 return.
		return a;
	return rUclidGCD(b, a%b);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", rUclidGCD(a, b));
	return 0;

}