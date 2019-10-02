#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void        *open_file(char *path, void **ptr)
{
    int     fd;
    struct stat buf;

    if (path && (fd = open(path, O_RDONLY)) < 0)
    {
        ft_printf("can't open %s\n", path);
        return (1);
    }
    if (fstat(fd, &buf) < 0)
    {
        ft_printf("can't get info on %s\n", path);
        return (1);
    }
    if ((*ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
        ft_printf("can't read %s\n", path);
        return (1);
    }
    return (0);
}

void        *free_file(int fd, void *ptr, size_t size, char *path)
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