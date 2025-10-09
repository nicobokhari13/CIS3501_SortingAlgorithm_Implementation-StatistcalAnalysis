# CIS3501_SortingAlgorithm_Implementation-StatistcalAnalysis
This implementation was used to understand and analyze the time complexities of sorting algorithms

A list of integers is generated with different factors of "randomness". 
This list of integers is sorted with 3 different algorithms: Merge Sort, Deterministic Quick Sort, and Random Quick Sort. 

Deterministic Quick Sort and Random Quick Sort only differ in that the "pivots" utilized in dividing the sorting problem are a fixed index in Deterministic and a random index in Random.

This implementation sorts lists of 10,20,50,100,200,500,750,1000,2000,2500,3000 number of integers.
Each list is subjected to some percentage of scrambling operations. Scrambling is measured by value 'p' which can be: 0.0 (no scrambling), 0.1, 0.2, 0.5, 1.0
For example, for list size 50 and p = 0.5, 
  the scrambling operation performs 50 * 0.5 = 25 swappings of random integers in the list of 50 integers. 
 
After scrambling, the list is sorted with the three sorting algorithms. 
The CPU time for the sorting algorith's work is recorded. 
Additioanlly, the number of comparison operations made in the algorithm are recorded. 

All data was exported and analyzed in a Statistical Analysis Software called MiniTab. 

A final report was produced with discussion of findings and results from the experiment. 
