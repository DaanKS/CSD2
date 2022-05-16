#include "GarbageClass.h"
#include <vector>

std::vector<GarbageClass> garbage;

int main(){

    for(auto i = 0; i < 2; i++)
        garbage.emplace_back(GarbageClass());
    for(auto& ciska : garbage){
        std::cout << "made temporary object" << std::endl;
        ciska.method();
    }
    std::cout << "\n\n";

    std::cout << "hit enter to proceed: ";
    std::cin.get();

    auto f = 0;
    for(auto& marc : garbage){
        std::cout << f++ << std::endl;
        marc.method(1);
    }
    std::cout << "\n\n";

    std::cout << "hit enter to proceed: ";
    std::cin.get();

    for(auto& temp : garbage) {
        for (auto i = 0; i < 5; i++) {
            std::cout << "Value: " << i << " " << temp.getValue(i) << std::endl;
        }
    }

    std::cout << "\n\n";


    std::cout << "Finished Running" << std::endl;
    return 0;
}