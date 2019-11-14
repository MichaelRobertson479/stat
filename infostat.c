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
        printf("%s\n",strerro(errno));
    }

    printf("file size: %ld\n",info.st_size);
    printf("mode: %o\n",info.st_mode);
    printf("time of last access: %s\n",ctime(info.st_atime));

    return 0;
}