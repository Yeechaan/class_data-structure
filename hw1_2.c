
//data_hw1_2
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
	int arr_size = 0;
	int *numbers;
	int move_number;

	int number;
	int i = 0;
	FILE *file;

	file = fopen("numbers.txt", "rt");
	if (file != NULL) {
		fscanf(file, "%d", &number);
		while (!feof(file)) {
			fscanf(file, "%d", &number);
			arr_size++;
		}
		if (arr_size > 0) {
			numbers = (int*)calloc(arr_size, sizeof(int));
		}
		fseek(file, 0, SEEK_SET);
		fscanf(file, "%d", &number);
		while (!feof(file)) {
			numbers[i] = number;
			fscanf(file, "%d", &number);
			i++;
		}
		fclose(file);
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
