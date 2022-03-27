#include "event.h"

std::ostream &operator<<(std::ostream &out, const EVENT &obj){
    out << obj.time; 
    return out; 
}

EVENT::EVENT()
    :type{NULL}, time{0}, duration{0}{

}

EVENT::EVENT(char nType, int nTime)
    :type{nType}, time{nTime}, duration{0}{

}

EVENT::EVENT(char nType, int nTime, int nDuration)
    :type{nType}, time{nTime}, duration{nDuration}{

}

char EVENT::getType() const{
    return type; 
}

int EVENT::getTime() const{
    return time; 
}

int EVENT::getDuration() const{
    return duration; 
} 

void EVENT::setType(char nType){
    type = nType; 
}
    
void EVENT::setTime(int nTime){
    time = nTime;
}

void EVENT::setDuration(int nDuration){
    duration = nDuration; 
}

bool EVENT::operator<(const EVENT &rhs) const{
    return this->time > rhs.time; 
}
    
bool EVENT::operator<=(const EVENT &rhs) const{
    return this->time >= rhs.time; 
}

bool EVENT::operator>(const EVENT &rhs) const{
    return this->time < rhs.time; 
}

