//
// Created by David on 10/13/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
    if (number_of_bits <= 0) {
        return NULL;
    }

    int num_bytes = (number_of_bits + 7) / 8;

    BIT_FLAGS* hBit_Flags;

    hBit_Flags = (BIT_FLAGS*)malloc(num_bytes);

    if (hBit_Flags == NULL) {
        printf("Failed to allocate space");
        exit(1);
    }

    // initialize all bits to zero
    for (int i = 0; i < number_of_bits; i++) {
        ((int*)hBit_Flags)[i] = 0;
    }

    return hBit_Flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {
    return FAILURE;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
    return FAILURE;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
    return 0;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags) {
    return 0;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
    return 0;
}

void bit_flags_destroy(BIT_FLAGS *phBit_flags) {

}
