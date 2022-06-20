

#ifndef ASTENENKO_ANIMALSCONTROLLER_H
#define ASTENENKO_ANIMALSCONTROLLER_H


#include "../infrastructure/controller/IController.h"
#include "../model/animal/Animal.h"
#include "../infrastructure/controller/AbstractStorageController.h"

class AnimalsController : public AbstractStorageController<AnimalsController, Animal>{
private:
    static void printSep(){
        std::cout<<"+"<<std::setw(10)<<std::setfill('-')<<"";//type
        std::cout<<"+"<<std::setw(10)<<""; //age
        std::cout<<"+"<<std::setw(10)<<""; //weight
        std::cout<<"+"<<std::setw(10)<<""; //hunger
        std::cout<<"+"<<std::setw(40)<<""<<"+\n"; //additional


    }
public:
    void print() override {
        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        std::cout<<"|"<<std::setw(10)<<"type";//type
        std::cout<<"|"<<std::setw(10)<<"age"; //age
        std::cout<<"|"<<std::setw(10)<<"weight"; //weight
        std::cout<<"|"<<std::setw(10)<<"hunger"; //hunger
        std::cout<<"|"<<std::setw(40)<<"additional"<<"|\n"; //additional
        printSep();
        std::cout<<std::setfill(' ');
        for (const auto &item: *this->getStorage()){
            std::cout<<*item;
        }
        printSep();
    }

    std::string name() override {
        return "animal";
    }

    void create() override {
        std::cout<<"select type:\n";
        for (const auto &item: *BaseAnimalFactory::getMap()){
            std::cout<<"\t"<<item.first<<"\n";
        }
        std::cout<<"type >";
        std::string type;
        std::cin>>type;
        this->add(BaseAnimalFactory::createInstance(type));
    }

    void remove() override {

    }

};

Init(AnimalsController)

#endif //ASTENENKO_ANIMALSCONTROLLER_H
