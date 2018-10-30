#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>


int main(){
 
    struct stat fileStat;
    if(stat("in.txt",&fileStat) < 0)    
        return 1;
 
    printf("\nInformation for %s\n","in.txt");
    printf("---------------------------\n");
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);

    printf("File Access Time: \t%s",ctime(&fileStat.st_atime));

    printf("File Permissions: \t");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");


    //printf("\n%o\n",fileStat.st_mode & 0x1FF);

    printf("\n\n");

    return 0;
}