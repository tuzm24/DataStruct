//#include <stdio.h>
//
//#pragma warning(disable:4996)
//
//
//#define MAX_ARR 10
//
//void swap(int *a, int *b) {
//	int temp; 
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//
//void ABC(int arr[], int k) {
//	int *index = &arr[k];
//	for (int i = k; i < MAX_ARR; i++) 
//		if (*index < arr[i])
//			index = &arr[i];
//	swap(index, &arr[k]);
//	return;
//}
//
//int main() {
//	int arr[MAX_ARR];
//	for (int i = 0; i < MAX_ARR; i++)
//		scanf("%d", &arr[i]);
//	for (int i = 0; i < MAX_ARR-1; i++)
//		ABC(arr, i);
//	for (int i = 0; i < MAX_ARR; i++)
//		printf(" %d", arr[i]);
//	return 0;
//}