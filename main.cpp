#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> msg {"pisulak", "maj"};
    for (auto element : msg){
        std::cout << element << "\n";
    }
    return 0;
}

