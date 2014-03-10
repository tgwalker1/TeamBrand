################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(SOURCE)/Application.c" \
"$(SOURCE)/Event.c" \
"$(SOURCE)/LED.c" \
"$(SOURCE)/Platform.c" \

C_SRCS += \
$(SOURCE)/Application.c \
$(SOURCE)/Event.c \
$(SOURCE)/LED.c \
$(SOURCE)/Platform.c \

OBJS += \
./Sources/source/Application.o \
./Sources/source/Event.o \
./Sources/source/LED.o \
./Sources/source/Platform.o \

C_DEPS += \
./Sources/source/Application.d \
./Sources/source/Event.d \
./Sources/source/LED.d \
./Sources/source/Platform.d \

OBJS_QUOTED += \
"./Sources/source/Application.o" \
"./Sources/source/Event.o" \
"./Sources/source/LED.o" \
"./Sources/source/Platform.o" \

C_DEPS_QUOTED += \
"./Sources/source/Application.d" \
"./Sources/source/Event.d" \
"./Sources/source/LED.d" \
"./Sources/source/Platform.d" \

OBJS_OS_FORMAT += \
./Sources/source/Application.o \
./Sources/source/Event.o \
./Sources/source/LED.o \
./Sources/source/Platform.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/source/Application.o: $(SOURCE)/Application.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/source/Application.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/source/Application.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/source/Event.o: $(SOURCE)/Event.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/source/Event.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/source/Event.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/source/LED.o: $(SOURCE)/LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/source/LED.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/source/LED.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/source/Platform.o: $(SOURCE)/Platform.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/source/Platform.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/source/Platform.o"
	@echo 'Finished building: $<'
	@echo ' '


