#include <stdexcept>
#include <typeinfo>
#include <iostream>
#include <sstream>

class OutOfRange : public std::exception{};

/// @brief Питоновский список
/// @tparam 
template <typename T>
class Vector
{
    T *data;     // Массив для хранения данных списка
    int pointer; // Указатель на элемент массива, куда идет запись (на одну ячейку "левее" последнего)
    int size;    // Размер массива
    void expand();

    /// @brief Класс итератора для списка
    class iterator
    {
        int index;   // Индекс элемента, на котором "находится" итератор
        Vector *vec; // Список, который надо итерировать
    public:
        iterator(Vector *vec, int a) : vec(vec) { index = a; };
        iterator *operator++()
        {
            index++;
            return this;
        }
        T operator*() { return vec->data[index]; }
        int operator==(iterator other) { return this->index == other.index; }
        int operator!=(iterator other) { return this->index != other.index; }
    };

public:
    //~Vector();
    Vector();
    void append(T a);
    T pop();
    /// @brief Длина списка
    /// @return Длина списка (int)
    int len() {return pointer;};
    T &operator[](int);
    void Vector::sort(bool key(T, T) = nullptr);
    void Vector::clear();
    //friend std::ostream& operator<<(std::ostream&, Vector<T>);

    iterator begin() { return iterator(this, 0); };
    iterator end() { return iterator(this, pointer); };
};


/// @brief Конструктор списка
/// @tparam
template <typename T>
Vector<T>::Vector()
{
    data = new T[1];
    size = 1;
    pointer = 0;
}

/*
/// @brief Деструктор списка
/// @tparam
template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}
*/

/// @brief Расширение списка
/// @tparam
template <typename T>
void Vector<T>::expand()
{
    T *a = data;
    if (size >= 2048)
    {
        T *b = new T[size + 2048];
        for (int i = 0; i < size; i++)
            b[i] = a[i];
        size = size + 2048;
        data = b;
        delete[] a;
    }
    else
    {
        T *b = new T[size * 2];
        for (int i = 0; i < size; i++)
            b[i] = a[i];
        size = size * 2;
        data = b;
        delete[] a;
    }
}

/// @brief Добавление элемента в список
/// @tparam
/// @param a Элемент на добавление
template <typename T>
void Vector<T>::append(T a)
{
    if (pointer == size)
        expand();
    data[pointer] = a;
    pointer++;
}

/// @brief Изъятие последнего элемента в списке
/// @tparam
/// @return Элемент списка
template <typename T>
T Vector<T>::pop()
{
    if (pointer == 0)
        throw std::out_of_range("popError");
    pointer--;
    T b = data[pointer];
    return b;
}

/// @brief Вывод элемента по индексу
/// @tparam
/// @param a Индекс
/// @return Элемент списка
template <typename T>
T &Vector<T>::operator[](int a)
{
    if (a >= pointer || a < -pointer)
        throw std::out_of_range("[]Error");
    if (a >= 0)
        return data[a];
    else
        return data[pointer + a];
}

/// @brief Очистка списка
/// @tparam
template <typename T>
void Vector<T>::clear()
{
    delete[] data;
    data = new T[1];
    size = 1;
    pointer = 0;
}

/// @brief Сортировка списка
/// @tparam
/// @param key Критерий сортировки
template <typename T>
void Vector<T>::sort(bool key(T, T))
{
    if (key == nullptr)
        key = [](T x, T y)
        { return (x > y) ? true : false; };
    for (int i = 0; i < pointer - 1; i++)
    {
        for (int j = 0; j <= pointer - 2 - i; j++)
        {
            if (key(data[j], data[j + 1]))
            {
                T c = data[j];
                data[j] = data[j + 1];
                data[j + 1] = c;
            }
        }
    }
}

/* ???
/// @brief Выводит список
/// @tparam
/// @return Список в питоновском формате (поток)
template <typename T>
std::ostream& operator<<(std::ostream& stream, Vector<T> Vector)
{
    stream << "["
    for (int i = 0; i < pointer; i++)
    {
        stream << Vector[i] << ", ";
    }
    return stream << "]";
}
*/