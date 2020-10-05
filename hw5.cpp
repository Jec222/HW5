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

void merge(std::vector<std::string>&v, int p, int q, int r){ 
  int size1 = q-p+1;
  int size2 = r-q;
  std::vector<std::string> left(size1);
  std::vector<std::string> right(size2);

  for(int i = 0; i < size1; i++)
    left.at(i) = v.at(p+i);
  
  for(int j = 0; j < size2; j++)
    right.at(j) = v.at(q+j+1);
  
  int i=0,j=0;
  int k;
  for(k = p; k <= r && i < size1 && j < size2; k++){
    if(left.at(i) <= right.at(j)){
      v.at(k) = left.at(i);
      i++;
    }
    else{
      v.at(k) = right.at(j);
      j++;
    }
  }
  for(i = i; i < size1; ++i){
    v.at(k) = left.at(i);
    k++;
  }

  for(j = j; j < size2; j++){
    v.at(k) = right.at(j);
    k++;
  }
} 
void mergeSortHelper(std::vector<std::string>& v, int left, int right){ 
  if (left < right){ 
    int middle = left+(right-left)/2; 
    mergeSortHelper(v,left, middle); 
    mergeSortHelper(v, ++middle,right); 
    merge(v, left,middle,right); 
  } 
} 
void MergeSort(std::vector<std::string>&v){
  mergeSortHelper(v,0,v.size()-1);
}