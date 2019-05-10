#
# Makefile for the Linux filesystems.
#
# 14 Sep 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
# 

obj-y :=	open.o read_write.o file_table.o buffer.o  bio.o super.o \
		block_dev.o char_dev.o stat.o exec.o pipe.o namei.o fcntl.o \
		ioctl.o readdir.o select.o fifo.o locks.o dcache.o inode.o \
		attr.o bad_inode.o file.o filesystems.o namespace.o aio.o \
		seq_file.o xattr.o libfs.o fs-writeback.o mpage.o direct-io.o \
		ioprio.o pnode.o anon_inodes.o

obj-$(CONFIG_INOTIFY)		+= inotify.o
obj-$(CONFIG_EPOLL)			+= eventpoll.o
obj-$(CONFIG_COMPAT)		+= compat.o

nfsd-$(CONFIG_NFSD)			:= nfsctl.o
obj-y						+= $(nfsd-y) $(nfsd-m)

# binfmt_script is always there
obj-y						+= binfmt_script.o
obj-$(CONFIG_BINFMT_ELF)	+= binfmt_elf.o

obj-$(CONFIG_FS_MBCACHE)	+= mbcache.o
obj-$(CONFIG_FS_POSIX_ACL)	+= posix_acl.o xattr_acl.o

obj-$(CONFIG_DNOTIFY)		+= dnotify.o

obj-$(CONFIG_PROC_FS)		+= proc/
obj-y						+= partitions/
obj-$(CONFIG_SYSFS)			+= sysfs/
obj-y						+= devpts/

obj-$(CONFIG_PROFILING)		+= dcookies.o

# Do not add any filesystems before this line
obj-$(CONFIG_EXT3_FS)		+= ext3/
obj-$(CONFIG_JBD)			+= jbd/
obj-$(CONFIG_EXT2_FS)		+= ext2/
obj-$(CONFIG_RAMFS)			+= ramfs/
obj-$(CONFIG_HUGETLBFS)		+= hugetlbfs/
obj-$(CONFIG_ISO9660_FS)	+= isofs/
obj-$(CONFIG_NFS_FS)		+= nfs/
obj-$(CONFIG_EXPORTFS)		+= exportfs/
obj-$(CONFIG_NFSD)			+= nfsd/
obj-$(CONFIG_LOCKD)			+= lockd/
obj-$(CONFIG_NLS)			+= nls/
obj-$(CONFIG_AUTOFS_FS)		+= autofs/
obj-$(CONFIG_AUTOFS4_FS)	+= autofs4/
obj-$(CONFIG_RELAYFS_FS)	+= relayfs/
obj-$(CONFIG_DEBUG_FS)		+= debugfs/
