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

class bqnode
{

public:

	int time; //data

	bqnode *prev; //pointers
	bqnode *next;

};

class BQUEUE
{

public:

	BQUEUE(); //con/de-structors
	~BQUEUE();
	BQUEUE(const BQUEUE &);

	void Enqueue(int);//functions
	void Dequeue();
	void Print();

private:

	bqnode *front; //pointer to front
};