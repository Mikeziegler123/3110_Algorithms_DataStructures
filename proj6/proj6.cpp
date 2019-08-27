/* Michael Ziegler                                                DRIVER_PROGRAM
 * CSCI 3110-001
 * Project #6
 * Due: 04/01/19
 * File: proj6.cpp
 * 
 * Purpose: Driver program for proj6.cpp
 * 	This program opens and reads input from a file named input.txt, and in turn 
 *  builds ip a binary search tree of words and counts as it progresses. The 
 *  The Wordsare stored in alphabetical order among the tree. This program 
 * ignores the case of words varying between upper and lowerr case(Ex:Branch vs.
 * branch), while words that are spelled differently are stored in the tree 
 * separately. ALL nodes will be stored in the tree in their lowercase form.
 *   
 * _(QUERIES.TXT)_: TWO forms of queries are supported by the wordtree class:
 * 			
 * 		(1)->['F']: A query for an individual word, which returns the number of 
 *             occurances within the input file.
 * 		(2)->['C']: A query for words that meet or exceed a specified threshold 
 * 			    of occurances within the input file. 
 *   
 * This program achieves these goals using an INORDER traversal of the binary
 * search tree(BST).
 */
#include "wordtree.h"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
using namespace std;


int main()
{
	string text;
	char ch;
	string word;
	int num;
	
	vector<string> myVec;	//Initalize vector 'myVec' container to create BST.
	WordTree Tree;       	//Initalize Binary Search Tree (BST).

	ifstream myin;
	ifstream myinQ;
	myin.open("input.txt");							  // open 'input.txt' file

	if (!"input.txt")
	{
		cerr << "File not found" << endl;
		exit(1);
	}
	getline(myin, text);
	
	// transform all words to lower case
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	
	// stores lowercase words from 'input.txt' into the vector 'myVec' 
	size_t pos = 0, found;
	while ((found = text.find_first_of(' ', pos)) != std::string::npos)
	{
		myVec.push_back(text.substr(pos, found - pos));
		pos = found + 1;
	}
	myVec.push_back(text.substr(pos));
	
	// initializes Binary search tree from vector data
	for (unsigned int i = 0; i < myVec.size(); i++)
	{
		Tree.addWord(myVec[i]);
	}
	cout << "Word tree built and loaded\n\n";
	myin.close();									  // close 'input.txt' file
	
	/*------------------------------------------------------------------------*/
	
	myinQ.open("queries.txt");				   	 	  // open 'queries.txt' file	
	if (!"queries.txt")
	{
		cerr << "File not found" << endl;
		exit(1);
	}
	while(!(myinQ.eof()))
	{
		myinQ >> ch;
		if(ch == 'C')
		{
			myinQ >> num;
			cout << "Finding all words with " << num << " or more occurrences:\n";
			Tree.getCounts(num);
			cout << endl;
			ch = ' ';
		}
		else if(ch == 'F')
		{
			myinQ >> word;
			cout << "Searching for occurrences of the word '" << word << "'\n";
			Tree.findWord(word);
			ch = ' ';
		}
	}
	myinQ.close();									 // close 'queries.txt' file
return 0;
}
