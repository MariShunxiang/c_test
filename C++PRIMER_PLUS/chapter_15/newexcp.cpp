// newexcp.cpp -- the bad_alloc execption
#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try {
        cout << "Try to get a big block of memory:\n";
        pb = new Big[10000000000000];
        cout << "Got past the new request:\n";
        
    }
    catch (bad_alloc & ba)
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    if (pb != 0) {
        pb[0].stuff[0] = 4;
        cout << pb[0].stuff[0] << endl;
    } else {
        cout << "pb is null pointer\n";
    }
    delete [] pb;
    return 0;    
}