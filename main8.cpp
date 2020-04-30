#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

template <typename type>
class Matrix
{
private:
  int x, y;
  type** Arr;
  int size_x, size_y;
public:
  Matrix() {

  }
  Matrix(int size_x, int size_y)
  {
    x = size_x;
    y = size_y; 
    Arr = new type * [size_x];
    for (int i = 0; i < size_x; i++) 
    {
      Arr[i] = new type[size_y];
      for (int j = 0; j < size_y; j++) 
      {
        Arr[i][j] = 0;
      }
    }
  }
  void create(int size_x, int size_y)
  {
    Arr = new type * [size_x];
    for (int i = 0; i < size_x; i++)
    {
      Arr[i] = new type[size_y];
      for (int j = 0; j < size_y; j++)
      {
        Arr[i][j] = 0;
      }
    }
  }
  ~Matrix()
  {
    for (int i = 0; i < size_x; i++)
    {
      delete Arr[i];
    }
    delete[] Arr;
  }
  friend ostream& operator<<(ostream& output, Matrix<type>& matr) 
  { 
    for (int i = 0; i < matr.size_x; i++) 
    { 
      for (int j = 0; j < matr.size_y; j++) 
      { 
        output << matr.Arr[i][j] << "\t"; 
      }
      output << endl << endl;
    }
    output << endl;
    return output; 
  }
  friend istream& operator>>(istream& is, Matrix<type>& matr) 
  {
    matr.~Matrix();
    cout << "Введіть кількість рядків: "; 
    is >> matr.size_x;
    cout << "Введіть кількість стовпців: ";
    is >> matr.size_y;
    matr.Arr = new type * [matr.size_x];
    cout << "Для рандомного заповнення введіть - 1\nДля ручного заповнення введіть - 2\n";
    matr.create(matr.size_x, matr.size_y);
    int l = 1; 
    cin >> l; 
    switch (l)
    {
    case 1:
      for (int i = 0; i < matr.size_x; i++)
      {
        for (int j = 0; j < matr.size_y; j++)
        {
          matr.Arr[i][j] = rand() % 99;
        }
      }
      break;
    case 2:
      for (int i = 0; i < matr.size_x; i++)
      {
        for (int j = 0; j < matr.size_y; j++)
        {
          cout << "a[" << i << "]" << "[" << j << "]" << "=";
          is >> matr.Arr[i][j];
        }
      }
      break;
      return is;
    }
  }
  int search()
  {
    int n = 0;
    for (int i = 0; i < size_x - 2; i += 2)
    {
      for (int j = 0; j < size_y - 2; j += 2)
      {
        if (Arr[i][j] > Arr[i][j + 2])
        {
          n++;
        }
      }
    }
    return n;
  }
};

template <typename type>
class Array
{
  friend istream& operator>> (istream& input, Array& obj)
  {
    cout << "Для рандомного заповнення введіть - 1\nДля ручного заповнення введіть - 2\n";
    int l = 1;
    cin >> l;
    switch (l)
    {
    case 1:
      for (int ix = 0; ix < obj.size; ix++)
      {
        obj.ptr[ix] = rand() % 99;
      }
      break;
    case 2:
      for (int ix = 0; ix < obj.size; ix++)
      {
        cout << "a[" << ix << "]" << "=";
        input >> obj.ptr[ix];
      }
      break;  
    }
    return input;
  }
  friend ostream& operator<< (ostream& output, const Array& obj)
  {
    for (int ix = 0; ix < obj.size; ix++)
    {
      output << setw(5) << obj.ptr[ix];
    }

    output << endl;

    return output;
  }
private:
  int* ptr;
  int size;
public:
  Array()
  {
    size = 10;
    ptr = new int[size];
    for (int ix = 0; ix < size; ix++)
    {
      ptr[ix] = 0;
    }  
  }
  Array(int arraySize)
  {
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];
    for (int ix = 0; ix < size; ix++)
    {
      ptr[ix] = 0;
    }
  }
  ~Array()
  {
    delete[] ptr;
  }

  int getSize() const
  {
    return size;
  }
  int& operator[] (int subscript)
  {
    if (subscript < 0 || subscript >= size)
    {
      std::cerr << "\n Ошибка индекса: " << subscript << std::endl;
      exit(1);
    }
    return ptr[subscript];
  }
  int search()
  {
    int n = 1, max;
    for (int i = 0; i < size - 2; i++, i++)
    {
      if (ptr[i] > ptr[i+2])
      {
        n++;
        max = n;
      }  
      else
      {
        max = n;
        n = 1;
      }
    }
    return max;
  }
};


int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  
  Array<int> Arr(10);

  cin >> Arr;
  cout << Arr;

cout << endl << Arr.search() << endl;

system("pause");
  return 0;
}
