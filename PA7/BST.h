#pragma once
#include "Node.h"

using namespace std;

class BST {
public:
	// constructor
	BST();
	// deconstructor
	~BST();
	string searchTree(char key);
	void print();
	void insertInBST(string newLine, char newLetter);
	// getter
	Node *getRoot() const;

private:
	Node *mpRoot;
	// private functions
	Node *makeNode(string newLine, char newLetter); 
	void insertInBST(Node *&root, string newLine, char newLetter);
	void destroyer(Node *root);
	void printTree(Node *root);
	Node *& searchTree(Node *&pRoot, char key);
};