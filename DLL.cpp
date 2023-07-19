/* By: Adam Higazi & Nicole Kinsella */

#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}
	
	void DLL::push(string n, string a, int m, int s) {
		DNode *newNode = new DNode(n, a, m, s);
		if (first == nullptr) {
			first = newNode;
			last = newNode;
			numSongs = 1;
			return;
		}
		DNode *lastNode = last;
		lastNode->next = newNode;
		newNode->prev = lastNode;
		last = newNode;
		numSongs++;
	}

	Song *DLL::pop() { 
		if (last == NULL) {
			cout << "The list is empty." << endl;
		}
		DNode* tmp = last;
		Song *song = tmp->song;
		last = last->prev;
		if (last != NULL) {
			last->next = NULL;
		} else {
			first = NULL;
		}
		numSongs--;
		delete tmp;
	}

	void DLL::printList() {
		DNode *tmp = first;
		while (tmp != NULL){
			cout << tmp->song->title << ", " << tmp->song->artist << "................" << tmp->song->min << ":" << tmp->song->sec << endl;
			tmp = tmp->next;
		}
	}

	void DLL::moveUp(string s) {
		DNode* tmp = first;
		if (first == NULL) {
			cout << "The list is empty." << endl;
		}
		if (first->song->title == s) {
			first = first->next;
		} else {
			DNode* currentNode = first->next;
			while (currentNode != NULL && currentNode->t != s) {
				currentNode = currentNode->next;
			}
			if (currentNode != NULL) {
				currentNode->next->prev = currentNode->prev;
				currentNode->prev = currentNode->prev->prev;
				currentNode->next = currentNode->prev->next;
				currentNode->prev->next = currentNode;
			} else {
				currentNode->prev->next = NULL;
				last = currentNode->prev;
			}
		}
	}

	void DLL::listDuration(int *tm, int *ts) {
			}
			
	void DLL::moveDown(string s) {
		DNode *tmp = first;
		if (first == NULL) {
			cout << "The list is empty." << endl;
		}
		if (tmp->next == NULL){
			// Moves the bottom node to the top
			tmp->prev = NULL;
			tmp = first;
			first->prev = tmp;
		}
		while (tmp->next != NULL){
			// Moves the node down as long as it is not last
			if (tmp->song->title == s){
				tmp->prev = tmp->next;
				tmp->next = tmp->next->next;
				DNode *nextNode = tmp->next;
				nextNode->next = tmp->prev;
				nextNode->prev = tmp->prev->prev;
			}
			tmp = tmp->next;
		}
	}

	void DLL::makeRandom() {
		}
	int DLL::remove(string s) {  
		DNode *tmp;
		int i = 0;
		for (tmp = first; tmp != NULL; tmp = tmp->next){
			if (tmp->song->title == s){
				if (tmp->prev == NULL){
					// Removes from beginning
					first = tmp->next;
					tmp->next->prev = NULL;
				}
				else if (tmp->next == NULL){
					// Removes from end
					last = tmp->prev;
					tmp->prev->next = NULL;
				}
				else {
					// Removes from middle
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
				}
				delete tmp;
			}
			i++;
		}
		return i;
// note that the int returned is the index - this is standard for a remove, but we won't be using it.
		}


	DLL::~DLL(){
	}
