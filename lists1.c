#include "shell.h"

/**
 * list_len - the function that determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t d = 0;

	while (d)
	{
		h = h->next;
		d++;
	}
	return (d);
}

/**
 * list_to_strings - the function that returns an array
 * of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t d = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !d)
		return (NULL);
	strs = malloc(sizeof(char *) * (d + 1));
	if (!strs)
		return (NULL);
	for (d = 0; node; node = node->next, d++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < d; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[d] = str;
	}
	strs[d] = NULL;
	return (strs);
}


/**
 * print_list - the function that prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 * node_starts_with - the function that returns node
 * whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - the function that gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t d = 0;

	while (head)
	{
		if (head == node)
			return (d);
		head = head->next;
		d++;
	}
	return (-1);
}
