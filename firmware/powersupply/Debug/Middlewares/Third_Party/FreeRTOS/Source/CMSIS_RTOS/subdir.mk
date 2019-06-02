################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F732xx -I"D:/myprojects/2018/powersupply/firmware/powersupply/Inc" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/myprojects/2018/powersupply/firmware/powersupply/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


