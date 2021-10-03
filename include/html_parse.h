#ifndef HTML_PARSE_H
#define HTML_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 4096
#define INPUT_FILE_NAME "./input/index.html"
#define OUTPUT_FILE_NAME "./output/dom.json"
#define CREATE_OUTPUT_FILE "touch ./output/dom.json"

int bp;

typedef struct s_node
{
	char *tag;
	char *content;
	struct s_node *child;
} t_node;

void erex(void);
int parse_text(t_node *node, char *buf);
int parse_element(t_node *node, char *buf);
t_node *parse_node(char *buf);
void print_node(t_node *node);

void to_json(t_node *node);

#endif
