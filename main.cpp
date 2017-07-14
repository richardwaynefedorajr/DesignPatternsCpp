# include <iostream>
# include <stdio.h>
# include <vector>
# include "Factory.h"
# include "Adapter.h"
# include "Builder.h"
# include "AbstractFactory.h"

int main(int argc, char *argv[]) {

    std::cout << "Main point of entry for use of Gang of Four design pattern implementations" << std::endl;

    
    // --- ######################################## --- 
   
    // FACTORY CLASS TEST

    // Add several lures to tacklebox to test Factory class implementation
    //std::vector<Lure*> tackleBox;
    //tackleBox.push_back(Lure::setLure(JIG, "3/8th oz.","football head","Rage Craw"));
    //tackleBox.push_back(Lure::setLure(SPINNER,"1/4 oz.","willow leaf","gold"));
    //tackleBox.push_back(Lure::setLure(PLUG,"6 inch","Rapala","Fire Tiger"));
    //tackleBox.push_back(Lure::setLure(FLY,"3 inch","streamer","blue over white"));
    //tackleBox.push_back(Lure::setLure(SOFTPLASTIC,"6 inch","stick bait","watermelon flake"));

    //for (int i = 0; i < tackleBox.size(); ++i){
    //    tackleBox.at(i)->getLure();
    //}

    //for (int i = 0; i < tackleBox.size(); ++i){
    //    delete tackleBox[i];
    //}
    
    // --- ######################################## --- 
    
    // ADAPTER CLASS TEST
   
    // Client interacts with Weight interface through weightAdapter initilized with weight in lbs. 
    //Weight *w = new weightAdapter(30); // lbs.
    
    // Calling the getWeight function shows that a mass value is now available to the incompatible Mass interface
    //w->getWeight();    

    // --- ######################################## --- 

    // BUILDER CLASS TEST
    
    //TruckDealership dealer;
    //RamBuilder ram;
    //FordBuilder ford;

    //dealer.makeTruck(&ram);
    //dealer.lookAtTruck();

    //dealer.makeTruck(&ford);
    //dealer.lookAtTruck();

    // --- ######################################## --- 

    // ABSTRACT FACTORY CLASS TEST
    bankType whichBank = BOA;
    double savingsDeposit = 1000;
    double checkingDeposit = 2500;
    double creditLine = 2500;
    
    Bank *bank;
    
    if (whichBank == WF) { bank = new WellsFargo; }
    else { bank = new BankOfAmerica; }

    BankPatron *patron = new BankPatron(bank, savingsDeposit, checkingDeposit, creditLine);
    patron->viewAccounts();
    
    delete patron;
    delete bank;

    // --- ######################################## --- 


    return 0;

}
