/*Program to Insert, Delete or Search within an array*/

#include<stdio.h>
#include<conio.h>
#include<math.h>


#define MAX 100

void Insert(int n, long int arr[MAX]);
void Delete(int n, long int arr[MAX]);
void Search(int n, long int arr[MAX]);

int main()
{
	long int arr[MAX];
	int i, j, n, task, realCount,temp, min, pos;
	printf("\nEnter Length of the Array : "); scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		realCount=i+1;
		printf("Enter Element %d : ", realCount); scanf("%d", &arr[i]);
	}
	
/*Sorting Array*/
	
	/*for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			{
				if(arr[i]>arr[j]){
					temp = arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}*/
			
	for(i=0; i<n-1; i++){
		min=arr[i];
		pos=i;
		for(j=i+1; j<n; j++){
			if(arr[j]<min){
				min=arr[j];
				pos=j;
			}
		}
			temp=arr[i];
			arr[i]=arr[pos];
			arr[pos]=temp;
	}
	
	printf("\n*****Sorted Array in Ascending Order*****\n");
	for(i=0;i<n;i++){
		realCount=i+1;
		printf("\nElement %d : %d",realCount, arr[i]);
	}
	
/*Options to perform Actions*/
	repeat:
	printf("\n\n--Enter '1' to perform INSERT--\n--Enter '2' to perform DELETE--\n--Enter '3' to perform SEARCH--\n--Enter '4' to EXIT--\n"); scanf("%d",&task);
	
	switch(task){
	case 1:	Insert(n, arr); n=n+1; goto repeat;
	case 2: Delete(n, arr); n=n-1; goto repeat;;
	case 3: Search(n, arr); goto repeat;;
	case 4: printf("*****EXITING*****"); break;			
	}
}

/*Function Definitions*/

/*INSERT Function*/

void Insert(int n, long int arr[MAX]){
	int element, position, i, realCount;
	printf("\nEnter New Element to Insert : "); scanf("%d",&element);
	printf("\nEnter Position : "); scanf("%d",&position);
	position = position-1;
	for (i=n-1;i>=position;i--){
		arr[i+1]=arr[i];
	}
	arr[position]=element;
	printf("\n*****Modified Array*****\n");
	for(i=0;i<n+1;i++){
		realCount=i+1;
		printf("\nElement %d : %d", realCount,arr[i]);
	}
	}

/*DELETE Function*/

void Delete(int n, long int arr[MAX]){
	int position, i, realCount;
	printf("\nEnter Position : "); scanf("%d",&position);
	position=position-1;
	for(i=position;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	printf("\n*****Modified Array*****\n");
	for(i=0;i<n-1;i++){
		realCount=i+1;
		printf("\nElement %d : %d",realCount,arr[i]);
	}
}

/*SEARCH Function*/

void Search(int n,long int arr[MAX]){
	int element,realCount,i, check=0;
	printf("\nEnter Search Element : "); scanf("%d",&element);
	for(i=0;i<n;i++){
		if(arr[i]==element)
			{
			realCount=i+1;
			printf("\nMatch Found - Element Number %d : %d", realCount ,arr[i]);
			check = 1;
			
			}
		} if(check==0)
			{
			printf("\nElement Not in the Array !!\n");
			}
	
}
