#
# Makefile for the Linux kernel device drivers.
#
# 15 Sep 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
#

obj-$(CONFIG_PCI)		+= pci/
obj-y				+= video/
obj-$(CONFIG_ACPI)		+= acpi/
# PnP must come after ACPI since it will eventually need to check if acpi
# was used and do nothing if so

# char/ comes before serial/ etc so that the VT console is the boot-time
# default.
obj-y				+= char/

# we also need input/serio early so serio bus is initialized by the time
# serial drivers start registering their serio ports
obj-$(CONFIG_SERIO)		+= input/serio/
obj-y				+= serial/
obj-y				+= base/ block/ net/
obj-$(CONFIG_IDE)		+= ide/
obj-$(CONFIG_SCSI)		+= scsi/
obj-$(CONFIG_FUSION)		+= message/
obj-y				+= cdrom/
obj-$(CONFIG_USB)		+= usb/
obj-$(CONFIG_PCI)		+= usb/
obj-$(CONFIG_INPUT)		+= input/
obj-$(CONFIG_HWMON)		+= hwmon/
obj-$(CONFIG_MD)		+= md/
obj-$(CONFIG_CPU_FREQ)		+= cpufreq/
