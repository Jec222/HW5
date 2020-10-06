/*
BubbleSort: 
will take in a vector 
will create a temp value so that value can change spot
will loop and will compare values at each element of the vetor
if value1 is grater than value2 swap spots 

Insertion Sort:

will check base case if checked the entire list return 
will call itself again pasing in a vector minus the last element
will keep track of the last element in vetor
will keep the positon before the last element in vector  
will check the position that it does not go under the size of vector
will also check that the element infront is bigger that the one infront if true 
change spots 

MergeSort:

will take in a vector 

will chck if right side is grater than left side 
will find the midlde point of each vector and devide it acordently 
will call intself recursebly for ach part will pass the vector the the left side parameters and right side respectably 
after its sorted both sides merge the left vector with the right vector 
*/


#include <iostream>
#include <vector>

void BubbleSort(std::vector<std::string> &vec){

  std::string temp; 
  for (int k = 0; k < vec.size(); k++){ 
    for (int i=k + 1; i < vec.size(); i++) { 
      if (vec.at(i).compare(vec.at(k)) < 0){ 
        temp = vec.at(k); 
        vec.at(k) = vec.at(i);
        vec.at(i) = temp;
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

void merge(std::vector<std::string>&v, int left_index, int middle_index, int right_index){ 

  int size_one = middle_index-left_index+1;
  int size_two = right_index-middle_index;
  std::vector<std::string> left(size_one);
  std::vector<std::string> right(size_two);

  for(int i = 0; i < size_one; i++)
    left[i] = v[left_index+i];

  for(int j = 0; j < size_two; j++)
    right.at(j)=v.at(middle_index+j+1);
  
  int i=0,j=0;
  int k;
  for(k = left_index; k <= right_index && i < size_one && j < size_two; k++){
    if(left.at(i) <= right.at(j)){
      v.at(k) = left.at(i);
      i++;
    }
    else{
      v.at(k) = right.at(j);
      j++;
    }
  }
  for(i = i; i < size_one; ++i){
    v.at(k) = left.at(i);
    k++;
  }
  for(j = j; j < size_two; j++){
    v.at(k) = right.at(j);
    k++;
  }
} 
void mergeSortHelper(std::vector<std::string>& v, int left, int right){ 
  if (left < right){ 
    int middle = left + (right - left) / 2;  
    mergeSortHelper(v, left, middle); 
    mergeSortHelper(v, middle + 1,right); 
    merge(v, left, middle, right);
  } 
} 
void MergeSort(std::vector<std::string>&v){
  mergeSortHelper(v,0,v.size()-1);
}