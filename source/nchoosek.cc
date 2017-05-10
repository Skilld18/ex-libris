#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void test(){
	cout << "test" << endl;	
}
vector<int> n_choose_k(vector<int> n, int k, bool (*valid)(vector<int> data)) {
    typename vector<int>::iterator it = n.begin();
    vector<int> result;
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

