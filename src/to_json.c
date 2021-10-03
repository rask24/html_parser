#include "html_parse.h"

//typedef struct s_node
//{
//	char *tag;
//	char *content;
//	struct s_node *child;
//} t_node;

void puts_fd(int fd, const char *str)
{
	write(fd, str, strlen(str));
}

void indent(int fd, int level)
{
	int i;

	for (i = 0; i < level; i++)
		puts_fd(fd, "\t");
}

void write_json(int fd, t_node *node, int level)
{
	int flag;

	puts_fd(fd, "{\n");
	if (node->tag)
	{
		indent(fd, level);
		puts_fd(fd, "\"tag\": ");
		puts_fd(fd, "\"");
		puts_fd(fd, node->tag);
		puts_fd(fd, "\",\n");
	}
	if (node->content)
	{
		indent(fd, level);
		puts_fd(fd, "\"content\": ");
		puts_fd(fd, "\"");
		puts_fd(fd, node->content);
		puts_fd(fd, "\"\n");
	}
	if (node->child)
	{
		indent(fd, level);
		puts_fd(fd, "\"child\": ");
		write_json(fd, node->child, level + 1);
	}
	indent(fd, level - 1);
	puts_fd(fd, "}\n");
}

void to_json(t_node *node)
{
	int fd;

	system(CREATE_OUTPUT_FILE);
	if ((fd = open(OUTPUT_FILE_NAME, O_WRONLY)) == -1)
		erex();
	write_json(fd, node, 1);
	close(fd);
}
