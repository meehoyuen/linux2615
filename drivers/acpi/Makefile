#
# Makefile for the Linux ACPI interpreter
# 

export ACPI_CFLAGS

ACPI_CFLAGS	:= -Os

ifdef CONFIG_ACPI_DEBUG
  ACPI_CFLAGS	+= -DACPI_DEBUG_OUTPUT
endif

EXTRA_CFLAGS	+= $(ACPI_CFLAGS)

#
# ACPI Boot-Time Table Parsing
#
obj-y				+= tables.o
obj-$(CONFIG_X86)		+= blacklist.o

#
# ACPI Core Subsystem (Interpreter)
#
obj-y				+= osl.o utils.o \
				   dispatcher/ events/ executer/ hardware/ \
				   namespace/ parser/ resources/ tables/ \
				   utilities/

#
# ACPI Bus and Device Drivers
#
processor-objs	+= processor_core.o processor_throttling.o \
				processor_idle.o processor_thermal.o
ifdef CONFIG_CPU_FREQ
processor-objs	+= processor_perflib.o			
endif

obj-y				+= sleep/
obj-y				+= bus.o glue.o
obj-$(CONFIG_ACPI_SBS)		+= i2c_acpi_ec.o acpi_sbs.o
obj-$(CONFIG_ACPI_BUTTON)	+= button.o
obj-$(CONFIG_ACPI_EC)		+= ec.o
obj-$(CONFIG_ACPI_FAN)		+= fan.o
obj-$(CONFIG_ACPI_HOTKEY)	+= hotkey.o
obj-y				+= pci_root.o pci_link.o pci_irq.o pci_bind.o
obj-$(CONFIG_ACPI_POWER)	+= power.o
obj-$(CONFIG_ACPI_PROCESSOR)	+= processor.o
obj-$(CONFIG_ACPI_CONTAINER)	+= container.o
obj-$(CONFIG_ACPI_THERMAL)	+= thermal.o
obj-$(CONFIG_ACPI_SYSTEM)	+= system.o event.o
obj-$(CONFIG_ACPI_DEBUG)	+= debug.o
obj-$(CONFIG_ACPI_NUMA)		+= numa.o
obj-y				+= scan.o motherboard.o
obj-$(CONFIG_ACPI_HOTPLUG_MEMORY)	+= acpi_memhotplug.o
obj-$(CONFIG_ACPI_DEV)		+= dev_acpi.o
