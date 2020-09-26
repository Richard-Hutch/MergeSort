#include <iostream>
using namespace std;
//right, left, middle are all index values not size values
void merge(int arr[], int left,int middle, int right){
  int lSize = middle-left+1;
  int rSize = right - middle;
  int L[lSize];
  int R[rSize];
  //copy arr data into temp arrays
  for (int i = 0; i < lSize; i++){
      L[i] = arr[left + i];
  }
  for (int i = 0; i < rSize; i++){
    R[i] = arr[middle + 1 + i];
  }


  int leftInit = 0;
  int rightInit = 0;
  int mergedInit = left;
  //copy the temp arrays into arr[]
  while (leftInit < lSize && rightInit < rSize){
    if (L[leftInit] <= R[rightInit]){
      arr[mergedInit] = L[leftInit];
      leftInit++;
    }
    else{
      arr[mergedInit] = R[rightInit];
      rightInit++;
    }
    mergedInit++;
  }

  
  //copies remaining elements of L[] if any
  while (leftInit < lSize){
      arr[mergedInit] = L[leftInit];
      leftInit++;
      mergedInit++;
  }
  //copies remaining elements of R[] if any
  while (rightInit < rSize){
      arr[mergedInit] = R[rightInit];
      rightInit++;
      mergedInit++;
  }
}

void mergeSort(int arr[], int left, int right){
  if (left < right){
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {2, 12412, 1, 100, 2343, 144, 41, 15, 6};
  int size = sizeof(arr)/ sizeof(arr[0]);
  mergeSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++){
    cout << arr[i] << " " << endl;
  }

}
/*


1,2,3,4
left = 0
right = 3
middle = 1

lSize = 1-0+1 = 2
rSize = 3 - 1 = 2
L[i] = 0 + 0 = 0, 0
R[i] = 


*/