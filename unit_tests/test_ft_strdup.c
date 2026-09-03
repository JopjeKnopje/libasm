#include "libasm.h"
#include "unity.h"
#include <malloc.h>
#include <stdint.h>
#include <string.h>

void print_info()
{
    struct mallinfo2 mi = mallinfo2();

    printf("Total non-mmapped bytes (arena):       %lu\n", mi.arena);
    printf("# of free chunks (ordblks):            %lu\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %lu\n", mi.smblks);
    printf("# of mapped regions (hblks):           %lu\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %lu\n", mi.hblkhd);
    printf("Max. total allocated space (usmblks):  %lu\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %lu\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %lu\n", mi.uordblks);
    printf("Total free space (fordblks):           %lu\n", mi.fordblks);
    printf("Topmost releasable block (keepcost):   %lu\n", mi.keepcost);
}

// TODO: Figure out how to monitor malloced size
void test_malloc_info()
{
    char *test = strdup("test123");
    char *s = ft_strdup(test);
    int64_t x = (int64_t)s;

    printf("%ld\n", x);

    // void *x = (int32_t *) s;
    //
    // printf("%u\n", (int32_t) x);

    // s[2100] = 't';
    (void)s;
}
