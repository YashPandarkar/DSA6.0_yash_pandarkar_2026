/*"Accept elements in n*m matrix and display its saddle point

(sadle point : the element which is the highest in the row and at the same time lowest in the column )"*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int n1, m1, highest,index, flag = 0, found = 0;
    int** ptr1 = NULL;

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
    printf("\n Matrix :\n\n");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){

            printf(" %d ",ptr1[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n1; i++){

        highest = ptr1[i][0],index = 0;

        for(int j = 0; j < m1; j++){

           if(ptr1[i][j] > highest){

                highest = ptr1[i][j];
                index = j;
            }
        }

        flag = 0;
        for(int k = 0; k < n1; k++){

            if(highest > ptr1[k][index]){

                flag = 1;
                break;
            }
        }
        if(flag == 0){

            printf("saddle point is %d ",highest);
            found = 1;
        }      
    }
    if(found == 0){

        printf("saddle point not found");
    }
        
    for (int i = 0; i < n1; i++) {
        free(ptr1[i]);
    }
    free(ptr1);
   
    return 0;
}    