#include "sortingLists.h"
sortingLists::sortingLists() {
}
void 
sortingLists::setList(int s) {
	delete numArray;
	size = s;
	numArray = new int[size];
	for (int i = 0; i < size; i++) {
		numArray[i] = i;
	}
}
void 
sortingLists::swap(int* seq, int ind1, int ind2) {
	int temp = seq[ind1]; 
	seq[ind1] = numArray[ind2];
	seq[ind2] = temp; 
}
void
sortingLists::mergeSort(int* seqList, int firstPos, int lastPos) {
	if (firstPos >= lastPos) {//if the seq has size 1, 
		return; 
	}
	int middle = (firstPos + lastPos) / 2;
	mergeSort(seqList, firstPos, middle);
	mergeSort(seqList, middle + 1, lastPos);
	merge(seqList, firstPos, middle, lastPos);
}
void
sortingLists::merge(int* list, int firstPos, int middle, int lastPos) {
	int sizeList1 = middle - firstPos + 1; 
	int sizeList2 = lastPos - middle; 
	int* list1 = new int[sizeList1];
	int* list2 = new int[sizeList2];
	int indL1 = 0; 
	int indL2 = 0; 
	int indMerged = firstPos; 
	for(int i = 0; i < sizeList1; i++) {
		list1[i] = list[firstPos + i]; //list1 is from 0 to middle
	}
	for (int j = 0; j < sizeList2; j++) {
		list2[j] = list[middle + j + 1];//list 2 is from middle + 1 to end
	}
	while (indL1 != sizeList1 && indL2 != sizeList2) {
		if (list1[indL1] < list2[indL2]) {
			list[indMerged] = list1[indL1];
			indL1++;
		}
		else {
			list[indMerged] = list2[indL2];
			indL2++; 
		}
		indMerged++;
		compMerge++; 
	}
	//indL2 = sizeList2, so "list2 is empty" 
	while (indL1 != sizeList1) {
		list[indMerged] = list1[indL1];
		indL1++;
		indMerged++; 
	}
	//indL1 = sizeList1, so "A is empty" 
	while (indL2 != sizeList2) {
		list[indMerged] = list2[indL2];
		indL2++; 
		indMerged++; 
	}
}
void 
sortingLists::quickSort(bool type) {
	if (type)
		detQuickSort(numArray, 0, size - 1);
	else
		randQuickSort(numArray, 0, size - 1);
}
void 
sortingLists::detQuickSort(int* seq, int begin, int end) {
	if (begin >= end){
		return; 
	}
	int pivot = seq[end];
	int first = begin; 
	int last = end; 
	while (first <= last) {
		while (seq[first] < pivot) {
			first++; 
			compQuickDet++;
		}//exits when seq[first] is greater than pivot
		while (seq[last] > pivot) {
			last--; 
			compQuickDet++;
		}//exits when seq[last] is less than pivot
		if (first <= last) {
			//code gets here when seq[first] and seq[last] must swap
			//if first is NOT less than or equal to last, everything is checked and left half of array < pivot and right half > pivot
			swap(seq, first, last);
			first++;
			last--; 
		}
	}
	detQuickSort(seq, begin, last); 
	detQuickSort(seq, first, end);
}
void 
sortingLists::randQuickSort(int* seq, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int pos = begin + rand() % (end - begin + 1);
	int pivot = seq[pos]; //pivot = random number 
	int first = begin;
	int last = end;
	while (first <= last) {
		while (seq[first] < pivot) {
			compQuickRand++;
			first++;
		}//exits when seq[first] is greater than pivot
		while (seq[last] > pivot) {
			compQuickRand++;
			last--;
		}//exits when seq[last] is less than pivot
		if (first <= last) {
			//code gets here when seq[first] and seq[last] must swap
			//if first is NOT less than or equal to last, everything is checked and half < pivot and other half > pivot
			swap(seq, first, last);
			first++;
			last--;
		}
	}
	randQuickSort(seq, begin, last);
	randQuickSort(seq, first, end);
}
