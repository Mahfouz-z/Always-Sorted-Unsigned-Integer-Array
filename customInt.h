#ifndef CUSTOM_INT
#define CUSTOM_INT

class customInt;
#include "sortedUIntArr.h"

class customInt
{
      friend std::ostream& operator << (std::ostream &, const customInt& );
      friend class sortedUIntArr;
      sortedUIntArr * obj;
      int index;
    public:
      customInt();
      const customInt& operator=(const unsigned int &);
      bool operator == (const customInt &) const;
};

#endif