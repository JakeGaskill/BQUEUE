/********************************************************************************************
Name: Jacob Gaskill                    Z#: 23236263
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  3/25/2016           Due Time: 11:00 PM
Total Points: 100
Assignment 6: Queue Program

Description: In this assignment, we:
(1) manipulate pointers, (2) allocate memory dynamically,
(3) implement a default constructor, copy constructor and destructor,
(4) use only one pointer to add to the back and to dequeue from the front of the queue.
*********************************************************************************************/

#include "BQUEUE.h"
#include<iostream>
using namespace std;

/**********************************************************************************************
Name:	BQUEUE
Precondition: The state of the object (private data) has not been initialized
Postcondition: The state has been initialized to the default values described below
Description:  This is the default constructor which will be called automatically when
an object is declared.  It will initialize the state of the class.
***********************************************************************************************/
BQUEUE::BQUEUE()
{
	front = new bqnode; //front node
	front->next = NULL;
	front->prev = NULL;
	front->time = -1; //set front pointer time to flag value
}

/**********************************************************************************************
Name:	~BQUEUE
Precondition: The state of the object (private data) has been initialized
Postcondition: Memory is de-allocated
Description:  This is the destructor which de-allocates memory and "deletes" the circular queued list
***********************************************************************************************/
BQUEUE::~BQUEUE()
{
	while (front->time != -1) //while loop to delete
	{
		delete front; //delete
		front = front->next; //front now points next and we repeat
	}
}

/**********************************************************************************************
Name:	BQUEUE
Precondition: The state of the object (private data) has not been initialized
Postcondition: The state has been initialized to the values of the explicit object
Description:  This is the copy constructor which will create an identical circular queue of the 
explicit argument and copy it to the implicit argument.
***********************************************************************************************/
BQUEUE::BQUEUE(const BQUEUE &org)
{
	front = org.front; //implicit front now = explicit front...
}

/**********************************************************************************************
Name:	Enqueue
Precondition: The state of the object (private data) has been initialized
Postcondition: An integer has been added to the queue
Description:  This function, enqueue, inserts an integer into the queue.
***********************************************************************************************/
void BQUEUE::Enqueue(int orgTime)
{
	bqnode *newNode = new bqnode; //new node
	newNode->time = orgTime; //time = int passed

	bqnode *temp = new bqnode; //temp...
	temp = front;

	if (front->next == NULL) //if front->next is null, the list is empty...
	{
		newNode->next = front; //make first node
		newNode->prev = temp;

		temp->next = newNode;
		front->prev = newNode;
	}

	else //else means queue has at least one element...
	{
		while (temp->next->time != -1) //add to the end of the queue
		{
			temp = temp->next;
		}

		newNode->next = front;
		newNode->prev = temp;

		temp->next = newNode;
		front->prev = newNode;
	}

	cout << orgTime << " has been enqueued." << endl;

}

/**********************************************************************************************
Name:	Dequeue
Precondition: The state of the object (private data) has been initialized
Postcondition: An integer is removed from the queue
Description:  This function, Dequeue, takes an integer out of the queue.
***********************************************************************************************/
void BQUEUE::Dequeue()
{
	if (front->next->time != -1) //if true, there is at least one element in the queue...
	{
		cout << front->next->time	//cout statement
			<< " has been dequeued." << endl;
		
		front->next = front->next->next; //next points next
		front->next->prev = front;	//previous unlinked
	}

	else
		cout << "Error, queue is empty!" << endl; //error message (empty)
}


/**********************************************************************************************
Name:	Print
Precondition: The state of the object (private data) has been initialized
Postcondition: The queue is displayed in the output.
Description:  This function, Print, displays all integers within the queue.
***********************************************************************************************/
void BQUEUE::Print()
{
	bqnode *temp = new bqnode; //temp node
	temp = front;

	if (temp->next == NULL) //checks if empty
	{
		cout << "Error, queue is empty!" << endl; //error message (empty)
	}

	else
	{
		cout << "Time in queues include: " << endl; //cout statement

		while (temp->next->time != -1) //while !empty
		{
			cout << "\t" << temp->next->time << endl; //print time

			temp = temp->next; //temp node point next
		}
	}
}

