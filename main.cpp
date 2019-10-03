//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <vector>
#include "Sort.h"
#include "Quick.h"
#include "Shell.h"
#include "Heap.h"
#include <fstream>
#include <sstream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::ifstream;
using std::swap;

struct Commodity{
    string countryOrArea;
    int year;
    long long int comm_code;
    string commodity;
    string flow;
    long long int trade_usd;
    long long int weight_kg;
    string quantity_name;
    long long int quantity;
    string categori;
};



template<typename container>
void Save(std::ofstream& myfile,container &commodities){
    auto it = commodities.begin();
    myfile <<"country_or_area,year,comm_code,commodity,flow,trade_usd,weight_kg,quantity_name,quantity,category\n";
    for(auto &i: commodities){
        for(auto &j : i.commodity){
            if(j == ',')
                j = '.';
        }
    }
    while(it != commodities.end()){
        myfile << (it->countryOrArea) << ',' << (it->year) << ',' << (it->comm_code) <<',' << (it->commodity) << ',' << (it->flow) << ',' << (it->trade_usd);
        myfile << ',' << (it->weight_kg) << ',' << (it ->quantity_name) << ',' << (it->quantity) << ',' << (it->categori) << '\n';
        it++;
    }
}




int main(){

    std::fstream fin("C://unidad-2-ordenamiento-Marcuss17-master//archivossort.csv");
    if(!fin){
        cout <<"File not open\n";
        return 0;
    }

    vector<string> row;
    vector<Commodity> commodities;
    vector<Commodity> commodities2;
    vector<Commodity> commodities3;
    vector<Commodity> commodities4;
    vector<Commodity> commodities5;
    vector<Commodity> commodities6;
    vector<Commodity> commodities7;
    vector<Commodity> commodities8;

    string line;
    const char delim = ',';




   while(getline(fin, line)) {
        string h;
        std::istringstream ss(line);
        Commodity commodity;
        getline(ss, commodity.countryOrArea, delim);
        ss >> commodity.year;ss.ignore(10, delim);
        ss >> commodity.comm_code;
        ss.ignore(10, '"');
        getline(ss, commodity.commodity, '"');
        getline(ss, commodity.flow, delim);
        getline(ss, commodity.flow, delim);
        ss >> commodity.trade_usd;
        ss.ignore(10, delim);
        ss >> commodity.weight_kg;
        ss.ignore(10, delim);
        getline(ss, commodity.quantity_name, delim);
        ss >> commodity.quantity; ss.ignore(10, delim);
        getline(ss, commodity.categori, delim);

        if (ss) {
            commodities.push_back(commodity);
            commodities2.push_back(commodity);
            commodities3.push_back(commodity);
            commodities4.push_back(commodity);
            commodities5.push_back(commodity);
            commodities6.push_back(commodity);
            commodities7.push_back(commodity);
            commodities8.push_back(commodity);

        }

    }





    //Used this to check
    for(int i =20; i !=30 ; i ++){
        cout << commodities[i].countryOrArea <<';'<< commodities[i].year <<';'<< commodities[i].comm_code <<';' << commodities[i].commodity;
        cout << ';' << commodities[i].flow << ';' << commodities[i].trade_usd <<';' << commodities[i].weight_kg << ';' << commodities[i].quantity_name;
        cout << ';' << commodities[i].quantity << ';' << commodities[i].categori;
        cout <<endl;
    }
    Sorter<QuickSort> S1;
    Sorter<MergeSort> S2;
    Sorter<ShellSort> S3;
    Sorter<HeapSort> S4;
    S1(commodities,commodities.begin(),commodities.end()-1,1);
    S1(commodities7,commodities7.begin(),commodities7.end()-1,5);
    S2(commodities2,commodities2.begin(),commodities2.end()-1,1);
    S2(commodities6,commodities6.begin(),commodities6.end()-1,5);
    S3(commodities3,commodities3.begin(),commodities3.end()-1,1);
    S3(commodities8,commodities8.begin(),commodities8.end()-1,5);
    S4(commodities4,commodities4.begin(),commodities4.end()-1,1);
    S4(commodities5,commodities5.begin(),commodities5.end()-1,5);




    std::ofstream myfile;
    myfile.open ("C:\\Users\\Usuario\\Desktop\\OutputQuick.csv");
    Save(myfile,commodities);



    std::ofstream myfile2;
    myfile2.open ("C:\\Users\\Usuario\\Desktop\\OutputMERGE.csv");
    Save(myfile2,commodities2);






    std::ofstream myfile3;
    myfile3.open ("C:\\Users\\Usuario\\Desktop\\OutputShell.csv");
    Save(myfile3,commodities3);


    std::ofstream myfile4;
    myfile4.open ("C:\\Users\\Usuario\\Desktop\\OutputHeap.csv");
    Save(myfile4,commodities4);






    std::ofstream myfile5;
    myfile5.open ("C:\\Users\\Usuario\\Desktop\\OutputHeap5Filtros.csv");
    Save(myfile5,commodities5);


    std::ofstream myfile6;
    myfile6.open ("C:\\Users\\Usuario\\Desktop\\OutputMerge5Filtros.csv");
    Save(myfile6,commodities6);

    std::ofstream myfile7;
    myfile7.open ("C:\\Users\\Usuario\\Desktop\\OutputQuick5Filtros.csv");
    Save(myfile7,commodities7);


    std::ofstream myfile8;
    myfile8.open ("C:\\Users\\Usuario\\Desktop\\OutputShell5Filtros.csv");
    Save(myfile8,commodities8);




    commodities8.clear();
    commodities7.clear();
    commodities6.clear();
    commodities5.clear();
    commodities4.clear();
    commodities3.clear();
    commodities2.clear();
    commodities.clear();





    return 0;
}