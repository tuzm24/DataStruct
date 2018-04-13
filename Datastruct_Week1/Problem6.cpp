//#include <stdio.h>
//
//#pragma warning(disable:4996)
//
//#define MAX_NAME 10
//
//typedef struct student {
//	char name[MAX_NAME];
//	int grade;
//
//};
//
//#define MAX_STUDENT 5
//
//int main() {
//	student starr[MAX_STUDENT];
//	double avg = 0;
//	for (int i = 0; i < MAX_STUDENT; i++) {
//		scanf("%s%d", starr[i].name, &starr[i].grade);
//		avg += starr[i].grade;
//	}
//	avg = avg / MAX_STUDENT;
//	for (int i = 0; i < MAX_STUDENT; i++)
//		if (starr[i].grade <= avg)
//			printf("%s\n", starr[i].name);
//	return 0;
//
//}