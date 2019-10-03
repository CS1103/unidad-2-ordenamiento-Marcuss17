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
    void sort(container &cnt, forward first, forward last, int k) {
        if (k == 1)
            sort1(cnt, first, last);

        else
            sort5(cnt, first, last);
    }


    template<typename container, typename forward>
    void sort1(container &cnt, forward first, forward last) {

        if (first != last) {
            auto mid = first + (last - first) / 2;
            sort1(cnt, first, mid);
            sort1(cnt, mid + 1, last);
            merge1(cnt, first, mid, last);
        }
    }

    template<typename container, typename forward>
    void sort5(container &cnt, forward first, forward last) {

        if (first != last) {
            auto mid = first + (last - first) / 2;
            sort5(cnt, first, mid);
            sort5(cnt, mid + 1, last);
            merge5(cnt, first, mid, last);
        }
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
    void merge1(container &cnt, forward first, forward mid, forward last) {
        int sizeLeft = (mid - first) + 1;
        int sizeRight = (last - mid);
        container left(sizeLeft);
        container right(sizeRight);
        auto beg = first;
        auto startOfSecondHalf = mid + 1;
        auto lbeg = left.begin();
        auto rbeg = right.begin();
        for (auto &i : left) {
            i = *beg;
            beg++;
        }
        for (auto &i : right) {
            i = *startOfSecondHalf;
            startOfSecondHalf++;
        }
        beg = first;
        while (lbeg != left.end() && rbeg != right.end()) {
            if (lbeg->trade_usd <= rbeg->trade_usd) {
                *beg = *lbeg;
                lbeg++;
            } else {
                *beg = *rbeg;
                rbeg++;
            }
            beg++;
        }
        while (lbeg != left.end()) {
            *beg = *lbeg;
            lbeg++;
            beg++;
        }
        while (rbeg != right.end()) {
            *beg = *rbeg;
            rbeg++;
            beg++;
        }
    }

    template<typename container, typename forward>
    void merge5(container &cnt, forward first, forward mid, forward last) {
        int sizeLeft = (mid - first) + 1;
        int sizeRight = (last - mid);
        container left(sizeLeft);
        container right(sizeRight);
        auto beg = first;
        auto startOfSecondHalf = mid + 1;
        auto lbeg = left.begin();
        auto rbeg = right.begin();
        for (auto &i : left) {
            i = *beg;
            beg++;
        }
        for (auto &i : right) {
            i = *startOfSecondHalf;
            startOfSecondHalf++;
        }
        beg = first;
        while (lbeg != left.end() && rbeg != right.end()) {
            if (comp(lbeg, rbeg)) {
                *beg = *lbeg;
                lbeg++;
            } else {
                *beg = *rbeg;
                rbeg++;
            }
            beg++;
        }
        while (lbeg != left.end()) {
            *beg = *lbeg;
            lbeg++;
            beg++;
        }
        while (rbeg != right.end()) {
            *beg = *rbeg;
            rbeg++;
            beg++;
        }
    }

};


#endif //PROYECTO2_MERGE_H
