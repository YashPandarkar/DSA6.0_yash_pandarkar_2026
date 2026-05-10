/*"- Write a C program which allocates 2D array dynamically (N X M).

- Implement logic to get:
    - Sum of all elements.
    - sum of elements from the 2nd column
    - Display left and right diagonals
    - sum of left diagonal
    - sum of right diagonal
    - larger element from left diagonal
    - smaller element from left diagonal
    - larger element from right diagonal
    - smaller element from right diagonal
    - Sort the left diagonal
    - sort the right diagonal"*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, m, sum, smallest, largest, temp;
    int** ptr = NULL;

    printf("\nenter the rows of array :");
    scanf("%d",&n);

    printf("\nenter the column of array :");
    scanf("%d",&m);

    ptr = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){

       ptr[i] = (int*)malloc(m * sizeof(int));
    }

    printf("\nenter the elements :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            scanf("%d",&ptr[i][j]);
        }
    }

    printf("\n 2D array :\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            printf(" %d ",ptr[i][j]);
        }
        printf("\n");
    }

    sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

          sum = sum + ptr[i][j];
        }
    }
    printf("\nSum of all elements : %d \n",sum);

    sum = 0;
    for(int i = 0; i < n; i++){
        
        sum = sum + ptr[i][1];   
    }
    printf("\nSum of elements from the 2nd column : %d \n",sum);

    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(i == j || (m - 1 - j == i)){
                printf(" %d ",ptr[i][j]);
            }else{
                printf("   ");
            }    
        }
        printf("\n");
    }
    if(n == m){

        sum = 0,smallest = ptr[0][0], largest = ptr[0][0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(j == i){
                    sum = sum + ptr[i][j];

                    if(ptr[i][j] < smallest){
                        smallest = ptr[i][j];
                    }
                    if(ptr[i][j] > largest){
                        largest = ptr[i][j];
                    }
                }
            }
        }
        printf("\nSum of left diagonals : %d \n",sum);
        printf("\nSmallest element of left diagonals : %d \n",smallest);
        printf("\nLargest element of left diagonals : %d \n",largest);

        sum = 0,smallest = ptr[0][m-1], largest = ptr[0][m-1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(m - 1 - j == i){
                    sum = sum + ptr[i][j];

                    if(ptr[i][j] < smallest){
                        smallest = ptr[i][j];
                    }
                    if(ptr[i][j] > largest){
                        largest = ptr[i][j];
                    }
                }
            }
        }
        printf("\nSum of right diagonals : %d \n",sum);
        printf("\nSmallest element of right diagonals : %d \n",smallest);
        printf("\nLargest element of right diagonals : %d \n",largest);
        

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < m; j++){

                if(ptr[i][i] > ptr[j][j]){

                    temp = ptr[i][i];
                    ptr[i][i] = ptr[j][j];
                    ptr[j][j] = temp;
                }
            }
        }
        printf("\n Sorted left diagonal :\n\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                printf(" %d ",ptr[i][j]);
            }
            printf("\n");
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < m; j++){

                if(m - 1 - j == i){
                    if(ptr[i][n - 1 -i] > ptr[j][n - 1 - j]){

                        temp = ptr[i][n - 1 - i];
                        ptr[i][n - 1 - i] = ptr[j][n - 1 - j];
                        ptr[j][n - 1 - j] = temp;
                    }
                }
            }
        }
        printf("\n Sorted right diagonal :\n\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                printf(" %d ",ptr[i][j]);
            }
            printf("\n");
        }
    }else{
        
        printf("matrix is not valid for digonal operations");
    }

    for (int i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}    