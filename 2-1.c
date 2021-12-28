#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* treepointer;
typedef struct node
{
	int data;
	treepointer leftchild, rightchild;
};

void Inorder_traversal(treepointer ptr);     // Inorder traversal�� ����� ����ϴ� �Լ�
void Preorder_traversal(treepointer ptr);    // Preorder traversal�� ����� ����ϴ� �Լ�
void Postorder_traversal(treepointer ptr);   // Postorder traversal�� ����� ����ϴ� �Լ�

int main(void)
{
	// �־��� binary tree ����
	struct node node1 = { 1, NULL, NULL }; struct node node2 = { 3, NULL, NULL };
	struct node node3 = { 6, NULL, NULL }; struct node node4 = { 7, NULL, NULL };
	struct node node5 = { 11, NULL, NULL }; struct node node6 = { 12, NULL, NULL };
	struct node node7 = { 2, &node1, &node2 }; struct node node8 = { 5, &node3, &node4 };
	struct node node9 = { 10, &node5, &node6 }; struct node node10 = { 13, NULL, NULL };
	struct node node11 = { 4, &node7, &node8 }; struct node node12 = { 9, &node9, &node10 };
	struct node node13 = { 8, &node11, &node12 }; // root

	treepointer root = &node13;

	// �� traversal�� ��� ���
	printf("Inorder traversal�� ���: ");
	Inorder_traversal(root);
	printf("\nPreorder traversal�� ���: ");
	Preorder_traversal(root);
	printf("\nPostorder traversal�� ���: ");
	Postorder_traversal(root);

	return 0;
}

void Inorder_traversal(treepointer ptr)
{
	if (ptr) {
		Inorder_traversal(ptr->leftchild);
		printf("%d ", ptr->data);
		Inorder_traversal(ptr->rightchild);
	}
}

void Preorder_traversal(treepointer ptr)
{
	if (ptr) {
		printf("%d ", ptr->data);
		Preorder_traversal(ptr->leftchild);
		Preorder_traversal(ptr->rightchild);
	}
}

void Postorder_traversal(treepointer ptr)
{
	if (ptr) {
		Postorder_traversal(ptr->leftchild);
		Postorder_traversal(ptr->rightchild);
		printf("%d ", ptr->data);
	}
}