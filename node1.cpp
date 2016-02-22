// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW4: 6936HW4->node1.cpp



// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <iostream>
#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{

	size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			++answer;

		return answer;
    }
    
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
		head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry) 
    {
		node *insert_ptr;

		insert_ptr = new node(entry, previous_ptr->link( ));
		previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
    {
		node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			if (target == cursor->data( ))
				return cursor;
		return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
    {
		const node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			if (target == cursor->data( ))
				return cursor;
		return NULL;
    }

    node* list_locate(node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
    {
		node *cursor;
		size_t i;

		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link( );
		return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
    {
		const node *cursor;
		size_t i;

		assert (0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link( );
		return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
		node *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link( );
		delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
		node *remove_ptr;

		remove_ptr = previous_ptr->link( );
		previous_ptr->set_link( remove_ptr->link( ) );
		delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
		while (head_ptr != NULL)
		{
///*DEBUG*/	std::cout << "[LENGTH = " << list_length(head_ptr) << "      REMOVING HEAD]\n";
			list_head_remove(head_ptr);
		}
///*DEBUG*/	std::cout << "[LIST CLEARED]\n";
	}

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) 
    // Library facilities used: cstdlib
    {
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data( ));
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link( );
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data( ));
			tail_ptr = tail_ptr->link( );
			source_ptr = source_ptr->link( );
		}
    }


	ostream &operator<<(ostream &outs, const node* arg_ptr_headNode)
	{
		const node* cursor;

		for (cursor = arg_ptr_headNode; cursor != NULL; cursor = cursor->link( ))
		{
			outs << cursor->data() << "\n";
		}

		return outs;
	}



	//	Then ask the user to pick two
	//	words, one for the starting and one for the ending word. And search the
	//	original list to find a new sub-list that contains the items, as a starting
	//	and ending node, and print out the new list. When you print, include the last
	//	word. The list_piece() function's post condition in the textbook says the
	//	node pointed by the end_ptr should be excluded. So you have to implement the
	//	list_piece() to include the last word as well. If there's no such sub-list,
	//	just print out an error message.
	//

	// Precondition: start_ptr and end_ptr are pointers to nodes on the same
	// linked list, with the start_ptr node at or before the end_ptr node.
	// Postcondition: head_ptr and tail_ptr are the head and tail pointers
	// for a new list that contains the items from start_ptr up to but not
	// including end_ptr.  The end_ptr may also be NULL, in which case the
	// new list contains elements from start_ptr to the end of the list.

	void list_piece(const node* start_ptr, const node* end_ptr,
					node*& head_ptr, node*& tail_ptr)
	{
		const node* inputCursor;

		node* outputCursor;
			  outputCursor = head_ptr;

		node::value_type endData;

		bool encounteredEndData;
			 encounteredEndData = false;

		// SET ENDDATA TO VALID VALUE OR SENTINEL
		if (end_ptr != NULL)
			endData = end_ptr->data();
		else
			endData = "<<<>>>";


		for (inputCursor = start_ptr;
			 inputCursor != NULL && !encounteredEndData;
			 inputCursor = inputCursor->link())
		{
			// INSERT CURRENT DATA INTO NEW SUBLIST NODE
			list_insert(outputCursor, inputCursor->data());
			outputCursor = outputCursor->link();

			// IF ENDDATA ENCOUNTERED THEN SET FLAG
			if (outputCursor->data() == endData)
			{
///*DEBUG*/    std::cout << "ENDING LOOP\n";
				encounteredEndData = true;
			}

		}

	//	list_copy(start_ptr, head_ptr, tail_ptr);
	}


	bool isStartWordBeforeEndWord(const node *searchResultStartWord, const node *searchResultEndWord)
	{

		// USE MODIFIED GENERIC FUNCTION

		const node* cursor;

		if (searchResultEndWord != NULL)
		{

			if (searchResultStartWord == searchResultEndWord)
				return true;


			node::value_type endWord;
			endWord = searchResultEndWord->data();


			for (cursor = searchResultStartWord;
				 cursor != NULL;
				 cursor = cursor->link())
					if (cursor->data() == endWord)
						return true;
		}

	return false;
	}



	void list_sort(node* &arg_ptr_headNode)
	{
		// THIS ALGORITHM WAS DEVELOPED BY TRACING THROUGH LISTS MADE OF PAPER
		// CARDS ARRANGED ON THE LIVING ROOM FLOOR.  IF YOU ARE HAVING TROUBLE
		// DEBUGGING THIS FUNCTION, AND YOU'RE NOT TRACING THROUGH LISTS MADE
		// OF PAPER CARDS, THEN YOU'RE NOT TRYING HARD ENOUGH.  NOW WITHOUT
		// FURTHER ADO, BRIAN SUMNER'S LINKED LIST INSERTION SORT ALGORITHM:

		// DECLARATIONS
			// NODE POINTER CURSOR
				// NODE POINTER NEXTC
			// NODE POINTER MINICURSOR
				// NODE POINTER PREVM

		// CURSOR = ARG_PTR_HEAD
		// NEXTC = CURSOR->LINK
		// WHILE (NEXTC !== NULL)
			// CURSOR = NEXTC
			// NEXTC = CURSOR->LINK
			// IF (NEXTC != NULL) THEN
				// IF (CURSOR->DATA > NEXTC->DATA) THEN
					// PREVM = ARG_PTR_HEAD
					// MINI = PREVM->LINK
					// WHILE (MINI != NEXTC || CURSOR->DATA > NEXTC->DATA)
						// IF (MINI == NEXTC) THEN
							// PREVM = ARG_PTR_HEAD
							// MINI = PREVM->LINK
						// ENDIF
						// IF (MINI->DATA > NEXTC->DATA) THEN
							// CURSOR->SET_LINK(NEXTC->LINK)
							// PREVM->SET_LINK(NEXTC)
							// NEXTC->SET_LINK(MINI)
							// NEXTC = CURSOR->LINK
							// MINI = NEXTC
						// ELSE
							// PREVM = MINI
							// MINI = PREVM->LINK
						// ENDIF
					// ENDWHILE
				// ENDIF
			// ENDIF
		// ENDWHILE



		// DECLARATIONS
		// NODE POINTER CURSOR = OUTER LOOP CURSOR
		// NODE POINTER NEXTC = NODE AFTER CURSOR
		// NODE POINTER MINICURSOR = INNER LOOP CURSOR
		// NODE POINTER PREVM = NODE BEFORE MINICURSOR
		node* cursor = NULL;
		node* nextc = NULL;
		node* minicursor = NULL;
		node* prevm = NULL;

///*DEBUG*/	std::cout << arg_ptr_headNode;

		// CURSOR = ARG_PTR_HEAD
		cursor = arg_ptr_headNode;

		// NEXTC = CURSOR->LINK
		nextc = cursor->link();

		// WHILE (NEXTC !== NULL)
		while (nextc != NULL)
		{

			// CURSOR = NEXTC
			cursor = nextc;

			// NEXTC = CURSOR->LINK
			nextc = cursor->link();

			// IF (NEXTC != NULL) THEN
			if (nextc != NULL)
			{

				// IF (CURSOR->DATA > NEXTC->DATA) THEN
				if (cursor->data() > nextc->data())
				{

					// PREVM = ARG_PTR_HEAD
					prevm = arg_ptr_headNode;

					// MINI = PREVM->LINK
					minicursor = prevm->link();


					// WARNING: NEVER DEREFERENCE THE NULL POINTER!!
					// WHILE (MINI != NEXTC || CURSOR->DATA > NEXTC->DATA)
					// NOTE: SOMETIMES MINI == NEXTC AND NEXTC->DATA < CURSOR->DATA
					while ((minicursor != nextc) ||
						  	 (nextc != NULL && cursor->data() > nextc->data()))
					{

///*DEBUG*/	std::cout << "AFTER CRASH\n";

						// IF (MINI == NEXTC) THEN
						// NOTE: THIS PREVENTS NEXTC FROM GETTING SKIPPED ON
						// NEXTC->DATA < CURSOR->DATA STILL AFTER INSERTION
						if (minicursor == nextc)
						{
							// PREVM = ARG_PTR_HEAD
							prevm = arg_ptr_headNode;

							// MINI = PREVM->LINK
							minicursor = prevm->link();

							// ENDIF
						}
						// IF (MINI->DATA > NEXTC->DATA) THEN DO INSERTION
						if (minicursor->data() > nextc->data())
						{

							// CURSOR->SET_LINK(NEXTC->LINK)
							cursor->set_link(nextc->link());

							// PREVM->SET_LINK(NEXTC)
							prevm->set_link(nextc);

							// NEXTC->SET_LINK(MINI)
							nextc->set_link(minicursor);

							// NEXTC = CURSOR->LINK
							nextc = cursor->link();

							// MINI = NEXTC
							minicursor = nextc;

						}
						// ELSE ADVANCE MINI
						else
						{
							// PREVM = MINI
							prevm = minicursor;

							// MINI = PREVM->LINK
							minicursor = prevm->link();

							// ENDIF
						}

///*DEBUG*/	std::cout << "ENDWHILE GONNA CRASH\n";

						// ENDWHILE
					}
					// ENDIF
				}
				// ENDIF
			}
			// ENDWHILE
		}
		// END FUNCTION
	}



	// END NAMESPACE
}
