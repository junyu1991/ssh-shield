#include "list.h"

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
	root->length = 0;
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
	new_node = (struct node *)malloc(sizeof(struct node));
	if(!new_node) {
		perror("malloc");
		return -1;
	}
	new_node->next = NULL;

	root->list_length += 1;

	temp = root;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->pre = temp;

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
	if(index >= root->list_length)
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
		return NULL;
	else if(i>=root->length) {
		return peek(root);
	} else {
		
	}

}

/**
* 删除链表末尾值，并返回被删除的值
*/
void* pop(struct node* root) 
{
	void *result;
	struct node* temp = root;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->pre->next = NULL;
	result = temp->value;
	free(temp);
	root->list_length -= 1;
	return result;
}

/**
* 删除链表指定位置的值，并返回被删除的值
*/
void* delete_index(struct node* root, int index) 
{
	void *result;
	struct node* temp = root;
	int i=0;
	if(index >= root->list_length)
		return pop(root);
	else {
		while(i<index) {
			temp = temp->next;
		}
		temp->pre->next = NULL;
		result = temp->value;
		free(temp);
		root->list_length -= 1;
		return result;
	}
}