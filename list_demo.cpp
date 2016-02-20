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

	node*processFile_return_ptr_tailNode(std::ifstream &arg_inputFile, node *&arg_ptr_headNode)
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
	return cursor;
	}




//	Then ask the user to pick two words, one for the starting and one for the
//	ending word. And search the original list to find a new sub-list that
//	contains the items, as a starting and ending node, and print out the new
//	list. When you print, include the last word.








};

