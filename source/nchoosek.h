#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
template <typename T, typename A>
//vector<T,A> n_choose_k(vector<T,A> n, vector<typename vector<T,A>::iterator> stack, int k, bool (*valid)(vector<T,A> data)) {
vector<T,A> n_choose_k(vector<T,A> n, int k, bool (*valid)(vector<T,A> data)) {
    typename vector<T,A>::iterator it = n.begin();
    vector<T,A> result;
    while (result.size() < k) {
        if (it == n.end()) {
	    int x = result[result.size()-1];
	    it = find(n.begin(), n.end(), x);
	    it++;
            result.pop_back();
        }
        while (it != n.end()) {
            result.push_back(*it);
            if (valid(result)) {
                ++it;
                break;
            }
            result.pop_back();
            it++;
        }
    }
    return result;
}

