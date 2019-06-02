
#include "include.h"

bool		compare_str(char *real, char *mine, size_t length)
{
	return strncmp(real, mine, length);
}

bool		compare_num(int64_t real, int64_t mine)
{
	return (real != mine);
}
