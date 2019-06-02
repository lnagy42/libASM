
#include "include.h"

/*
** Handles following functions:
**
** 	int	ft_isalpha(int c);
**	int	ft_isdigit(int c);
**	int	ft_isalnum(int c);
**	int	ft_isascii(int c);
**	int	ft_isprint(int c);
**	int	ft_tolower(int c);
**	int	ft_toupper(int c);
** 	int	ft_isspace(int c);
** 	int	ft_isblank(int c);
**
*/

static int		(*real)(int);
static int		(*mine)(int);
static bool		isok = true;

static void		errors(char *name, char *desc, int real, int mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** "\
	"got %d instead of %d\n", name, desc, real, mine);
	isok = false;
}

bool			ut_is(struct unit_test *ut)
{
	struct result	res;
	int		ret_r;
	int		ret_m;
	int		i;

	real = ut->f_real;
	mine = ut->f_mine;
	i = 0;
	while (get_char(&res, i, TYPE_CHAR))
	{
		ret_r = real(res.test[0]);
		ret_m = mine(res.test[0]);
		if (compare_num(ret_r, ret_m))
			errors(ut->name, res.description, ret_r, ret_m);
		i++;
	}
	return isok;
}
