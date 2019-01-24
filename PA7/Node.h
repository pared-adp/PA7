#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
	// constructor
	Node(string &newLine, char newLetter);
	//destructor
	~Node();
	//getters
	Node *& getRightPtr();
	Node *& getLeftPtr();
	string & getLine();
	char getLetter();
	// setters
	void setRightPtr(Node *newRightPtr);
	void setLeftPtr(Node *newLeftPrt);
	void setLine(string &newLine);
	void setLetter(char newLetter);

private:
	string mLine;
	char mLetter;
	Node *mpLeft;
	Node *mpRight;
};