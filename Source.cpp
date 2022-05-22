// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "iostream"
using namespace std;

struct node {
	int val;
	node *next;

};
void Add(node *&H, int x) {

	node *p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void show(node *H)
{
	cout << "H->";
	node *p = H;
	/*for (node *p = H; p != NULL; p = p->next)
	{
		cout << p->val << "->";
	}*/
	while(p!=NULL)
	{
	cout << p->val<<"->";
	p=p->next;
	}
	cout << "NULL" << endl;
}

//while(p!=NULL)
//{
//cout << p->val<<"->";
//p=p->next;
//}

void del(node *&H)
{
	if (H != NULL) {
		node *p = H;
		H = H->next; //H = p->next;
		delete p;
	}
}
void del_x(node *&H, int x)
{
	if (H != NULL)
	{
		if (H->val == x)
		{
			del(H);
		}

		else {
			node *p = H;
			while (p->next != NULL && p->next->val != x)
			{
				p = p->next;
				//if (p->next!=NULL) // przy stosowaniu funkcji zewnetrznej
			}
			del(p->next);
		}
	}
}

void copy(node *&H)
{
	if (H != NULL)
	{
		node *p = H;
		while (p != NULL)
		{
			Add(p->next, p->val);
			p = p->next->next;
		}
	}
	


}

void zamiana(node *&H)
{
	if (H != NULL)
	{
		node *p = H;
		H = p->next;
		p->next = H->next;
		H->next = p;
		
	}
}

void sort(node *&H, int x)
{
	if (H == NULL)
	{
		Add(H, x);
	}
	else {
		if (H->val > x)
			Add(H, x);

		else
		{
			node *p = H;
			while (p->next != NULL && p->next->val < x)
			{
				p = p->next;
				
			}
			Add(p->next, x);
		}
	}
}

int length(node *H)
{
	int n = 0;
	node *p = H;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return int(n / 2) - 1;
}

void Split(node*& H, node*& H1, node*& H2)
{
	H1 = H;
	if (H != NULL && H->next == NULL) H = NULL;
	else
	{
		node* p = H;
		int dl = length(H);
		for (int i = 0; dl > i; i++)
		{
			p = p->next;
		}
		H2 = p->next;
		p->next = NULL;
		H = NULL;

	}
}


void merge(node* &H, node* &H1, node* &H2)
{
	if (H1 == NULL && H2 != NULL)
	{
		H = H2;
		H2 = NULL;
	}

	if (H2 == NULL && H1 != NULL)
	{
		H = H1;
		H1 = NULL;
	}
	if (H1 != NULL && H2 != NULL)
	{
		node* T = NULL;
		node*p = NULL;
		while (H1 && H2)
		{
			if (H1->val < H2->val)
			{
				p = H1;
				H1 = H1->next;

				if (H == NULL)
				{
					H = p;
					T = p;
				}
				else
				{
					T->next = p;
					T = p;
				}
			}
			else
			{
				p = H2;
				H2 = H2->next;
				if (H == NULL)
				{
					H = p;
					T = p;

				}
				else
				{

					T->next = p;
					T = p;

				}
			}
		}
		if (H1 == NULL)
		{
			T->next = H2;
			H2 = NULL;
		}
		else
		{
			T->next = H1;
			H1 = NULL;
		}
	}
}

void MergeSort(node* &H)
{
	if (H && H->next != NULL)
	{
		node* H1 = NULL;
		node* H2 = NULL;
		Split(H, H1, H2);
		MergeSort(H1);
		MergeSort(H2);
		merge(H, H1, H2);
	}
}
// sortowanie kopcowe
void heapify(int *T, int heapsize, int i)
{
	int L = 2 * i;
	int P = L + 1;
	int largest = i;
	if (L <= heapsize && T[L] > T[i])
		largest = L;
	if (P <= heapsize && T[P] > T[largest])
		largest = P;
	if (largest != i)
	{
		swap(T[i], T[largest]);
		heapify(T, heapsize, largest);
	}
}
void BuildHeap(int *T, int heapsize)
{
	for (int i = heapsize / 2; i > 0; i--)
	{
		heapify(T, heapsize, i);
	}
}

void HeapSort(int *T, int size)
{
	int heapsize = size-1;
	BuildHeap(T, heapsize);
	while (heapsize > 1)
	{
		swap(T[1], T[heapsize]);
		heapsize--;
		heapify(T, heapsize, 1);
	}
}
//to trzeba zrobic
void bubbleSort(struct node *H)
{
	int swapp, i;
	struct node *ptr1;
	struct node *lptr = NULL;

	
	if (H == NULL)
		return;

	do
	{
		swapp = 0;
		ptr1 = H;

		while (ptr1->next != lptr)
		{
			if (ptr1->val > ptr1->next->val)
			{
				swap(ptr1, ptr1->next);
				swapp = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapp);
}

int main()
{
	node *H = NULL;
	//node *p = new node;
	//p->val = 3;
	//p->next = NULL;
	//H = p;
	//cout << H->val << endl;
	Add(H, 5);
	Add(H, 9);
	Add(H, 7);
	Add(H, 4);
	Add(H, 9);
	Add(H, 14);
	//cout << H->val << endl;
	//show(H);
	//Add(H->next->next, 12);
	//del(H);
	//show(H);
	//del_x(H, 3);
	//show(H);
	////copy(H);
	//show(H);
	//zamiana(H);
	//show(H);
	
	/*sort(H, 5);
	sort(H, 3);
	sort(H, -2);
	sort(H, 0);*/
	//show(H);
	/*split(H, H2, H3);
	show(H);
	show(H2);
	show(H3);*/
	/*merge(H, H2, H3);*/
	//MergeSort(H);
	int* tablica = new int[10]{0, 20, -10, 6, -6, 3, 15, 8, 8, 30 };
	HeapSort(tablica, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << tablica[i] << " ";
	}
	
	bubbleSort(&H, 10);
	show(H);
	//show(H2);
	//show(H3);
	system("pause");
	return 0;
}

