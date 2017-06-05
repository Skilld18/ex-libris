#include <cstdlib>
#include <iostream>
#include <vector>
#include "nchoosek.h"


bool valid(std::vector<std::vector<int>::iterator>  stack){
    return true;
}

bool complete(std::vector<std::vector<int>::iterator>  stack){
    return stack.size() == 3;
}

int main(void) {
	std::vector<int> n = {1, 2, 3, 4, 5};
	std::vector<std::vector<int>::iterator> stack;
	while(true){
	    n_choose_k(&n, valid, complete, &stack);
		if(stack.empty()){
			break;
		}
		else{
			for (size_t i = 0; i < stack.size(); i++) {
				std::cout << *stack[i] << ", ";
			}
			std::cout << std::endl;

		}
	}
    return 0;
}
