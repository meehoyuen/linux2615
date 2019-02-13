#
# Makefile for linux/drivers/scsi
#
# 30 May 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
#
# 20 Sep 2000, Torben Mathiasen <tmm@image.dk>
# Changed link order to reflect new scsi initialization.
#
# *!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!
# The link order must be, SCSI Core, SCSI HBA drivers, and
# lastly SCSI peripheral drivers (disk/tape/cdrom/etc.) to
# satisfy certain initialization assumptions in the SCSI layer.
# *!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!


CFLAGS_aha152x.o =   -DAHA152X_STAT -DAUTOCONF
CFLAGS_gdth.o    = # -DDEBUG_GDTH=2 -D__SERIAL__ -D__COM2__ -DGDTH_STATISTICS
CFLAGS_seagate.o =   -DARBITRATE -DPARITY -DSEAGATE_USE_ASM

obj-$(CONFIG_SCSI)		+= scsi_mod.o

obj-$(CONFIG_RAID_ATTRS)	+= raid_class.o

# --- NOTE ORDERING HERE ---
# For kernel non-modular link, transport attributes need to
# be initialised before drivers
# --------------------------
obj-$(CONFIG_SCSI_SPI_ATTRS)	+= scsi_transport_spi.o
obj-$(CONFIG_SCSI_SPI2_ATTRS)	+= scsi_transport_spi2.o

obj-$(CONFIG_SCSI_ATA_PIIX)	+= libata.o ata_piix.o

obj-$(CONFIG_BLK_DEV_SD)	+= sd_mod.o

scsi_mod-y			+= scsi.o hosts.o scsi_ioctl.o constants.o \
				   scsicam.o scsi_error.o scsi_lib.o \
				   scsi_scan.o scsi_sysfs.o \
				   scsi_devinfo.o
scsi_mod-$(CONFIG_SYSCTL)	+= scsi_sysctl.o
scsi_mod-$(CONFIG_SCSI_PROC_FS)	+= scsi_proc.o

sd_mod-objs	:= sd.o
sr_mod-objs	:= sr.o sr_ioctl.o sr_vendor.o
obj-$(CONFIG_SCSI_DEBUG)	+= scsi_debug.o
obj-$(CONFIG_SCSI_SATA_VIA)	+= libata.o sata_via.o
obj-$(CONFIG_SCSI_SATA_NV)	+= libata.o sata_nv.o
libata-y	:= libata-core.o libata-scsi.o
libata-$(CONFIG_SCSI_SATA_ACPI)	+= libata-acpi.o

# Files generated that shall be removed upon make clean
clean-files :=
