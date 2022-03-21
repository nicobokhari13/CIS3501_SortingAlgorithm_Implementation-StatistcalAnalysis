#include "globals.h"
//Comp Merge vector
//Comp Quick Det Vector
//Comp Quick Rand Vector
//CPU Merge vector 
//CPU Quick Det Vector 
//CPU Quick Rand Vector 
int compMerge = 0; 
int compQuickDet = 0;
int compQuickRand = 0;
long double cpu_Merge = 0; 
long double cpu_QuickDet = 0; 
long double cpu_QuickRand = 0;
double avg_CompMerge = 0; 
double avg_CompQuickRand = 0; 
double avg_CompQuickDet = 0; 
//dont need
double num_CompMerge = 0; 
double num_CompQuickRand = 0; 
double num_CompQuickDet = 0; 
//keep 
double std_dev_CompMerge = 0; 
double std_dev_CompQuickRand = 0;
double std_dev_CompQuickDet = 0; 
long double std_dev_cpu_Merge = 0; 
long double std_dev_cpu_QuickDet = 0; 
long double std_dev_cpu_QuickRand = 0; 
long double avg_cpu_Merge = 0; 
long double avg_cpu_QuickDet = 0; 
long double avg_cpu_QuickRand = 0;

//std = sqrt(Sxxz/n - 1)
//Sxx = sum(all points^2) - (sum(all points)^2)/n
//avg already sums up everything

