//----------------------------------------------------------------------------
#ifndef ARRAYINT_H
#define ARRAYINT_H
//----------------------------------------------------------------------------
#include <QCoreApplication>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <chrono>
#include <list>
#include <string>
#include <sstream>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
class ArrayInt
{
private:
  int m_size;
  int m_counter;
  int *m_data;

public:
  ArrayInt():m_size(0), m_counter(0), m_data(nullptr) {}

  ArrayInt(int length);

  ~ArrayInt();

  void erase();
  int getLength() const { return m_counter; }

  int& operator[](int index);

  void resize(int newLength);

  void insertBefore(int value, int index);

  void push_back(int value) { insertBefore(value, m_counter); }

  int pop_back();

  int pop_front();

  void sort();

  void print();
};

#endif // ARRAYINT_H
