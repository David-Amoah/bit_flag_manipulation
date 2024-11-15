#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"




int main (int argc, char **argv) {

    BIT_FLAGS* new_bits;

    new_bits = bit_flags_init_number_of_bits(10);

    bit_flags_set_flag(new_bits,2);
    //bit_flags_unset_flag(new_bits,2);

    print_bits(&new_bits);

    printf("%d\n",bit_flags_get_size(new_bits));

    bit_flags_destroy(&new_bits);








    return 0;
}
