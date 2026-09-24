#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	*ip;
	int		prefix;
	int		a, b, c, d;
	unsigned int addr;
	unsigned int mask;
	unsigned int network;
	unsigned int broadcast;
	unsigned int first;
	unsigned int last;
	unsigned int hosts;

	if (argc != 2)
		return (1);

	ip = strtok(argv[1], "/");
	if (!ip)
		return (1);

	prefix = atoi(strtok(NULL, "/"));
	if (prefix < 0 || prefix > 32)
		return (1);

	if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
		return (1);

	if (a < 0 || a > 255 || b < 0 || b > 255
		|| c < 0 || c > 255 || d < 0 || d > 255)
		return (1);

	/* IP -> 32 bits */
	addr = ((unsigned int)a << 24)
		| ((unsigned int)b << 16)
		| ((unsigned int)c << 8)
		| (unsigned int)d;

	/* Create the subnet mask */
	if (prefix == 0)
		mask = 0;
	else
		mask = 0xFFFFFFFF << (32 - prefix);

	/* Network and broadcast */
	network = addr & mask;
	broadcast = network | ~mask;

	/* Usable addresses */
	if (prefix == 31 || prefix == 32)
	{
		first = network;
		last = broadcast;
		hosts = broadcast - network + 1;
	}
	else
	{
		first = network + 1;
		last = broadcast - 1;
		hosts = broadcast - network - 1;
	}

	printf("Network   : %u.%u.%u.%u\n",
		network >> 24, (network >> 16) & 255,
		(network >> 8) & 255, network & 255);

	printf("First     : %u.%u.%u.%u\n",
		first >> 24, (first >> 16) & 255,
		(first >> 8) & 255, first & 255);

	printf("Last      : %u.%u.%u.%u\n",
		last >> 24, (last >> 16) & 255,
		(last >> 8) & 255, last & 255);

	printf("Broadcast : %u.%u.%u.%u\n",
		broadcast >> 24, (broadcast >> 16) & 255,
		(broadcast >> 8) & 255, broadcast & 255);

	printf("Hosts     : %u\n", hosts);

	return (0);
}
