// BRIAN SUMNER
// xxxxx6936
// CSCI 2421-E01
// SPRING 2016
// HW4: 6936HW4->list_demo.h

#ifndef UCD_CSCI2421_HW4_LIST_DEMO_H
#define UCD_CSCI2421_HW4_LIST_DEMO_H




#include "node1.h"
using namespace main_savitch_5;



namespace list_demo
{

	void processFile(std::ifstream &arg_inputFile, node* &arg_ptr_headNode, node* &arg_ptr_tailNode);

	void generateSublist(node* &arg_ptr_headNode, node* &arg_ptr_tailNode,
						 node* &arg_ptr_sublistHeadNode, node* &arg_ptr_sublistTailNode);




};


#endif //UCD_CSCI2421_HW4_LIST_DEMO_H
