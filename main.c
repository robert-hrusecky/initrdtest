#include <stdio.h>
#include <stdlib.h>

/* Import user configuration: */
#include <uk/config.h>
#include <uk/plat/memory.h>

#include <uk/hexdump.h>

int main()
{

    printf("Hello world!\n");

    struct ukplat_memregion_desc desc;
    ukplat_memregion_get(0, &desc);
    printf("heap_size: %ld\n", desc.len);

    ukplat_memregion_get(1, &desc);
    printf("initrd_size: %ld\n", desc.len);
    uk_hexdumpCd(desc.base, 27);
    return 0;
}
