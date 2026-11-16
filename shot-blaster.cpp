#include "shot-blaster.h"

//initializes a shot blaster with an empty stack magazine, empty shot count, displays next round: [empty]
ShotBlaster::ShotBlaster():m_range(0),m_capacity(5),m_count(0),m_heat(0){
    std::cout<<"Magazine: [empty]"<<std::endl;
}

//loading shells (gives user choice between slug[s], large bearing[l], and mini bearing[m]), up to m_capacity can be loaded, updates shot count
void ShotBlaster::load_shells(){
    int shells;
    std::cout<<"How many shells do you want to load?: ";
    std::cin>>shells;
    if(shells>0&&shells<=(m_capacity-m_count)){
        for(int i=0;i<shells;i++){
            std::string shell;
            std::cout<<"Shell to load (slug, lb (large-bearing), sb (small-bearing): ";
            std::cin>>shell;
            if(shell=="slug"||shell=="lb"||shell=="sb"){
                m_mag.push(shell);
                m_count=m_count+1;
                std::cout<<"Shells: "<<m_count<<"/"<<m_capacity<<std::endl;
            }else{
                std::cout<<"Not a valid shell type: slug, lb, or sb"<<std::endl;
                return;
            }
        }
    }else{
        std::cout<<"Not valid space avaliable: 1-"<<(m_capacity-m_count)<<std::endl;
        return;
    }
}

//fire, removes a round from the magazine and returns it
std::string ShotBlaster::fire(){
    if(m_heat<100){
        std::string shell=m_mag.top();
        m_mag.pop();
        m_count=m_count-1;
        return shell;
    }
    return "!!!";
}

void ShotBlaster::change_range(){
    int range;
    std::cout<<"Distance (0-100): ";
    std::cin>>range;
    if(range<=100&&range>=0){
        m_range=range;
    }else{
        std::cout<<"Not a valid valid distance: 0-100"<<std::endl;
        return;
    }
}

void ShotBlaster::cool(){
    int cooling=(rand() % (70 - 35 + 1)) + 35;
    if((m_heat-cooling)>=0){
        m_heat=m_heat-cooling;
        std::cout<<"Shot-blaster heat: "<<m_heat<<std::endl;
    }else{
        m_heat=0;
        std::cout<<"Shot-blaster heat: "<<m_heat<<std::endl;
    }
}
