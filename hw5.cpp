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
void merge(std::vector<std::string>&arr, int p, int q, int r) 
{ 
    int size1 = q-p+1;
    int size2 = r-q;
    std::vector<std::string> L(size1);
    std::vector<std::string> R(size2);

    for(int i = 0; i < size1; i++)
    {
        L[i] = arr[p+i];
    }
    for(int j = 0; j < size2; j++)
    {
        R[j]=arr[q+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = p; k <= r && i < size1 && j < size2; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    for(i = i; i < size1; ++i)
    {
        arr[k] = L[i];
        k++;
    }

    for(j = j; j < size2; j++)
    {
        arr[k] = R[j];
        k++;
    }
} 

//This function uses the divid and conquer methodology and divides 
//till it has just one element ..recursively
void mergeSortHelper(std::vector<std::string>& arr, int l, int r) 
{ 
        if (l < r) { 
                // Same as (l+r)/2, but avoids overflow for 
                // large l and h 
                int m = l + (r - l) / 2; 

                // Sort first and second halves 
                mergeSortHelper(arr, l, m); 
                mergeSortHelper(arr, m + 1, r); 

                merge(arr, l, m, r); //this function merges the left sorted
                //and the right sorted string
        } 
} 

void MergeSort(std::vector<std::string>&arr){
    int n=arr.size();
    mergeSortHelper(arr,0,n-1);//helper function
}