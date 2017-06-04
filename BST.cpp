#include <stdio.h>

class BSTNode
{
public:
	int data;
	BSTNode* leftChild;
	BSTNode* rightChild;
	BSTNode(int _d) { data = _d; }
};

class BST
{

	BSTNode* GetNewNode(int data)
	{
		BSTNode* node = new BSTNode(data);
		node->leftChild = node->rightChild = NULL;
		return node;
	}
public:
	BST()
	{
		counter = 0;
	}

	BSTNode* Insert(int data)
	{
		Curr = InsertProcess(Curr, data);
		if (counter == 0)
			Root = Curr;
		counter++;
		return Curr;
	}

	bool Search(int data)
	{
		return SearchProcess(Root, data);
	}
	
private:
	int counter;
	BSTNode* Root = NULL;
	BSTNode* Curr = NULL;

	BSTNode* InsertProcess(BSTNode* Node, int data)
	{
		if (Node == NULL){
			Node = GetNewNode(data);
			return Node;
		}
		else
		{
			if (data <= Node->data){
				Node->leftChild = InsertProcess(Node->leftChild, data);
			}
			else{
				Node->rightChild = InsertProcess(Node->rightChild, data);
			}
		}
		return Node;
	}

	bool SearchProcess(BSTNode* Node, int search)
	{
		if (Node == NULL)
			return false;
		if (Node->data == search)
			return true;
		else if (Node->data > search)
			return SearchProcess(Node->leftChild, search);
		else
			return SearchProcess(Node->rightChild, search);
	}

};

int main()
{
	BST bst = BST();
	bst.Insert(5);
	bst.Insert(14);
	bst.Insert(10);
	bst.Insert(2);
	printf("%d", bst.Search(10));
	return 0;
}