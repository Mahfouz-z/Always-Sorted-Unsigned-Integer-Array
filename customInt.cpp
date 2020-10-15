
#include <iostream>
#include <string>
#include "customInt.h"


using namespace std;

// Helper Class Implementation
customInt::customInt():obj(nullptr), index(-1){}

const customInt&  customInt::operator=(const unsigned int & value)
{
    if(index != -1)
    {
        try
        {
            obj->setAt(index, value);
        }
        catch(string err)
        {
            throw(err);
        }
    }
    else
    {
        throw(string("This int refers to a non-existing sortedUIntArr class"));
    }
}

bool customInt::operator == (const customInt & right) const
{
    try
    {
        return (this->obj->getAt(this->index) == right.obj->getAt(right.index));
    }
    catch(string err)
    {
        throw(err);
    }
}

ostream& operator << (ostream& ostream, const customInt & a)
{
    try
    {
        ostream << a.obj->getAt(a.index);
    }
    catch(string err)
    {
        throw(err);
    }
    return ostream;
}

