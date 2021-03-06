// newplace.cpp -- using placement new 
// 9.3 布局new操作符，要使用布局 new 特性，首先要包含头文件 new, 它提供了这个版本的 new 操作符的原型，然后将 new 操作符用于提供了所需地址的参数。

#include<iostream>
#include<new>
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
    using namespace std;
    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];
    pd2 = new (buffer) double[N]; // use deap
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Buffer address:\n" << " heap: " << pd1
        << " static; " << (void *) buffer << endl;
    cout << "Buffer contents:\n";
    for (i = 0; i < N; i ++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a sencond time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 20.0 * i;
    cout << "Buffer contents:\n";
    for (i = 0; i < N; i ++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a thired time:\n";
    delete [] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Buffer contents:\n";
    for (i = 0; i < N; i ++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    delete [] pd1;
    delete [] pd3;

    return 0;
}