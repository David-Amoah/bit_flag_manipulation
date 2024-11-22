//
// Created by David on 10/13/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags{
    int* data;
    int size;
    int capacity;
};

typedef struct bit_flags Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits) {
    if (number_of_bits <= 0) {
        return NULL;
    }

    Bit_flags* p_bits = (Bit_flags*)malloc(sizeof(Bit_flags));

    if (p_bits == NULL) {
        printf("Failed to allocate space");
        return NULL;
    }
    p_bits->size = number_of_bits;

    int bits_per_int = sizeof(int) * 8;
    int num_integers = (number_of_bits + bits_per_int - 1) / bits_per_int;

    p_bits->capacity = num_integers;


    p_bits->data = (int*)malloc(sizeof(int) * p_bits->capacity);
    if (p_bits->data == NULL) {
        free(p_bits);
        return NULL;
    }

    //sets bits to 0;
    for (int i = 0; i < num_integers; i++) {
        p_bits->data[i] = 0;
    }

    return p_bits;
}



Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

    if (pBit_flags == NULL || flag_position < 0) {
        return FAILURE;
    }

    int bits_per_int = sizeof(int) * 8;
    int needed_ints = (flag_position + bits_per_int) / bits_per_int;


    if (flag_position >= pBit_flags->capacity * bits_per_int) {

        int* temp = (int*)malloc(needed_ints * sizeof(int));

        if (temp == NULL) {
            printf("Failed to allocate memory");
            return FAILURE;
        }

        int old_num_ints = (pBit_flags->capacity * bits_per_int + bits_per_int - 1) / bits_per_int;
        for (int i = 0; i < old_num_ints; i++) {
            temp[i] = pBit_flags->data[i];
        }

        for (int i = old_num_ints; i < needed_ints; i++) {
            temp[i] = 0;
        }

        free(pBit_flags->data);
        pBit_flags->data = temp;
        pBit_flags->capacity = needed_ints;
    }


    int index = flag_position / bits_per_int;
    int bit_offset = flag_position % bits_per_int;


    pBit_flags->data[index] |= (1 << bit_offset);

    if (flag_position >= pBit_flags->size) {
        pBit_flags->size = flag_position + 1;
    }

    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

    if (flag_position < 0) {
        return FAILURE;
    }


    if (flag_position >= pBit_flags->capacity) {
        if (bit_flags_set_flag(hBit_flags, flag_position) == FAILURE) {
            return FAILURE;
        }
    }

    int index = flag_position / (int)(sizeof(int) * 8);
    int bit_offset = flag_position % (int)(sizeof(int) * 8);

    pBit_flags->data[index] &= ~(1 << bit_offset); // Set the bit to 0

    return SUCCESS;

}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position) {
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

    if (flag_position < 0 || flag_position >= pBit_flags->capacity) {
        return -1;
    }
    int index = flag_position % (int)(sizeof(int) * 8);

    return (pBit_flags->data[index] & (1 << (flag_position% (sizeof(int) * 8))))!= 0;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags) {
    Bit_flags* p_bits =(Bit_flags*)hBit_flags;
    return p_bits->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags) {
    Bit_flags* p_bits =(Bit_flags*)hBit_flags;
    return p_bits->capacity;
}

void bit_flags_destroy(BIT_FLAGS *phBit_flags) {
    if (phBit_flags != NULL ) {
        Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
        if (pBit_flags->data != NULL) {
            free(pBit_flags->data);
        }

        free(pBit_flags);
    }

    *phBit_flags = NULL;

}

void print_bits(BIT_FLAGS *pbits) {
    // Cast to your Bit_flags structure
    Bit_flags* pBit_flags = (Bit_flags*)*pbits;

    for (int i = pBit_flags->size -1; i >= 0; i--) {
        int index = i / (sizeof(int) * 8);  // Determine which integer holds this bit
        int bit_offset = i % (sizeof(int) * 8);  // Determine bit position within that integer

        // Check if the bit at position i is set or not
        int bit = (pBit_flags->data[index] & (1 << bit_offset)) ? 1 : 0;

        printf("%d", bit);


        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}
