/*
 * netlink/genl/genl.h		Generic Netlink
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation version 2.1
 *	of the License.
 *
 * Copyright (c) 2003-2006 Thomas Graf <tgraf@suug.ch>
 */

#ifndef NETLINK_GENL_H_
#define NETLINK_GENL_H_

#include <netlink/netlink.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int		genl_connect(struct nl_handle *);

extern int		genl_send_simple(struct nl_handle *, int, int,
					 int, int);

extern void *		genlmsg_put(struct nl_msg *, uint32_t, uint32_t,
				    int, int, int, uint8_t, uint8_t);
extern void *		genlmsg_data(const struct genlmsghdr *);
extern int		genlmsg_len(const struct genlmsghdr *);

extern char *		genl_op2name(int, int, char *, size_t);

#ifdef __cplusplus
}
#endif

#endif