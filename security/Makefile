#
# Makefile for the kernel security code
#

# if we don't select a security model, use the default capabilities
ifneq ($(CONFIG_SECURITY),y)
obj-y		+= commoncap.o
endif
