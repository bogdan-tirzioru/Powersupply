################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display_2raw.c \
../Src/freertos.c \
../Src/main.c \
../Src/processing.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_hal_timebase_TIM.c \
../Src/stm32f7xx_it.c \
../Src/string_proc.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/Display_2raw.o \
./Src/freertos.o \
./Src/main.o \
./Src/processing.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_hal_timebase_TIM.o \
./Src/stm32f7xx_it.o \
./Src/string_proc.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/Display_2raw.d \
./Src/freertos.d \
./Src/main.d \
./Src/processing.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_hal_timebase_TIM.d \
./Src/stm32f7xx_it.d \
./Src/string_proc.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F732xx -I"D:/gitRepos/Powersupply/firmware/powersupply/Inc" -I"D:/gitRepos/Powersupply/firmware/powersupply/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/gitRepos/Powersupply/firmware/powersupply/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/gitRepos/Powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"D:/gitRepos/Powersupply/firmware/powersupply/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"D:/gitRepos/Powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/gitRepos/Powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/gitRepos/Powersupply/firmware/powersupply/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


