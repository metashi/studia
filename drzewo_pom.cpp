void find(node* root, int _element) {
	if (root != NULL) {
		find(root->L, _element);
		if (root->val == _element) {
			cout << root->val << " ";
			
		}
		find(root->R, _element);
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

//predecessor lustrzane odbicie
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
