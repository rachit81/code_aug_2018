#include <stdio.h>

void printMatrix(int mat[][5],int row, int col)
{
	int i, j;
	for (i =0 ;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
		printf("\n");
}

/*****Rotate a matrix by 90 degree without using any extra space***/

void transpose(int mat[][5],int row, int col)
{
	int i, j;
	int temp;
	for (i =0 ;i<row;i++)
	{
		for (j=i;j<col;j++)
		{
			temp =mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;

		}
	}

}

void rotateAntiClockwise(int mat[][5],int row, int col)
{
	int i, j,temp;
	for (i =0 ;i<row/2;i++)
	{
		for (j=0;j<col;j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[row-i-1][j];
		    mat[row-i-1][j] =temp;	
		}
	}

}

void rotateClockwise(int mat[][5],int row, int col)
{
	int i, j,temp;
	for (i =0 ;i<row;i++)
	{
		for (j=0;j<col/2;j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[i][col-1-j];
		    mat[i][col-1-j] =temp;	
		}
	}

}


/*****Rotate a matrix by 90 degree without using any extra space***/

int main()
{
	int mat[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	printMatrix(mat,5,5);
	transpose(mat,5,5);
	printMatrix(mat,5,5);
	rotateAntiClockwise(mat,5,5);
	//rotateClockwise(mat,5,5);
	printMatrix(mat,5,5);
}
