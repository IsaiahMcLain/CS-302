template<typename T1, typename T2> 
People<T1,T2>::People()
    : height(0.0), name("none"){

}

template<typename T1, typename T2>
People<T1,T2>::People(const T1& nHeight,const T2& nName){
    height = nHeight;
    name = nName; 
}

template<typename T3, typename T4>
bool operator<(const T3& lhs, const T4& rhs){
    return lhs.height < rhs.height; 
}

template<typename T3, typename T4>
std::ostream& operator<<(std::ostream& out, const People<T3,T4>& obj){
    out << "Passenger's height: " << obj.height << " ft" 
    << " Passenger's name: " << obj.name;
    return out;
}

template<typename T3, typename T4>
bool operator==(const T3& lhs, const T4& rhs){
    return lhs.height == rhs.height; 
}
