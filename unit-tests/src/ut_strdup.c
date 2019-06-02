
#include "include.h"

/*
** Handles following functions:
**
**	char	*ft_strdup(const char *s1);
**
*/

static char*	(*r)(char*);
static char*	(*m)(char*);
static char	isok = true;

static void	errors(char *name, char *desc, char *real, char *mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got |%s| instead of |%s|\n", name, desc, real, mine);
	isok = false;
}

static void	run(bool (*test)(struct result *, uint32_t, char), char *name)
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
		ret_r = r(res.test);
		ret_m = m(res.test);
		if (strncmp(ret_r, ret_m, length))
			errors(name, res.description, ret_r, ret_m);
		free(ret_r);
		free(ret_m);
		++i;
	}
}

bool		ut_strdup(struct unit_test *ut)
{
	r = ut->f_real;
	m = ut->f_mine;
	run(get_str, ut->name);
	return isok;
}
