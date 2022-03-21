//Nico Bokhari
//CIS3501-Luis Ortiz
//11/24/21
#include <iostream>
#include "sortingLists.h"
#include <vector>
#include <stdlib.h> //srand, rand
#include <time.h> //time 
#include <fstream>
using namespace std; 
void resetGlobals(); 
void genRandList(sortingLists list1, sortingLists list2, sortingLists list3, int inputSize, int numSwaps);
void trialUpdateGlobals(long double time1, long double time2, long double time3); 
void finalUpdateGlobals(int numTrials);
void runTestCase(sortingLists listMerge, sortingLists listDetQuick, sortingLists listRandQuick); 
int main()
{	//output file to store averages 
	ofstream outputFile; 
	outputFile.open("outputFile.txt"); 
	//establish random numbers
	srand(time(NULL));
	//list input sizes: 10,20,50,100,200,500,1000
	//p values: 0.0, 0.1 , 0.2 , 0.5 , 1.0 
	//m = number of swaps 
	vector <int> inputSizes = {10, 20, 50, 100, 200, 500, 750, 1000, 2000, 2500, 3000};
	vector <double> pValues = {0.0, 0.1, 0.2, 0.5, 1.0};
	sortingLists listMerge;
	sortingLists listDetQuick;
	sortingLists listRandQuick; 
	int sample = 0; 
	int numSwaps = 0; 
	double proportion = 0; 
	outputFile << "Time in ms" << endl; 
	cout << "Size:" << " " << "P-Value" << endl;
	cout << "\t" << "avg_CompMerge" << " " << "std_dev_CompMerge" << " " << "avg_cpu_Merge" << " " << "std_dev_cpu_Merge" << endl;
	cout << "\t" << "avg_CompQuickDet" << " " << "std_dev_CompQuickDet" << " " << "avg_cpu_QuickDet" << " " << "std_dev_cpu_QuickDet" << endl;
	cout << "\t" << "avg_CompQuickRand" << " " << "std_dev_CompQuickRand" << " " << "avg_cpu_QuickRand" << " " << "std_dev_cpu_QuickRand" << endl;
	cout << endl;
	outputFile << "Size:" << " " << "P-Value" << endl;
	outputFile << "\t" << "avg_CompMerge" << " " << "std_dev_CompMerge" << " " << "avg_cpu_Merge" << " " << "std_dev_cpu_Merge" << endl;
	outputFile << "\t" << "avg_CompQuickDet" << " " << "std_dev_CompQuickDet" << " " << "avg_cpu_QuickDet" << " " << "std_dev_cpu_QuickDet" << endl;
	outputFile << "\t" << "avg_CompQuickRand" << " " << "std_dev_CompQuickRand" << " " << "avg_cpu_QuickRand" << " " << "std_dev_cpu_QuickRand" << endl;
	outputFile << endl;
	//cout << "Size:\t" << "P-Value:\t" << "MergeComp:\t" << "MergeTime:\t" << "DetQComp:\t" << "DetQTime:\t" << "RandQComp:\t" << "RandQTime: \t" << endl;
	//outputFile << "Size:\t" << "P-Value:\t" << "MergeComp:\t" << "MergeTime:\t" << "DetQComp:\t" << "DetQTime:\t" << "RandQComp:\t" << "RandQTime: \t" << endl;
	for(int i = 0; i < pValues.size(); i++){//loop thru input sizes
		proportion = pValues[i]; 
		for (int j = 0; j < inputSizes.size(); j++) {//loop thru p values
			sample = inputSizes[j];
			numSwaps = ceil((sample * proportion)); 
			listMerge.setList(sample);
			listDetQuick.setList(sample);
			listRandQuick.setList(sample);
			for (int trial = 0; trial < 25; trial++) {
				genRandList(listMerge, listDetQuick, listRandQuick, sample, numSwaps);
				//cpu time for merge
				clock_t time1 = clock(); 
				listMerge.mergeSort(listMerge.numArray, 0, listMerge.size - 1);
				time1 = clock() - time1;  
				//cpu time for det quick sort 
				clock_t time2 = clock();
				listDetQuick.quickSort(true);
				time2 = clock() - time2; 
				//cpu time for rand quick sort
				clock_t time3 = clock();
				listRandQuick.quickSort(false);
				time3 = clock() - time3;
				trialUpdateGlobals(time1, time2, time3); 
				compMerge = 0; 
				compQuickDet = 0; 
				compQuickRand = 0; 
				cpu_Merge = 0; 
				cpu_QuickDet = 0; 
				cpu_QuickRand = 0; 
			}//end of 25 trials, avg now holds the sum of all points 
			finalUpdateGlobals(25); 
			cout << sample << " " << proportion << endl;
			cout << "\t" << avg_CompMerge << " " << std_dev_CompMerge << " " << avg_cpu_Merge << " " << std_dev_cpu_Merge << endl; 
			cout << "\t" << avg_CompQuickDet << " " << std_dev_CompQuickDet << " " << avg_cpu_QuickDet << " " << std_dev_cpu_QuickDet << endl; 
			cout << "\t" << avg_CompQuickRand << " " << std_dev_CompQuickRand << " " << avg_cpu_QuickRand << " " << std_dev_cpu_QuickRand << endl; 
			cout << endl; 
			outputFile << sample << " " << proportion << endl;
			outputFile << "\t" << avg_CompMerge << " " << std_dev_CompMerge << " " << avg_cpu_Merge << " " << std_dev_cpu_Merge << endl;
			outputFile << "\t" << avg_CompQuickDet << " " << std_dev_CompQuickDet << " " << avg_cpu_QuickDet << " " << std_dev_cpu_QuickDet << endl;
			outputFile << "\t" << avg_CompQuickRand << " " << std_dev_CompQuickRand << " " << avg_cpu_QuickRand << " " << std_dev_cpu_QuickRand << endl;
			outputFile << endl;
			//cout << endl; 
			//outputFile << sample << "\t" << proportion << "\t\t" << avg_CompMerge << "\t\t" << avg_cpu_Merge << "\t\t" << avg_CompQuickDet;
			//outputFile << "\t\t" << avg_cpu_QuickDet << "\t\t" << avg_CompQuickRand << "\t\t\t" << avg_cpu_QuickRand << endl; 
			//outputFile << endl;
			//outputFile << endl;
			resetGlobals();
		}
	}
	outputFile.close();
	//test case
	//test case 1 = {19,......2, 1, 0}
	cout << "Test Case 1: " << endl;
	listMerge.setList(20);
	listDetQuick.setList(20);
	listRandQuick.setList(20);
	for (int i = 0; i < 20; i++) {
		listMerge.numArray[i] = 19 - i;
		listDetQuick.numArray[i] = 19 - i;
		listRandQuick.numArray[i] = 19 - i;
	}
	runTestCase(listMerge, listDetQuick, listRandQuick);
	// test case 2 = {1,3,5,7,2,4,6,8}
	cout << "Test Case 2: " << endl;
	listMerge.setList(8);
	listDetQuick.setList(8);
	listRandQuick.setList(8);
	listMerge.numArray[0] = 1;
	listMerge.numArray[1] = 3;
	listMerge.numArray[2] = 5;
	listMerge.numArray[3] = 7;
	listMerge.numArray[4] = 2;
	listMerge.numArray[5] = 4;
	listMerge.numArray[6] = 6;
	listMerge.numArray[7] = 8;
	listDetQuick.numArray[0] = 1;
	listDetQuick.numArray[1] = 3;
	listDetQuick.numArray[2] = 5;
	listDetQuick.numArray[3] = 7;
	listDetQuick.numArray[4] = 2;
	listDetQuick.numArray[5] = 4;
	listDetQuick.numArray[6] = 6;
	listDetQuick.numArray[7] = 8;
	listRandQuick.numArray[0] = 1;
	listRandQuick.numArray[1] = 3;
	listRandQuick.numArray[2] = 5;
	listRandQuick.numArray[3] = 7;
	listRandQuick.numArray[4] = 2;
	listRandQuick.numArray[5] = 4;
	listRandQuick.numArray[6] = 6;
	listRandQuick.numArray[7] = 8;
	runTestCase(listMerge, listDetQuick, listRandQuick);
	//test case 3 = {24, 2, 3, 4,......22, 23, 1}
	cout << "Test Case 3: " << endl;
	int temp = 0;
	listMerge.setList(25);
	listDetQuick.setList(25);
	listRandQuick.setList(25);
	listMerge.swap(listMerge.numArray, 0, 24);
	listDetQuick.swap(listDetQuick.numArray, 0, 24);
	listRandQuick.swap(listRandQuick.numArray, 0, 24);
	runTestCase(listMerge, listDetQuick, listRandQuick);
}
void resetGlobals() {
	//clear averages
	avg_CompMerge = 0; 
	avg_CompQuickDet = 0; 
	avg_CompQuickRand = 0; 
	avg_cpu_Merge = 0; 
	avg_cpu_QuickDet = 0;
	avg_cpu_QuickRand = 0;
	//clear 
	compMerge = 0; 
	compQuickDet = 0; 
	compQuickRand = 0; 
	cpu_Merge = 0; 
	cpu_QuickDet = 0; 
	cpu_QuickRand = 0; 
	std_dev_CompMerge = 0;
	std_dev_CompQuickRand = 0;
	std_dev_CompQuickDet = 0;
	std_dev_cpu_Merge = 0;
	std_dev_cpu_QuickDet = 0;
	std_dev_cpu_QuickRand = 0;
}
void genRandList(sortingLists list1, sortingLists list2, sortingLists list3, int inputSize, int numSwaps) {
	int iRand; 
	int jRand; 
	for (int k = 0; k < numSwaps; k++) {//create randomness in lists
		iRand = rand() % inputSize;
		jRand = rand() % inputSize;
		list1.swap(list1.numArray, iRand, jRand);
		list2.swap(list2.numArray, iRand, jRand);
		list3.swap(list3.numArray, iRand, jRand);
	}
}
void trialUpdateGlobals(long double time1, long double time2, long double time3) {
	cpu_Merge = (1000.0 * (long double)(time1) / (long double)CLOCKS_PER_SEC);
	avg_cpu_Merge += cpu_Merge; //sum up cpu
	std_dev_cpu_Merge += pow(cpu_Merge, 2); //sum of squared cpu
	avg_CompMerge += compMerge; //sum up comparisons
	std_dev_CompMerge += pow(compMerge, 2);  // sum of squared comparisons
	cpu_QuickDet = (1000.0 * (long double)(time2) / (long double)CLOCKS_PER_SEC);
	avg_cpu_QuickDet += cpu_QuickDet;
	std_dev_cpu_QuickDet += pow(cpu_QuickDet, 2);
	avg_CompQuickDet += compQuickDet;
	std_dev_CompQuickDet += pow(compQuickDet, 2);
	cpu_QuickRand = (1000.0 * (long double)(time3) / (long double)CLOCKS_PER_SEC);
	avg_cpu_QuickRand += cpu_QuickRand;
	std_dev_cpu_QuickRand += pow(cpu_QuickRand, 2);
	avg_CompQuickRand += compQuickRand;
	std_dev_CompQuickRand += pow(compQuickRand, 2);
}
void finalUpdateGlobals(int numTrials) {
	std_dev_CompMerge -= (pow(avg_CompMerge, 2) / numTrials); //add the square of the sum of all points divided by the size
	std_dev_CompMerge /= ((double)numTrials - 1);
	std_dev_cpu_Merge -= (pow(avg_cpu_Merge, 2) / numTrials);
	std_dev_cpu_Merge /= ((double long)numTrials - 1);
	std_dev_CompQuickDet -= (pow(avg_CompQuickDet, 2) / numTrials);
	std_dev_CompQuickDet /= ((double)numTrials - 1);
	std_dev_cpu_QuickDet -= (pow(avg_cpu_QuickDet, 2) / numTrials);
	std_dev_cpu_QuickDet /= ((double long)numTrials - 1);
	std_dev_CompQuickRand -= (pow(avg_CompQuickRand, 2) / numTrials);
	std_dev_CompQuickRand /= ((double)numTrials - 1);
	std_dev_cpu_QuickRand -= (pow(avg_cpu_QuickRand, 2) / numTrials);
	std_dev_cpu_QuickRand /= ((double long)numTrials - 1);
	//square root std dev
	std_dev_CompMerge = sqrt(std_dev_CompMerge); 
	std_dev_cpu_Merge = sqrt(std_dev_cpu_Merge);
	std_dev_CompQuickDet = sqrt(std_dev_CompQuickDet);
	std_dev_cpu_QuickDet = sqrt(std_dev_cpu_QuickDet);
	std_dev_CompQuickRand = sqrt(std_dev_CompQuickRand);
	std_dev_cpu_QuickRand = sqrt(std_dev_cpu_QuickRand);
	//divide by num trials
	avg_CompMerge /= 25;
	avg_CompQuickDet /= 25;
	avg_CompQuickRand /= 25;
	avg_cpu_Merge /= (long double)25;
	avg_cpu_QuickDet /= (long double)25;
	avg_cpu_QuickRand /= (long double)25;
}
void runTestCase(sortingLists listMerge, sortingLists listDetQuick, sortingLists listRandQuick) {
	cout << "Merge List: " << endl; 
	cout << "\t"; 
	listMerge.printList();
	cout << endl;
	cout << "Det. QuickSort List: " << endl; 
	cout << "\t";
	listDetQuick.printList();
	cout << endl;
	cout << "Rand. QuickSort List: " << endl; 
	cout << "\t";
	listRandQuick.printList();
	cout << endl;
	listMerge.mergeSort(listMerge.numArray, 0, listMerge.size - 1);
	listDetQuick.quickSort(true);
	listRandQuick.quickSort(false);
	cout << "Merge List: " << endl; 
	cout << "\t";
	listMerge.printList();
	cout << endl;
	cout << "Det. QuickSort List: " << endl; 
	cout << "\t";
	listDetQuick.printList();
	cout << endl;
	cout << "Rand. QuickSort List: " << endl; 
	cout << "\t";
	listRandQuick.printList();
	cout << endl;
}