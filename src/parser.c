#include "html_parse.h"

int parse_element(t_node *node, char *buf)
{
	size_t len;
	char *tag;
	int loop;
	t_node **tmp;

	loop = 0;
	do
	{
		bp++;
		len = 0;
		while (isalnum(buf[bp + len]))
			len++;
		if (!(tag = malloc(sizeof(char) * len + 1)))
			return 1;
		strncpy(tag, buf + bp, len);
		tag[len] = '\0';
		bp += len + 1;
		if (loop == 0)
		{
			node->tag = tag;
			if (!(node->child = parse_node(buf)))
				return 1;
		}
		else
		{
			if (loop == 1)
				tmp = &(node->next);
			else
				tmp = &((*tmp)->next);
			if (!((*tmp) = parse_node(buf)))
				return 1;
			(*tmp)->tag = tag;
		}
		bp += 2 + len + 1;
		while (isspace(buf[bp]))
			bp++;
		loop++;
	}
	while (buf[bp] && buf[bp] == '<' && buf[bp + 1] != '/');
	return 0;
}

int parse_text(t_node *node, char *buf) 
{
	char *content;
	size_t len;

	len = 0;
	while (buf[bp + len] != '<')
		len++;
	if (!(content = malloc(sizeof(char) * len + 1)))
		return 1;
	strncpy(content, buf + bp, len);
	content[len] = '\0';
	bp += len;
	node->content = content;
	while (isspace(buf[bp]))
		bp++;
	return 0;
}

t_node *parse_node(char *buf)
{
	t_node *ret;
	int ex;

	if (!(ret = malloc(sizeof(t_node))))
		return NULL;
	ret->tag = NULL;
	ret->content = NULL;
	ret->next = NULL;
	ret->child = NULL;
	while (isspace(buf[bp]))
		bp++;
	while (buf[bp] && !(buf[bp] == '<' && buf[bp + 1] == '/'))
	{
		if (buf[bp] == '<')
		{
			ex = parse_element(ret, buf);
		}
		else
			ex = parse_text(ret, buf);
		if (ex == 1)
			break;
	}
	return ret;
}
