#include <iostream>

void qSort(int *array, int len) {
  if (len <= 0)
    return;
  int value = array[0];
  int start = 0;
  int end = len - 1;
  
  while(start < end) {
    for(; start < end; end--) {
      if (array[end] < value){
        array[start++] = array[end];
        break;
      }
    }
    for(; start < end; start++) {
      if (array[start] > value) {
        array[end--] = array[start];
        break;
      }
    }
  }
  array[start] = value;
  qSort(array, start);
  qSort(&array[start+1], len-start-1);
}
