#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <uchar.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

typedef int8_t char8_t;

bool ru32(const char8_t* fpath, uint32_t* v)
{
	uint32_t fdat;
	struct stat st;
	FILE* fp = fopen(fpath, "rb");
	fstat(fp, &st);
	if (st.st_size < 4)
	{
		fclose(fp);
		return false;
	}
	fread(&fdat, sizeof(uint32_t), 1, fp);
	fclose(fp);
	*v = ntohl(fdat);
	return true;
}

int32_t main(int32_t argc, char8_t *argv[])
{
	if (argc != 3)
		return 1;

	uint32_t u_0;
	uint32_t u_1;
	if (!ru32(argv[1], &u_0) || !ru32(argv[2], &u_1))
		return 1;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", u_0, u_0, u_1, u_1, u_0 + u_1, u_0 + u_1);
	return 0;
}

