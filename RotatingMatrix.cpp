#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char buffer;
	int angle = 0;
	int matrix[4][4] = { { 4, 3, 8, 1 }, 
						 { 2, 7, 6, 5}, 
						 { 3, 4, 9, 2}, 
						 { 1, 2, 4, 7} };
	int newMatrix[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	scanf("%d", &angle); scanf("%c", &buffer);

	if (angle < 0)
		angle += 360;

	for (int x = 0; x < angle / 90; x++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newMatrix[j][4-1-i] = matrix[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix[i][j] = newMatrix[i][j];
			}
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}