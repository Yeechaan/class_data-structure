
//data_hw1_1
#include<stdio.h>
#include<stdlib.h>

void leftRotate(int numbers[], int move_number, int count);
void leftRotatebyOne(int numbers[], int count);
void printArray(int numbers[], int count);

void leftRotate(int numbers[], int move_number, int count)
{
	int i;
	for (i = 0; i < move_number; i++)
	{
		leftRotatebyOne(numbers, count);
	}
}

void leftRotatebyOne(int numbers[], int count)
{
	int temp = numbers[0], i;
	for (i = 0; i < count - 1; i++)
	{
		numbers[i] = numbers[i + 1];
	}
	numbers[i] = temp;
}

void printArray(int numbers[], int count)
{
	int i;
	printf("Array is : ");
	for (i = 0; i < count; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	printf("%s\n", "11_ÀÌ¿¹Âù_20180903");
	int i = 0;
	int arr_size;
	int *numbers;
	int move_number;

	printf("What is Array size : ");
	scanf("%d", &arr_size);
	numbers = (int*)calloc(arr_size, sizeof(int));

	if (numbers == NULL) {
		return 0;
	}
	printf("What is Array elements : ");
	while (i < arr_size) {
		scanf("%d", &numbers[i]);
		i++;
	}
	printArray(numbers, arr_size);

	printf("How many left do you want : ");
	scanf("%d", &move_number);

	leftRotate(numbers, move_number, arr_size);
	printf("Moved ");
	printArray(numbers, arr_size);

	free(numbers);

	return 0;
}
