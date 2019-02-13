#
# Makefile for the linux networking.
#
# 2 Sep 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
#

obj-y	:= nonet.o

obj-$(CONFIG_NET)		:= socket.o core/

tmp-$(CONFIG_COMPAT) 		:= compat.o
obj-$(CONFIG_NET)		+= $(tmp-y)

obj-$(CONFIG_NET)		+= ethernet/ 802/ sched/ netlink/
obj-$(CONFIG_INET)		+= ipv4/
obj-$(CONFIG_UNIX)		+= unix/
ifneq ($(CONFIG_IPV6),)
obj-y				+= ipv6/
endif
obj-$(CONFIG_PACKET)		+= packet/
obj-$(CONFIG_NET_SCHED)		+= sched/
obj-$(CONFIG_SUNRPC)		+= sunrpc/

ifeq ($(CONFIG_NET),y)
obj-$(CONFIG_SYSCTL)		+= sysctl_net.o
endif
