#include <iostream>
#include <vector>


int main(){
std::vector<int> vec{1,2,3};

auto iter = vec.begin();

auto iter2 = vec.begin();
iter2++;
iter2--;

if(iter==iter2)std::cout<<"siii";




// std::cout<<*vec.end();
return 0;
}