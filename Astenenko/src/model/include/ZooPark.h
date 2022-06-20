

#ifndef ASTENENKO_ZOOPARK_H
#define ASTENENKO_ZOOPARK_H


#include <string>
#include "../animal/Animal.h"

class ZooPark {
public:
    friend std::ostream& operator<<(std::ostream& os, const ZooPark& dt);

    ZooPark(std::string name) : name(std::move(name)) {}

private:
    std::string name;
    std::vector<Animal*> animals;
};

std::ostream &operator<<(std::ostream &os, const ZooPark &dt) {
    os << "|" << std::setw(10) << dt.name;
    os << "|" << std::setw(10) << dt.animals.size();
    os << "|\n";
    return os;
}


#endif //ASTENENKO_ZOOPARK_H
