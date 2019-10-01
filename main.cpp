//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <vector>
#include "Sort.h"
#include "Quick.h"
#include "Shell.h"
#include <fstream>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::ifstream;

struct Commodity{
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

int main(){

    ifstream fin("/home/eduardo/Desktop/Utec/Poo2/Proyecto2/outputP2/commodity_trade_statistics_data.csv");
    if(!fin){
        cout <<"File not open\n";
        return 1;
    }
    vector<Commodity> commodities;
    string line;
    const char delim = ',';


    while(getline(fin, line)){
        std::istringstream ss(line);
        Commodity commodity;
        getline(ss,commodity.countryOrArea,delim);
        ss >> commodity.year;ss.ignore(10,delim);
        ss >> commodity.comm_code;ss.ignore(10,'"');
        getline(ss,commodity.commodity,'"');
        getline(ss,commodity.flow,delim);
        getline(ss,commodity.flow,delim);
        ss >> commodity.trade_usd;ss.ignore(10,delim);
        ss >> commodity.weight_kg;ss.ignore(10,delim);
        getline(ss,commodity.quantity_name,delim);
        ss >> commodity.quantity; ss.ignore(10,delim);
        getline(ss,commodity.categori,delim);

        if (ss)
            commodities.push_back(commodity);
    }
    //Used this to check
    for(int i = 0; i != 5; i ++){
        cout << commodities[i].countryOrArea <<';'<< commodities[i].year <<';'<< commodities[i].comm_code <<';' << commodities[i].commodity;
        cout << ';' << commodities[i].flow << ';' << commodities[i].trade_usd <<';' << commodities[i].weight_kg << ';' << commodities[i].quantity_name;
        cout << ';' << commodities[i].quantity << ';' << commodities[i].categori;
        cout <<endl;
    }
    Sorter<QuickSort> S1;
    S1(commodities,commodities.begin(),commodities.end()-1);/*
    Sorter<MergeSort> S2;
    S2(commodities,commodities.begin(),commodities.end()-1);
    Sorter<ShellSort> S3;
    S3(commodities,commodities.begin(),commodities.end());*/

    /*QUICKSORT FUNCIONA PARA VECTORES SIMPLES. SE DEBE VOLVER A LA FORMA, DE LAS FUNCIONES, DE LOS PRIMEROS PUSH.
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

    /*MERGESORT FUNCIONA PARA VECTORES SIMPLES. SE DEBE VOLVER A LA FORMA, DE LAS FUNCIONES, DE LOS PRIMEROS PUSH.
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

    /*SHELL SORT FUNCIONA PARA VECTORES SIMPLES. SE DEBE VOLVER A LA FORMA, DE LAS FUNCIONES, DE LOS PRIMEROS PUSH.
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

    /* Para poder usar esta clase se debe cambiar todas las flechas a ->edad.
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
    S1.print(personas);*/


    std::ofstream myfile;
    myfile.open ("/home/eduardo/Desktop/Utec/Poo2/Proyecto2/output/output.csv");
    auto it = commodities.begin();
    myfile <<"country_or_area,year,comm_code,commodity,flow,trade_usd,weight_kg,quantity_name,quantity,category\n";
    //Changed the ',' for a dot. So that it can be easier to read.
    for(auto &i: commodities){
        for(auto &j : i.commodity){
            if(j == ',')
                j = '.';
        }
    }
    while(it != commodities.end()){
        myfile << (it->countryOrArea) << ',' << (it->year) << ',' << (it->comm_code) <<',' << (it->commodity) << ',' << (it->flow) << ',' << (it->trade_usd);
        myfile << ',' << (it->weight_kg) << ',' << (it ->quantity_name) << ',' << (it ->quantity) << ',' << (it ->categori) << '\n';
        it++;
    }

    return 0;
}