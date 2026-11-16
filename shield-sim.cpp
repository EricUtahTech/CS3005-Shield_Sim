#include "shield.h"
#include "shot-blaster.h"
#include <string>

void main(){
    Shield shield;
    ShotBlaster shotblaster;
    bool quit=false;
    std::cout<<"Shield testing in progress..."<<std::endl;
    while(!quit){
        std::string choice;
        std::cout<<"Choice[charge, shoot, reload, cool, range, quit]: ";
        std::cin>>choice;
        if(input=="charge"){
            shield.crank_charge();
        }else if(input=="shoot"){
            shield.take_shot();
        }else if(input=="reload"){
            shotblaster.load_shells();
        }else if(input=="cool"){
            shotblaster.cool();
        }else if(input=="range"){
            shotblaster.change_range();
        }else if(input=="quit"){
            std::cout<<"Testing Completed"<<std::endl;
            quit=true;
        }else{
            std::cout<<"Not a valid choice"<<std::endl;
        }
    }
}