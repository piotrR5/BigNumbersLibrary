 #include "Int.h"
 #include <iostream>
 #include <string>
 #include <vector>
 #include <list>
 #include <unistd.h>


int main(){


    for(Int i("0");;i+=Int("20")){
        std::cout<<i.getBin()<<std::endl;
    }



    return 0;
}