
#include "include.h"

/*
** Handles following functions:
**
**	int		ft_putstr_fd(char *s, int fd);
**
*/

static int			(*r)(char*, FILE*);
static int			(*m)(char*, int);
static char			isok = true;

static void	errors(char *name, char *desc, char *real, char *mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got |%s| instead of |%s|\n", name, desc, real, mine);
	isok = false;
}

static char	*read_pipe(char* s, size_t length)
{
	char	buff[length + 1];
	int	pids[2];
	int	stdout_copy;
	int	fd;

	stdout_copy = dup(2);
	pipe(pids);
	dup2(pids[1], 2);

	m(s, 2);
	dup2(stdout_copy, 2);
	read(pids[0], buff, length);
	buff[length] = 0;

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(stdout_copy);
	return strdup(buff);
}

static char	*read_file(char *s, size_t length)
{
	FILE		*fp;
	char		buff[length + 1];
	int		fd;

	fp = fopen(REAL_PATH, "w+");
	if (!fp)
		return NULL;
	r(s, fp);
	length = strlen(s);
	fclose(fp);

	fd = open(REAL_PATH, O_RDONLY, 0666);
	read(fd, buff, length);
	buff[length] = 0;
	close(fd);
	return strdup(buff);
}

static void		run(bool (*test)(struct result *res, uint32_t, char), char *name)
{
	struct result	res;
	static uint32_t	i;
	char		*ret_r;
	char		*ret_m;
	size_t		length;

	i = 0;
	while (test(&res, i, TYPE_STRING))
	{
		length = strlen(res.test);
		ret_m = read_pipe(res.test, length);
		ret_r = read_file(res.test, length);
		if (compare_str(ret_r, ret_m, length))
			errors(name, res.description, ret_r, ret_m);
		free(ret_r);
		free(ret_m);
		++i;
	}
}

bool		ut_putstr_fd(struct unit_test *ut)
{
	r = ut->f_real;
	m = ut->f_mine;
	run(get_str, ut->name);
	return isok;
}
