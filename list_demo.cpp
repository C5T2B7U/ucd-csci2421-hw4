// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW4: 6936HW4->list_demo.cpp



#include <iostream>
#include <cstdlib> // Provides size_t and NULL
#include <string> // STRING TYPE
#include <fstream> // FOR FILE
#include <cctype> // FOR ISSPACE, ISPUNCT

#include "list_demo.h"
#include "node1.h"
using namespace main_savitch_5;


namespace list_demo
{

	void processFile(std::ifstream &arg_inputFile, node* &arg_ptr_headNode, node* &arg_ptr_tailNode)
	{
		// DECLARATIONS
		std::string line, buffer;
		int index = 0;
		node* cursor = arg_ptr_headNode;
		node* ptr_prevNode = NULL;

		// WHILE NOT FILE FAIL
		while (!arg_inputFile.fail())
		{
			// CLEAR BUFFER
			buffer = "";

			// GETLINE
			getline(arg_inputFile, line);

			// GUARANTEE LAST WORD INSERTED INTO LIST
			line += " ";

///*DEBUG*/	std::cout << line << "\n";

			/*The input text file may have sentences with punctuation marks. But to
			simplify the issue, let's assume that the text file will have only five
			punctuation marks . , ' - ? . So when you assign a string to a node,
			you need to get rid of those five punctuation marks and store only the
			word itself.*/

			// TEST EACH CHARACTER
			while (index < line.length())
			{
				// IF NOT ISPUNCT LINE[INDEX] AND NOT ISSPACE LINE[INDEX]
				if (!std::isspace(line[index]) && !std::ispunct(line[index]))
				{
					// THEN BUFFER += LINE[INDEX]
					buffer += line[index];
				}
				// ELSE IF BUFFER != "" THEN STORE BUFFER TO NEW NODE
				else if (buffer != "")
				{

///*DEBUG*/	std::cout << "[INDEX = " << index << "   LENGTH = " << line.length() << "   NODES = " << list_length(arg_ptr_headNode) << "   INSERTING BUFFER = " << buffer << "]\n";

					// INSERT NEW NODE WITH BUFFER
					list_insert(cursor, buffer);

					// UPDATE POINTERS
					ptr_prevNode = cursor;
					cursor = cursor->link();

					// RESET BUFFER
					buffer = "";
				}
				// ELSE DISREGARD CHARACTER

				// INDEX++
				index++;

			// ENDWHILE
			}
			// END OF LINE REACHED

			// RESET INDEX
			index = 0;

		// ENDWHILE
		}
		// END OF FILE

	// RETURN TAIL POINTER
	// IF NOT FILE OPEN OR EMPTY LIST THEN RETURN HEAD POINTER
	arg_ptr_tailNode = cursor;
	}




//	Then ask the user to pick two words, one for the starting and one for the
//	ending word. And search the original list to find a new sub-list that
//	contains the items, as a starting and ending node, and print out the new
//	list. When you print, include the last word.  If there's no such sub-list,
//  just print out an error message.
	void generateSublist(node* &arg_ptr_headNode, node* &arg_ptr_tailNode,
						 node* &arg_ptr_sublistHeadNode, node* &arg_ptr_sublistTailNode)
	{
		// DECLARATIONS
		node::value_type startWord, endWord;
		node* ptr_searchResultStartWord;
		node* ptr_searchResultEndWord;

//		ptr_searchResultEndWord = NULL;
//		ptr_searchResultStartWord = NULL;


		// PROMPT STARTING WORD
		std::cout << "PLEASE ENTER START WORD>  ";
		std::cin >> startWord;

		std::cout << "PLEASE ENTER END WORD>  ";
		std::cin >> endWord;

		std::cout << "GENERATING SUBLIST: " << startWord << " TO " << endWord << "\n";


		// SEARCH START NODE
		ptr_searchResultStartWord = list_search(arg_ptr_headNode, startWord);

///*DEBUG*/	if (ptr_searchResultStartWord != NULL) std::cout << "FOUND START WORD -> " << ptr_searchResultStartWord->data() << "\n";


		// SEARCH END NODE
		ptr_searchResultEndWord = list_search(arg_ptr_headNode, endWord);

///*DEBUG*/	if (ptr_searchResultEndWord != NULL) std::cout << "FOUND END WORD -> " << ptr_searchResultEndWord->data() << "\n";


		// SUBLIST POINTERS WERE INITIALIZED WITH NULL
		// HEAD == NULL MEANS START WORD NOT FOUND OR EMPTY LIST
		// TAIL == NULL MEANS END WORD NOT FOUND
		if (ptr_searchResultStartWord != NULL &&
				isNodeBefore(ptr_searchResultStartWord, ptr_searchResultEndWord))
		{

	//		list_insert(arg_ptr_sublistHeadNode, ptr_searchResultStartWord->data());
	//		arg_ptr_sublistHeadNode->set_data(ptr_searchResultStartWord->data());
	//		arg_ptr_sublistHeadNode->set_link(ptr_searchResultStartWord->link());



			list_piece(ptr_searchResultStartWord, ptr_searchResultEndWord,
					   arg_ptr_sublistHeadNode, arg_ptr_sublistTailNode);
///*DEBUG*/	std::cout << "FOUND START WORD -> " << arg_ptr_sublistHeadNode->data() ;


		}
		else if (ptr_searchResultStartWord == NULL)
		{
			// DISPLAY ERROR
			std::cout << "ERROR: CANNOT GENERATE SUBLIST (START WORD NOT FOUND)\n";
		}
		else
		{
			std::cout << "ERROR: CANNOT GENERATE SUBLIST (END WORD DOES NOT FOLLOW START WORD)\n";
		}


	}







};

