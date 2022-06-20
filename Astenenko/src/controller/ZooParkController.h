

#ifndef ASTENENKO_ZOOPARKCONTROLLER_H
#define ASTENENKO_ZOOPARKCONTROLLER_H


#include <vector>
#include <iostream>
#include <iomanip>
#include "ZooPark.h"
#include "../infrastructure/controller/AbstractStorageController.h"

class ZooParkController : public AbstractStorageController<ZooParkController, ZooPark>{
private:
    static inline void printSep(){
        std::cout<<"+"<<std::setw(2)<<std::setfill('-')<<"";
        std::cout<<"+"<<std::setw(10)<<"";
        std::cout<<"+"<<std::setw(10)<<""<<"+\n";
    }
public:
    ZooParkController() = default;

    void print() override {

        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        std::cout <<"|"<<std::setw(2)<<"id";
        std::cout <<"|"<<std::setw(10)<<"name";
        std::cout <<"|"<<std::setw(10)<<"animals";
        std::cout <<"|\n";
        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        for (int i = 0; i < this->getStorage()->size(); ++i) {
            std::cout << "|" << std::setw(2)<<i;
            std::cout << *this->getStorage()->at(i);
        }
        printSep();

    }

    std::string name() override {
        return "zoo";
    }

    void create() override {
        std::string name;

        std::cout << "name >";
        std::cin>>name;
        ZooPark* zoo = new ZooPark(name);
        this->add(zoo);
    }

    void remove() override {
        this->getStorage()->erase(this->getStorage()->begin()+selectId());
    }
};

Init(ZooParkController)

#endif //ASTENENKO_ZOOPARKCONTROLLER_H
