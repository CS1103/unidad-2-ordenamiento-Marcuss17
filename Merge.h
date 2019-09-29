#ifndef PROYECTO2_MERGE_H
#define PROYECTO2_MERGE_H
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class MergeSort {
public:
    template<typename container, typename forward>
    void sort(container &cnt, forward first, forward last) {
        if(first != last){
            auto mid = first + (last-first) / 2;
            sort(cnt, first, mid);
            sort(cnt,mid+1,last);
            merge(cnt,first,mid,last);
        }
    }
    template<typename container, typename forward>
    void merge(container &cnt, forward first, forward mid, forward last){
        int sizeLeft = (mid-first)+1;
        int sizeRight = (last-mid);
        container left(sizeLeft);
        container right(sizeRight);
        auto beg = first;
        auto startOfSecondHalf = mid+1;
        auto lbeg = left.begin();
        auto rbeg = right.begin();
        for(auto &i : left){
            i = *beg;
            beg++;
        }
        for(auto &i : right){
            i = *startOfSecondHalf;
            startOfSecondHalf++;
        }
        beg = first;
        while(lbeg != left.end() && rbeg != right.end()){
            if(*lbeg <= *rbeg){
                *beg = *lbeg;
                lbeg++;
            }
            else{
                *beg = *rbeg;
                rbeg++;
            }
            beg++;
        }
        while(lbeg != left.end()){
            *beg = *lbeg;
            lbeg++;
            beg++;
        }
        while(rbeg != right.end()){
            *beg = *rbeg;
            rbeg++;
            beg++;
        }
    }
};


#endif //PROYECTO2_MERGE_H
