/* Header of ADC MFD core driver for sunxi platforms
 *
 * Copyright (c) 2016 Quentin Schulz <quentin.schulz@free-electrons.com>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation.
 */

#ifndef __SUN4I_GPADC__H__
#define __SUN4I_GPADC__H__

#define SUN4I_GPADC_CTRL0				0x00

#define SUN4I_GPADC_CTRL0_ADC_FIRST_DLY(x)		((GENMASK(7, 0) & (x)) << 24)
#define SUN4I_GPADC_CTRL0_ADC_FIRST_DLY_MODE		BIT(23)
#define SUN4I_GPADC_CTRL0_ADC_CLK_SELECT		BIT(22)
#define SUN4I_GPADC_CTRL0_ADC_CLK_DIVIDER(x)		((GENMASK(1, 0) & (x)) << 20)
#define SUN4I_GPADC_CTRL0_FS_DIV(x)			((GENMASK(3, 0) & (x)) << 16)
#define SUN4I_GPADC_CTRL0_T_ACQ(x)			(GENMASK(15, 0) & (x))

#define SUN4I_GPADC_CTRL1				0x04

#define SUN4I_GPADC_CTRL1_STYLUS_UP_DEBOUNCE(x)		((GENMASK(7, 0) & (x)) << 12)
#define SUN4I_GPADC_CTRL1_STYLUS_UP_DEBOUNCE_EN		BIT(9)
#define SUN4I_GPADC_CTRL1_TOUCH_PAN_CALI_EN		BIT(6)
#define SUN4I_GPADC_CTRL1_TP_DUAL_EN			BIT(5)
#define SUN4I_GPADC_CTRL1_TP_MODE_EN			BIT(4)
#define SUN4I_GPADC_CTRL1_TP_ADC_SELECT			BIT(3)
#define SUN4I_GPADC_CTRL1_ADC_CHAN_SELECT(x)		(GENMASK(2, 0) & (x))
#define SUN4I_GPADC_CTRL1_ADC_CHAN_MASK			GENMASK(2, 0)

/* TP_CTRL1 bits for sun6i SOCs */
#define SUN6I_GPADC_CTRL1_TOUCH_PAN_CALI_EN		BIT(7)
#define SUN6I_GPADC_CTRL1_TP_DUAL_EN			BIT(6)
#define SUN6I_GPADC_CTRL1_TP_MODE_EN			BIT(5)
#define SUN6I_GPADC_CTRL1_TP_ADC_SELECT			BIT(4)
#define SUN6I_GPADC_CTRL1_ADC_CHAN_SELECT(x)		(GENMASK(3, 0) & BIT(x))
#define SUN6I_GPADC_CTRL1_ADC_CHAN_MASK			GENMASK(3, 0)

/* TP_CTRL1 bits for sun8i A23/A33 SoCs */
#define SUN8I_A23_GPADC_CTRL1_CHOP_TEMP_EN		BIT(8)
#define SUN8I_A23_GPADC_CTRL1_GPADC_CALI_EN		BIT(7)

/* TP_CTRL1 bits for SoCs after H3 */
#define SUN8I_H3_GPADC_CTRL1_GPADC_CALI_EN		BIT(17)

#define SUN4I_GPADC_CTRL2				0x08

#define SUN4I_GPADC_CTRL2_TP_SENSITIVE_ADJUST(x)	((GENMASK(3, 0) & (x)) << 28)
#define SUN4I_GPADC_CTRL2_TP_MODE_SELECT(x)		((GENMASK(1, 0) & (x)) << 26)
#define SUN4I_GPADC_CTRL2_PRE_MEA_EN			BIT(24)
#define SUN4I_GPADC_CTRL2_PRE_MEA_THRE_CNT(x)		(GENMASK(23, 0) & (x))

#define SUN8I_H3_GPADC_CTRL2				0x40

#define SUN8I_H3_GPADC_CTRL2_TEMP_SENSE_EN		BIT(0)
#define SUN8I_H3_GPADC_CTRL2_T_ACQ1(x)			((GENMASK(15, 0) * (x)) << 16)

#define SUN4I_GPADC_CTRL3				0x0c
/*
 * This register is named "Average filter Control Register" in H3 Datasheet,
 * but the register's definition is the same as the old CTRL3 register.
 */
#define SUN8I_H3_GPADC_CTRL3				0x70

#define SUN4I_GPADC_CTRL3_FILTER_EN			BIT(2)
#define SUN4I_GPADC_CTRL3_FILTER_TYPE(x)		(GENMASK(1, 0) & (x))

#define SUN4I_GPADC_TPR					0x18

#define SUN4I_GPADC_TPR_TEMP_ENABLE			BIT(16)
#define SUN4I_GPADC_TPR_TEMP_PERIOD(x)			(GENMASK(15, 0) & (x))

#define SUN4I_GPADC_INT_FIFOC				0x10

#define SUN4I_GPADC_INT_FIFOC_TEMP_IRQ_EN		BIT(18)
#define SUN4I_GPADC_INT_FIFOC_TP_OVERRUN_IRQ_EN		BIT(17)
#define SUN4I_GPADC_INT_FIFOC_TP_DATA_IRQ_EN		BIT(16)
#define SUN4I_GPADC_INT_FIFOC_TP_DATA_XY_CHANGE		BIT(13)
#define SUN4I_GPADC_INT_FIFOC_TP_FIFO_TRIG_LEVEL(x)	((GENMASK(4, 0) & (x)) << 8)
#define SUN4I_GPADC_INT_FIFOC_TP_DATA_DRQ_EN		BIT(7)
#define SUN4I_GPADC_INT_FIFOC_TP_FIFO_FLUSH		BIT(4)
#define SUN4I_GPADC_INT_FIFOC_TP_UP_IRQ_EN		BIT(1)
#define SUN4I_GPADC_INT_FIFOC_TP_DOWN_IRQ_EN		BIT(0)

#define SUN8I_H3_GPADC_INTC				0x44

#define SUN8I_H3_GPADC_INTC_TEMP_PERIOD(x)		((GENMASK(19, 0) & (x)) << 12)
#define SUN8I_H3_GPADC_INTC_TEMP_DATA			BIT(8)
#define SUN8I_H3_GPADC_INTC_TEMP_SHUT			BIT(4)
#define SUN8I_H3_GPADC_INTC_TEMP_ALARM			BIT(0)

#define SUN4I_GPADC_INT_FIFOS				0x14

#define SUN4I_GPADC_INT_FIFOS_TEMP_DATA_PENDING		BIT(18)
#define SUN4I_GPADC_INT_FIFOS_FIFO_OVERRUN_PENDING	BIT(17)
#define SUN4I_GPADC_INT_FIFOS_FIFO_DATA_PENDING		BIT(16)
#define SUN4I_GPADC_INT_FIFOS_TP_IDLE_FLG		BIT(2)
#define SUN4I_GPADC_INT_FIFOS_TP_UP_PENDING		BIT(1)
#define SUN4I_GPADC_INT_FIFOS_TP_DOWN_PENDING		BIT(0)

#define SUN8I_H3_GPADC_INTS				0x44

#define SUN8I_H3_GPADC_INTS_TEMP_DATA			BIT(8)
#define SUN8I_H3_GPADC_INTS_TEMP_SHUT			BIT(4)
#define SUN8I_H3_GPADC_INTS_TEMP_ALARM			BIT(0)

#define SUN4I_GPADC_CDAT				0x1c
#define SUN4I_GPADC_TEMP_DATA				0x20
#define SUN4I_GPADC_DATA				0x24
#define SUN8I_H3_GPADC_TEMP_DATA			0x80

#define SUN4I_GPADC_IRQ_FIFO_DATA			0
#define SUN4I_GPADC_IRQ_TEMP_DATA			1

/* 10s delay before suspending the IP */
#define SUN4I_GPADC_AUTOSUSPEND_DELAY			10000

struct sun4i_gpadc_dev {
	struct device			*dev;
	struct regmap			*regmap;
	struct regmap_irq_chip_data	*regmap_irqc;
	void __iomem			*base;
};

#endif
