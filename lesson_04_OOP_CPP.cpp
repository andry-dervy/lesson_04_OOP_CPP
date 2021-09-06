//============================================================================
// Name        : lesson_04_OOP_CPP.cpp
// Author      : andry antonenko
// IDE         : Qt Creator 4.14.2 based on Qt 5.15.2
// Description : lesson 04 of the object-oriented programming on C++ course
//============================================================================
#include <QCoreApplication>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <chrono>
#include <list>
#include <set>
#include <string>
#include <sstream>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
#include "arrayint.h"
#include "game_blackjack.h"
//----------------------------------------------------------------------------
int getRandomNum(int min, int max)
{
  const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  static std::mt19937_64 generator(seed);
  std::uniform_int_distribution<int> dis(min, max);
  return dis(generator);
}
//----------------------------------------------------------------------------
/*
1. Добавить в контейнерный класс,
который был написан в этом уроке, методы:
    • для удаления последнего элемента массива
(аналог функции pop_back() в векторах)
    • для удаления первого элемента массива
(аналог pop_front() в векторах)
    • для сортировки массива
    • для вывода на экран элементов.
//*/

void task_1()
{
  cout << "Task 1\n" << endl;

  const int MIN = 0;
  const int MAX = 100;

  int AMOUNT;
  int SIZE;


  //Test 1
  cout << "Test 1\n" << endl;

  AMOUNT = 10;
  SIZE = 20;
  {
    cout << "Created array capacity is SIZE equaled " <<
            SIZE << "." << endl;
    ArrayInt array(SIZE);


    cout << "Added " << AMOUNT <<
            " elements to the array." << endl;
    for(int i = 0; i < AMOUNT; ++i)
    {
      array.push_back(getRandomNum(MIN,MAX)%100);
    }
    array.print();

    cout << "Erased the array." << endl;
    array.erase();
    array.print();
  }

  //Test 2
  cout << "\nTest 2\n" << endl;

  AMOUNT = 20;
  SIZE = 10;
  {
    cout << "Created array capacity is " <<
            SIZE << "." << endl;
    ArrayInt array(SIZE);


    cout << "Added " << AMOUNT <<
            " elements to the array." << endl;
    for(int i = 0; i < AMOUNT; ++i)
    {
      array.push_back(getRandomNum(MIN,MAX)%100);
    }
    array.print();

    cout << "Erased the array." << endl;
    array.erase();
    array.print();
  }

  //Test 3
  cout << "\nTest 3\n" << endl;

  AMOUNT = 10;
  SIZE = 20;
  {
    cout << "Created array capacity is " <<
            SIZE << "." << endl;
    ArrayInt array(SIZE);


    cout << "Added " << AMOUNT <<
            " elements to the array." << endl;
    for(int i = 0; i < AMOUNT; ++i)
    {
      array.push_back(getRandomNum(MIN,MAX)%100);
    }
    array.print();

    int Value = 50;
    int Position = 5;

    cout << "Insert " << Value <<
            " to the array before the " << Position <<
            " position." << endl;
    array.insertBefore(Value,Position);
    array.print();
  }

  //Test 4
  cout << "\nTest 4\n" << endl;

  AMOUNT = 10;
  SIZE = 20;
  {
    cout << "Created array capacity is " <<
            SIZE << "." << endl;
    ArrayInt array(SIZE);

    cout << "Added " << AMOUNT <<
            " elements to the array." << endl;
    for(int i = 0; i < AMOUNT; ++i)
    {
      array.push_back(getRandomNum(MIN,MAX)%100);
    }
    array.print();


    cout << "Array was sorted." << endl;
    array.sort();
    array.print();
  }

  cout << endl;
}

//----------------------------------------------------------------------------
/*
2. Дан вектор чисел, требуется выяснить,
сколько среди них различных.
Постараться использовать максимально быстрый алгоритм.
//*/

size_t getOriginalElements(const vector<int> &Numbers)
{
  set<int> setNum;
  for(const int &n : Numbers)
    if(setNum.find(n) == setNum.end())
      setNum.insert(n);
  return setNum.size();
}

void printVector(const vector<int> &Numbers)
{
  for(const int &n : Numbers)
    cout << n << " ";
  cout << endl;
}

void task_2()
{
  cout << "Task 2\n" << endl;

  const int MIN = 0;
  const int MAX = 100;

  int AMOUNT;
//  int SIZE;

  //Test 1
  cout << "Test 1\n" << endl;

  AMOUNT = 100;
  {
    vector<int> vecInt(AMOUNT);

    cout << "Added " << AMOUNT <<
            " elements to the vector." << endl;
    for(int i = 0; i < AMOUNT; ++i)
    {
      vecInt[i] = getRandomNum(MIN,MAX)%100;
    }
    printVector(vecInt);

    cout << "Get an amount of original elements: " <<
         getOriginalElements(vecInt) << endl;

    vecInt.clear();
  }

  cout << endl;
}

//----------------------------------------------------------------------------
/*
3. Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт
(удобно использовать вектор,
т.к. это по сути динамический массив,
а тип его элементов должен быть -
указатель на объекты класса Card).
Также в классе Hand должно быть 3 метода:
    • метод Add, который добавляет в коллекцию карт новую карту,
соответственно он принимает в качестве параметра указатель на новую карту
    • метод Clear, который очищает руку от карт
    • метод GetValue, который возвращает сумму очков карт руки
(здесь предусмотреть возможность того, что туз может быть равен 11).
//*/

void task_3()
{
  cout << "Task 3\n" << endl;

  Hand hand;

  hand.Add(new Card(HEARTS,THREE,true));
  hand.Add(new Card(DIAMONDS,SIX,true));
  hand.Add(new Card(DIAMONDS,LADY,true));

  cout << "Total value: " << hand.GetValue() << endl;

/*
//*/
  cout << endl;
}

//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  //----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
  //----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
  //----------------------------------------------------------------------------
  // Task 3
  //*
  task_3();
  //*/
  //----------------------------------------------------------------------------
  return a.exec();
}
