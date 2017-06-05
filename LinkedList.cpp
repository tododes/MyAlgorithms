#include<stdio.h>

class Data
{
public:
	int data;
	Data* next;
	Data* prev;
	Data(int _data)
	{
		data = _data;
	}
};

class LinkedList
{
public:
	int counter;
private:
	Data* head;
	Data* curr;
	Data* tail;
	void DeleteAtFront()
	{
		Data* n = head;
		head = head->next;
		if (n == curr)
			curr = curr->next;
		head->prev->next = NULL;
		head->prev = NULL;
		counter--;
		delete n;
		n = NULL;
	}

	void DeleteAtRear()
	{
		Data* n = tail;
		tail = tail->prev;
		if (n == curr)
			curr = curr->prev;
		tail->next->prev = NULL;
		tail->next = NULL;
		counter--;
		delete n;
		n = NULL;
	}

public:
	Data* PushBack(int data)
	{
		curr = new Data(data);
		curr->next = curr->prev = NULL;
		if (head == NULL)
		{
			head = tail = curr;
		}
		else
		{
			tail->next = curr;
			curr->prev = tail;
			curr->next = NULL;
			tail = curr;
		}
		counter++;
		return curr;
	}

	Data* PushFront(int data)
	{
		curr = new Data(data);
		curr->next = curr->prev = NULL;
		if (head == NULL)
		{
			head = tail = curr;
		}
		else
		{
			head->prev = curr;
			curr->next = head;
			curr->prev = NULL;
			head = curr;
		}
		//printf("head = %d", head->data);
		counter++;
		return curr;
	}
	LinkedList()
	{
		counter = 0;
	}

	void PrintAll()
	{
		printf("===============================\n");
		for (Data* temp = head; temp != NULL; temp = temp->next)
		{
			printf("%d\n", temp->data);
		}
		printf("===============================\n");
	}

	void DeleteData(int data)
	{
		if (head == tail && head->data == data)
		{
			counter--;
			delete head;
			head = NULL;
		}
		else
		{
			Data* deletedNode;
			for (Data* temp = head; temp != NULL; temp = temp->next)
			{
				deletedNode = temp;
				if (temp->data == data)
				{
					if (temp == head)
						DeleteAtFront();
					else if (temp == tail)
						DeleteAtRear();
					else
					{
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						temp->next = temp->prev = NULL;
						counter--;
						delete temp;
						temp = NULL;
					}

					break;
				}
			}
		}
	}

	void DeleteAll()
	{
		while (head->next != NULL)
		{
			DeleteAtFront();
		}
		counter--;
		delete head;
		head = NULL;
	}

	~LinkedList()
	{
	
	}
};

int main()
{
	
	return 0;
}