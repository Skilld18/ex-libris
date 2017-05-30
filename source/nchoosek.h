#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

template<typename T, typename A>
void n_choose_k(vector<T, A> *n, vector<typename vector<T, A>::iterator> *stack,
                bool (*valid)(vector<typename vector<T, A>::iterator> data),
                bool (*complete)(vector<typename vector<T, A>::iterator> data)) {
    //if this is the first time this is getting called load up the stack with the start of n
    if (stack->size() < 1) {
        stack->push_back(n->begin());
    } else {
        //if this is reentrant increase the last element of the stack before we start
        //catch ending
        for (int i = 0; n->end() - stack->back() <= i + 1; i++) {
            stack->pop_back();
        }
        if (stack->size() < 1) {
            return;
        }
        stack->back()++;
    }

    while (!complete(*stack)) {
        for (int i = 0; n->end() - stack->back() <= i + 1; i++) {
            stack->pop_back();
            stack->back()++;
        }
        //All possibilities exhausted
        if (stack->size() < 1) {
            return;
        }
        if (valid(*stack)) {
            stack->push_back(stack->back());
        }

        //All possibilities of one var exhausted
        stack->back()++;

    }
}

