/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/08 15:46:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

extern int g_malloc_inject;

int		error()
{
	ft_putstr("error\n");
	return (0);
}

int		valid_1(char *str, int bytes)
{
	int n;
	int i;
	int count1;
	int count2;

	n = 0;
	while (n < bytes)
	{
		i = -1;
		count1 = 0;
		count2 = 0;
		while (++i < 19)
		{
			if (str[n + i] == '#')
				count1++;
			if (str[n + i] == '.')
				count2++;
		}
		if (count1 != 4)
			return (1);
		if (count2 != 12)
			return (1);
		n += 21;
	}
	return (0);
}

int		valid_2(char *str, int bytes)
{
	int n;
	int i;
	int k;

	n = 0;
	while (n < bytes)
	{
		i = 0;
		while (i <= 15)
		{
			k = n + i;
			if (!V1(str[k]) || !V1(str[k + 1]) || !V1(str[k + 2])
					|| !V1(str[k + 3]) || !V2(str[k + 4]))
				return (1);
			i += 5;
		}
		n += 21;
	}
	return (0);
}

int		valid_0(char *str, int bytes)
{
	if (valid_1(str, bytes) == 1)
		return (1);
	printf("Valid1 PASS\n");
	//if (valid_2(str, bytes) == 1)
	//	return (1);
	//printf("Valid2 PASS\n");
	while (*str)
	{
		if (!V3(*str))
			return (1);
		str++;
	}
	printf("Valid3 PASS\n");
	return (0);
}

void	tmp_print(char **tbl, int blocks)
{
	int i;
	i = -1;
	while (++i <  blocks)
		printf("%s\n", tbl[i]);
}

int		main(int av, char **ac)
{
	size_t	fd;
	size_t	rd;
	char	*str;
	char	**tbl;
	size_t	blocks;

//	g_malloc_inject = 50;

	CHK1(av != 2, ft_putstr("usage: ./fillit source_file\n"), 0);
	CHK1((str = (char*)malloc(sizeof(char) * BUFFER_SIZE)) == NULL,
		 ft_putstr("error\n"), 0);
	ft_bzero((void *)str, BUFFER_SIZE);
	if ((fd = open(ac[1], O_RDONLY)) != 0)
	{
		CHK2((rd = read(fd, str, BUFFER_SIZE)) < 0, error(), free(str), 0);
		CHK2(str[545] != 0, error(), free(str), 0);
		CHK2(valid_0(str, rd) == 1, error(), free(str), 0);
		blocks = (rd + 1) / 21;
		change_end(&str, rd);
		CHK2((tbl = ft_strsplit(str, '@')) == 0, error(), free(str), 0);
		trim_newline(tbl);
		trim_block(tbl);
		CHK3(valid_pattern(tbl, blocks) == 1, error(), ft_tbldel(tbl), free(str), 0);
		printf("Valid4 PASS\n");
		rename_block(tbl);
		tmp_print(tbl, blocks);
		solve(tbl, blocks);
		ft_tbldel(tbl);
		free(str);
	}
	else
	{
		free(str);
		error();
	}
	return (0);
}
