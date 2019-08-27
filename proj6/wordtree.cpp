/* Michael Ziegler                                       WORDTREE_IMPLIMENTATION
 * CSCI 3110-001
 * Project #4
 * Due: 04/01/19
 * 
 * File: wordtree.cpp
 * Purpose: Wordtree class implimentation for proj6 executable.
 */
#include "wordtree.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*(1)(CONSTRUCTOR)_Purpose: To create an empty 'WordTree' object, initializing
 * the root to nullptr.														  */
WordTree::WordTree()
{
	root = nullptr;
}
/*(2h)(DESTRUCTOR)_Purpose: Explicitly deletes all nodes from the tree.		  */
WordTree::~WordTree()
{
	deleteSubTree(root);
}
/*(2r)(DELETESUBTREE)_Purpose: A Recursive function called by the destructor(2)
 * to explicitely delete all allocated WordTree Nodes	                      */
void WordTree::deleteSubTree(TreeNode* newRoot)
{
	if (newRoot)
	{
		deleteSubTree(newRoot->left);
		deleteSubTree(newRoot->right);
		delete newRoot;
	}
}

/*(3h)(ADDWORD)_Purpose: A helper function that takes a string(the 
 * word to be inserted into the tree, and calls the recursive function 		  */
void WordTree::addWord(std::string wrd)
{
	addWord(root, wrd);
}

/*(3r)(ADDWORD)_Purpose: A Recursive function that adds a node containing the 
 * word to the tree, accounts for duplicates by incrementing it's count if the 
 * word is already in the (BST)tree.									  	  */
void WordTree::addWord(struct TreeNode *& newRoot, string wrd)
{
	if (newRoot == nullptr)
	{
		newRoot = new TreeNode;
		newRoot->value = wrd;
		newRoot->left = nullptr;
		newRoot->right = nullptr;
	newRoot->count = 1;
	}
	else if (wrd < newRoot->value)
	{
		addWord(newRoot->left, wrd);
	}
	else if (wrd > newRoot->value)
	{
		addWord(newRoot->right, wrd);
	}
	else if (newRoot->value == wrd)
	{
		newRoot->count++;
	}
}
/*(4)(FINDWORD)_Purpose: An Iterative function that searches for a word in the
 * tree. If the word is found, it outputs the word and its occurrence count. 
 * Otherwise, it displays a message stating that the word was not found.  	  */
void WordTree::findWord(std::string word)
{
    TreeNode* curr = root;

    while(curr != NULL && curr->value != word)
	{
        if (word > curr->value)
		{
            curr = curr->right;
        }
        else
		{
            curr = curr->left;
        }
    }
    if (curr == NULL)
	{
        std::cout << "The word '" << word << "' was not found in the text.\n" <<
		std::endl;
    }
    else 
	{
        std::cout << "The word '" << word << "' occurs " << curr->count <<
		" time(s) in the text.\n" << std::endl;
    }
}
/*(5h)(GETCOUNTS)_Purpose: A helper function that takes an integer threshold
 * value and calls the recursive function. It also outputs the number of words
 * meeting the query, upon returning from the recursive function.             */
void WordTree::getCounts(int num)
{
	int total = 0;
	getCounts(root, num, total);
	cout << total << " nodes had words with " << num << " or more occurrence(s)\
	.\n";
}
/*(5r)(GETCOUNTS)_Purpose: A Recursive function that traverses the tree in order,
 * outputting the words that meet or exceed the threshold, along with their 
 * counts, and updating the accumulator(total).  							  */ 
void WordTree::getCounts(TreeNode * newRoot, int num, int& total) const
{
	if (newRoot != nullptr)
	{
		getCounts(newRoot->left, num, total);
		if (newRoot->count >= num)
		{
			cout << newRoot->value << "(" << newRoot->count << ")\n";
			total++;
		}
		getCounts(newRoot->right, num, total);
	}
}
