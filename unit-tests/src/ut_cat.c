
#include "include.h"

/*
** Handles following functions:
**
**	void		ft_cat(int fd);
**
*/

static int			(*r)(char*, FILE*);
static void			(*m)(int);
static char			isok = true;

static void	errors(char *name, char *desc, char *real, char *mine)
{
	printf("[%s]: " CLR_RED "FAIL" CLR_NONE " ** %s ** " \
	"got |%s| instead of |%s|\n", name, desc, real, mine);
	isok = false;
}

static char	*read_pipe(int fd, size_t length)
{
	char	buff[length + 1];
	int	pids[2];
	int	stdout_copy;

	stdout_copy = dup(1);
	pipe(pids);
	dup2(pids[1], 1);

	m(fd);
	dup2(stdout_copy, 1);
	read(pids[0], buff, length);
	buff[length] = 0;

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(stdout_copy);
	close(fd);
	return strdup(buff);
}

static char	*read_file(char *file, size_t length)
{
	FILE		*fp;
	char		buff[length + 1];
	int		fd = open(file, O_RDONLY);

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
	while (test(&res, i, TYPE_FILE_CONTENT))
	{
		length = strlen(res.test);
		ret_m = read_pipe(res.type, res.length);
		ret_r = read_file(res.test, res.length);
		if (compare_str(ret_r, ret_m, res.length))
			errors(name, res.description, ret_r, ret_m);
		free(ret_r);
		free(ret_m);
		++i;
	}
}

bool		ut_cat(struct unit_test *ut)
{
	r = ut->f_real;
	m = ut->f_mine;
	run(get_file_fd, ut->name);
	return isok;
}
