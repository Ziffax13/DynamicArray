#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}

DynamicArray DynamicArray::GetObj()const
{
    DynamicArray obj(3);
    obj.Input();

    return obj;
}
DynamicArray DynamicArray::operator+(int size)
{
    DynamicArray a(*this);
    a.ReSize(a.size + size);
    return a;
}
DynamicArray DynamicArray::operator-(int size)
{
    DynamicArray a(*this);
    if (a.size < size)
    {
        return a;
    }
    a.ReSize(a.size - size);
    return a;
}
DynamicArray DynamicArray::operator*(int x)
{
    DynamicArray a(*this);
    for (int i = 0; i < size; i++)
    {
        a.ptr[i] = (a.ptr[i] * x);
    }
    return a;
}
DynamicArray DynamicArray::operator+(DynamicArray b)
{
    DynamicArray a(*this);
    a.ReSize(a.size + b.size);
    for (int i = a.size-b.size; i < a.size; i++)
    {
        a.ptr[i] = b.ptr[i - b.size];
    }
    return a;
}
DynamicArray& DynamicArray::operator--()
{
    ReSize(size - 1);
    return *this;
}
DynamicArray& DynamicArray::operator++()
{
    ReSize(size + 1);
    return *this;
}
DynamicArray DynamicArray::operator-(DynamicArray b)
{
    DynamicArray a(*this);
    for (int i = 0; i < b.size; i++)
    {
        a.ptr[i] -= b.ptr[i];
    }
    return a;
}
DynamicArray& DynamicArray::operator=(DynamicArray b)
{
    delete[] ptr;
    size = b.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = b.ptr[i];
    }
    return *this;
}
DynamicArray::DynamicArray(int S)
{
    cout << "Construct by 1 param\n";
    size = S;
    ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
DynamicArray::~DynamicArray()
{
    if (ptr != 0)
    {
        delete[] ptr;
    }
}
void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}
void DynamicArray::Output()const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "-------";
    }  
    cout << endl;
}
int* DynamicArray::GetPointer()const
{
    return ptr;
}
int DynamicArray::GetSize()const
{
    return size;
}
void DynamicArray::ReSize(int size)
{
    if (size < 0)
    {
        size = 0;
    }
    DynamicArray a(*this);
    if (this->GetSize() < size)
    {
        delete[] ptr;
        ptr = new int[size];
        this->size = size;
        for (int i = 0; i < a.GetSize(); i++)
        {
            ptr[i] = a.ptr[i];
        }
        for (int i = a.GetSize(); i < size; i++)
        {
            ptr[i] = 0;
        }
        return;
    }
    delete[] ptr;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
    this->size = size;
}

void DynamicArray::Sort()
{
    for (int step = 0; step < size; ++step) {

        for (int i = 0; i < size - step - 1; ++i) {

            if (ptr[i] > ptr[i + 1]) {

                int temp = ptr[i];
                ptr[i] = ptr[i + 1];
                ptr[i + 1] = temp;
            }
        }
    }
}
int DynamicArray::Search(int a)
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == a)
        {
            return i;
        }
    }
    return -1;
}

void DynamicArray::Reverse()
{
    DynamicArray a = *this;
    
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[size -1 - i];
    }
}