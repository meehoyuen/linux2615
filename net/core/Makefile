#
# Makefile for the Linux networking core.
#

obj-y := sock.o request_sock.o skbuff.o iovec.o datagram.o stream.o scm.o \
	 gen_stats.o gen_estimator.o

obj-$(CONFIG_SYSCTL) += sysctl_net_core.o

obj-y		     += dev.o ethtool.o dev_mcast.o dst.o \
			neighbour.o rtnetlink.o utils.o link_watch.o filter.o

obj-$(CONFIG_SYSFS) += net-sysfs.o
