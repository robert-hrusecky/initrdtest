#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* Import user configuration: */
#include <uk/config.h>
#include <uk/plat/memory.h>
#include <uk/initramfs.h>
#include <uk/hexdump.h>
#include <uk/alloc.h>
#include <dirent.h>
int main()
{
    //printf("Hello world!\n");

    struct ukplat_memregion_desc desc;
    ukplat_memregion_get(0, &desc);
    printf("heap_size: %ld\n", desc.len);

    ukplat_memregion_get(1, &desc);
    printf("initrd_size: %ld\n", desc.len);
    //uk_hexdumpCd(desc.base, desc.len);

    initramfs_init(&desc);
    //uk_hexdumpCd(desc.base, 110);
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
    //buf[len] = '\0';
    if (read(fd, &buf[0], 100) < 0) {
        return -2;
    }
    printf("The message in testile is: %s", buf);
    return 0;
}
