#include "GarbageClass.h"
#include <vector>

std::vector<GarbageClass> garbage;

int main(){

    for(auto i = 0; i < 2; i++)
        //hier roep je constructors aan
        garbage.emplace_back(GarbageClass());

    std::cout << "\n";

    for(auto& temp: garbage){
        temp.method();
    }
    std::cout << "\n\n";
    std::cout << "hit enter to proceed: ";
    std::cin.get();

    for(auto& temp : garbage)
        temp.method(1);

    GarbageClass garb;
    //hier kopieer je naar al bestaand object
    garb = garbage[0];

    for(auto i = 0; i < 5; i++){
        std::cout << garb.getValue(i) << std::endl;
    }


    std::cout << "Finished Running" << std::endl;
    return 0;
}