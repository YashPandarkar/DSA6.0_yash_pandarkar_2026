/*Accept  two different n*m matrix and store and display the addition of two matrix in 3rd matrix*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n1, m1, n2 ,m2;
    int** ptr1 = NULL, **ptr2 = NULL, **ptr3 = NULL;

    printf("\nenter the rows of matrix1 :");
    scanf("%d",&n1);

    printf("\nenter the column of matrix1 :");
    scanf("%d",&m1);

    ptr1 = (int**)malloc(n1 * sizeof(int*));
    for(int i = 0; i < n1; i++){

       ptr1[i] = (int*)malloc(m1 * sizeof(int));
    }

    printf("\nenter the elements :");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            scanf("%d",&ptr1[i][j]);
        }
    }
    printf("\nenter the rows of matrix2 :");
    scanf("%d",&n2);

    printf("\nenter the column of matrix2 :");
    scanf("%d",&m2);

    ptr2 = (int**)malloc(n2 * sizeof(int*));
    for(int i = 0; i < n2; i++){

       ptr2[i] = (int*)malloc(m2 * sizeof(int));
    }

    printf("\nenter the elements :");
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2; j++){

            scanf("%d",&ptr2[i][j]);
        }
    }

    printf("\n Matrix 1 :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr1[i][j]);
        }
        printf("\n");
    }
    printf("\n Matrix 2 :\n\n");
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2; j++){

            printf(" %d ",ptr2[i][j]);
        }
        printf("\n");
    }
    if(n1 == n2 && m1 == m2){

        ptr3 = (int**)malloc(n1 * sizeof(int*));

        for(int i = 0; i < n1; i++){
            ptr3[i] = (int*)malloc(m1 * sizeof(int));
        }

        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m1; j++){

                ptr3[i][j] = ptr1[i][j] + ptr2[i][j];
            }
        }
        printf("\n Matrix 3 :\n\n");
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m1; j++){

                printf(" %d ",ptr3[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < n1; i++) {
            free(ptr3[i]);
        }
        free(ptr3);

    }else{

        printf("matrix are not same ");
    }
    for (int i = 0; i < n1; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
    for (int i = 0; i < n2; i++) {
        free(ptr2[i]);
    }
    free(ptr2);

    return 0;
}    