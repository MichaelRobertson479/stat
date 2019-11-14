#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {

    struct stat info;

    int i = stat("file.txt",&info);

    if (i == -1) {
        printf("stat failed\n");
        printf("%s\n",strerror(errno));
    }

    printf("file size: %ld\n",info.st_size);
    printf("mode: %o\n",info.st_mode);
    printf("time of last access: %s\n",ctime(&info.st_atime));

    printf("file size:\n");
    printf("%ld B\n",info.st_size);
    printf("%ld KB\n",info.st_size / 1000);
    printf("%ld MB\n",info.st_size / 1000000);
    printf("%ld GB\n",info.st_size / 1000000000);

    printf("ls -l format:\n");

    int perm = info.st_mode;
    char str[9] = {'r','w','x','r','w','x','r','w','x'};

    for (i = 0; i < 9; i++) {

        if (perm % 2 == 0) {
            str[8-i] = '-';
        }

        perm = perm / 2;
    }

    for (i = 0; i < 9; i++) {

        printf("%c",str[i]);
    }

    printf(" 1 %s %s",info.st_uid,info.st_gid);

    return 0;
}