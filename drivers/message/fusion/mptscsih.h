/*
 *  linux/drivers/message/fusion/mptscsih.h
 *      High performance SCSI / Fibre Channel SCSI Host device driver.
 *      For use with PCI chip/adapter(s):
 *          LSIFC9xx/LSI409xx Fibre Channel
 *      running LSI Logic Fusion MPT (Message Passing Technology) firmware.
 *
 *  Copyright (c) 1999-2005 LSI Logic Corporation
 *  (mailto:mpt_linux_developer@lsil.com)
 *
 */

#ifndef SCSIHOST_H_INCLUDED
#define SCSIHOST_H_INCLUDED

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*
 *	SCSI Public stuff...
 */

#define MPT_SCSI_CMD_PER_DEV_HIGH	64
#define MPT_SCSI_CMD_PER_DEV_LOW	32

#define MPT_SCSI_CMD_PER_LUN		7

#define MPT_SCSI_MAX_SECTORS    8192

/* To disable domain validation, uncomment the
 * following line. No effect for FC devices.
 * For SCSI devices, driver will negotiate to
 * NVRAM settings (if available) or to maximum adapter
 * capabilities.
 */

#define MPTSCSIH_ENABLE_DOMAIN_VALIDATION


/* SCSI driver setup structure. Settings can be overridden
 * by command line options.
 */
#define MPTSCSIH_DOMAIN_VALIDATION      1
#define MPTSCSIH_MAX_WIDTH              1
#define MPTSCSIH_MIN_SYNC               0x08
#define MPTSCSIH_SAF_TE                 0
#define MPTSCSIH_PT_CLEAR               0


#endif

extern void mptscsih_remove(struct pci_dev *);
extern void mptscsih_shutdown(struct pci_dev *);
#ifdef CONFIG_PM
extern int mptscsih_suspend(struct pci_dev *pdev, pm_message_t state);
extern int mptscsih_resume(struct pci_dev *pdev);
#endif
extern int mptscsih_proc_info(struct Scsi_Host *host, char *buffer, char **start, off_t offset, int length, int func);
extern const char * mptscsih_info(struct Scsi_Host *SChost);
extern int mptscsih_qcmd(struct scsi_cmnd *SCpnt, void (*done)(struct scsi_cmnd *));
extern int mptscsih_slave_alloc(struct scsi_device *device);
extern void mptscsih_slave_destroy(struct scsi_device *device);
extern int mptscsih_slave_configure(struct scsi_device *device);
extern int mptscsih_abort(struct scsi_cmnd * SCpnt);
extern int mptscsih_dev_reset(struct scsi_cmnd * SCpnt);
extern int mptscsih_bus_reset(struct scsi_cmnd * SCpnt);
extern int mptscsih_host_reset(struct scsi_cmnd *SCpnt);
extern int mptscsih_bios_param(struct scsi_device * sdev, struct block_device *bdev, sector_t capacity, int geom[]);
extern int mptscsih_io_done(MPT_ADAPTER *ioc, MPT_FRAME_HDR *mf, MPT_FRAME_HDR *r);
extern int mptscsih_taskmgmt_complete(MPT_ADAPTER *ioc, MPT_FRAME_HDR *mf, MPT_FRAME_HDR *r);
extern int mptscsih_scandv_complete(MPT_ADAPTER *ioc, MPT_FRAME_HDR *mf, MPT_FRAME_HDR *r);
extern int mptscsih_event_process(MPT_ADAPTER *ioc, EventNotificationReply_t *pEvReply);
extern int mptscsih_ioc_reset(MPT_ADAPTER *ioc, int post_reset);
extern int mptscsih_change_queue_depth(struct scsi_device *sdev, int qdepth);
extern void mptscsih_timer_expired(unsigned long data);
