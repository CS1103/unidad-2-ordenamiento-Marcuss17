#ifndef PROYECTO2_QUICK_H
#define PROYECTO2_QUICK_H
#include <iostream>
#include <vector>


class QuickSort{
public:

    template<typename container, typename forward>
    void sort(container &cnt, forward first, forward last,int k){
        if (k==1)
         sort1(cnt,first,last);
        else sort5(cnt,first,last);

    }

    template<typename container>
    bool comp(container &cnt1, container &cnt2) {
        if (cnt1->countryOrArea < cnt2->countryOrArea)
            return true;
        else if (cnt1->countryOrArea == cnt2->countryOrArea) {
            if (cnt1->year < cnt2->year)
                return true;
            else if (cnt1->year == cnt2->year) {
                if (cnt1->flow < cnt2->flow)
                    return true;
                else if (cnt1->flow == cnt2->flow) {
                    if (cnt1->commodity < cnt2->commodity)
                        return true;
                    else if (cnt1->commodity == cnt2->commodity)
                        if (cnt1->trade_usd <= cnt2->trade_usd)
                            return true;
                }
            }
        }
        return false;
    }






    template<typename container, typename forward>
    void sort5(container &cnt, forward first, forward last) {
        auto beg = first;
        auto end = last;
        auto mid = first + (end - beg) / 2;
        //auto pivot = mid->trade_usd;
        //int vbeg;
        //int vend;
        do {
            //vbeg = beg->trade_usd;
            //vend = end->trade_usd;
            //(vbeg >= pivot && vend <= pivot){
            if (comp(mid, beg) && comp(end, mid)) {
                swap(*beg, *end);
                beg++;
                end--;
            }
        /*if(vbeg < pivot)
            beg++;
        if(vend > pivot)
            end--;
            */
        if (comp(beg, mid))
                beg++;
        if (comp(mid, end))
                end--;


    }while (beg <= end) ;
                if (first < end)
                    sort5(cnt, first, end);
                if (beg < last)
                    sort5(cnt, beg, last);

    }









    template<typename container, typename forward>
    void sort1(container &cnt, forward first, forward last) {
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
            sort1(cnt,first,end);
        if(beg < last)
            sort1(cnt,beg,last);
    }





    template<typename T>
    void swap(T& beg, T& end) {
        T temp=beg;
        beg = end;
        end = temp;
    }
};


#endif //PROYECTO2_QUICK_H
