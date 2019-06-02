
#include "include.h"

/*
** Handles following functions:
**
**	void	*ft_memset(void *b, int c, size_t len);
**
*/

static void*	(*r)(void*, int, size_t);
static void*	(*m)(void*, int, size_t);
static bool	isok = true;

static void	errors(char *name, char *desc, char *real, char *mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got |%s| instead of |%s|\n", name, desc, real, mine);
	isok = false;
}

static void	run(bool (*test)(struct result *res, uint32_t, char), char *name)
{
	struct result	res;
	void		*ret_r;
	void		*ret_m;
	size_t		length;
	uint32_t	i;

	i = 0;
	while (test(&res, i, TYPE_STRING))
	{
		length = strlen(res.test);
		ret_r = strdup(res.test);
		ret_m = strdup(res.test);
		r(ret_r, '5', length);
		m(ret_m, '5', length);
		if (compare_str(ret_r, ret_m, length))
			errors(name, res.description, ret_r, ret_m);
		++i;
	}
}

bool		ut_memset(struct unit_test *ut)
{
	r = ut->f_real;
	m = ut->f_mine;
	run(get_str, ut->name);
	return isok;
}
