#include "shield.h"

//initializes a shield with 100 charge, and displays it
Shield::Shield():m_charge(100){
    std::cout<<"Charge: "<<m_charge;
}

//crank recharge random 7-12% per crank, displays current charge when loop ends
void Shield::crank_charge(){
    int cranks;
    printf("How many cranks?: ");
    scanf("%d", &cranks);
    for(int i=0;i<cranks;i++){
        int crank_power=(rand() % (12 - 7 + 1)) + 7;
        if((crank_power+m_charge)<=100){
            m_charge=m_charge+crank_power;
        }else{
            m_charge=100;
        }
    }
    std::cout<<"Charge: "<<m_charge;
}


//taking a shot, takes shot-blaster in by reference, 
//fires the shot blaster using the fire method, and uses the returned shell to calculate:
//calculates damage based on range/shell-type, and displays shells fired, and shield charge left
//if trying to fire an empty magazine, displays: No shells left to fire, charge: {charge}
void Shield::take_shot(ShotBlaster& shotblaster,int range){

}





