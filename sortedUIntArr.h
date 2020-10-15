#ifndef SORT_UI_ARR
#define SORT_UI_ARR
 
#include <iostream>

class sortedUIntArr;
#include "customInt.h"


class sortedUIntArr 
{
    unsigned int * data;
    int size;
    int vid;
    static int id;
    friend std::ostream& operator << (std::ostream &, const sortedUIntArr& );
    friend class customInt;
    void swap(unsigned int & a, unsigned int & b)
    {
      unsigned int c = a;
      a = b;
      b = c;
    }

  public:
    sortedUIntArr(int s = 32);
    sortedUIntArr (const sortedUIntArr&);
    sortedUIntArr (sortedUIntArr&&);
    ~sortedUIntArr();
    void setAt(int, unsigned int);
    unsigned int getAt(int) const;
    unsigned int operator[](int) const;
    customInt operator[](int); 
    bool operator == (const sortedUIntArr &) const;
    const sortedUIntArr& operator=(const sortedUIntArr &);
    const sortedUIntArr& operator=(sortedUIntArr &&);
};
 

#endif