#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define ALPHABET_LEN 256

void	make_delta1(int *delta1, char *pat, int32_t patlen)
{
	size_t	i;

	memset(delta1, patlen, ALPHABET_LEN);
	i = 0;
	while (i < patlen - 1)
	{
		delta1[pat[i]] = patlen - 1 - i;
		++i;
	}
}

size_t	suffix_length(char *word, int wordlen, int pos)
{
	size_t	i;

	i = 0;
	while ((word[pos - i] == word[wordlen - 1 - i] && (i < pos)))
		++i;
	return (i);
}

void make_delta2(int *delta2, char *pat, int32_t patlen)
{
	size_t	p;
	size_t	last_prefix_index;
	size_t	slen;

	p = patlen - 1;
	last_prefix_index = p;
	while (p > 0)
	{
		if (!strncmp(pat, pat + p + 1, patlen - p - 1))
			last_prefix_index = p + 1;
		delta2[p] = last_prefix_index + (patlen - p - 1);
		--p;
	}
	if (!strncmp(pat, pat + p + 1, patlen - p - 1))
		last_prefix_index = p + 1;
	delta2[p] = last_prefix_index + (patlen - p - 1);
	while (p < patlen - 1)
	{
		slen = suffix_length(pat, patlen, p);
		if (pat[p - slen] != pat[patlen - slen - 1])
			delta2[patlen - slen - 1] = patlen - 1 - p + slen;
		++p;
	}
}

char	*boyer_moore(char *string, uint32_t stringlen, char *pat, uint32_t patlen)
{
	int	i;
	int	j;
	int	delta1[ALPHABET_LEN];
	int	*delta2;

	if (patlen == 0)
		return (string);
	delta2 = (int *)malloc(patlen * sizeof(int)); //switch back to bruteforce if fail
	make_delta1(delta1, pat, patlen);
	make_delta2(delta2, pat, patlen);
	i = patlen - 1;
	while (i < stringlen)
	{
		j = patlen - 1;
		while (j >= 0 && (string[i] == pat[j]))
		{
			--i;
			--j;
		}
		if (j < 0)
		{
			free(delta2);
			return (string + i + 1);
		}
		i += delta1[string[i]] > delta2[j] ? delta1[string[i]] : delta2[j];
	}
	free(delta2);
	return (NULL);
}

int	main(void)
{
	printf("%s\n", boyer_moore("HelloHelloHelloHelloDHelloWorldHelloHelloWorld!!!",49, "HelloHelloWorld",  15));
	return (0);
}
