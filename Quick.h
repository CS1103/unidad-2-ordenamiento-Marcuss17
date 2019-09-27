#ifndef PROYECTO2_QUICK_H
#define PROYECTO2_QUICK_H
#include <iostream>
#include <vector>
using std::vector;
using std::cout; using std::cin; using std::string;


class QuickSort{
public:
    template<typename C, typename forward, typename T>
    void sort(C &cnt, forward &primero, T &ultimo) {
        auto beg = primero; //Controla los elementos de la sublista izquierda
        auto end = ultimo; //Controla los elementos de la sublista derecha
        auto mid = primero + (end-beg)/2;
        auto pivot = *mid;
        do{
            if(*beg >= pivot && *end <= pivot){
                swap(*beg,*end);
                beg++;
                end--;
            }
            if(*beg < pivot)
                beg++;
            if(*end > pivot)
                end--;
        }while(beg <= end);
        if(primero < end)
            sort(cnt,primero,end);
        if(beg < ultimo)
            sort(cnt,beg,ultimo);
    }

    template<typename T>
    void swap(T& beg, T& end) {
        T temporal;
        temporal = beg;
        beg = end;
        end = temporal;
    }
};


#endif //PROYECTO2_QUICK_H
