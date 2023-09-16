#include "DynamicArray.h"

void main()
{
    DynamicArray a(5); // constructor 1 param
    a.Input();
    a.Output();
    a.Reverse();
    a.Output();
    cout << a.Search(14) << endl;
    a.Sort();
    a.Output();
    a.ReSize(3);
    a.Output();
    a.ReSize(10);
    a.Output();

    DynamicArray b(a.GetSize());
    b.Input();
    b.Output();

    DynamicArray rez = a + 10; // увеличиваем кол-во элементов на 10
    rez.Output();
    rez = (a - 2); // удаляем последние 2 элемента, если размер >2
    rez.Output();
    rez = a * 2;// значение каждого элемента массива умножаем на 2, возвращаем новый массив!
    rez.Output();
    rez = a - b; // разность массивов
    rez.Output();
    rez = a + b;  // конкатенация массивов
    rez.Output();
    ++rez;  // увеличиваем количество элементов на 1(значение 0).
    rez.Output();
    --rez;  // ум. количество элементов на 1, удаляем последний элемент
    rez.Output();

    system("pause");


}