/******************************************************************************

 Filename:		server.h
 Description:	Private header file for WiServer

 ******************************************************************************

 Copyright(c) 2009 Mark A. Patel  All rights reserved.

 This program is free software; you can redistribute it and/or modify it
 under the terms of version 2 of the GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 more details.

 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59
 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

 Contact Information:

 Author               Date        Comment
 ---------------------------------------------------------------
 Mark A. Patel		06/10/2009	Initial version

 *****************************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__

#include <avr/pgmspace.h>
#include <uip-conf.h>

#ifdef APP_WISERVER

// Enables client mode (i.e. for sending Tweets and HTTP POST or GET requests)
// Comment out this #define if client mode isn't required
// (it'll save a bunch of code size and a bit of RAM too!)
#define ENABLE_CLIENT_MODE

// Enables dhcp client (so you don't have to implement the callbacks manually)
// call dhcp_client_configure_network to configure the network via DHCP
// UIP_DHCP must also be enabled
// #define ENABLE_DHCP_CLIENT

// Enables dns client (so you don't have to implement the callbacks manually)
// call dns_client_init with the DNS server to use and then call 
// dns_client_resolve with a hostname to resolve
// UIP_DNS must also be enabled
#define ENABLE_DNS_CLIENT

// If DEBUG is defined, the Serial class is used to output lots of diagnostic data
// (verbose mode is also enabled automatically)
// Warning: this increases RAM usage and code size and will slow execution speed
//#define DEBUG


// Declare the server's uip callback function
void server_app_task();

#define UIP_APPCALL server_app_task

/*
 * Stores the state for a single connection
 */
struct conn_state {
	int ackedCount; // Number of bytes sent and acked
	int sentCount; // Number of bytes awaiting an ack
	char* cursor; // Virtual cursor for write operations
	void* request; // Points to a char* URL (server mode) or a request object (client mode)
};

typedef struct conn_state uip_tcp_appstate_t;

#endif	/* APP_WISERVER */

#endif //__SERVER_H__
