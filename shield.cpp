#include "shield.h"

//initializes a shield with 100 charge, and displays it
Shield::Shield():m_charge(100){
    std::cout<<"Charge: {"<<m_charge<<"}"<<std::endl;
}

//crank recharge random 7-12% per crank, displays current charge when loop ends
void Shield::crank_charge(){
    int cranks;
    std::cout<<"How many cranks?: ";
    std::cin>>cranks;
    for(int i=0;i<cranks;i++){
        int crank_power=(rand() % (12 - 7 + 1)) + 7;
        if((crank_power+m_charge)<=100){
            m_charge=m_charge+crank_power;
        }else{
            m_charge=100;
        }
    }
    std::cout<<"Charge: {"<<m_charge<<"}"<<std::endl;
}


//taking a shot, takes shot-blaster in by reference, 
//fires the shot blaster using the fire method, and uses the returned shell to calculate:
//calculates damage/generated blaster heat based on range/shell-type, displays shells fired, shells left, and shield charge left
//if trying to fire an empty magazine, displays: No shells left to fire, Charge: {charge}
//if trying to fire while overheated, displays: Too hot, nothing fired! Charge: {charge}
void Shield::take_shot(ShotBlaster& shotblaster){
    if(shotblaster.m_count>0){
        std::string shell=shotblaster.fire();
        std::cout<<"Shell fired: ["<<shell<<"]"<<std::endl;
        std::cout<<"Shells left: "<<shotblaster.m_count<<std::endl;
        if(shell=="slug"){
            //shield damage
            if(shotblaster.m_range<=25&&shotblaster.m_range>=0){
                if((m_charge-100)>0){
                    m_charge=m_charge-100;
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                } 
            }else if(shotblaster.m_range<=50){
                if((m_charge-75)>0){
                    m_charge=m_charge-75;
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                }
            }else if(shotblaster.m_range<=75){
                if((m_charge-50)>0){
                    m_charge=m_charge-50;
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                }
            }else if(shotblaster.m_range<=100){
                if((m_charge-25)>0){
                    m_charge=m_charge-25;
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                }
            }
            //heat
            if((shotblaster.m_heat+25)<100){
                shotblaster.m_heat=shotblaster.m_heat+25;
            }else{
                shotblaster.m_heat=100;
                std::cout<<"Overheat!"<<std::endl;
            }
            std::cout<<"Charge: {"<<m_charge<<"}"<<std::endl;
            std::cout<<"Shot-blaster heat: "<<shotblaster.m_heat<<std::endl;

        }else if(shell=="lb"){
            //shield damage
            if(shotblaster.m_range<=100&&shotblaster.m_range>=0){
                if((m_charge-(100*std::pow(0.97,shotblaster.m_range)))>0){
                    m_charge=m_charge-(100*std::pow(0.97,shotblaster.m_range));
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                }
            }
            //heat
            if((shotblaster.m_heat+15)<100){
                shotblaster.m_heat=shotblaster.m_heat+15;
            }else{
                shotblaster.m_heat=100;
                std::cout<<"Overheat!"<<std::endl;
            }
            std::cout<<"Charge: {"<<m_charge<<"}"<<std::endl;
            std::cout<<"Shot-blaster heat: "<<shotblaster.m_heat<<std::endl;

        }else if(shell=="sb"){
            //shield damage
            if(shotblaster.m_range<=100&&shotblaster.m_range>=0){
                if((m_charge-(50*std::pow(0.9909,shotblaster.m_range)))>0){
                    m_charge=m_charge-(50*std::pow(0.9909,shotblaster.m_range));
                }else{
                    m_charge=0;
                    std::cout<<"Shields Depleted!"<<std::endl;
                }
            }
            //heat
            if((shotblaster.m_heat+10)<100){
                shotblaster.m_heat=shotblaster.m_heat+10;
            }else{
                shotblaster.m_heat=100;
                std::cout<<"Overheat!"<<std::endl;
            }
            std::cout<<"Charge: {"<<m_charge<<"}"<<std::endl;
            std::cout<<"Shot-blaster heat: "<<shotblaster.m_heat<<std::endl;

        }else if(shell=="!!!"){
            std::cout<<"Too hot, nothing fired! Charge: {"<<m_charge<<"}"<<std::endl;
        }
    }else{
        std::cout<<"No shells left to fire, Charge: {"<<m_charge<<"}"<<std::endl;
    }
}





