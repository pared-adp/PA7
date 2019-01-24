#include "Node.h"
// Node constructor
Node::Node(string & newLine, char newLetter)
{
	this->mLine = newLine;
	this->mLetter = newLetter;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}
// destructor
Node::~Node()
{
}
// getters
Node *& Node::getRightPtr()
{
	return this->mpRight;
}

Node *& Node::getLeftPtr()
{
	return this->mpLeft;
}

string & Node::getLine()
{
	return this->mLine;
}

char Node::getLetter()
{
	return this->mLetter;
}
//setters
void Node::setRightPtr(Node * newRightPtr)
{
	this->mpRight = newRightPtr;
}

void Node::setLeftPtr(Node * newLeftPrt)
{
	this->mpLeft = newLeftPrt;
}

void Node::setLine(string & newLine)
{
	this->mLine = newLine;
}

void Node::setLetter(char newLetter)
{
	this->mLetter = newLetter;
}
