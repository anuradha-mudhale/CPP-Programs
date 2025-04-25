#include <stdio.h>

// Function to search for a key in the matrix
int larEle(int mat1[3][3])
{
	int i,j;
	printf("largest element in mat is:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			int max=0;
			if(max<mat[i][j])
			{
			max = mat[i][j];	
			}
			
		}
	}
	
}
int search(int mat1[3][3], int key)
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(key == mat1[i][j])
            {
                printf("Element %d found at position (%d, %d)\n", key, i, j);
                return 1;  // Return 1 if key is found
            }
        }
    }
    printf("Element %d not found in the matrix.\n", key);
    return 0;  // Return 0 if key is not found
}

int main()
{
    int mat1[3][3];
    int i, j, key;

    // Taking input for mat1
    printf("Enter mat1 elements:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Printing mat1
    printf("mat1 elements:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", mat1[i][j]);  // Added space for better formatting
        }
        printf("\n"); // Moves to next row
    }

    // Asking user for the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Searching for the key in the matrix
    search(mat1, key);
    larEle(mat1);

    return 0;
}

