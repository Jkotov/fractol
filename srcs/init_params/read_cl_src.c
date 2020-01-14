/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cl_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:56:20 by epainter          #+#    #+#             */
/*   Updated: 2019/12/30 22:02:46 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 4096

size_t	read_cl_src(char **src, char *file_name)
{
	int		fd;
	size_t	source_size;
	char	*source_str;
	char	*buf;
	int		ret;

	if (!(buf = malloc(sizeof(char) * (BUFFSIZE + 1))))
		exit(-1);
	fd = open(file_name, O_RDONLY);
	if (!(source_str = ft_strnew(0)))
		exit(-1);
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = '\0';
		source_str = ft_strjoinfree(&source_str, &buf, 1);
	}
	free(buf);
	source_size = ft_strlen(source_str);
	*src = source_str;
	return (source_size);
}
