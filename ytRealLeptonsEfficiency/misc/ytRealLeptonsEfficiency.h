#ifndef ytRealLeptonsEfficiency_H
#define ytRealLeptonsEfficiency_H

#include <EventLoop/Algorithm.h>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLine.h>
#include <TLegend.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>

#include <iostream>
#include <vector>
using namespace std;

class ytRealLeptonsEfficiency : public EL::Algorithm
{
    // put your configuration variables here as public variables.
    // that way they can be set directly from CINT and python.
public:
    // float cutValue;
    bool isMC;
    bool isData;

    TString trigger;
    TString lepton;
    TString process;

    // variables that don't get filled at submission time should be
    // protected from being send from the submission node to the worker
    // node (done by the //!)
public:
    // Tree *myTree; //!
    // TH1 *myHist; //!

    TTree          *fChain;   //!pointer to the analyzed TTree or TChain

    // Declaration of leaf types

    // List of branches

    // Histograms
    TH1F *h_AvgMu; //!
    TH1F *h_mll; //!
    TH1F *h_zPV; //!

    // Baseline histograms
    // 1-dim histograms
    TH1F *h_baseline_mll; //!
    TH1F *h_baseline_pt; //!
    TH1F *h_baseline_eta; //!
    TH1F *h_baseline_d0pvtx; //!
    TH1F *h_baseline_sigd0; //!
    TH1F *h_baseline_d0err; //!
    TH1F *h_baseline_z0sinTheta; //!
    TH1F *h_baseline_ptvarcone20; //!
    TH1F *h_baseline_ptvarcone30; //!
    TH1F *h_baseline_topoetcone20; //!
    TH1F *h_baseline_nJets; //!
    TH1F *h_baseline_dRjet; //!
    TH1F *h_baseline_Etmiss; //!
    TH1F *h_baseline_meff; //!

    TH1F *h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut; //!
    TH1F *h_baseline_CaloIso_cut; //!
    TH1F *h_baseline_TrackIso_cut; //!
    TH1F *h_baseline_Iso_cut; //!
    TH1F *h_baseline_z0_cut; //!
    TH1F *h_baseline_sigd0_cut; //!

    // 2-dim histograms
    TH2F *h_baseline_pt_eta; //! x: pt, y: eta
    TH2F *h_baseline_pt_nJets; //! x: pt, y: nJets
    TH2F *h_baseline_pt_dRjet; //! x: pt, y: dRjet
    TH2F *h_baseline_pt_Etmiss; //! x: pt, y: Etmiss
    TH2F *h_baseline_pt_meff; //! x: pt, y: meff

    // 3-dim histograms
    TH3F *h_baseline_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_baseline_pt_eta_dRjet; //! x: pt, y: eta, z: dRjet
    TH3F *h_baseline_pt_dRjet_mll; //! x: pt, y: dRjet, z: mll

    // Signal histograms
    // 1-dim histograms
    TH1F *h_signal_mll; //!
    TH1F *h_signal_pt; //!
    TH1F *h_signal_eta; //!
    TH1F *h_signal_d0pvtx; //!
    TH1F *h_signal_sigd0; //!
    TH1F *h_signal_d0err; //!
    TH1F *h_signal_z0sinTheta; //!
    TH1F *h_signal_ptvarcone20; //!
    TH1F *h_signal_ptvarcone30; //!
    TH1F *h_signal_topoetcone20; //!
    TH1F *h_signal_nJets; //!
    TH1F *h_signal_dRjet; //!
    TH1F *h_signal_Etmiss; //!
    TH1F *h_signal_meff; //!

    // 2-dim histograms
    TH2F *h_signal_pt_eta; //! x: pt, y: eta
    TH2F *h_signal_pt_nJets; //! x: pt, y: nJets
    TH2F *h_signal_pt_dRjet; //! x: pt, y: dRjet
    TH2F *h_signal_pt_Etmiss; //! x: pt, y: Etmiss
    TH2F *h_signal_pt_meff; //! x: pt, y: meff

    // 3-dim histograms
    TH3F *h_signal_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_signal_pt_eta_dRjet; //! x: pt, y: eta, z: dRjet
    TH3F *h_signal_pt_dRjet_mll; //! x: pt, y: dRjet, z: mll

    // Cut efficiency histograms
    TH1F *h_cut_eff_LooseAndBLayerLLH_to_MediumLLH; //!
    TH1F *h_cut_eff_CaloIso; //!
    TH1F *h_cut_eff_TrackIso; //!
    TH1F *h_cut_eff_Iso; //!
    TH1F *h_cut_eff_z0; //!
    TH1F *h_cut_eff_sigd0; //!

    // Background template histograms
    TH1F *h_bkg_template_fail_truth; //!
    TH1F *h_bkg_template_fail_id_only; //!
    TH1F *h_bkg_template_fail_CaloIso_only; //!
    TH1F *h_bkg_template_fail_TrackIso_only; //!
    TH1F *h_bkg_template_fail_id_and_CaloIso; //!
    TH1F *h_bkg_template_fail_id_and_TrackIso; //!
    TH1F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso; //!
    TH1F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight; //!
    TH1F *h_bkg_template_fail_CaloIso_and_TrackIso; //!

    // 3-dim background template histograms
    TH3F *h_bkg_template_fail_truth_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_id_only_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_CaloIso_only_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_TrackIso_only_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_id_and_CaloIso_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_id_and_TrackIso_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll; //! x: pt, y: eta, z: mll
    TH3F *h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll; //! x: pt, y: eta, z: mll

    // Real lepton efficiency histograms
    // 1-dim histograms
    TH1F *h_eff_pt; //!
    TH1F *h_eff_eta; //!
    TH1F *h_eff_nJets; //!
    TH1F *h_eff_dRjet; //!
    TH1F *h_eff_Etmiss; //!
    TH1F *h_eff_meff; //!

    // 2-dim histograms
    TH2F *h_2d_eff_pt_eta; //!
    TH2F *h_2d_eff_pt_nJets; //!
    TH2F *h_2d_eff_pt_dRjet; //!
    TH2F *h_2d_eff_pt_Etmiss; //!
    TH2F *h_2d_eff_pt_meff; //!

    TCanvas *baseline_mll_plot; //!
    TCanvas *cut_efficiency_plot; //!
    TCanvas *real_efficiency_plot; //!
    //TLine *line; //!
    //TLegend *leg; //!

    // Binning
    vector<float> m_mll_bins; //!
    vector<float> m_pt_bins; //!
    vector<float> m_eta_bins; //!
    vector<float> m_deltaR_bins; //!
    vector<float> m_NJet_bins; //!
    vector<float> m_Etmiss_bins; //!
    vector<float> m_meff_bins; //!

    int n_mll_bins; //!
    int n_pt_bins; //!
    int n_eta_bins; //!
    int n_deltaR_bins; //!
    int n_NJet_bins; //!
    int n_Etmiss_bins; //!
    int n_meff_bins; //!

    static const float m_default_mll_bins[91]; //
    static const float m_default_pt_bins[14]; //!
    static const float m_default_eta_bins[21]; //!
    static const float m_default_deltaR_bins[21]; //!
    static const float m_default_NJet_bins[11]; //!
    static const float m_default_Etmiss_bins[9]; //!
    static const float m_default_meff_bins[7]; //!

    static const float m_muon_eta_bins[21]; //!
    static const float m_abs_eta_bins[11]; //!
    static const float m_muon_abs_eta_bins[11]; //!

    static const float m_electron_coarse_pt_bins[12]; //!
    static const float m_electron_coarse_eta_bins[6]; //!
    static const float m_muon_coarse_pt_bins[12]; //!
    static const float m_muon_coarse_eta_bins[5]; //!
    static const float m_coarse_deltaR_bins[7]; //!

    // this is a standard constructor
    ytRealLeptonsEfficiency ();

    // these are the functions inherited from Algorithm
    virtual EL::StatusCode setupJob (EL::Job& job);
    virtual EL::StatusCode fileExecute ();
    virtual EL::StatusCode histInitialize ();
    virtual EL::StatusCode changeInput (bool firstFile);
    virtual EL::StatusCode initialize ();
    virtual EL::StatusCode execute ();
    virtual EL::StatusCode postExecute ();
    virtual EL::StatusCode finalize ();
    virtual EL::StatusCode histFinalize ();

    // Set methods
    void set_isMC(bool b) { isMC = b; cout << "isMC=" << isMC << endl; }
    void set_isData(bool b) { isData = b; cout << "isData=" << isData << endl; }
    void set_trigger(TString str) { trigger = str; cout << "trigger=" << trigger << endl; }
    void set_lepton(TString str) { lepton = str; cout << "lepton=" << lepton << endl; }
    void set_process(TString str) { process = str; cout << "process=" << process << endl; }

    void set_binning_default();
    void set_binning(int i, const float *bins, vector<float> &vec);
    void set_binning_pt(int i, const float *bins) { set_binning(i, bins, m_pt_bins); }
    void set_binning_eta(int i, const float *bins) { set_binning(i, bins, m_eta_bins); }
    void set_binning_mll(int i, const float *bins) { set_binning(i, bins, m_mll_bins); }

    // Background subtraction methods
    void do_background_subtraction() { /* Need to be implemented */ }

    // loop over leptons
    void loop_over_electrons();
    void loop_over_muons();

    // plots
    void make_baseline_mll_plot();
    void make_cut_efficiency_plot();
    void make_electron_real_efficiency_plot();
    void make_muon_real_efficiency_plot();

    // this is needed to distribute the algorithm to the workers
    ClassDef(ytRealLeptonsEfficiency, 1);
};

#endif

