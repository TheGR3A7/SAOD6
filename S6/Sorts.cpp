#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �������� ���������, ����������� ��������� ���������� �������(������� �����, ����� �� ������).�������� ��
// �������������(����� ��������� � ������������) ��� ���������� � ���������� ��������� �������������������.

// ��������� ���� ������
struct TreeNode {
	int data; 
	TreeNode* left;
	TreeNode* right;
};

// ������� ������ ����� ������ (��������� �����)
void TreePrint(TreeNode* tree) 
{
	if (tree != NULL) 
	{
		TreePrint(tree->left);
		printf("%d ", tree->data);
		TreePrint(tree->right);
	}
}

// ������� ���������� ����� � ������
TreeNode* AddNode(int x, TreeNode* tree)
{
	if (tree == NULL) 
	{
		tree = (TreeNode*)malloc(sizeof(TreeNode));
		tree->data = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else 
	{
		if (x < tree->data)
			tree->left = AddNode(x, tree->left);
		else
			tree->right = AddNode(x, tree->right);
	}
	return tree;
}

// ������� ������������ ������ ������
void FreeMemory(TreeNode* tree) 
{
	if (tree != NULL) 
	{
		FreeMemory(tree->left);
		FreeMemory(tree->right);
		free(tree);
	}
}

//�������� ������� ���������� ������� �������� ������
void SelectionSort(int k, int mas[])
{
	int i, j, min, temp;
	for (i = 0; i < k - 1; i++)
	{
		//������������� ��������� �������� ������������ �������
		min = i;
		//������� ����������� ������ ��������
		for (j = i + 1; j < k; j++) {
			if (mas[j] < mas[min])
				min = j;
			//������ �������� �������
		}
		temp = mas[i];
		mas[i] = mas[min];
		mas[min] = temp;
	}
}

int main()
{
	system("chcp 1251");

	TreeNode* root = NULL;
	int choice;
	bool flag = true;
	int* mas = NULL;

	while (flag)
	{
		do {
			printf("1 - ������� �����.\n"
				"2 - ����� �� ������.\n"
				"3 - �����.\n");
			scanf("%i", &choice);
		} while (choice < 0 || choice >3);
		system("cls");
		switch (choice)
		{
			case 1:
				int k;
				printf("������� ������ �������: ");
				scanf("%d", &k);

				mas = (int*)malloc(k * sizeof(int));

				printf("������� �������� �������: \n");
				for (int i = 0; i < k; i++) 
					scanf("%d", &mas[i]);

				SelectionSort(k, mas);

				printf("��������������� ������ (������� �����): ");
				for (int i = 0; i < k; i++) 
					printf("%d ", mas[i]);
				printf("\n");

				free(mas);
				break;
			case 2:
				int n;
				printf("������� ���������� ��������� � ������: ");
				scanf("%d", &n);

				printf("������� �������� ��� ������:\n");
				for (int i = 0; i < n; i++) 
				{
					int x;
					scanf("%d", &x);
					root = AddNode(x, root);
				}
				
				printf("��������������� ������ (����� �� ������): ");
				TreePrint(root);
				printf("\n");
				
				FreeMemory(root);
				break;
			case 3:
				flag = false;
				break;
		}
	}

	return 0;
}


//��� � � ���������� ���������, ������� ���� ����������� n�1 ���, � ���������� � � ������� n / 2 ���.
//�������������, ���������� ������� ������� ������� (n^2 - n)/2 ���������.����� �������, �����
//���������� ���������� ������� ������� ����� ��������� ������� n^2, �� - �� ���� ��� ��������� ����� ��������� ��� ���������� �������� ����� ���������.