//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <vector>
#include "Sort.h"
#include "Quick.h"
#include "Shell.h"
#include "Heap.h"
#include <iomanip>
#include <fstream>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::ifstream;

struct Objeto{
    string countryOrArea;
    int year;
    int comm_code;
    string commodity;
    string flow;
    int trade_usd;
    int weight_kg;
    string quantity_name;
    int quantity;
    string categori;
};

struct Persona{
    int edad;
    string nombre;
    Persona(int edad, string nombre){
        this -> edad = edad;
        this -> nombre = nombre;
    }
};

int main(){/*
    ifstream fin("/home/eduardo/Desktop/commodity_trade_statistics_data.csv");
    if(!fin){
        cout <<"File not open\n";
        return 1;
    }
    vector<Objeto> objetos;
    string line;
    const char delim = ',';


    while(getline(fin, line)){
        std::istringstream ss(line);
        Objeto objeto;
        getline(ss,objeto.countryOrArea,delim);
        ss >> objeto.year;ss.ignore(10,delim);
        ss >> objeto.comm_code;ss.ignore(10,'"');
        getline(ss,objeto.commodity,'"');
        getline(ss,objeto.flow,delim);
        getline(ss,objeto.flow,delim);
        ss >> objeto.trade_usd;ss.ignore(10,delim);
        ss >> objeto.weight_kg;ss.ignore(10,delim);
        getline(ss,objeto.quantity_name,delim);
        ss >> objeto.quantity; ss.ignore(10,delim);
        getline(ss,objeto.categori,delim);

        if (ss)
            objetos.push_back(objeto);
    }
    for(int i = 0; i != 5; i ++){
        cout << objetos[i].countryOrArea <<';'<< objetos[i].year <<';'<< objetos[i].comm_code <<';' << objetos[i].commodity;
        cout << ';' << objetos[i].flow << ';' << objetos[i].trade_usd <<';' << objetos[i].weight_kg << ';' << objetos[i].quantity_name;
        cout << ';' << objetos[i].quantity << ';' << objetos[i].categori;
        cout <<endl;
    }
    cout << endl;*/
    Sorter<QuickSort> S1;
    //S1(objetos,objetos.begin(),objetos.end()-1);
    vector <Persona> personas;
    Persona P1(25,"Marco");
    Persona P2(23,"Jose");
    Persona P3(19,"Carlos");
    Persona P4(32,"Rodrigo");
    Persona P5(18,"Bryan");
    personas.push_back(P1);
    personas.push_back(P2);
    personas.push_back(P3);
    personas.push_back(P4);
    personas.push_back(P5);
    cout << "Vector de personas desordenado: " << endl;
    S1.print(personas);
    cout << endl;
    cout <<"Vector de personas ordenado: " << endl;
    S1(personas,personas.begin(),personas.end()-1);
    S1.print(personas);

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