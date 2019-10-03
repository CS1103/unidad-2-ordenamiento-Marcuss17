#ifndef SORTMETHODS_SHELL_H
#define SORTMETHODS_SHELL_H

class ShellSort{
public:





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
    void sort(container& cnt, forward first, forward last,int k){
        if(k==1) sort1(cnt,first,last);
        else sort5(cnt,first,last);

    }







    template<typename container, typename forward>
    void sort5(container& cnt, forward first, forward last){
        int n = 2;
        auto jump = first + (last-first)/n;
        while(jump > first){
            bool allOrdered = true;
            while(allOrdered){
                int count = 0; auto j = first; auto it2 = jump;
                while(it2 != last){
                      if(comp(it2,j)){
                        swap(*j, *it2);
                        it2++;
                        j++;
                        count++;
                        allOrdered = true;
                    }
                    else{
                        it2++;
                        j++;
                        allOrdered = false;
                        if(count >= 1)
                            allOrdered = true;
                    }
                }
            }
            jump = first + (jump-first)/n;
        }
    }




    template<typename container, typename forward>
    void sort1(container& cnt, forward first, forward last){
        int n = 2;
        auto jump = first + (last-first)/n;
        while(jump > first){
            bool allOrdered = true;
            while(allOrdered){
                int count = 0; auto j = first; auto it2 = jump;
                while(it2 != last){
                    if(j->trade_usd > it2->trade_usd) {
                        swap(*j, *it2);
                        it2++;
                        j++;
                        count++;
                        allOrdered = true;
                    }
                    else{
                        it2++;
                        j++;
                        allOrdered = false;
                        if(count >= 1)
                            allOrdered = true;
                    }
                }
            }
            jump = first + (jump-first)/n;
        }
    }

    template<typename T>
    void swap(T& A, T& B){
        auto aux = A;
        A = B;
        B = aux;
    }
};

#endif //SORTMETHODS_SHELL_H
