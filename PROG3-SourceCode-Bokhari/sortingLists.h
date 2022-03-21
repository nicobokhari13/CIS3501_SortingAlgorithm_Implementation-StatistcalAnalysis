#pragma once
#ifndef SORTINGLISTS_H
#define	SORTINGLISTS_H
#include <iostream>
#include "globals.h"
#include <stdlib.h> //srand, rand
#include <time.h> //time 
using namespace std;
class sortingLists
{
public: 
	sortingLists();
	int* numArray; 
	int size;
	void swap(int* seq, int ind1, int ind2);
	void printList() {
		for (int i = 0; i < size; i++) {
			cout << numArray[i] << ", "; 
		}
	}
	//PRECONDITION: The list is created
	//POSTCONDITION: The list is a full sorted list 
	void setList(int s); 
	//specific to quickSort
	//int pivot; last element and randomized 
	void quickSort(bool type);
	void detQuickSort(int* seq, int begin, int end);
	void randQuickSort(int* seq, int begin, int end);
	//specific to mergeSort
	void mergeSort(int* seqList, int firstPos, int lastPos); 
	void merge(int* list, int firstPos, int middle, int lastPos);
};
#endif
