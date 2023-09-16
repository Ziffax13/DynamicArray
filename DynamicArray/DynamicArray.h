#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
    int* ptr; // указатель на динам. массив
    int size;  // размер массива 
public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(const DynamicArray&); // copy constructor
    ~DynamicArray();
    void Input();// rand
    void Output()const;// вывод на консоль
    int* GetPointer()const;
    int GetSize()const;
    DynamicArray GetObj()const;

    DynamicArray operator+(int)const;
    DynamicArray operator-(int)const;
    DynamicArray operator*(int)const;
    DynamicArray operator+(DynamicArray)const;
    DynamicArray operator-(DynamicArray)const;
    DynamicArray& operator--();
    DynamicArray& operator++();
    DynamicArray& operator=(DynamicArray);

    void ReSize(int size);// изменение размера массива
    void Sort();// сортировка(любой алгоритм сортировки)
    int Search(int a)const; // поиск элемента в массиве, возвращает индекс наиденного эл., либо -1.
    void Reverse(); // перезаписывает последовательность элементов в обратном порядке, напрмер 12345 -> 54321
};
