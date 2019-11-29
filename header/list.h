#ifndef LISTHEADER
#define LISTHEADER

#include <stdlib.h>

struct node {
	void *value;
	struct node *next;
	struct node *pre;
	long list_length;//存储链表长度，可只在链表头中保存该值
};

/**
* 初始化一个链表，返回一个表头
*/
struct node* initialize();

/**
* 向指定链表尾添加新的节点
*/
int add(void *new_node_value, struct node* root);

/**
* 向指定链表中的指定位置添加新的节点
*/
int add_to_index(void *new_node_value, struct node* root, int index);

/**
* 获取链表中指定位置的值
*/
struct node* get(int index, struct node* root);

/**
* 删除链表末尾值，并返回被删除的值
*/
struct node* pop(struct node* root);

/**
* 删除链表指定位置的值，并返回被删除的值
*/
struct node* delete_index(struct node* root, int index);

/**
* 查看链表末尾值
*/
struct node* peek(struct node* root);

/**
* 删除链表中的所有节点值，但链表还可继续使用
*/
int delete_all_node(struct node* root);

/**
* 删除链表，释放链表的占用的所有资源
*/
//int delete_list(struct node* root);

/**
 * 打印链表信息
 * */
void print_list_info(struct node* root);

#endif
