// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW4: 6936HW4->main.cpp


////////////////////////////////////////////////////////////////////////////////
/*
Homework 4

Refer to the documenting and submitting homework from here.

Using the the sample code of linked list node1.h and node1.cpp

		Implement the list_piece() function described in exercise 24 from
		textbook page 258.

Implement a main program that takes a text file as an input (as a command line
 argument or after a prompt) and processes followings. The words in the input
 text file should be stored in a linked list, one word at a node. So you have
 to modify the node1.h to accommodate a string. Then ask the user to pick two
 words, one for the starting and one for the ending word. And search the
 original list to find a new sub-list that contains the items, as a starting
 and ending node, and print out the new list. When you print, include the last
 word. The list_piece() funciton's post condition in the textbook says the
 node pointed by the end_ptr should be excluded. So you have to implement the
 list_piece() to include the last word as well. If there's no such sub-list,
 just print out an error message.

Once you printout the new sub-list, you need to sort the sub-list (in
 dictionary order) using the insertion sort algorithm and print out the new
 sorted sub-list. When you sort the list, you must rearrange the link
 structure of nodes by updating associated pointers, not by copying/moving
 the strings between nodes.

Just in case, here's a detailed description of the insertion sort algorithm and
 a sample implementation.

http://www.algolist.net/Algorithms/Sorting/Insertion_sort

		The input text file may have sentences with punctuation marks. But to
		simplify the issue, let's assume that the text file will have only five
		punctuation marks . , ' - ? . So when you assign a string to a node,
		you need to get rid of those five punctuation marks and store only the
		word itself.

Note that the main objective of this homework is to reinforce the
 understanding of linked list by implementing pertinent functions, not getting
 a sub list by using any means. So I want you to use provided node class to
 implement this homework.

Grading guideline

Correct and complete functionality 70%
Reasonable fault tolerance, i.e. it should not crash often. 10%
Makefile and Readme 10%
Documentation and comments in the code 10%

*/


/*
24. Implement this function:
void list_piece(const node* start_ptr, const node* end_ptr,
		node*& head_ptr, node*& tail_ptr)
// Precondition: start_ptr and end_ptr are pointers to nodes on the same
// linked list, with the start_ptr node at or before the end_ptr node.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers
// for a new list that contains the items from start_ptr up to but not
// including end_ptr.  The end_ptr may also be NULL, in which case the
// new list contains elements from start_ptr to the end of the list.
*/



#include <iostream>


#include "node1.h"
using namespace main_savitch_5;




int main()
{
	// CONSTANTS

	// DECLARATIONS


	// RETURN
	return 0;
}