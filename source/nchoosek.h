#include <vector>
#include <iostream>
#include <algorithm>
//TODO:: check if set will never exist
using namespace std;
template <typename T, typename A>
vector<T,A> n_choose_k(vector<T,A> n, vector<typename vector<T,A>::iterator> stack, int k, bool (*valid)(vector<T,A> data)) {
    //TODO:: pass this in?
    //typename vector<T,A>::iterator it = n.begin();
    stack .push_back(n.begin());
    vector<T,A> result;
    //size of the current vector
    while (result.size() < k) {
        //if we are at the end of the iterator pop the stack and increment the end of the stack
        if (stack.back() == n.end()) {
	    stack.pop_back();
            stack.back()++;
            result.pop_back();
        }
        
        //while we haven't exhausted the stack
        while (stack.back() != n.end()) {
            //add the current eos to result
            result.push_back(*stack.back());
            //if it's valid add another layer to the stack
            if (valid(result)) {
                stack.push_back(++stack.back());
                break;
            }
            //otherwise pop the result and increment the stack
            result.pop_back();
            //it++;
            stack.back()++;
        }
    }
    return result;
}

