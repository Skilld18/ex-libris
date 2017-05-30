#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
template<typename T, typename A>
bool at_end(vector<T,A> * n, vector<typename vector<T, A>::iterator> *stack){
    for (int i = 0; n->end() - stack->back() <= i + 1; i++) {
        if (stack->size() == 1) {
            stack->clear();
            return true;
        }
        stack->pop_back();
    }
    return false;
}

/** Iterative n choose k algorithm that fills up a sta **/
template<typename T, typename A>
void n_choose_k(
        vector<T, A> *n,
        vector<typename vector<T, A>::iterator> *stack,
        bool (*valid)(vector<typename vector<T, A>::iterator> data),
        bool (*complete)(vector<typename vector<T, A>::iterator> data),
        //Allows duplicate elements of n
        bool duplicates) {

    //if this is the first time this is getting called load up the stack with the start of n
    if (stack->size() < 1) {
        stack->push_back(n->begin());
    } else {
        if(at_end(n, stack)){
            return;
        }
        stack->back()++;
    }

    while (!complete(*stack)) {
        if (n->end() - stack->back() <= 1 ) {
            if(at_end(n, stack)){
                return;
            }
            stack->back()++;
        }
        if (valid(*stack)) {
            stack->push_back(stack->back());
        }

        if (!duplicates) {
            stack->back()++;
        }
    }
}

