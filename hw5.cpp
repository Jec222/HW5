#include <iostream>
#include <vector>

void BubbleSort(std::vector<std::string> &vec){

  /*Hint: given two strings str1 and str2, we can use str1.compare(str2). compare() returns 0 if the strings are equal, < 0 if str1 comes first alphabetically, and > 0 if str2 comes first alphabetically*/
//void sortStrings(char arr[][MAX], int n

  //char temp = vec.at(vec.size()); 
  
    // Sorting strings using bubble sort 
    for (int k = 0; k < vec.size(); k++){ 
      for (int i=k+1; i < vec.size(); i++) { 
        if (vec.at(k).compare(vec.at(i))<0){ 
          std::string temp = vec.at(k); 
          vec.at(k) = vec.at(i);
          vec.at(i) = temp;
        } 
      } 
    } 

}
void InsertionSort(std::vector<int>& v){

}
void MergeSort(std::vector<std::string> &vec){

}