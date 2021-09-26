// 트리 순회

#include <iostream>

using namespace std;

bool isFind = false;

class Node {
private:
	char value;
	Node* left;
	Node* right;
	Node* root;

public:
	Node() : value(NULL), left(nullptr), right(nullptr), root(nullptr) {};
	Node(char _value) : value(_value), left(nullptr), right(nullptr), root(nullptr) {};

	~Node() {};

	void SetLeft(Node* node) { this->left = node; }
	void SetRight(Node* node) { this->right = node; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	char GetValue() { return value; }
};

// 전위
void Preorder(Node* node) {
	if (node == nullptr || node->GetValue() == '.')
		return;
	cout << node->GetValue();
	Preorder(node->GetLeft());
	Preorder(node->GetRight());
}

// 중위
void Inorder(Node* node) {
	if (node == nullptr || node->GetValue() == '.')
		return;

	Inorder(node->GetLeft());
	cout << node->GetValue();
	Inorder(node->GetRight());
}

// 후위
void Postorder(Node* node) {
	if (node == nullptr || node->GetValue() == '.')
		return;

	Postorder(node->GetLeft());
	Postorder(node->GetRight());
	cout << node->GetValue();
}

void SetValue(Node* node, char value, char left, char right) {
	if (isFind) return;
	
	if (node == nullptr || node->GetValue() == '.')
		return;
	else if (node->GetValue() == value) {
		node->SetLeft(new Node(left));
		node->SetRight(new Node(right));
		isFind = true;
		return;
	}

	SetValue(node->GetLeft(), value, left, right);
	SetValue(node->GetRight(), value, left, right);
}


int main(void) {
	int N;
	cin >> N;

	char value, left, right;
	
	cin >> value >> left >> right;

	Node* root = new Node(value);
	root->SetLeft(new Node(left));
	root->SetRight(new Node(right));

	for (int i = 1; i < N; i++) {
		cin >> value >> left >> right;

		isFind = false;
		SetValue(root, value, left, right);
	}

	Preorder(root); cout << '\n';
	Inorder(root); cout << '\n';
	Postorder(root); cout << '\n';
}
