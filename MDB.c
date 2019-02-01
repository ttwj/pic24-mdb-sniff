#include "MDB.h"

uint8_t calc_checksum(uint8_t arr[], size_t arr_size) {
    uint8_t accum = 0;
    size_t i;
    for (i = 0; i < arr_size; i++) {
      accum += arr[i];
    }
    return accum;
}
