#include <vector>
#include <iostream>
#include <algorithm>
//TODO:: add an append to iterator function
//TODO:: terminate on n finished check code for partials? Whats the term condition on undef n
//TODO:: check if set will never exist 
//TODO:: allow duplicates? bool flag



using namespace std;
template <typename T, typename A>
void n_choose_k(vector<T,A> * n, vector<typename vector<T,A>::iterator> * stack, size_t k, bool (*valid)(vector<typename vector<T,A>::iterator> data)) {
	bool second = false;
	if(stack->size() < 1){
		stack->push_back(n->begin());
	}
	else{
		second = true;
		stack->pop_back();
	}

    //size of the current n vector
    while (stack->size() < k) {
		//if this is reentrant increase the last element of the stack before we start
		if(second){
			stack->back()++;
			second = false;
		}
        //if we are at the end of the iterator pop the stack and increment the end of the stack 
		if (stack->back() == n->end()) {
			stack->pop_back();
            stack->back()++;
        }
        
        //while we haven't exhausted the stack
        while (stack->back() != n->end()) {
            //add the current eos to result
            //if it's valid add another layer to the stack
            if (valid(*stack)){
				if (stack->size() < k){
					stack->push_back(stack->back());
					stack->back()++;
				}
                break;
            }
            //otherwise pop the result and increment the stack
            stack->back()++;
        }
    }
}

