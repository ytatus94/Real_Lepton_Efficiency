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

TString path = "/Users/ytshen/Desktop/skim/Results/1015/";

void ytCalculate_real_muon_efficiency_systematics(int eta_bin_low = 0,
												  int eta_bin_up = -1)
{

	bool debug = true;
	bool verbose = false;

	TString path = "/Users/ytshen/Desktop/skim/Results/1015/";
	TFile *data_file = TFile::Open(path + "submitDir_Data_muon/hist-0929_80mll100.root");

	if (debug)
		cout << data_file << endl;

	// Get 3-dim data histograms
	TH3F *data_baseline_pt_eta_mll = (TH3F *)data_file->Get("h_baseline_pt_eta_mll");
	TH3F *data_signal_pt_eta_mll = (TH3F *)data_file->Get("h_signal_pt_eta_mll");

	if (debug) {
		cout << "pt min=" << data_baseline_pt_eta_mll->GetZaxis()->GetXmin() << endl;
		cout << "pt max=" << data_baseline_pt_eta_mll->GetZaxis()->GetXmax() << endl;
	}

	// Full mll range.
	int mll_60_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(60. + 0.01);
	int mll_150_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(150. - 0.01);
	// 80 < mll < 100
	int mll_80_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(80. + 0.01);
	int mll_100_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(100. - 0.01);
	// 85 < mll < 95
	int mll_85_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(85. + 0.01);
	int mll_95_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(95. - 0.01);
	// 75 < mll < 105
	int mll_75_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(75. + 0.01);
	int mll_105_bin = data_baseline_pt_eta_mll->GetZaxis()->FindBin(105. - 0.01);

	if (debug) {
		cout << "(mll_60_bin, mll_150_bin)=(" << mll_60_bin << ", " << mll_150_bin << ")" << endl;
		cout << "(mll_80_bin, mll_100_bin)=(" << mll_80_bin << ", " << mll_100_bin << ")" << endl;
		cout << "(mll_85_bin, mll_95_bin)=(" << mll_85_bin << ", " << mll_95_bin << ")" << endl;
		cout << "(mll_75_bin, mll_105_bin)=(" << mll_75_bin << ", " << mll_105_bin << ")" << endl;
	}

	// Get 1-dim data histograms
	TH1F *data_baseline_pt_1 = (TH1F *)data_baseline_pt_eta_mll->ProjectionX("data_baseline_pt_1", eta_bin_low, eta_bin_up, mll_60_bin, mll_150_bin);
	TH1F *data_signal_pt_1 = (TH1F *)data_signal_pt_eta_mll->ProjectionX("data_signal_pt_1", eta_bin_low, eta_bin_up, mll_60_bin, mll_150_bin);

	TH1F *data_baseline_pt_2 = (TH1F *)data_baseline_pt_eta_mll->ProjectionX("data_baseline_pt_2", eta_bin_low, eta_bin_up, mll_80_bin, mll_100_bin);
	TH1F *data_signal_pt_2 = (TH1F *)data_signal_pt_eta_mll->ProjectionX("data_signal_pt_2", eta_bin_low, eta_bin_up, mll_80_bin, mll_100_bin);

	TH1F *data_baseline_pt_3 = (TH1F *)data_baseline_pt_eta_mll->ProjectionX("data_baseline_pt_3", eta_bin_low, eta_bin_up, mll_85_bin, mll_95_bin);
	TH1F *data_signal_pt_3 = (TH1F *)data_signal_pt_eta_mll->ProjectionX("data_signal_pt_3", eta_bin_low, eta_bin_up, mll_85_bin, mll_95_bin);
	
	TH1F *data_baseline_pt_4 = (TH1F *)data_baseline_pt_eta_mll->ProjectionX("data_baseline_pt_4", eta_bin_low, eta_bin_up, mll_75_bin, mll_105_bin);
	TH1F *data_signal_pt_4 = (TH1F *)data_signal_pt_eta_mll->ProjectionX("data_signal_pt_4", eta_bin_low, eta_bin_up, mll_75_bin, mll_105_bin);

	if (debug) {
		cout << data_baseline_pt_1->Integral() << ", " 
			<< data_baseline_pt_2->Integral() << ", " 
			<< data_baseline_pt_3->Integral() << ", " 
			<< data_baseline_pt_4->Integral() << endl;
		cout << data_signal_pt_1->Integral() << ", " 
			<< data_signal_pt_2->Integral() << ", " 
			<< data_signal_pt_3->Integral() << ", " 
			<< data_signal_pt_4->Integral() << endl;
	}

	TH1F *eff_1 = (TH1F *)data_signal_pt_1->Clone();
	TH1F *eff_2 = (TH1F *)data_signal_pt_2->Clone();
	TH1F *eff_3 = (TH1F *)data_signal_pt_3->Clone();
	TH1F *eff_4 = (TH1F *)data_signal_pt_4->Clone();

	eff_1->Divide(data_signal_pt_1, data_baseline_pt_1, 1, 1, "B");
	eff_2->Divide(data_signal_pt_2, data_baseline_pt_2, 1, 1, "B");
	eff_3->Divide(data_signal_pt_3, data_baseline_pt_3, 1, 1, "B");
	eff_4->Divide(data_signal_pt_4, data_baseline_pt_4, 1, 1, "B");

	if (debug) {
		cout << eff_1->GetBinContent(0) << ", " << eff_2->GetBinContent(0) << ", " << eff_3->GetBinContent(0) << ", " << eff_4->GetBinContent(0) << endl;
		cout << eff_1->GetBinContent(1) << ", " << eff_2->GetBinContent(1) << ", " << eff_3->GetBinContent(1) << ", " << eff_4->GetBinContent(1) << endl;
		cout << eff_1->GetBinContent(2) << ", " << eff_2->GetBinContent(2) << ", " << eff_3->GetBinContent(2) << ", " << eff_4->GetBinContent(2) << endl;
		cout << eff_1->GetBinContent(3) << ", " << eff_2->GetBinContent(3) << ", " << eff_3->GetBinContent(3) << ", " << eff_4->GetBinContent(3) << endl;
		cout << eff_1->GetBinContent(4) << ", " << eff_2->GetBinContent(4) << ", " << eff_3->GetBinContent(4) << ", " << eff_4->GetBinContent(4) << endl;
		cout << eff_1->GetBinContent(5) << ", " << eff_2->GetBinContent(5) << ", " << eff_3->GetBinContent(5) << ", " << eff_4->GetBinContent(5) << endl;
		cout << eff_1->GetBinContent(6) << ", " << eff_2->GetBinContent(6) << ", " << eff_3->GetBinContent(6) << ", " << eff_4->GetBinContent(6) << endl;
		cout << eff_1->GetBinContent(7) << ", " << eff_2->GetBinContent(7) << ", " << eff_3->GetBinContent(7) << ", " << eff_4->GetBinContent(7) << endl;
		cout << eff_1->GetBinContent(8) << ", " << eff_2->GetBinContent(8) << ", " << eff_3->GetBinContent(8) << ", " << eff_4->GetBinContent(8) << endl;
		cout << eff_1->GetBinContent(9) << ", " << eff_2->GetBinContent(9) << ", " << eff_3->GetBinContent(9) << ", " << eff_4->GetBinContent(9) << endl;
		cout << eff_1->GetBinContent(10) << ", " << eff_2->GetBinContent(10) << ", " << eff_3->GetBinContent(10) << ", " << eff_4->GetBinContent(10) << endl;
		cout << eff_1->GetBinContent(11) << ", " << eff_2->GetBinContent(11) << ", " << eff_3->GetBinContent(11) << ", " << eff_4->GetBinContent(11) << endl;
		cout << eff_1->GetBinContent(12) << ", " << eff_2->GetBinContent(12) << ", " << eff_3->GetBinContent(12) << ", " << eff_4->GetBinContent(12) << endl;
		cout << eff_1->GetBinContent(13) << ", " << eff_2->GetBinContent(13) << ", " << eff_3->GetBinContent(13) << ", " << eff_4->GetBinContent(13) << endl;
	}
}
