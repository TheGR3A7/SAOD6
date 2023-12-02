#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Написать программы, реализующие алгоритмы сортировки выбором(простой выбор, выбор из дерева).Сравнить их
// эффективность(число сравнений и перестановок) для наилучшего и наихудшего вариантов последовательностей.

// Структура узла дерева
struct TreeNode {
	int data; 
	TreeNode* left;
	TreeNode* right;
};

// Функция вывода узлов дерева (инфиксный обход)
void TreePrint(TreeNode* tree) 
{
	if (tree != NULL) 
	{
		TreePrint(tree->left);
		printf("%d ", tree->data);
		TreePrint(tree->right);
	}
}

// Функция добавления узлов в дерево
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

// Функция освобождения памяти дерева
void FreeMemory(TreeNode* tree) 
{
	if (tree != NULL) 
	{
		FreeMemory(tree->left);
		FreeMemory(tree->right);
		free(tree);
	}
}

//Описание функции сортировки методом простого выбора
void SelectionSort(int k, int mas[])
{
	int i, j, min, temp;
	for (i = 0; i < k - 1; i++)
	{
		//устанавливаем начальное значение минимального индекса
		min = i;
		//находим минимальный индекс элемента
		for (j = i + 1; j < k; j++) {
			if (mas[j] < mas[min])
				min = j;
			//меняем значения местами
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
			printf("1 - Простой выбор.\n"
				"2 - Выбор из дерева.\n"
				"3 - Выйти.\n");
			scanf("%i", &choice);
		} while (choice < 0 || choice >3);
		system("cls");
		switch (choice)
		{
			case 1:
				int k;
				printf("Введите размер массива: ");
				scanf("%d", &k);

				mas = (int*)malloc(k * sizeof(int));

				printf("Введите элементы массива: \n");
				for (int i = 0; i < k; i++) 
					scanf("%d", &mas[i]);

				SelectionSort(k, mas);

				printf("Отсортированный массив (простой выбор): ");
				for (int i = 0; i < k; i++) 
					printf("%d ", mas[i]);
				printf("\n");

				free(mas);
				break;
			case 2:
				int n;
				printf("Введите количество элементов в дереве: ");
				scanf("%d", &n);

				printf("Введите элементы для дерева:\n");
				for (int i = 0; i < n; i++) 
				{
					int x;
					scanf("%d", &x);
					root = AddNode(x, root);
				}
				
				printf("Отсортированный массив (выбор из дерева): ");
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


//Как и в сортировке пузырьком, внешний цикл выполняется n–1 раз, а внутренний – в среднем n / 2 раз.
//Следовательно, сортировка простым выбором требует (n^2 - n)/2 сравнений.Таким образом, время
//выполнения сортировки простым выбором имеет сложность порядка n^2, из - за чего она считается очень медленной для сортировки большого числа элементов.