################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA/utils/memory_manager/buffer_pool_allocator.c \
D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA/utils/memory_manager/rail_integration.c 

OBJS += \
./buffer-pool-memory-manager/buffer_pool_allocator.o \
./buffer-pool-memory-manager/rail_integration.o 

C_DEPS += \
./buffer-pool-memory-manager/buffer_pool_allocator.d \
./buffer-pool-memory-manager/rail_integration.d 


# Each subdirectory must supply rules for building sources it contributes
buffer-pool-memory-manager/buffer_pool_allocator.o: D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA/utils/memory_manager/buffer_pool_allocator.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --no_wrap_diagnostics -IC:/Users/Szarlej/SimplicityStudio/v3_workspace/Test -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/rtcdrv/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/ustimer/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/gpiointerrupt/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/common/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emlib/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/common/bsp" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/common/drivers" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//hal/efr32" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/common" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/graphics" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib/glib" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib/dmd" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/memory_manager" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/response_print" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/command_interpreter" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/chip/efr32/rf/common/cortex" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/EFR32MG1_BRD4151A/config" -I"C:\Users\Szarlej\SimplicityStudio\v3_workspace\Test\lcd-graphics_inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/CMSIS/Include" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/Device/SiliconLabs/EFR32MG1P/Include" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/chip/efr32" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --dlib_config "D:\Soft\IAR Systems\Embedded Workbench 7.3\arm\inc\c\DLib_Config_Normal.h" --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DEFR32MG1P232F256GM48=1' '-DBOARD_BRD4151A=1' '-DCONFIGURATION_HEADER="rail-configuration.h"' '-DRETARGET_VCOM=1' --diag_suppress Pa050 --dependencies=m "$(basename $(notdir $<)).d"
	@echo 'Finished building: $<'
	@echo ' '

buffer-pool-memory-manager/rail_integration.o: D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA/utils/memory_manager/rail_integration.c
	@echo 'Building file: $<'
	@echo 'Invoking: IAR C/C++ Compiler for ARM'
	iccarm "$<" -o "$@" --no_wrap_diagnostics -IC:/Users/Szarlej/SimplicityStudio/v3_workspace/Test -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/rtcdrv/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/ustimer/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/gpiointerrupt/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emdrv/common/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/emlib/inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/common/bsp" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/common/drivers" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//hal/efr32" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/common" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/graphics" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib/glib" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/reptile/glib/dmd" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/memory_manager" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/response_print" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//utils/command_interpreter" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/chip/efr32/rf/common/cortex" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/kits/EFR32MG1_BRD4151A/config" -I"C:\Users\Szarlej\SimplicityStudio\v3_workspace\Test\lcd-graphics_inc" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/CMSIS/Include" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/Device/SiliconLabs/EFR32MG1P/Include" -I"D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//submodules/rail_lib/chip/efr32" -e --cpu Cortex-M4F --fpu VFPv4_sp --debug --dlib_config "D:\Soft\IAR Systems\Embedded Workbench 7.3\arm\inc\c\DLib_Config_Normal.h" --endian little --cpu_mode thumb -On --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling '-DEFR32MG1P232F256GM48=1' '-DBOARD_BRD4151A=1' '-DCONFIGURATION_HEADER="rail-configuration.h"' '-DRETARGET_VCOM=1' --diag_suppress Pa050 --dependencies=m "$(basename $(notdir $<)).d"
	@echo 'Finished building: $<'
	@echo ' '


