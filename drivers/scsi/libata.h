/*
 *  libata.h - helper library for ATA
 *
 *  Copyright 2003-2004 Red Hat, Inc.  All rights reserved.
 *  Copyright 2003-2004 Jeff Garzik
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *
 *  libata documentation is available via 'make {ps|pdf}docs',
 *  as Documentation/DocBook/libata.*
 *
 */

#ifndef __LIBATA_H__
#define __LIBATA_H__

#define DRV_NAME	"libata"
#define DRV_VERSION	"1.20"	/* must be exactly four chars */

struct ata_scsi_args {
	u16			*id;
	struct scsi_cmnd	*cmd;
	void			(*done)(struct scsi_cmnd *);
};

/* libata-core.c */
extern int atapi_enabled;
extern int ata_qc_complete_noop(struct ata_queued_cmd *qc);
extern int noacpi;
extern int libata_printk;

extern int ata_bus_probe(struct ata_port *ap);
extern struct ata_queued_cmd *ata_qc_new_init(struct ata_port *ap,
				      struct ata_device *dev);
extern void ata_rwcmd_protocol(struct ata_queued_cmd *qc);
extern void ata_qc_free(struct ata_queued_cmd *qc);
extern int ata_qc_issue(struct ata_queued_cmd *qc);
extern int ata_check_atapi_dma(struct ata_queued_cmd *qc);
extern void ata_check_kill_qc(struct ata_port *ap);
extern void ata_dev_select(struct ata_port *ap, unsigned int device,
                           unsigned int wait, unsigned int can_sleep);
extern void swap_buf_le16(u16 *buf, unsigned int buf_words);
extern int ata_task_ioctl(struct scsi_device *scsidev, void __user *arg);
extern int ata_cmd_ioctl(struct scsi_device *scsidev, void __user *arg);
extern unsigned int ata_exec_internal(struct ata_port *ap,
				struct ata_device *dev,
				struct ata_taskfile *tf,
				int dma_dir, void *buf, unsigned int buflen);


/* libata-acpi.c */
#ifdef CONFIG_SCSI_SATA_ACPI
extern int ata_acpi_push_id(struct ata_port *ap, unsigned int ix);
extern int do_drive_get_GTF(struct ata_port *ap, int ix,
			unsigned int *gtf_length, unsigned long *gtf_address,
			unsigned long *obj_loc);
extern int do_drive_set_taskfiles(struct ata_port *ap, struct ata_device *atadev,
			unsigned int gtf_length, unsigned long gtf_address);
extern int ata_acpi_exec_tfs(struct ata_port *ap);
extern void ata_acpi_get_timing(struct ata_port *ap);
extern void ata_acpi_push_timing(struct ata_port *ap);
extern void ata_acpi_bus_register(void);
#else
static inline int ata_acpi_push_id(struct ata_port *ap, unsigned int ix)
{
	return 0;
}
static inline int do_drive_get_GTF(struct ata_port *ap, int ix,
			unsigned int *gtf_length, unsigned long *gtf_address,
			unsigned long *obj_loc)
{
	return 0;
}
static inline int do_drive_set_taskfiles(struct ata_port *ap,
			struct ata_device *atadev,
			unsigned int gtf_length, unsigned long gtf_address)
{
	return 0;
}
static inline int ata_acpi_exec_tfs(struct ata_port *ap)
{
	return 0;
}
static void ata_acpi_get_timing(struct ata_port *ap)
{
}
static void ata_acpi_push_timing(struct ata_port *ap)
{
}
static void ata_acpi_bus_register()
{
}
#endif


/* libata-scsi.c */
extern void ata_scsi_scan_host(struct ata_port *ap);
extern int ata_scsi_error(struct Scsi_Host *host);
extern unsigned int ata_scsiop_inq_std(struct ata_scsi_args *args, u8 *rbuf,
			       unsigned int buflen);

extern unsigned int ata_scsiop_inq_00(struct ata_scsi_args *args, u8 *rbuf,
			      unsigned int buflen);

extern unsigned int ata_scsiop_inq_80(struct ata_scsi_args *args, u8 *rbuf,
			      unsigned int buflen);
extern unsigned int ata_scsiop_inq_83(struct ata_scsi_args *args, u8 *rbuf,
			      unsigned int buflen);
extern unsigned int ata_scsiop_noop(struct ata_scsi_args *args, u8 *rbuf,
			    unsigned int buflen);
extern unsigned int ata_scsiop_sync_cache(struct ata_scsi_args *args, u8 *rbuf,
				  unsigned int buflen);
extern unsigned int ata_scsiop_mode_sense(struct ata_scsi_args *args, u8 *rbuf,
				  unsigned int buflen);
extern unsigned int ata_scsiop_read_cap(struct ata_scsi_args *args, u8 *rbuf,
			        unsigned int buflen);
extern unsigned int ata_scsiop_report_luns(struct ata_scsi_args *args, u8 *rbuf,
				   unsigned int buflen);
extern void ata_scsi_badcmd(struct scsi_cmnd *cmd,
			    void (*done)(struct scsi_cmnd *),
			    u8 asc, u8 ascq);
extern void ata_scsi_set_sense(struct scsi_cmnd *cmd,
			       u8 sk, u8 asc, u8 ascq);
extern void ata_scsi_rbuf_fill(struct ata_scsi_args *args,
                        unsigned int (*actor) (struct ata_scsi_args *args,
                                           u8 *rbuf, unsigned int buflen));
extern void ata_scsi_prepare_qc_abort(struct ata_queued_cmd *qc);
extern void ata_scsi_handle_plug(struct ata_port *ap);
extern void ata_scsi_handle_unplug(struct ata_port *ap);

#endif /* __LIBATA_H__ */
