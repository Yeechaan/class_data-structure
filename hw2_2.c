
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void ReverseArray(int arr[], int size);
void PrintArray(int arr[], int size);

void ReverseArray(int arr[], int size)
{
	int start, end;
	int temp;

	start = 0;
	end = size - 1;

	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}
}

void PrintArray(int arr[], int size) 
{
	int i;
	printf("Array is : ");
	for (i = 0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[MAX];
	int size, i;
	int temp; 

	//1. Write down Array size
	printf("Write down the Array size : ");
	scanf("%d", &size);

	//2. Write down Array's elements
	printf("Write down Array's elements : ");
	for (i = 0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}

	//3, Print the Array
	PrintArray(arr, size);
	printf("\n");

	//4. reverse the Array
	ReverseArray(arr, size);

	//5, Print the reversed Array
	printf("Reversed ");
	PrintArray(arr, size);

	return 0;
}
