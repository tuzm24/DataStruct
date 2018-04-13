//#include <stdio.h>
//
//#pragma warning(disable:4996)
//
//
//typedef struct clock{
//	int hour;
//	int min;
//	int sec;
//	int total;
//};
//
//#define TIME_D 60
//
//int main() {
//	clock arr[2];
//	clock ans;
//	for (int i = 0; i < 2; i++) {
//		scanf("%d%d%d", &arr[i].hour, &arr[i].min, &arr[i].sec);
//		arr[i].total = arr[i].hour * TIME_D*TIME_D + arr[i].min * TIME_D + arr[i].sec;
//	}
//	ans.total = arr[1].total - arr[0].total;
//	ans.hour = ans.total / (TIME_D*TIME_D);
//	ans.min = (ans.total % (TIME_D*TIME_D)) / TIME_D;
//	ans.sec = ans.total%TIME_D;
//	printf("%d %d %d", ans.hour, ans.min, ans.sec);
//	return 0;
//	
//
//}