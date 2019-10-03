#ifndef SORTMETHODS_HEAP_H
#define SORTMETHODS_HEAP_H
#include <iostream>
#include <vector>
#include <string>
using std::swap;
class HeapSort {
public:

    template<typename container, typename forward>
    void sort(container &cnt, forward first, forward last,int k){
        auto n=last-first + 1;
        if(k==1){

            for (auto i = n / 2 - 1; i >= 0; i--)
                heapify1(cnt, n, i);


            for (auto i = n - 1; i >= 0; i--) {
                swap((*cnt.begin()), *(cnt.begin() + i));

                heapify1(cnt, i, 0);
            }

        }


        else  {
            for (auto i = n / 2 - 1; i >= 0; i--)
                heapify5(cnt, n, i);


            for (auto i = n - 1; i >= 0; i--) {
                swap((*cnt.begin()), *(cnt.begin() + i));

                heapify5(cnt, i, 0);
            }
        }
    }
    template<typename container, typename forward>
    void heapify5(container &cnt, forward n, forward i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n){
            if ((cnt.begin()+l)->countryOrArea > (cnt.begin()+largest)->countryOrArea)
                largest = l;
            else if ((cnt.begin()+l)->countryOrArea == (cnt.begin()+largest)->countryOrArea) {
                if ((cnt.begin() + l)->year > (cnt.begin() + largest)->year)
                    largest = l;
                else if ((cnt.begin() + l)->year == (cnt.begin() + largest)->year) {
                    if ((cnt.begin() + l)->flow > (cnt.begin() + largest)->flow)
                        largest = l;
                    else if ((cnt.begin() + l)->flow == (cnt.begin() + largest)->flow) {
                        if ((cnt.begin() + l)->commodity > (cnt.begin() + largest)->commodity)
                            largest = l;
                        else if ((cnt.begin() + l)->commodity == (cnt.begin() + largest)->commodity)
                            if ((cnt.begin() + l)->trade_usd > (cnt.begin() + largest)->trade_usd)
                                largest = l;
                    }
                }
            }
        }
        if (r < n){
            if ((cnt.begin()+r)->countryOrArea > (cnt.begin()+largest)->countryOrArea)
                largest = r;
            else if ((cnt.begin()+r)->countryOrArea == (cnt.begin()+largest)->countryOrArea) {
                if ((cnt.begin() + r)->year > (cnt.begin() + largest)->year)
                    largest = r;
                else if ((cnt.begin() + r)->year == (cnt.begin() + largest)->year) {
                    if ((cnt.begin() + r)->flow > (cnt.begin() + largest)->flow)
                        largest = r;
                    else if ((cnt.begin() + r)->flow == (cnt.begin() + largest)->flow) {
                        if ((cnt.begin() + r)->commodity > (cnt.begin() + largest)->commodity)
                            largest = r;
                        else if ((cnt.begin() + r)->commodity == (cnt.begin() + largest)->commodity)
                            if ((cnt.begin() + r)->trade_usd > (cnt.begin() + largest)->trade_usd)
                                largest = r;
                    }
                }
            }
            }


        if (largest != i)
        {
            swap(*(cnt.begin()+i), *(cnt.begin()+largest));

            heapify5(cnt, n, largest);
        }
    };

    template<typename container, typename forward>
    void heapify1(container &cnt, forward n, forward i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && (cnt.begin()+l)->trade_usd > (cnt.begin()+largest)->trade_usd)
                largest = l;

        if (r < n && (cnt.begin()+r)->trade_usd > (cnt.begin()+largest)->trade_usd)
            largest = r;



        if (largest != i)
        {
            swap(*(cnt.begin()+i), *(cnt.begin()+largest));

            heapify1(cnt, n, largest);
        }

    }


};
#endif //SORTMETHODS_HEAP_H
