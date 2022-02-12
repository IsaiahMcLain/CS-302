#include "cargo.h"

Cargo::Cargo()
    : weight(0.0), type("none"){

}

Cargo::Cargo(const double& nWeight,const std::string& nType){
    weight = nWeight;
    type = nType; 
}

std::ostream& operator<<(std::ostream& out, const Cargo& obj){
    out << "Objects weight: " << obj.weight << " lbs" 
    << " Object's type: " << obj.type;
    return out;
}

Cargo& Cargo::operator+(const Cargo& obj1){
    this->weight = this->weight + obj1.weight; 
    return *this; 
}
