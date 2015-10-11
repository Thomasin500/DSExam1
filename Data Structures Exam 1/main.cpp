#ifndef MAIN_CPP
#define MAIN_CPP

// Exam 1 Solutions - Data Structures Fall 2015
// This project is to demonstrate the correct algorithms and answers to select questions of Exam 1
// Solutions are not provided, these were created independently before receiving my graded exam

//Question 1: merge 2 sorted array
//question 2: insert a new element into a sorted circular linked list.

#include <iostream>

using namespace std;


template <class T>
int main() {

	//insert a new node into a sorted circular linked list
	template  <class T>
	void insertSorted(T val) {
	
		Node * newNode = new Node(val);

		Node * temp = head;

		int counter = 0;

		//case 1: list is empty
		if (head == NULL) {
		
			newNode->next = newNode;
			head = newNode;
			return;			
		}
		else {
		
			//case 2: insert before head
			if (val <= head->data) {
			
				//have temp point to the last node in the list
				while (temp->next != head) temp = temp->next;

				newNode->next = head;
				temp->next = newNode;
				head = newNode;	
				return;
			}

			while (temp->next != head) {

				//case 3: insert after head somewhere
				if (temp->data <= val && temp->next->data >= val) {

					newNode->next = temp->next;
					temp->next = newNode;
					return;
				}
				//case 4: insert at the end of the list (val is greatest value)
				else if (temp->data <= val && temp->next->data <= val) {
					
					newNode->next = temp->next;
					temp->next = newNode;
					return;				
				}

				temp = temp->next;
			}			
		}	
	}

	//merge 2 sorted arrays
	void mergeSorted() {
	
		int array1 = {1,3,5};
		int array2 = {0,2,4,6};

		int array1Size = 3;
		int array2Size = 4;

		int result [array1Size + array2Size];

		int i = 0;
		int j = 0;
		int k = 0;

		while (i < array1Size && j < array2Size) {
		
			if (array1[i] <= array2[j]) {
			
				result[k] = array1[i];
				i++;
			} 
			else {

				result[k] = array2[j];
				j++;
			}
			k++;
		}
		if (i < m) { //allow for different size arrays

			int p = i;

			for (p; p < array1Size; p++) {
			
				result[k] = array1[p];
				k++;
			}
		}
		else {	//allow for different size arrays
		
			for (int p = j; p < array2Size; p++) {

				result[k] = array2[p];
				k++;
			}		
		}
	}

	cin.ignore();


	return 0;
}



#endif