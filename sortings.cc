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
void Merge(T *array, int start, int end)
{
  int mid = (end + start) / 2;
  int len = end - start + 1;
  T *sorted_array = new T[len];
  int i = start;
  int j = mid + 1;
  int idx = 0;
  for (; (i <= mid) && (j <= end); idx++) 
  {
    if (array[i] < array[j]) {
      sorted_array[idx] = array[i];
      i++;
    } else {
      sorted_array[idx] = array[j];
      j++;
    }

  }
  int t;
  if (i > mid)
    t = j;
  else 
    t = i;

  while (idx < len)
  {
    sorted_array[idx] = array[t];
    t++;
    idx++;
  }

  for (int i = start; i <= end; i++)
    array[i] = sorted_array[i - start];

  delete []sorted_array;
}

template <class T>
void MergeSort(T *array, int start, int end)
{
  int mid = (end + start) / 2;
  if (start < end) {
    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, start, end);
  }
}
