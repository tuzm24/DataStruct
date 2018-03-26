#include <stdio.h>
#pragma warning(disable:4996)


/*
길이를 알수 없는 arr 배열 중

0부터 n번째까지 중에 가장 큰 수를 return 한다.
*/

int rscanmax(int arr[], int n) { 
	if (n == 0)// index가 0 하나뿐인 배열(길이가 1인배열)은 index 0이 가장 큰수이다.
		return arr[n];
	int temp = rscanmax(arr, n - 1); // temp 에 n-1번째 인덱스 중에 가장 큰수를 보관한다
	if ( temp < arr[n])
		return arr[n]; // 비교후 큰수 return
	return temp;

}


int main() {
	int n;
	int arr[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", rscanmax(arr, n - 1));
	return 0;
	

}