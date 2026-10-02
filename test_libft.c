#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <bsd/string.h>

// Part 1: Libc functions
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

	assert(ft_atoi("-7906324293082309") == atoi("-7906324293082309"));
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

// Part 2: Additional functions
void	test_substr()
{
	char	*sub;

	sub = ft_substr("test", 1, 2);
	if (!sub)
		exit(1);
	assert(strcmp(sub, "es") == 0);
	free(sub);

	sub = ft_substr("test", 1, 20);
	if (!sub)
		exit(1);
	assert(strcmp(sub, "est") == 0);
	free(sub);

	sub = ft_substr("test", 0, 0);
	if (!sub)
		exit(1);
	assert(strcmp(sub, "") == 0);
	free(sub);

	sub = ft_substr("", 6, 20);
	if (!sub)
		exit(1);
	assert(strcmp(sub, "") == 0);
	free(sub);

	sub = ft_substr(NULL, 10, 10);
	assert(sub == NULL);
}

void	test_strjoin()
{
	char	*joined;

	joined = ft_strjoin("hello", "world");
	if (!joined)
		exit(1);
	assert(strcmp(joined, "helloworld") == 0);
	free(joined);

	joined = ft_strjoin("", "world");
	if (!joined)
		exit(1);
	assert(strcmp(joined, "world") == 0);
	free(joined);

	joined = ft_strjoin("hello", "");
	if (!joined)
		exit(1);
	assert(strcmp(joined, "hello") == 0);
	free(joined);

	joined = ft_strjoin("", "");
	if (!joined)
		exit(1);
	assert(strcmp(joined, "") == 0);
	free(joined);

	joined = ft_strjoin("hello", NULL);
	if (!joined)
		exit(1);
	assert(strcmp(joined, "hello") == 0);
	free(joined);

	joined = ft_strjoin(NULL, "world");
	if (!joined)
		exit(1);
	assert(strcmp(joined, "world") == 0);
	free(joined);

	joined = ft_strjoin(NULL, NULL);
	assert(joined == NULL);
}

void	test_strtrim()
{
	char	*trimmed;

	trimmed = ft_strtrim("aaaatestaaa", "a");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim("abcdtestdbc", "bacd");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim("test", "80adwdio");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim("   test  ", "es ");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim("", "es ");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "") == 0);
	free(trimmed);

	trimmed = ft_strtrim("test", "");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim("", "");
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "") == 0);
	free(trimmed);

	trimmed = ft_strtrim("test", NULL);
	if (!trimmed)
		exit(1);
	assert(strcmp(trimmed, "test") == 0);
	free(trimmed);

	trimmed = ft_strtrim(NULL, "abcd");
	assert(trimmed == NULL);

	trimmed = ft_strtrim(NULL, NULL);
	assert(trimmed == NULL);
}

void	test_split()
{
	char	**strs;

	strs = ft_split("zero one two", ' ');
	if (!strs)
		exit(1);
	assert(strcmp(strs[0], "zero") == 0);
	assert(strcmp(strs[1], "one") == 0);
	assert(strcmp(strs[2], "two") == 0);
	assert(strs[3] == NULL);
	free(strs[0]);
	free(strs[1]);
	free(strs[2]);
	free(strs);

	strs = ft_split("Hello world!", 'a');
	if (!strs)
		exit(1);
	assert(strcmp(strs[0], "Hello world!") == 0);
	assert(strs[1] == NULL);
	free(strs[0]);
	free(strs);

	strs = ft_split("Hello world!", '\0');
	if (!strs)
		exit(1);
	assert(strcmp(strs[0], "Hello world!") == 0);
	assert(strs[1] == NULL);
	free(strs[0]);
	free(strs);

	strs = ft_split("", 'a');
	if (!strs)
		exit(1);
	assert(strs[0] == NULL);
	free(strs);

	strs = ft_split(NULL, 'a');
	assert(strs == NULL);
}

void	test_itoa()
{
	char	*str;

	str = ft_itoa(25);
	assert(strcmp(str, "25") == 0);
	free(str);

	str = ft_itoa(-593);
	assert(strcmp(str, "-593") == 0);
	free(str);

	str = ft_itoa(0);
	assert(strcmp(str, "0") == 0);
	free(str);

	str = ft_itoa(2147483647);
	assert(strcmp(str, "2147483647") == 0);
	free(str);

	str = ft_itoa(-2147483648);
	assert(strcmp(str, "-2147483648") == 0);
	free(str);
}

char	char_func(unsigned int i, char c)
{
	return (c + i);
}

void	test_strmapi()
{
	char	*mapped;

	mapped = ft_strmapi("test", char_func);
	assert(strcmp(mapped, "tfuw") == 0);
	free(mapped);

	mapped = ft_strmapi("", char_func);
	assert(strcmp(mapped, "") == 0);
	free(mapped);

	mapped = ft_strmapi("test", NULL);
	assert(strcmp(mapped, "test") == 0);
	free(mapped);

	mapped = ft_strmapi(NULL, char_func);
	assert(mapped == NULL);

	mapped = ft_strmapi(NULL, NULL);
	assert(mapped == NULL);
}

void	void_func(unsigned int i, char *c)
{
	*c += i;
}

void	test_striteri()
{
	char	*test = strdup("test");
	char	*empty = strdup("");

	ft_striteri(test, void_func);
	assert(strcmp(test, "tfuw") == 0);

	ft_striteri(empty, void_func);
	assert(strcmp(empty, "") == 0);

	ft_striteri(test, NULL);
	assert(strcmp(test, "tfuw") == 0);

	ft_striteri(NULL, void_func);

	ft_striteri(NULL, NULL);

	free(test);
	free(empty);
}

void	test_putchar_fd()
{
	int		BUFFER_SIZE = 16;
	int		fd[2];
	int		bytes_read;
	char	buff[BUFFER_SIZE];

	pipe(fd);

	ft_putchar_fd('a', fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 1);
	assert(memcmp(buff, "a", 1) == 0);

	ft_putchar_fd('t', fd[1]);
	ft_putchar_fd('e', fd[1]);
	ft_putchar_fd('s', fd[1]);
	ft_putchar_fd('t', fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 4);
	assert(memcmp(buff, "test", 4) == 0);

	ft_putchar_fd('t', fd[1]);
	ft_putchar_fd('e', fd[1]);
	ft_putchar_fd('s', fd[1]);
	ft_putchar_fd('t', fd[1]);
	ft_putchar_fd('\0', fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 5);
	assert(strcmp(buff, "test") == 0);

	close(fd[0]);
	close(fd[1]);
}

void	test_putstr_fd()
{
	int		BUFFER_SIZE = 16;
	int		fd[2];
	int		bytes_read;
	char	buff[BUFFER_SIZE];

	pipe(fd);

	ft_putstr_fd("test", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 4);
	assert(memcmp(buff, "test", 4) == 0);

	ft_putstr_fd("test", fd[1]);
	ft_putstr_fd("ing", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 7);
	assert(memcmp(buff, "testing", 7) == 0);

	ft_putstr_fd("", fd[1]);
	// Empty pipe would hang forever
	ft_putstr_fd("a", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 1);
	assert(memcmp(buff, "a", 1) == 0);

	ft_putstr_fd(NULL, fd[1]);
	// Empty pipe would hang forever
	ft_putstr_fd("b", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 1);
	assert(memcmp(buff, "b", 1) == 0);

	close(fd[0]);
	close(fd[1]);
}

void	test_putendl_fd()
{
	int		BUFFER_SIZE = 16;
	int		fd[2];
	int		bytes_read;
	char	buff[BUFFER_SIZE];

	pipe(fd);

	ft_putendl_fd("test", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 5);
	assert(memcmp(buff, "test\n", 5) == 0);

	ft_putendl_fd("test", fd[1]);
	ft_putendl_fd("ing", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 9);
	assert(memcmp(buff, "test\ning\n", 9) == 0);

	ft_putendl_fd("", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 1);
	assert(memcmp(buff, "\n", 1) == 0);

	ft_putendl_fd(NULL, fd[1]);
	// Empty pipe would hang forever
	ft_putendl_fd("a", fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 2);
	assert(memcmp(buff, "a\n", 2) == 0);

	close(fd[0]);
	close(fd[1]);
}

void	test_putnbr_fd()
{
	int		BUFFER_SIZE = 16;
	int		fd[2];
	int		bytes_read;
	char	buff[BUFFER_SIZE];

	pipe(fd);

	ft_putnbr_fd(34, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 2);
	assert(memcmp(buff, "34", 2) == 0);

	ft_putnbr_fd(-1056, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 5);
	assert(memcmp(buff, "-1056", 5) == 0);

	ft_putnbr_fd(0, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 1);
	assert(memcmp(buff, "0", 1) == 0);

	ft_putnbr_fd(2147483647, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 10);
	assert(memcmp(buff, "2147483647", 10) == 0);

	ft_putnbr_fd(-2147483648, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 11);
	assert(memcmp(buff, "-2147483648", 11) == 0);

	ft_putnbr_fd(805, fd[1]);
	ft_putnbr_fd(-154, fd[1]);
	bytes_read = read(fd[0], buff, BUFFER_SIZE);
	assert(bytes_read == 7);
	assert(memcmp(buff, "805-154", 7) == 0);

	close(fd[0]);
	close(fd[1]);
}

void	test_lstnew()
{
	t_list	*new;
	char	*str = strdup("test");

	new = ft_lstnew(str);
	if (!new)
		exit(1);
	assert(new->content == str);
	assert(strcmp(new->content, "test") == 0);
	assert(new->next == NULL);

	free(new);

	new = ft_lstnew(NULL);
	if (!new)
		exit(1);
	assert(new->content == NULL);
	assert(new->next == NULL);
	free(new);

	free(str);
}

void	test_lstadd_front()
{
	t_list	*lst = NULL;

	t_list	*first = ft_lstnew(NULL);
	ft_lstadd_front(&lst, first);
	assert(lst == first);
	assert(lst->next == NULL);

	ft_lstadd_front(&lst, NULL);
	assert(lst == first);
	assert(lst->next == NULL);

	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_front(&lst, second);
	assert(lst == second);
	assert(lst->next == first);

	free(first);
	free(second);
}

void	test_lstsize()
{
	t_list	*lst = NULL;

	assert(ft_lstsize(lst) == 0);

	ft_lstadd_front(&lst, ft_lstnew(NULL));
	assert(ft_lstsize(lst) == 1);

	ft_lstadd_front(&lst, ft_lstnew(NULL));
	assert(ft_lstsize(lst) == 2);

	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	assert(ft_lstsize(lst) == 5);

	t_list	*next;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

void	test_lstlast()
{
	t_list	*lst = NULL;

	assert(ft_lstlast(lst) == NULL);

	t_list	*first = ft_lstnew(NULL);
	ft_lstadd_front(&lst, first);
	assert(ft_lstlast(lst) == first);

	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	assert(ft_lstlast(lst) == first);

	t_list	*next;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

void	test_lstadd_back()
{
	t_list	*lst = NULL;

	t_list	*first = ft_lstnew(NULL);
	ft_lstadd_back(&lst, first);
	assert(lst == first);

	t_list	*second = ft_lstnew(NULL);
	ft_lstadd_back(&lst, second);
	assert(lst == first);
	assert(lst->next == second);
	assert(lst->next->next == NULL);

	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, NULL);
	t_list	*third = ft_lstnew(NULL);
	ft_lstadd_back(&lst, third);
	assert(lst == first);
	assert(lst->next == second);
	assert(ft_lstlast(lst) == third);

	t_list	*next;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

void	set_to_zero(void *content)
{
	*(int *)content = 0;
}

void	test_lstdelone()
{
	int	content1 = 1;
	t_list	*first = ft_lstnew(&content1);
	int content2 = 2;
	t_list	*second = ft_lstnew(&content2);

	ft_lstdelone(first, NULL);
	ft_lstdelone(NULL, set_to_zero);
	ft_lstdelone(NULL, NULL);

	ft_lstadd_back(&first, second);
	ft_lstdelone(first, set_to_zero);
	assert(content1 == 0);
	assert(*(int *)second->content == 2);

	free(second);
}

void	test_lstclear()
{
	t_list	*lst = NULL;
	int	content1 = 1;
	t_list	*first = ft_lstnew(&content1);
	int content2 = 2;
	t_list	*second = ft_lstnew(&content2);
	int content3 = 3;
	t_list	*third = ft_lstnew(&content3);

	ft_lstclear(&first, NULL);
	ft_lstclear(NULL, set_to_zero);
	ft_lstclear(NULL, NULL);

	ft_lstadd_back(&lst, first);
	ft_lstadd_back(&lst, second);
	ft_lstadd_back(&lst, third);
	ft_lstclear(&lst, set_to_zero);
	assert(content1 == 0);
	assert(content2 == 0);
	assert(content3 == 0);
}

void	square(void *i)
{
	int	*p = i;
	*p *= *p;
}

void	test_lstiter()
{
	t_list	*lst = NULL;
	t_list	*cur;
	int		i1 = 1;
	int		i2 = 2;
	int		i3 = 3;
	ft_lstadd_back(&lst, ft_lstnew(&i1));
	ft_lstadd_back(&lst, ft_lstnew(&i2));
	ft_lstadd_back(&lst, ft_lstnew(&i3));

	ft_lstiter(lst, square);
	cur = lst;
	assert(*(int *)cur->content == 1);
	cur = cur->next;
	assert(*(int *)cur->content == 4);
	cur = cur->next;
	assert(*(int *)cur->content == 9);

	ft_lstclear(&lst, set_to_zero);
}

void	*square2(void *i)
{
	int	*p = i;
	int *r = malloc(sizeof(int));
	*r = *p * *p;
	return ((void *)r);
}

void	test_lstmap()
{
	t_list	*lst = NULL;
	t_list	*cur;
	int		i1 = 1;
	int		i2 = 2;
	int		i3 = 3;
	ft_lstadd_back(&lst, ft_lstnew(&i1));
	ft_lstadd_back(&lst, ft_lstnew(&i2));
	ft_lstadd_back(&lst, ft_lstnew(&i3));

	t_list *mapped = ft_lstmap(lst, square2, NULL);
	cur = mapped;
	assert(*(int *)cur->content == 1);
	cur = cur->next;
	assert(*(int *)cur->content == 4);
	cur = cur->next;
	assert(*(int *)cur->content == 9);

	ft_lstclear(&lst, set_to_zero);
	ft_lstclear(&mapped, free);
}

int	main(void)
{
	printf("\n");
	printf("\n");
	printf("Part 1: Libc functions\n");
	printf("\n");

	test_isalpha();
	printf("ft_isalpha:\t\tOK\n");

	test_isdigit();
	printf("ft_isdigit:\t\tOK\n");

	test_isalnum();
	printf("ft_isalnum:\t\tOK\n");

	test_isascii();
	printf("ft_isascii:\t\tOK\n");

	test_isprint();
	printf("ft_isprint:\t\tOK\n");

	test_strlen();
	printf("ft_strlen:\t\tOK\n");

	test_memset();
	printf("ft_memset:\t\tOK\n");

	test_bzero();
	printf("ft_bzero:\t\tOK\n");

	test_memcpy();
	printf("ft_memcpy:\t\tOK\n");

	test_memmove();
	printf("ft_memmove:\t\tOK\n");

	test_strlcpy();
	printf("ft_strlcpy:\t\tOK\n");

	test_strlcat();
	printf("ft_strlcat:\t\tOK\n");

	test_toupper();
	printf("ft_toupper:\t\tOK\n");

	test_tolower();
	printf("ft_tolower:\t\tOK\n");

	test_strchr();
	printf("ft_strchr:\t\tOK\n");

	test_strrchr();
	printf("ft_strrchr:\t\tOK\n");

	test_strncmp();
	printf("ft_strncmp:\t\tOK\n");

	test_memchr();
	printf("ft_memchr:\t\tOK\n");

	test_memcmp();
	printf("ft_memcmp:\t\tOK\n");

	test_strnstr();
	printf("ft_strnstr:\t\tOK\n");

	test_atoi();
	printf("ft_atoi:\t\tOK\n");

	test_calloc();
	printf("ft_calloc:\t\tOK\n");

	test_strdup();
	printf("ft_strdup:\t\tOK\n");

	printf("\n");
	printf("\tPart 1\tOK\n");

	printf("\n");
	printf("\n");
	printf("\n");
	printf("Part 2: Additional functions\n");
	printf("\n");

	test_substr();
	printf("ft_substr:\t\tOK\n");

	test_strjoin();
	printf("ft_strjoin:\t\tOK\n");

	test_strtrim();
	printf("ft_strtrim:\t\tOK\n");

	test_split();
	printf("ft_split:\t\tOK\n");

	test_itoa();
	printf("ft_itoa:\t\tOK\n");

	test_strmapi();
	printf("ft_strmapi:\t\tOK\n");

	test_striteri();
	printf("ft_striteri:\t\tOK\n");

	test_putchar_fd();
	printf("ft_putchar_fd:\t\tOK\n");

	test_putstr_fd();
	printf("ft_putstr_fd:\t\tOK\n");

	test_putendl_fd();
	printf("ft_putendl_fd:\t\tOK\n");

	test_putnbr_fd();
	printf("ft_putnbr_fd:\t\tOK\n");

	printf("\n");
	printf("\tPart 2\tOK\n");

	printf("\n");
	printf("\n");
	printf("\n");
	printf("Part 3: Linked list\n");
	printf("\n");

	test_lstnew();
	printf("ft_lstnew:\t\tOK\n");

	test_lstadd_front();
	printf("ft_lstadd_front:\tOK\n");

	test_lstsize();
	printf("ft_lstsize:\t\tOK\n");

	test_lstlast();
	printf("ft_lstlast:\t\tOK\n");

	test_lstadd_back();
	printf("ft_lstadd_back:\t\tOK\n");

	test_lstdelone();
	printf("ft_lstdelone:\t\tOK\n");

	test_lstclear();
	printf("ft_lstclear:\t\tOK\n");

	test_lstiter();
	printf("ft_lstiter:\t\tOK\n");

	test_lstmap();
	printf("ft_lstmap:\t\tOK\n");

	printf("\n");
	printf("\tPart 3\tOK\n");

	printf("\n");
	printf("\n");
	printf(	"       ::::::::  :::    ::: \n"
			"     :+:    :+: :+:   :+:   \n"
			"    +:+    +:+ +:+  +:+     \n"
			"   +#+    +:+ +#++:++       \n"
			"  +#+    +#+ +#+  +#+       \n"
			" #+#    #+# #+#   #+#       \n"
			" ########  ###    ###       \n\n");
	printf("\n");

	return (0);
}
