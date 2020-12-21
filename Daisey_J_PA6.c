/*NAME:	Daisey Jaramillo
CS 4350–001-Unix Systems Programming
Assignment	Number: 6
Due	Date: 11/16/2020  */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/stat.h>


void num2(char filenamee[]);
void num3and5and9(char filenamee[]);
void num4(char filenamee[]);
void num6and7(char filenamee[]);
void num8and33();
void num10(char filenamee[]);
void num11();
void num12();
void num13();
void num14and15and16();
void num17(char filenamee[]);
void num18and19and20(char filenamee[]);
void num28(char filenamee[]);
void num29(char filenamee[]);
void num31(char filenamee[]);
void num32(char filenamee[]);
void num34(char filenamee[]);
void num35(char filenamee[]);


int main()
{
    char *temp;
    char fileNamee[50];
    printf("System / File Manipulation Program \n\n");
    printf("1. Enter File name to be created :   ");
    scanf("%s", fileNamee);
    /*2-35 must be implemented in functions*/
    num2(fileNamee);
    printf("\n3. File permission status is : \n");
    num3and5and9(fileNamee);
    num4(fileNamee);
    printf("\n5. File permission status is : \n");
    num3and5and9(fileNamee);
    num6and7(fileNamee);
    printf("\n8. Current date and time is : \n");
    num8and33();
    printf("9. Time of last file access :\n");
    num3and5and9(fileNamee);
    num10(fileNamee);
    num11();
    num12();
    num13();
    num14and15and16();
    num17(fileNamee);
    num18and19and20(fileNamee);
    num28(fileNamee);
    num29(fileNamee);
    printf("\n30. The time of last access of %s file\n", fileNamee);
    num3and5and9(fileNamee);
    num31(fileNamee);
    char newww[]="p6in-2.txt";
    num32(newww);
    printf("\n33. The current date and time: \n");
    num8and33(newww);
    num34(newww);
    num35(newww);


    printf("\n\nNovember - 2020\n");
    printf("Daisey Jaramillo\n\n");
    return 0;
}
//function to create file
void num2(char filenamee[])
{
    printf("2. %s File is created.", filenamee);
     char str[50] = "touch ";
    strcat(str,filenamee);
    const char *command = str;
    system(command);

}
//function to see properties of the file
void num3and5and9(char filenamee[])
{
    char str2[50]="ls -l ";
    strcat(str2,filenamee);
    const char *command2 = str2;
    system(command2);
}
//function to change mode
void num4(char filenamee[])
{
    printf("4. File mode is changed");
    char str3[50]="chmod 700 ";
    strcat(str3,filenamee);
    const char *command3 = str3;
    system(command3);
}
//function to add to file
void num6and7(char filenamee[])
{
  printf("6. Text is appended to the file.");
  const char *namee = filenamee;
  FILE *filepointer;
  filepointer = fopen(namee,"w");
  fprintf(filepointer,"Texas State University, Fall 2020, Unix Programming");
  fclose(filepointer);
  printf("\n7. File is closed.");
}
//fuction to show date and time
void num8and33()
{
    system("date");
}
//function to show contents of file
void num10(char filenamee[])
{
    printf("10. The content of the created file is : \n");
    char str4[50]="cat ";
    strcat(str4,filenamee);
    const char *command4 = str4;
    system(command4);
}
//function to show system name and hostname
void num11()
{
    int uname(struct utsname *name);
    struct utsname uts;
    uname(&uts);
    printf("\n11. System name: %s\n", uts.sysname);

}
//function to show local host name
void num12()
{
    printf("12. Local host name: \n");
    system("who -m");
}
//function to show host name
void num13()
{
    char hostbuffer[256];
    int hostname;

    hostname = gethostname(hostbuffer,sizeof(hostbuffer));

    if(hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
    printf("13. Host name: %s\n", hostbuffer);
}
//function to get process id, parent id, and priority
void num14and15and16()
{
    int which = PRIO_PROCESS;
    id_t pid;
    int ret;
    pid_t process_id;
    process_id = getpid();
    printf("14. The process id: %d\n",process_id);
    process_id = getppid();
    printf("15. Parent process id: %d\n",process_id);
    pid = getpid();
    ret = getpriority(which,pid);
    printf("16. Priority level of the process: %d\n",ret);
}
//function to show file name
void num17(char filenamee[])
{
    printf("17. The file Name is %s\n",filenamee);
}
//function to file stats 18-27
void num18and19and20(char filenamee[])
{
    struct stat file_stats;
    if((stat(filenamee,&file_stats))==-1)
    {
        perror("fstat");
    }
    printf("18. The device is: %lld\n", file_stats.st_dev);
    printf("19. The inode is: %lld\n", file_stats.st_ino);
    printf("20. The file protection: %o\n", file_stats.st_mode);
    printf("21. Number of hard links: %d\n", file_stats.st_nlink);
    printf("22. Owner's user ID: %d\n", file_stats.st_uid);
    printf("23. Owner's group ID: %d\n", file_stats.st_gid);
    printf("24. Owner's effective user ID: %lld\n", file_stats.st_rdev);
    printf("25. Size of %s file: %ld\n",filenamee,file_stats.st_size);
    printf("26. Block size of %s file: %ld\n",filenamee,file_stats.st_blksize);
    printf("27. Number of blocks allocated to %s file: %ld\n",filenamee,file_stats.st_blocks);

}
//function to append text to the file
void num28(char filenamee[])
{
  printf("28. New text is appended to %s file.\n",filenamee);
  const char *namee = filenamee;
  FILE *filepointer;
  filepointer = fopen(namee,"a");
  fprintf(filepointer," Last Step.");
  fclose(filepointer);
}
//function to show contents of file
void num29(char filenamee[])
{
     printf("29. Redisplaying the content of %s file.\n",filenamee);
    char str6[50]="cat ";
    strcat(str6,filenamee);
    const char *command6 = str6;
    system(command6);
}
//function to rename file
void num31(char filenamee[])
{
    int ret;
    char newname[]="p6in-2.txt";
    ret = rename(filenamee,newname);
    if(ret==0)
    {
        printf("31. Renamed the file to be p6in-2.txt.\n");
    }
    else
    {
        printf("Error: unable to rename the file");
    }
}
//function to show contents of file
void num32(char filenamee[])
{
     printf("32. The content of the new %s file: \n",filenamee);
    char str7[50]="cat ";
    strcat(str7,filenamee);
    const char *command7 = str7;
    system(command7);
}
//function to remove file from directory
void num34(char filenamee[])
{
    int status;
    status = remove(filenamee);
    if(status==0)
    {
        printf("34. Removed %s files from current Directory.\n", filenamee);
    }
    else
    {
        printf("34. Unable to delete the file\n");
        perror("Error");
    }

}
//function to display content of file
void num35(char filenamee[])
{
    printf("35. Displaying the content of %s file.\n", filenamee);
    char str8[50]="cat ";
    strcat(str8,filenamee);
    const char *command8 = str8;
    system(command8);
}
