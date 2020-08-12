#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

void TriggerLateStudy::InitHist()
{
    h_mass = new TH1D("h_mass",";M^{L1}_{#mu#mu} [GeV];Events",45,0,15);
    h_L1pt = new TH2D("h_L1pt",";p^{offline}_{T};p^{offline}_{T}",21,0,21,21,0,21);
    h_late = new TH1D("h_late",";;Events",6,0,6);
    h_range = new TH1D("h_range",";;Events",16,0,16);
    h_dR = new TH1D("h_dR",";#DeltaR;Events",50,0,3);
}

void TriggerLateStudy::End()
{
    if(h_mass!=0){delete h_mass;}
    if(h_L1pt!=0){delete h_L1pt;}
    if(h_late!=0){delete h_late;}
    if(h_range!=0){delete h_range;}
    if(h_dR!=0){delete h_dR;}
}
