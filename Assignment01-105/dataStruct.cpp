/**
*	Data Structure - Programming Assignment (1)
*	powered by aaaddress1@gmail.com
**/
#include <stdio.h>
#include <stdlib.h>

void usrInputPoly(int *arr, int leaderTerm) {
	for(int i = leaderTerm; (i + 1); i--) {
		printf("input the coefficient of n^%d: ", i);
		scanf("%d", (arr + i));
	}
	puts("");
}

void polyDisplay(int *arr, int leaderTerm) {
	for(int i = leaderTerm; (i + 1); i--) {
		printf("(%dn^%d)", *(arr + i), i);
		if (i > 0) printf(" + ");
	}
	puts("");
}
int evalPoly(int *arr, int leaderTerm, int base) {
	int sum = 0, n = 1;
	for(int i = 0; i < leaderTerm + 1 ; i++) {
		sum += n **(arr + i);
		n *= base;
	}
	return sum;
}

int main(void) {
	int leaderTerm = 0, n = 0;
	printf("input the max leader term: ");
	if (!scanf("%d", &leaderTerm)) {
		puts("It's not a real leader term input.");
		exit(1);
	}

	int *poly[4] =
	{
		new int[leaderTerm + 1],
		new int[leaderTerm + 1],
		new int[leaderTerm + 1],
		new int[leaderTerm + 1]
	};
	for(int i = 0; i < 2; i++) {
		puts("");
		printf("please input the detail of polynomial %c\n", "AB"[i]);
		usrInputPoly(poly[i], leaderTerm);
		printf("this is your polynomial %c\n", "AB"[i]);
		polyDisplay(poly[i], leaderTerm);
	}

	puts("");
	puts("this is the sum of polynomial A and B:");
	for(int i = leaderTerm; (i + 1); i--)
		*(poly[2] + i) = *(poly[0] + i) + *(poly[1] + i);
	polyDisplay(poly[2], leaderTerm);
	puts("this is the difference between polynomial A and B:");
	for(int i = leaderTerm; (i + 1); i--)
		*(poly[2] + i) = *(poly[0] + i) - *(poly[1] + i);
	polyDisplay(poly[2], leaderTerm);

	puts("");
	printf("give a number as n: ");
	if (!scanf("%d", &n)) {
		puts("It's not a real n input.");
		exit(1);
	}
	for(int i = 0; i < 2; i++)
		printf
		(
			"value of polynomial %c is %i\n",
			"AB"[i],
			evalPoly(poly[i],leaderTerm, n)
		);
	return 0;
}
