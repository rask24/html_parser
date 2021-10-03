#include "html_parse.h"


void erex(void)
{
	perror("");
	exit(1);
}

void print_node(t_node *node)
{
	if (node->tag)
		printf("tag: %s\n", node->tag);
	if (node->content)
		printf("content: %s\n", node->content);
	if (node->child)
		print_node(node->child);
	if (node->next)
		print_node(node->next);
}
