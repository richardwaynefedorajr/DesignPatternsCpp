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
    tackleBox.push_back(Lure::setLure(JIG, "3/8th oz.","football head","Rage Craw"));
    tackleBox.push_back(Lure::setLure(SPINNER,"1/4 oz.","willow leaf","gold"));
    tackleBox.push_back(Lure::setLure(PLUG,"6 inch","Rapala","Fire Tiger"));
    tackleBox.push_back(Lure::setLure(FLY,"3 inch","streamer","blue over white"));
    tackleBox.push_back(Lure::setLure(SOFTPLASTIC,"6 inch","stick bait","watermelon flake"));

    for (int i = 0; i < tackleBox.size(); ++i){
        tackleBox.at(i)->getLure();
    }

    for (int i = 0; i < tackleBox.size(); ++i){
        delete tackleBox[i];
    }
    
    // --- ######################################## --- 

    return 0;

}
