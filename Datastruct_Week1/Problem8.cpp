#include <stdio.h>
#include <malloc.h>

#pragma warning(disable:4996)

#define MAX_NAME 8
#define MAX_SUBJECT 3
typedef struct student {
	char name[MAX_NAME];
	int grade[MAX_SUBJECT];
	double avg;

};

#define GREAT_SCORE 90
#define BAD_SCORE 70

int main() {
	int n;
	student *starr;
	scanf("%d", &n);
	starr = (student*)malloc(sizeof(student)*n);
	for (int i = 0; i < n; i++) {
		scanf("%s", starr[i].name);
		starr[i].avg = 0;
		for (int j = 0; j < MAX_SUBJECT; j++) {
			scanf("%d", &starr[i].grade[j]);
			starr[i].avg += starr[i].grade[j];
		}
		starr[i].avg = starr[i].avg / MAX_SUBJECT;
	}
	for (int i = 0; i < n; i++) {
		printf("%s %.1lf", starr[i].name, starr[i].avg);
		for(int j=0; j<MAX_SUBJECT; j++)
			if (starr[i].grade[j] >= GREAT_SCORE) {
				printf(" GREAT");
				break;
			}
		for (int j = 0; j<MAX_SUBJECT; j++)
			if (starr[i].grade[j] <= BAD_SCORE) {
				printf(" BAD");
				break;
			}
		printf("\n");
	}
	return 0;


}