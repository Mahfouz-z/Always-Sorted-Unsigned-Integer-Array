/*
    Name: Mohamed Mafhouz Shehawy
    gnu complier with c++11 is required
    To compile run:
        make clean
        make all
    Run using:
        ./main
    
    N.B: The class is extended by many debugging statements; however,
    this could be later modified and only use the return values that
    indicate errors. That could be easiy done by using a #ifndef VERBOSE
    statements.
*/

#include <iostream>
#include "sortedUIntArr.h"
#include <string>

using namespace std;


int main()
{
    // sortedUIntArr a (7);
    // cout << a;
    // a.setAt(1, 98);
    // cout << a;
    // a.setAt(4, 23);
    // cout << a;



    //Testing Invalid Vector
    cout << "Testing Invalid Vector\n";
    try
    {
        sortedUIntArr a (-1);
    }
    catch(string msg)
    {
        cerr << msg;
    }
    cout << "_____________________________________\n\n";
    
    // //Testing Move Constructor
    cout << "Testing Move Constructor\n";
    sortedUIntArr b = sortedUIntArr(1000);
    cout << "_____________________________________\n\n";

    // //Testing Copy Constructor
    cout << "Testing Copy Constructor\n";
    try
    {
        sortedUIntArr c (b);
    }
    catch(string msg)
    {
        cerr << msg;
    }
    cout << "_____________________________________\n\n";


    // //Testing setting index out of bounds
    cout << "Testing setting an out of bounds index\n";
    try
    {
        b.setAt(10000, 1); 
    }
    catch(string msg)
    {
        cerr << msg << endl;
    }
    cout << "_____________________________________\n\n";



    //Testing getting an out of bounds index value
    cout << "Testing getting an out of bounds index value\n";
    cout << "Using Value: ";
    try
    {
        b.getAt(10000); 
    }
    catch(string msg)
    {
        cerr << msg << endl;
    }
    cout << "Using [] operator: ";
    try
    {
        b[10000]; 
    }
    catch(string msg)
    {
        cerr << msg << endl;
    }
    cout << "_____________________________________\n\n";

    // Testing move assignment 
    cout << "Testing move assignment\n";
    b = sortedUIntArr(78);
    cout << "_____________________________________\n\n";

    // Testing copy assignemnt
    cout << "Testing copy assignment\n";
    sortedUIntArr c (8);
    b = c;
    cout << "_____________________________________\n\n";

    // Testing == operator
    cout << "Testing == operator\n";
    if(b == c && !(b == sortedUIntArr(1)))
    {
        cout << "op == success" << endl;
    }
    else
    {
        cout << "op == fail" << endl;
    }
    cout << "_____________________________________\n\n";

    //Testing setting a value and getting value at it's index
    cout << "Testing setting a value at index 3 using setAt() and getting value at index 0 that shall equal to the set value as it is smaller than U_MAX_INT\n";
    cout << "Using setAt(): ";
    b.setAt(3,221);
    cout << "Using getAt(): ";
    try
    {
        cout << b.getAt(0) << endl;
    }
    catch(string err)
    {
        cout << err << endl;
    }
    cout << "Using [] operator: ";
    try
    {
        cout << b[0] << endl;
    }
    catch(string err)
    {
        cout << err << endl;
    }
    cout << "Arr: \n" << b << endl;
    cout << "_____________________________________\n\n";

    // Editing value using [] operator
    cout << "Editing value at index 1 using [] operator to 20\n";
    b[1] = 20;

    cout << "Array: \n"<< b << endl;    

    // returning a refrence to an array elm and using it to edit a class element sustaining array sorted
    cout << "returning a refrence to an array elm at ind 6 and using it to edit a class element sustaining array sorted\n";
    customInt ref = b[6];
    cout << "Edit ref value to 4\n";
    ref = 4;
    cout << "Arr: \n" << b << endl;  

    return 0;
}