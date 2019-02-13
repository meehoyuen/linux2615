#
# Makefile for the kernel ata, atapi, and ide block device drivers.
#
# 12 September 2000, Bartlomiej Zolnierkiewicz <bkz@linux-ide.org>
# Rewritten to use lists instead of if-statements.
#
# Note : at this point, these files are compiled on all systems.
# In the future, some of these should be built conditionally.
#
# First come modules that register themselves with the core

EXTRA_CFLAGS						+= -Idrivers/ide

obj-$(CONFIG_BLK_DEV_IDE)			+= pci/

ide-core-y += ide.o ide-io.o ide-iops.o ide-lib.o ide-probe.o ide-taskfile.o

# Core IDE code - must come before legacy
ide-core-$(CONFIG_BLK_DEV_IDEPCI)	+= setup-pci.o
ide-core-$(CONFIG_BLK_DEV_IDEDMA)	+= ide-dma.o
ide-core-$(CONFIG_PROC_FS)			+= ide-proc.o

obj-$(CONFIG_BLK_DEV_IDE)			+= ide-core.o
obj-$(CONFIG_IDE_GENERIC)			+= ide-generic.o
obj-$(CONFIG_BLK_DEV_IDEPNP)		+= ide-pnp.o

obj-$(CONFIG_BLK_DEV_IDEDISK)		+= ide-disk.o
obj-$(CONFIG_BLK_DEV_IDECD)			+= ide-cd.o
obj-$(CONFIG_BLK_DEV_IDETAPE)		+= ide-tape.o
obj-$(CONFIG_BLK_DEV_IDEFLOPPY)		+= ide-floppy.o

