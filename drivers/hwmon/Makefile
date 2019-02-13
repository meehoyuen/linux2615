#
# Makefile for sensor chip drivers.
#

obj-$(CONFIG_HWMON)		+= hwmon.o

ifeq ($(CONFIG_HWMON_DEBUG_CHIP),y)
EXTRA_CFLAGS += -DDEBUG
endif

