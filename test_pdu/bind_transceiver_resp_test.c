
/*
 * Copyright (C) 2006 Raul Tremsal
 * File  : bind_transceiver_resp_test.c
 * Author: Raul Tremsal <ultraismo@yahoo.com>
 *
 * This file is part of libsmpp34 (c-open-smpp3.4 library).
 *
 * The libsmpp34 library is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation; either version 2.1 of the 
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public 
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this library; if not, write to the Free Software Foundation, 
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 *
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>

#ifdef __linux__
#include <stdint.h>
#endif

#include "smpp34.h"
#include "smpp34_structs.h"
#include "smpp34_params.h"
#include "core.h"


#define TEXTO "Raul Antonio Tremsal"

int
main( int argc, char *argv[] )
{
    bind_transceiver_resp_t a;
    bind_transceiver_resp_t b;
    tlv_t tlv;

    memset(&a, 0, sizeof(bind_transceiver_resp_t));
    memset(&b, 0, sizeof(bind_transceiver_resp_t));
    memset(&tlv, 0, sizeof(tlv));

    /* Init PDU ***********************************************************/
    b.command_length   = 0;
    b.command_id       = BIND_TRANSCEIVER_RESP;
    b.command_status   = ESME_ROK;
    b.sequence_number  = 1;
    snprintf((char*)b.system_id, sizeof(b.system_id), "%s", "system_id");

    tlv.tag = TLVID_sc_interface_version;
    tlv.length = sizeof(uint8_t);
    tlv.value.val16 = 0x34;
    build_tlv( &(b.tlv), &tlv );

    doTest(BIND_TRANSCEIVER_RESP, &a, &b);
    destroy_tlv( b.tlv );
    destroy_tlv( a.tlv );
    return( 0 );
};
