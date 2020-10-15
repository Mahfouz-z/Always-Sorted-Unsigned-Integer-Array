#include <iostream>
#include <iomanip>
#include <climits>
#include <string>
#include "sortedUIntArr.h"


using namespace std;
int sortedUIntArr::id = 0;


// class implementation 
sortedUIntArr::sortedUIntArr(int s):size(s),  vid(++id)
{
    if(size > 0)
    {
        // Handle memorey allocation exceptions
        try
        {
            //init the array to UINT_MAX
            data = new unsigned int[s];
            for (int i = 0; i < s; i++)
            {
                data[i] = UINT_MAX;
            }
            cout << "\tobject with ID: "<< this->vid << " Created a sortedUIntArr of size: " << s << endl; 
        }
        catch(bad_alloc& ex)
        {
            data = nullptr;
            size = -1;
            throw("Couldn't allocate the needed memorey, array was not created!");
        }
    }
    else 
    {
        string thVal = "object with ID: " + to_string(this->vid) + ": Invalid non-zero value entered, vector is not created!\n";
        data = nullptr;
        size = -1;
        throw(thVal);
    }
}

sortedUIntArr::sortedUIntArr (const sortedUIntArr& a):size(a.size), data(nullptr) //copy
{ 
    // Handle memorey allocation errors for copying!
    try
    {
        data = new unsigned int[a.size];
        cout << "\tobject with ID: "<< this->vid << " Running Copy Constructor copying " << "object with ID: "<< a.vid << " to itself!" << endl;
        for(int i=0; i<size; i++)
            data[i]=a.data[i];
    }
    catch(bad_alloc& ex)
    {
        data = nullptr;
        size = -1;
        throw(string("Couldn't allocate the needed memorey to copy object with id " + to_string(a.vid)+ " to object with id " + to_string(this->vid)));
    }
}

sortedUIntArr::sortedUIntArr (sortedUIntArr&& a):size(a.size), data(a.data) //move
{ 
    cout << "\tobject with ID: "<< this->vid << " Running Move Constructor moving " << "object with ID: " << a.vid << " to itself!" << endl;
    a.data = nullptr;
    a.size = -1;
}

sortedUIntArr::~sortedUIntArr()
{
    cout << "\tobject with ID: "<< this->vid << " running destructor!\n";
    if(data!=nullptr)
    {
        delete [] data;
        data = nullptr;
    }
    else 
        cout << "\tnothing to delete\n";
}

void sortedUIntArr::setAt(int index, unsigned int value)
{
    if(index >= 0 && index < size)
    {
        data[index] = value;
        bool upFlag = true;
        bool downFlag = true;
        int upPos = index + 1;
        int downPos = index - 1;
        int pos = index;
        while(true)
        {
            if(upFlag == false && downFlag == false)
                break;
            else
            {
                if(upFlag == true)
                    if(upPos < size)
                    {
                        if(data[pos] > data[upPos])
                        {
                            downFlag = false;
                            sortedUIntArr::swap(data[pos], data[upPos]);
                            pos++;
                            upPos++;
                        }
                        else
                            upFlag = false;    
                    }
                    else
                    {
                        upFlag = false;
                    }
                if(downFlag == true)
                    if(downPos >= 0)
                    {
                        if(data[pos] < data[downPos])
                        {
                            upFlag = false;
                            sortedUIntArr::swap(data[pos], data[downPos]);
                            pos--;
                            downPos--;
                        }
                        else
                            downFlag = false;    
                    }
                    else
                    {
                        downFlag = false;
                    }      
            }
        }
    }
    else
    {
        throw(string("Index out of range!"));
    }
}



unsigned int sortedUIntArr::getAt(int index) const
{
    if(index >= 0 && index < this->size)
    {
        return data[index];
    }
    else
    {
        throw(string("Index out of range!"));
    }
}


bool sortedUIntArr::operator == (const sortedUIntArr & right) const
{
    if(size != right.size)
        return false;
    
    for (size_t i = 0; i < size; i++)
    {
        if(data[i] != right.data[i])
            return false;
    }

    return true;
}


unsigned int sortedUIntArr::operator[](int index) const
{
    cout << "\tValue [] operator\n";
    if(index >= 0 && index < this->size)
    {
        return data[index];
    }
    else
    {
        throw(string("Index out of range!"));
    }
}

customInt sortedUIntArr::operator[](int index) 
{
    cout << "\t customInt [] operator\n";
    if(index >= 0 && index < this->size)
    {
        customInt retVal;
        retVal.index = index;
        retVal.obj = this;
        return retVal;
    }
    else
    {
        throw(string("Index out of range!"));
    }
}

const sortedUIntArr& sortedUIntArr::operator=(const sortedUIntArr & right)
{
    cout << "\tobject with ID: "<< this->vid << " Running Copy Assignment copying " << "object with ID: "<< right.vid << " to itself!" << endl;
    if(this != &right)
    {
        if(size != right.size)
        {
            delete [] data;
            size = right.size;
            try
            {
                data = new unsigned int [size];
            }
            catch(bad_alloc& ex)
            {
                size = -1;
                data = nullptr;
                throw(string("cannot do the assignment, memorey is not enough!"));
            }
        }
        for (size_t i = 0; i < size; i++)
        {
            data[i] = right.data[i];
        }
        
    }
    return *this; //why don't we just return this, not a pointer to it?
}


const sortedUIntArr& sortedUIntArr::operator=(sortedUIntArr&& right)
{
    cout << "\tobject with ID: "<< this->vid << " Running Move Assignment moving " << "object with ID: "<< right.vid << " to itself!" << endl;
    if(this != &right)
    {
        delete [] data;
        size = right.size;
        data = right.data;
        right.data = nullptr;
        right.size = -1;
    }
    return *this; //why don't we just return this, not a pointer to it?
}




ostream& operator << (ostream& ostream, const sortedUIntArr & a)
{
    for (size_t i = 0; i < a.size; i++)
    {
        if(i%4 == 0)
            ostream << endl;
        ostream << setw(13) << a.data[i];
    }
    if(a.size%4 != 0)
        ostream << endl;
    return ostream;
}


