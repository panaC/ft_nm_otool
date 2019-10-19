/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:59:48 by pleroux           #+#    #+#             */
/*   Updated: 2019/10/19 13:39:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ft_printf.h>
#include "common.h"

int		free_file(int fd, void *ptr, size_t size, char *path)
{
	if (munmap(ptr, size) < 0)
	{
		ft_printf("can't desalocate memory mapping of %s\n", path);
		return (1);
	}
	if (close(fd) < 0)
	{
		ft_printf("can't close %s\n", path);
		return (1);
	}
	return (0);
}

int		open_fd(char *path, struct stat *buf)
{
	int			fd;

	if (path && (fd = open(path, O_RDONLY)))
	{
		if (fstat(fd, buf) > -1)
		{
			s_size(buf->st_size);
			return (fd);
		}
		else
		{
			ft_printf("can't get info on %s\n", path);
			close(fd);
		}
	}
	else
	{
		ft_printf("can't open %s\n", path);
	}
	return (-1);
}

int				open_file(char *path, int (*run)(void*))
{
	int			fd;
	struct stat	buf;
	void		*ptr;
	int			ret;


	ret = EXIT_FAILURE;
	if ((fd = open_fd(path, &buf)) > -1)
	{
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
				!= MAP_FAILED)
		{
			if (run)
				ret = run(ptr);
			if (free_file(fd, ptr, buf.st_size, path) == EXIT_FAILURE)
				ret = EXIT_FAILURE;
		}
		else
		{
			ft_printf("can't read %s\n", path);
			close(fd);
		}
	}
	return (ret);
}


