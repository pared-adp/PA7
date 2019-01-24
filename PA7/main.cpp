#include "BST.h"

int main(void) {
	BST tree;
	fstream convert;
	tree.print();
	char convertSent[1000];
	char key=' ';
	convert.open("convert.txt");
	int j = 0;
	while (!convert.eof()) { // reads from file and inputs into the array
		convert.get(convertSent[j]);
		++j;
	}
	int i = 0;
	while (i < j-1) { // there was an off by one error causing my program to crash 
		key = convertSent[i];
		key = toupper(key);
		if (key == ' ') {
			cout << "   ";
		}
		else if (key == '\n') {
			cout << endl;
		}

		else {
			string *convert2 = new string(tree.searchTree(key)); // dynamically allocating string 
			*convert2 = tree.searchTree(key);
			cout << *convert2 << " ";
		}
		i++;
	}
	return 0;
}