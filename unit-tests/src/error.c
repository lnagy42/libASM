
#include "include.h"

static void		print_backtrace(void)
{
	char			*array[16];
	size_t			size;

	size = backtrace((void**)array, 16);
	printf("Obtained %zu stack frame:\n", size);
	backtrace_symbols_fd((void*const*)(&array[1]), size, 0);
}

static void		handle_sigsegv(int sig)
{
	printf("\n\e[1;31m[segmentation fault]:\n\n");
	print_backtrace();
	printf("\n\e[0m");
	exit(EXIT_FAILURE);
}

static void		handle_sigbus(int sig)
{
	printf("\n\e[1;31m[bus error]:\n\n");
	print_backtrace();
	printf("\n\e[0m");
	exit(EXIT_FAILURE);
}

static void		handle_sigabrt(int sig)
{
	printf("\n\e[1;31m[abort]:\n\n");
	print_backtrace();
	printf("\n\e[0m");
	exit(EXIT_FAILURE);
}

void			handle_exeptions(void)
{
	signal(SIGSEGV, handle_sigsegv);
	signal(SIGABRT, handle_sigabrt);
	signal(SIGBUS, handle_sigbus);
}
