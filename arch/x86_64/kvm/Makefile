#
# Makefile for Kernel-based Virtual Machine module
#

common-objs = $(addprefix ../../../virt/, kvm_main.o ioapic.o \
                coalesced_mmio.o irq_comm.o)
ifeq ($(CONFIG_IOMMU_API),y)
common-objs += $(addprefix ../../../virt/, iommu.o)
endif

EXTRA_CFLAGS += -Ivirt -Iarch/x86_64/kvm

kvm-objs := $(common-objs) x86.o mmu.o x86_emulate.o i8259.o irq.o lapic.o i8254.o
obj-m += kvm.o
kvm-intel-objs = vmx.o
obj-m += kvm-intel.o
