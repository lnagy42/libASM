#include "../libfts.h"
#include <stdlib.h>
#include <string.h>

#define SIZE    64

int main()
{
//     char    *real;
//     char    *mine;

//     real = malloc(SIZE);
//     mine = malloc(SIZE);
//     real[SIZE] = 0;
//     mine[SIZE] = 0;

//     memset(real, '5', SIZE - 1);
//     memset(mine, '5', SIZE - 1);

//     printf("before:\nreal: |%s|\nmine: |%s|\n", (char*)real, (char*)mine);

//     bzero(real, SIZE - 1);
//     ft_bzero(mine, SIZE - 1);

//     printf("after:\n");

//     printf("real: |");
//     write(1, real, SIZE);
//     printf("|\n");

//     printf("mine: |");
//     write(1, real, SIZE);
//     printf("|\n");

//     free(real);
//     free(mine);

// __________________FUNCTION__________________
//     char    *s2 = "tu veux voir mon chat?";
//     char    *s1 = malloc(4096);

//     bzero(s1, 4096);
//     memcpy(s1, "Coucou, ", 8);

//     printf("mine: %s\n", ft_strcat(s1, s2));
//     printf("real: %s\n", strcat(s1, s2));

// __________________FUNCTION__________________
//     char *s = "plop";

//     printf("\nREAL STRLEN: %zu\n", strlen(s));
    // printf("\nMY FT_STRLEN: %zu\n", ft_strlen(s));
    // __________________FUNCTION__________________
//     printf("real : %d\n", isalpha('0'));
    // printf("me : %d\n", ft_isalpha('0'));
    // __________________FUNCTION__________________
//     printf("real : %d\n", isdigit('a'));
//     printf("me : %d\n", ft_isdigit('a'));
//     printf("real : %d\n", isdigit(2));
//     printf("me : %d\n", ft_isdigit(2));
//     printf("real : %d\n", isdigit('1'));
    // printf("me : %d\n", ft_isdigit('1'));
    // __________________FUNCTION__________________
//     printf("real : %d\n", isalnum('a'));
//     printf("me : %d\n", ft_isalnum('a'));
//     printf("real : %d\n", isalnum('Q'));
//     printf("me : %d\n", ft_isalnum('Q'));
//     printf("real : %d\n", isalnum(2));
//     printf("me : %d\n", ft_isalnum(2));
//     printf("real : %d\n", isalnum('1'));
//     printf("me : %d\n", ft_isalnum('1'));
//     printf("real : %d\n", isalnum('+'));
//     printf("me : %d\n", ft_isalnum('+'));
//     printf("real : %d\n", isalnum(' '));
    // printf("me : %d\n", ft_isalnum(' '));
    // __________________FUNCTION__________________
//     printf("real : %d\n", isascii('a'));
//     printf("me : %d\n", ft_isascii('a'));
//     printf("real : %d\n", isascii('Q'));
//     printf("me : %d\n", ft_isascii('Q'));
//     printf("real : %d\n", isascii(2));
//     printf("me : %d\n", ft_isascii(2));
//     printf("real : %d\n", isascii(-1));
//     printf("me : %d\n", ft_isascii(-1));
//     printf("real : %d\n", isascii('1'));
//     printf("me : %d\n", ft_isascii('1'));
//     printf("real : %d\n", isascii(128));
//     printf("me : %d\n", ft_isascii(128));
//     printf("real : %d\n", isascii(' '));
    // printf("me : %d\n", ft_isascii(' '));
    // __________________FUNCTION__________________
//     printf("real : %d\n", isprint('a'));
//     printf("me : %d\n", ft_isprint('a'));
//     printf("real : %d\n", isprint('Q'));
//     printf("me : %d\n", ft_isprint('Q'));
//     printf("real 2: %d\n", isprint(2));
//     printf("me : %d\n", ft_isprint(2));
//     printf("real -1: %d\n", isprint(-1));
//     printf("me : %d\n", ft_isprint(-1));
//     printf("real : %d\n", isprint('1'));
//     printf("me : %d\n", ft_isprint('1'));
//     printf("real : %d\n", isprint(128));
//     printf("me : %d\n", ft_isprint(128));
//     printf("real : %d\n", isprint(' '));
    // printf("me : %d\n", ft_isprint(' '));
    // __________________FUNCTION__________________}
// int main()
// {
//     printf("real vide: %d\n", puts(""));
//     printf("real vide: %d\n", puts("oki"));
//     printf("mine vide: %d\n", ft_puts(""));
//     printf("real lol: %d\n", puts("lol"));
//     printf("mine lol: %d\n", ft_puts("lol"));
//     // printf("real "": %d\n", puts(1));
    // printf("mine "": %d\n", ft_puts(1));
    // __________________FUNCTION__________________}
// int main()
// {
//     printf("real M: %c\n", tolower('M'));
//     printf("mine M: %c\n", ft_tolower('M'));
//     printf("real m: %c\n", tolower('m'));
//     printf("mine m: %c\n", ft_tolower('m'));
//     printf("real -: %c\n", tolower('-'));
    // printf("mine -: %c\n", ft_tolower('-'));
    // __________________FUNCTION__________________
//     char *s1 = strdup("lolcat");
//     char *s2 = strdup("lolcat");

//     printf("real : %s\n", memset(s1, '4', strlen(s1)));
//     printf("mine : %s\n", ft_memset(s2, '4', ft_strlen(s2)));
//     printf("real : %s\n", memset(s1, 'c', strlen(s1)));
//     printf("mine : %s\n", ft_memset(s2, 'c', ft_strlen(s2)));

//     char *s1 = strdup("bonsoir");
//     char *s2 = strdup("salut!!");

//     char *s3 = strdup("bonsoir");
//     char *s4 = strdup("salut!!");
    
//     printf("real : %s\n", memcpy(s1, s2, strlen(s1)));
//     printf("mine : %s\n", ft_memcpy(s3, s4, ft_strlen(s4)));

//     char    *copy = NULL;
//     char    *r = malloc(strlen(copy)) + 1;
//     char    *m = malloc(strlen(copy)) + 1;
//     bzero(r, strlen(copy));
//     bzero(m, strlen(copy));
//     printf("real: %s\n", memcpy(r, copy, strlen(copy)));
//     printf("mine: %s\n", ft_memcpy(m, copy, strlen(copy)));

    // printf("mine : %s\n", ft_memcpy(s3, s4, ft_strlen(s4)));
    // printf("real : %s\n", memcpy(s1, s2, strlen(s1)));
// __________________FUNCTION____________
    // char *s1 = "bonsoir";
    // char *s2 = "salut!!";
    
    // printf("real : %s\n", strdup(s1));
    // printf("mine : %s\n", ft_strdup(s2));

    // ___________________FUNCTION_______________
    //  #include <fcntl.h>
    // int fd = open("hello.s", O_RDONLY);
    // printf("fd : %d\n", fd);
    // printf("cat : %d\n", ft_cat(fd));
    // printf("cat : %d\n", ft_cat(fd));
    // printf("cat : %d\n", ft_cat(fd));
    // ft_cat(fd);
    // close(fd);

    // ___________________FUNCTION__________
    putchar('\n');
    ft_putchar('c');
    // ft_putstr("SOLITUDE");
    ft_putchar_fd('K', 1);
    putchar('\n');
    return 0;
}