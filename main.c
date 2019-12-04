#include <stdio.h>
#include <stdlib.h>

/* Import user configuration: */
#include <uk/config.h>
#include <uk/plat/memory.h>
#include <uk/initramfs.h>
#include <uk/hexdump.h>
#include <uk/alloc.h>
#include <uk/json_frontend.h>
#include <string.h>
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



    const char* test = "{ \"message\" : \"Hello, world!\"  }";
    struct json_value* json = parse_json(test, strlen(test));
    printf("json : %p\n", json);

    return 0;
}
