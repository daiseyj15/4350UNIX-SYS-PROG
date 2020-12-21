/*
NAME: Daisey Jaramillo
CS 4350-Unix Systems Programming
Assignment Number:  4
Due Date: 10/19/2020 No Later than 5:15pm
This program creates a 7x& 2d array then passes
it to different functions to manipulate it
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popArray(int arr[7][7]);
void howManyOnes(int arr[7][7]);



int main()
{
    srand(time(NULL));
    char de='f';
    int seven[7][7];

   while(2<5)
    {
        popArray(seven);
        printf("You are given 7x7 array whose elements are either 0 or 1.");
        printf("\n\nThen program then will ask for two integer indices i and j");
        printf("\n(less or equal to 7 or -1) and will return the number of nonzero");
        printf("\nelements of the array that are adjacent to the i-th and j-th element.");
        printf("\n\nThe generated array is:\n");

    /*DISPLAY THE ARRAY*/
        printf("_____________________________\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[0][0],seven[0][1],seven[0][2],seven[0][3],seven[0][4],seven[0][5],seven[0][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[1][0],seven[1][1],seven[1][2],seven[1][3],seven[1][4],seven[1][5],seven[1][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[2][0],seven[2][1],seven[2][2],seven[2][3],seven[2][4],seven[2][5],seven[2][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[3][0],seven[3][1],seven[3][2],seven[3][3],seven[3][4],seven[3][5],seven[3][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[4][0],seven[4][1],seven[4][2],seven[4][3],seven[4][4],seven[4][5],seven[4][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[5][0],seven[5][1],seven[5][2],seven[5][3],seven[5][4],seven[5][5],seven[5][6]);
        printf("|___|___|___|___|___|___|___|\n");
        printf("| %d | %d | %d | %d | %d | %d | %d |\n",seven[6][0],seven[6][1],seven[6][2],seven[6][3],seven[6][4],seven[6][5],seven[6][6]);
        printf("|___|___|___|___|___|___|___|\n");


        howManyOnes(seven);
    do{
           printf("\nWould like to rerun the program again (Y or N): ");
            de=getchar();

                switch(de)
                {
                case 'Y':
                    break;
                case 'y':
                    break;
                case 'n':
                    break;
                case 'N':
                    break;
                default:
                    printf("\nInvalid. Must be Y|y or N|n");
                }

         if(de == 'n' || de == 'N')
            break;
         if(de == 'y' || de == 'Y')
            break;

    }while(2<5);



        if(de == 'n' || de == 'N')
            break;
    }


    printf("\n\nProgram is Terminated\n");
    printf("This algorithm is implemented by Daisey Jaramillo\n");
    printf("October - 2020");
    return 0;
}

void popArray(int arr[7][7])
{   int x=0;
    int y=0;
    int r=0;


    while(x<7)
    {
         while(y<7)
         {
             r=rand();
            if(r%2==0)
            {
                arr[x][y]=0;
            }
            else
            {
                arr[x][y]=1;
            }
           y++;
         }
      y=0;
      x++;
    }

}

void howManyOnes(int arr[7][7])
{
    int x,y;
    int sumOfOnes=0;
    int ans1=2;
    int ans2=2;

    while(ans1 != -1 && ans2 != -1)
    {
        sumOfOnes=0;
        printf("Enter two integer indices i and j (between 1 and 7) or -1 to exit\n");
        scanf("%d %d",&ans1,&ans2);

        if(ans1==-1 || ans2==-1)
          continue;

        if((ans1<1)||(ans1>7)||(ans2<1)||(ans2>7))
        {
            while((ans1<1)||(ans1>7)||(ans2<1)||(ans2>7))
            {
            printf("Invalid. Indices must be between 1 and 7 or -1 to exit\n");
            scanf("%d %d",&ans1,&ans2);
            }
          if(ans1==-1 || ans2==-1)
          continue;
        }
        sumOfOnes=0;\

        x=ans1-1;
        y=ans2-1;

        if(arr[x-1][y-1]==1)
            sumOfOnes++;
        if(arr[x-1][y]==1)
            sumOfOnes++;
        if(arr[x-1][y+1]==1)
            sumOfOnes++;
        if(arr[x][y-1]==1)
            sumOfOnes++;
        if(arr[x][y+1]==1)
            sumOfOnes++;
        if(arr[x+1][y-1]==1)
            sumOfOnes++;
        if(arr[x+1][y]==1)
            sumOfOnes++;
        if(arr[x+1][y+1]==1)
            sumOfOnes++;




        printf("\nNumber of non-zero neighbors to element (%d,%d) = %d\n", ans1,ans2,sumOfOnes);
    }
}
