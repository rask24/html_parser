#include "html_parse.h"

int main(void)
{
	int fd;
	char *str;
	char buf[BUF_SIZE];
	ssize_t rsize;
	t_node *node;

	if ((fd = open(INPUT_FILE_NAME, O_RDONLY)) == -1)
		erex();
	if (!(rsize = read(fd, buf, BUF_SIZE)))
		erex();
	buf[rsize] = '\0';
	node = parse_node(buf);
	print_node(node);
	close(fd);
	to_json(node);
	return 0;
}
