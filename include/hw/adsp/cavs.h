/* Core Audio DSP
 *
 * Copyright (C) 2016 Intel Corporation
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __HW_ADSP_CAVS_H__
#define __HW_ADSP_CAVS_H__

#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>
#include "qemu/osdep.h"
#include "qapi/error.h"
#include "qemu-common.h"
#include "exec/hwaddr.h"
#include "hw.h"

/*
 * Host Side
 */

#define ADSP_CAVS_PCI_BASE           0xF2200000
#define ADSP_CAVS_MMIO_BASE          0xF2400000
#define ADSP_CAVS_HOST_IRAM_BASE     (ADSP_CAVS_MMIO_BASE + 0x000c0000)
#define ADSP_CAVS_HOST_DRAM_BASE     (ADSP_CAVS_MMIO_BASE + 0x00100000)
#define ADSP_CAVS_HOST_SHIM_BASE     (ADSP_CAVS_MMIO_BASE + 0x00140000)
#define ADSP_CAVS_HOST_MAILBOX_BASE  (ADSP_CAVS_MMIO_BASE + 0x00144000)
#define ADSP_CAVS_HOST_IPC_BASE	     (ADSP_CAVS_MMIO_BASE + 0x00148040)

/*
 * ROM
 */
#define ADSP_CAVS_DSP_ROM_BASE     0xBEFE0000
#define ADSP_CAVS_DSP_ROM_SIZE         0x0002000

/*
 * CAVS 1.5
 */

#define ADSP_CAVS_1_5_DSP_SHIM_BASE      0x00001000
#define ADSP_CAVS_1_5_SHIM_SIZE          0x00000100

#define ADSP_CAVS_1_5_DSP_CMD_BASE       0x00001100
#define ADSP_CAVS_1_5_DSP_CMD_SIZE       0x00000010

#define ADSP_CAVS_1_5_DSP_RES_BASE       0x00001110
#define ADSP_CAVS_1_5_DSP_RES_SIZE       0x00000010

#define ADSP_CAVS_1_5_DSP_IPC_HOST_BASE  0x00001180
#define ADSP_CAVS_1_5_DSP_IPC_HOST_SIZE  0x00000040

#define ADSP_CAVS_1_5_DSP_IDC_DSP_SIZE   0x00000080
#define ADSP_CAVS_1_5_DSP_IDC_DSP_BASE(x) \
    (0x00001200 + x * ADSP_CAVS_1_5_DSP_IDC_DSP_SIZE)

#define ADSP_CAVS_1_5_DSP_HOST_WIN_SIZE  0x00000008
#define ADSP_CAVS_1_5_DSP_HOST_WIN_BASE(x) \
    (0x00001580 + x * ADSP_CAVS_1_5_DSP_HOST_WIN_SIZE)

#define ADSP_CAVS_1_5_DSP_L2_BASE       0x00001500
#define ADSP_CAVS_1_5_DSP_L2_SIZE       0x00000040

#define ADSP_CAVS_1_5_DSP_IRQ_BASE       0x00001600
#define ADSP_CAVS_1_5_DSP_IRQ_SIZE       0x00000200

#define ADSP_CAVS_1_5_DSP_TIME_BASE      0x00001800
#define ADSP_CAVS_1_5_DSP_TIME_SIZE      0x00000200

#define ADSP_CAVS_1_5_DSP_MN_BASE        0x00001A00
#define ADSP_CAVS_1_5_DSP_MN_SIZE        0x00000200

#define ADSP_CAVS_1_5_DSP_LP_GP_DMA_LINK_SIZE    0x00000080
#define ADSP_CAVS_1_5_DSP_LP_GP_DMA_LINK_BASE(x) \
    (0x00001C00 + x * ADSP_CAVS_1_5_DSP_LP_GP_DMA_LINK_SIZE)

#define ADSP_CAVS_1_5_DSP_HP_GP_DMA_LINK_SIZE    0x00000800
#define ADSP_CAVS_1_5_DSP_HP_GP_DMA_LINK_BASE(x) \
    (0x00001D00 + x * ADSP_CAVS_1_5_DSP_HP_GP_DMA_LINK_SIZE)

#define ADSP_CAVS_1_5_DSP_GTW_LINK_OUT_STREAM_SIZE   0x00000020
#define ADSP_CAVS_1_5_DSP_GTW_LINK_OUT_STREAM_BASE(x) \
    (0x00002400 + x * ADSP_CAVS_1_5_DSP_GTW_LINK_OUT_STREAM_SIZE)

#define ADSP_CAVS_1_5_DSP_GTW_LINK_IN_STREAM_SIZE    0x00000020
#define ADSP_CAVS_1_5_DSP_GTW_LINK_IN_STREAM_BASE(x) \
    (0x00002600 + x * ADSP_CAVS_1_5_DSP_GTW_LINK_IN_STREAM_SIZE)

#define ADSP_CAVS_1_5_DSP_GTW_HOST_OUT_STREAM_SIZE   0x00000040
#define ADSP_CAVS_1_5_DSP_GTW_HOST_OUT_STREAM_BASE(x) \
    (0x00002800 + x * ADSP_CAVS_1_5_DSP_GTW_LINK_OUT_STREAM_SIZE)

#define ADSP_CAVS_1_5_DSP_GTW_HOST_IN_STREAM_SIZE    0x00000040
#define ADSP_CAVS_1_5_DSP_GTW_HOST_IN_STREAM_BASE(x) \
    (0x00002C00 + x * ADSP_CAVS_1_5_DSP_GTW_LINK_IN_STREAM_SIZE)

#define ADSP_CAVS_1_5_DSP_GTW_CODE_LDR_SIZE  0x00000040
#define ADSP_CAVS_1_5_DSP_GTW_CODE_LDR_BASE  0x00002BC0

#define ADSP_CAVS_1_5_DSP_DMIC_BASE      0x00004000
#define ADSP_CAVS_1_5_DSP_DMIC_SIZE      0x00004000

#define ADSP_CAVS_1_5_DSP_SSP_BASE(x) \
    (0x00008000 + x * ADSP_CAVS_1_5_DSP_SSP_SIZE)
#define ADSP_CAVS_1_5_DSP_SSP_SIZE       0x00002000

#define ADSP_CAVS_1_5_DSP_LP_GP_DMA_SIZE 0x00001000
#define ADSP_CAVS_1_5_DSP_LP_GP_DMA_BASE(x) \
    (0x0000C000 + x * ADSP_CAVS_1_5_DSP_LP_GP_DMA_SIZE)

#define ADSP_CAVS_1_5_DSP_HP_GP_DMA_SIZE 0x00001000
#define ADSP_CAVS_1_5_DSP_HP_GP_DMA_BASE(x) \
    (0x0000E000 + x * ADSP_CAVS_1_5_DSP_HP_GP_DMA_SIZE)

/* L2 SRAM */
#define ADSP_CAVS_1_5_DSP_SRAM_BASE      0xA000A000
#define ADSP_CAVS_1_5_DSP_SRAM_SIZE          (1024 * 1024 * 2)

/* HP SRAM */
#define ADSP_CAVS_1_5_DSP_HP_SRAM_BASE     0xBE000000
#define ADSP_CAVS_1_5_DSP_HP_SRAM_SIZE         ADSP_CAVS_1_5_DSP_SRAM_SIZE

/* LP SRAM */
#define ADSP_CAVS_1_5_DSP_LP_SRAM_BASE     0xBE800000
#define ADSP_CAVS_1_5_DSP_LP_SRAM_SIZE         0x00020000

/* Uncache */
#define ADSP_CAVS_1_5_DSP_UNCACHE_BASE     (ADSP_CAVS_1_5_DSP_HP_SRAM_BASE - 0x20000000)
#define ADSP_CAVS_1_5_DSP_UNCACHE_SIZE         0x0080000

/* IMR  */
#define ADSP_CAVS_1_5_DSP_IMR_BASE     0xB0000000
#define ADSP_CAVS_1_5_DSP_IMR_SIZE         0x0080000
#define ADSP_CAVS_1_5P_DSP_IMR_MAN_OFFSET  0x4000
#define ADSP_CAVS_1_5_DSP_IMR_MAN_OFFSET  0x2000


/*
 * CAVS 1.8
 */

#define ADSP_CAVS_1_8_DSP_CAP_BASE      0x00001000
#define ADSP_CAVS_1_8_DSP_CAP_SIZE          0x00000100

#define ADSP_CAVS_1_8_DSP_HP_GPDMA_SHIM_BASE       0x00001100
#define ADSP_CAVS_1_8_DSP_HP_GPDMA_SHIM_SIZE       0x00000200

#define ADSP_CAVS_1_8_DSP_IDC_DSP_SIZE   0x00000080
#define ADSP_CAVS_1_8_DSP_IDC_DSP_BASE(x) \
    (0x00001200 + x * ADSP_CAVS_1_8_DSP_IDC_DSP_SIZE)

#define ADSP_CAVS_1_8_DSP_L2C_BASE       0x00001500
#define ADSP_CAVS_1_8_DSP_L2C_SIZE       0x00000040

#define ADSP_CAVS_1_8_DSP_HP_GPDMA0_BASE 0x00004000
#define ADSP_CAVS_1_8_DSP_HP_GPDMA0_SIZE    0x1000

#define ADSP_CAVS_1_8_DSP_DMIC_BASE      0x00010000
#define ADSP_CAVS_1_8_DSP_DMIC_SIZE      0x00008000

#define ADSP_CAVS_1_8_DSP_TIME_BASE      0x00071800
#define ADSP_CAVS_1_8_DSP_TIME_SIZE      0x00000200

#define ADSP_CAVS_1_8_DSP_HOST_WIN_SIZE  0x00000008
#define ADSP_CAVS_1_8_DSP_HOST_WIN_BASE(x) \
    (0x00071a00 + x * ADSP_CAVS_1_8_DSP_HOST_WIN_SIZE)

#define ADSP_CAVS_1_8_DSP_CMD_BASE       0x00071a50
#define ADSP_CAVS_1_8_DSP_CMD_SIZE       0x00000010

#define ADSP_CAVS_1_8_DSP_RES_BASE       0x00071a60
#define ADSP_CAVS_1_8_DSP_RES_SIZE       0x00000020

#define ADSP_CAVS_1_8_DSP_L2M_BASE       0x00071d00
#define ADSP_CAVS_1_8_DSP_L2M_SIZE       0x00000080

#define ADSP_CAVS_1_8_DSP_IPC_HOST_BASE  0x00071e00
#define ADSP_CAVS_1_8_DSP_IPC_HOST_SIZE  0x00000040

#define ADSP_CAVS_1_8_DSP_SHIM_BASE        0x00071f00
#define ADSP_CAVS_1_8_DSP_SHIM_SIZE        0x00000100

#define ADSP_CAVS_1_8_DSP_GTW_LINK_OUT_STREAM_SIZE   0x00000020
#define ADSP_CAVS_1_8_DSP_GTW_LINK_OUT_STREAM_BASE(x) \
    (0x00072400 + x * ADSP_CAVS_1_8_DSP_GTW_LINK_OUT_STREAM_SIZE)

#define ADSP_CAVS_1_8_DSP_GTW_LINK_IN_STREAM_SIZE    0x00000020
#define ADSP_CAVS_1_8_DSP_GTW_LINK_IN_STREAM_BASE(x) \
    (0x00072600 + x * ADSP_CAVS_1_8_DSP_GTW_LINK_IN_STREAM_SIZE)

#define ADSP_CAVS_1_8_DSP_GTW_HOST_OUT_STREAM_SIZE   0x00000040
#define ADSP_CAVS_1_8_DSP_GTW_HOST_OUT_STREAM_BASE(x) \
    (0x00072800 + x * ADSP_CAVS_1_8_DSP_GTW_LINK_OUT_STREAM_SIZE)

#define ADSP_CAVS_1_8_DSP_GTW_HOST_IN_STREAM_SIZE    0x00000040
#define ADSP_CAVS_1_8_DSP_GTW_HOST_IN_STREAM_BASE(x) \
    (0x00072C00 + x * ADSP_CAVS_1_8_DSP_GTW_LINK_IN_STREAM_SIZE)

#define ADSP_CAVS_1_8_DSP_GTW_CODE_LDR_SIZE  0x00000040
#define ADSP_CAVS_1_8_DSP_GTW_CODE_LDR_BASE  0x00072BC0

#define ADSP_CAVS_1_8_DSP_SSP_BASE(x) \
    (0x00077000 + x * ADSP_CAVS_1_8_DSP_SSP_SIZE)
#define ADSP_CAVS_1_8_DSP_SSP_SIZE       0x00000200

#define ADSP_CAVS_1_8_DSP_LP_GPDMA_SHIM_BASE(x)\
    (0x00078400 + x * ADSP_CAVS_1_8_DSP_LP_GPDMA_SHIM_SIZE)
#define ADSP_CAVS_1_8_DSP_LP_GPDMA_SHIM_SIZE       0x00000100

#define ADSP_CAVS_1_8_DSP_IRQ_BASE        0x00078800
#define ADSP_CAVS_1_8_DSP_IRQ_SIZE        0x00000200

#define ADSP_CAVS_1_8_DSP_MN_BASE        0x00078c00
#define ADSP_CAVS_1_8_DSP_MN_SIZE        0x00000200

#define ADSP_CAVS_1_8_DSP_LP_GP_DMA_LINK_SIZE    0x00001000
#define ADSP_CAVS_1_8_DSP_LP_GP_DMA_LINK_BASE(x) \
    (0x0007C000 + x * ADSP_CAVS_1_8_DSP_LP_GP_DMA_LINK_SIZE)

/* L2 SRAM */
#define ADSP_CAVS_1_8_DSP_SRAM_BASE      0xA000A000
#define ADSP_CAVS_1_8_DSP_SRAM_SIZE          0x00800000

/* HP SRAM */
#define ADSP_CAVS_1_8_DSP_HP_SRAM_BASE     0xBE000000
#define ADSP_CAVS_1_8_DSP_HP_SRAM_SIZE         ADSP_CAVS_1_8_DSP_SRAM_SIZE

/* LP SRAM */
#define ADSP_CAVS_1_8_DSP_LP_SRAM_BASE     0xBE800000
#define ADSP_CAVS_1_8_DSP_LP_SRAM_SIZE         0x00020000

/* Uncache */
#define ADSP_CAVS_1_8_DSP_UNCACHE_BASE         (ADSP_CAVS_1_8_DSP_HP_SRAM_BASE - 0x20000000)
#define ADSP_CAVS_1_8_DSP_UNCACHE_SIZE         ADSP_CAVS_1_8_DSP_SRAM_SIZE

/* Uncache */
#define ADSP_CAVS_1_8_DSP_LP_UNCACHE_BASE         (ADSP_CAVS_1_8_DSP_LP_SRAM_BASE - 0x20000000)
#define ADSP_CAVS_1_8_DSP_LP_UNCACHE_SIZE         ADSP_CAVS_1_8_DSP_LP_SRAM_SIZE

#define ADSP_CAVS_1_8_DSP_IMR_BASE     0xB0000000
#define ADSP_CAVS_1_8_DSP_IMR_SIZE         0x0100000
#define ADSP_CAVS_1_8_DSP_IMR_MAN_OFFSET  0x32000

/* SUE additions on CAVS 1.8 */
#define ADSP_CAVS_1_8_DSP_SUE_SPIS_BASE  0x80000
#define ADSP_CAVS_1_8_DSP_SUE_SPIS_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_I2C_BASE  0x80400
#define ADSP_CAVS_1_8_DSP_SUE_I2C_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_UART_BASE  0x88000
#define ADSP_CAVS_1_8_DSP_SUE_UART_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_GPIO_BASE  0x80c00
#define ADSP_CAVS_1_8_DSP_SUE_GPIO_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_TIMER_BASE  0x81000
#define ADSP_CAVS_1_8_DSP_SUE_TIMER_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_WDT_BASE  0x81400
#define ADSP_CAVS_1_8_DSP_SUE_WDT_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_IRQ_BASE  0x81800
#define ADSP_CAVS_1_8_DSP_SUE_IRQ_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_CTRL_BASE  0x81c00
#define ADSP_CAVS_1_8_DSP_SUE_CTRL_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_USB_BASE  0xA0000
#define ADSP_CAVS_1_8_DSP_SUE_USB_SIZE  0x6000

#define ADSP_CAVS_1_8_DSP_SUE_SPIM_BASE  0xE000
#define ADSP_CAVS_1_8_DSP_SUE_SPIM_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_PMEMCTRL_BASE  0xE400
#define ADSP_CAVS_1_8_DSP_SUE_PMEMCTRL_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_GNA_BASE  0xE800
#define ADSP_CAVS_1_8_DSP_SUE_GNA_SIZE  0x400

#define ADSP_CAVS_1_8_DSP_SUE_SPIMEM_UNCACHE_BASE  0xC0000000
#define ADSP_CAVS_1_8_DSP_SUE_SPIMEM_CACHE_BASE  0xE0000000
#define ADSP_CAVS_1_8_DSP_SUE_SPIMEML_SIZE  0x8000000

#define ADSP_CAVS_1_8_DSP_SUE_PARMEM_UNCACHE_BASE  0xD0000000
#define ADSP_CAVS_1_8_DSP_SUE_PARMEM_CACHE_BASE  0xF0000000
#define ADSP_CAVS_1_8_DSP_SUE_PARMEML_SIZE  0x4000000

/* mailbox */
#define ADSP_CAVS_DSP_MAILBOX_SIZE      0x4000

/* external interrupts */
#define IRQ_HPGPDMA     0
#define IRQ_DWCT1       1
#define IRQ_DWCT0       2
#define IRQ_L2ME       3
#define IRQ_DTS       4
#define IRQ_IDC       5
#define IRQ_IPC       6
#define IRQ_DSPGCL       7
#define IRQ_DSPGHOS       8
#define IRQ_HPGPDMA0       9
#define IRQ_DSPGHIS       10
#define IRQ_LPGPDMA1       11
#define IRQ_DSPGLOS       12
#define IRQ_LPGPDMA0       13
#define IRQ_DSPGLIS       14
#define IRQ_DMIC0       15
#define IRQ_DMIC1       16
#define IRQ_SSP0       17
#define IRQ_SSP1       18
#define IRQ_SSP2       19
#define IRQ_SSP3       20
#define IRQ_SSP4       21
#define IRQ_SSP5       22
#define IRQ_LPGPDMA     23
#define IRQ_SNDW    24


struct cavs_irq_desc {
    int id;
    int level;
    uint32_t mask;
    uint32_t shift;
};

struct cavs_irq_map {
    int level;
    int irq;
};

/* external IRQ xtensa mappings */
#define IRQ_NUM_EXT_LEVEL2  6   /* level 2 */
#define IRQ_NUM_EXT_LEVEL3  10  /* level 3 */
#define IRQ_NUM_EXT_LEVEL4  13  /* level 4 */
#define IRQ_NUM_EXT_LEVEL5  16  /* level 5 */

extern const MemoryRegionOps cavs_shim_ops;
void cavs_irq_set(struct adsp_io_info *info, int irq, uint32_t mask);
void cavs_irq_clear(struct adsp_io_info *info, int irq, uint32_t mask);
void cavs_ext_timer_cb0(void *opaque);
void cavs_ext_timer_cb1(void *opaque);

/* IPC - v1.5 */
#define IPC_DIPCT       0x0
#define IPC_DIPCT_DSPLRST   (0x1 << 31)

#define IPC_DIPCTE       0x4
#define IPC_DIPCI       0x8
#define IPC_DIPCI_DSPRST    (0x1 << 31)

#define IPC_DIPCIE       0xc
#define IPC_DIPCIE_DONE       (0x1 << 30)

#define IPC_DIPCCTL5		 0x10
#define IPC_DIPCCTL5_IPCIDIE     (1 << 1)
#define IPC_DIPCCTL5_IPCTBIE     (1 << 0)

/*
 * IPC -v1.5 DSP registers
 * On the real device, these are the host side doorbell registers.
 * Kepping these part of the same io region as the DSP doorbell registers
 * in QEMU.
 */
#define IPC_DSP_REG_BASE	0x20
#define IPC_HIPCT		(IPC_DSP_REG_BASE + 0x0)
#define IPC_HIPCT_BUSY		(0x1 << 31)
#define IPC_HIPCTE		(IPC_DSP_REG_BASE + 0x4)
#define IPC_HIPCI		(IPC_DSP_REG_BASE + 0x8)
#define IPC_HIPCI_BUSY		(0x1 << 31)
#define IPC_HIPCIE		(IPC_DSP_REG_BASE + 0xC)
#define IPC_HIPCIE_DONE		(0x1 << 31)
#define IPC_HIPCCTL		(IPC_DSP_REG_BASE + 0x10)

/* IPC v1.8 */
#define IPC_DIPCTDR     0x0
#define IPC_DIPCTDA     0x4
#define IPC_DIPCTDD     0x8
#define IPC_DIPCIDR     0x10
#define IPC_DIPCIDA     0x14
#define IPC_DIPCIDD     0x18
#define IPC_DIPCCST     0x20
#define IPC_DIPCCSR     0x24
#define IPC_DIPCCTL8     0x28

#endif
