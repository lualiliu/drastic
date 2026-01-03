// spi.h - SPI外设
#ifndef SPI_H
#define SPI_H

#include "drastic_val.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_spi_peripherals(long param_1);
void initialize_spi_peripherals(long param_1, long param_2);

#ifdef __cplusplus
}
#endif

#endif // SPI_H
