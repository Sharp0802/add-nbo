#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <uchar.h>
#include <unistd.h>
#include <stdio.h>

#define char8_t int8_t

uint32_t ru32(char8_t* fpath)
{
	uint32_t fdat, fdes = open(fpath, O_RDONLY);
	read(fdes, &fdat, 4);
	fdat = ntohl(fdat);
	close(fdes);
	return fdat;
}

int32_t main(int32_t argc, char8_t *argv[])
{
	if (argc != 3)
		return 1;

	uint32_t u_0 = ru32(argv[1]);
	uint32_t u_1 = ru32(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", u_0, u_0, u_1, u_1, u_0 + u_1, u_0 + u_1);
	return 0;
}

