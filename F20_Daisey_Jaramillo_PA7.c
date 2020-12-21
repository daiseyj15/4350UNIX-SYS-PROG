/*
NAME: Daisey Jaramillo
Course Number/Name: CS 4350-001 - Unix Systems Programming
Assignment Number: 7
Due Date: 11/18/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>

//prototypes
void *oddNums(void *inputt);
void *evenNums(void *inputt);
void *summ(void *inputt);
void *hailstonSeq(void *inputt);
void *armstrongNum(void *inputt);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int inputt, *pinputt;
    pthread_t tid1, tid2, tid3, tid4, tid5;
    printf("Welcome to Daisey Jaramillo's Thread App\n\n");
    printf("This program will do the following: \n\n");
    printf("Accepts an integer number X from the user and then uses 5\n");
    printf("synchronized threads in order to do the following: \n\n\n");
    printf("1. The first thread prints all odd numbers between 1\n");
    printf("   and X.\n");
    printf("2. The second thread prints all the even numbers\n");
    printf("   between 1 and X.\n");
    printf("3. The third thread prints the sum between 1 and X.\n");
    printf("4. The fourth thread print the hailstone sequence for\n");
    printf("   the number X.\n");
    printf("5. The last thread determines whether or not X is an\n");
    printf("   Armstrong number.\n\n");


    printf("Enter an Integer > 0 --- >     ");
    scanf("%d", &inputt);


    if(inputt>3000)
    {
        printf("\n\n***    Number must be grantor than 0    ***");
    }
    else if(inputt <= 0)
    {
       printf("\n\n***    Number must be grantor than 0    ***");

    }
    else
    {
        printf("\nAll odd / Even / Sum of numbers between 1 and %d \n\n",inputt);

        int numm = 1;
        while(numm<=inputt)
        {
            pthread_mutex_lock(&mutex1);

            pthread_create(&tid1,NULL,oddNums,numm);
            pthread_join(tid1,NULL);
            numm++;

            if(numm==inputt || numm>inputt)
            {
                break;
            }

            pthread_create(&tid2,NULL,evenNums,numm);
            pthread_join(tid2,NULL);

            pthread_create(&tid3,NULL,summ,numm);
            pthread_join(tid3,NULL);

            pthread_mutex_unlock(&mutex1);
            numm++;
        }



        printf("\nAll odd / Even / Sum Threads Exits\n\n");

        printf("\nFunction4 - Hailstone Process Started\n");
        pthread_create(&tid4,NULL,hailstonSeq,inputt);
        pthread_join(tid4,NULL);

        printf("\n\n\nFunction5 - Armstrong Process Started\n\n");
        pthread_create(&tid5,NULL,armstrongNum,inputt);
        pthread_join(tid5,NULL);

        printf("\n\nHailstone Thread Exits");
        printf("\nArmstrong Thread Exits\n");
        int hehe=1;
        int sum=0;
        while(hehe<=inputt)
        {
          sum+=hehe;
          hehe++;
        }
        printf("\nEnd of Main program  ---- >   Sum = %d",sum);
    }


    printf("\n\nProgram by Daisey Jaramillo\n");
    printf("11-30-2020\n");
    return 0;
}

void *oddNums(void *numm)
{
    int h=numm;

        if(h%2 == 1)
        {
            printf("Function1-Odd : %d\n",h);
        }



}
void *evenNums(void *numm)
{
    int k=numm;

        if(k%2 == 0)
        {
            printf("Function2-Even : %d\n",k);
        }

}

void *summ(void *numm)
{
    int thenum = numm;
    static int sums=0;
    int g= thenum-1;

   sums += (thenum + g);

    printf("Function3-Sum : %d\n",sums);

}

//this function gets the hailstone sequence
void *hailstonSeq(void *inputt)
{
    printf("Input Number %d\n",inputt);
    printf("Hailstone sequence of %d is: %d,",inputt,inputt);
    int x = inputt;

    while(x != 1)
    {
        if(x%2 == 0)
        {
            x=x/2;
            printf(" %d,",x);
        }
        else
        {
            x=((3*x)+1);
            printf(" %d,",x);
        }
    }

}
//this function determines if the number is an armstrong number
void *armstrongNum(void *inputt)
{
  int b = inputt;
  int arr[10];
  int x=0;
  while(b)
  {
      arr[x]=b%10;
      x++;
      b /= 10;
  }
  int g = x-1;
  int armss=0;
  while(g>=0)
  {
      armss+=(arr[g]*arr[g]*arr[g]);
      g--;
  }

  if(armss==b)
  {
      printf("%d is an Armstrong number\n",inputt);
  }
  else
  {
      printf("%d is not an Armstrong number\n",inputt);
  }
}
