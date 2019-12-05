#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* Import user configuration: */
#include <uk/config.h>
#include <uk/plat/memory.h>
#include <uk/hexdump.h>
#include <uk/alloc.h>
#include <dirent.h>
int main()
{
    DIR *dr = opendir("/");
    struct dirent *de;
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }
    int fd = open("/testfile", O_RDWR);
    if (fd < 0) {
        return -1;
    }
    char buf[1024];
    if (read(fd, &buf[0], 100) < 0) {
        return -2;
    }
    buf[100] = '\0';
    printf("The message in testile is: %s", buf);
    return 0;
}
