# include <iostream>
# include <stdio.h>
# include <vector>
# include "Factory.h"
# include "Adapter.h"
# include "Builder.h"
# include "AbstractFactory.h"
# include "Memento.h"
# include "Singleton.h"
# include "Facade.h"

int main(int argc, char *argv[]) {

    std::cout << "Main point of entry for testing Gang of Four design pattern implementations" << std::endl;

    
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
    
    //bankType whichBank = BOA;
    //double savingsDeposit = 1000;
    //double checkingDeposit = 2500;
    //double creditLine = 2500;
    
    //Bank *bank;
    
    //if (whichBank == WF) { bank = new WellsFargo; }
    //else { bank = new BankOfAmerica; }

    //BankPatron *patron = new BankPatron(bank, savingsDeposit, checkingDeposit, creditLine);
    //patron->viewAccounts();
    
    //delete patron;
    //delete bank;

    // --- ######################################## --- 
    
    // MEMENTO CLASS TEST

    // PROBLEM IS NOW THAT INDEXING LEADS TO VECTOR INDEX -1 ON FINAL UNDO...
    // NEED TO UPDATE USING CODE BLOCKS TO DEBUG, THEN BRANCH REPO, COPY PASTE FROM CODE BLOCKS WORKSPACE, AND MERGE BEFORE PUSHING TO GITHUB

    //std::string input;
    //std::cout << "Input string: ";
    //std::getline(std::cin,input);
    //InputString *string_in = new InputString(input);
    //
    //InputReceiver *directive = new InputReceiver(string_in, &InputString::concatString);
    //
    //std::cout << "Exit: exit, Undo: undo, Redo: redo, Concatenate: enter any other string: ";
    //std::getline(std::cin,input);
    //string_in->setInput(input);


    //while (input != "exit") {
    //    if (input == "undo") { directive->undo(); }
    //    else if (input == "redo") { directive->redo(); }
    //    else { directive->execute(); }
    //    std::cout << "   " << string_in->getString() << std::endl;
    //    std::cout << "Exit: exit, Undo: undo, Redo: redo, Concatenate: enter any other string: ";
    //    std::getline(std::cin,input);
    //    string_in->setInput(input);
    //}
   
    //delete directive;
    //delete string_in;

    // --- ######################################## --- 
    
    // SINGLETON CLASS TEST
    
    //SingletonClass::getInstance()->setString("Hello world");
    //std::cout << "Singleton class member string initialized as: " << SingletonClass::getInstance()->getString() << std::endl; 
    //std::cout << "Singleton class member string set to: " << SingletonClass::getInstance()->getString() << std::endl; 

    // --- ######################################## --- 
    
    // FACADE CLASS TEST
    
    FacadeClass DateAndTimeInterface;
    DateAndTimeInterface.getDateAndTime();

    // --- ######################################## --- 

    return 0;

}
