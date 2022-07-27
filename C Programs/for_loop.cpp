#include<stdio.h>

int main()
{
	float cel_start, cel_stop, far; int i=1;
	printf("Enter Celcius Start Value\n");
	scanf("%f",&cel_start);
	printf("Enter Celcius Stop Value\n");
	scanf("%f",&cel_stop);
	for(i=cel_start; i<=cel_stop; i++)
	{
		far=(9.0/5.0)*i+32;
		printf("%d Celcius = %0.2f Farhenhite\n",i,far);
	}
}
