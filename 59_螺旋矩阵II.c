#include <stdlib.h>
#include <stdio.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
  int **matrix = malloc(n * sizeof(int *)); // 分配二维数组的行
  for (int i = 0; i < n; i++)
  {
    matrix[i] = malloc(n * sizeof(int)); // 分配二维数组的列
  }

  int left = 0, right = n - 1, top = 0, bottom = n - 1;
  int num = 1, tar = n * n;
  while (num <= tar)
  {
    for (int i = left; i <= right; i++)
      matrix[top][i] = num++; // 从左到右填充数字
    top++;
    for (int i = top; i <= bottom; i++)
      matrix[i][right] = num++; // 从上到下填充数字
    right--;
    for (int i = right; i >= left; i--)
      matrix[bottom][i] = num++; // 从右到左填充数字
    bottom--;
    for (int i = bottom; i >= top; i--)
      matrix[i][left] = num++; // 从下到上填充数字
    left++;
  }
  *returnSize = n;
  *returnColumnSizes = malloc(n * sizeof(int)); // 分配返回的列大小数组
  for (int i = 0; i < n; i++)
  {
    (*returnColumnSizes)[i] = n; // 设置每列的大小为n
  }
  return matrix;
}

void printMatrix(int **matrix, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void testGenerateMatrix() {
  int returnSize;
  int* returnColumnSizes;
  int** matrix = generateMatrix(3, &returnSize, &returnColumnSizes);
  printMatrix(matrix, returnSize);
  for (int i = 0; i < returnSize; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(returnColumnSizes);
}

int main() {
  testGenerateMatrix();
  return 0;
}