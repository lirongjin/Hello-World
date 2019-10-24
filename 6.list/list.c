#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct node
{
	struct node *next, *prev;
	int data;
};

struct node *create_node(int data);
void list_add(struct node *head, struct node *new);
void traverse_list(struct node *head);

int main()
{
	struct node *head = NULL;

	head = create_node(0);
	if(NULL == head)
	{
		printf("create_node error.\n");
		exit(-1);
	}
	
	list_add(head, create_node(12));
	list_add(head, create_node(13));
	list_add(head, create_node(14));
	list_add(head, create_node(15));

	traverse_list(head);

}

struct node *create_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if(NULL == p)
	{
		printf("malloc error.\n");
		return NULL;
	}

	bzero(p, sizeof(struct node));
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
}

void list_add(struct node *head, struct node *new)
{
	struct node *p = head;

	if(NULL == p->next)
	{
		p->next = new;
		new->prev = p;
	}
	else
	{
		new->next = p->next;
		p->next->prev = new;
		p->next = new;
		new->prev = p;
	}

}

void traverse_list(struct node *head)
{
	struct node *p = head;

	while(NULL != p->next)
	{
		p = p->next;
		printf("data is %d\n", p->data);
	}
}
