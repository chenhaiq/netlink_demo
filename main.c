#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <linux/netlink.h>
#include <errno.h>

#include "main.h"

int main (int argc, char *argv[])
{
	struct rtnl_link *result;
	struct nl_sock *nlh;
	char *type;
//	int res = NM_IFACE_TYPE_UNSPEC;
	int err;
        printf("started\n");
        printf("arg1 [%s]\n", argv[1]);
        int ifindex = atoi(argv[1]);
        printf("ifindex [%d]\n", ifindex);
        printf("arg2 [%s]\n", argv[2]);

	nlh = nl_socket_alloc ();
	if (!nlh)
		printf("fail to get socket\n");

	err = nl_connect (nlh, NETLINK_ROUTE);
	if (err < 0) {
              printf("nl_connect failed err [%d]", err);
              return err;
	}
	/* Prefer interface indexes to names */
	err = rtnl_link_get_kernel (nlh, ifindex, argv[2], &result);
	if (err < 0) {
              printf("failed err [%d]", err);
	}else{
             type = rtnl_link_get_type (result);
             printf("type [%s]\n", type);
        }

}
