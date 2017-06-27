# include <iostream>
# include <stdio.h>
# include <vector>
# include "Factory.h"

int main(int argc, char *argv[]) {

    std::cout << "Main point of entry for use of Gang of Four design pattern implementations" << std::endl;

    
    // --- ######################################## --- 
   
    // FACTORY CLASS TEST

    // Add several lures to tacklebox to test Factory class implementation
    std::vector<Lure*> tackleBox;
    tackleBox.push_back(Lure::setLure(JIG));
    tackleBox.push_back(Lure::setLure(SPINNER));
    tackleBox.push_back(Lure::setLure(PLUG));
    tackleBox.push_back(Lure::setLure(FLY));
    tackleBox.push_back(Lure::setLure(SOFTPLASTIC));

    for (int i = 0; i < tackleBox.size(); ++i){
        tackleBox.at(i)->getLure();
    }

    for (int i = 0; i < tackleBox.size(); ++i){
        delete tackleBox[i];
    }
    
    // --- ######################################## --- 

    return 0;

}
