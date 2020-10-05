#include <iostream>
#include <vector>

void BubbleSort(std::vector<std::string> &vec){

  /*Hint: given two strings str1 and str2, we can use str1.compare(str2). compare() returns 0 if the strings are equal, < 0 if str1 comes first alphabetically, and > 0 if str2 comes first alphabetically*/
//void sortStrings(char arr[][MAX], int n

  std::string temp; 

    // Sorting strings using bubble sort 
    for (int k = 0; k < vec.size(); k++){ 
      for (int i=k + 1; i < vec.size(); i++) { 
        if (vec[i].compare(vec[k]) < 0){ 
           temp = vec[k]; 
          vec[k] = vec[i];
          vec[i] = temp;
        } 
      } 
    } 

}
/*void InsertionSort(std::vector<int>& v){
  
  if (v.size() <= 1) 
    return;

  v.pop_back();
  InsertionSort(v); 


    // Insert last element at its correct position 
    // in sorted array. 
    int last = v[v.size()-1]; 
    int j = v.size()-2; 
  
    /* Move elements of arr[0..i-1], that are 
      greater than key, to one position ahead 
      of their current position 
    while (j >= 0 && v[j] > last) 
    { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = last; 
} */
void InsertionSortHelper(std::vector<int> & v, int size) {  
    
  if (size <= 1) 
    return; 

  InsertionSortHelper(v, size-1); 
  
    // Insert last element at its correct position 
    // in sorted array. 
    int last = v[size-1]; 
    int j = size-2; 
  
    //Move elements of arr[0..i-1], that are 
      //greater than key, to one position ahead 
      //of their current position 
    while (j >= 0 && v[j] > last) { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = last; 
} 
void InsertionSort(std::vector <int>& v){
    int n=v.size();
    InsertionSortHelper(v,n);
}
void MergeSort(std::vector<std::string> &vec){

}