/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rdunk
 *
 * Created on May 6, 2017, 11:20 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

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

unordered_map<int, bool> primeMap;

bool check(int a, int b){
    ostringstream oss;

    oss << a << b;

    istringstream iss(oss.str());
    int c;

    iss >> c;
    /*if(c<10000){
        return primeMap.at(c);
    }*/
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

void recurse(vector<int> primes, vector<int> perm){
    if(perm.size()>4){
        for(int i = 0;i<5;i++){
            cout << perm[i] << ", ";
        }
        cout << endl;
    }
    for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
        perm.push_back(*it);
        if(valid(perm)){
            recurse(vector<int>(++it, primes.end()), perm);
        }
        perm.pop_back();
    }
}



/*
 * 
 */
int main(int argc, char** argv) {
    
    vector<int> primes;
    for(int i = 3;i<10000;i++){
        if(isPrime(i)){
            primes.push_back(i);
            primeMap.insert(pair<int,bool>(i, true));

        }
        else{
            primeMap.insert(pair<int,bool>(i, false));
        }
    }
   

                
    
   
    vector<int> perm;
    vector<int>::iterator it = primes.begin();
//    vector<auto> itStack;
//    itStack.push_back(primes.begin());
    //13, 5197, 5701, 6733, 8389, 
    //recurse(primes, perm);
    while(perm.size()<5){
        if(it==primes.end()){
            it = std::find(primes.begin(), primes.end(), perm[perm.size()-1]);
            it++;
            perm.pop_back();
        }
        while(it!=primes.end()){
            
        
            perm.push_back(*it);
            if(valid(perm)){
                ++it;
                break;
            }
            perm.pop_back();
            it++;
        }
        
    }
    for(int i = 0;i<5;i++){
        cout << perm[i] << ", ";
    }
    cout << endl;
    
    

    return 0;
}

