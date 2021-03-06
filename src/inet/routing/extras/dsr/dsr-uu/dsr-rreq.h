/* Copyright (C) Uppsala University
 *
 * This file is distributed under the terms of the GNU general Public
 * License (GPL), see the file LICENSE
 *
 * Author: Erik Nordström, <erikn@it.uu.se>
 */
#ifndef _DSR_RREQ_H
#define _DSR_RREQ_H

#include "inet/routing/extras/dsr/dsr-uu/dsr.h"

#ifdef NS2
#ifndef OMNETPP
#include "endian.h"
#endif
#endif

#ifndef NO_GLOBALS
#include "dsr_options.h"

namespace inet {

namespace inetmanet {
#define DSR_RREQ_OPT_LEN (DSR_RREQ_HDR_LEN - 2)
#define DSR_RREQ_TOT_LEN IP_HDR_LEN + DSR_OPT_HDR_LEN + DSR_RREQ_HDR_LEN
#define DSR_RREQ_ADDRS_LEN(rreq_opt) (rreq_opt->length - 6)


} // namespace inetmanet

} // namespace inet

#endif              /* NO_GLOBALS */

#ifndef NO_DECLS
void rreq_tbl_set_max_len(unsigned int max_len);
int dsr_rreq_opt_recv(struct dsr_pkt *dp, struct dsr_rreq_opt *rreq_opt);
int rreq_tbl_route_discovery_cancel(struct in_addr dst);
int dsr_rreq_route_discovery(struct in_addr target);
int dsr_rreq_send(struct in_addr target, int ttl);
void rreq_tbl_timeout(void *data);
int dsr_rreq_duplicate(struct in_addr initiator, struct in_addr target,
                               unsigned int id,double cost,unsigned int length, VectorAddress &addrs);

int rreq_tbl_add_id(struct in_addr initiator, struct in_addr target,
                unsigned short id,double cost,const VectorAddress &addr,int length);

int rreq_tbl_init(void);
void rreq_tbl_cleanup(void);
#ifdef OMNETPP
void rreq_timer_test(cMessage *);
#endif

#endif              /* NO_DECLS */

#endif              /* _DSR_RREQ */
