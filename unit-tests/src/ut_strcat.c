
#include "include.h"

/*
** Handles following functions:
**
**	char	*ft_strcat(char *s1, char *s2);
**
*/

static char*	(*r)(char*,char*);
static char*	(*m)(char*,char*);
static char	isok = true;

static void	errors(char *name, char *desc, char *real, char *mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got |%s| instead of |%s|\n", name, desc, real, mine);
	isok = false;
}

static void		run(bool (*test)(struct result *, uint32_t, char), char *name)
{
	struct result	res;
	char		*ret_r;
	char		*ret_m;
	size_t		length;
	uint32_t	i;

	i = 0;
	while (test(&res, i, TYPE_STRING))
	{
		length = strlen(res.test);
		ret_r = (char*)malloc(length * 2 + 1);
		ret_m = (char*)malloc(length * 2 + 1);
		ret_r = r(ret_r, res.test);
		ret_m = m(ret_m, res.test);
		if (compare_str(ret_r, ret_m, length))
			errors(name, res.description, ret_r, ret_m);
		free(ret_r);
		free(ret_m);
		++i;
	}
}

bool		ut_strcat(struct unit_test *ut)
{
	r = ut->f_real;
	m = ut->f_mine;
	run(get_str, ut->name);
	return isok;
}
