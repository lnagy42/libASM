
#include "include.h"

bool		get_str(struct result *res, uint32_t i, char type)
{
	static struct result	strs[] =
	{
		{"Empty string", ""},
		{"One char string", "a"},
		{"Small string", "A bit longer"},
		{"32 bytes string", "Hi, I have a length of 32 bytes."},
		{"64 bytes string", "Hi, I have a length of 64 bytes. Bleeeeeeeeeeeeeeeeeeeeeeeeeeeh."}
	};
	static size_t		range = sizeof(strs) / sizeof(struct result) - 1;

	res->description = strs[i].description;
	res->test = strs[i].test;
	res->type = type;
	return (!(i > range));
}

bool		get_char(struct result *res, uint32_t i, char type)
{
	static char	buff[2] = {0};
	buff[0] = i;

	res->description = "simple char";
	res->test = buff;
	res->type = type;
	return !(i > 127);
}

bool		get_file_fd(struct result *res, uint32_t i, char type)
{
	static struct result	files[] =
	{
		{"Small file", "rsc/text_small.txt"},
		{"Medium file", "rsc/text_medium.txt"},
		{"Large file", "rsc/text_large.txt"}
	};
	static size_t		range = sizeof(files) / sizeof(struct result) - 1;
	struct stat		file_stat;
	res->description = files[i].description;
	res->test = files[i].test;

	int	fd = open(res->test, O_RDONLY);
	if (!fd)
		return false;
	res->type = fd;

	fstat(fd, &file_stat);
	res->length = file_stat.st_size;

	return !(i > range);
}
