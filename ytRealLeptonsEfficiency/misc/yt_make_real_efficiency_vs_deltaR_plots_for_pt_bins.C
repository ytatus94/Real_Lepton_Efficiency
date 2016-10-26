#include <TROOT.h>
#include <TFile.h>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>

#include <iostream>
using namespace std;

void yt_make_real_efficiency_vs_deltaR_plots_for_pt_bins(float pt_low = 10., float pt_up = 200.)
{
    TString path = "~/Desktop/skim/Results/1015/";

    TFile *data_elec   = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon   = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");

    TFile *Zee_TandP   = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");

    TFile *Zee_truth   = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
    TFile *Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");

    TFile *ttbar_elec  = TFile::Open(path + "submitDir_MC_ttbar_electron/hist-0929_80mll100.root");
    TFile *ttbar_muon  = TFile::Open(path + "submitDir_MC_ttbar_muon/hist-0929_80mll100.root");

    TFile *Gtt_elec    = TFile::Open(path + "submitDir_MC_GG_ttn1_electron/hist-0929_80mll100.root");
    TFile *Gtt_muon    = TFile::Open(path + "submitDir_MC_GG_ttn1_muon/hist-0929_80mll100.root");


    // Get 3 dim histograms
    TH3F *h_elec_baseline_pt_dRjet_mll = (TH3F *)data_elec->Get("h_baseline_pt_dRjet_mll");
/*
    TH1F *hb1 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet")->Clone();
    for (int i = 0; i <= hb1->GetXaxis()->GetNbins() + 1; i++) {
        cout << hb1->GetBinContent(i) << ", ";
    }
    cout << endl;
    TH1F *hb2 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 0, -1)->Clone();
    for (int i = 0; i <= hb2->GetXaxis()->GetNbins() + 1; i++) {
        cout << hb2->GetBinContent(i) << ", ";
    }
    cout << endl;
    TH1F *hb3 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 1, 14)->Clone();
    for (int i = 0; i <= hb3->GetXaxis()->GetNbins() + 1; i++) {
        cout << hb3->GetBinContent(i) << ", ";
    }
    cout << endl;
*/


    TH3F *h_elec_signal_pt_dRjet_mll = (TH3F *)data_elec->Get("h_signal_pt_dRjet_mll");
    h_elec_baseline_pt_dRjet_mll->Sumw2();
    h_elec_signal_pt_dRjet_mll->Sumw2();
/*
    TH1F *hb1 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet")->Clone();
    TH1F *hs1 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet")->Clone();
    hb1->SetLineColor(1);
    hb1->Draw();

    TH1F *he1 = (TH1F *)hs1->Clone();
    he1->Reset();
    he1->Divide(hs1, hb1, 1, 1, "B");
    he1->SetLineColor(kBlack);
    //he1->Draw();
    for (int i = 1; i <= he1->GetXaxis()->GetNbins(); i++) {
        cout << he1->GetBinContent(i) << ", ";
    }
    cout << endl;

    TH1F *hb2 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 0, -1);
    TH1F *hs2 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 0, -1);


    TH1F *he2 = (TH1F *)hs2->Clone();
    he2->Reset();
    he2->Divide(hs2, hb2, 1, 1, "B");
    he2->SetLineColor(kRed);
    //he2->Draw("same");
    for (int i = 1; i <= he2->GetXaxis()->GetNbins(); i++) {
        cout << he2->GetBinContent(i) << ", ";
    }
    cout << endl;

    TH1F *hb3 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 1, 13);
    TH1F *hs3 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 1, 13);

    TH1F *he3 = (TH1F *)hs3->Clone();
    he3->Reset();
    he3->Divide(hs3, hb3, 1, 1, "B");
    he3->SetLineColor(kBlue);
    //he3->Draw("same");
    for (int i = 1; i <= he3->GetXaxis()->GetNbins(); i++) {
        cout << he3->GetBinContent(i) << ", ";
    }
    cout << endl;

    TH1F *hbadd1 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 1, 1);
    TH1F *hbadd2 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 2, 2);
    TH1F *hbadd3 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 3, 3);
    TH1F *hbadd4 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 4, 4);
    TH1F *hbadd5 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 5, 5);
    TH1F *hbadd6 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 6, 6);
    TH1F *hbadd7 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 7, 7);
    TH1F *hbadd8 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 8, 8);
    TH1F *hbadd9 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 9, 9);
    TH1F *hbadd10 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 10, 10);
    TH1F *hbadd11 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 11, 11);
    TH1F *hbadd12 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 12, 12);
    TH1F *hbadd13 = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", 13, 13);
    TH1F *hbadd = (TH1F *)hbadd1->Clone();
    hbadd->Add(hbadd2); 
    hbadd->Add(hbadd3); 
    hbadd->Add(hbadd4); 
    hbadd->Add(hbadd5); 
    hbadd->Add(hbadd6); 
    hbadd->Add(hbadd7); 
    hbadd->Add(hbadd8); 
    hbadd->Add(hbadd9); 
    hbadd->Add(hbadd10);
    hbadd->Add(hbadd11);
    hbadd->Add(hbadd12);
    hbadd->Add(hbadd13);
    hb1->SetLineColor(kBlack);
    hb1->Draw();
    hb2->SetLineColor(2);
    //hb2->Draw("same");
    hb3->SetLineColor(3);
    //hb3->Draw("same");
    hbadd->SetLineColor(4);
    //hbadd->Draw("same");



    TH1F *hsadd1 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 1, 1);
    TH1F *hsadd2 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 2, 2);
    TH1F *hsadd3 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 3, 3);
    TH1F *hsadd4 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 4, 4);
    TH1F *hsadd5 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 5, 5);
    TH1F *hsadd6 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 6, 6);
    TH1F *hsadd7 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 7, 7);
    TH1F *hsadd8 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 8, 8);
    TH1F *hsadd9 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 9, 9);
    TH1F *hsadd10 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 10, 10);
    TH1F *hsadd11 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 11, 11);
    TH1F *hsadd12 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 12, 12);
    TH1F *hsadd13 = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", 13, 13);
    TH1F *hsadd = (TH1F *)hsadd1->Clone();
    hsadd->Add(hsadd2);
    hsadd->Add(hsadd3);
    hsadd->Add(hsadd4);
    hsadd->Add(hsadd5);
    hsadd->Add(hsadd6);
    hsadd->Add(hsadd7);
    hsadd->Add(hsadd8);
    hsadd->Add(hsadd9);
    hsadd->Add(hsadd10);
    hsadd->Add(hsadd11);
    hsadd->Add(hsadd12);
    hsadd->Add(hsadd13);

    TH1F *headd = (TH1F *)hsadd->Clone();
    headd->Reset();
    headd->Divide(hsadd, hbadd, 1, 1, "B");
    //headd->SetLineColor(kGreen);
    //headd->Draw();
    for (int i = 1; i <= headd->GetXaxis()->GetNbins(); i++) {
        cout << headd->GetBinContent(i) << ", ";
    }
    cout << endl;
*/

/*
    //int pt_bin_low = h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_low + 0.01);
    //int pt_bin_up = h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_up - 0.01);
    cout << h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_low + 0.01) << endl;
    cout << h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_up - 0.01) << endl;;
    int pt_bin_low = 1; //0;
    int pt_bin_up = 13; //-1;

    TH1F *h_elec_baseline_dRjet = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_elec_signal_dRjet = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_elec_eff_dRjet = (TH1F *)h_elec_signal_dRjet->Clone();
    h_elec_eff_dRjet->Divide(h_elec_baseline_dRjet);
    h_elec_eff_dRjet->Draw();

    TH3F *h_muon_baseline_pt_dRjet_mll = (TH3F *)data_muon->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_muon_signal_pt_dRjet_mll = (TH3F *)data_muon->Get("h_signal_pt_dRjet_mll");
    h_muon_baseline_pt_dRjet_mll->Sumw2();
    h_muon_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_muon_baseline_dRjet = (TH1F *)h_muon_baseline_pt_dRjet_mll->ProjectionY("h_muon_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_muon_signal_dRjet = (TH1F *)h_muon_signal_pt_dRjet_mll->ProjectionY("h_muon_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_muon_eff_dRjet = (TH1F *)h_muon_signal_dRjet->Clone();
    h_muon_eff_dRjet->Divide(h_muon_baseline_dRjet);

    TH3F *h_Zee_baseline_pt_dRjet_mll = (TH3F *)Zee_TandP->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Zee_signal_pt_dRjet_mll = (TH3F *)Zee_TandP->Get("h_signal_pt_dRjet_mll");
    h_Zee_baseline_pt_dRjet_mll->Sumw2();
    h_Zee_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Zee_baseline_dRjet = (TH1F *)h_Zee_baseline_pt_dRjet_mll->ProjectionY("h_Zee_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_signal_dRjet = (TH1F *)h_Zee_signal_pt_dRjet_mll->ProjectionY("h_Zee_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_eff_dRjet = (TH1F *)h_Zee_signal_dRjet->Clone();
    h_Zee_eff_dRjet->Divide(h_Zee_baseline_dRjet);

    TH3F *h_Zmumu_baseline_pt_dRjet_mll = (TH3F *)Zmumu_TandP->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Zmumu_signal_pt_dRjet_mll = (TH3F *)Zmumu_TandP->Get("h_signal_pt_dRjet_mll");
    h_Zmumu_baseline_pt_dRjet_mll->Sumw2();
    h_Zmumu_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Zmumu_baseline_dRjet = (TH1F *)h_Zmumu_baseline_pt_dRjet_mll->ProjectionY("h_Zmumu_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_signal_dRjet = (TH1F *)h_Zmumu_signal_pt_dRjet_mll->ProjectionY("h_Zmumu_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_eff_dRjet = (TH1F *)h_Zmumu_signal_dRjet->Clone();
    h_Zmumu_eff_dRjet->Divide(h_Zmumu_baseline_dRjet);

    TH3F *h_Zee_truth_baseline_pt_dRjet_mll = (TH3F *)Zee_truth->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Zee_truth_signal_pt_dRjet_mll = (TH3F *)Zee_truth->Get("h_signal_pt_dRjet_mll");
    h_Zee_truth_baseline_pt_dRjet_mll->Sumw2();
    h_Zee_truth_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Zee_truth_baseline_dRjet = (TH1F *)h_Zee_truth_baseline_pt_dRjet_mll->ProjectionY("h_Zee_truth_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_truth_signal_dRjet = (TH1F *)h_Zee_truth_signal_pt_dRjet_mll->ProjectionY("h_Zee_truth_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_truth_eff_dRjet = (TH1F *)h_Zee_truth_signal_dRjet->Clone();
    h_Zee_truth_eff_dRjet->Divide(h_Zee_truth_baseline_dRjet);

    TH3F *h_Zmumu_truth_baseline_pt_dRjet_mll = (TH3F *)Zmumu_truth->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Zmumu_truth_signal_pt_dRjet_mll = (TH3F *)Zmumu_truth->Get("h_signal_pt_dRjet_mll");
    h_Zmumu_truth_baseline_pt_dRjet_mll->Sumw2();
    h_Zmumu_truth_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Zmumu_truth_baseline_dRjet = (TH1F *)h_Zmumu_truth_baseline_pt_dRjet_mll->ProjectionY("h_Zmumu_truth_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_truth_signal_dRjet = (TH1F *)h_Zmumu_truth_signal_pt_dRjet_mll->ProjectionY("h_Zmumu_truth_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_truth_eff_dRjet = (TH1F *)h_Zmumu_truth_signal_dRjet->Clone();
    h_Zmumu_truth_eff_dRjet->Divide(h_Zmumu_truth_baseline_dRjet);

    TH3F *h_ttbar_elec_baseline_pt_dRjet_mll = (TH3F *)ttbar_elec->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_ttbar_elec_signal_pt_dRjet_mll = (TH3F *)ttbar_elec->Get("h_signal_pt_dRjet_mll");
    h_ttbar_elec_baseline_pt_dRjet_mll->Sumw2();
    h_ttbar_elec_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_ttbar_elec_baseline_dRjet = (TH1F *)h_ttbar_elec_baseline_pt_dRjet_mll->ProjectionY("h_ttbar_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_elec_signal_dRjet = (TH1F *)h_ttbar_elec_signal_pt_dRjet_mll->ProjectionY("h_ttbar_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_elec_eff_dRjet = (TH1F *)h_ttbar_elec_signal_dRjet->Clone();
    h_ttbar_elec_eff_dRjet->Divide(h_ttbar_elec_baseline_dRjet);

    TH3F *h_ttbar_muon_baseline_pt_dRjet_mll = (TH3F *)ttbar_muon->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_ttbar_muon_signal_pt_dRjet_mll = (TH3F *)ttbar_muon->Get("h_signal_pt_dRjet_mll");
    h_ttbar_muon_baseline_pt_dRjet_mll->Sumw2();
    h_ttbar_muon_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_ttbar_muon_baseline_dRjet = (TH1F *)h_ttbar_muon_baseline_pt_dRjet_mll->ProjectionY("h_ttbar_muon_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_muon_signal_dRjet = (TH1F *)h_ttbar_muon_signal_pt_dRjet_mll->ProjectionY("h_ttbar_muon_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_muon_eff_dRjet = (TH1F *)h_ttbar_muon_signal_dRjet->Clone();
    h_ttbar_muon_eff_dRjet->Divide(h_ttbar_muon_baseline_dRjet);

    TH3F *h_Gtt_elec_baseline_pt_dRjet_mll = (TH3F *)Gtt_elec->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Gtt_elec_signal_pt_dRjet_mll = (TH3F *)Gtt_elec->Get("h_signal_pt_dRjet_mll");
    h_Gtt_elec_baseline_pt_dRjet_mll->Sumw2();
    h_Gtt_elec_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Gtt_elec_baseline_dRjet = (TH1F *)h_Gtt_elec_baseline_pt_dRjet_mll->ProjectionY("h_Gtt_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_elec_signal_dRjet = (TH1F *)h_Gtt_elec_signal_pt_dRjet_mll->ProjectionY("h_Gtt_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_elec_eff_dRjet = (TH1F *)h_Gtt_elec_signal_dRjet->Clone();
    h_Gtt_elec_eff_dRjet->Divide(h_Gtt_elec_baseline_dRjet);

    TH3F *h_Gtt_muon_baseline_pt_dRjet_mll = (TH3F *)Gtt_muon->Get("h_baseline_pt_dRjet_mll");
    TH3F *h_Gtt_muon_signal_pt_dRjet_mll = (TH3F *)Gtt_muon->Get("h_signal_pt_dRjet_mll");
    h_Gtt_muon_baseline_pt_dRjet_mll->Sumw2();
    h_Gtt_muon_signal_pt_dRjet_mll->Sumw2();
    TH1F *h_Gtt_muon_baseline_dRjet = (TH1F *)h_Gtt_muon_baseline_pt_dRjet_mll->ProjectionY("h_Gtt_muon_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_muon_signal_dRjet = (TH1F *)h_Gtt_muon_signal_pt_dRjet_mll->ProjectionY("h_Gtt_muon_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_muon_eff_dRjet = (TH1F *)h_Gtt_muon_signal_dRjet->Clone();
    h_Gtt_muon_eff_dRjet->Divide(h_Gtt_muon_baseline_dRjet);
    
    */
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    
        
    
    
/*
    int pt_bin_low = h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_low + 0.01);
    int pt_bin_up = h_elec_baseline_pt_dRjet_mll->GetXaxis()->FindBin(pt_up - 0.01);

    TH3F *h_elec_eff_pt_dRjet_mll = (TH3F *)h_elec_signal_pt_dRjet_mll->Clone();
    TH3F *h_muon_eff_pt_dRjet_mll = (TH3F *)h_muon_signal_pt_dRjet_mll->Clone();
    TH3F *h_Zee_eff_pt_dRjet_mll = (TH3F *)h_Zee_signal_pt_dRjet_mll->Clone();
    TH3F *h_Zmumu_eff_pt_dRjet_mll = (TH3F *)h_Zmumu_signal_pt_dRjet_mll->Clone();
    TH3F *h_Zee_truth_eff_pt_dRjet_mll = (TH3F *)h_Zee_truth_signal_pt_dRjet_mll->Clone();
    TH3F *h_Zmumu_truth_eff_pt_dRjet_mll = (TH3F *)h_Zmumu_truth_signal_pt_dRjet_mll->Clone();
    TH3F *h_ttbar_elec_eff_pt_dRjet_mll = (TH3F *)h_ttbar_elec_signal_pt_dRjet_mll->Clone();
    TH3F *h_ttbar_muon_eff_pt_dRjet_mll = (TH3F *)h_ttbar_muon_signal_pt_dRjet_mll->Clone();
    TH3F *h_Gtt_elec_eff_pt_dRjet_mll = (TH3F *)h_Gtt_elec_signal_pt_dRjet_mll->Clone();
    TH3F *h_Gtt_muon_eff_pt_dRjet_mll = (TH3F *)h_Gtt_muon_signal_pt_dRjet_mll->Clone();

    h_elec_eff_pt_dRjet_mll->Divide(h_elec_baseline_pt_dRjet_mll);
    h_muon_eff_pt_dRjet_mll->Divide(h_muon_baseline_pt_dRjet_mll);
    h_Zee_eff_pt_dRjet_mll->Divide(h_Zee_baseline_pt_dRjet_mll);
    h_Zmumu_eff_pt_dRjet_mll->Divide(h_Zmumu_baseline_pt_dRjet_mll);
    h_Zee_truth_eff_pt_dRjet_mll->Divide(h_Zee_truth_baseline_pt_dRjet_mll);
    h_Zmumu_truth_eff_pt_dRjet_mll->Divide(h_Zmumu_truth_baseline_pt_dRjet_mll);
    h_ttbar_elec_eff_pt_dRjet_mll->Divide(h_ttbar_elec_baseline_pt_dRjet_mll);
    h_ttbar_muon_eff_pt_dRjet_mll->Divide(h_ttbar_muon_baseline_pt_dRjet_mll);
    h_Gtt_elec_eff_pt_dRjet_mll->Divide(h_Gtt_elec_baseline_pt_dRjet_mll);
    h_Gtt_muon_eff_pt_dRjet_mll->Divide(h_Gtt_muon_baseline_pt_dRjet_mll);

    h_elec_eff_dRjet = h_elec_eff_pt_dRjet_mll->ProjectionY("h_elec_eff_dRjet");
    h_muon_eff_dRjet = h_muon_eff_pt_dRjet_mll->ProjectionY("h_muon_eff_dRjet");
    h_Zee_eff_dRjet = h_Zee_eff_pt_dRjet_mll->ProjectionY("h_Zee_eff_dRjet");
    h_Zmumu_eff_dRjet = h_Zmumu_eff_pt_dRjet_mll->ProjectionY("h_Zmumu_eff_dRjet");
    h_Zee_truth_eff_dRjet = h_Zee_truth_eff_pt_dRjet_mll->ProjectionY("h_Zee_truth_eff_dRjet");
    h_Zmumu_truth_eff_dRjet = h_Zmumu_truth_eff_pt_dRjet_mll->ProjectionY("h_Zmumu_truth_eff_dRjet");
    h_ttbar_elec_eff_dRjet = h_ttbar_elec_eff_pt_dRjet_mll->ProjectionY("h_ttbar_elec_eff_dRjet");
    h_ttbar_muon_eff_dRjet = h_ttbar_muon_eff_pt_dRjet_mll->ProjectionY("h_ttbar_muon_eff_dRjet");
    h_Gtt_elec_eff_dRjet = h_Gtt_elec_eff_pt_dRjet_mll->ProjectionY("h_Gtt_elec_eff_dRjet");
    h_Gtt_muon_eff_dRjet = h_Gtt_muon_eff_pt_dRjet_mll->ProjectionY("h_Gtt_muon_eff_dRjet");
*/
/*
    TH2F *h_elec_baseline_pt_dRjet = (TH2F *)data_elec->Get("h_baseline_pt_dRjet");
    TH2F *h_muon_baseline_pt_dRjet = (TH2F *)data_muon->Get("h_baseline_pt_dRjet");
    TH2F *h_Zee_baseline_pt_dRjet = (TH2F *)Zee_TandP->Get("h_baseline_pt_dRjet");
    TH2F *h_Zmumu_baseline_pt_dRjet = (TH2F *)Zmumu_TandP->Get("h_baseline_pt_dRjet");
    TH2F *h_Zee_truth_baseline_pt_dRjet = (TH2F *)Zee_truth->Get("h_baseline_pt_dRjet");
    TH2F *h_Zmumu_truth_baseline_pt_dRjet = (TH2F *)Zmumu_truth->Get("h_baseline_pt_dRjet");
    TH2F *h_ttbar_elec_baseline_pt_dRjet = (TH2F *)ttbar_elec->Get("h_baseline_pt_dRjet");
    TH2F *h_ttbar_muon_baseline_pt_dRjet = (TH2F *)ttbar_muon->Get("h_baseline_pt_dRjet");
    TH2F *h_Gtt_elec_baseline_pt_dRjet = (TH2F *)Gtt_elec->Get("h_baseline_pt_dRjet");
    TH2F *h_Gtt_muon_baseline_pt_dRjet = (TH2F *)Gtt_muon->Get("h_baseline_pt_dRjet");

    h_elec_baseline_pt_dRjet->Sumw2();
    h_muon_baseline_pt_dRjet->Sumw2();
    h_Zee_baseline_pt_dRjet->Sumw2();
    h_Zmumu_baseline_pt_dRjet->Sumw2();
    h_Zee_truth_baseline_pt_dRjet->Sumw2();
    h_Zmumu_truth_baseline_pt_dRjet->Sumw2();
    h_ttbar_elec_baseline_pt_dRjet->Sumw2();
    h_ttbar_muon_baseline_pt_dRjet->Sumw2();
    h_Gtt_elec_baseline_pt_dRjet->Sumw2();
    h_Gtt_muon_baseline_pt_dRjet->Sumw2();

    TH2F *h_elec_signal_pt_dRjet = (TH2F *)data_elec->Get("h_signal_pt_dRjet");
    TH2F *h_muon_signal_pt_dRjet = (TH2F *)data_muon->Get("h_signal_pt_dRjet");
    TH2F *h_Zee_signal_pt_dRjet = (TH2F *)Zee_TandP->Get("h_signal_pt_dRjet");
    TH2F *h_Zmumu_signal_pt_dRjet = (TH2F *)Zmumu_TandP->Get("h_signal_pt_dRjet");
    TH2F *h_Zee_truth_signal_pt_dRjet = (TH2F *)Zee_truth->Get("h_signal_pt_dRjet");
    TH2F *h_Zmumu_truth_signal_pt_dRjet = (TH2F *)Zmumu_truth->Get("h_signal_pt_dRjet");
    TH2F *h_ttbar_elec_signal_pt_dRjet = (TH2F *)ttbar_elec->Get("h_signal_pt_dRjet");
    TH2F *h_ttbar_muon_signal_pt_dRjet = (TH2F *)ttbar_muon->Get("h_signal_pt_dRjet");
    TH2F *h_Gtt_elec_signal_pt_dRjet = (TH2F *)Gtt_elec->Get("h_signal_pt_dRjet");
    TH2F *h_Gtt_muon_signal_pt_dRjet = (TH2F *)Gtt_muon->Get("h_signal_pt_dRjet");

    h_elec_signal_pt_dRjet->Sumw2();
    h_muon_signal_pt_dRjet->Sumw2();
    h_Zee_signal_pt_dRjet->Sumw2();
    h_Zmumu_signal_pt_dRjet->Sumw2();
    h_Zee_truth_signal_pt_dRjet->Sumw2();
    h_Zmumu_truth_signal_pt_dRjet->Sumw2();
    h_ttbar_elec_signal_pt_dRjet->Sumw2();
    h_ttbar_muon_signal_pt_dRjet->Sumw2();
    h_Gtt_elec_signal_pt_dRjet->Sumw2();
    h_Gtt_muon_signal_pt_dRjet->Sumw2();

    TH1F *h_elec_baseline_dRjet = (TH1F *)data_elec->Get("h_baseline_dRjet");
    TH1F *h_muon_baseline_dRjet = (TH1F *)data_muon->Get("h_baseline_dRjet");
    TH1F *h_Zee_baseline_dRjet = (TH1F *)Zee_TandP->Get("h_baseline_dRjet");
    TH1F *h_Zmumu_baseline_dRjet = (TH1F *)Zmumu_TandP->Get("h_baseline_dRjet");
    TH1F *h_Zee_truth_baseline_dRjet = (TH1F *)Zee_truth->Get("h_baseline_dRjet");
    TH1F *h_Zmumu_truth_baseline_dRjet = (TH1F *)Zmumu_truth->Get("h_baseline_dRjet");
    TH1F *h_ttbar_elec_baseline_dRjet = (TH1F *)ttbar_elec->Get("h_baseline_dRjet");
    TH1F *h_ttbar_muon_baseline_dRjet = (TH1F *)ttbar_muon->Get("h_baseline_dRjet");
    TH1F *h_Gtt_elec_baseline_dRjet = (TH1F *)Gtt_elec->Get("h_baseline_dRjet");
    TH1F *h_Gtt_muon_baseline_dRjet = (TH1F *)Gtt_muon->Get("h_baseline_dRjet");

    h_elec_baseline_dRjet->Sumw2();
    h_muon_baseline_dRjet->Sumw2();
    h_Zee_baseline_dRjet->Sumw2();
    h_Zmumu_baseline_dRjet->Sumw2();
    h_Zee_truth_baseline_dRjet->Sumw2();
    h_Zmumu_truth_baseline_dRjet->Sumw2();
    h_ttbar_elec_baseline_dRjet->Sumw2();
    h_ttbar_muon_baseline_dRjet->Sumw2();
    h_Gtt_elec_baseline_dRjet->Sumw2();
    h_Gtt_muon_baseline_dRjet->Sumw2();

    TH1F *h_elec_signal_dRjet = (TH1F *)data_elec->Get("h_signal_dRjet");
    TH1F *h_muon_signal_dRjet = (TH1F *)data_muon->Get("h_signal_dRjet");
    TH1F *h_Zee_signal_dRjet = (TH1F *)Zee_TandP->Get("h_signal_dRjet");
    TH1F *h_Zmumu_signal_dRjet = (TH1F *)Zmumu_TandP->Get("h_signal_dRjet");
    TH1F *h_Zee_truth_signal_dRjet = (TH1F *)Zee_truth->Get("h_signal_dRjet");
    TH1F *h_Zmumu_truth_signal_dRjet = (TH1F *)Zmumu_truth->Get("h_signal_dRjet");
    TH1F *h_ttbar_elec_signal_dRjet = (TH1F *)ttbar_elec->Get("h_signal_dRjet");
    TH1F *h_ttbar_muon_signal_dRjet = (TH1F *)ttbar_muon->Get("h_signal_dRjet");
    TH1F *h_Gtt_elec_signal_dRjet = (TH1F *)Gtt_elec->Get("h_signal_dRjet");
    TH1F *h_Gtt_muon_signal_dRjet = (TH1F *)Gtt_muon->Get("h_signal_dRjet");

    h_elec_signal_dRjet->Sumw2();
    h_muon_signal_dRjet->Sumw2();
    h_Zee_signal_dRjet->Sumw2();
    h_Zmumu_signal_dRjet->Sumw2();
    h_Zee_truth_signal_dRjet->Sumw2();
    h_Zmumu_truth_signal_dRjet->Sumw2();
    h_ttbar_elec_signal_dRjet->Sumw2();
    h_ttbar_muon_signal_dRjet->Sumw2();
    h_Gtt_elec_signal_dRjet->Sumw2();
    h_Gtt_muon_signal_dRjet->Sumw2();
*/




/*
    TH1F *h_elec_baseline_dRjet = (TH1F *)h_elec_baseline_pt_dRjet_mll->ProjectionY("h_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_muon_baseline_dRjet = (TH1F *)h_muon_baseline_pt_dRjet_mll->ProjectionY("h_muon_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_baseline_dRjet = (TH1F *)h_Zee_baseline_pt_dRjet_mll->ProjectionY("h_Zee_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_baseline_dRjet = (TH1F *)h_Zmumu_baseline_pt_dRjet_mll->ProjectionY("h_Zmumu_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_truth_baseline_dRjet = (TH1F *)h_Zee_truth_baseline_pt_dRjet_mll->ProjectionY("h_Zee_truth_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_truth_baseline_dRjet = (TH1F *)h_Zmumu_truth_baseline_pt_dRjet_mll->ProjectionY("h_Zmumu_truth_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_elec_baseline_dRjet = (TH1F *)h_ttbar_elec_baseline_pt_dRjet_mll->ProjectionY("h_ttbar_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_muon_baseline_dRjet = (TH1F *)h_ttbar_muon_baseline_pt_dRjet_mll->ProjectionY("h_ttbar_muon_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_elec_baseline_dRjet = (TH1F *)h_Gtt_elec_baseline_pt_dRjet_mll->ProjectionY("h_Gtt_elec_baseline_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_muon_baseline_dRjet = (TH1F *)h_Gtt_muon_baseline_pt_dRjet_mll->ProjectionY("h_Gtt_muon_baseline_dRjet", pt_bin_low, pt_bin_up);

    TH1F *h_elec_signal_dRjet = (TH1F *)h_elec_signal_pt_dRjet_mll->ProjectionY("h_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_muon_signal_dRjet = (TH1F *)h_muon_signal_pt_dRjet_mll->ProjectionY("h_muon_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_signal_dRjet = (TH1F *)h_Zee_signal_pt_dRjet_mll->ProjectionY("h_Zee_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_signal_dRjet = (TH1F *)h_Zmumu_signal_pt_dRjet_mll->ProjectionY("h_Zmumu_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zee_truth_signal_dRjet = (TH1F *)h_Zee_truth_signal_pt_dRjet_mll->ProjectionY("h_Zee_truth_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Zmumu_truth_signal_dRjet = (TH1F *)h_Zmumu_truth_signal_pt_dRjet_mll->ProjectionY("h_Zmumu_truth_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_elec_signal_dRjet = (TH1F *)h_ttbar_elec_signal_pt_dRjet_mll->ProjectionY("h_ttbar_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_ttbar_muon_signal_dRjet = (TH1F *)h_ttbar_muon_signal_pt_dRjet_mll->ProjectionY("h_ttbar_muon_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_elec_signal_dRjet = (TH1F *)h_Gtt_elec_signal_pt_dRjet_mll->ProjectionY("h_Gtt_elec_signal_dRjet", pt_bin_low, pt_bin_up);
    TH1F *h_Gtt_muon_signal_dRjet = (TH1F *)h_Gtt_muon_signal_pt_dRjet_mll->ProjectionY("h_Gtt_muon_signal_dRjet", pt_bin_low, pt_bin_up);

    h_elec_baseline_dRjet->Divide(h_elec_signal_dRjet);
    h_muon_baseline_dRjet->Divide(h_muon_signal_dRjet);
    h_Zee_baseline_dRjet->Divide(h_Zee_signal_dRjet);
    h_Zmumu_baseline_dRjet->Divide(h_Zmumu_signal_dRjet);
    h_Zee_truth_baseline_dRjet->Divide(h_Zee_truth_signal_dRjet);
    h_Zmumu_truth_baseline_dRjet->Divide(h_Zmumu_truth_signal_dRjet);
    h_ttbar_elec_baseline_dRjet->Divide(h_ttbar_elec_signal_dRjet);
    h_ttbar_muon_baseline_dRjet->Divide(h_ttbar_muon_signal_dRjet);
    h_Gtt_elec_baseline_dRjet->Divide(h_Gtt_elec_signal_dRjet);
    h_Gtt_muon_baseline_dRjet->Divide(h_Gtt_muon_signal_dRjet);
*/
/*
    TCanvas *ee_eff_dRjet = new TCanvas("ee_eff_dRjet", "Real electron efficiency vs deltaR", 600, 600);
    gStyle->SetOptStat(0);

    h_elec_eff_dRjet->SetMarkerColor(kBlack);
    h_elec_eff_dRjet->SetMarkerStyle(kFullCircle);
    h_elec_eff_dRjet->SetLineColor(kBlack);
    h_elec_eff_dRjet->SetMaximum(1.4);
    h_elec_eff_dRjet->SetMinimum(0);
    h_elec_eff_dRjet->SetTitle("");
    h_elec_eff_dRjet->SetXTitle("#Delta R(e, jet)");
    h_elec_eff_dRjet->SetYTitle("Real electron efficiency");
    h_elec_eff_dRjet->SetStats(kFALSE);
    h_elec_eff_dRjet->Draw();

    h_Zee_eff_dRjet->SetMarkerColor(kRed);
    h_Zee_eff_dRjet->SetMarkerStyle(kFullSquare);
    h_Zee_eff_dRjet->SetLineColor(kRed);
    h_Zee_eff_dRjet->Draw("same");

    h_Zee_truth_eff_dRjet->SetMarkerColor(kBlue);
    h_Zee_truth_eff_dRjet->SetMarkerStyle(kFullTriangleUp);
    h_Zee_truth_eff_dRjet->SetLineColor(kBlue);
    h_Zee_truth_eff_dRjet->Draw("same");

    h_ttbar_elec_eff_dRjet->SetMarkerColor(kMagenta);
    h_ttbar_elec_eff_dRjet->SetMarkerStyle(kFullDiamond);
    h_ttbar_elec_eff_dRjet->SetLineColor(kMagenta);
    h_ttbar_elec_eff_dRjet->Draw("same");

    h_Gtt_elec_eff_dRjet->SetMarkerColor(kOrange);
    h_Gtt_elec_eff_dRjet->SetMarkerStyle(kFullCross);
    h_Gtt_elec_eff_dRjet->SetLineColor(kOrange);
    h_Gtt_elec_eff_dRjet->Draw("same");
   
    TLegend *leg1 = new TLegend(0.2, 0.6, 0.7, 0.89);
    leg1->SetBorderSize(0);
    leg1->SetFillColor(0);
    leg1->AddEntry("h_elec_eff_dRjet", "Data");
    leg1->AddEntry("h_Zee_eff_dRjet", "Z #rightarrow ee T&P MC");
    leg1->AddEntry("h_Zee_truth_eff_dRjet", "Z #rightarrow ee truth matched MC");
    leg1->AddEntry("h_ttbar_elec_eff_dRjet", "ttbar MC");
    leg1->AddEntry("h_Gtt_elec_eff_dRjet", "Gtt MC");
    leg1->Draw();
*/
}
