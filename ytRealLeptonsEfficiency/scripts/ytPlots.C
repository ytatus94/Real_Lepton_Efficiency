#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>

//#include "AtlasStyle/AtlasStyle.C"
//#include "AtlasStyle/AtlasLabels.C"
//#include "AtlasStyle/AtlasUtils.C"

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

//
// Mll plots
//

// Make baseline level and signal level mll plots or ratio plots for pt_bin_low < pt < pt_bin_up.
// Using pt_bin_low = 0 and pt_bin_up = -1 means the full pt range.
// Default overlap data, Tag and Probe, and truth match results.
// Set truth_match = true to turn on truth match on the plot.
void yt_mll_plots()
{
    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");

    TH3F *data_elec_baseline_pt_eta_mll = (TH3F *)data_elec->Get("h_baseline_pt_eta_mll");
    TH3F *data_muon_baseline_pt_eta_mll = (TH3F *)data_muon->Get("h_baseline_pt_eta_mll");
    TH3F *data_elec_signal_pt_eta_mll = (TH3F *)data_elec->Get("h_signal_pt_eta_mll");
    TH3F *data_muon_signal_pt_eta_mll = (TH3F *)data_muon->Get("h_signal_pt_eta_mll");

    // Project all bins to Z axis
    TH1D *data_elec_baseline_mll = (TH1D *)data_elec_baseline_pt_eta_mll->ProjectionZ("data_elec_baseline_mll");
    TH1D *data_muon_baseline_mll = (TH1D *)data_muon_baseline_pt_eta_mll->ProjectionZ("data_muon_baseline_mll");
    TH1D *data_elec_signal_mll = (TH1D *)data_elec_signal_pt_eta_mll->ProjectionZ("data_elec_signal_mll");
    TH1D *data_muon_signal_mll = (TH1D *)data_muon_signal_pt_eta_mll->ProjectionZ("data_muon_signal_mll");

    double elec_max = max(data_elec_baseline_mll->GetMaximum(), data_elec_signal_mll->GetMaximum());
    double muon_max = max(data_muon_baseline_mll->GetMaximum(), data_muon_signal_mll->GetMaximum());

    // Create a dummy histogram in order to fill color between 80 < mll < 100
    TH1F *h_80_100 = new TH1F("h_80_100", "h_80_100", 1, 80, 100);
    h_80_100->SetFillColor(kYellow);
    h_80_100->SetFillColorAlpha(kYellow, 0.35);
    h_80_100->SetFillStyle(1001); // solid
    h_80_100->SetLineColor(kYellow);

    TCanvas *c_ee = new TCanvas("c_ee", "M_{ee}", 600, 600);
    c_ee->SetGrid();
    c_ee->SetLogy();

    data_elec_baseline_mll->SetTitle("");
    data_elec_baseline_mll->SetXTitle("M_{ee} [GeV]");
    data_elec_baseline_mll->SetYTitle("Events");
    data_elec_baseline_mll->SetStats(kFALSE);
    data_elec_baseline_mll->SetMaximum(elec_max * 10);
    data_elec_baseline_mll->SetMinimum(1000.);
    data_elec_baseline_mll->SetLineColor(kBlack);
    data_elec_baseline_mll->SetMarkerColor(kBlack);
    data_elec_baseline_mll->SetMarkerStyle(kFullCircle);
    data_elec_baseline_mll->Draw();

    data_elec_signal_mll->SetLineColor(kRed);
    data_elec_signal_mll->SetMarkerColor(kRed);
    data_elec_signal_mll->SetMarkerStyle(kFullTriangleUp);
    data_elec_signal_mll->Draw("same");

    h_80_100->Fill(90, elec_max * 10);
    h_80_100->Draw("hist,same");

    TLegend *leg_ee = new TLegend(0.6, 0.7, 0.85, 0.8);
    leg_ee->AddEntry(data_elec_baseline_mll, "Baseline", "p");
    leg_ee->AddEntry(data_elec_signal_mll, "Signal", "p");
    //leg_ee->SetBorderSize(0);
    //leg_ee->SetTextFont(42);
    //leg_ee->SetTextSize(0.05);
    //leg_ee->SetFillColor(0);
    //leg_ee->SetFillStyle(0);
    leg_ee->Draw("same");

    TCanvas *c_mumu = new TCanvas("c_mumu", "M_{#mu#mu}", 600, 600);
    c_mumu->SetGrid();
    c_mumu->SetLogy();

    data_muon_baseline_mll->SetTitle("");
    data_muon_baseline_mll->SetXTitle("M_{#mu#mu} [GeV]");
    data_muon_baseline_mll->SetYTitle("Events");
    data_muon_baseline_mll->SetStats(kFALSE);
    data_muon_baseline_mll->SetMaximum(muon_max * 10);
    data_muon_baseline_mll->SetMinimum(1000.);
    data_muon_baseline_mll->SetLineColor(kBlack);
    data_muon_baseline_mll->SetMarkerColor(kBlack);
    data_muon_baseline_mll->SetMarkerStyle(kFullCircle);
    data_muon_baseline_mll->Draw();

    data_muon_signal_mll->SetLineColor(kRed);
    data_muon_signal_mll->SetMarkerColor(kRed);
    data_muon_signal_mll->SetMarkerStyle(kFullTriangleUp);
    data_muon_signal_mll->Draw("same");

    h_80_100->Reset();
    h_80_100->Fill(90, muon_max * 10);
    h_80_100->Draw("hist,same");

    TLegend *leg_mumu = new TLegend(0.6, 0.7, 0.85, 0.8);
    leg_mumu->AddEntry(data_muon_baseline_mll, "Baseline", "p");
    leg_mumu->AddEntry(data_muon_signal_mll, "Signal", "p");
    //leg_mumu->SetBorderSize(0);
    //leg_mumu->SetTextFont(42);
    //leg_mumu->SetTextSize(0.05);
    //leg_mumu->SetFillColor(0);
    //leg_mumu->SetFillStyle(0);
    leg_mumu->Draw("same");
}

void yt_baseline_mll_plots(int pt_bin_low = 0, int pt_bin_up = -1, bool truth_match = false)
{
    // default pt bins are:
    // 10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200

    bool debug = false;

    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");
    TFile *Zee_TandP = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");

    TFile *Zee_truth;
    TFile *Zmumu_truth;
    if (truth_match) {
        Zee_truth = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
    }

    if (debug) {
        cout << data_elec << endl;
        cout << data_muon << endl;
        cout << Zee_TandP << endl;
        cout << Zmumu_TandP << endl;
        if (truth_match) {
            cout << Zee_truth << endl;
            cout << Zmumu_truth << endl;
        }
    }

    TH3F *data_elec_baseline_pt_eta_mll = (TH3F *)data_elec->Get("h_baseline_pt_eta_mll");
    TH3F *data_muon_baseline_pt_eta_mll = (TH3F *)data_muon->Get("h_baseline_pt_eta_mll");
    TH3F *Zee_TandP_baseline_pt_eta_mll = (TH3F *)Zee_TandP->Get("h_baseline_pt_eta_mll");
    TH3F *Zmumu_TandP_baseline_pt_eta_mll = (TH3F *)Zmumu_TandP->Get("h_baseline_pt_eta_mll");

    TH3F *Zee_truth_baseline_pt_eta_mll;
    TH3F *Zmumu_truth_baseline_pt_eta_mll;
    if (truth_match) {
        Zee_truth_baseline_pt_eta_mll = (TH3F *)Zee_truth->Get("h_baseline_pt_eta_mll");
        Zmumu_truth_baseline_pt_eta_mll = (TH3F *)Zmumu_truth->Get("h_baseline_pt_eta_mll");
    }
    if (debug) {
        cout << data_elec_baseline_pt_eta_mll << endl;
        cout << data_muon_baseline_pt_eta_mll << endl;
        cout << Zee_TandP_baseline_pt_eta_mll << endl;
        cout << Zmumu_TandP_baseline_pt_eta_mll << endl;
        if (truth_match) {
            cout << Zee_truth_baseline_pt_eta_mll << endl;
            cout << Zmumu_truth_baseline_pt_eta_mll << endl;
        }
    }

    TH1D *data_elec_mll = (TH1D *)data_elec_baseline_pt_eta_mll->ProjectionZ("data_elec_mll", pt_bin_low, pt_bin_up);
    TH1D *data_muon_mll = (TH1D *)data_muon_baseline_pt_eta_mll->ProjectionZ("data_muon_mll", pt_bin_low, pt_bin_up);
    TH1D *Zee_TandP_mll = (TH1D *)Zee_TandP_baseline_pt_eta_mll->ProjectionZ("Zee_TandP_mll", pt_bin_low, pt_bin_up);
    TH1D *Zmumu_TandP_mll = (TH1D *)Zmumu_TandP_baseline_pt_eta_mll->ProjectionZ("Zmumu_TandP_mll", pt_bin_low, pt_bin_up);

    TH1D *Zee_truth_mll;
    TH1D *Zmumu_truth_mll;
    if (truth_match) {
        Zee_truth_mll = (TH1D *)Zee_truth_baseline_pt_eta_mll->ProjectionZ("Zee_truth_mll", pt_bin_low, pt_bin_up);
        Zmumu_truth_mll = (TH1D *)Zmumu_truth_baseline_pt_eta_mll->ProjectionZ("Zmumu_truth_mll", pt_bin_low, pt_bin_up);
    }
    if (debug) {
        cout << data_elec_mll << endl;
        cout << data_muon_mll << endl;
        cout << Zee_TandP_mll << endl;
        cout << Zmumu_TandP_mll << endl;
        if (truth_match) {
            cout << Zee_truth_mll << endl;
            cout << Zmumu_truth_mll << endl;
        }
    }

    double pt_bin_low_value;
    double pt_bin_up_value;
    if (pt_bin_low != 0 && pt_bin_up != -1) {
        pt_bin_low_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinLowEdge(pt_bin_low);
        pt_bin_up_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinUpEdge(pt_bin_up);
    }
    else {
        pt_bin_low_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinLowEdge(1);
        int nbins = data_elec_baseline_pt_eta_mll->GetXaxis()->GetNbins();
        pt_bin_up_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinUpEdge(nbins - 1);
    }
    // Convert double to string using stringstream
    stringstream sstream_pt_low, sstream_pt_up;
    sstream_pt_low << pt_bin_low_value;
    sstream_pt_up << pt_bin_up_value;

    TCanvas *Mee_plot = new TCanvas("Mee_plot", "Baseline level M_{ee} plot", 500, 500);

    double data_elec_value = data_elec_mll->GetMaximum();
    double Zee_TandP_max_value = Zee_TandP_mll->GetMaximum();

    data_elec_mll->SetMarkerColor(kBlack);
    data_elec_mll->SetMarkerStyle(kFullCircle);
    data_elec_mll->SetLineColor(kBlack);
    data_elec_mll->SetTitle("");
    data_elec_mll->SetXTitle("M_{ee} [GeV]");
    data_elec_mll->SetYTitle("Events");
    data_elec_mll->SetMaximum(max(data_elec_value, Zee_TandP_max_value) * 1.05);
    data_elec_mll->SetMinimum(0.);
    data_elec_mll->SetStats(kFALSE);
    data_elec_mll->Draw();
    //Zee_TandP_mll->SetMarkerColor(kRed);
    //Zee_TandP_mll->SetMarkerStyle(kFullSquare);
    Zee_TandP_mll->SetLineColor(kRed);
    Zee_TandP_mll->SetFillColor(kRed);
    Zee_TandP_mll->SetFillStyle(3004);
    Zee_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zee_truth_mll->SetMarkerColor(kBlue);
        //Zee_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zee_truth_mll->SetLineColor(kBlue);
        Zee_truth_mll->SetFillColor(kBlue);
        Zee_truth_mll->SetFillStyle(3005);
        Zee_truth_mll->Draw("hist,same");
    }

    TLegend *leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg1->SetBorderSize(0);
    leg1->SetFillStyle(0);
    leg1->SetFillColor(0);
    leg1->AddEntry(data_elec_mll, "Data");
    leg1->AddEntry(Zee_TandP_mll, "Zee Tag and Probe", "f");

    if (truth_match) {
        leg1->AddEntry(Zee_truth_mll, "Zee truth match", "f");
    }

    leg1->Draw("same");

    TPaveText *text1 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text1->SetTextSize(0.03);
    text1->SetBorderSize(0);
    text1->SetFillStyle(0);
    text1->SetFillColor(0);
    text1->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text1->Draw("same");

    string filename1 = "baseline_level_Mee_pt" + sstream_pt_low.str() + sstream_pt_up.str() + ".pdf";
    Mee_plot->SaveAs(filename1.c_str(), "pdf");

    TCanvas *Mmumu_plot = new TCanvas("Mmumu_plot", "Baseline level M_{#mu#mu} plot", 500, 500);

    double data_muon_value = data_muon_mll->GetMaximum();
    double Zmumu_TandP_max_value = Zmumu_TandP_mll->GetMaximum();

    data_muon_mll->SetMarkerColor(kBlack);
    data_muon_mll->SetMarkerStyle(kFullCircle);
    data_muon_mll->SetLineColor(kBlack);
    data_muon_mll->SetTitle("");
    data_muon_mll->SetXTitle("M_{#mu#mu} [GeV]");
    data_muon_mll->SetYTitle("Events");
    data_muon_mll->SetMaximum(max(data_muon_value, Zmumu_TandP_max_value) * 1.05);
    data_muon_mll->SetMinimum(0.);
    data_muon_mll->SetStats(kFALSE);
    data_muon_mll->Draw();
    //Zmumu_TandP_mll->SetMarkerColor(kRed);
    //Zmumu_TandP_mll->SetMarkerStyle(kFullSquare);
    Zmumu_TandP_mll->SetLineColor(kRed);
    Zmumu_TandP_mll->SetFillColor(kRed);
    Zmumu_TandP_mll->SetFillStyle(3004);
    Zmumu_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zmumu_truth_mll->SetMarkerColor(kBlue);
        //Zmumu_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zmumu_truth_mll->SetLineColor(kBlue);
        Zmumu_truth_mll->SetFillColor(kBlue);
        Zmumu_truth_mll->SetFillStyle(3005);
        Zmumu_truth_mll->Draw("hist,same");
    }

    TLegend *leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg2->SetBorderSize(0);
    leg2->SetFillStyle(0);
    leg2->SetFillColor(0);
    leg2->AddEntry(data_muon_mll, "Data");
    leg2->AddEntry(Zmumu_TandP_mll, "Z#mu#mu Tag and Probe", "f");

    if (truth_match) {
        leg2->AddEntry(Zmumu_truth_mll, "Z#mu#mu truth match", "f");
    }

    leg2->Draw("same");

    TPaveText *text2 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text2->SetTextSize(0.03);
    text2->SetBorderSize(0);
    text2->SetFillStyle(0);
    text2->SetFillColor(0);
    text2->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text2->Draw("same");

    string filename2 = "baseline_level_Mmumu_pt" + sstream_pt_low.str() + sstream_pt_up.str() + ".pdf";
    Mmumu_plot->SaveAs(filename2.c_str(), "pdf");
}

void yt_baseline_mll_ratio_plots(int pt_bin_low = 0, int pt_bin_up = -1, bool truth_match = false, bool norm = false)
{
    // default pt bins are:
    // 10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200

    bool debug = false;

    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");
    TFile *Zee_TandP = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");

    TFile *Zee_truth;
    TFile *Zmumu_truth;
    if (truth_match) {
        Zee_truth = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
    }

    if (debug) {
        cout << data_elec << endl;
        cout << data_muon << endl;
        cout << Zee_TandP << endl;
        cout << Zmumu_TandP << endl;
        if (truth_match) {
            cout << Zee_truth << endl;
            cout << Zmumu_truth << endl;
        }
    }

    TH3F *data_elec_baseline_pt_eta_mll = (TH3F *)data_elec->Get("h_baseline_pt_eta_mll");
    TH3F *data_muon_baseline_pt_eta_mll = (TH3F *)data_muon->Get("h_baseline_pt_eta_mll");
    TH3F *Zee_TandP_baseline_pt_eta_mll = (TH3F *)Zee_TandP->Get("h_baseline_pt_eta_mll");
    TH3F *Zmumu_TandP_baseline_pt_eta_mll = (TH3F *)Zmumu_TandP->Get("h_baseline_pt_eta_mll");

    TH3F *Zee_truth_baseline_pt_eta_mll;
    TH3F *Zmumu_truth_baseline_pt_eta_mll;
    if (truth_match) {
        Zee_truth_baseline_pt_eta_mll = (TH3F *)Zee_truth->Get("h_baseline_pt_eta_mll");
        Zmumu_truth_baseline_pt_eta_mll = (TH3F *)Zmumu_truth->Get("h_baseline_pt_eta_mll");
    }
    if (debug) {
        cout << data_elec_baseline_pt_eta_mll << endl;
        cout << data_muon_baseline_pt_eta_mll << endl;
        cout << Zee_TandP_baseline_pt_eta_mll << endl;
        cout << Zmumu_TandP_baseline_pt_eta_mll << endl;
        if (truth_match) {
            cout << Zee_truth_baseline_pt_eta_mll << endl;
            cout << Zmumu_truth_baseline_pt_eta_mll << endl;
        }
    }

    TH1D *data_elec_mll = (TH1D *)data_elec_baseline_pt_eta_mll->ProjectionZ("data_elec_mll", pt_bin_low, pt_bin_up);
    TH1D *data_muon_mll = (TH1D *)data_muon_baseline_pt_eta_mll->ProjectionZ("data_muon_mll", pt_bin_low, pt_bin_up);
    TH1D *Zee_TandP_mll = (TH1D *)Zee_TandP_baseline_pt_eta_mll->ProjectionZ("Zee_TandP_mll", pt_bin_low, pt_bin_up);
    TH1D *Zmumu_TandP_mll = (TH1D *)Zmumu_TandP_baseline_pt_eta_mll->ProjectionZ("Zmumu_TandP_mll", pt_bin_low, pt_bin_up);

    TH1D *Zee_truth_mll;
    TH1D *Zmumu_truth_mll;
    if (truth_match) {
        Zee_truth_mll = (TH1D *)Zee_truth_baseline_pt_eta_mll->ProjectionZ("Zee_truth_mll", pt_bin_low, pt_bin_up);
        Zmumu_truth_mll = (TH1D *)Zmumu_truth_baseline_pt_eta_mll->ProjectionZ("Zmumu_truth_mll", pt_bin_low, pt_bin_up);
    }
    if (debug) {
        cout << data_elec_mll << endl;
        cout << data_muon_mll << endl;
        cout << Zee_TandP_mll << endl;
        cout << Zmumu_TandP_mll << endl;
        if (truth_match) {
            cout << Zee_truth_mll << endl;
            cout << Zmumu_truth_mll << endl;
        }
    }

    double pt_bin_low_value;
    double pt_bin_up_value;
    if (pt_bin_low != 0 && pt_bin_up != -1) {
        pt_bin_low_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinLowEdge(pt_bin_low);
        pt_bin_up_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinUpEdge(pt_bin_up);
    }
    else {
        pt_bin_low_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinLowEdge(1);
        int nbins = data_elec_baseline_pt_eta_mll->GetXaxis()->GetNbins();
        pt_bin_up_value = data_elec_baseline_pt_eta_mll->GetXaxis()->GetBinUpEdge(nbins - 1);
    }
    // Convert double to string using stringstream
    stringstream sstream_pt_low, sstream_pt_up;
    sstream_pt_low << pt_bin_low_value;
    sstream_pt_up << pt_bin_up_value;

    //
    // Normalize MC to data using a Gaussian fit of the Z peak (85 < mll < 95)
    //
    data_elec_mll->Fit("gaus", "0", "", 85, 95);
    TF1 *func_ee = data_elec_mll->GetFunction("gaus");
    //cout << func_ee->Integral(85., 95.) << endl;  // function integral uses values as arguments.
    //cout << data_elec_mll->Integral(data_elec_mll->GetXaxis()->FindBin(85. + 0.01), data_elec_mll->GetXaxis()->FindBin(95. - 0.01)) << endl; // histogram integral uses bins as argument.
    double data_elec_mll_peak_area = func_ee->Integral(85., 95.);

    data_muon_mll->Fit("gaus", "0", "", 85, 95);
    TF1 *func_mumu = data_muon_mll->GetFunction("gaus");
    //cout << func_mumu->Integral(85., 95.) << endl;  // function integral uses values as arguments.
    //cout << data_muon_mll->Integral(data_muon_mll->GetXaxis()->FindBin(85. + 0.01), data_muon_mll->GetXaxis()->FindBin(95. - 0.01)) << endl; // histogram integral uses bins as argument.
    double data_muon_mll_peak_area = func_mumu->Integral(85., 95.);

    if (norm) {
        double Zee_TandP_mll_peak_area = Zee_TandP_mll->Integral(Zee_TandP_mll->GetXaxis()->FindBin(85. + 0.01), Zee_TandP_mll->GetXaxis()->FindBin(95. - 0.01));
        double Zmumu_TandP_mll_peak_area = Zmumu_TandP_mll->Integral(Zmumu_TandP_mll->GetXaxis()->FindBin(85. + 0.01), Zmumu_TandP_mll->GetXaxis()->FindBin(95. - 0.01));
        Zee_TandP_mll->Scale(data_elec_mll_peak_area / Zee_TandP_mll_peak_area);
        Zmumu_TandP_mll->Scale(data_muon_mll_peak_area / Zmumu_TandP_mll_peak_area);
        if (truth_match) {
            double Zee_truth_mll_peak_area = Zee_truth_mll->Integral(Zee_truth_mll->GetXaxis()->FindBin(85. + 0.01), Zee_truth_mll->GetXaxis()->FindBin(95. - 0.01));
            double Zmumu_truth_mll_peak_area = Zmumu_truth_mll->Integral(Zmumu_truth_mll->GetXaxis()->FindBin(85. + 0.01), Zmumu_truth_mll->GetXaxis()->FindBin(95. - 0.01));
            Zee_truth_mll->Scale(data_elec_mll_peak_area / Zee_truth_mll_peak_area);
            Zmumu_truth_mll->Scale(data_muon_mll_peak_area / Zmumu_truth_mll_peak_area);
        }
    }

    //
    // For Mee
    //
    TCanvas *Mee_plot = new TCanvas("Mee_plot", "Baseline level M_{ee} ratio plot", 600, 600);

    //Upper plot will be in pad1
    TPad *pad1_Mee = new TPad("pad1_Mee", "pad1_Mee", 0, 0.35, 1, 1.0);
    pad1_Mee->SetBottomMargin(0); // Upper and lower plot are joined
    pad1_Mee->SetRightMargin(0.08);
    //pad1_Mee->SetGridy(); // grid lines
    //pad1_Mee->SetLogx();
    pad1_Mee->Draw();

    // lower plot will be in pad
    TPad *pad2_Mee = new TPad("pad2_Mee", "pad2_Mee", 0, 0.05, 1, 0.35);
    pad2_Mee->SetTopMargin(0);
    pad2_Mee->SetBottomMargin(0.3);
    pad2_Mee->SetRightMargin(0.08);
    pad2_Mee->SetGridy(); // grid lines
    //pad2_Mee->SetLogx();
    pad2_Mee->Draw();

    pad1_Mee->cd(); // pad1 becomes the current pad
    //pad1_Mee->SetFrameLineWidth(2);

    // Draw curve here

    double data_elec_value = data_elec_mll->GetMaximum();
    double Zee_TandP_max_value = Zee_TandP_mll->GetMaximum();

    data_elec_mll->SetMarkerColor(kBlack);
    data_elec_mll->SetMarkerStyle(kFullCircle);
    data_elec_mll->SetLineColor(kBlack);
    data_elec_mll->SetTitle("");
    data_elec_mll->SetYTitle("Events");
    data_elec_mll->SetMaximum(max(data_elec_value, Zee_TandP_max_value) * 1.05);
    data_elec_mll->SetMinimum(0.1);
    data_elec_mll->SetStats(kFALSE);
    data_elec_mll->Draw();
    //Zee_TandP_mll->SetMarkerColor(kRed);
    //Zee_TandP_mll->SetMarkerStyle(kFullSquare);
    Zee_TandP_mll->SetLineColor(kRed);
    Zee_TandP_mll->SetFillColor(kRed);
    Zee_TandP_mll->SetFillStyle(3004);
    Zee_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zee_truth_mll->SetMarkerColor(kBlue);
        //Zee_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zee_truth_mll->SetLineColor(kBlue);
        Zee_truth_mll->SetFillColor(kBlue);
        Zee_truth_mll->SetFillStyle(3005);
        Zee_truth_mll->Draw("hist,same");
    }

    TLegend *leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg1->AddEntry(data_elec_mll, "Data");
    leg1->AddEntry(Zee_TandP_mll, "Zee Tag and Probe", "f");

    if (truth_match) {
        leg1->AddEntry(Zee_truth_mll, "Zee truth match", "f");
    }

    leg1->SetBorderSize(0);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.05);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(0);
    leg1->Draw("same");

    TPaveText *text1 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text1->SetTextSize(0.05);
    text1->SetBorderSize(0);
    text1->SetFillStyle(0);
    text1->SetFillColor(0);
    text1->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text1->Draw("same");

    pad2_Mee->cd(); // pad2 becomes the current pad

    TH1F *frame_Mee = pad2_Mee->DrawFrame(60, 0.8, 150, 1.19);
    frame_Mee->GetXaxis()->SetNdivisions(510);
    frame_Mee->GetYaxis()->SetNdivisions(405);
    frame_Mee->SetLineWidth(1);
    frame_Mee->SetXTitle("M_{ll} [GeV]");
    frame_Mee->GetXaxis()->SetTitleSize(20);
    frame_Mee->GetXaxis()->SetTitleFont(47);
    frame_Mee->GetXaxis()->SetTitleOffset(3.0);
    frame_Mee->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mee->GetXaxis()->SetLabelSize(15);
    frame_Mee->SetYTitle("Data / MC");
    frame_Mee->GetYaxis()->SetTitleSize(17);
    frame_Mee->GetYaxis()->SetTitleFont(43);
    frame_Mee->GetYaxis()->SetTitleOffset(1.5);
    frame_Mee->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mee->GetYaxis()->SetLabelSize(16);
    frame_Mee->Draw();

    TH1F *ratio_Mee_TandP = (TH1F *)data_elec_mll->Clone();
    ratio_Mee_TandP->Sumw2();
    ratio_Mee_TandP->Divide(Zee_TandP_mll);
    ratio_Mee_TandP->SetMarkerColor(kRed);
    ratio_Mee_TandP->SetMarkerStyle(kFullTriangleUp);
    ratio_Mee_TandP->SetLineColor(kRed);
    ratio_Mee_TandP->Draw("same");

    if (truth_match) {
        TH1F *ratio_Mee_truth = (TH1F *)data_elec_mll->Clone();
        ratio_Mee_truth->Sumw2();
        ratio_Mee_truth->Divide(Zee_truth_mll);
        ratio_Mee_truth->SetMarkerColor(kBlue);
        ratio_Mee_truth->SetMarkerStyle(kFullTriangleDown);
        ratio_Mee_truth->SetLineColor(kBlue);
        ratio_Mee_truth->Draw("same");
    }

    string filename1 = "baseline_level_Mee_pt" + sstream_pt_low.str() + sstream_pt_up.str() + "_ratio_plot.pdf";
    Mee_plot->SaveAs(filename1.c_str(), "pdf");

    //
    // For Mmumu
    //
    TCanvas *Mmumu_plot = new TCanvas("Mmumu_plot", "Baseline level M_{#mu#mu} ratio plot", 600, 600);

    //Upper plot will be in pad1
    TPad *pad1_Mmumu = new TPad("pad1_Mmumu", "pad1_Mmumu", 0, 0.35, 1, 1.0);
    pad1_Mmumu->SetBottomMargin(0); // Upper and lower plot are joined
    pad1_Mmumu->SetRightMargin(0.08);
    //pad1_Mmumu->SetGridy(); // grid lines
    //pad1_Mmumu->SetLogx();
    pad1_Mmumu->Draw();

    // lower plot will be in pad
    TPad *pad2_Mmumu = new TPad("pad2_Mmumu", "pad2_Mmumu", 0, 0.05, 1, 0.35);
    pad2_Mmumu->SetTopMargin(0);
    pad2_Mmumu->SetBottomMargin(0.3);
    pad2_Mmumu->SetRightMargin(0.08);
    pad2_Mmumu->SetGridy(); // grid lines
    //pad2_Mmumu->SetLogx();
    pad2_Mmumu->Draw();

    pad1_Mmumu->cd(); // pad1 becomes the current pad
    //pad1_Mmumu->SetFrameLineWidth(2);

    // Draw curve here

    double data_muon_value = data_muon_mll->GetMaximum();
    double Zmumu_TandP_max_value = Zmumu_TandP_mll->GetMaximum();

    data_muon_mll->SetMarkerColor(kBlack);
    data_muon_mll->SetMarkerStyle(kFullCircle);
    data_muon_mll->SetLineColor(kBlack);
    data_muon_mll->SetTitle("");
    data_muon_mll->SetMaximum(max(data_muon_value, Zmumu_TandP_max_value) * 1.05);
    data_muon_mll->SetMinimum(0.1);
    data_muon_mll->SetStats(kFALSE);
    data_muon_mll->Draw();
    //Zmumu_TandP_mll->SetMarkerColor(kRed);
    //Zmumu_TandP_mll->SetMarkerStyle(kFullSquare);
    Zmumu_TandP_mll->SetLineColor(kRed);
    Zmumu_TandP_mll->SetFillColor(kRed);
    Zmumu_TandP_mll->SetFillStyle(3004);
    Zmumu_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zmumu_truth_mll->SetMarkerColor(kBlue);
        //Zmumu_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zmumu_truth_mll->SetLineColor(kBlue);
        Zmumu_truth_mll->SetFillColor(kBlue);
        Zmumu_truth_mll->SetFillStyle(3005);
        Zmumu_truth_mll->Draw("hist,same");
    }

    TLegend *leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg2->AddEntry(data_muon_mll, "Data");
    leg2->AddEntry(Zmumu_TandP_mll, "Z#mu#mu Tag and Probe", "f");

    if (truth_match) {
        leg2->AddEntry(Zmumu_truth_mll, "Z#mu#mu truth match", "f");
    }

    leg2->SetBorderSize(0);
    leg2->SetTextFont(42);
    leg2->SetTextSize(0.05);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(0);
    leg2->Draw("same");

    TPaveText *text2 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text2->SetTextSize(0.05);
    text2->SetBorderSize(0);
    text2->SetFillStyle(0);
    text2->SetFillColor(0);
    text2->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text2->Draw("same");

    pad2_Mmumu->cd(); // pad2 becomes the current pad

    TH1F *frame_Mmumu = pad2_Mmumu->DrawFrame(60, 0.8, 150, 1.19);
    frame_Mmumu->GetXaxis()->SetNdivisions(510);
    frame_Mmumu->GetYaxis()->SetNdivisions(405);
    frame_Mmumu->SetLineWidth(1);
    frame_Mmumu->SetXTitle("M_{ll} [GeV]");
    frame_Mmumu->GetXaxis()->SetTitleSize(20);
    frame_Mmumu->GetXaxis()->SetTitleFont(47);
    frame_Mmumu->GetXaxis()->SetTitleOffset(3.0);
    frame_Mmumu->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mmumu->GetXaxis()->SetLabelSize(15);
    frame_Mmumu->SetYTitle("Data / MC");
    frame_Mmumu->GetYaxis()->SetTitleSize(17);
    frame_Mmumu->GetYaxis()->SetTitleFont(43);
    frame_Mmumu->GetYaxis()->SetTitleOffset(1.5);
    frame_Mmumu->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mmumu->GetYaxis()->SetLabelSize(16);
    frame_Mmumu->Draw();

    TH1F *ratio_Mmumu_TandP = (TH1F *)data_muon_mll->Clone();
    ratio_Mmumu_TandP->Sumw2();
    ratio_Mmumu_TandP->Divide(Zmumu_TandP_mll);
    ratio_Mmumu_TandP->SetMarkerColor(kRed);
    ratio_Mmumu_TandP->SetMarkerStyle(kFullTriangleUp);
    ratio_Mmumu_TandP->SetLineColor(kRed);
    ratio_Mmumu_TandP->Draw("same");

    if (truth_match) {
        TH1F *ratio_Mmumu_truth = (TH1F *)data_muon_mll->Clone();
        ratio_Mmumu_truth->Sumw2();
        ratio_Mmumu_truth->Divide(Zmumu_truth_mll);
        ratio_Mmumu_truth->SetMarkerColor(kBlue);
        ratio_Mmumu_truth->SetMarkerStyle(kFullTriangleDown);
        ratio_Mmumu_truth->SetLineColor(kBlue);
        ratio_Mmumu_truth->Draw("same");
    }

    string filename2 = "baseline_level_Mmumu_pt" + sstream_pt_low.str() + sstream_pt_up.str() + "_ratio_plot.pdf";
    Mmumu_plot->SaveAs(filename2.c_str(), "pdf");
}

void yt_signal_mll_plots(int pt_bin_low = 0, int pt_bin_up = -1, bool truth_match = false)
{
    // default pt bins are:
    // 10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200

    bool debug = false;

    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");
    TFile *Zee_TandP = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");

    TFile *Zee_truth;
    TFile *Zmumu_truth;
    if (truth_match) {
        Zee_truth = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
    }

    if (debug) {
        cout << data_elec << endl;
        cout << data_muon << endl;
        cout << Zee_TandP << endl;
        cout << Zmumu_TandP << endl;
        if (truth_match) {
            cout << Zee_truth << endl;
            cout << Zmumu_truth << endl;
        }
    }

    TH3F *data_elec_signal_pt_eta_mll = (TH3F *)data_elec->Get("h_signal_pt_eta_mll");
    TH3F *data_muon_signal_pt_eta_mll = (TH3F *)data_muon->Get("h_signal_pt_eta_mll");
    TH3F *Zee_TandP_signal_pt_eta_mll = (TH3F *)Zee_TandP->Get("h_signal_pt_eta_mll");
    TH3F *Zmumu_TandP_signal_pt_eta_mll = (TH3F *)Zmumu_TandP->Get("h_signal_pt_eta_mll");

    TH3F *Zee_truth_signal_pt_eta_mll;
    TH3F *Zmumu_truth_signal_pt_eta_mll;
    if (truth_match) {
        Zee_truth_signal_pt_eta_mll = (TH3F *)Zee_truth->Get("h_signal_pt_eta_mll");
        Zmumu_truth_signal_pt_eta_mll = (TH3F *)Zmumu_truth->Get("h_signal_pt_eta_mll");
    }
    if (debug) {
        cout << data_elec_signal_pt_eta_mll << endl;
        cout << data_muon_signal_pt_eta_mll << endl;
        cout << Zee_TandP_signal_pt_eta_mll << endl;
        cout << Zmumu_TandP_signal_pt_eta_mll << endl;
        if (truth_match) {
            cout << Zee_truth_signal_pt_eta_mll << endl;
            cout << Zmumu_truth_signal_pt_eta_mll << endl;
        }
    }

    TH1D *data_elec_mll = (TH1D *)data_elec_signal_pt_eta_mll->ProjectionZ("data_elec_mll", pt_bin_low, pt_bin_up);
    TH1D *data_muon_mll = (TH1D *)data_muon_signal_pt_eta_mll->ProjectionZ("data_muon_mll", pt_bin_low, pt_bin_up);
    TH1D *Zee_TandP_mll = (TH1D *)Zee_TandP_signal_pt_eta_mll->ProjectionZ("Zee_TandP_mll", pt_bin_low, pt_bin_up);
    TH1D *Zmumu_TandP_mll = (TH1D *)Zmumu_TandP_signal_pt_eta_mll->ProjectionZ("Zmumu_TandP_mll", pt_bin_low, pt_bin_up);

    TH1D *Zee_truth_mll;
    TH1D *Zmumu_truth_mll;
    if (truth_match) {
        Zee_truth_mll = (TH1D *)Zee_truth_signal_pt_eta_mll->ProjectionZ("Zee_truth_mll", pt_bin_low, pt_bin_up);
        Zmumu_truth_mll = (TH1D *)Zmumu_truth_signal_pt_eta_mll->ProjectionZ("Zmumu_truth_mll", pt_bin_low, pt_bin_up);
    }
    if (debug) {
        cout << data_elec_mll << endl;
        cout << data_muon_mll << endl;
        cout << Zee_TandP_mll << endl;
        cout << Zmumu_TandP_mll << endl;
        if (truth_match) {
            cout << Zee_truth_mll << endl;
            cout << Zmumu_truth_mll << endl;
        }
    }

    double pt_bin_low_value;
    double pt_bin_up_value;
    if (pt_bin_low != 0 && pt_bin_up != -1) {
        pt_bin_low_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinLowEdge(pt_bin_low);
        pt_bin_up_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinUpEdge(pt_bin_up);
    }
    else {
        pt_bin_low_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinLowEdge(1);
        int nbins = data_elec_signal_pt_eta_mll->GetXaxis()->GetNbins();
        pt_bin_up_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinUpEdge(nbins - 1);
    }
    // Convert double to string using stringstream
    stringstream sstream_pt_low, sstream_pt_up;
    sstream_pt_low << pt_bin_low_value;
    sstream_pt_up << pt_bin_up_value;

    TCanvas *Mee_plot = new TCanvas("Mee_plot", "Signal level M_{ee} plot", 500, 500);

    double data_elec_value = data_elec_mll->GetMaximum();
    double Zee_TandP_max_value = Zee_TandP_mll->GetMaximum();

    data_elec_mll->SetMarkerColor(kBlack);
    data_elec_mll->SetMarkerStyle(kFullCircle);
    data_elec_mll->SetLineColor(kBlack);
    data_elec_mll->SetTitle("");
    data_elec_mll->SetXTitle("M_{ee} [GeV]");
    data_elec_mll->SetYTitle("Events");
    data_elec_mll->SetMaximum(max(data_elec_value, Zee_TandP_max_value) * 1.05);
    data_elec_mll->SetMinimum(0.);
    data_elec_mll->SetStats(kFALSE);
    data_elec_mll->Draw();
    //Zee_TandP_mll->SetMarkerColor(kRed);
    //Zee_TandP_mll->SetMarkerStyle(kFullSquare);
    Zee_TandP_mll->SetLineColor(kRed);
    Zee_TandP_mll->SetFillColor(kRed);
    Zee_TandP_mll->SetFillStyle(3004);
    Zee_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zee_truth_mll->SetMarkerColor(kBlue);
        //Zee_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zee_truth_mll->SetLineColor(kBlue);
        Zee_truth_mll->SetFillColor(kBlue);
        Zee_truth_mll->SetFillStyle(3005);
        Zee_truth_mll->Draw("hist,same");
    }

    TLegend *leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg1->SetBorderSize(0);
    leg1->SetFillStyle(0);
    leg1->SetFillColor(0);
    leg1->AddEntry(data_elec_mll, "Data");
    leg1->AddEntry(Zee_TandP_mll, "Zee Tag and Probe", "f");

    if (truth_match) {
        leg1->AddEntry(Zee_truth_mll, "Zee truth match", "f");
    }

    leg1->Draw("same");

    TPaveText *text1 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text1->SetTextSize(0.03);
    text1->SetBorderSize(0);
    text1->SetFillStyle(0);
    text1->SetFillColor(0);
    text1->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text1->Draw("same");

    string filename1 = "signal_level_Mee_pt" + sstream_pt_low.str() + sstream_pt_up.str() + ".pdf";
    Mee_plot->SaveAs(filename1.c_str(), "pdf");

    TCanvas *Mmumu_plot = new TCanvas("Mmumu_plot", "Signal level M_{#mu#mu} plot", 500, 500);

    double data_muon_value = data_muon_mll->GetMaximum();
    double Zmumu_TandP_max_value = Zmumu_TandP_mll->GetMaximum();

    data_muon_mll->SetMarkerColor(kBlack);
    data_muon_mll->SetMarkerStyle(kFullCircle);
    data_muon_mll->SetLineColor(kBlack);
    data_muon_mll->SetTitle("");
    data_muon_mll->SetXTitle("M_{#mu#mu} [GeV]");
    data_muon_mll->SetYTitle("Events");
    data_muon_mll->SetMaximum(max(data_muon_value, Zmumu_TandP_max_value) * 1.05);
    data_muon_mll->SetMinimum(0.);
    data_muon_mll->SetStats(kFALSE);
    data_muon_mll->Draw();
    //Zmumu_TandP_mll->SetMarkerColor(kRed);
    //Zmumu_TandP_mll->SetMarkerStyle(kFullSquare);
    Zmumu_TandP_mll->SetLineColor(kRed);
    Zmumu_TandP_mll->SetFillColor(kRed);
    Zmumu_TandP_mll->SetFillStyle(3004);
    Zmumu_TandP_mll->Draw("hist,same");

    if (truth_match) {
        //Zmumu_truth_mll->SetMarkerColor(kBlue);
        //Zmumu_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zmumu_truth_mll->SetLineColor(kBlue);
        Zmumu_truth_mll->SetFillColor(kBlue);
        Zmumu_truth_mll->SetFillStyle(3005);
        Zmumu_truth_mll->Draw("hist,same");
    }

    TLegend *leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg2->SetBorderSize(0);
    leg2->SetFillStyle(0);
    leg2->SetFillColor(0);
    leg2->AddEntry(data_muon_mll, "Data");
    leg2->AddEntry(Zmumu_TandP_mll, "Z#mu#mu Tag and Probe", "f");

    if (truth_match) {
        leg2->AddEntry(Zmumu_truth_mll, "Z#mu#mu truth match", "f");
    }

    leg2->Draw("same");

    TPaveText *text2 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text2->SetTextSize(0.03);
    text2->SetBorderSize(0);
    text2->SetFillStyle(0);
    text2->SetFillColor(0);
    text2->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text2->Draw("same");
    
    string filename2 = "signal_level_Mmumu_pt" + sstream_pt_low.str() + sstream_pt_up.str() + ".pdf";
    Mmumu_plot->SaveAs(filename2.c_str(), "pdf");
}

void yt_signal_mll_ratio_plots(int pt_bin_low = 0, int pt_bin_up = -1, bool truth_match = false, bool norm = false)
{
    // default pt bins are:
    // 10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200
    
    bool debug = false;
    
    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";
    
    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");
    TFile *Zee_TandP = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");
    
    TFile *Zee_truth;
    TFile *Zmumu_truth;
    if (truth_match) {
        Zee_truth = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
    }
    
    if (debug) {
        cout << data_elec << endl;
        cout << data_muon << endl;
        cout << Zee_TandP << endl;
        cout << Zmumu_TandP << endl;
        if (truth_match) {
            cout << Zee_truth << endl;
            cout << Zmumu_truth << endl;
        }
    }
    
    TH3F *data_elec_signal_pt_eta_mll = (TH3F *)data_elec->Get("h_signal_pt_eta_mll");
    TH3F *data_muon_signal_pt_eta_mll = (TH3F *)data_muon->Get("h_signal_pt_eta_mll");
    TH3F *Zee_TandP_signal_pt_eta_mll = (TH3F *)Zee_TandP->Get("h_signal_pt_eta_mll");
    TH3F *Zmumu_TandP_signal_pt_eta_mll = (TH3F *)Zmumu_TandP->Get("h_signal_pt_eta_mll");
    
    TH3F *Zee_truth_signal_pt_eta_mll;
    TH3F *Zmumu_truth_signal_pt_eta_mll;
    if (truth_match) {
        Zee_truth_signal_pt_eta_mll = (TH3F *)Zee_truth->Get("h_signal_pt_eta_mll");
        Zmumu_truth_signal_pt_eta_mll = (TH3F *)Zmumu_truth->Get("h_signal_pt_eta_mll");
    }
    if (debug) {
        cout << data_elec_signal_pt_eta_mll << endl;
        cout << data_muon_signal_pt_eta_mll << endl;
        cout << Zee_TandP_signal_pt_eta_mll << endl;
        cout << Zmumu_TandP_signal_pt_eta_mll << endl;
        if (truth_match) {
            cout << Zee_truth_signal_pt_eta_mll << endl;
            cout << Zmumu_truth_signal_pt_eta_mll << endl;
        }
    }
    
    TH1D *data_elec_mll = (TH1D *)data_elec_signal_pt_eta_mll->ProjectionZ("data_elec_mll", pt_bin_low, pt_bin_up);
    TH1D *data_muon_mll = (TH1D *)data_muon_signal_pt_eta_mll->ProjectionZ("data_muon_mll", pt_bin_low, pt_bin_up);
    TH1D *Zee_TandP_mll = (TH1D *)Zee_TandP_signal_pt_eta_mll->ProjectionZ("Zee_TandP_mll", pt_bin_low, pt_bin_up);
    TH1D *Zmumu_TandP_mll = (TH1D *)Zmumu_TandP_signal_pt_eta_mll->ProjectionZ("Zmumu_TandP_mll", pt_bin_low, pt_bin_up);
    
    TH1D *Zee_truth_mll;
    TH1D *Zmumu_truth_mll;
    if (truth_match) {
        Zee_truth_mll = (TH1D *)Zee_truth_signal_pt_eta_mll->ProjectionZ("Zee_truth_mll", pt_bin_low, pt_bin_up);
        Zmumu_truth_mll = (TH1D *)Zmumu_truth_signal_pt_eta_mll->ProjectionZ("Zmumu_truth_mll", pt_bin_low, pt_bin_up);
    }
    if (debug) {
        cout << data_elec_mll << endl;
        cout << data_muon_mll << endl;
        cout << Zee_TandP_mll << endl;
        cout << Zmumu_TandP_mll << endl;
        if (truth_match) {
            cout << Zee_truth_mll << endl;
            cout << Zmumu_truth_mll << endl;
        }
    }
    
    double pt_bin_low_value;
    double pt_bin_up_value;
    if (pt_bin_low != 0 && pt_bin_up != -1) {
        pt_bin_low_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinLowEdge(pt_bin_low);
        pt_bin_up_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinUpEdge(pt_bin_up);
    }
    else {
        pt_bin_low_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinLowEdge(1);
        int nbins = data_elec_signal_pt_eta_mll->GetXaxis()->GetNbins();
        pt_bin_up_value = data_elec_signal_pt_eta_mll->GetXaxis()->GetBinUpEdge(nbins - 1);
    }
    // Convert double to string using stringstream
    stringstream sstream_pt_low, sstream_pt_up;
    sstream_pt_low << pt_bin_low_value;
    sstream_pt_up << pt_bin_up_value;

    //
    // Normalize MC to data using a Gaussian fit of the Z peak (85 < mll < 95)
    //
    data_elec_mll->Fit("gaus", "0", "", 85, 95);
    TF1 *func_ee = data_elec_mll->GetFunction("gaus");
    //cout << func_ee->Integral(85., 95.) << endl;  // function integral uses values as arguments.
    //cout << data_elec_mll->Integral(data_elec_mll->GetXaxis()->FindBin(85. + 0.01), data_elec_mll->GetXaxis()->FindBin(95. - 0.01)) << endl; // histogram integral uses bins as argument.
    double data_elec_mll_peak_area = func_ee->Integral(85., 95.);
    
    data_muon_mll->Fit("gaus", "0", "", 85, 95);
    TF1 *func_mumu = data_muon_mll->GetFunction("gaus");
    //cout << func_mumu->Integral(85., 95.) << endl;  // function integral uses values as arguments.
    //cout << data_muon_mll->Integral(data_muon_mll->GetXaxis()->FindBin(85. + 0.01), data_muon_mll->GetXaxis()->FindBin(95. - 0.01)) << endl; // histogram integral uses bins as argument.
    double data_muon_mll_peak_area = func_mumu->Integral(85., 95.);
    
    if (norm) {
        double Zee_TandP_mll_peak_area = Zee_TandP_mll->Integral(Zee_TandP_mll->GetXaxis()->FindBin(85. + 0.01), Zee_TandP_mll->GetXaxis()->FindBin(95. - 0.01));
        double Zmumu_TandP_mll_peak_area = Zmumu_TandP_mll->Integral(Zmumu_TandP_mll->GetXaxis()->FindBin(85. + 0.01), Zmumu_TandP_mll->GetXaxis()->FindBin(95. - 0.01));
        Zee_TandP_mll->Scale(data_elec_mll_peak_area / Zee_TandP_mll_peak_area);
        Zmumu_TandP_mll->Scale(data_muon_mll_peak_area / Zmumu_TandP_mll_peak_area);
        if (truth_match) {
            double Zee_truth_mll_peak_area = Zee_truth_mll->Integral(Zee_truth_mll->GetXaxis()->FindBin(85. + 0.01), Zee_truth_mll->GetXaxis()->FindBin(95. - 0.01));
            double Zmumu_truth_mll_peak_area = Zmumu_truth_mll->Integral(Zmumu_truth_mll->GetXaxis()->FindBin(85. + 0.01), Zmumu_truth_mll->GetXaxis()->FindBin(95. - 0.01));
            Zee_truth_mll->Scale(data_elec_mll_peak_area / Zee_truth_mll_peak_area);
            Zmumu_truth_mll->Scale(data_muon_mll_peak_area / Zmumu_truth_mll_peak_area);
        }
    }
    
    //
    // For Mee
    //
    TCanvas *Mee_plot = new TCanvas("Mee_plot", "Signal level M_{ee} ratio plot", 600, 600);
    
    //Upper plot will be in pad1
    TPad *pad1_Mee = new TPad("pad1_Mee", "pad1_Mee", 0, 0.35, 1, 1.0);
    pad1_Mee->SetBottomMargin(0); // Upper and lower plot are joined
    pad1_Mee->SetRightMargin(0.08);
    //pad1_Mee->SetGridy(); // grid lines
    //pad1_Mee->SetLogx();
    pad1_Mee->Draw();
    
    // lower plot will be in pad
    TPad *pad2_Mee = new TPad("pad2_Mee", "pad2_Mee", 0, 0.05, 1, 0.35);
    pad2_Mee->SetTopMargin(0);
    pad2_Mee->SetBottomMargin(0.3);
    pad2_Mee->SetRightMargin(0.08);
    pad2_Mee->SetGridy(); // grid lines
    //pad2_Mee->SetLogx();
    pad2_Mee->Draw();
    
    pad1_Mee->cd(); // pad1 becomes the current pad
    //pad1_Mee->SetFrameLineWidth(2);
    
    // Draw curve here
    
    double data_elec_value = data_elec_mll->GetMaximum();
    double Zee_TandP_max_value = Zee_TandP_mll->GetMaximum();
    
    data_elec_mll->SetMarkerColor(kBlack);
    data_elec_mll->SetMarkerStyle(kFullCircle);
    data_elec_mll->SetLineColor(kBlack);
    data_elec_mll->SetTitle("");
    data_elec_mll->SetYTitle("Events");
    data_elec_mll->SetMaximum(max(data_elec_value, Zee_TandP_max_value) * 1.05);
    data_elec_mll->SetMinimum(0.1);
    data_elec_mll->SetStats(kFALSE);
    data_elec_mll->Draw();
    //Zee_TandP_mll->SetMarkerColor(kRed);
    //Zee_TandP_mll->SetMarkerStyle(kFullSquare);
    Zee_TandP_mll->SetLineColor(kRed);
    Zee_TandP_mll->SetFillColor(kRed);
    Zee_TandP_mll->SetFillStyle(3004);
    Zee_TandP_mll->Draw("hist,same");
    
    if (truth_match) {
        //Zee_truth_mll->SetMarkerColor(kBlue);
        //Zee_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zee_truth_mll->SetLineColor(kBlue);
        Zee_truth_mll->SetFillColor(kBlue);
        Zee_truth_mll->SetFillStyle(3005);
        Zee_truth_mll->Draw("hist,same");
    }
    
    TLegend *leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg1->AddEntry(data_elec_mll, "Data");
    leg1->AddEntry(Zee_TandP_mll, "Zee Tag and Probe", "f");
    
    if (truth_match) {
        leg1->AddEntry(Zee_truth_mll, "Zee truth match", "f");
    }
    
    leg1->SetBorderSize(0);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.05);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(0);
    leg1->Draw("same");
    
    TPaveText *text1 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text1->SetTextSize(0.05);
    text1->SetBorderSize(0);
    text1->SetFillStyle(0);
    text1->SetFillColor(0);
    text1->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text1->Draw("same");

    pad2_Mee->cd(); // pad2 becomes the current pad
    
    TH1F *frame_Mee = pad2_Mee->DrawFrame(60, 0.8, 150, 1.19);
    frame_Mee->GetXaxis()->SetNdivisions(510);
    frame_Mee->GetYaxis()->SetNdivisions(405);
    frame_Mee->SetLineWidth(1);
    frame_Mee->SetXTitle("M_{ll} [GeV]");
    frame_Mee->GetXaxis()->SetTitleSize(20);
    frame_Mee->GetXaxis()->SetTitleFont(47);
    frame_Mee->GetXaxis()->SetTitleOffset(3.0);
    frame_Mee->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mee->GetXaxis()->SetLabelSize(15);
    frame_Mee->SetYTitle("Data / MC");
    frame_Mee->GetYaxis()->SetTitleSize(17);
    frame_Mee->GetYaxis()->SetTitleFont(43);
    frame_Mee->GetYaxis()->SetTitleOffset(1.5);
    frame_Mee->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mee->GetYaxis()->SetLabelSize(16);
    frame_Mee->Draw();
    
    TH1F *ratio_Mee_TandP = (TH1F *)data_elec_mll->Clone();
    ratio_Mee_TandP->Sumw2();
    ratio_Mee_TandP->Divide(Zee_TandP_mll);
    ratio_Mee_TandP->SetMarkerColor(kRed);
    ratio_Mee_TandP->SetMarkerStyle(kFullTriangleUp);
    ratio_Mee_TandP->SetLineColor(kRed);
    ratio_Mee_TandP->Draw("same");
    
    if (truth_match) {
        TH1F *ratio_Mee_truth = (TH1F *)data_elec_mll->Clone();
        ratio_Mee_truth->Sumw2();
        ratio_Mee_truth->Divide(Zee_truth_mll);
        ratio_Mee_truth->SetMarkerColor(kBlue);
        ratio_Mee_truth->SetMarkerStyle(kFullTriangleDown);
        ratio_Mee_truth->SetLineColor(kBlue);
        ratio_Mee_truth->Draw("same");
    }
    
    string filename1 = "signal_level_Mee_pt" + sstream_pt_low.str() + sstream_pt_up.str() + "_ratio_plot.pdf";
    Mee_plot->SaveAs(filename1.c_str(), "pdf");

    //
    // For Mmumu
    //
    TCanvas *Mmumu_plot = new TCanvas("Mmumu_plot", "Signal level M_{#mu#mu} ratio plot", 600, 600);
    
    //Upper plot will be in pad1
    TPad *pad1_Mmumu = new TPad("pad1_Mmumu", "pad1_Mmumu", 0, 0.35, 1, 1.0);
    pad1_Mmumu->SetBottomMargin(0); // Upper and lower plot are joined
    pad1_Mmumu->SetRightMargin(0.08);
    //pad1_Mmumu->SetGridy(); // grid lines
    //pad1_Mmumu->SetLogx();
    pad1_Mmumu->Draw();
    
    // lower plot will be in pad
    TPad *pad2_Mmumu = new TPad("pad2_Mmumu", "pad2_Mmumu", 0, 0.05, 1, 0.35);
    pad2_Mmumu->SetTopMargin(0);
    pad2_Mmumu->SetBottomMargin(0.3);
    pad2_Mmumu->SetRightMargin(0.08);
    pad2_Mmumu->SetGridy(); // grid lines
    //pad2_Mmumu->SetLogx();
    pad2_Mmumu->Draw();
    
    pad1_Mmumu->cd(); // pad1 becomes the current pad
    //pad1_Mmumu->SetFrameLineWidth(2);
    
    // Draw curve here
    
    double data_muon_value = data_muon_mll->GetMaximum();
    double Zmumu_TandP_max_value = Zmumu_TandP_mll->GetMaximum();
    
    data_muon_mll->SetMarkerColor(kBlack);
    data_muon_mll->SetMarkerStyle(kFullCircle);
    data_muon_mll->SetLineColor(kBlack);
    data_muon_mll->SetTitle("");
    data_muon_mll->SetMaximum(max(data_muon_value, Zmumu_TandP_max_value) * 1.05);
    data_muon_mll->SetMinimum(0.1);
    data_muon_mll->SetStats(kFALSE);
    data_muon_mll->Draw();
    //Zmumu_TandP_mll->SetMarkerColor(kRed);
    //Zmumu_TandP_mll->SetMarkerStyle(kFullSquare);
    Zmumu_TandP_mll->SetLineColor(kRed);
    Zmumu_TandP_mll->SetFillColor(kRed);
    Zmumu_TandP_mll->SetFillStyle(3004);
    Zmumu_TandP_mll->Draw("hist,same");
    
    if (truth_match) {
        //Zmumu_truth_mll->SetMarkerColor(kBlue);
        //Zmumu_truth_mll->SetMarkerStyle(kFullTriangleUp);
        Zmumu_truth_mll->SetLineColor(kBlue);
        Zmumu_truth_mll->SetFillColor(kBlue);
        Zmumu_truth_mll->SetFillStyle(3005);
        Zmumu_truth_mll->Draw("hist,same");
    }
    
    TLegend *leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg2->AddEntry(data_muon_mll, "Data");
    leg2->AddEntry(Zmumu_TandP_mll, "Z#mu#mu Tag and Probe", "f");
    
    if (truth_match) {
        leg2->AddEntry(Zmumu_truth_mll, "Z#mu#mu truth match", "f");
    }
    
    leg2->SetBorderSize(0);
    leg2->SetTextFont(42);
    leg2->SetTextSize(0.05);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(0);
    leg2->Draw("same");
    
    TPaveText *text2 = new TPaveText(0.6, 0.5, 0.9, 0.7, "NDC");
    text2->SetTextSize(0.05);
    text2->SetBorderSize(0);
    text2->SetFillStyle(0);
    text2->SetFillColor(0);
    text2->AddText(string(sstream_pt_low.str() + " GeV < p_{T} <" + sstream_pt_up.str() + " GeV").c_str());
    text2->Draw("same");

    pad2_Mmumu->cd(); // pad2 becomes the current pad
    
    TH1F *frame_Mmumu = pad2_Mmumu->DrawFrame(60, 0.8, 150, 1.19);
    frame_Mmumu->GetXaxis()->SetNdivisions(510);
    frame_Mmumu->GetYaxis()->SetNdivisions(405);
    frame_Mmumu->SetLineWidth(1);
    frame_Mmumu->SetXTitle("M_{ll} [GeV]");
    frame_Mmumu->GetXaxis()->SetTitleSize(20);
    frame_Mmumu->GetXaxis()->SetTitleFont(47);
    frame_Mmumu->GetXaxis()->SetTitleOffset(3.0);
    frame_Mmumu->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mmumu->GetXaxis()->SetLabelSize(15);
    frame_Mmumu->SetYTitle("Data / MC");
    frame_Mmumu->GetYaxis()->SetTitleSize(17);
    frame_Mmumu->GetYaxis()->SetTitleFont(43);
    frame_Mmumu->GetYaxis()->SetTitleOffset(1.5);
    frame_Mmumu->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    frame_Mmumu->GetYaxis()->SetLabelSize(16);
    frame_Mmumu->Draw();
    
    TH1F *ratio_Mmumu_TandP = (TH1F *)data_muon_mll->Clone();
    ratio_Mmumu_TandP->Sumw2();
    ratio_Mmumu_TandP->Divide(Zmumu_TandP_mll);
    ratio_Mmumu_TandP->SetMarkerColor(kRed);
    ratio_Mmumu_TandP->SetMarkerStyle(kFullTriangleUp);
    ratio_Mmumu_TandP->SetLineColor(kRed);
    ratio_Mmumu_TandP->Draw("same");
    
    if (truth_match) {
        TH1F *ratio_Mmumu_truth = (TH1F *)data_muon_mll->Clone();
        ratio_Mmumu_truth->Sumw2();
        ratio_Mmumu_truth->Divide(Zmumu_truth_mll);
        ratio_Mmumu_truth->SetMarkerColor(kBlue);
        ratio_Mmumu_truth->SetMarkerStyle(kFullTriangleDown);
        ratio_Mmumu_truth->SetLineColor(kBlue);
        ratio_Mmumu_truth->Draw("same");
    }

    string filename2 = "signal_level_Mmumu_pt" + sstream_pt_low.str() + sstream_pt_up.str() + "_ratio_plot.pdf";
    Mmumu_plot->SaveAs(filename2.c_str(), "pdf");
}



//
// Efficiency plots
//

void yt_make_cut_efficiency_plot(TString filename, TString lepton)
{
    TFile *file = TFile::Open(filename);
    TH1F *h_eff_pt = (TH1F *)file->Get("h_eff_pt");

    TH1F *h_cut_eff_LooseAndBLayerLLH_to_MediumLLH;
    TH1F *h_cut_eff_CaloIso;
    if (lepton == "electron") {
        h_cut_eff_LooseAndBLayerLLH_to_MediumLLH = (TH1F *)file->Get("h_cut_eff_LooseAndBLayerLLH_to_MediumLLH");
        h_cut_eff_CaloIso = (TH1F *)file->Get("h_cut_eff_CaloIso");
    } 
    TH1F *h_cut_eff_TrackIso = (TH1F *)file->Get("h_cut_eff_TrackIso");
    //TH1F *h_cut_eff_Iso = (TH1F *)file->Get("h_cut_eff_Iso");
    TH1F *h_cut_eff_z0 = (TH1F *)file->Get("h_cut_eff_z0");
    TH1F *h_cut_eff_sigd0;
    if (lepton == "muon") {
        h_cut_eff_sigd0 = (TH1F *)file->Get("h_cut_eff_sigd0");
    }
 
    //
    // The following part are the same as ytRealLeptonEfficiency_Data::make_cut_efficiency_plot()
    //

    TCanvas *cut_efficiency_plot = new TCanvas("cut_efficiency", "Cut efficiency comparison", 500, 500);
    cut_efficiency_plot->cd();
    //gStyle->SetOptStat(0);

    h_eff_pt->SetLineColor(kBlack);
    h_eff_pt->SetMarkerColor(kBlack);
    h_eff_pt->SetMarkerStyle(kFullCircle);
    h_eff_pt->SetStats(kFALSE);
    h_eff_pt->SetMaximum(1.1);
    h_eff_pt->SetMinimum(0.);
    h_eff_pt->SetTitle("");
    h_eff_pt->Draw();

    if (lepton == "electron") {
        h_cut_eff_LooseAndBLayerLLH_to_MediumLLH->SetLineColor(kRed);
        h_cut_eff_LooseAndBLayerLLH_to_MediumLLH->SetMarkerColor(kRed);
        h_cut_eff_LooseAndBLayerLLH_to_MediumLLH->SetMarkerStyle(kFullSquare);
        h_cut_eff_LooseAndBLayerLLH_to_MediumLLH->Draw("same");

        h_cut_eff_CaloIso->SetLineColor(kGreen);
        h_cut_eff_CaloIso->SetMarkerColor(kGreen);
        h_cut_eff_CaloIso->SetMarkerStyle(kFullTriangleUp);
        h_cut_eff_CaloIso->Draw("same");
    }

    h_cut_eff_TrackIso->SetLineColor(kBlue);
    h_cut_eff_TrackIso->SetMarkerColor(kBlue);
    h_cut_eff_TrackIso->SetMarkerStyle(kFullTriangleDown);
    h_cut_eff_TrackIso->Draw("same");

    h_cut_eff_z0->SetLineColor(kMagenta);
    h_cut_eff_z0->SetMarkerColor(kMagenta);
    h_cut_eff_z0->SetMarkerStyle(kFullDiamond);
    h_cut_eff_z0->Draw("same");

    if (lepton == "muon") {
        h_cut_eff_sigd0->SetLineColor(kCyan);
        h_cut_eff_sigd0->SetMarkerColor(kCyan);
        h_cut_eff_sigd0->SetMarkerStyle(kFullCross);
        h_cut_eff_sigd0->Draw("same");
    }

    float X_max = h_eff_pt->GetXaxis()->GetXmax();
    float X_min = h_eff_pt->GetXaxis()->GetXmin();

    TLine *line = new TLine(X_min, 1., X_max,1.);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->SetLineWidth(1);
    line->Draw("SAME");

    TLegend *leg = new TLegend(0.5, 0.2, 0.8, 0.7);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    //leg->SetTextFont(42);
    leg->AddEntry("h_eff_pt", "Real Efficiency");
    if (lepton == "electron") {
        leg->AddEntry("h_cut_eff_LooseAndBLayerLLH_to_MediumLLH", "LooseLH to MediumLH");
        leg->AddEntry("h_cut_eff_CaloIso", "Calo isolation");
    }
    leg->AddEntry("h_cut_eff_TrackIso", "Track isolation");
    leg->AddEntry("h_cut_eff_z0", "|z_{0} sin(#theta)| < 0.5");
    if (lepton == "muon") {
        leg->AddEntry("h_cut_eff_sigd0", "|d_{0}/#sigma_{d0}| < 3");
    }
    leg->Draw();

    string output_filename = "cut_efficiency_" + static_cast<string>(lepton) + ".pdf";
    cut_efficiency_plot->SaveAs(output_filename.c_str(), "pdf");
}

void yt_make_electron_real_efficiency_plot(TString filename)
{
    TFile *file = TFile::Open(filename);
    TH2F *h_baseline_pt_eta = (TH2F *)file->Get("h_baseline_pt_eta");
    TH2F *h_signal_pt_eta = (TH2F *)file->Get("h_signal_pt_eta");

    TH1F *h_baseline_eta_range_1 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_1", 1, 3);
    TH1F *h_baseline_eta_range_2 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_2", 4, 5);
    TH1F *h_baseline_eta_range_3 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_3", 7, 8);

    TH1F *h_signal_eta_range_1 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_1", 1, 3);
    TH1F *h_signal_eta_range_2 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_2", 4, 5);
    TH1F *h_signal_eta_range_3 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_3", 7, 8);

    //
    // The following part are the same as ytRealLeptonEfficiency_Data::make_electron_real_efficiency_plot()
    //
/*
    // For electrons, there are 3 eta ranges: [0, 0.8], [0.8, 1.37], [1.52, 2]
    // Corresponding to eta bins: [1, 3], [4, 5], and [7, 8]
    // In order to get the correct bin, we have to use lower_edge + 0.01 and upper_edge - 0.01 to find the bin.
    // This is because FindBin() sometimes assign the lower_edge (upper_edge) to the correct_bin-1 (correct_bin+1).
    TH1F *h_baseline_eta_range_1 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_1", h_baseline_pt_eta->GetYaxis()->FindBin(0. + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(0.8 - 0.01));
    TH1F *h_baseline_eta_range_2 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_2", h_baseline_pt_eta->GetYaxis()->FindBin(0.8 + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(1.37 - 0.01));
    TH1F *h_baseline_eta_range_3 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_3", h_baseline_pt_eta->GetYaxis()->FindBin(1.52 + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(2.0 - 0.01));

    TH1F *h_signal_eta_range_1 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_1", h_signal_pt_eta->GetYaxis()->FindBin(0. + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(0.8 - 0.01));
    TH1F *h_signal_eta_range_2 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_2", h_signal_pt_eta->GetYaxis()->FindBin(0.8 + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(1.37 - 0.01));
    TH1F *h_signal_eta_range_3 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_3", h_signal_pt_eta->GetYaxis()->FindBin(1.52 + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(2.0 - 0.01));
*/
    TH1F *ratio_1 = (TH1F *)h_signal_eta_range_1->Clone();
    TH1F *ratio_2 = (TH1F *)h_signal_eta_range_2->Clone();
    TH1F *ratio_3 = (TH1F *)h_signal_eta_range_3->Clone();

    ratio_1->SetName("ratio_1");
    ratio_2->SetName("ratio_2");
    ratio_3->SetName("ratio_3");

    ratio_1->Divide(h_baseline_eta_range_1);
    ratio_2->Divide(h_baseline_eta_range_2);
    ratio_3->Divide(h_baseline_eta_range_3);

    TCanvas *real_efficiency_plot = new TCanvas("real_efficiency_plot", "Electron Real Efficiency", 500, 500);
    real_efficiency_plot->cd();

    ratio_1->SetLineColor(kBlack);
    ratio_1->SetMarkerColor(kBlack);
    ratio_1->SetMarkerStyle(kFullCircle);
    ratio_1->SetXTitle("p_{T} [GeV]");
    ratio_1->SetYTitle("Electron Real Efficiency");
    ratio_1->SetStats(kFALSE);
    ratio_1->SetMaximum(1.1);
    ratio_1->SetMinimum(0.);
    ratio_1->SetTitle("");
    ratio_1->Draw();

    ratio_2->SetLineColor(kRed);
    ratio_2->SetMarkerColor(kRed);
    ratio_2->SetMarkerStyle(kFullSquare);
    ratio_2->Draw("same");

    ratio_3->SetLineColor(kBlue);
    ratio_3->SetMarkerColor(kBlue);
    ratio_3->SetMarkerStyle(kFullTriangleUp);
    ratio_3->Draw("same");

    float X_max = ratio_1->GetXaxis()->GetXmax();
    float X_min = ratio_1->GetXaxis()->GetXmin();

    TLine *line = new TLine(X_min, 1., X_max,1.);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->SetLineWidth(1);
    line->Draw("SAME");

    TLegend *leg = new TLegend(0.5, 0.2, 0.7, 0.7);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    leg->AddEntry("ratio_1", "0 < |#eta| < 0.8");
    leg->AddEntry("ratio_2", "0.8 < |#eta| < 1.37");
    leg->AddEntry("ratio_3", "1.52 < |#eta| < 2.0");
    leg->Draw();

    real_efficiency_plot->SaveAs("electron_real_efficiency_before_bkg_subtraction.pdf", "pdf");
}

void yt_make_muon_real_efficiency_plot(TString filename)
{
    TFile *file = TFile::Open(filename);
    TH2F *h_baseline_pt_eta = (TH2F *)file->Get("h_baseline_pt_eta");
    TH2F *h_signal_pt_eta = (TH2F *)file->Get("h_signal_pt_eta");

    TH1F *h_baseline_eta_range_1 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_1", 1, 1);
    TH1F *h_baseline_eta_range_2 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_2", 2, 2);
    TH1F *h_baseline_eta_range_3 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_3", 3, 3);
    TH1F *h_baseline_eta_range_4 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_4", 4, 4);

    TH1F *h_signal_eta_range_1 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_1", 1, 1);
    TH1F *h_signal_eta_range_2 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_2", 2, 2);
    TH1F *h_signal_eta_range_3 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_3", 3, 3);
    TH1F *h_signal_eta_range_4 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_4", 4, 4);

    //
    // The following part are the same as ytRealLeptonEfficiency_Data::make_muon_real_efficiency_plot()
    //
/*
    // For muons, there are 4 eta ranges: [0, 0.6], [0.6, 1.2], [1.2, 1.8], [1.8, 2.5]
    // Corresponding to eta bins: [1, 1], [2, 2], [3, 3], and [4, 4]
    // In order to get the correct bin, we have to use lower_edge + 0.01 and upper_edge - 0.01 to find the bin.
    // This is because FindBin() sometimes assign the lower_edge (upper_edge) to the correct_bin-1 (correct_bin+1).
    TH1F *h_baseline_eta_range_1 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_1", h_baseline_pt_eta->GetYaxis()->FindBin(0. + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(0.6 - 0.01));
    TH1F *h_baseline_eta_range_2 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_2", h_baseline_pt_eta->GetYaxis()->FindBin(0.6 + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(1.2 - 0.01));
    TH1F *h_baseline_eta_range_3 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_3", h_baseline_pt_eta->GetYaxis()->FindBin(1.2 + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(1.8 - 0.01));
    TH1F *h_baseline_eta_range_4 = (TH1F *)h_baseline_pt_eta->ProjectionX("h_eta_range_4", h_baseline_pt_eta->GetYaxis()->FindBin(1.8 + 0.01), h_baseline_pt_eta->GetYaxis()->FindBin(2.5 - 0.01));

    TH1F *h_signal_eta_range_1 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_1", h_signal_pt_eta->GetYaxis()->FindBin(0. + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(0.6 - 0.01));
    TH1F *h_signal_eta_range_2 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_2", h_signal_pt_eta->GetYaxis()->FindBin(0.6 + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(1.2 - 0.01));
    TH1F *h_signal_eta_range_3 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_3", h_signal_pt_eta->GetYaxis()->FindBin(1.2 + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(1.8 - 0.01));
    TH1F *h_signal_eta_range_4 = (TH1F *)h_signal_pt_eta->ProjectionX("h_signal_eta_range_4", h_signal_pt_eta->GetYaxis()->FindBin(1.8 + 0.01), h_signal_pt_eta->GetYaxis()->FindBin(2.5 - 0.01));
*/
    TH1F *ratio_1 = (TH1F *)h_signal_eta_range_1->Clone();
    TH1F *ratio_2 = (TH1F *)h_signal_eta_range_2->Clone();
    TH1F *ratio_3 = (TH1F *)h_signal_eta_range_3->Clone();
    TH1F *ratio_4 = (TH1F *)h_signal_eta_range_4->Clone();

    ratio_1->SetName("ratio_1");
    ratio_2->SetName("ratio_2");
    ratio_3->SetName("ratio_3");
    ratio_4->SetName("ratio_4");

    ratio_1->Divide(h_baseline_eta_range_1);
    ratio_2->Divide(h_baseline_eta_range_2);
    ratio_3->Divide(h_baseline_eta_range_3);
    ratio_4->Divide(h_baseline_eta_range_4);

    TCanvas *real_efficiency_plot = new TCanvas("real_efficiency_plot", "Muon Real Efficiency", 500, 500);
    real_efficiency_plot->cd();

    ratio_1->SetLineColor(kBlack);
    ratio_1->SetMarkerColor(kBlack);
    ratio_1->SetMarkerStyle(kFullCircle);
    ratio_1->SetXTitle("p_{T} [GeV]");
    ratio_1->SetYTitle("Muon Real Efficiency");
    ratio_1->SetStats(kFALSE);
    ratio_1->SetMaximum(1.1);
    ratio_1->SetMinimum(0.);
    ratio_1->SetTitle("");
    ratio_1->Draw();

    ratio_2->SetLineColor(kRed);
    ratio_2->SetMarkerColor(kRed);
    ratio_2->SetMarkerStyle(kFullSquare);
    ratio_2->Draw("same");

    ratio_3->SetLineColor(kBlue);
    ratio_3->SetMarkerColor(kBlue);
    ratio_3->SetMarkerStyle(kFullTriangleUp);
    ratio_3->Draw("same");

    ratio_4->SetLineColor(kGreen);
    ratio_4->SetMarkerColor(kGreen);
    ratio_4->SetMarkerStyle(kFullTriangleDown);
    ratio_4->Draw("same");

    float X_max = ratio_1->GetXaxis()->GetXmax();
    float X_min = ratio_1->GetXaxis()->GetXmin();

    TLine *line = new TLine(X_min, 1., X_max,1.);
    line->SetLineColor(kBlack);
    line->SetLineStyle(2);
    line->SetLineWidth(1);
    line->Draw("SAME");

    TLegend *leg = new TLegend(0.5, 0.2, 0.7, 0.7);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    leg->AddEntry("ratio_1", "0 < |#eta| < 0.6");
    leg->AddEntry("ratio_2", "0.6 < |#eta| < 1.2");
    leg->AddEntry("ratio_3", "1.2 < |#eta| < 1.8");
    leg->AddEntry("ratio_4", "1.8 < |#eta| < 2.5");
    leg->Draw();

    real_efficiency_plot->SaveAs("muon_real_efficiency_before_bkg_subtraction.pdf", "pdf");
}

void yt_make_real_efficiency_plots(bool truth_match = false, bool ttbar = false, bool Gtt = false)
{
	TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TFile *data_muon = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");
    TFile *Zee_TandP = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
    TFile *Zmumu_TandP = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");

    TFile *Zee_truth;
    TFile *Zmumu_truth;
    if (truth_match) {
        Zee_truth = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        Zmumu_truth = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
    }

	TFile *ttbar_elec;
	TFile *ttbar_muon;
	if (ttbar) {
		ttbar_elec = TFile::Open(path + "submitDir_MC_ttbar_electron/hist-0929_80mll100.root");
		ttbar_muon = TFile::Open(path + "submitDir_MC_ttbar_muon/hist-0929_80mll100.root");
	}

	TFile *Gtt_elec;
	TFile *Gtt_muon;
	if (Gtt) {
		Gtt_elec = TFile::Open(path + "submitDir_MC_GG_ttn1_electron/hist-0929_80mll100.root");
		Gtt_muon = TFile::Open(path + "submitDir_MC_GG_ttn1_muon/hist-0929_80mll100.root");
	}

    TH1F *h_elec_eff_pt = (TH1F *)data_elec->Get("h_eff_pt");
    TH1F *h_elec_eff_eta = (TH1F *)data_elec->Get("h_eff_eta");
    TH1F *h_elec_eff_dRjet = (TH1F *)data_elec->Get("h_eff_dRjet");

    TH1F *h_muon_eff_pt = (TH1F *)data_muon->Get("h_eff_pt");
    TH1F *h_muon_eff_eta = (TH1F *)data_muon->Get("h_eff_eta");
    TH1F *h_muon_eff_dRjet = (TH1F *)data_muon->Get("h_eff_dRjet");

    TH1F *h_Zee_eff_pt = (TH1F *)Zee_TandP->Get("h_eff_pt");
    TH1F *h_Zee_eff_eta = (TH1F *)Zee_TandP->Get("h_eff_eta");
    TH1F *h_Zee_eff_dRjet = (TH1F *)Zee_TandP->Get("h_eff_dRjet");

    TH1F *h_Zmumu_eff_pt = (TH1F *)Zmumu_TandP->Get("h_eff_pt");
    TH1F *h_Zmumu_eff_eta = (TH1F *)Zmumu_TandP->Get("h_eff_eta");
    TH1F *h_Zmumu_eff_dRjet = (TH1F *)Zmumu_TandP->Get("h_eff_dRjet");

    TH1F *h_Zee_truth_eff_pt;
    TH1F *h_Zee_truth_eff_eta;
    TH1F *h_Zee_truth_eff_dRjet;

    TH1F *h_Zmumu_truth_eff_pt;
    TH1F *h_Zmumu_truth_eff_eta;
    TH1F *h_Zmumu_truth_eff_dRjet;

	if (truth_match) {
    	h_Zee_truth_eff_pt = (TH1F *)Zee_truth->Get("h_eff_pt");
    	h_Zee_truth_eff_eta = (TH1F *)Zee_truth->Get("h_eff_eta");
    	h_Zee_truth_eff_dRjet = (TH1F *)Zee_truth->Get("h_eff_dRjet");

    	h_Zmumu_truth_eff_pt = (TH1F *)Zmumu_truth->Get("h_eff_pt");
    	h_Zmumu_truth_eff_eta = (TH1F *)Zmumu_truth->Get("h_eff_eta");
    	h_Zmumu_truth_eff_dRjet = (TH1F *)Zmumu_truth->Get("h_eff_dRjet");
	}

	TH1F *h_ttbar_elec_eff_pt;
	TH1F *h_ttbar_elec_eff_eta;
	TH1F *h_ttbar_elec_eff_dRjet;

	TH1F *h_ttbar_muon_eff_pt;
	TH1F *h_ttbar_muon_eff_eta;
	TH1F *h_ttbar_muon_eff_dRjet;

	if (ttbar) {
    	h_ttbar_elec_eff_pt = (TH1F *)ttbar_elec->Get("h_eff_pt");
    	h_ttbar_elec_eff_eta = (TH1F *)ttbar_elec->Get("h_eff_eta");
    	h_ttbar_elec_eff_dRjet = (TH1F *)ttbar_elec->Get("h_eff_dRjet");

    	h_ttbar_muon_eff_pt = (TH1F *)ttbar_muon->Get("h_eff_pt");
    	h_ttbar_muon_eff_eta = (TH1F *)ttbar_muon->Get("h_eff_eta");
    	h_ttbar_muon_eff_dRjet = (TH1F *)ttbar_muon->Get("h_eff_dRjet");
	}

	TH1F *h_Gtt_elec_eff_pt;
	TH1F *h_Gtt_elec_eff_eta;
	TH1F *h_Gtt_elec_eff_dRjet;

	TH1F *h_Gtt_muon_eff_pt;
	TH1F *h_Gtt_muon_eff_eta;
	TH1F *h_Gtt_muon_eff_dRjet;

	if (Gtt) {
    	h_Gtt_elec_eff_pt = (TH1F *)Gtt_elec->Get("h_eff_pt");
    	h_Gtt_elec_eff_eta = (TH1F *)Gtt_elec->Get("h_eff_eta");
    	h_Gtt_elec_eff_dRjet = (TH1F *)Gtt_elec->Get("h_eff_dRjet");

    	h_Gtt_muon_eff_pt = (TH1F *)Gtt_muon->Get("h_eff_pt");
    	h_Gtt_muon_eff_eta = (TH1F *)Gtt_muon->Get("h_eff_eta");
    	h_Gtt_muon_eff_dRjet = (TH1F *)Gtt_muon->Get("h_eff_dRjet");
	}

    h_elec_eff_pt->SetName("h_elec_eff_pt");
    h_elec_eff_eta->SetName("h_elec_eff_eta");
    h_elec_eff_dRjet->SetName("h_elec_eff_dRjet");

    h_muon_eff_pt->SetName("h_muon_eff_pt");
    h_muon_eff_eta->SetName("h_muon_eff_eta");
    h_muon_eff_dRjet->SetName("h_muon_eff_dRjet");

    h_Zee_eff_pt->SetName("h_Zee_eff_pt");
    h_Zee_eff_eta->SetName("h_Zee_eff_eta");
    h_Zee_eff_dRjet->SetName("h_Zee_eff_dRjet");

    h_Zmumu_eff_pt->SetName("h_Zmumu_eff_pt");
    h_Zmumu_eff_eta->SetName("h_Zmumu_eff_eta");
    h_Zmumu_eff_dRjet->SetName("h_Zmumu_eff_dRjet");

	if (truth_match) {
    	h_Zee_truth_eff_pt->SetName("h_Zee_truth_eff_pt");
    	h_Zee_truth_eff_eta->SetName("h_Zee_truth_eff_eta");
    	h_Zee_truth_eff_dRjet->SetName("h_Zee_truth_eff_dRjet");

    	h_Zmumu_truth_eff_pt->SetName("h_Zmumu_truth_eff_pt");
    	h_Zmumu_truth_eff_eta->SetName("h_Zmumu_truth_eff_eta");
    	h_Zmumu_truth_eff_dRjet->SetName("h_Zmumu_truth_eff_dRjet");
	}

	if (ttbar) {
    	h_ttbar_elec_eff_pt->SetName("h_ttbar_elec_eff_pt");
    	h_ttbar_elec_eff_eta->SetName("h_ttbar_elec_eff_eta");
    	h_ttbar_elec_eff_dRjet->SetName("h_ttbar_elec_eff_dRjet");

    	h_ttbar_muon_eff_pt->SetName("h_ttbar_muon_eff_pt");
    	h_ttbar_muon_eff_eta->SetName("h_ttbar_muon_eff_eta");
    	h_ttbar_muon_eff_dRjet->SetName("h_ttbar_muon_eff_dRjet");
	}

	if (Gtt) {
    	h_Gtt_elec_eff_pt->SetName("h_Gtt_elec_eff_pt");
    	h_Gtt_elec_eff_eta->SetName("h_Gtt_elec_eff_eta");
    	h_Gtt_elec_eff_dRjet->SetName("h_Gtt_elec_eff_dRjet");

    	h_Gtt_muon_eff_pt->SetName("h_Gtt_muon_eff_pt");
    	h_Gtt_muon_eff_eta->SetName("h_Gtt_muon_eff_eta");
    	h_Gtt_muon_eff_dRjet->SetName("h_Gtt_muon_eff_dRjet");
	}

    TCanvas *real_efficiency_plot = new TCanvas("real_efficiency_plot", "Real Efficiency", 1500, 1000);
    real_efficiency_plot->Divide(3, 2);

    real_efficiency_plot->cd(1);
    h_elec_eff_pt->SetMarkerColor(kBlack);
    h_elec_eff_pt->SetMarkerStyle(kFullCircle);
    h_elec_eff_pt->SetLineColor(kBlack);
    h_elec_eff_pt->SetMaximum(1.1);
    h_elec_eff_pt->SetMinimum(0);
	h_elec_eff_pt->SetTitle("");
    h_elec_eff_pt->SetXTitle("p_{T} [GeV]");
    h_elec_eff_pt->SetYTitle("Real electron efficiency");
    h_elec_eff_pt->SetStats(kFALSE);
    h_elec_eff_pt->Draw();

    h_Zee_eff_pt->SetMarkerColor(kRed);
    h_Zee_eff_pt->SetMarkerStyle(kFullSquare);
    h_Zee_eff_pt->SetLineColor(kRed);
    h_Zee_eff_pt->Draw("same");

	if (truth_match) {
    	h_Zee_truth_eff_pt->SetMarkerColor(kBlue);
    	h_Zee_truth_eff_pt->SetMarkerStyle(kFullTriangleUp);
    	h_Zee_truth_eff_pt->SetLineColor(kBlue);
    	h_Zee_truth_eff_pt->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_elec_eff_pt->SetMarkerColor(kMagenta);
    	h_ttbar_elec_eff_pt->SetMarkerStyle(kFullDiamond);
    	h_ttbar_elec_eff_pt->SetLineColor(kMagenta);
    	h_ttbar_elec_eff_pt->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_elec_eff_pt->SetMarkerColor(kOrange);
    	h_Gtt_elec_eff_pt->SetMarkerStyle(kFullCross);
    	h_Gtt_elec_eff_pt->SetLineColor(kOrange);
    	h_Gtt_elec_eff_pt->Draw("same");
	}

    TLegend *leg1 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg1->SetBorderSize(0);
    leg1->SetFillColor(0);
    leg1->AddEntry("h_elec_eff_pt", "Data");
    leg1->AddEntry("h_Zee_eff_pt", "Z #rightarrow ee T&P MC");
	if (truth_match) {
    	leg1->AddEntry("h_Zee_truth_eff_pt", "Z #rightarrow ee truth matched MC");
	}
	if (ttbar) {
    	leg1->AddEntry("h_ttbar_elec_eff_pt", "ttbar MC");
	}
	if (Gtt) {
    	leg1->AddEntry("h_Gtt_elec_eff_pt", "Gtt MC");
	}
    leg1->Draw();

    real_efficiency_plot->cd(2);
    h_elec_eff_eta->SetMarkerColor(kBlack);
    h_elec_eff_eta->SetMarkerStyle(kFullCircle);
    h_elec_eff_eta->SetLineColor(kBlack);
    h_elec_eff_eta->SetMaximum(1.1);
    h_elec_eff_eta->SetMinimum(0);
    h_elec_eff_eta->GetXaxis()->SetRangeUser(0, 2.0);
    h_elec_eff_eta->SetTitle("");
    h_elec_eff_eta->SetXTitle("|#eta|");
    h_elec_eff_eta->SetYTitle("Real electron efficiency");
    h_elec_eff_eta->SetStats(kFALSE);
    h_elec_eff_eta->Draw();

    h_Zee_eff_eta->SetMarkerColor(kRed);
    h_Zee_eff_eta->SetMarkerStyle(kFullSquare);
    h_Zee_eff_eta->SetLineColor(kRed);
    h_Zee_eff_eta->Draw("same");

	if (truth_match) {
    	h_Zee_truth_eff_eta->SetMarkerColor(kBlue);
    	h_Zee_truth_eff_eta->SetMarkerStyle(kFullTriangleUp);
    	h_Zee_truth_eff_eta->SetLineColor(kBlue);
    	h_Zee_truth_eff_eta->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_elec_eff_eta->SetMarkerColor(kMagenta);
    	h_ttbar_elec_eff_eta->SetMarkerStyle(kFullDiamond);
    	h_ttbar_elec_eff_eta->SetLineColor(kMagenta);
    	h_ttbar_elec_eff_eta->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_elec_eff_eta->SetMarkerColor(kOrange);
    	h_Gtt_elec_eff_eta->SetMarkerStyle(kFullCross);
    	h_Gtt_elec_eff_eta->SetLineColor(kOrange);
    	h_Gtt_elec_eff_eta->Draw("same");
	}

    TLegend *leg2 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg2->SetBorderSize(0);
    leg2->SetFillColor(0);
    leg2->AddEntry("h_elec_eff_eta", "Data");
    leg2->AddEntry("h_Zee_eff_eta", "Z #rightarrow ee T&P MC");
	if (truth_match) {
    	leg2->AddEntry("h_Zee_truth_eff_eta", "Z #rightarrow ee truth matched MC");
	}
	if (ttbar) {
    	leg2->AddEntry("h_ttbar_elec_eff_eta", "ttbar MC");
	}
	if (Gtt) {
    	leg2->AddEntry("h_Gtt_elec_eff_eta", "Gtt MC");
	}
    leg2->Draw();

    real_efficiency_plot->cd(3);
    h_elec_eff_dRjet->SetMarkerColor(kBlack);
    h_elec_eff_dRjet->SetMarkerStyle(kFullCircle);
    h_elec_eff_dRjet->SetLineColor(kBlack);
    h_elec_eff_dRjet->SetMaximum(1.1);
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

	if (truth_match) {
    	h_Zee_truth_eff_dRjet->SetMarkerColor(kBlue);
    	h_Zee_truth_eff_dRjet->SetMarkerStyle(kFullTriangleUp);
    	h_Zee_truth_eff_dRjet->SetLineColor(kBlue);
    	h_Zee_truth_eff_dRjet->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_elec_eff_dRjet->SetMarkerColor(kMagenta);
    	h_ttbar_elec_eff_dRjet->SetMarkerStyle(kFullDiamond);
    	h_ttbar_elec_eff_dRjet->SetLineColor(kMagenta);
    	h_ttbar_elec_eff_dRjet->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_elec_eff_dRjet->SetMarkerColor(kOrange);
    	h_Gtt_elec_eff_dRjet->SetMarkerStyle(kFullCross);
    	h_Gtt_elec_eff_dRjet->SetLineColor(kOrange);
    	h_Gtt_elec_eff_dRjet->Draw("same");
	}

    TLegend *leg3 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg3->SetBorderSize(0);
    leg3->SetFillColor(0);
    leg3->AddEntry("h_elec_eff_dRjet", "Data");
    leg3->AddEntry("h_Zee_eff_dRjet", "Z #rightarrow ee T&P MC");
	if (truth_match) {
    	leg3->AddEntry("h_Zee_truth_eff_dRjet", "Z #rightarrow ee truth matched MC");
	}
	if (ttbar) {
    	leg3->AddEntry("h_ttbar_elec_eff_dRjet", "ttbar MC");
	}
	if (Gtt) {
    	leg3->AddEntry("h_Gtt_elec_eff_dRjet", "Gtt MC");
	}
    leg3->Draw();

    real_efficiency_plot->cd(4);
    h_muon_eff_pt->SetMarkerColor(kBlack);
    h_muon_eff_pt->SetMarkerStyle(kFullCircle);
    h_muon_eff_pt->SetLineColor(kBlack);
    h_muon_eff_pt->SetMaximum(1.1);
    h_muon_eff_pt->SetMinimum(0);
    h_muon_eff_pt->SetTitle("");
    h_muon_eff_pt->SetYTitle("Real muon efficiency");
    h_muon_eff_pt->SetStats(kFALSE);
    h_muon_eff_pt->Draw();

    h_Zmumu_eff_pt->SetMarkerColor(kRed);
    h_Zmumu_eff_pt->SetMarkerStyle(kFullSquare);
    h_Zmumu_eff_pt->SetLineColor(kRed);
    h_Zmumu_eff_pt->Draw("same");

	if (truth_match) {
    	h_Zmumu_truth_eff_pt->SetMarkerColor(kBlue);
    	h_Zmumu_truth_eff_pt->SetMarkerStyle(kFullTriangleUp);
    	h_Zmumu_truth_eff_pt->SetLineColor(kBlue);
    	h_Zmumu_truth_eff_pt->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_muon_eff_pt->SetMarkerColor(kMagenta);
    	h_ttbar_muon_eff_pt->SetMarkerStyle(kFullDiamond);
    	h_ttbar_muon_eff_pt->SetLineColor(kMagenta);
    	h_ttbar_muon_eff_pt->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_muon_eff_pt->SetMarkerColor(kOrange);
    	h_Gtt_muon_eff_pt->SetMarkerStyle(kFullCross);
    	h_Gtt_muon_eff_pt->SetLineColor(kOrange);
    	h_Gtt_muon_eff_pt->Draw("same");
	}

    TLegend *leg4 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg4->SetBorderSize(0);
    leg4->SetFillColor(0);
    leg4->AddEntry("h_muon_eff_pt", "Data");
    leg4->AddEntry("h_Zmumu_eff_pt", "Z #rightarrow #mu#mu T&P MC");
	if (truth_match) {
    	leg4->AddEntry("h_Zmumu_truth_eff_pt", "Z #rightarrow #mu#mu truth matched MC");
	}
	if (ttbar) {
    	leg4->AddEntry("h_ttbar_muon_eff_pt", "ttbar MC");
	}
	if (Gtt) {
    	leg4->AddEntry("h_Gtt_muon_eff_pt", "Gtt MC");
	}
    leg4->Draw();

    real_efficiency_plot->cd(5);
    h_muon_eff_eta->SetMarkerColor(kBlack);
    h_muon_eff_eta->SetMarkerStyle(kFullCircle);
    h_muon_eff_eta->SetLineColor(kBlack);
    h_muon_eff_eta->SetMaximum(1.1);
    h_muon_eff_eta->SetMinimum(0);
    h_muon_eff_eta->SetTitle("");
    h_muon_eff_eta->SetXTitle("|#eta|");
    h_muon_eff_eta->SetYTitle("Real muon efficiency");
    h_muon_eff_eta->SetStats(kFALSE);
    h_muon_eff_eta->Draw();

    h_Zmumu_eff_eta->SetMarkerColor(kRed);
    h_Zmumu_eff_eta->SetMarkerStyle(kFullSquare);
    h_Zmumu_eff_eta->SetLineColor(kRed);
    h_Zmumu_eff_eta->Draw("same");

	if (truth_match) {
    	h_Zmumu_truth_eff_eta->SetMarkerColor(kBlue);
    	h_Zmumu_truth_eff_eta->SetMarkerStyle(kFullTriangleUp);
    	h_Zmumu_truth_eff_eta->SetLineColor(kBlue);
    	h_Zmumu_truth_eff_eta->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_muon_eff_eta->SetMarkerColor(kMagenta);
    	h_ttbar_muon_eff_eta->SetMarkerStyle(kFullDiamond);
    	h_ttbar_muon_eff_eta->SetLineColor(kMagenta);
    	h_ttbar_muon_eff_eta->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_muon_eff_eta->SetMarkerColor(kOrange);
    	h_Gtt_muon_eff_eta->SetMarkerStyle(kFullCross);
    	h_Gtt_muon_eff_eta->SetLineColor(kOrange);
    	h_Gtt_muon_eff_eta->Draw("same");
	}

    TLegend *leg5 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg5->SetBorderSize(0);
    leg5->SetFillColor(0);
    leg5->AddEntry("h_muon_eff_eta", "Data");
    leg5->AddEntry("h_Zmumu_eff_eta", "Z #rightarrow #mu#mu T&P MC");
	if (truth_match) {
    	leg5->AddEntry("h_Zmumu_truth_eff_eta", "Z #rightarrow #mu#mu truth matched MC");
	}
	if (ttbar) {
    	leg5->AddEntry("h_ttbar_muon_eff_eta", "ttbar MC");
	}
	if (Gtt) {
    	leg5->AddEntry("h_Gtt_muon_eff_eta", "Gtt MC");
	}
    leg5->Draw();

    real_efficiency_plot->cd(6);
    h_muon_eff_dRjet->SetMarkerColor(kBlack);
    h_muon_eff_dRjet->SetMarkerStyle(kFullCircle);
    h_muon_eff_dRjet->SetLineColor(kBlack);
    h_muon_eff_dRjet->SetMaximum(1.1);
    h_muon_eff_dRjet->SetMinimum(0);
    h_muon_eff_dRjet->SetTitle("");
    h_muon_eff_dRjet->SetXTitle("#Delta R(#mu, jet)");
    h_muon_eff_dRjet->SetYTitle("Real muon efficiency");
    h_muon_eff_dRjet->SetStats(kFALSE);
    h_muon_eff_dRjet->Draw();

    h_Zmumu_eff_dRjet->SetMarkerColor(kRed);
    h_Zmumu_eff_dRjet->SetMarkerStyle(kFullSquare);
    h_Zmumu_eff_dRjet->SetLineColor(kRed);
    h_Zmumu_eff_dRjet->Draw("same");

	if (truth_match) {
    	h_Zmumu_truth_eff_dRjet->SetMarkerColor(kBlue);
    	h_Zmumu_truth_eff_dRjet->SetMarkerStyle(kFullTriangleUp);
    	h_Zmumu_truth_eff_dRjet->SetLineColor(kBlue);
    	h_Zmumu_truth_eff_dRjet->Draw("same");
	}

	if (ttbar) {
    	h_ttbar_muon_eff_dRjet->SetMarkerColor(kMagenta);
    	h_ttbar_muon_eff_dRjet->SetMarkerStyle(kFullDiamond);
    	h_ttbar_muon_eff_dRjet->SetLineColor(kMagenta);
    	h_ttbar_muon_eff_dRjet->Draw("same");
	}

	if (Gtt) {
    	h_Gtt_muon_eff_dRjet->SetMarkerColor(kOrange);
    	h_Gtt_muon_eff_dRjet->SetMarkerStyle(kFullCross);
    	h_Gtt_muon_eff_dRjet->SetLineColor(kOrange);
    	h_Gtt_muon_eff_dRjet->Draw("same");
	}

    TLegend *leg6 = new TLegend(0.3, 0.2, 0.7, 0.5);
    leg6->SetBorderSize(0);
    leg6->SetFillColor(0);
    leg6->AddEntry("h_muon_eff_dRjet", "Data");
    leg6->AddEntry("h_Zmumu_eff_dRjet", "Z #rightarrow #mu#mu T&P MC");
	if (truth_match) {
    	leg6->AddEntry("h_Zmumu_truth_eff_dRjet", "Z #rightarrow #mu#mu truth matched MC");
	}
	if (ttbar) {
    	leg6->AddEntry("h_ttbar_muon_eff_dRjet", "ttbar MC");
	}
	if (Gtt) {
    	leg6->AddEntry("h_Gtt_muon_eff_dRjet", "Gtt MC");
	}
    leg6->Draw();

    real_efficiency_plot->SaveAs("real_efficiency.pdf", "pdf");
}

// lepton = electron, muon
// x: pt, eta, dRjet
void yt_truth_match_TandP_comparison(TString lepton, TString x, bool TandP_truth_match = false)
{
    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *TandP_file;
    TFile *truth_match_file;
    TFile *TandP_truth_match_file;
    if (lepton == "electron") {
        TandP_file = TFile::Open(path + "submitDir_MC_Zee/hist-0929_80mll100.root");
        truth_match_file = TFile::Open(path + "submitDir_MC_Zee_truth_match/hist-0929_80mll100.root");
        if (TandP_truth_match)
            TandP_truth_match_file = TFile::Open(path + "submitDir_MC_Zee_TandP_truth_match/hist-0929_80mll100.root");
    }
    else if (lepton == "muon") {
        TandP_file = TFile::Open(path + "submitDir_MC_Zmumu/hist-0929_80mll100.root");
        truth_match_file = TFile::Open(path + "submitDir_MC_Zmumu_truth_match/hist-0929_80mll100.root");
        if (TandP_truth_match)
            TandP_truth_match_file = TFile::Open(path + "submitDir_MC_Zmumu_TandP_truth_match/hist-0929_80mll100.root");
    }

    TH1F *h_TandP_eff_pt = (TH1F *)TandP_file->Get("h_eff_pt");
    TH1F *h_TandP_eff_eta = (TH1F *)TandP_file->Get("h_eff_eta");
    TH1F *h_TandP_eff_dRjet = (TH1F *)TandP_file->Get("h_eff_dRjet");

    TH1F *h_truth_match_eff_pt = (TH1F *)truth_match_file->Get("h_eff_pt");
    TH1F *h_truth_match_eff_eta = (TH1F *)truth_match_file->Get("h_eff_eta");
    TH1F *h_truth_match_eff_dRjet = (TH1F *)truth_match_file->Get("h_eff_dRjet");

    if (TandP_truth_match) {
        TH1F *h_TandP_truth_match_eff_pt = (TH1F *)TandP_truth_match_file->Get("h_eff_pt");
        TH1F *h_TandP_truth_match_eff_eta = (TH1F *)TandP_truth_match_file->Get("h_eff_eta");
        TH1F *h_TandP_truth_match_eff_dRjet = (TH1F *)TandP_truth_match_file->Get("h_eff_dRjet");
    }
    
	TH1F *h_TandP_eff;
	TH1F *h_truth_match_eff;
    TH1F *h_TandP_truth_match_eff;
	TString x_title;
	float xlow, xup;

	if (x == "pt") {
		h_TandP_eff = (TH1F *)h_TandP_eff_pt->Clone();
		h_truth_match_eff = (TH1F *)h_truth_match_eff_pt->Clone();
        if (TandP_truth_match)
            h_TandP_truth_match_eff = (TH1F *)h_truth_match_eff_pt->Clone();
		x_title = "p_{T} [GeV]";
		xlow = 10.;
		xup = 200.;
	}
	else if (x == "eta") {
		h_TandP_eff = (TH1F *)h_TandP_eff_eta->Clone();
		h_truth_match_eff = (TH1F *)h_truth_match_eff_eta->Clone();
        if (TandP_truth_match)
            h_TandP_truth_match_eff = (TH1F *)h_truth_match_eff_eta->Clone();
		x_title = "|#eta|";
		xlow = 0.;
		if (lepton == "electron")
            xup = 2.0; // electron
        if (lepton == "muon")
            xup = 2.5; // muon
	}
	else if (x == "dRjet") {
		h_TandP_eff = (TH1F *)h_TandP_eff_dRjet->Clone();
		h_truth_match_eff = (TH1F *)h_truth_match_eff_dRjet->Clone();
        if (TandP_truth_match)
            h_TandP_truth_match_eff = (TH1F *)h_truth_match_eff_dRjet->Clone();
        if (lepton == "electron")
            x_title = "#Delta R(e, jet)";
        if (lepton == "muon")
            x_title = "#Delta R(#mu, jet)";
		xlow = 0.;
		xup = 4.;
	}

	TCanvas *c1 = new TCanvas("c1", "c1", 500, 500);

	//Upper plot will be in pad1
	TPad *pad1 = new TPad("pad1", "pad1", 0, 0.35, 1, 1.0);
	pad1->SetBottomMargin(0); // Upper and lower plot are joined
	pad1->SetRightMargin(0.08);
	//pad1->SetGridy(); // grid lines
	//pad1->SetLogx();
	pad1->Draw();

	// lower plot will be in pad
	TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.35);
	pad2->SetTopMargin(0);
	pad2->SetBottomMargin(0.3);
	pad2->SetRightMargin(0.08);
	pad2->SetGridy(); // grid lines
	//pad2->SetLogx();
	pad2->Draw();

	pad1->cd(); // pad1 becomes the current pad
	//pad1->SetFrameLineWidth(2);

	// Draw curve here

	h_TandP_eff->SetMarkerColor(kRed);
	h_TandP_eff->SetMarkerStyle(kFullCircle);
	h_TandP_eff->SetLineColor(kRed);
    h_TandP_eff->SetMaximum(1.1);
    h_TandP_eff->SetMinimum(0.01);
	h_TandP_eff->SetTitle("");
    h_TandP_eff->SetXTitle(x_title);
    h_TandP_eff->SetYTitle("Real lepton efficiency");
	h_TandP_eff->GetXaxis()->SetRangeUser(xlow, xup);
    h_TandP_eff->SetStats(kFALSE);
    h_TandP_eff->Draw();

	h_truth_match_eff->SetMarkerColor(kBlue);
	h_truth_match_eff->SetMarkerStyle(kFullTriangleUp);
	h_truth_match_eff->SetLineColor(kBlue);
	h_truth_match_eff->Draw("same");

    if (TandP_truth_match) {
        h_TandP_truth_match_eff->SetMarkerColor(kGreen);
        h_TandP_truth_match_eff->SetMarkerStyle(kFullTriangleDown);
        h_TandP_truth_match_eff->SetLineColor(kGreen);
        h_TandP_truth_match_eff->Draw("same");
    }

	// Add legend
	TLegend *leg = new TLegend(0.5, 0.4, 0.7, 0.6);
	leg->AddEntry(h_TandP_eff, "T&P", "lp");
	leg->AddEntry(h_truth_match_eff, "truth match", "lp");
    if (TandP_truth_match)
        leg->AddEntry(h_TandP_truth_match_eff, "TandP + truth match", "lp");
	leg->SetBorderSize(0);
	leg->SetTextFont(42);
	leg->SetTextSize(0.04);
	leg->SetFillColor(0);
	leg->SetFillStyle(0);
	leg->Draw();

	pad2->cd(); // pad2 becomes the current pad

    TH1F *frame_left;
    if (lepton == "electron")
        frame_left = pad2->DrawFrame(xlow, 0.90, xup, 1.099); // electron
    if (lepton == "muon")
        frame_left = pad2->DrawFrame(xlow, 0.98, xup, 1.019); // muon
	frame_left->GetXaxis()->SetNdivisions(510);
	frame_left->GetYaxis()->SetNdivisions(405);
	frame_left->SetLineWidth(1);
	frame_left->SetXTitle(x_title);
	frame_left->GetXaxis()->SetTitleSize(20);
	frame_left->GetXaxis()->SetTitleFont(47);
	frame_left->GetXaxis()->SetTitleOffset(3.0);
	frame_left->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
	frame_left->GetXaxis()->SetLabelSize(12);
	frame_left->SetYTitle("ratio");
	frame_left->GetYaxis()->SetTitleSize(17);
	frame_left->GetYaxis()->SetTitleFont(43);
	frame_left->GetYaxis()->SetTitleOffset(2.0);
	frame_left->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
	frame_left->GetYaxis()->SetLabelSize(12);
	frame_left->Draw();

	h_TandP_eff->Sumw2();
	h_truth_match_eff->Sumw2();
    if (TandP_truth_match)
        h_TandP_truth_match_eff->Sumw2();

	TH1F *ratio = (TH1F *)h_truth_match_eff->Clone();
	ratio->Divide(h_TandP_eff);
	ratio->SetMarkerColor(kBlue);
	ratio->SetMarkerStyle(kFullTriangleUp);
	ratio->SetLineColor(kBlue);
	ratio->Draw("e0, same");

    if (TandP_truth_match) {
        TH1F *ratio2 = (TH1F *)h_TandP_truth_match_eff->Clone();
        ratio2->Divide(h_TandP_eff);
        ratio2->SetMarkerColor(kGreen);
        ratio2->SetMarkerStyle(kFullTriangleDown);
        ratio2->SetLineColor(kGreen);
        ratio2->Draw("e0, same");
    }

    c1->SaveAs("Compare_TandP_truth_match_" + lepton + "_" + x + ".pdf", "pdf");
}


//
// Background plots
//

void yt_background_subtraction_illustration()
{
    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");
    TH3F *data_elec_baseline_pt_eta_mll = (TH3F *)data_elec->Get("h_baseline_pt_eta_mll");
    TH1D *data_elec_mll = (TH1D *)data_elec_baseline_pt_eta_mll->ProjectionZ("data_elec_mll");

    double bin_mll_low = data_elec_mll->FindBin(80. + 0.01);
    double bin_mll_up = data_elec_mll->FindBin(100. - 0.01);
    double bin_tail_low = data_elec_mll->FindBin(120. + 0.01);
    double bin_tail_up = data_elec_mll->FindBin(150. - 0.01);

    TH1D *h_mll_window = (TH1D *)data_elec_mll->Clone();
    h_mll_window->Reset();
    TH1D *h_tail = (TH1D *)data_elec_mll->Clone();
    h_tail->Reset();

    for (int i = 0; i < data_elec_mll->GetXaxis()->GetNbins() ; i++) {
        if (i >= bin_mll_low && i <= bin_mll_up)
            h_mll_window->SetBinContent(i, data_elec_mll->GetBinContent(i));
        if (i >= bin_tail_low && i <= bin_tail_up)
            h_tail->SetBinContent(i, data_elec_mll->GetBinContent(i));
    }
    TCanvas *Mee_plot = new TCanvas("Mee_plot", "Baseline M_{ee}", 500, 500);
    Mee_plot->SetLogy();
    data_elec_mll->SetMarkerColor(kBlack);
    data_elec_mll->SetMarkerStyle(kFullCircle);
    data_elec_mll->SetLineColor(kBlack);
    data_elec_mll->SetTitle("");
    data_elec_mll->SetYTitle("Events");
    data_elec_mll->SetMaximum(data_elec_mll->GetMaximum() * 10);
    data_elec_mll->SetMinimum(0.1);
    data_elec_mll->SetStats(kFALSE);
    data_elec_mll->Draw();
    h_mll_window->SetFillColor(kYellow);
    h_mll_window->SetFillStyle(3003);
    h_mll_window->SetLineColor(kYellow);
    h_mll_window->Draw("hist,same");
    h_tail->SetFillColor(kYellow);
    h_tail->SetFillStyle(3003);
    h_tail->SetLineColor(kYellow);
    h_tail->Draw("hist,same");
}

void yt_background_template_mll_plot(int pt_bin_low = 0, int pt_bin_up = -1, int eta_bin_low = 0, int eta_bin_up = -1)
{
    TString path = "/Users/ytshen/Desktop/skim/Results/1006/";

    TFile *data_elec = TFile::Open(path + "submitDir_Data_electron/hist-0929_80mll100.root");

    TH1F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso;
    TH1F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight;
    TH1F *h_bkg_template_fail_CaloIso_and_TrackIso;

    if (pt_bin_low == 0 && pt_bin_up == -1 &&
        eta_bin_low == 0 && eta_bin_up == -1) {
        // 1 dim histograms
        h_bkg_template_fail_id_and_CaloIso_and_TrackIso = (TH1F *)data_elec->Get("h_bkg_template_fail_id_and_CaloIso_and_TrackIso"); // baseline template
        h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight = (TH1F *)data_elec->Get("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight"); // variation2 bkg template
        h_bkg_template_fail_CaloIso_and_TrackIso = (TH1F *)data_elec->Get("h_bkg_template_fail_CaloIso_and_TrackIso"); // variation1 bkg template
        
        cout << h_bkg_template_fail_id_and_CaloIso_and_TrackIso << endl;
        cout << h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight << endl;
        cout << h_bkg_template_fail_CaloIso_and_TrackIso << endl;
    }
    else {
        // 3-dim histograms
        TH3F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll = (TH3F *)data_elec->Get("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll"); // baseline template
        TH3F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll = (TH3F *)data_elec->Get("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll"); // variation2 bkg template
        TH3F *h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll = (TH3F *)data_elec->Get("h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll"); // variation1 bkg template

        // project on Z axis
        h_bkg_template_fail_id_and_CaloIso_and_TrackIso = (TH1F *)h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll->ProjectionZ("baseline", pt_bin_low, pt_bin_up, eta_bin_low, eta_bin_up);
        h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight = (TH1F *)h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll->ProjectionZ("template2", pt_bin_low, pt_bin_up, eta_bin_low, eta_bin_up);
        h_bkg_template_fail_CaloIso_and_TrackIso = (TH1F *)h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll->ProjectionZ("template1", pt_bin_low, pt_bin_up, eta_bin_low, eta_bin_up);
    }

    double pt_bin_low_value, eta_bin_low_value;
    double pt_bin_up_value, eta_bin_up_value;
    if (pt_bin_low != 0 && pt_bin_up != -1) {
        pt_bin_low_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetXaxis()->GetBinLowEdge(pt_bin_low);
        pt_bin_up_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetXaxis()->GetBinUpEdge(pt_bin_up);
    }
    else {
        pt_bin_low_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetXaxis()->GetBinLowEdge(1);
        int nbins = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetXaxis()->GetNbins();
        pt_bin_up_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetXaxis()->GetBinUpEdge(nbins - 1);
    }
    if (eta_bin_low_value != 0 && eta_bin_up_value != -1) {
        eta_bin_low_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetYaxis()->GetBinLowEdge(eta_bin_low);
        eta_bin_up_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetYaxis()->GetBinUpEdge(eta_bin_up);
    }
    else {
        eta_bin_low_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetYaxis()->GetBinLowEdge(1);
        int nbins = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetYaxis()->GetNbins();
        eta_bin_up_value = h_bkg_template_fail_id_and_CaloIso_and_TrackIso->GetYaxis()->GetBinUpEdge(nbins - 1);
    }
    // Convert double to string using stringstream
    stringstream sstream_pt_low, sstream_pt_up, sstream_eta_low, sstream_eta_up;
    sstream_pt_low << pt_bin_low_value;
    sstream_pt_up << pt_bin_up_value;
    sstream_eta_low << eta_bin_low_value;
    sstream_eta_up << eta_bin_up_value;

    TCanvas *c_ee = new TCanvas("c_ee", "c_ee", 600, 600);

    // The current template 1 and 2 are exactly the same.
    h_bkg_template_fail_CaloIso_and_TrackIso->SetTitle("");
    h_bkg_template_fail_CaloIso_and_TrackIso->SetXTitle("M_{ee} [GeV]");
    h_bkg_template_fail_CaloIso_and_TrackIso->SetYTitle("Events");
    h_bkg_template_fail_CaloIso_and_TrackIso->SetLineColor(kBlue);
    h_bkg_template_fail_CaloIso_and_TrackIso->SetStats(kFALSE);
    h_bkg_template_fail_CaloIso_and_TrackIso->Draw("hist");
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->SetTitle("");
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->SetXTitle("M_{ee} [GeV]");
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->SetYTitle("Events");
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->SetStats(kFALSE);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->SetLineColor(kBlack);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Draw("hist,same");
    //h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Draw("hist");
    //h_bkg_template_fail_CaloIso_and_TrackIso->Draw("hist,same");
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->SetLineColor(kRed);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->Draw("hist,same");
    TLegend *leg = new TLegend(0.5, 0.6, 0.85, 0.8);
    leg->AddEntry(h_bkg_template_fail_id_and_CaloIso_and_TrackIso, "baseline template", "l");
    leg->AddEntry(h_bkg_template_fail_CaloIso_and_TrackIso, "variation 1 template", "l");
    leg->AddEntry(h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight, "variation 2 template", "l");
    leg->SetBorderSize(0);
    leg->Draw("same");

    string output_filename = "bkg_template_electron_pt_" + sstream_pt_low.str() + sstream_pt_up.str() + "_eta" + sstream_eta_low.str() + sstream_eta_up.str() + ".pdf";
    c_ee->SaveAs(output_filename.c_str(), "pdf");
}
