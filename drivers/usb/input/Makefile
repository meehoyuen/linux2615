#
# Makefile for the USB input drivers
#

# Multipart objects.
usbhid-objs	:= hid-core.o

# Optional parts of multipart objects.
ifeq ($(CONFIG_USB_HIDINPUT),y)
	usbhid-objs	+= hid-input.o
endif

obj-$(CONFIG_USB_HID)		+= usbhid.o

ifeq ($(CONFIG_USB_DEBUG),y)
EXTRA_CFLAGS += -DDEBUG
endif
