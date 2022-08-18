 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <list>
 #include <unistd.h>


int main(){
std::ios_base::sync_with_stdio(false);

    for(Int i("5");i<Int("1000000000000000000");i+=i){
        std::cout<<i.getBin()<<std::endl;
    }


    return 0;
}