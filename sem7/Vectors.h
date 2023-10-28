#include <stdexcept>


class OutOfRange: public std::exception {};
template <typename T>
class Vector
{
T* data;
int pointer;
int size;
void expand();

class iterator
{
    int index;
    Vector * vec;
public:
    iterator(Vector * vec, int a):vec(vec) {index = a;};
    iterator *operator++() {index++; return this;}
    T operator*() {return vec->data[index];}
    int operator==(iterator other) {return this->index == other.index;}
    int operator!=(iterator other) {return this->index != other.index;}
};
public:
~Vector();
Vector();
void append(T a);
T pop();
T operator[](int);
void Vector::sort(bool key(T, T) = nullptr);

iterator begin() {return iterator(this, 0);};
iterator end() {return iterator(this, pointer);};
};

template <typename T>
Vector<T>::Vector()
{
data = new T[1];
size = 1;
pointer = 0;
}

template <typename T>
Vector<T>::~Vector()
{
delete[] data;
}

template <typename T>
void Vector<T>::expand()
{
T* a = data;
T* b = new T[size*2];
for (int i = 0; i < size; i++) b[i] = a[i];
size = size*2;
data = b;
delete[] a;
delete[] b;
}

template <typename T>
void Vector<T>::append(T a)
{
if (pointer==size) expand();
data[pointer] = a;
pointer++;
}

template <typename T>
T Vector<T>::pop()
{
if (pointer == 0)
throw std::out_of_range("popError");
pointer--;
T b = data[pointer];
return b;
}

template <typename T>
T Vector<T>::operator[](int a)
{
if (a >= pointer || a < -pointer)
throw std::out_of_range("[]Error");
if (a >= 0)
return data[a];
else
return data[pointer+a];
}

template <typename T>
void Vector<T>::sort(bool key(T, T))
{
if (key == nullptr) key = [](T x, T y){return (x > y)?true:false;};
for (int i = 0; i < pointer-1; i++)
{
    for (int j = 0 ;j <= pointer - 2 - i; j++)
    {
        if (key(data[j], data[j+1]))
        {T c = data[j]; data[j] = data[j+1]; data[j+1] = c;}
    }
}
}

