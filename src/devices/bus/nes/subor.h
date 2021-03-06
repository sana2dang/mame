// license:BSD-3-Clause
// copyright-holders:Kaz, Fabio Priuli
#ifndef MAME_BUS_NES_SUBOR_H
#define MAME_BUS_NES_SUBOR_H

#include "nxrom.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> nes_subor0_device

class nes_subor0_device :
		public nes_nrom_device
{
public:
	// construction/destruction
	nes_subor0_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// device-level overrides
	virtual void device_start() override;
	virtual DECLARE_WRITE8_MEMBER(write_h) override;

	virtual void pcb_reset() override;

private:
	uint8_t m_reg[4];
};

// ======================> nes_subor1_device

class nes_subor1_device :
		public nes_nrom_device
{
public:
	// construction/destruction
	nes_subor1_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// device-level overrides
	virtual void device_start() override;
	virtual DECLARE_WRITE8_MEMBER(write_h) override;

	virtual void pcb_reset() override;

private:
	uint8_t m_reg[4];
};

// ======================> nes_subor2_device

class nes_subor2_device :
		public nes_nrom_device
{
public:
	// construction/destruction
	nes_subor2_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	// device-level overrides
	virtual void device_start() override;
	virtual DECLARE_READ8_MEMBER(nt_r) override;
	virtual DECLARE_WRITE8_MEMBER(write_l) override;
	virtual DECLARE_READ8_MEMBER(read_l) override;

	virtual void ppu_latch(offs_t offset) override;
	virtual void pcb_reset() override;

private:
	void update_banks();
	uint8_t m_switch_reg, m_bank_reg, m_chr_banking, m_page;
};

// device type definition
extern const device_type NES_SUBOR0;
extern const device_type NES_SUBOR1;
extern const device_type NES_SUBOR2;

#endif /* MAME_BUS_NES_SUBOR_H */
