
#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <ctype.h>
# include <sys/stat.h>
# include <execinfo.h>
# include <errno.h>
# include <stdbool.h>

struct		unit_test
{
	void	*f_real;
	void	*f_mine;
	char	*name;
	char	type;
};

struct result
{
	char	*description;
	char	*test;
	size_t	length;
	char	type;
};

enum
{
	UT_IS,
	UT_TO,
	UT_STRLEN,
	UT_BZERO,
	UT_STRDUP,
	UT_STRCAT,
	UT_MEMSET,
	UT_MEMCPY,
	UT_PUTS,
	UT_CAT,
	UT_PUTCHAR,
	UT_PUTCHAR_FD,
	UT_PUTSTR,
	UT_PUTSTR_FD,
	UT_MEMALLOC,
	UT_SIZE
};

enum
{
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_FILE_CONTENT,
	TYPE_SIZE
};

#define CLR_NONE	"\e[0m"
#define CLR_RED		"\e[31m"
#define CLR_GREEN	"\e[32m"
#define CLR_YELLOW	"\e[33m"

#define P_EOTEST	"\n"
#define P_BEGIN		CLR_YELLOW "Tests for %s: " CLR_NONE
#define P_END		"[%s]: " CLR_GREEN "OK" CLR_NONE P_EOTEST

#define DIR_PATH	"."
#define REAL_PATH	DIR_PATH "/" "real"
#define MINE_PATH	DIR_PATH "/" "mine"

/*
** ----------------------------- Unit tests ------------------------------------
*/

void		handle_exeptions(void);
bool		run_tests(void);
bool		compare_str(char *real, char *mine, size_t length);
bool		compare_num(int64_t real, int64_t mine);

bool		get_char(struct result *res, uint32_t i, char type);
bool		get_str(struct result *res, uint32_t i, char type);
bool		get_file_fd(struct result *res, uint32_t i, char type);

bool		ut_bzero(struct unit_test *ut);
bool		ut_strcat(struct unit_test *ut);
bool		ut_is(struct unit_test *ut);
bool		ut_puts(struct unit_test *ut);

bool		ut_strlen(struct unit_test *ut);
bool		ut_memset(struct unit_test *ut);
bool		ut_memcpy(struct unit_test *ut);
bool		ut_strdup(struct unit_test *ut);

bool		ut_cat(struct unit_test *ut);

/*
** ------------------------------- Bonus ---------------------------------------
*/

bool		ut_putchar(struct unit_test *ut);
bool		ut_putchar_fd(struct unit_test *ut);
bool		ut_putstr(struct unit_test *ut);
bool		ut_putstr_fd(struct unit_test *ut);
bool		ut_memalloc(struct unit_test *ut);

/*
** --------------------------- Libfts functions --------------------------------
*/

/*
** Calling convention:
**
**	User level:	%rdi, %rsi, %rdx, %rcx, %r8, %r9
** 	Kernel level: 	%rdi, %rsi, %rdx, %r10, %r8, %r9
**
*/

void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *s1, char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);

size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);

void		ft_cat(int fd);

/*
** ------------------------------- Bonus ---------------------------------------
*/

int		ft_isspace(int c);
int		ft_isblank(int c);
int		ft_putchar(int c);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr(char *s);
int		ft_putstr_fd(char *s, int fd);
void		*ft_memalloc(size_t size);

#endif
