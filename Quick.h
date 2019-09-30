#ifndef PROYECTO2_QUICK_H
#define PROYECTO2_QUICK_H
#include <iostream>
#include <vector>


class QuickSort{
public:
    template<typename container, typename forward>
    void sort(container &cnt, forward first, forward last) {
        auto beg = first;
        auto end = last;
        auto mid = first + (end-beg)/2;
        auto pivot = mid->trade_usd;
        int vbeg;
        int vend;
        do{
            vbeg = beg->trade_usd;
            vend = end->trade_usd;
            if(vbeg >= pivot && vend <= pivot){
                swap(*beg,*end);
                beg++;
                end--;
            }
            if(vbeg < pivot)
                beg++;
            if(vend > pivot)
                end--;
        }while(beg <= end);
        if(first < end)
            sort(cnt,first,end);
        if(beg < last)
            sort(cnt,beg,last);
    }


    template<typename T>
    void swap(T& beg, T& end) {
        T temp=beg;
        beg = end;
        end = temp;
    }
};


#endif //PROYECTO2_QUICK_H
