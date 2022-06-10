#include <iostream>

using namespace std;

struct node
{
	int val;
	node* L;
	node* R;
	node* up;
};

void insertBST(node*& root, int x, node*& up)
{
	if (root == NULL) {
		root = new node;
		root->val = x;
		root->R = root->L = NULL;
		root->up = up;
	}
	else {
		if (x < root->val) {
			insertBST(root->L, x, root);
		}
		else {
			insertBST(root->R, x, root);
		}
	}
}

void inOrder(node* root) {
	if (root != NULL) {
		inOrder(root->L);
		cout << root->val << " ";
		inOrder(root->R);
	}
}

void find(node* root, int _element) {
	if (root != NULL) {
		find(root->L, _element);
		if (root->val == _element) {
			cout << root->val << " ";
			
		}
		find(root->R, _element);
	}
}

void findEvenNumbers(node* root) {
	if (root != NULL) {
		findEvenNumbers(root->L);
		if (root->val % 2 == 0) {
			cout << root->val << " ";
		}
		findEvenNumbers(root->R);
	}
}

void count(node* root, int& licznik)
{

	if (root != NULL) {
		count(root->L, licznik);
		if (root->val % 2 == 0) {
			licznik += 1;
		}
		count(root->R, licznik);
	}
}
void findMin(node*& root, node*& min)
{
	if (root != NULL) {
		if (root->L != NULL) {
			findMin(root->L, min);
		}
		else {
			min = root;
		}
	}
}

void findMax(node*& root, node*& max)
{
	if (root != NULL) {
		if (root->R != NULL) {
			findMin(root->R, max);
		}
		else {
			max = root;
		}
	}
}

void findSuccessor(node*& root, node*& successor) {
	if (root != NULL) {
		if (root->R != NULL) {
			findMin(root->R, successor);
		}
		else if (root->up != NULL && root->up->L == root) {
			successor = root->up;
		}
		else {
			successor = NULL;
		}
	}
}

void findPredecessor(node*& root, node*& predecessor)
{
	if (root != NULL)
	{
		if (root->L != NULL) findMax(root->L, predecessor);
		else if (root->up != NULL && root->up->R == root) predecessor = root->up;
		else predecessor = NULL;
	}
}


node* minValueNode(node* root)
{
	node* current = root;

	
	while (current && current->L != NULL)
		current = current->L;

	return current;
}

node* deleteNode(node* root, int _val)
{
	if (root == NULL)
		return root;

	if (_val < root->val)
		root->L = deleteNode(root->L, _val);

	else if (_val > root->val)
		root->R = deleteNode(root->R, _val);

	else {
		//no child
		if (root->L == NULL and root->R == NULL)
			return NULL;

		// one child or no child
		else if (root->L == NULL) {
			node* temp = root->R;
			delete root;
			return temp;
		}
		else if (root->R == NULL) {
			node* temp = root->L;
			delete root;
			return temp;
		}

		// children:successor
		node* temp = minValueNode(root->R);
		root->val = temp->val;
		root->R = deleteNode(root->R, temp->val);
	}
	return root;
}

int main() {
	node* root = NULL;
	node* up = NULL;

	node* max = NULL;
	node* min = NULL;
	node* successor = NULL;
	node* predecessor = NULL;

	insertBST(root, 13, up);
	insertBST(root, 15, up);
	insertBST(root, 8, up);
	insertBST(root, 10, up);
	insertBST(root, -3, up);
	insertBST(root, 9, up);
	insertBST(root, 2, up);

	inOrder(root);

	cout << endl << "+=========+" << endl;
	find(root, 10);

	cout << endl << "+=========+" << endl;

	findEvenNumbers(root);
	cout << endl << "+=========+" << endl;

	findMin(root, min);
	cout << min->val;
	cout << endl << "+=========+" << endl;

	findMax(root, max);
	cout << max->val;
	cout << endl << "+=========+" << endl;

	findSuccessor(root->L->R->L, successor);
	cout << endl << "+=========+" << endl;
	if (successor != NULL) {
		cout << "Nastepnik " << root->L->R->L->val << " to: " << successor->val << endl;
	}


	cout << endl << "+=========+" << endl;
	deleteNode(root, 10);
	cout << endl << "+=========+" << endl;
	inOrder(root);
	cout << endl << "+=========+" << endl;
	int temp = 0;
	count(root, temp);
	cout << temp;

	system("pause");
	return 0;
}
