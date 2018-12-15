#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
};

struct node* new_node(struct node*, int);
void append_node(struct node*, int);
struct node* insert_node(struct node*, int);
int count_node(struct node*);
void print_list(struct node*);
int find_mid(struct node*, int);
void delete_node(struct node**, int);
struct node* reverse_list(struct node*);

void main()
{
	struct node* head = NULL;
	struct node* rev = NULL;

	int i = 1;
	int input = 0;

	int stdin_check = 0;

	printf("숫자를 입력을 반복합니다. ctrl+z를 3번 입력받으면 반복을 종료합니다.\n");
	while(1)
	{
		printf("%d 번째 입력 : ", i);

		stdin_check = scanf("%d", &input);
		if (stdin_check == -1)
			break;
		else
		{
			if (i++ == 1)
				head = new_node(head, input);
			else
				append_node(head, input);
		}
	} 

	int size = count_node(head);

	print_list(head);
	printf("\n");
	printf("%d", size);
	printf("\n");
	printf("%d", find_mid(head, size));
	printf("\n");
	rev = reverse_list(head);
	print_list(rev);
	printf("\n");
	if (size % 2 == 1)
	{
		for (i = 1; i < size / 2 + 2; i++)
		{
			delete_node(&head, i);
		}
	}
	else if (size % 2 == 0)
	{
		for (i = 1; i < size / 2 + 1; i++)
		{
			delete_node(&head, i);
		}
	}
	print_list(head);
	printf("\n");
}

struct node* new_node(struct node* head, int value)
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	head = new;
	new->value = value;
	new->next = NULL;

	return head;
}

void append_node(struct node* head, int value)
{
	struct node* cur;
	cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	
	cur->next = new;
	new->value = value;
	new->next = NULL;
}

struct node* insert_node(struct node* head, int value)
{
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->next = head;
	new->value = value;
	head = new;
	return head;
}


int count_node(struct node* head)
{
	int cnt = 1;

	struct node* cur;
	cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

void print_list(struct node* head)
{
	struct node* cur;
	cur = head;

	while (cur->next != NULL)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("%d ", cur->value);
}

int find_mid(struct node* head, int size)
{
	int i;
	struct node* cur;
	cur = head;

	if (size % 2 == 0)
	{
		for (i =  1; i < size / 2; i++)
		{
			cur = cur->next;
		}
		return (cur->value);
	}
	
	else if (size % 2 == 1)
	{
		for (i = 0; i < size /  2; i++)
		{
			cur = cur->next;
		}
		return (cur->value);
	}
}

void delete_node(struct node** phead, int index)
{
	struct node* cur;
	cur = *phead;

	int i;
	if (index == 1)
	{
		*phead = (*phead)->next;
	}
	else if (index > 1)
	{
		for (i = 2; i < index; i++)
		{
			cur = cur->next;
		}
		struct node* temp = cur->next;
		cur->next = temp->next;
	}
}

struct node* reverse_list(struct node* head)
{
	struct node* rev = NULL;
	struct node* cur = head;
	
	while (cur->next != NULL)
	{
		rev = insert_node(rev, cur->value);
		cur = cur->next;
	}
	rev = insert_node(rev, cur->value);

	return rev;
}