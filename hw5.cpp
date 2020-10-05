#include <iostream>
#include <vector>

void BubbleSort(std::vector<std::string> &vec){

  std::string temp; 
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

void InsertionSortHelper(std::vector<int> & v, int size) {  
    
  if (size <= 1) 
    return; 

  InsertionSortHelper(v, size-1); 
 
  int last = v.at(size-1); 
  int pos = size-2; 

  while (pos >= 0 && v[pos] > last) { 
    v.at(pos+1) = v.at(pos); 
    pos--; 
  } 
  v.at(pos+1) = last; 
} 
void InsertionSort(std::vector <int>& v){
  InsertionSortHelper(v,v.size());
} 
//void MergeSort(std::vector<std::string> &vec){}

//this merges two sorted subarrays to one sorted array
//merge(v, left, middle, right);
void merge(std::vector<std::string>&v, int left_index, int middle_index, int right_index){ 
  
  int size_one = middle_index-left_index+1;
  int size_two = right_index-middle_index;
  std::vector<std::string> left(size_one);
  std::vector<std::string> right(size_two);

  for(int i = 0; i < size_one; i++)
    left[i] = v[left_index+i];

  for(int j = 0; j < size_two; j++)
    right[j]=v[middle_index+j+1];
  
    int i=0,j=0;
    int k;
    for(k = left_index; k <= right_index && i < size_one && j < size_two; k++){
      if(left[i] <= right[j]){
        v[k] = left[i];
        i++;
      }
      else{
        v[k] = right[j];
        j++;
      }
    }
    for(i = i; i < size_one; ++i)
    {
        v[k] = left[i];
        k++;
    }

    for(j = j; j < size_two; j++){
      v[k] = right[j];
      k++;
    }
} 

//This function uses the divid and conquer methodology and divides 
//till it has just one element ..recursively
void mergeSortHelper(std::vector<std::string>& v, int left, int right){ 
  if (left < right){ 
    // Same as (l+r)/2, but avoids overflow for 
    // large l and h 
    int middle = left + (right - left) / 2; 
    // Sort first and second halves 
    mergeSortHelper(v, left, middle); 
    mergeSortHelper(v, middle + 1,right); 
    merge(v, left, middle, right); //this function merges the left sorted
    //and the right sorted string
  } 
} 
void MergeSort(std::vector<std::string>&v){
  mergeSortHelper(v,0,v.size()-1);
}