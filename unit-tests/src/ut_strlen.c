
#include "include.h"

/*
** Handles following functions:
**
**	size_t		ft_strlen(const char *s);
**
*/

static size_t	(*real)(char*);
static size_t	(*mine)(char*);
static char	isok = true;

static void	errors(char *name, char *desc, int real, int mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got %d instead of %d\n", name, desc, real, mine);
	isok = false;
}

static void	run(bool (*test)(struct result*, uint32_t, char), char *name)
{
	struct result	res;
	char		*s;
	size_t		ret_r;
	size_t		ret_m;
	uint32_t	i;

	i = 0;
	while (test(&res, i, TYPE_STRING))
	{
		ret_r = real(res.test);
		ret_m = mine(res.test);
		if (compare_num(ret_r, ret_m))
			errors(name, res.description, ret_r, ret_m);
		++i;
	}
}

bool			ut_strlen(struct unit_test *ut)
{
	real = ut->f_real;
	mine = ut->f_mine;
	run(get_str, ut->name);
	return isok;
}
