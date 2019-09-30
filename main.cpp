//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Sort.h"
#include "Quick.h"
#include "Shell.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main(){
    vector <int> v{12,34,54,2,3};
    vector <int> v2{15,14,3,32,5,67,8};
    vector <char> v3{'c','d','a','e'};
    vector <float> v4{5.4,3.2,10.3,6.5,8.8,1.2};
    Sorter<QuickSort> S1;
    Sorter<MergeSort> S2;
    Sorter<ShellSort> S3;

    /*QUICKSORT
    S1(v,v.begin(),v.end()-1);
    S1.print(v);
    cout << endl;
    S1(v2,v2.begin(),v2.end()-1);
    S1.print(v2);
    cout << endl;
    S1(v3,v3.begin(),v3.end()-1);
    S1.print(v3);
    cout << endl;
    S1(v4,v4.begin(),v4.end()-1);
    S1.print(v4);*/

    /*MERGE SORT
    S2(v,v.begin(),v.end()-1);
    S2.print(v);
    cout << endl;
    S2(v2,v2.begin(),v2.end()-1);
    S2.print(v2);
    cout << endl;
    S2(v3,v3.begin(),v3.end()-1);
    S2.print(v3);
    cout << endl;
    S2(v4,v4.begin(),v4.end()-1);
    S2.print(v4);*/

    /*SHELL SORT
    S3(v,v.begin(),v.end());
    S3.print(v);
    cout << endl;
    S3(v2,v2.begin(),v2.end());
    S3.print(v2);
    cout << endl;
    S3(v3,v3.begin(),v3.end());
    S3.print(v3);
    cout << endl;
    S3(v4,v4.begin(),v4.end());
    S3.print(v4);*/

    return 0;
}