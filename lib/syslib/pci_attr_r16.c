/*
pci_attr_r16.c
*/

#include "pci.h"
#include "syslib.h"
#include <minix/sysutil.h>

/*===========================================================================*
 *				pci_attr_r16				     *
 *===========================================================================*/
PUBLIC u16_t pci_attr_r16(devind, port)
int devind;
int port;
{
	int r;
	message m;

	m.m_type= BUSC_PCI_ATTR_R16;
	m.m2_i1= devind;
	m.m2_i2= port;

	r= sendrec(pci_procnr, &m);
	if (r != 0)
		panic("syslib/" __FILE__, "pci_attr_r16: can't talk to PCI", r);

	if (m.m_type != 0)
		panic("syslib/" __FILE__, "pci_attr_r16: got bad reply from PCI", m.m_type);

	return m.m2_l1;
}

