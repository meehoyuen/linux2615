#
# Makefile for the kernel character device drivers.
#

#
# This file contains the font map for the default (hardware) font
#
FONTMAPFILE = cp437.uni

obj-y	 += mem.o random.o tty_io.o n_tty.o tty_ioctl.o

obj-$(CONFIG_LEGACY_PTYS)	+= pty.o
obj-$(CONFIG_UNIX98_PTYS)	+= pty.o
obj-y				+= misc.o
obj-$(CONFIG_VT)		+= vt_ioctl.o vc_screen.o consolemap.o \
				   consolemap_deftbl.o selection.o keyboard.o
obj-$(CONFIG_HW_CONSOLE)	+= vt.o defkeymap.o
obj-$(CONFIG_MAGIC_SYSRQ)	+= sysrq.o
obj-$(CONFIG_RAW_DRIVER)	+= raw.o
obj-$(CONFIG_RTC) += rtc.o
obj-$(CONFIG_HPET) += hpet.o
obj-$(CONFIG_HW_RANDOM) += hw_random.o

obj-$(CONFIG_WATCHDOG)	+= watchdog/
obj-$(CONFIG_AGP) += agp/

obj-$(CONFIG_HANGCHECK_TIMER) += hangcheck-timer.o
# Files generated that shall be removed upon make clean
clean-files := consolemap_deftbl.c defkeymap.c qtronixmap.c

quiet_cmd_conmk = CONMK   $@
      cmd_conmk = scripts/conmakehash $< > $@

$(obj)/consolemap_deftbl.c: $(src)/$(FONTMAPFILE)
	$(call cmd,conmk)

$(obj)/defkeymap.o:  $(obj)/defkeymap.c

$(obj)/qtronixmap.o: $(obj)/qtronixmap.c

# Uncomment if you're changing the keymap and have an appropriate
# loadkeys version for the map. By default, we'll use the shipped
# versions.
# GENERATE_KEYMAP := 1

ifdef GENERATE_KEYMAP

$(obj)/defkeymap.c $(obj)/qtronixmap.c: $(obj)/%.c: $(src)/%.map
	loadkeys --mktable $< > $@.tmp
	sed -e 's/^static *//' $@.tmp > $@
	rm $@.tmp

endif
