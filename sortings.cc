template <class T>
void InsertionSort(T *array, int length)
{
  for (int i = 1; i < length; i++)
  {
    T cur_data = array[i];
    int j = i - 1;
    while ((j >= 0) && (array[j] > cur_data))
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = cur_data;
      
  }
}

template <class T>
void MergeSort(T *array, 
