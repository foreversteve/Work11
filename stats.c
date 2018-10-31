#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>


int main(){
 
    struct stat fileStat;
    if(stat("in.txt",&fileStat) < 0)    
        return 1;
 
    printf("\nInformation for %s\n","in.txt");
    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n",fileStat.st_size);

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

    
    printf("\nUser ID: \t\t%s\n", getpwuid(fileStat.st_uid) -> pw_name);
    printf("Group ID: \t\t%s\n", getpwuid(fileStat.st_gid) -> pw_name);

    char size[100];
    char *format = "%ld B";
    long file_size = fileStat.st_size;
      
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ld KB";
    }
    
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ld MB";
    }
    
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ld GB";
    }
    
    sprintf(size, format, file_size);
    
    printf("\nFile Size (Reformatted): %s\n", size);
    //printf("\n%o\n",fileStat.st_mode & 0x1FF);

    printf("\n\n");

    return 0;
}
