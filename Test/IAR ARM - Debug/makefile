################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include response-printf/subdir.mk
-include lcd-graphics/subdir.mk
-include hal-efr32/subdir.mk
-include command-interpreter/subdir.mk
-include buffer-pool-memory-manager/subdir.mk
-include CMSIS/efr32mg1p/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S79_DEPS)),)
-include $(S79_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(MSA_UPPER_DEPS)),)
-include $(MSA_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(MSA_DEPS)),)
-include $(MSA_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S79_UPPER_DEPS)),)
-include $(S79_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Test.out

# Tool invocations
Test.out: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: IAR Linker for ARM'
	ilinkarm $(OBJS) $(USER_OBJS) -o "Test.out" --config "D:/Soft/IARSYS~1/EMBEDD~1.3/arm/config/generic_cortex.icf" --no_wrap_diagnostics "D:/Projects/Gecko/SiliconLabs/SiliconLabsRAIL/1.2.0.0-GA//autogen/librail_release/librail_efr32_iar_release.a" --redirect _Printf=_PrintfFull --redirect _Scanf=_ScanfFull  
	ielftool --ihex --verbose "Test.out" "Test.hex"  
	ielftool --ihex "Test.out" "Test.hex" 
	ielftool --bin "Test.out" "Test.bin" 
	ielftool --srec "Test.out" "Test.s37"
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(S79_DEPS)$(S_DEPS)$(CXX_DEPS)$(MSA_UPPER_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(CC_DEPS)$(MSA_DEPS)$(ASM_UPPER_DEPS)$(S79_UPPER_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS) Test.out
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
