#
# Makefile for X86_64 specific PCI routines
#
# Reuse the i386 PCI subsystem
#
obj-y		:= i386.o
obj-$(CONFIG_PCI_DIRECT)+= direct.o
obj-y		+= fixup.o
obj-$(CONFIG_ACPI)	+= acpi.o
obj-y			+= legacy.o irq.o common.o
# mmconfig has a 64bit special
obj-$(CONFIG_PCI_MMCONFIG) += mmconfig.o direct.o

obj-$(CONFIG_NUMA)	+= k8-bus.o
