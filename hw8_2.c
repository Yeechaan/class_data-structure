#include <stdio.h> 

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[7];

	printf("Write down the numbers\n");
	for (int i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);
	}

	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);

	printf("\nBubble Sorted array is \n");
	printArray(arr, n);

	return 0;
}