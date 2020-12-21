/*NAME:		Daisey Jaramillo
Serial	Number: 001
CS 4350–251-Unix Systems Programming
Assignment	Number:	5
Due	Date:	11 	/ 	2	/	2020 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("File Manipulation Program\n\n");

    FILE *filepointer;
    /* 1. */
    filepointer = fopen("pa4in.txt","w");

    if(filepointer == NULL)
   {
      printf("Error!");
      exit(1);
   }
    /* 2. */
    fputs("CS4350 - 001\n",filepointer);
    fputs("Unix Programing ;\n",filepointer);
    fputs("Fall 2020\n",filepointer);
    fputs("Assignment # 4;\n",filepointer);
    fputs("Due Date 11/2/2020",filepointer);


    /* 3. */
    fclose(filepointer);
    filepointer = fopen("pa4in.txt","r");

   if(filepointer == NULL)
   {
      printf("Error!");
      exit(1);
   }

    /* 4. */
    char c;
      while ((c = fgetc(filepointer)) != EOF)
      {
            printf("%c", c);
      }

    /* 5. & 6. */
    rewind(filepointer);

    char ch;
    int characters, words, lines;

    characters = words = lines = 0;
    while ((ch = fgetc(filepointer)) != EOF)
    {
        characters++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    printf("\n\nNumber of lines: %d",lines);
    printf("\nNumber of words: %d", words);


    /* 7. 8. 9. 10. 11. 12. 13. */
    rewind(filepointer);
    char chara;
    int spaces,smallLetters,capLetters,digits,alphaNum,special,endlineW;
    spaces=smallLetters=capLetters=digits=alphaNum=special=endlineW=0;

    while((chara=fgetc(filepointer))!= EOF)
    {
        if((isdigit(chara))==1)
            digits++;
        if(chara == ' ')
            spaces++;
        if((islower(chara))!=0)
            smallLetters++;
        if((isupper(chara))==1)
            capLetters++;
        if((isalnum(chara))==1)
            alphaNum++;
        if((ispunct(chara))!=0)
            special++;
        if(chara == ';')
            endlineW++;
    }
    printf("\nNumber of Small Letters: %d", smallLetters);
    printf("\nNumber of Capital Letters: %d", capLetters);
    printf("\nNumber of Digits: %d", digits);
    printf("\nNumber of Alpha Numeric Characters: %d", alphaNum);
    printf("\nNumber of Spaces: %d", spaces);
    printf("\nNumber of Special Symbols: %d", special);
    printf("\nNumber of Lines that end with ';': %d", endlineW);


    /* 14. */
    rewind(filepointer);
    FILE *fptr;
    fptr = fopen("pa4o1.txt","w");
    char cc;
    while((cc=fgetc(filepointer))!= EOF)
    {
        if(isalpha(cc))
        {
            if(islower(cc))
            {
                char tu = toupper(cc);
                fprintf(fptr,"%c",tu);
            }
            if(isupper(cc))
            {
                char tl = tolower(cc);
                fprintf(fptr,"%c",tl);
            }
        }
        else if(isprint(cc))
        {
            fprintf(fptr,"%c",cc);
        }
    }
        fclose(fptr);
    /* 15. */
    rewind(filepointer);
    FILE *fptr2;
    fptr2 = fopen("pa4o2.txt","w");
    char line[250];
    int num=1;
    while(fgets(line,sizeof(line),filepointer))
    {
        fprintf(fptr2,"%d. ",num);
        fprintf(fptr2,"%s",line);
        num++;
    }

        fclose(fptr2);

    /* 16. */
    fptr = fopen("pa4o1.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fptr2 = fopen("pa4o2.txt","r");
    if(fptr2 == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("\n\nContents of pa4o1.txt\n\n");
      char d=d;
      while ((d = fgetc(fptr)) != EOF)
      {
            printf("%c", d);
      }
    printf("\n\nContents of pa4o2.txt\n\n");
      char q=q;
      while ((q = fgetc(fptr2)) != EOF)
      {
            printf("%c", q);
      }

    /* 17. */
    int i =0;
    fclose(filepointer);
    fclose(fptr);
    fclose(fptr2);
    i = system("rm pa4in.txt");
    printf("\n\nRemoved pa4in.txt!\n");
    i = system("rm pa4o1.txt");
    printf("Removed pa4o1.txt!\n");
    i = system("rm pa4o2.txt");
    printf("Removed pa4o2.txt!\n\n");


    /* 18. */
    filepointer = fopen("pa4in.txt","r");
    if(filepointer == NULL)
    {
      printf("\n\nFile pa4in.txt does not exist!\n");
    }

    fptr = fopen("pa4o1.txt","r");
    if(fptr == NULL)
    {
      printf("File pa4o1.txt does not exist!\n");
    }

    fptr2 = fopen("pa4o2.txt","r");
    if(fptr == NULL)
    {
      printf("File pa4o2.txt does not exist!\n");
    }

    printf("\n\n\nImplemented by Daisey Jaramillo\n");
    printf("November - 2nd - 2020\n");
    return 0;
}
