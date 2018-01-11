#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class PriorityQueue //неубывающая
{ 

	static const int MAX_SIZE = 8;
	struct Elem
	{
		string val;
		int priority;
		Elem(string v="", int p = 0) 
		{
			val = v;
			priority = p;
		}
	}
	a[MAX_SIZE];
	int size;

	void up (int i) 
	{
		while (i != 0 && a[i].priority > a[(i - 1) / 2].priority) 
		{
			swap(a[i], a[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void down(int i) 
	{
		while (i < size / 2) 
		{
			int maxI = 2 * i + 1;
			if (2 * i + 2 < size && a[2 * i + 2].priority > a[2 * i + 1].priority)
				maxI = 2 * i + 2;
			if (a[i].priority >= a[maxI].priority)
				return;
			swap(a[i], a[maxI]);
			i = maxI;
		}
	}

public:

	PriorityQueue() 
	{
		size = 0;
	}

	string top()
	{
		return(a[0].val);
	}

	void insertqueue(string value, int priority) //вставка элемента value с приоритетом priority в очередь
	{
		assert(size+1 < MAX_SIZE);  // обработка ошибки - переполнение очереди 
		a[size++] = Elem(value, priority);
		up(size-1);
	}

	string dequeue() //извлечение элемента с максимальным приоритетом
	{
		assert(size > 0);  // обработка ошибки - извлечение из пустой очереди
		swap(a[0], a[--size]);
		down(0);
		return a[size].val;
	}

	bool isEmpty() //проверка на пустоту
	{
		return size == 0;
	}

	void print_heap()
	{
		for (int i = 0; i < size; i++)
			cout << a[i].val << endl;
	}

};

int main(void)
{
	PriorityQueue q;
	q.print_heap();

	//q.dequeue();

	q.insertqueue("a", 0);
	q.insertqueue("b", 1);
	q.insertqueue("c", 7);
	q.insertqueue("g", 31);
	q.insertqueue("f", 21);
	q.insertqueue("c", 7);
	q.insertqueue("d", 11);
	//q.insertqueue("n", 17);
	

	q.print_heap();
	
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.print_heap();

}