#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"


int main() {

    BIT_FLAGS new_bits;

    new_bits = bit_flags_init_number_of_bits(10);

    int num_bytes = (10+7) / 8;

    printf("%d\n", num_bytes);


    printf("Hello, World!\n");
    return 0;
}
