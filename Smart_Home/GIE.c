#include "STD_Types.h"
#include "BIT_Math.h"

#include  "GIE.h"

#define SREG *((volatile uint8 *) 0x5F)

void GIE_VIDEnable(void)
{
	SET_BIT(SREG , 7);
}

void GIE_VIDDisable(void)
{
	CLR_BIT(SREG , 7);
}
