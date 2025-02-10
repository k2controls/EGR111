#include <stdio.h>
int main()
{
	int mark;
	printf("Enter a number:");
	scanf("%d", &mark);
	if (mark > 95 && mark <= 100)
	{
		printf("O Grade");
	}
	else if (mark > 90 && mark <= 95)
	{
		printf("A grade");
	}
	else if (mark > 80 && mark < 91)
	{
		printf("B Grade");
	}
	else if (mark > 70 && mark < 81)
	{
		printf("C Grade");
	}
	else if (mark > 60 && mark < 71)
	{
		printf("D Grade");
	}
	else if (mark > 50 && mark < 61)
	{
		printf("E Grade");
	}
	else if (mark >= 0 && mark < 50)
	{
		printf("F Grade");
	}
	else
	{
		printf("Invalid Mark");
	}
	return 0;
}
