template <class T>
class MaxHeap {
 public:
  MaxHeap(T *array, int len);        //Create the heap structure based on an existing
                                     //array, sharing the same memory.
  int Parent(int idx) { return (idx - 1) >> 1; } 
  int Left(int idx) { return ((idx << 1) + 1); }
  int Right(int idx) { return ((idx + 1) << 1); }
  void MaxHeapify(int head); //Assuming the left subtree and right subtree are max heaps
  void BuildMaxHeap();
  void HeapSort();
  void ShowHeap();

  int length;        //Number of elements
  int heap_size;     //Size of the heap, may smaller than length

 private:
  T *heap_array;
};

template <class T>
MaxHeap<T>::MaxHeap(T *array, int len):heap_array(array),length(len),heap_size(len)
{
}

template <class T>
void MaxHeap<T>::MaxHeapify(int head)
{
  int left = Left(head);
  int right = Right(head);
  T tmp;
  int largest = head;
  if ((left < heap_size)&&(heap_array[left] > heap_array[head]))
    largest = left;
  if ((right < heap_size)&&(heap_array[largest] < heap_array[right]))
    largest = right;

  if (largest != head) {
    tmp = heap_array[largest];
    heap_array[largest] = heap_array[head];
    heap_array[head] = tmp;
    MaxHeapify(largest);
  }
 }

template <class T>
void MaxHeap<T>::BuildMaxHeap()
{
  for (int i = Parent(heap_size - 1); i >= 0; i--)
  {
    MaxHeapify(i);
  }
}

template <class T>
void MaxHeap<T>::HeapSort()
{
  std::cout << "Begin Heap Sorting:" << std::endl;
  //std::cout << "Original Heap: " << std::endl;
  //ShowHeap();
  BuildMaxHeap();
  //ShowHeap();

  T tmp;
  for (int i = heap_size - 1; i > 0; i--)
  {
    tmp = heap_array[0];
    heap_array[0] = heap_array[i];
    heap_array[i] = tmp;
    heap_size--;
    MaxHeapify(0);
  }
}

template <class T>
void MaxHeap<T>::ShowHeap()
{
  int lev = 0;
  int count = 2;
  std::cout << "Heap: " << std::endl;
  for (int i = 0; i < length; i++)
  {
    std::cout << heap_array[i] << " ";
    if (i == (count - 2)) {
      std::cout << std::endl;
      count *= 2;
    }
    
  }
  std::cout << std::endl;
  
  std::cout << std::endl;
  
}

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
