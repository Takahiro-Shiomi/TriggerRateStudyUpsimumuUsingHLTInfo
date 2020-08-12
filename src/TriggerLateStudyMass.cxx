#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "map"
#include "TVector2.h"

using namespace std;

void TriggerLateStudy::Mass()
{
    int candidate = RoI_pt.size();
    bool signal[16]; for(int i=0; i!=16; i++){signal[i]=false;}

    for(int i=0;i!=candidate;i++){
        for(int j=i+1;j!=candidate;j++){

            bool sign = false;
            if(RoI_source.at(i)!=0 && RoI_source.at(j)!=0){
                if(RoI_charge.at(i) == RoI_charge.at(j)){ sign=true; }
            }
            if(sign) continue;

            float eta_cal = cosh(RoI_eta.at(i) - RoI_eta.at(j));
            float phi_cal = cos(RoI_phi.at(i) - RoI_phi.at(j));
            float mass = 2*RoI_pt.at(i)*RoI_pt.at(j)*(eta_cal - phi_cal);
            float deta =abs(RoI_eta.at(i) - RoI_eta.at(j));
            float dphi=TVector2::Phi_mpi_pi(RoI_phi.at(i) - RoI_phi.at(j));
            float dR=sqrt(deta*deta + dphi*dphi);

            if(dR<=1.5){
                for(int k=0; k!=16; k++){
                    if(sqrt(mass)>=(1.5-(k/10)) && sqrt(mass)<=(7+(k/10))){
                        signal[k]= true;
                    }
                }
                if(sqrt(mass)>=1.5 && sqrt(mass)<=7){
                    h_mass->Fill(sqrt(mass));
                    h_L1pt->Fill(RoI_pt.at(i), RoI_pt.at(j));
                    h_dR->Fill(dR);
                }
            }
        }
    }
    if(signal[0]){h_late->Fill(3);}
    for(int i=0;i!=16;i++){
        if(signal[i]){
            h_range->Fill(i);
        }
    }
}
