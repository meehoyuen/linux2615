/*
 *  ec.h - ACPI Embedded Controller Driver ($Revision: 38 $)
 *
 *  Copyright (C) 2004 Luming Yu <luming.yu@intel.com>
 *  Copyright (C) 2001, 2002 Andy Grover <andrew.grover@intel.com>
 *  Copyright (C) 2001, 2002 Paul Diefenbaugh <paul.s.diefenbaugh@intel.com>
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or (at
 *  your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

union acpi_ec {
	struct {
		u32 mode;
		acpi_handle handle;
		unsigned long uid;
		unsigned long gpe_bit;
		struct acpi_generic_address status_addr;
		struct acpi_generic_address command_addr;
		struct acpi_generic_address data_addr;
		unsigned long global_lock;
	} common;

	struct {
		u32 mode;
		acpi_handle handle;
		unsigned long uid;
		unsigned long gpe_bit;
		struct acpi_generic_address status_addr;
		struct acpi_generic_address command_addr;
		struct acpi_generic_address data_addr;
		unsigned long global_lock;
		unsigned int expect_event;
		atomic_t leaving_burst;	/* 0 : No, 1 : Yes, 2: abort */
		atomic_t pending_gpe;
		struct semaphore sem;
		wait_queue_head_t wait;
	} burst;

	struct {
		u32 mode;
		acpi_handle handle;
		unsigned long uid;
		unsigned long gpe_bit;
		struct acpi_generic_address status_addr;
		struct acpi_generic_address command_addr;
		struct acpi_generic_address data_addr;
		unsigned long global_lock;
		struct semaphore sem;
		spinlock_t lock;
	} polling;
};

extern int acpi_ec_read(union acpi_ec *ec, u8 address, u32 * data);
extern int acpi_ec_write(union acpi_ec *ec, u8 address, u8 data);
