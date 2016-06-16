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
#include <iostream>
#include "BQUEUE.h"

using namespace std;

int main()
{
		BQUEUE  k;

		k.Enqueue(60);
		k.Print();
		k.Enqueue(20);
		k.Enqueue(30);
		k.Print();
		k.Enqueue(10);
		k.Print();
		k.Enqueue(50);
		k.Enqueue(40);
		k.Print();

		BQUEUE j = k;

		j.Dequeue();
		j.Print();
		j.Dequeue();
		j.Dequeue();
		j.Dequeue();
		j.Print();
		j.Dequeue();
		j.Dequeue();
		j.Print();
		j.Dequeue();
		j.Dequeue();

		return 0;
}