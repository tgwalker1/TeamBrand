################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/LED1.c" \
"../Generated_Code/LED2.c" \
"../Generated_Code/LED3.c" \
"../Generated_Code/LED4.c" \
"../Generated_Code/LED5.c" \
"../Generated_Code/LEDpin1.c" \
"../Generated_Code/LEDpin2.c" \
"../Generated_Code/LEDpin3.c" \
"../Generated_Code/LEDpin4.c" \
"../Generated_Code/LEDpin5.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/LED1.c \
../Generated_Code/LED2.c \
../Generated_Code/LED3.c \
../Generated_Code/LED4.c \
../Generated_Code/LED5.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/LEDpin2.c \
../Generated_Code/LEDpin3.c \
../Generated_Code/LEDpin4.c \
../Generated_Code/LEDpin5.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/LED1_c.obj \
./Generated_Code/LED2_c.obj \
./Generated_Code/LED3_c.obj \
./Generated_Code/LED4_c.obj \
./Generated_Code/LED5_c.obj \
./Generated_Code/LEDpin1_c.obj \
./Generated_Code/LEDpin2_c.obj \
./Generated_Code/LEDpin3_c.obj \
./Generated_Code/LEDpin4_c.obj \
./Generated_Code/LEDpin5_c.obj \
./Generated_Code/Vectors_c.obj \

OBJS_QUOTED += \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/LED1_c.obj" \
"./Generated_Code/LED2_c.obj" \
"./Generated_Code/LED3_c.obj" \
"./Generated_Code/LED4_c.obj" \
"./Generated_Code/LED5_c.obj" \
"./Generated_Code/LEDpin1_c.obj" \
"./Generated_Code/LEDpin2_c.obj" \
"./Generated_Code/LEDpin3_c.obj" \
"./Generated_Code/LEDpin4_c.obj" \
"./Generated_Code/LEDpin5_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS += \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/LED1_c.d \
./Generated_Code/LED2_c.d \
./Generated_Code/LED3_c.d \
./Generated_Code/LED4_c.d \
./Generated_Code/LED5_c.d \
./Generated_Code/LEDpin1_c.d \
./Generated_Code/LEDpin2_c.d \
./Generated_Code/LEDpin3_c.d \
./Generated_Code/LEDpin4_c.d \
./Generated_Code/LEDpin5_c.d \
./Generated_Code/Vectors_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/LED1_c.d" \
"./Generated_Code/LED2_c.d" \
"./Generated_Code/LED3_c.d" \
"./Generated_Code/LED4_c.d" \
"./Generated_Code/LED5_c.d" \
"./Generated_Code/LEDpin1_c.d" \
"./Generated_Code/LEDpin2_c.d" \
"./Generated_Code/LEDpin3_c.d" \
"./Generated_Code/LEDpin4_c.d" \
"./Generated_Code/LEDpin5_c.d" \
"./Generated_Code/Vectors_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/LED1_c.obj \
./Generated_Code/LED2_c.obj \
./Generated_Code/LED3_c.obj \
./Generated_Code/LED4_c.obj \
./Generated_Code/LED5_c.obj \
./Generated_Code/LEDpin1_c.obj \
./Generated_Code/LEDpin2_c.obj \
./Generated_Code/LEDpin3_c.obj \
./Generated_Code/LEDpin4_c.obj \
./Generated_Code/LEDpin5_c.obj \
./Generated_Code/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cpu.args" -ObjN="Generated_Code/Cpu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/IO_Map.args" -ObjN="Generated_Code/IO_Map_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED1_c.obj: ../Generated_Code/LED1.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED1.args" -ObjN="Generated_Code/LED1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED2_c.obj: ../Generated_Code/LED2.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED2.args" -ObjN="Generated_Code/LED2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED3_c.obj: ../Generated_Code/LED3.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED3.args" -ObjN="Generated_Code/LED3_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED4_c.obj: ../Generated_Code/LED4.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED4.args" -ObjN="Generated_Code/LED4_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED5_c.obj: ../Generated_Code/LED5.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LED5.args" -ObjN="Generated_Code/LED5_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin1_c.obj: ../Generated_Code/LEDpin1.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LEDpin1.args" -ObjN="Generated_Code/LEDpin1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin2_c.obj: ../Generated_Code/LEDpin2.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LEDpin2.args" -ObjN="Generated_Code/LEDpin2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin3_c.obj: ../Generated_Code/LEDpin3.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LEDpin3.args" -ObjN="Generated_Code/LEDpin3_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin4_c.obj: ../Generated_Code/LEDpin4.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LEDpin4.args" -ObjN="Generated_Code/LEDpin4_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LEDpin5_c.obj: ../Generated_Code/LEDpin5.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/LEDpin5.args" -ObjN="Generated_Code/LEDpin5_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Vectors.args" -ObjN="Generated_Code/Vectors_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


