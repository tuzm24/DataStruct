#include <stdio.h>
#pragma warning(disable:4996)

#define MAX_STRING 100

int rScanCharater(char *str, char target) {
	if (*str == '\0')
		return 0;
	if (*str == target)
		return 1 + rScanCharater(str + 1, target);
	return rScanCharater(str + 1, target);
}

int main() {
	char str[MAX_STRING + 1];
	char c;
	scanf("%s%c%c", str, &c, &c);
	printf("%d\n", rScanCharater(str, c));
	return 0;

}