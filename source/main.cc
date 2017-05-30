#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> 
#include <unordered_map>
#include "nchoosek.h"

using namespace std;
bool isPrime(int number){
    if(number == 2) return true;
    if(number % 2 == 0) return false; 
	for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    } 
	return true;
}


bool check(int a, int b){ ostringstream oss;
    oss << a << b;
    istringstream iss(oss.str());
    int c;

    iss >> c;
    return isPrime(c);
}


bool valid(vector<vector<int>::iterator>  stack){
    for(auto const& a: stack) {
        for(auto const& b: stack) {
            if(a!=b && !check(*a,*b)){
                return false;
            }
        }
    }
    return true;
}

bool val(vector<vector<int>::iterator>  stack){
    return true;
}

bool complete(vector<vector<int>::iterator>  stack){
	return stack.size() == 5 && valid(stack);
}
bool comp(vector<vector<int>::iterator>  stack){
    return stack.size() == 3 && val(stack);
}



int main(void) {
    vector<int> n;
    vector<vector<int>::iterator>  stack;


    for(int i = 3;i<10000;i++){
        if(isPrime(i)){
            n.push_back(i);
        }
    }
    //13, 5197, 5701, 6733, 8389,
	n_choose_k(&n, &stack, &valid, &complete, false);
	for(size_t i = 0;i<stack.size();i++){
		cout << *stack[i] << ", ";
	}
	cout << endl;
    n.clear();
    for(int i = 1;i<6;i++){
        n.push_back(i);
    }
    stack.clear();
    do {
    n_choose_k(&n, &stack, &val, &comp, false);
        for(size_t i = 0;i<stack.size();i++){
            cout << *stack[i] << ", ";
        }
    cout << endl;
    }while(!stack.empty());
    return 0;
}
