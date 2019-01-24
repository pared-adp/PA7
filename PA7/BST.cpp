#include "BST.h"
// destructor
void BST::destroyer(Node *pRoot) {
	if (pRoot != nullptr) {
		destroyer(pRoot->getLeftPtr());
		destroyer(pRoot->getRightPtr());
		delete(pRoot);
	}
}
BST::~BST()
{
	destroyer(mpRoot);
}
// constructor
BST::BST()
{
	this->mpRoot = nullptr;
	fstream morse;
	morse.open("morse.txt");
	string letter;
	char mainLetter;
	string line;
	if (morse.is_open()) {
		while (!morse.eof()) {
			getline(morse, letter, ':');
			char *letter2 = new char[letter.length() + 1];
			strcpy(letter2, letter.c_str());
			mainLetter = *letter2;
			getline(morse, line, '\n');
			insertInBST(line, mainLetter);
		}
	}
	morse.close();
}

// search tree public function
string BST::searchTree(char key)
{
	Node *temp;
	string returnData = "";
	temp = searchTree(this->mpRoot, key);
	returnData = temp->getLine();
	return returnData;
}
// private function of search tree
Node *& BST::searchTree(Node *& pRoot, char key)
{	// ask to get looked at 
	if (pRoot != nullptr) {
		if (pRoot->getLetter() == key) {
			return pRoot;
		}
		else if (pRoot->getLetter() > key) {
			searchTree(pRoot->getLeftPtr(), key);
		}
		else if (pRoot->getLetter() < key) {
			searchTree(pRoot->getRightPtr(), key);
		}
	}
}
// private print function
void BST::printTree(Node *root) {
	if (root != nullptr) {
		printTree(root->getLeftPtr());
		cout << "Letter: " << root->getLetter() << " "<< "Line: " << root->getLine() << endl;
		printTree(root->getRightPtr());
	}
}
// public print function
void BST::print()
{ 
	printTree(this->mpRoot);
}
// public insert
void BST::insertInBST(string newLine, char newLetter)
{
	insertInBST(this->mpRoot, newLine, newLetter);
}
// getter
Node * BST::getRoot() const
{
	return this->mpRoot;
}
// private make node
Node * BST::makeNode(string newLine, char newLetter)
{
	Node *newNode = nullptr;
	newNode = new Node(newLine, newLetter);
	return newNode;
}
// private insert
void BST::insertInBST(Node *& root, string newLine, char newLetter)
{
	Node * current;
	if (this->mpRoot == nullptr) {
		Node *n = new Node(newLine, newLetter);
		mpRoot = n;
	}
	else if (root == nullptr) {
		Node * n = new Node(newLine, newLetter);
		root = n;
	}
	else {
		if (newLetter < root->getLetter()) {
			insertInBST((root)->getLeftPtr(), newLine, newLetter);
		}
		else {
			insertInBST((root)->getRightPtr(), newLine, newLetter);
		}
	}
}



