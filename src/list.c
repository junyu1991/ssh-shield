#include "all_headers.h"

/**
* 初始化一个链表，返回一个表头
*/
struct node* initialize()
{
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	if(!root) {
		perror("malloc");
		return NULL;
	}
	root->value = NULL;
	root->list_length = 0;
	root->next = NULL;
	root->pre = NULL;
	return root;
}

/**
* 向指定链表尾添加新的节点
*/
int add(void *new_node_value, struct node* root)
{
	struct node* new_node;
	struct node* temp;
	if(root == NULL)
		return -1;
	new_node = (struct node *)malloc(sizeof(struct node));
	if(!new_node) {
		perror("malloc");
		return -1;
	}
	new_node->next = NULL;
	new_node->value = new_node_value;

	temp = root;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->pre = temp;
	root->list_length += 1;

	return 1;
}

/**
* 向指定链表中的指定位置添加新的节点
*/
int add_to_index(void *new_node_value, struct node* root, int index) 
{
	struct node* new_node;
	struct node* temp = root;
	int i = 0;
	if(root == NULL)
	if(index >= root->list_length-1)
		return add(new_node_value, root);
	else{
		while(i<index) {
			temp = temp->next;
			i += 1;
		}

		new_node = (struct node *)malloc(sizeof(struct node));
		if(!new_node) {
			perror("malloc");
			return -1;
		}
		new_node->value = new_node_value;
		new_node->next = temp->next;
		temp->next = new_node;
		new_node->pre = temp;

		root->list_length += 1;
		return 1;
	}
}

/**
* 获取链表中指定位置的值
*/
struct node* get(int index, struct node* root) 
{
	int i = 0;
	struct node* temp;
	if(i<0)
		return root->next;
	if(index >= root->list_length) {
		index = root->list_length-1;
	}
	for(i=0;i<=index;i++) {
		temp=temp->next;
	} 
	return temp;
}

/**
* 删除链表末尾值，并返回被删除的值
*/
struct node* pop(struct node* root) 
{
	struct node* temp = root;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->pre->next = NULL;
	temp->pre = NULL;
	root->list_length -= 1;
	return temp;
}

/**
* 删除链表指定位置的值，并返回被删除的值
*/
struct node* delete_index(struct node* root, int index) 
{
	struct node* temp = root;
	int i=0;
	if(index >= root->list_length-1)
		return pop(root);
	else {
		while(i<=index) {
			temp = temp->next;
			i+=1;
		}
		temp->pre->next = temp->next;
		temp->next->pre = temp->pre;
		temp->next = NULL;
		temp->pre = NULL;
		root->list_length -= 1;
		return temp;
	}
}

struct node* peek(struct node* root) 
{
	return get(root->list_length, root);
}

int delete_list(struct node* root) 
{
	int result = delete_all_node(root);
	free(root);
	root = NULL;
	return result;
}
int delete_all_node(struct node* root) 
{
	//int result = delete_list(root->next);
	struct node* temp = root->next;
	struct node* delete_node;
	while(temp != NULL) {
		delete_node = temp;
		if(delete_node->value != NULL)
			delete_node->value = NULL;
		free(delete_node);
		delete_node = NULL;
		temp = temp->next;
	}
	root->list_length = 0;
	root->next = NULL;
	return 1;
}

void print_list_info(struct node* root) 
{
	if(root != NULL) {
		struct node* temp = root->next;
		if(root->list_length == 0) {
			printf("Empty list\n");
			return;
		}
		printf("list length: %ld, the list is:", root->list_length);
		while(temp->next != NULL) {
			printf("%s->", (char *)temp->value);
			temp = temp->next;
		}
		if(temp)
			printf("%s", (char *)temp->value);
		printf("\n");
	} else {
		printf("NULL list\n");
	}
}
