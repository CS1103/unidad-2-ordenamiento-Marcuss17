#ifndef SORTMETHODS_SHELL_H
#define SORTMETHODS_SHELL_H

class ShellSort{
public:
    template<typename container, typename forward>
    void sort(container& cnt, forward first, forward last){
        int n = 2;
        auto jump = first + (last-first)/n;
        while(jump > first){
            bool allOrdered = true;
            while(allOrdered){
                int count = 0; auto j = first; auto it2 = jump;
                while(it2 != last){
                    if(*j > *it2) {
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
