#include "arrayint.h"

ArrayInt::ArrayInt(int length)
  :m_size(length), m_counter(0)
{
  assert(length >= 0);

  if (length > 0)
  {
    m_data = new int[length];
  }
  else
    m_data = nullptr;
}

ArrayInt::~ArrayInt()
{
  delete[] m_data;
}

void ArrayInt::erase()
{
  delete[] m_data;

  // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
  m_data = nullptr;
  m_size = 0;
  m_counter = 0;
}

int& ArrayInt::operator[](int index)
{
  assert(index >= 0 && index < m_counter);
  return m_data[index];
}

void ArrayInt::resize(int newSize)
{
  // Если массив уже нужной длины — return
  if (newSize == m_size)
    return;

  // Если нужно сделать массив пустым — делаем это и затем return
  if (newSize <= 0)
  {
    erase();
    return;
  }

  // Теперь знаем, что newLength >0
  // Выделяем новый массив
  int *data = new int[newSize];

  // Затем нужно разобраться с количеством копируемых элементов в новый массив
  // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
  if (m_counter > 0)
  {
    int elementsToCopy = (newSize > m_counter) ? m_counter : newSize;

    // Поочередно копируем элементы
    for (int index=0; index < elementsToCopy ; ++index)
      data[index] = m_data[index];
  }

  // Удаляем старый массив, так как он нам уже не нужен
  delete[] m_data;

  // И используем вместо старого массива новый! Обратите внимание, m_data указывает
  // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
  // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
  m_data = data;
  //m_length = newLength;
  m_size = newSize;
}

void ArrayInt::insertBefore(int value, int index)
{
  // Проверка корректности передаваемого индекса
  assert(index >= 0 && index <= m_counter);

  // Если в массиве есть свободная ячейка
  if(m_size > m_counter)
  {
    for(int i = m_counter; i > index; --i)
    {
      m_data[i] = m_data[i-1];
    }

    m_data[index] = value;
    m_counter++;
    return;
  }

  // Создаем новый массив на один элемент больше старого массива
  int *data = new int[m_counter+1];

  // Копируем все элементы до index-а
  for (int before=0; before < index; ++before)
    data[before] = m_data[before];

  // Вставляем новый элемент в новый массив
  data[index] = value;

  // Копируем все значения после вставляемого элемента
  for (int after=index; after < m_counter; ++after)
    data[after+1] = m_data[after];

  // Удаляем старый массив и используем вместо него новый
  delete[] m_data;
  m_data = data;
  ++m_counter;
}

int ArrayInt::pop_back()
{
  // Проверка наличия элементов в массиве
  assert(m_counter > 0);

  return m_data[m_counter--];
}

int ArrayInt::pop_front()
{
  // Проверка наличия элементов в массиве
  assert(m_counter > 0);

  int data = m_data[0];

  for(int i = 1; i < m_counter; ++i)
    m_data[i-1] = m_data[i];

  return data;
}

static void swapInt(int * pA, int * pB)
{
  int t = *pA; *pA = *pB; *pB = t;
}

static void sortInserts(int *pArr, const int aFirst, const int aLast)
{
  // Проверка входных параметров
  assert(pArr != nullptr);
  assert(aFirst >= 0 && aFirst <= aLast);
  assert(aLast >= 0 && aFirst <= aLast);

  if(aFirst >= aLast) return;
  int indLast = aFirst;
  while(indLast < aLast)
  {
    indLast++;
    for(int i = aFirst; i < indLast; i++)
      if(pArr[i] > pArr[indLast])
        swapInt(&pArr[i],&pArr[indLast]);
  }
}

static void sortQuickImprovement(int *pArr, const int aFirst, const int aLast)
{
  // Проверка входных параметров
  assert(pArr != nullptr);
  assert(aFirst >= 0 && aFirst <= aLast);
  assert(aLast >= 0 && aFirst <= aLast);

  if(aFirst >= aLast) return;
  if( (aLast - aFirst) <= 10)
    sortInserts(pArr,aFirst,aLast);
  else
  {
    int m[3] = {pArr[aFirst],
                pArr[(aFirst + aLast)/2],
                pArr[aLast]};
    sortInserts(m,0,2);
    int ref = m[1];

    int indFirst = aFirst;
    int indLast = aLast;

    do {
      while(pArr[indFirst] < ref) indFirst++;
      while(pArr[indLast] > ref) indLast--;
      if(indFirst <= indLast) {
        swapInt(&pArr[indFirst],&pArr[indLast]);
        indFirst++;
        indLast--;
      }
    }
    while(indFirst <= indLast);
    if(indFirst < aLast) sortQuickImprovement(pArr,indFirst,aLast);
    if(aFirst < indLast) sortQuickImprovement(pArr,aFirst,indLast);
  }
}

void ArrayInt::sort()
{
  // Проверка наличия элементов в массиве
  assert(m_counter > 0);
  assert(m_data != nullptr);

  sortQuickImprovement(m_data,0,m_counter-1);
}

void ArrayInt::print()
{
  if(m_counter == 0) cout << "Array is empty!";

  for(int i = 0; i < m_counter; ++i)
  {
    cout << m_data[i] << " ";
  }
  cout << endl;
}
