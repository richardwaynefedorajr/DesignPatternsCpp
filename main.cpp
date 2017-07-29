# include <iostream>
# include <stdio.h>
# include <vector>
//# include "Factory.h"
//# include "Adapter.h"
//# include "Builder.h"
//# include "AbstractFactory.h"
//# include "Memento.h"
//# include "Singleton.h"
//# include "Facade.h"
//# include "Mediator.h"
//# include "Decorator.h"
//# include "Bridge.h"
# include "CoR.h"

int main(int argc, char *argv[]) {

    std::cout << "Main point of entry for testing Gang of Four design pattern implementations" << std::endl;

    
    // --- ######################################## --- 
   
    // FACTORY DESIGN PATTERN TEST

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
    
    // ADAPTER DESIGN PATTERN TEST
   
    // Client interacts with Weight interface through weightAdapter initilized with weight in lbs. 
    //Weight *w = new weightAdapter(30); // lbs.
    
    // Calling the getWeight function shows that a mass value is now available to the incompatible Mass interface
    //w->getWeight();    

    // --- ######################################## --- 

    // BUILDER DESIGN PATTERN TEST
    
    //TruckDealership dealer;
    //RamBuilder ram;
    //FordBuilder ford;

    //dealer.makeTruck(&ram);
    //dealer.lookAtTruck();

    //dealer.makeTruck(&ford);
    //dealer.lookAtTruck();

    // --- ######################################## --- 

    // ABSTRACT FACTORY DESIGN PATTERN TEST
    
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
    
    // MEMENTO DESIGN PATTERN TEST

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
    
    // SINGLETON DESIGN PATTERN TEST
    
    //SingletonClass::getInstance()->setString("Hello world");
    //std::cout << "Singleton class member string initialized as: " << SingletonClass::getInstance()->getString() << std::endl; 
    //std::cout << "Singleton class member string set to: " << SingletonClass::getInstance()->getString() << std::endl; 

    // --- ######################################## --- 
    
    // FACADE DESIGN PATTERN TEST
    
    //FacadeClass DateAndTimeInterface;
    //DateAndTimeInterface.getDateAndTime();

    // --- ######################################## --- 
    
    // MEDIATOR DESIGN PATTERN TEST
    
    //InteractionMediator *im; 
    //InteractionMediator i; 
    //im = &i;

    //Larry *larry; 
    //Curly *curly; 
    //Moe *moe;
    //
    //Larry l(im); 
    //Curly c(im);
    //Moe m(im);
    //
    //larry = &l; 
    //curly = &c; 
    //moe = &m;

    //im->getStooges(larry, curly, moe);

    //larry->accidentallyHitMoe();
    //curly->accidentallyHitMoe();
    //moe->pokeCurlysEyes();
    //moe->slapLarrysHead();

    // --- ######################################## --- 
    
    // DECORATOR DESIGN PATTERN TEST
    
    //WeaponSystem *base_platform = new AssaultRifle("M4 ");
    //WeaponSystem *with_scope = new Scope(new AssaultRifle("M4 "), "red dot ");
    //WeaponSystem *with_scope_and_foregrip = new Foregrip(new Scope(new AssaultRifle("M4 "), "red dot "),"vertical foregrip ");
    //WeaponSystem *with_scope_and_foregrip_and_suppressor = new Suppressor(new Foregrip(new Scope(new AssaultRifle("M4 "), "red dot "),"vertical foregrip "),"AAC M4-2000 ");
    //
    //base_platform->getWeaponSystem();
    //std::cout << std::endl; 

    //with_scope->getWeaponSystem();
    //std::cout << std::endl; 

    //with_scope_and_foregrip->getWeaponSystem();
    //std::cout << std::endl; 

    //with_scope_and_foregrip_and_suppressor->getWeaponSystem();
    //std::cout << std::endl; 

    //delete base_platform;
    //delete with_scope;
    //delete with_scope_and_foregrip;
    //delete with_scope_and_foregrip_and_suppressor;
    
    // --- ######################################## --- 
    
    // BRIDGE DESIGN PATTERN TEST
    
    //LureCharacteristic* black = new Color("black");
    //LureCharacteristic* pearl = new Color("pearl");
    //LureCharacteristic* firetiger = new Color("firetiger");

    //LureCharacteristic* quarter_oz = new Weight("1/4 oz."); 
    //LureCharacteristic* half_oz = new Weight("1/2 oz."); 
    //LureCharacteristic* three_quarter_oz = new Weight("3/4 oz."); 

    //LureCharacteristic* four_inch = new Length("4\"");
    //LureCharacteristic* five_inch = new Length("5\"");
    //LureCharacteristic* six_inch = new Length("6\"");

    //LureCharacteristic* shallow = new Depth ("0-4\'");
    //LureCharacteristic* medium_depth = new Depth ("4-8\'");
    //LureCharacteristic* deep_diver = new Depth ("8-12\'");

    //LureType* big_bass_jig = new Jig(black, three_quarter_oz);
    //LureType* finesse_jig = new Jig(pearl, quarter_oz);

    //LureType* big_plastic = new SoftPlastic(black, six_inch);
    //LureType* small_plastic = new SoftPlastic(pearl, four_inch);

    //LureType* power_crank = new Crankbait(firetiger, six_inch, deep_diver);
    //
    //LureType* classic_spinnerbait = new Spinnerbait(pearl, half_oz);

    //big_bass_jig->getLure();
    //finesse_jig->getLure();
    //big_plastic->getLure();
    //small_plastic->getLure();
    //power_crank->getLure();
    //classic_spinnerbait->getLure();

    //delete big_bass_jig, delete finesse_jig;
    //delete big_plastic, delete small_plastic;
    //delete power_crank;
    //delete classic_spinnerbait;

    //delete black, delete pearl, delete firetiger;
    //delete quarter_oz, delete half_oz, delete three_quarter_oz;
    //delete four_inch, delete five_inch, delete six_inch;
    //delete shallow, delete medium_depth, delete deep_diver; 
    
    // --- ######################################## --- 
    
    // CHAIN OF RESPONSIBILITY DESIGN PATTERN TEST
    
    Cashier cashier;
    Cook cook;
    Runner runner;

    cashier.addWorker(&cook);
    cashier.addWorker(&runner);
    runner.setNext(&cashier);

    FastFood request1 = burger;
    FastFood request2 = drink;
    FastFood request3 = fries;
    FastFood request4 = change;

    cashier.service(request1);
    cashier.service(request2);
    cashier.service(request3);
    cashier.service(request4);

    // --- ######################################## --- 

    return 0;

}
