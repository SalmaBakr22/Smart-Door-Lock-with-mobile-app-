
#ifndef EXT1_PRIV_H
#define EXT1_PRIV_H


#define MCUCR  *((volatile uint8 *) 0x55)
#define GICR   *((volatile uint8 *) 0x5B)
#define GIFR   *((volatile uint8 *) 0x5A)

#endif