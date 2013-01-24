template <class T>
class SortedArray {
 public:
  explicit SortedArray(int num);
  ~SortedArray() { delete array; };
  bool Push(const T &data);
  void Show();
 
  void InsertionSort();
  
 private:
  T *array;
  int length;
  int top;
};

template <class T>
SortedArray<T>::SortedArray(int num):length(num),top(-1)
{
  array = new T[num];
}

template <class T>
bool SortedArray<T>::Push(const T &data)
{
  if (top >= length - 1)
    return false;

  top++;
  array[top] = data;
}

template <class T>
void SortedArray<T>::Show()
{
  std::cout << "Array Content: " <<std::endl;
  for (int i = 0; i <= top; i++)
    std::cout << array[i] << std::endl;
}

template <class T>
void SortedArray<T>::InsertionSort()
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
