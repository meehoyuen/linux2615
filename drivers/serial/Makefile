#
# Makefile for the kernel serial device drivers.
#
#  $Id: Makefile,v 1.8 2002/07/21 21:32:30 rmk Exp $
#

serial-8250-y :=
serial-8250-$(CONFIG_PCI) += 8250_pci.o
obj-$(CONFIG_SERIAL_CORE) += serial_core.o
obj-$(CONFIG_SERIAL_8250) += 8250.o $(serial-8250-y)
obj-$(CONFIG_SERIAL_8250_CONSOLE) += 8250_early.o
