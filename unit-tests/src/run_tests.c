
#include "include.h"

static void			end(char isok, char *name)
{
	if (isok)
		printf(P_END, name);
}

static void			cleanup(void)
{
	system("/bin/rm -f " REAL_PATH);
	system("/bin/rm -f " MINE_PATH);
}

static void			exec_test(struct unit_test *ut)
{
	static bool		(*ut_type[])(struct unit_test*) =
	{
		[UT_IS] = ut_is,
		[UT_TO] = ut_is,
		[UT_STRLEN] = ut_strlen,
		[UT_BZERO] = ut_bzero,
		[UT_STRDUP] = ut_strdup,
		[UT_STRCAT] = ut_strcat,
		[UT_MEMSET] = ut_memset,
		[UT_MEMCPY] = ut_memcpy,
		[UT_PUTS] = ut_puts,
		[UT_CAT] = ut_cat,
		[UT_PUTCHAR] = ut_putchar,
		[UT_PUTCHAR_FD] = ut_putchar_fd,
		[UT_PUTSTR] = ut_putstr,
		[UT_PUTSTR_FD] = ut_putstr_fd,
		[UT_MEMALLOC] = ut_memalloc
	};

	end(ut_type[ut->type](ut), ut->name);
}

bool				run_tests(void)
{
	static struct unit_test	run[] =
	{
		{isalnum, ft_isalnum, "ft_isalnum", UT_IS},
		{isalpha, ft_isalpha, "ft_isalpha", UT_IS},
		{isascii, ft_isascii, "ft_isascii", UT_IS},
		{isdigit, ft_isdigit, "ft_isdigit", UT_IS},
		{isprint, ft_isprint, "ft_isprint", UT_IS},
		{isspace, ft_isspace, "ft_isspace", UT_IS},
		{isblank, ft_isblank, "ft_isblank", UT_IS},
		{tolower, ft_tolower, "ft_tolower", UT_TO},
		{toupper, ft_toupper, "ft_toupper", UT_TO},
		{strlen, ft_strlen, "ft_strlen", UT_STRLEN},
		{bzero, ft_bzero, "ft_bzero", UT_BZERO},
		{strdup, ft_strdup, "ft_strdup", UT_STRDUP},
		{strcat, ft_strcat, "ft_strcat", UT_STRCAT},
		{memset, ft_memset, "ft_memset", UT_MEMSET},
		{memcpy, ft_memcpy, "ft_memcpy", UT_MEMCPY},
		{fputs, ft_puts, "ft_puts", UT_PUTS},
		{write, ft_cat, "ft_cat", UT_CAT},
		{fputc, ft_putchar, "ft_putchar", UT_PUTCHAR},
		{fputc, ft_putchar_fd, "ft_putchar_fd", UT_PUTCHAR_FD},
		{fputs, ft_putstr, "ft_putstr", UT_PUTSTR},
		// {fputs, ft_putstr_fd, "ft_putstr_fd", UT_PUTSTR_FD},
		// {strdup, ft_memalloc, "ft_memalloc", UT_MEMALLOC}
	};
	static const size_t	max = sizeof(run) / sizeof(struct unit_test);
	int32_t			i = -1;

	while (++i < max)
		exec_test(&run[i]);
	cleanup();
	return true;
}
