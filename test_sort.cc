#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortings.cc"
using namespace std;

void Show(int * array, int len)
{
  cout << "Array Content: " << endl;
  for (int i = 0; i < len; i++)
    cout << array[i] << endl;
}

int main(int argc, char *argv[])
{
  int array_len = 10;
  if (argc > 1)
    array_len = atoi(argv[1]);
  if (array_len < 0) {
    cout << "Invalid array length!" << endl;
    return -1;
  }
  srand(time(0));
  cout << "Array Length = " << array_len << endl;

  int *test_array = new int[array_len];
  for (int i = 0; i < array_len; i++)
    test_array[i] = rand() % 20;

  Show(test_array, array_len);
 /* cout << endl;
  InsertionSort(test_array, array_len);
  cout << "After Insertion Sorting: " << endl;
  Show(test_array, array_len);*/

 /* cout << endl;
  MergeSort(test_array, 0, array_len - 1);
  cout << "After Merge Sorting: " << endl;
  Show(test_array, array_len);*/

  MaxHeap<int> test_heap(test_array, array_len); 
  cout << endl;
  cout << "Heap length = " << test_heap.length << endl;
  cout << "Heap Size = " << test_heap.heap_size << endl;
  test_heap.HeapSort();
  Show(test_array,array_len);

  delete []test_array;
  return 0;
}
