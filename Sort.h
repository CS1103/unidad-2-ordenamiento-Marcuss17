#ifndef SORT_METHODS_SORT_H
#define SORT_METHODS_SORT_H
#include "Merge.h"
#include "Quick.h"

template<typename SortMethod>
class Sorter : private SortMethod{
public:
    template<typename container, typename ... Types>
    void operator()(container &cnt, Types ... args){
        this-> sort(cnt, args...);
    }
    template<typename container>
    void print(container cnt){
        auto it = cnt.begin();
        while(it != cnt.end()){
            std::cout << *it << "  ";
            it ++;
        }
    }
};


#endif //SORT_METHODS_SORT_H
