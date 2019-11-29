#include "all_headers.h"
#include "list.h"

void test_log() {
	log_init("./logs/test.log");
	log_write("DEBUG message", DEBUG);
	log_write("INFO message", INFO);
	log_write("ERROR message", ERROR);
	log_write("WARN message", WARN);
	log_write("FATA message", FATAL);
	close_log();
}

void test_list() 
{
	struct node* root = initialize();
	struct node* temp;
	if(!root)
		exit(EXIT_FAILURE);
	char *value = "a";
	add(value, root);
	add("b", root);
	add_to_index("c", root, 232);
	add("d", root);
	add("e", root);
	add("f", root);
	print_list_info(root);
	add_to_index("g", root, 1);
	print_list_info(root);
	add_to_index("h", root, 4);
	print_list_info(root);
	
	temp = pop(root);
	printf("pop the node: %s \n", (char *)temp->value);
	print_list_info(root);
	
	printf("pop the node: %s \n", (char *)pop(root)->value);
	print_list_info(root);

	printf("delete 3 node:%s \n", (char *)delete_index(root, 3)->value);
	print_list_info(root);
	printf("delete 1 node:%s \n", (char *)delete_index(root, 1)->value);
	print_list_info(root);
	printf("delete 2 node:%s \n", (char *)delete_index(root, 2)->value);
	print_list_info(root);

	delete_all_node(root);
	print_list_info(root);
	
	add("b", root);
	add_to_index("c", root, 232);
	add("d", root);
	add("e", root);
	add("f", root);
	print_list_info(root);
	
	//delete_list(root);
	free(root);
	root = NULL;
	if(root)
		printf("next is not null\n");
	printf("root!=NULL:%d\n", root!=NULL);
	print_list_info(root);
	//printf("%d----%d\n", root==NULL, root->next==NULL);
	add("b", root);
	add_to_index("c", root, 232);
	add("d", root);
	add("e", root);
	add("f", root);
	print_list_info(root);
	

	//free(root);
	//root = NULL;
	//print_list_info(root);
}

int main(int argc, char *argv[]) 
{
	//test_log();
	char *a = "sfdsf";
	a = NULL;
	test_list();
	return 0;
}
