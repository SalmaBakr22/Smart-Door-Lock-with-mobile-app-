################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../BUZZER.c \
../DIO.c \
../EXT0.c \
../EXT1.c \
../GIE.c \
../HELP.c \
../USART.c 

OBJS += \
./App.o \
./BUZZER.o \
./DIO.o \
./EXT0.o \
./EXT1.o \
./GIE.o \
./HELP.o \
./USART.o 

C_DEPS += \
./App.d \
./BUZZER.d \
./DIO.d \
./EXT0.d \
./EXT1.d \
./GIE.d \
./HELP.d \
./USART.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


