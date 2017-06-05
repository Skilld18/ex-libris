#include <vector>   
#include <algorithm>   
#include <sstream>   
#include <functional>



/// @brief An iterative algorithm to generate n choose k combinations   
/// @param n - Vector of possible values that n be chosen from   
/** @param valid - A check to see if a partial combination is valid   
 * For a typical n choose k any partial combination is valid*/   
///@param complete - A check to see if a given combination is fully vaild   
/**@param stack - A variable that holds the current combination. The function   
 * can be called again with the updated stack to get the next combination*/   
template<typename Collection,
         typename Subset = std::vector<typename Collection::const_iterator>,
         typename Predicate1 = std::function<bool(const Subset&)>,
         typename Predicate2 = std::function<bool(const Subset&)>>
void n_choose_k(Collection * n,
                Predicate1 valid,
                Predicate2 complete,
                Subset* stack){

    bool firstCall= true;   

    //The first time this gets called we need to populate the stack   
    //On subsequent calls the flag remains set so that the stack advances and doesn't return a duplicate combination   
    if (stack->size() < 1) {   
        stack->push_back(n->begin());   
        firstCall= false;   
    }   

    //As soon as we find a complete combination fall through   
    //complete in general means the combination is long enough(k) and that it is valid   
    //for typical n choose k everything is valid   
    while (!complete(*stack) || firstCall) {   
        //If the last element is at the end of the n iterator or we've set the 2nd pass flag   
        if (n->end() - stack->back() <= 1 || firstCall) {   
            //iterate through the stack and either   
            for (int i = 0; n->end() - stack->back() <= i + 1; i++) {   
                //clear the stack and return if all possibilities have been exhausted   
                if (stack->size() == 1) {   
                    stack->clear();   
                    return;   
                }   
                //or pop the last element of any stack that is a "conflict set"   
                //that is any stack that couldn't possibly be complete   
                //ie (1, 6, __) in (1,2,3,4,5,6) choose 3 as there is nothing   
                //greater than 6 and the elements go in ascending order   
                stack->pop_back();   
            }   
            //Advance to the next combination   
            stack->back()++;   

            //unset the flag and continue so we don't skip combinations   
            if (firstCall) {   
                firstCall= false;   
                continue;   
            }   
        }   


        //If the current partial combination(stack) is valid   
        if (valid(*stack)) {   
            stack->push_back(stack->back());   
        }   
        //And advance to the next combination   
        ++stack->back();
    }   
}   
