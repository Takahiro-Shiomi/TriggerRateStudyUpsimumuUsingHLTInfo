#include "../include/TriggerLateStudy.h"
#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "THStack.h"
#include "TLegend.h"
#include "TGraphErrors.h"

using namespace std;

void TriggerLateStudy::Draw(TString pdf)
{
    TCanvas_opt *c1 = new TCanvas_opt();
    gStyle->SetOptStat(0);
    c1->SetTopMargin(0.20);
    c1->Print(pdf + "[", "pdf");

    h_L1pt->Draw("COL");
    c1->Print(pdf,"pdf");

    c1->Clear();

    h_mass->Draw();
    h_mass->SetLineColor(kOrange);
    h_mass->SetFillColor(kOrange);
    h_mass->SetFillStyle(3015);
    c1->Print(pdf,"pdf");

    h_late->Draw("hist text");
    h_late->SetLineColor(kOrange);
    c1->Print(pdf,"pdf");

    h_dR->Draw();
    h_dR->SetLineColor(kOrange);
    h_dR->SetFillColor(kOrange);
    h_dR->SetFillStyle(3015);
    c1->Print(pdf,"pdf");

    c1->Clear();

    double L12MU4 = h_mass->GetBinContent(1);
    double rate[16];
    double x[16];
    for(int i=0; i!=16; i++){
        rate[i] = 100*(double)(h_range->GetBinContent(i+1))/L12MU4;
        x[i] = (double)i/10;
    }
    TGraphErrors *tge = new TGraphErrors(16,x,rate,0,0);
    tge->Draw("apl");
    tge->SetMarkerColor(kAzure-4);
    tge->SetMarkerStyle(8);
    tge->SetLineColor(kAzure-4);
    tge->SetLineWidth(1);
    tge->SetLineStyle(7);
    tge -> Write();
    c1 -> Print( pdf , "pdf" );

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
