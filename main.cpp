//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Sort.h"
#include "Quick.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main(){
    //QUICKSORT WORKS FINE
    vector <int> v{8,3,6,4,2,5,7,1};
    vector <int> v2{15,14,3,32,5,67,8};
    vector <char> v3{'c','d','a','e'};
    vector <float> v4{5.4,3.2,10.3,6.5,8.8,1.2};
    Sorter<QuickSort> S1;
    /*S1(v,v.begin(),v.end()-1);
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
    //MERGE SORT
    Sorter<MergeSort> S2;
    /*
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

    return 0;
}