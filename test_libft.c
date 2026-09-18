#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <bsd/string.h>

void	test_isalpha()
{
	for (int c = -1; c < 256; c++)
		assert(ft_isalpha(c) == !!isalpha(c));
}

void	test_isdigit()
{
	for (int c = -1; c < 256; c++)
		assert(ft_isdigit(c) == !!isdigit(c));
}

void	test_isalnum()
{
	for (int c = -1; c < 256; c++)
		assert(ft_isalnum(c) == !!isalnum(c));
}

void	test_isascii()
{
	for (int c = -1; c < 256; c++)
		assert(ft_isascii(c) == !!isascii(c));
}

void	test_isprint()
{
	for (int c = -1; c < 256; c++)
		assert(ft_isprint(c) == !!isprint(c));
}

void	test_strlen()
{
	char	*str_neg = strdup("Test with negative values");
	if (!str_neg)
		exit(1);
	str_neg[5] = -2;
	str_neg[10] = -101;

	assert(ft_strlen("Hello world!") == strlen("Hello world!"));
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen(str_neg) == strlen(str_neg));

	free(str_neg);
}

void	test_memset()
{
	char	buff_ft[1000];
	char	buff_libc[1000];

	ft_memset(buff_ft, 'X', 1000);
	memset(buff_libc, 'X', 1000);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
	ft_memset(buff_ft + 200, 0, 800);
	memset(buff_libc + 200, 0, 800);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
	ft_memset(buff_ft + 900, 255, 100);
	memset(buff_libc + 900, 255, 100);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
}

void	test_bzero()
{
	char	buff_ft[1000];
	char	buff_libc[1000];

	ft_bzero(buff_ft, 1000);
	bzero(buff_libc, 1000);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
}

void	test_memcpy()
{
	char	buff_src[1000];
	char	buff_ft[1000];
	char	buff_libc[1000];
	for (int i = 0; i < 1000; i++)
		buff_src[i] = i * i; // fill with various chars

	ft_memcpy(buff_ft + 500, buff_src, 500);
	ft_memcpy(buff_ft, buff_src + 500, 500);
	memcpy(buff_libc + 500, buff_src, 500);
	memcpy(buff_libc, buff_src + 500, 500);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
	ft_memcpy(buff_ft, buff_src, 0);
	memcpy(buff_libc, buff_src, 0);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
	ft_memcpy(buff_ft, buff_src, 1);
	memcpy(buff_libc, buff_src, 1);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
}

void	test_memmove()
{
	char	buff_ft[1000];
	char	buff_libc[1000];
	for (int i = 0; i < 1000; i++)
		buff_ft[i] = buff_libc[i] = i * i; // fill both with various chars

	ft_memmove(buff_ft, buff_ft + 250, 750);
	memmove(buff_libc, buff_libc + 250, 750);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
	ft_memmove(buff_ft + 300, buff_ft, 700);
	memmove(buff_libc + 300, buff_libc, 700);
	assert(memcmp(buff_ft, buff_libc, 1000) == 0);
}

void	test_strlcpy()
{
	char	*str_neg = strdup("Test with negative values");
	if (!str_neg)
		exit(1);
	str_neg[5] = -2;
	str_neg[10] = -101;
	char	*str_ft = malloc(60);
	if (!str_ft)
		exit(1);
	char	*str_libc = malloc(60);
	if (!str_libc)
		exit(1);
	size_t	ret_ft;
	size_t	ret_libc;

	ret_ft = ft_strlcpy(str_ft, "hello", 6);
	ret_libc = strlcpy(str_libc, "hello", 6);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcpy(str_ft, " world", 60);
	ret_libc = strlcpy(str_libc, " world", 60);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcpy(str_ft, "another", 0);
	ret_libc = strlcpy(str_libc, "another", 0);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcpy(str_ft, "", 40);
	ret_libc = strlcpy(str_libc, "", 40);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcpy(str_ft, str_neg, 60);
	ret_libc = strlcpy(str_libc, str_neg, 60);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);

	free(str_neg);
	free(str_ft);
	free(str_libc);
}

void	test_strlcat()
{
	char	*str_neg = strdup("Test with negative values");
	if (!str_neg)
		exit(1);
	str_neg[5] = -2;
	str_neg[10] = -101;
	char	*str_ft = calloc(60, 1);
	if (!str_ft)
		exit(1);
	char	*str_libc = calloc(60, 1);
	if (!str_libc)
		exit(1);
	size_t	ret_ft;
	size_t	ret_libc;

	ret_ft = ft_strlcat(str_ft, "hello", 6);
	ret_libc = strlcat(str_libc, "hello", 6);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcat(str_ft, " world", 60);
	ret_libc = strlcat(str_libc, " world", 60);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcat(str_ft, " another", 0);
	ret_libc = strlcat(str_libc, " another", 0);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcat(str_ft, "", 40);
	ret_libc = strlcat(str_libc, "", 40);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcat(str_ft, str_neg, 60);
	ret_libc = strlcat(str_libc, str_neg, 60);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);
	ret_ft = ft_strlcat(str_ft, "verylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstring", 60);
	ret_libc = strlcat(str_libc, "verylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstringverylongstring", 60);
	assert(strcmp(str_ft, str_libc) == 0);
	assert(ret_ft == ret_libc);

	free(str_neg);
	free(str_ft);
	free(str_libc);
}

void	test_toupper()
{
	for (int c = -1; c < 256; c++)
		assert(ft_toupper(c) == toupper(c));
}

void	test_tolower()
{
	for (int c = -1; c < 256; c++)
		assert(ft_tolower(c) == tolower(c));
}

void	test_strchr()
{
	char	*str = "test";
	char	*empty = "";

	assert(ft_strchr(str, 't') == strchr(str, 't'));
	assert(ft_strchr(str, 's') == strchr(str, 's'));
	assert(ft_strchr(str, '0') == strchr(str, '0'));
	assert(ft_strchr(empty, 'a') == strchr(empty, 'a'));
	assert(ft_strchr(str, '\0') == strchr(str, '\0'));
}

void	test_strrchr()
{
	char	*str = "test";
	char	*empty = "";

	assert(ft_strrchr(str, 't') == strrchr(str, 't'));
	assert(ft_strrchr(str, 's') == strrchr(str, 's'));
	assert(ft_strrchr(str, '0') == strrchr(str, '0'));
	assert(ft_strrchr(empty, 'a') == strrchr(empty, 'a'));
	assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
}

void	test_strncmp()
{
	assert(ft_strncmp("test", "test", 4) == strncmp("test", "test", 4));
	assert(ft_strncmp("test", "test", 10) == strncmp("test", "test", 10));
	assert(ft_strncmp("test", "test", 0) == strncmp("test", "test", 0));
	assert(ft_strncmp("test", "test2", 6) == strncmp("test", "test2", 6));
	assert(ft_strncmp("test", "test2", 4) == strncmp("test", "test2", 4));
	assert(ft_strncmp("", "", 10) == strncmp("", "", 10));
}

void	test_memchr()
{
	char	buff[20];
	for (int i = 0; i < 20; i++)
		buff[i] = i * i; // fill with various chars

	assert(ft_memchr(buff, 100, 20) == memchr(buff, 100, 20));
	assert(ft_memchr(buff, 100, 2) == memchr(buff, 100, 2));
	assert(ft_memchr(buff, 3, 20) == memchr(buff, 3, 20));
	assert(ft_memchr(buff, '\0', 20) == memchr(buff, '\0', 20));
	assert(ft_memchr(buff, 100, 0) == memchr(buff, 100, 0));
}

void	test_memcmp()
{
	char	buff1[20];
	char	buff2[20];
	// fill both with various chars
	for (int i = 0; i < 20; i++)
		buff1[i] = buff2[i] = i * i;
	// buff2 differs from index 10
	for (int i = 10; i < 20; i++)
		buff2[i] = -i;					

	assert(ft_memcmp(buff1, buff2, 20) == memcmp(buff1, buff2, 20));
	assert(ft_memcmp(buff1, buff2, 10) == memcmp(buff1, buff2, 10));
	assert(ft_memcmp(buff1, buff2, 0) == memcmp(buff1, buff2, 0));
	assert(ft_memcmp(buff1, buff1, 20) == memcmp(buff1, buff1, 20));
}

void	test_strnstr()
{
	char	*str = "test";
	char	*empty = "";

	assert(ft_strnstr(str, "es", 50) == strnstr(str, "es", 50));
	assert(ft_strnstr(str, "es", 5) == strnstr(str, "es", 5));
	assert(ft_strnstr(str, "es", 2) == strnstr(str, "es", 2));
	assert(ft_strnstr(str, "es", 0) == strnstr(str, "es", 0));
	assert(ft_strnstr(str, "allo", 5) == strnstr(str, "allo", 5));
	assert(ft_strnstr(empty, "allo", 5) == strnstr(empty, "allo", 5));
	assert(ft_strnstr(str, "", 50) == strnstr(str, "", 50));
	assert(ft_strnstr(empty, "", 0) == strnstr(empty, "", 0));
}

void	test_atoi()
{
	assert(ft_atoi("893") == atoi("893"));
	assert(ft_atoi("-12") == atoi("-12"));
	assert(ft_atoi("   +80ee983") == atoi("   +80ee983"));
	assert(ft_atoi("--+-43") == atoi("--+-43"));
	assert(ft_atoi("hello") == atoi("hello"));
	assert(ft_atoi("") == atoi(""));
	assert(ft_atoi("   ") == atoi("   "));
	assert(ft_atoi("+") == atoi("+"));
	assert(ft_atoi("-") == atoi("-"));
	assert(ft_atoi("+-") == atoi("+-"));
	assert(ft_atoi("2147483647") == atoi("2147483647"));
	assert(ft_atoi("-2147483648") == atoi("-2147483648"));
}

void	test_calloc()
{
	char	*buff_ft;
	char	*buff_libc;

	buff_ft = ft_calloc(8, 1);
	if (!buff_ft)
		exit(1);
	buff_libc = calloc(8, 1);
	assert(memcmp(buff_ft, buff_libc, 8) == 0);
	free(buff_ft);
	free(buff_libc);
	buff_ft = ft_calloc(256, 8);
	if (!buff_ft)
		exit(1);
	buff_libc = calloc(256, 8);
	assert(memcmp(buff_ft, buff_libc, 256 * 8) == 0);
	free(buff_ft);
	free(buff_libc);
	// maximum bytes allowed should fail and return NULL
	buff_ft = ft_calloc(SIZE_MAX / 2, 1);
	buff_libc = calloc(SIZE_MAX / 2, 1);
	assert(buff_libc == NULL);
	assert(buff_ft == buff_libc);
}

void	test_strdup()
{
	char	*str_neg = strdup("Test with negative values");
	if (!str_neg)
		exit(1);
	str_neg[5] = -2;
	str_neg[10] = -101;
	char	*str_ft;
	char	*str_libc;

	str_ft = ft_strdup("hello");
	if (!str_ft)
		exit(1);
	str_libc = strdup("hello");
	assert(strcmp(str_ft, str_libc) == 0);
	free(str_ft);
	free(str_libc);
	str_ft = ft_strdup("");
	if (!str_ft)
		exit(1);
	str_libc = strdup("");
	assert(strcmp(str_ft, str_libc) == 0);
	free(str_ft);
	free(str_libc);
	str_ft = ft_strdup(str_neg);
	if (!str_ft)
		exit(1);
	str_libc = strdup(str_neg);
	assert(strcmp(str_ft, str_libc) == 0);
	free(str_ft);
	free(str_libc);
	free(str_neg);
}

int	main(void)
{
	printf("\n");
	printf(" === Part 1 - Libc functions ===\n");
	printf("|\t\t\t\t|\n");
	test_isalpha();
	printf("|\tft_isalpha:\tOK\t|\n");
	test_isdigit();
	printf("|\tft_isdigit:\tOK\t|\n");
	test_isalnum();
	printf("|\tft_isalnum:\tOK\t|\n");
	test_isascii();
	printf("|\tft_isascii:\tOK\t|\n");
	test_isprint();
	printf("|\tft_isprint:\tOK\t|\n");
	test_strlen();
	printf("|\tft_strlen:\tOK\t|\n");
	test_memset();
	printf("|\tft_memset:\tOK\t|\n");
	test_bzero();
	printf("|\tft_bzero:\tOK\t|\n");
	test_memcpy();
	printf("|\tft_memcpy:\tOK\t|\n");
	test_memmove();
	printf("|\tft_memmove:\tOK\t|\n");
	test_strlcpy();
	printf("|\tft_strlcpy:\tOK\t|\n");
	test_strlcat();
	printf("|\tft_strlcat:\tOK\t|\n");
	test_toupper();
	printf("|\tft_toupper:\tOK\t|\n");
	test_tolower();
	printf("|\tft_tolower:\tOK\t|\n");
	test_strchr();
	printf("|\tft_strchr:\tOK\t|\n");
	test_strrchr();
	printf("|\tft_strrchr:\tOK\t|\n");
	test_strncmp();
	printf("|\tft_strncmp:\tOK\t|\n");
	test_memchr();
	printf("|\tft_memchr:\tOK\t|\n");
	test_memcmp();
	printf("|\tft_memcmp:\tOK\t|\n");
	test_strnstr();
	printf("|\tft_strnstr:\tOK\t|\n");
	test_atoi();
	printf("|\tft_atoi:\tOK\t|\n");
	test_calloc();
	printf("|\tft_calloc:\tOK\t|\n");
	test_strdup();
	printf("|\tft_strdup:\tOK\t|\n");
	printf("|\t\t\t\t|\n");
	printf(" ====== Libc functions OK ======\n");
	printf("\n");
	printf("=== Part 2 - Additional functions ===\n");
	return (0);
}
