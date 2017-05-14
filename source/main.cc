#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include "nchoosek.h"

using namespace std;
bool isPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}


bool check(int a, int b){
    ostringstream oss;
    oss << a << b;
    istringstream iss(oss.str());
    int c;

    iss >> c;
    return isPrime(c);
}


bool valid(vector<int> perm){
    for(auto const& a: perm) {
        for(auto const& b: perm) {
            if(a!=b && !check(a,b)){
                return false;
            }
        }
    }
    return true;
}



int main(int argc, char** argv) {
    
    vector<int> primes;
    for(int i = 3;i<10000;i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
   
    vector<int> perm;
    vector<vector<int>::iterator> stack;
    //13, 5197, 5701, 6733, 8389, 
    perm = n_choose_k(primes, stack, 5, &valid);
    for(int i = 0;i<5;i++){
        cout << perm[i] << ", ";
    }
    cout << endl;
    
    return 0;
}
