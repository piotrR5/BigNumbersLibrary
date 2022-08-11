 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>


std::ostream& operator<<(std::ostream& stream, std::vector<bool>&bin){
    int foo=0;
    for(auto i:bin){
        if(foo++%64==0)stream<<std::endl;
        stream<<i;
    }
    stream<<"\r";
    return stream;
}

 int main(int argc, char* argv[]){

    Int integer("5982390578947151752839579853748234472490327491");
    std::cout<<integer.bin;
    //for(auto i:integer.bin)std::cout<<i;
    std::cout<<std::endl;
    std::cout<<integer.bin_length<<std::endl;
    integer.resize(INT1024SIZE);
    std::cout<<integer.bin<<std::endl;
    std::cout<<integer.bin_length<<std::endl;
    std::cout<<(integer+Int("12423424")).bin;

    return 0;
 }
