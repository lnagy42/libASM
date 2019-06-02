#ifndef LIBFTS_H
# define LIBFTS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	        ft_bzero(void *s, size_t n);
char            *ft_strcat(char *dest, const char *src);
unsigned long   ft_strlen(char *s);
int             ft_isalpha(int i);
int             ft_isdigit(int i);
int             ft_isalnum(int i);
int             ft_isascii(int i);
int             ft_isprint(int i);
int             ft_tolower(int i);
int             ft_toupper(int i);
int             ft_puts(char *s);
int             ft_putchar(int c);
int             ft_putchar_fd(int c, int fd);
int             ft_putstr(char *s);
void            *ft_memset (void *s, int c, size_t n);
void            *ft_memcpy (void *dest, void *src, size_t n);
char        	*ft_strdup(const char *s1);
int             ft_cat(int fd);
#endif