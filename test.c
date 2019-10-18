#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	void *ptr = mmap(0, 1000, PROT_READ, MAP_PRIVATE, fd, 0);
	ft_print_memory(ptr + 0xb0, 500);
	return 0;
}
