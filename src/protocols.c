/* Etherape
 * Copyright (C) 2000 Juan Toledo
 * $Id$
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glib.h>
#include "capture.h"
#include "etypes.h"

extern apemode_t mode;

gchar *
get_eth_type (const guint8 * packet)
{
  etype_t etype;
  gchar *prot;

  etype = pntohs (&packet[12]);

  /* TODO We are just considering EthernetII here
   * I guess I'll have to do the Right Thing some day. :-) */
  switch (etype)
    {
    case ETHERTYPE_IP:
      prot = g_strdup ("IP");
      break;
    case ETHERTYPE_ARP:
      prot = g_strdup ("ARP");
      break;
    case ETHERTYPE_IPv6:
      prot = g_strdup ("IPv6");
      break;
    case ETHERTYPE_X25L3:
      prot = g_strdup ("X25L3");
      break;
    case ETHERTYPE_REVARP:
      prot = g_strdup ("REVARP");
      break;
    case ETHERTYPE_ATALK:
      prot = g_strdup ("ATALK");
      break;
    case ETHERTYPE_AARP:
      prot = g_strdup ("AARP");
      break;
    case ETHERTYPE_IPX:
      prot = g_strdup ("IPX");
      break;
    case ETHERTYPE_VINES:
      prot = g_strdup ("VINES");
      break;
    case ETHERTYPE_TRAIN:
      prot = g_strdup ("TRAIN");
      break;
    case ETHERTYPE_LOOP:
      prot = g_strdup ("LOOP");
      break;
    case ETHERTYPE_PPPOED:
      prot = g_strdup ("PPPOED");
      break;
    case ETHERTYPE_PPPOES:
      prot = g_strdup ("PPPOES");
      break;
    case ETHERTYPE_VLAN:
      prot = g_strdup ("VLAN");
      break;
    case ETHERTYPE_SNMP:
      prot = g_strdup ("SNMP");
      break;
    case ETHERTYPE_UNK:
    default:
      prot = g_strdup ("ETH_UNKNOWN");
    }

  return prot;
}

gchar *
get_packet_prot (const guint8 * packet)
{
  gchar *prot = "UNKNOWN";

  switch (mode)
    {
    case ETHERNET:
      prot = get_eth_type (packet);
      break;
    case IP:
    case TCP:
    default:
    }

  return prot;
}
