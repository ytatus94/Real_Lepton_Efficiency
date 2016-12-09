#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <ytRealLeptonsEfficiency/ytRealLeptonsEfficiency.h>

// this is needed to distribute the algorithm to the workers
ClassImp(ytRealLeptonsEfficiency)

// Define the binnings
const float ytRealLeptonsEfficiency::m_default_mll_bins[91] = {
    60., 61., 62., 63., 64., 65., 66., 67., 68., 69.,
    70., 71., 72., 73., 74., 75., 76., 77., 78., 79.,
    80., 81., 82., 83., 84., 85., 86., 87., 88., 89.,
    90., 91., 92., 93., 94., 95., 96., 97., 98., 99.,
    100., 101., 102., 103., 104., 105., 106., 107., 108., 109.,
    110., 111., 112., 113., 114., 115., 116., 117., 118., 119.,
    120., 121., 122., 123., 124., 125., 126., 127., 128., 129.,
    130., 131., 132., 133., 134., 135., 136., 137., 138., 139.,
    140., 141., 142., 143., 144., 145., 146., 147., 148., 149.,
    150.
};
const float ytRealLeptonsEfficiency::m_default_pt_bins[14] = {
    10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200
};
const float ytRealLeptonsEfficiency::m_default_eta_bins[21]  = {
    -2.47, -2.37, -2.01, -1.81, -1.52, -1.37, -1.15, -0.8, -0.6, -0.1, 0., 0.1, 0.6, 0.8, 1.15, 1.37, 1.52, 1.81, 2.01, 2.37, 2.47
};
const float ytRealLeptonsEfficiency::m_default_deltaR_bins[21] = {
    0, 0.2, 0.4, 0.6, 0.8,
    1.0, 1.2, 1.4, 1.6, 1.8,
    2.0, 2.2, 2.4, 2.6, 2.8,
    3.0, 3.2, 3.4, 3.6, 3.8,
    4.0
};
const float ytRealLeptonsEfficiency::m_default_NJet_bins[11] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};
const float ytRealLeptonsEfficiency::m_default_Etmiss_bins[9] = {
    0., 50. , 100., 150., 200. , 250., 300., 350., 400.
};
const float ytRealLeptonsEfficiency::m_default_meff_bins[7] = {
    0., 250., 500., 750., 1000., 1250., 1500.
};
const float ytRealLeptonsEfficiency::m_muon_eta_bins[21] = {
    -2.5, -2.25, -2., -1.75, -1.5, -1.25, -1., -0.75, -0.5, -0.25, 0, 0.25, 0.5, 0.75, 1., 1.25, 1.5, 1.75, 2., 2.25, 2.5
};
const float ytRealLeptonsEfficiency::m_abs_eta_bins[11] = {
    0., 0.1, 0.6, 0.8, 1.15, 1.37, 1.52, 1.81, 2.01, 2.37, 2.47
};
const float ytRealLeptonsEfficiency::m_muon_abs_eta_bins[11] = {
    0, 0.25, 0.5, 0.75, 1., 1.25, 1.5, 1.75, 2., 2.25, 2.5
};
const float ytRealLeptonsEfficiency::m_electron_coarse_pt_bins[12] = {
    10, 15, 20, 25, 30, 35, 40, 50, 60, 80, 150, 200
};
const float ytRealLeptonsEfficiency::m_electron_coarse_eta_bins[6] = {
    0, 0.8, 1.37, 1.52, 2.01, 2.47
};
const float ytRealLeptonsEfficiency::m_muon_coarse_pt_bins[12] = {
    10, 15, 20, 25, 30, 35, 40, 50, 60, 80, 150, 200
};
const float ytRealLeptonsEfficiency::m_muon_coarse_eta_bins[5] = {
    //0, 0.5, 1.25 , 1.75 , 2.5
    0, 0.6, 1.2, 1.8, 2.5
};
const float ytRealLeptonsEfficiency::m_coarse_deltaR_bins[7] = {
    0, 0.2, 0.4, 0.6, 1.0, 2.0, 4.0
};

ytRealLeptonsEfficiency::ytRealLeptonsEfficiency ()
{
    // Here you put any code for the base initialization of variables,
    // e.g. initialize all pointers to 0.  Note that you should only put
    // the most basic initialization here, since this method will be
    // called on both the submission and the worker node.  Most of your
    // initialization code will go into histInitialize() and
    // initialize().

    //const char * function_name = "ytRealLeptonsEfficiency()";
    //Info(function_name, "Function calls");

    this->set_binning_default();

    n_mll_bins = m_mll_bins.size() - 1;
    n_pt_bins = m_pt_bins.size() - 1;
    n_eta_bins = m_eta_bins.size() - 1;
    n_deltaR_bins = m_deltaR_bins.size() - 1;
    n_NJet_bins = m_NJet_bins.size() - 1;
    n_Etmiss_bins = m_Etmiss_bins.size() - 1;
    n_meff_bins = m_meff_bins.size() - 1;
/*
    // For debug
    cout << "n_mll_bins=" << n_mll_bins << endl;
    cout << "n_pt_bins=" << n_pt_bins << endl;
    cout << "n_eta_bins=" << n_eta_bins << endl;
    cout << "n_deltaR_bins=" << n_deltaR_bins << endl;
    cout << "n_NJet_bins=" << n_NJet_bins << endl;
    cout << "n_Etmiss_bins=" << n_Etmiss_bins << endl;
    cout << "n_meff_bins=" << n_meff_bins << endl;
*/
}



EL::StatusCode ytRealLeptonsEfficiency::setupJob (EL::Job& job)
{
    // Here you put code that sets up the job on the submission object
    // so that it is ready to work with your algorithm, e.g. you can
    // request the D3PDReader service or add output files.  Any code you
    // put here could instead also go into the submission script.  The
    // sole advantage of putting it here is that it gets automatically
    // activated/deactivated when you add/remove the algorithm from your
    // job, which may or may not be of value to you.

    //const char * function_name = "setupJob()";
    //Info(function_name, "Function calls");

    return EL::StatusCode::SUCCESS;
}




EL::StatusCode ytRealLeptonsEfficiency::histInitialize ()
{
    // Here you do everything that needs to be done at the very
    // beginning on each worker node, e.g. create histograms and output
    // trees.  This method gets called before any input files are
    // connected.

    //const char * function_name = "histInitialize()";
    //Info(function_name, "Function calls");

    if (lepton == "electron") {
        this->set_binning_eta(sizeof(m_abs_eta_bins) / sizeof(m_abs_eta_bins[0]), m_abs_eta_bins);
    }
    if (lepton == "muon") {
        this->set_binning_eta(sizeof(m_muon_coarse_eta_bins) / sizeof(m_muon_coarse_eta_bins[0]), m_muon_coarse_eta_bins);
    }
    n_eta_bins = m_eta_bins.size() - 1;
/*
    // For debug
    cout << "m_mll_bins are" << endl;
    for (unsigned int i = 0; i < m_mll_bins.size(); i++) {
        cout << m_mll_bins[i] << endl;
    }
    cout << "n_mll_bins=" << n_mll_bins << endl;
    cout << "m_pt_bins are" << endl;
    for (unsigned int i = 0; i < m_pt_bins.size(); i++) {
        cout << m_pt_bins[i] << endl;
    }
    cout << "n_pt_bins=" << n_pt_bins << endl;
    cout << "m_eta_bins are" << endl;
    for (unsigned int i = 0; i < m_eta_bins.size(); i++) {
        cout << m_eta_bins[i] << endl;
    }
    cout << "n_eta_bins=" << n_eta_bins << endl;
*/
    h_AvgMu = new TH1F("h_AvgMu", "AvgMu;<#mu>;Events", 50, 0 , 50);
    h_mll   = new TH1F("h_mll", "mll;M_{ll} [GeV];Events", 100, 40, 140);
    h_zPV   = new TH1F("h_zPV", "zPV", 200, -200, 200);

    wk()->addOutput(h_AvgMu);
    wk()->addOutput(h_mll);
    wk()->addOutput(h_zPV);

    // Baseline histograms
    // 1-dim histograms
    h_baseline_mll          = new TH1F("h_baseline_mll", "mll;M_{ll} [GeV];Events", n_mll_bins, &m_mll_bins[0]);
    h_baseline_pt           = new TH1F("h_baseline_pt", "pt;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_eta          = new TH1F("h_baseline_eta", "eta;#eta;Events", n_eta_bins, &m_eta_bins[0]);
    h_baseline_d0pvtx       = new TH1F("h_baseline_d0pvtx", "d0pvtx", 100, -0.15, 0.15);
    h_baseline_sigd0        = new TH1F("h_baseline_sigd0", "sigd0", 100, 0, 10);
    h_baseline_d0err        = new TH1F("h_baseline_d0err", "d0err", 100, -0.1, 0.1);
    h_baseline_z0sinTheta   = new TH1F("h_baseline_z0SinTheta", "fabs(z0sinTheta)", 100, 0, 0.5);
    h_baseline_ptvarcone20  = new TH1F("h_baseline_ptvarcone20", "ptvarcone20", 100, 0, 0.2);
    h_baseline_ptvarcone30  = new TH1F("h_baseline_ptvarcone30", "ptvarcone30", 100, 0, 0.2);
    h_baseline_topoetcone20 = new TH1F("h_baseline_topoetcone20", "topoetcone20", 100, 0, 0.2);
    h_baseline_nJets        = new TH1F("h_baseline_nJets", "NJet", n_NJet_bins, &m_NJet_bins[0]);
    h_baseline_dRjet        = new TH1F("h_baseline_dRjet", "dRjet", n_deltaR_bins, &m_deltaR_bins[0]);
    h_baseline_Etmiss       = new TH1F("h_baseline_Etmiss", "Etmiss", n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_baseline_meff         = new TH1F("h_baseline_meff", "meff", n_meff_bins, &m_meff_bins[0]);

    h_baseline_mll->Sumw2();
    h_baseline_pt->Sumw2();
    h_baseline_eta->Sumw2();
    h_baseline_d0pvtx->Sumw2();
    h_baseline_sigd0->Sumw2();
    h_baseline_d0err->Sumw2();
    h_baseline_z0sinTheta->Sumw2();
    h_baseline_ptvarcone20->Sumw2();
    h_baseline_ptvarcone30->Sumw2();
    h_baseline_topoetcone20->Sumw2();
    h_baseline_nJets->Sumw2();
    h_baseline_dRjet->Sumw2();
    h_baseline_Etmiss->Sumw2();
    h_baseline_meff->Sumw2();

    wk()->addOutput(h_baseline_mll);
    wk()->addOutput(h_baseline_pt);
    wk()->addOutput(h_baseline_eta);
    wk()->addOutput(h_baseline_d0pvtx);
    wk()->addOutput(h_baseline_sigd0);
    wk()->addOutput(h_baseline_d0err);
    wk()->addOutput(h_baseline_z0sinTheta);
    wk()->addOutput(h_baseline_ptvarcone20);
    wk()->addOutput(h_baseline_ptvarcone30);
    wk()->addOutput(h_baseline_topoetcone20);
    wk()->addOutput(h_baseline_nJets);
    wk()->addOutput(h_baseline_dRjet);
    wk()->addOutput(h_baseline_Etmiss);
    wk()->addOutput(h_baseline_meff);

    h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut = new TH1F("h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut", "LooseAndBLayerLLH_to_MediumLLH_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_CaloIso_cut  = new TH1F("h_baseline_CaloIso_cut", "CaloIso_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_TrackIso_cut = new TH1F("h_baseline_TrackIso_cut", "TrackIso_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_Iso_cut      = new TH1F("h_baseline_Iso_cut", "Iso_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_z0_cut       = new TH1F("h_baseline_z0_cut", "z0_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);
    h_baseline_sigd0_cut    = new TH1F("h_baseline_sigd0_cut", "sigd0_cut;p_{T} [GeV];Events", n_pt_bins, &m_pt_bins[0]);

    h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut->Sumw2();
    h_baseline_CaloIso_cut->Sumw2();
    h_baseline_TrackIso_cut->Sumw2();
    h_baseline_Iso_cut->Sumw2();
    h_baseline_z0_cut->Sumw2();
    h_baseline_sigd0_cut->Sumw2();

    wk()->addOutput(h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut);
    wk()->addOutput(h_baseline_CaloIso_cut);
    wk()->addOutput(h_baseline_TrackIso_cut);
    wk()->addOutput(h_baseline_Iso_cut);
    wk()->addOutput(h_baseline_z0_cut);
    wk()->addOutput(h_baseline_sigd0_cut);

    // 2-dim histograms
    h_baseline_pt_eta       = new TH2F("h_baseline_pt_eta", "p_{T} vs #eta;p_{T} [GeV];#eta", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0]);
    h_baseline_pt_nJets     = new TH2F("h_baseline_pt_nJets", "p_{T} vs NJet;p_{T} [GeV];NJet", n_pt_bins, &m_pt_bins[0], n_NJet_bins, &m_NJet_bins[0]);
    h_baseline_pt_dRjet     = new TH2F("h_baseline_pt_dRjet", "p_{T} vs dRjet;p_{T} [GeV];dRjet", n_pt_bins, &m_pt_bins[0], n_deltaR_bins, &m_deltaR_bins[0]);
    h_baseline_pt_Etmiss    = new TH2F("h_baseline_pt_Etmiss", "p_{T} vs Etmiss;p_{T} [GeV];Etmiss", n_pt_bins, &m_pt_bins[0], n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_baseline_pt_meff      = new TH2F("h_baseline_pt_meff", "p_{T} vs meff;p_{T} [GeV];meff", n_pt_bins, &m_pt_bins[0], n_meff_bins, &m_meff_bins[0]);

    h_baseline_pt_eta->Sumw2();
    h_baseline_pt_nJets->Sumw2();
    h_baseline_pt_dRjet->Sumw2();
    h_baseline_pt_Etmiss->Sumw2();
    h_baseline_pt_meff->Sumw2();

    wk()->addOutput(h_baseline_pt_eta);
    wk()->addOutput(h_baseline_pt_nJets);
    wk()->addOutput(h_baseline_pt_dRjet);
    wk()->addOutput(h_baseline_pt_Etmiss);
    wk()->addOutput(h_baseline_pt_meff);

    // 3-dim histograms
    h_baseline_pt_eta_mll   = new TH3F("h_baseline_pt_eta_mll", "Baseline 3-dim;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_baseline_pt_eta_dRjet = new TH3F("h_baseline_pt_eta_dRjet", "Baseline 3-dim;p_{T} [GeV];#eta;#Delta R(#ell, jet)", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_deltaR_bins, &m_deltaR_bins[0]);
    h_baseline_pt_dRjet_mll = new TH3F("h_baseline_pt_dRjet_mll", "Baseline 3-dim;p_{T} [GeV];#Delta R(#ell, jet);M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_deltaR_bins, &m_deltaR_bins[0], n_mll_bins, &m_mll_bins[0]);

    h_baseline_pt_eta_mll->Sumw2();
    h_baseline_pt_eta_dRjet->Sumw2();
    h_baseline_pt_dRjet_mll->Sumw2();

    wk()->addOutput(h_baseline_pt_eta_mll);
    wk()->addOutput(h_baseline_pt_eta_dRjet);
    wk()->addOutput(h_baseline_pt_dRjet_mll);

    // Signal histograms
    // 1-dim histograms
    h_signal_mll            = new TH1F("h_signal_mll", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_signal_pt             = new TH1F("h_signal_pt", "pt;p_{T} [GeV];Events;", n_pt_bins, &m_pt_bins[0]);
    h_signal_eta            = new TH1F("h_signal_eta", "eta;#eta;Events", n_eta_bins, &m_eta_bins[0]);
    h_signal_d0pvtx         = new TH1F("h_signal_d0pvtx", "d0pvtx", 100, -0.15, 0.15);
    h_signal_sigd0          = new TH1F("h_signal_sigd0", "sigd0", 100, 0, 10);
    h_signal_d0err          = new TH1F("h_signal_d0err", "d0err", 100, -0.1, 0.1);
    h_signal_z0sinTheta     = new TH1F("h_signal_z0SinTheta", "fabs(z0sinTheta)", 100, 0, 0.5);
    h_signal_ptvarcone20    = new TH1F("h_signal_ptvarcone20", "ptvarcone20", 100, 0, 0.2);
    h_signal_ptvarcone30    = new TH1F("h_signal_ptvarcone30", "ptvarcone30", 100, 0, 0.2);
    h_signal_topoetcone20   = new TH1F("h_signal_topoetcone20", "topoetcone20", 100, 0, 0.2);
    h_signal_nJets          = new TH1F("h_signal_nJets", "NJet", n_NJet_bins, &m_NJet_bins[0]);
    h_signal_dRjet          = new TH1F("h_signal_dRjet", "dRjet", n_deltaR_bins, &m_deltaR_bins[0]);
    h_signal_Etmiss         = new TH1F("h_signal_Etmiss", "Etmiss", n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_signal_meff           = new TH1F("h_signal_meff", "meff", n_meff_bins, &m_meff_bins[0]);

    h_signal_mll->Sumw2();
    h_signal_pt->Sumw2();
    h_signal_eta->Sumw2();
    h_signal_d0pvtx->Sumw2();
    h_signal_sigd0->Sumw2();
    h_signal_d0err->Sumw2();
    h_signal_z0sinTheta->Sumw2();
    h_signal_ptvarcone20->Sumw2();
    h_signal_ptvarcone30->Sumw2();
    h_signal_topoetcone20->Sumw2();
    h_signal_nJets->Sumw2();
    h_signal_dRjet->Sumw2();
    h_signal_Etmiss->Sumw2();
    h_signal_meff->Sumw2();

    wk()->addOutput(h_signal_mll);
    wk()->addOutput(h_signal_pt);
    wk()->addOutput(h_signal_eta);
    wk()->addOutput(h_signal_d0pvtx);
    wk()->addOutput(h_signal_sigd0);
    wk()->addOutput(h_signal_d0err);
    wk()->addOutput(h_signal_z0sinTheta);
    wk()->addOutput(h_signal_ptvarcone20);
    wk()->addOutput(h_signal_ptvarcone30);
    wk()->addOutput(h_signal_topoetcone20);
    wk()->addOutput(h_signal_nJets);
    wk()->addOutput(h_signal_dRjet);
    wk()->addOutput(h_signal_Etmiss);
    wk()->addOutput(h_signal_meff);
   
    // 2-dim histograms
    h_signal_pt_eta     = new TH2F("h_signal_pt_eta", "p_{T} vs #eta;p_{T} [GeV];#eta", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0]);
    h_signal_pt_nJets   = new TH2F("h_signal_pt_nJets", "p_{T} vs NJet;p_{T} [GeV];NJet", n_pt_bins, &m_pt_bins[0], n_NJet_bins, &m_NJet_bins[0]);
    h_signal_pt_dRjet   = new TH2F("h_signal_pt_dRjet", "p_{T} vs dRjet;p_{T} [GeV];dRjet", n_pt_bins, &m_pt_bins[0], n_deltaR_bins, &m_deltaR_bins[0]);
    h_signal_pt_Etmiss  = new TH2F("h_signal_pt_Etmiss", "p_{T} vs Etmiss;p_{T} [GeV];Etmiss", n_pt_bins, &m_pt_bins[0], n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_signal_pt_meff    = new TH2F("h_signal_pt_meff", "p_{T} vs meff;p_{T} [GeV];meff", n_pt_bins, &m_pt_bins[0], n_meff_bins, &m_meff_bins[0]);

    h_signal_pt_eta->Sumw2();
    h_signal_pt_nJets->Sumw2();
    h_signal_pt_dRjet->Sumw2();
    h_signal_pt_Etmiss->Sumw2();
    h_signal_pt_meff->Sumw2();

    wk()->addOutput(h_signal_pt_eta);
    wk()->addOutput(h_signal_pt_nJets);
    wk()->addOutput(h_signal_pt_dRjet);
    wk()->addOutput(h_signal_pt_Etmiss);
    wk()->addOutput(h_signal_pt_meff);

    // 3-dim histograms
    h_signal_pt_eta_mll = new TH3F("h_signal_pt_eta_mll", "Signal 3-dim;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_signal_pt_eta_dRjet = new TH3F("h_signal_pt_eta_dRjet", "Signal 3-dim;p_{T} [GeV];#eta;#Delta R(#ell, jet)", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_deltaR_bins, &m_deltaR_bins[0]);
    h_signal_pt_dRjet_mll = new TH3F("h_signal_pt_dRjet_mll", "Signal 3-dim;p_{T} [GeV];#Delta R(#ell, jet);M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_deltaR_bins, &m_deltaR_bins[0], n_mll_bins, &m_mll_bins[0]);
    
    h_signal_pt_eta_mll->Sumw2();
    h_signal_pt_eta_dRjet->Sumw2();
    h_signal_pt_dRjet_mll->Sumw2();

    wk()->addOutput(h_signal_pt_eta_mll);
    wk()->addOutput(h_signal_pt_eta_dRjet);
    wk()->addOutput(h_signal_pt_dRjet_mll);

    // Cut efficiency histograms
    h_cut_eff_LooseAndBLayerLLH_to_MediumLLH = new TH1F("h_cut_eff_LooseAndBLayerLLH_to_MediumLLH", "LooseAndBLayerLLH_to_MediumLLH;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_cut_eff_CaloIso   = new TH1F("h_cut_eff_CaloIso", "CaloIso;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_cut_eff_TrackIso  = new TH1F("h_cut_eff_TrackIso", "TrackIso;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_cut_eff_Iso       = new TH1F("h_cut_eff_Iso", "Iso;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_cut_eff_z0        = new TH1F("h_cut_eff_z0", "z0;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_cut_eff_sigd0     = new TH1F("h_cut_eff_sigd0", "sigd0;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);

    wk()->addOutput(h_cut_eff_LooseAndBLayerLLH_to_MediumLLH);
    wk()->addOutput(h_cut_eff_CaloIso);
    wk()->addOutput(h_cut_eff_TrackIso);
    wk()->addOutput(h_cut_eff_Iso);
    wk()->addOutput(h_cut_eff_z0);
    wk()->addOutput(h_cut_eff_sigd0);

    // Background template histograms
    h_bkg_template_fail_truth           = new TH1F("h_bkg_template_fail_truth", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_only         = new TH1F("h_bkg_template_fail_id_only", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_CaloIso_only    = new TH1F("h_bkg_template_fail_CaloIso_only", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_TrackIso_only   = new TH1F("h_bkg_template_fail_TrackIso_only", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso  = new TH1F("h_bkg_template_fail_id_and_CaloIso", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_TrackIso = new TH1F("h_bkg_template_fail_id_and_TrackIso", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso         = new TH1F("h_bkg_template_fail_id_and_CaloIso_and_TrackIso", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight   = new TH1F("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_CaloIso_and_TrackIso                = new TH1F("h_bkg_template_fail_CaloIso_and_TrackIso", "mll;M_{ll} [GeV];Events;", n_mll_bins, &m_mll_bins[0]);

    wk()->addOutput(h_bkg_template_fail_truth);
    wk()->addOutput(h_bkg_template_fail_id_only);
    wk()->addOutput(h_bkg_template_fail_CaloIso_only);
    wk()->addOutput(h_bkg_template_fail_TrackIso_only);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso);
    wk()->addOutput(h_bkg_template_fail_id_and_TrackIso);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso_and_TrackIso);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight);
    wk()->addOutput(h_bkg_template_fail_CaloIso_and_TrackIso);

    h_bkg_template_fail_truth_pt_eta_mll = new TH3F("h_bkg_template_fail_truth_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_only_pt_eta_mll = new TH3F("h_bkg_template_fail_id_only_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_CaloIso_only_pt_eta_mll = new TH3F("h_bkg_template_fail_CaloIso_only_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_TrackIso_only_pt_eta_mll = new TH3F("h_bkg_template_fail_TrackIso_only_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso_pt_eta_mll = new TH3F("h_bkg_template_fail_id_and_CaloIso_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_TrackIso_pt_eta_mll = new TH3F("h_bkg_template_fail_id_and_TrackIso_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll = new TH3F("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll = new TH3F("h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);
    h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll = new TH3F("h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll", "mll;p_{T} [GeV];#eta;M_{ll} [GeV]", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0], n_mll_bins, &m_mll_bins[0]);

    wk()->addOutput(h_bkg_template_fail_truth_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_id_only_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_CaloIso_only_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_TrackIso_only_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_id_and_TrackIso_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll);
    wk()->addOutput(h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll);

    // Real lepton efficiency histograms
    // 1-dim histograms
    h_eff_pt        = new TH1F("h_eff_pt", "eff_pt;p_{T} [GeV];Efficiency", n_pt_bins, &m_pt_bins[0]);
    h_eff_eta       = new TH1F("h_eff_eta", "eff_eta;|#eta|;Efficiency", n_eta_bins, &m_eta_bins[0]);
    h_eff_nJets     = new TH1F("h_eff_nJets", "eff_nJet;NJet;Efficiency", n_NJet_bins, &m_NJet_bins[0]);
    h_eff_dRjet     = new TH1F("h_eff_dRjet", "eff_dRjet;dRjet;Efficiency", n_deltaR_bins, &m_deltaR_bins[0]);
    h_eff_Etmiss    = new TH1F("h_eff_Etmiss", "eff_Etmiss;Etmiss;Efficiency", n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_eff_meff      = new TH1F("h_eff_meff", "eff_meff;meff;Efficiency", n_meff_bins, &m_meff_bins[0]);

    wk()->addOutput(h_eff_pt);
    wk()->addOutput(h_eff_eta);
    wk()->addOutput(h_eff_nJets);
    wk()->addOutput(h_eff_dRjet);
    wk()->addOutput(h_eff_Etmiss);
    wk()->addOutput(h_eff_meff);

    // 2-dim histograms
    h_2d_eff_pt_eta     = new TH2F("h_2d_eff_pt_eta", "eff_pt_eta;p_{T} [GeV];#eta;Efficiency", n_pt_bins, &m_pt_bins[0], n_eta_bins, &m_eta_bins[0]);
    h_2d_eff_pt_nJets   = new TH2F("h_2d_eff_pt_nJets", "eff_pt_nJets;p_{T} [GeV];NJet;Efficiency", n_pt_bins, &m_pt_bins[0], n_NJet_bins, &m_NJet_bins[0]);
    h_2d_eff_pt_dRjet   = new TH2F("h_2d_eff_pt_dRjet", "eff_pt_dRjet;p_{T} [GeV];dRjet;Efficiency", n_pt_bins, &m_pt_bins[0], n_deltaR_bins, &m_deltaR_bins[0]);
    h_2d_eff_pt_Etmiss  = new TH2F("h_2d_eff_pt_Etmiss", "eff_pt_Etmiss;p_{T} [GeV];Etmiss;Efficiency", n_pt_bins, &m_pt_bins[0], n_Etmiss_bins, &m_Etmiss_bins[0]);
    h_2d_eff_pt_meff    = new TH2F("h_2d_eff_pt_meff", "eff_pt_meff;p_{T} [GeV];meff;Efficiency", n_pt_bins, &m_pt_bins[0], n_meff_bins, &m_meff_bins[0]);

    wk()->addOutput(h_2d_eff_pt_eta);
    wk()->addOutput(h_2d_eff_pt_nJets);
    wk()->addOutput(h_2d_eff_pt_dRjet);
    wk()->addOutput(h_2d_eff_pt_Etmiss);
    wk()->addOutput(h_2d_eff_pt_meff);

    return EL::StatusCode::SUCCESS;
}




EL::StatusCode ytRealLeptonsEfficiency::fileExecute ()
{
    // Here you do everything that needs to be done exactly once for every
    // single file, e.g. collect a list of all lumi-blocks processed

    //const char * function_name = "fileExecute()";
    //Info(function_name, "Function calls");

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode ytRealLeptonsEfficiency::changeInput (bool firstFile)
{
    // Here you do everything you need to do when we change input files,
    // e.g. resetting branch addresses on trees.  If you are using
    // D3PDReader or a similar service this method is not needed.

    //const char * function_name = "changeInput()";
    //Info(function_name, "Function calls");

    //Init (wk()->tree());
    //wk()->tree();
    return EL::StatusCode::SUCCESS;
}




EL::StatusCode ytRealLeptonsEfficiency::initialize ()
{
    // Here you do everything that you need to do after the first input
    // file has been connected and before the first event is processed,
    // e.g. create additional histograms based on which variables are
    // available in the input files.  You can also create all of your
    // histograms and trees in here, but be aware that this method
    // doesn't get called if no events are processed.  So any objects
    // you create here won't be available in the output if you have no
    // input events.

    //const char * function_name = "initialize()";
    //Info(function_name, "Function calls");

    // Set object pointer

    // Set branch addresses and branch pointers
    fChain = wk()->tree();
    fChain->SetMakeClass(1);

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode ytRealLeptonsEfficiency::execute ()
{
    // Here you do everything that needs to be done on every single
    // events, e.g. read input variables, apply cuts, and fill
    // histograms and trees.  This is where most of your actual analysis
    // code will go.

    //const char * function_name = "execute()";
    //Info(function_name, "Function calls");

    wk()->tree()->GetEntry(wk()->treeEntry());

    double weight = 1;
    if (isMC) {
        // Applying the pile-up weights
        weight = normalization * pileup_weight;
    }
    h_AvgMu->Fill(AvgMu, weight);
    h_mll->Fill(mll / 1000., weight);
    h_zPV->Fill(PV_z, weight);

    // Loop over all leptons
    if (lepton == "electron") {
        // tag leptons must satisfy single lepton trigger requirement.
        // single lepton triggers:
        if (trigger == "single_lepton_trigger") {
            // Electron: e24_lhmedium_L1EM20VH (2015)
            //           e24_lhtight_nod0_ivarloose (2016)
            if (RunNb < 290000) { // 2015 data
                if (!HLT_e24_lhmedium_L1EM20VH)
                    return EL::StatusCode::SUCCESS; // Go to next event
            }
            else if (RunNb > 290000) { // 2016 data
                if (!HLT_e24_lhtight_nod0_ivarloose)
                    return EL::StatusCode::SUCCESS; // Go to next event
            }
        }
        else if (trigger == "dilepton_trigger") {
            // do something here.
        }
        else if (trigger == "dilepton_trigger_but_fail_single_lepton_trigger") {
            // do something here.
        }
        else if (trigger == "other_trigger") {
            // do something here.
        }
        this->loop_over_electrons();
    }
    else if (lepton == "muon") {
        // tag leptons must satisfy single lepton trigger requirement.
        // single lepton triggers:
        if (trigger == "single_lepton_trigger") {
            // Muon: mu20_iloose_L1MU15 (2015)
            //       mu24_ivarmedium (2016)
            if (RunNb < 290000) { // 2015 data
                if (!HLT_mu20_iloose_L1MU15)
                    return EL::StatusCode::SUCCESS; // Go to next event
            }
            else if (RunNb > 290000) { // 2016 data
                if (!HLT_mu24_ivarmedium)
                    return EL::StatusCode::SUCCESS; // Go to next event
            }
        }
        else if (trigger == "dilepton_trigger") {
            // do something here.
        }
        else if (trigger == "dilepton_trigger_but_fail_single_lepton_trigger") {
            // do something here.
        }
        else if(trigger == "other_trigger") {
            // do something here.
        }
        this->loop_over_muons();
    }

    // Calculate the cut efficiency
    // option="B": Binomial errors are computed
    h_cut_eff_LooseAndBLayerLLH_to_MediumLLH->Divide(h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut, h_baseline_pt, 1, 1, "B");
    h_cut_eff_CaloIso->Divide(h_baseline_CaloIso_cut, h_baseline_pt, 1, 1, "B");
    h_cut_eff_TrackIso->Divide(h_baseline_TrackIso_cut, h_baseline_pt, 1, 1, "B");
    h_cut_eff_Iso->Divide(h_baseline_Iso_cut, h_baseline_pt, 1, 1, "B");
    h_cut_eff_z0->Divide(h_baseline_z0_cut, h_baseline_pt, 1, 1, "B");
    h_cut_eff_sigd0->Divide(h_baseline_sigd0_cut, h_baseline_pt, 1, 1, "B");

    // Calculate the real lepton efficiency
    h_eff_pt->Divide(h_signal_pt, h_baseline_pt, 1, 1, "B");
    h_eff_eta->Divide(h_signal_eta, h_baseline_eta, 1, 1, "B");
    h_eff_nJets->Divide(h_signal_nJets, h_baseline_nJets, 1, 1, "B");
    h_eff_dRjet->Divide(h_signal_dRjet, h_baseline_dRjet, 1, 1, "B");
    h_eff_Etmiss->Divide(h_signal_Etmiss, h_baseline_Etmiss, 1, 1, "B");
    h_eff_meff->Divide(h_signal_meff, h_baseline_meff, 1, 1, "B");

    h_2d_eff_pt_eta->Divide(h_signal_pt_eta, h_baseline_pt_eta,1, 1, "B");
    h_2d_eff_pt_nJets->Divide(h_signal_pt_nJets, h_baseline_pt_nJets,1, 1, "B");
    h_2d_eff_pt_dRjet->Divide(h_signal_pt_dRjet, h_baseline_pt_dRjet,1, 1, "B");
    h_2d_eff_pt_Etmiss->Divide(h_signal_pt_Etmiss, h_baseline_pt_Etmiss,1, 1, "B");
    h_2d_eff_pt_meff->Divide(h_signal_pt_meff, h_baseline_pt_meff,1, 1, "B");

    return EL::StatusCode::SUCCESS;
}




EL::StatusCode ytRealLeptonsEfficiency::postExecute ()
{
    // Here you do everything that needs to be done after the main event
    // processing.  This is typically very rare, particularly in user
    // code.  It is mainly used in implementing the NTupleSvc.

    //const char * function_name = "postExecute()";
    //Info(function_name, "Function calls");

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode ytRealLeptonsEfficiency::finalize ()
{
    // This method is the mirror image of initialize(), meaning it gets
    // called after the last event has been processed on the worker node
    // and allows you to finish up any objects you created in
    // initialize() before they are written to disk.  This is actually
    // fairly rare, since this happens separately for each worker node.
    // Most of the time you want to do your post-processing on the
    // submission node after all your histogram outputs have been
    // merged.  This is different from histFinalize() in that it only
    // gets called on worker nodes that processed input events.

    //const char * function_name = "finalize()";
    //Info(function_name, "Function calls");

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode ytRealLeptonsEfficiency::histFinalize ()
{
    // This method is the mirror image of histInitialize(), meaning it
    // gets called after the last event has been processed on the worker
    // node and allows you to finish up any objects you created in
    // histInitialize() before they are written to disk.  This is
    // actually fairly rare, since this happens separately for each
    // worker node.  Most of the time you want to do your
    // post-processing on the submission node after all your histogram
    // outputs have been merged.  This is different from finalize() in
    // that it gets called on all worker nodes regardless of whether
    // they processed input events.

    //const char * function_name = "histFinalize()";
    //Info(function_name, "Function calls");

    this->make_baseline_mll_plot();
    this->make_cut_efficiency_plot();

    if (lepton == "electron") {
        this->make_electron_real_efficiency_plot();
    }
    if (lepton == "muon") {
        this->make_muon_real_efficiency_plot();
    }

    return EL::StatusCode::SUCCESS;
}



void ytRealLeptonsEfficiency::set_binning_default()
{
    m_mll_bins      = vector<float> (m_default_mll_bins, m_default_mll_bins + sizeof(m_default_mll_bins) / sizeof(float));
    m_pt_bins       = vector<float> (m_default_pt_bins, m_default_pt_bins + sizeof(m_default_pt_bins) / sizeof(float));
    m_eta_bins      = vector<float> (m_default_eta_bins, m_default_eta_bins + sizeof(m_default_eta_bins) / sizeof(float));
    m_deltaR_bins   = vector<float> (m_default_deltaR_bins, m_default_deltaR_bins + sizeof(m_default_deltaR_bins) / sizeof(float));
    m_NJet_bins     = vector<float> (m_default_NJet_bins, m_default_NJet_bins + sizeof(m_default_NJet_bins) / sizeof(float));
    m_Etmiss_bins   = vector<float> (m_default_Etmiss_bins, m_default_Etmiss_bins + sizeof(m_default_Etmiss_bins) / sizeof(float));
    m_meff_bins     = vector<float> (m_default_meff_bins, m_default_meff_bins + sizeof(m_default_meff_bins) / sizeof(float));
}



void ytRealLeptonsEfficiency::set_binning(int n, const float *bins, vector<float> &vec)
{
    vec.clear();
    for (int i = 0; i < n; i++) {
        vec.push_back(bins[i]);
    }
}



void ytRealLeptonsEfficiency::loop_over_electrons()
{
    for (int n_el = 0; n_el < NEl; n_el++) {
        if (!El_isBaseline->at(n_el)) // reject non baseline electrons
            continue;
        // All the electrons here are baseline electrons

        // Truth match (only apply on the non Z MC, such as Gtt and ttbar).
        // We want to keep isolated Electron (2) and these isolated electrons must come from top (10), W bosons (12), and Z bosons (13).
        bool truth_match = false;
        if (process == "GG_ttn1") {
            if (El_type->at(n_el) == 2 ||
                (El_type->at(n_el) == 4 && (El_bkgOrigin->at(n_el) == 10 || El_bkgOrigin->at(n_el) == 12 || El_bkgOrigin->at(n_el) == 13 || El_bkgOrigin->at(n_el) == 40)))
                // the bkgOriginal is related charge filp. Ximo said just add the requirements at here.
                truth_match = true;
        }
        else { // process != GG_ttn1
            if ((El_type->at(n_el) == 2 && (El_origin->at(n_el) == 10 || El_origin->at(n_el) == 12 || El_origin->at(n_el) == 13)) ||
                (El_type->at(n_el) == 4 && (El_bkgOrigin->at(n_el) == 10 || El_bkgOrigin->at(n_el) == 12 || El_bkgOrigin->at(n_el) == 13 || El_bkgOrigin->at(n_el) == 40)))
                // the bkgOriginal is related charge filp. Ximo said just add the requirements at here.
                truth_match = true;
        }

        // Trigger matching

        // Background template
        double calo_isolation = El_topoetcone20->at(n_el) / El_pT->at(n_el);
        double track_isolation = El_ptvarcone20->at(n_el) / El_pT->at(n_el);

        if (!truth_match) {
            //h_bkg_template_fail_truth->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            //h_bkg_template_fail_truth_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., El_eta->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            h_bkg_template_fail_truth->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight); 
            h_bkg_template_fail_truth_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        }
        if (!El_isMediumLH->at(n_el)) { // Background template requires the electron object fails the MediumLLH
            //h_bkg_template_fail_id_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            //h_bkg_template_fail_id_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., El_eta->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            h_bkg_template_fail_id_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_id_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            // reverse calo isolation
            if (calo_isolation > 0.10) {
                //h_bkg_template_fail_id_and_CaloIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                //h_bkg_template_fail_id_and_CaloIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., El_eta->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                h_bkg_template_fail_id_and_CaloIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            }
            // reverse track isolation
            if (track_isolation > 0.06) {
                //h_bkg_template_fail_id_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                //h_bkg_template_fail_id_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                h_bkg_template_fail_id_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight); 
            }
            // reverse calo and track isolation (baseline bkg template)
            if (calo_isolation > 0.15 &&
                track_isolation > 0.08) {
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            }
            // reverse calo and track isolation with tighter requirements (variation2 bkg template)
            if (calo_isolation > 0.20 &&
                track_isolation > 0.15) {
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            }
        }
        // reverse calo isolation
        if (calo_isolation > 0.20) {
            //h_bkg_template_fail_CaloIso_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            //h_bkg_template_fail_CaloIso_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            h_bkg_template_fail_CaloIso_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_CaloIso_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        }
        // reverse track isolation
        if (track_isolation > 0.15) {
            //h_bkg_template_fail_TrackIso_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            //h_bkg_template_fail_TrackIso_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            h_bkg_template_fail_TrackIso_only->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_TrackIso_only_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        }
        // reverse calo and track isolation only (variation1 bkg template)
        if (calo_isolation > 0.06 &&
            track_isolation > 0.06) {
            //h_bkg_template_fail_CaloIso_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            //h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
            h_bkg_template_fail_CaloIso_and_TrackIso->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        }

        // mll window
/*
        h_baseline_mll->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
        h_baseline_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwLooseAndBLayerLH->at(n_el));
        if (El_isSignal->at(n_el)) {
            h_signal_mll->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwMediumLH->at(n_el) * El_IsoSFwMediumLH->at(n_el));
            h_signal_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * El_SFwMediumLH->at(n_el) * El_IsoSFwMediumLH->at(n_el));
        }
*/
        h_baseline_mll->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        if (El_isSignal->at(n_el)) {
            h_signal_mll->Fill(El_ZTandP_mll->at(n_el) / 1000., normalization * signal_weight);
            h_signal_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_ZTandP_mll->at(n_el) / 1000., normalization * signal_weight);
        }

        if (process == "Zee") {
            // Use probe electron only
            if (!El_isZProbe->at(n_el))
                continue;
        }
        else if (process == "Zee_TandP_truth_matched") {
            // Use truth match on top of probe electron
            if (!El_isZProbe->at(n_el))
                continue;
            if (!truth_match)
                continue;
        }
        else { // process == "GG_ttn1" || process == "ttbar" || process == "Zee_truth_match" || process == "Zmumu_truth_match"
            // Use truth match
            //cout << "process is " << process << endl;
            if (!truth_match)
                continue;
        }
/*
        // Define weight
        double baseline_weight = 1.0;
        double signal_weight = 1.0;

        baseline_weight = normalization * El_tag_trigger_SF->at(n_el) * El_SFwLooseAndBLayerLH->at(n_el);
        signal_weight = normalization * El_tag_trigger_SF->at(n_el) * El_SFwMediumLH->at(n_el) * El_IsoSFwMediumLH->at(n_el);
*/
        // 1-dim histograms
        //h_baseline_mll->Fill(El_ZTandP_mll->at(n_el) / 1000.);
        h_baseline_pt->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_eta->Fill(fabs(El_eta->at(n_el)), normalization * baseline_weight);
        h_baseline_d0pvtx->Fill(El_d0pvtx->at(n_el), normalization * baseline_weight);
        h_baseline_sigd0->Fill(El_sigd0->at(n_el), normalization * baseline_weight);
        h_baseline_d0err->Fill(El_d0pvtx->at(n_el) / El_sigd0->at(n_el), normalization * baseline_weight);
        h_baseline_z0sinTheta->Fill(El_z0sinTheta->at(n_el), normalization * baseline_weight);
        h_baseline_ptvarcone20->Fill(El_ptvarcone20->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_ptvarcone30->Fill(El_ptvarcone30->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_topoetcone20->Fill(El_topoetcone20->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_nJets->Fill(NJet, normalization * baseline_weight);
        h_baseline_dRjet->Fill(El_DR_closest_Jet->at(n_el), normalization * baseline_weight);
        h_baseline_Etmiss->Fill(Etmiss_TST_Et / 1000., normalization * baseline_weight);
        h_baseline_meff->Fill(meff / 1000., normalization * baseline_weight);
        // 2-dim histograms
        h_baseline_pt_eta->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), normalization * baseline_weight);
        h_baseline_pt_nJets->Fill(El_pT->at(n_el) / 1000., NJet, normalization * baseline_weight);
        h_baseline_pt_dRjet->Fill(El_pT->at(n_el) / 1000., El_DR_closest_Jet->at(n_el), normalization * baseline_weight);
        h_baseline_pt_Etmiss->Fill(El_pT->at(n_el) / 1000., Etmiss_TST_Et / 1000., normalization * baseline_weight);
        h_baseline_pt_meff->Fill(El_pT->at(n_el) / 1000., meff / 1000., normalization * baseline_weight);
        // 3-dim histograms
        //h_baseline_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., El_eta->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        h_baseline_pt_eta_dRjet->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_DR_closest_Jet->at(n_el), normalization * baseline_weight);
        h_baseline_pt_dRjet_mll->Fill(El_pT->at(n_el) / 1000., El_DR_closest_Jet->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * baseline_weight);
        // Apply MediumLLH
        if (El_isMediumLH->at(n_el)) {
            h_baseline_LooseAndBLayerLLH_to_MediumLLH_cut->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        }
        // Apply topoetcone20/pt < 0.06
        if ((El_topoetcone20->at(n_el) /  El_pT->at(n_el)) < 0.06) {
            h_baseline_CaloIso_cut->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        }
        // Apply ptvarcone20/pt < 0.06
        if ((El_ptvarcone20->at(n_el) / El_pT->at(n_el)) < 0.06) {
            h_baseline_TrackIso_cut->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        }
        // Apply topoetcone20/pt < 0.06 && ptvarcone20/pt < 0.06 at the same time
        if ((El_topoetcone20->at(n_el) /  El_pT->at(n_el)) < 0.06 &&
            (El_ptvarcone20->at(n_el) / El_pT->at(n_el)) < 0.06) {
            h_baseline_Iso_cut->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        }
        // Apply |z0*sin(theta)| < 0.5
        if (fabs(El_z0sinTheta->at(n_el)) < 0.5) {
            h_baseline_z0_cut->Fill(El_pT->at(n_el) / 1000., normalization * baseline_weight);
        }

        // All the electrons here are signal electrons
        if (El_isSignal->at(n_el)) {
            // 1-dim histograms
            //h_signal_mll->Fill(El_ZTandP_mll->at(n_el) / 1000.);
            h_signal_pt->Fill(El_pT->at(n_el) / 1000., normalization * signal_weight);
            h_signal_eta->Fill(fabs(El_eta->at(n_el)), normalization * signal_weight);
            h_signal_d0pvtx->Fill(El_d0pvtx->at(n_el), normalization * signal_weight);
            h_signal_sigd0->Fill(El_sigd0->at(n_el), normalization * signal_weight);
            h_signal_d0err->Fill(El_d0pvtx->at(n_el) / El_sigd0->at(n_el), normalization * signal_weight);
            h_signal_z0sinTheta->Fill(El_z0sinTheta->at(n_el), normalization * signal_weight);
            h_signal_ptvarcone20->Fill(El_ptvarcone20->at(n_el) / 1000., normalization * signal_weight);
            h_signal_ptvarcone30->Fill(El_ptvarcone30->at(n_el) / 1000., normalization * signal_weight);
            h_signal_topoetcone20->Fill(El_topoetcone20->at(n_el) / 1000., normalization * signal_weight);
            h_signal_nJets->Fill(NJet, normalization * signal_weight);
            h_signal_dRjet->Fill(El_DR_closest_Jet->at(n_el), normalization * signal_weight);
            h_signal_Etmiss->Fill(Etmiss_TST_Et / 1000., normalization * signal_weight);
            h_signal_meff->Fill(meff / 1000., normalization * signal_weight);
            // 2-dim histograms
            h_signal_pt_eta->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), normalization * signal_weight);
            h_signal_pt_nJets->Fill(El_pT->at(n_el) / 1000., NJet, normalization * signal_weight);
            h_signal_pt_dRjet->Fill(El_pT->at(n_el) / 1000., El_DR_closest_Jet->at(n_el), normalization * signal_weight);
            h_signal_pt_Etmiss->Fill(El_pT->at(n_el) / 1000.,Etmiss_TST_Et / 1000., normalization * signal_weight);
            h_signal_pt_meff->Fill(El_pT->at(n_el) / 1000., meff / 1000., normalization * signal_weight);
            // 3-dim histograms
            //h_signal_pt_eta_mll->Fill(El_pT->at(n_el) / 1000., El_eta->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * signal_weight);
            h_signal_pt_eta_dRjet->Fill(El_pT->at(n_el) / 1000., fabs(El_eta->at(n_el)), El_DR_closest_Jet->at(n_el), normalization * signal_weight);
            h_signal_pt_dRjet_mll->Fill(El_pT->at(n_el) / 1000., El_DR_closest_Jet->at(n_el), El_ZTandP_mll->at(n_el) / 1000., normalization * signal_weight);
        }
    }
}



void ytRealLeptonsEfficiency_MC :: loop_over_muons()
{
    for (int n_mu = 0; n_mu < NMu; n_mu++) {
        if (!Mu_isBaseline->at(n_mu)) // reject non baseline muons
            continue;
        // All the muons here are baseline muons

        // Truth match (only apply on the non Z MC, such as Gtt and ttbar).
        // We want to keep isolated Muons (6) and these isolated muons must come from top (10), W bosons (12), and Z bosons (13).
        bool truth_match = false;
        if (process == "GG_ttn1") {
            if (Mu_type->at(n_mu) == 6)
                truth_match = true;
        }
        else { // process != GG_ttn1
            if (Mu_type->at(n_mu) == 6 &&
                (Mu_origin->at(n_mu) == 10 || Mu_origin->at(n_mu) == 12 || Mu_origin->at(n_mu) == 13))
                truth_match = true;
        }

        // Trigger matching

        // Background template
        double calo_isolation = Mu_topoetcone20->at(n_mu) / Mu_pT->at(n_mu);
        double track_isolation = Mu_ptvarcone20->at(n_mu) / Mu_pT->at(n_mu);
        
        if (!truth_match) {
            //h_bkg_template_fail_truth->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            //h_bkg_template_fail_truth_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            h_bkg_template_fail_truth->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_truth_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        }
/*
        if (!Mu_isMediumLH->at(n_mu)) { // Background template requires the electron object fails the MediumLLH
            //h_bkg_template_fail_id_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            //h_bkg_template_fail_id_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            h_bkg_template_fail_id_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_id_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            // reverse calo isolation
            if (calo_isolation > 0.10) {
                //h_bkg_template_fail_id_and_CaloIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                //h_bkg_template_fail_id_and_CaloIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                h_bkg_template_fail_id_and_CaloIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            }
            // reverse track isolation
            if (track_isolation > 0.06) {
                //h_bkg_template_fail_id_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                //h_bkg_template_fail_id_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                h_bkg_template_fail_id_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            }
            // reverse calo and track isolation (baseline bkg template)
            if (calo_isolation > 0.15 &&
                track_isolation > 0.08) {
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            }
            // reverse calo and track isolation with tighter requirements (variation2 bkg template)
            if (calo_isolation > 0.20 &&
                track_isolation > 0.15) {
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                //h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
                h_bkg_template_fail_id_and_CaloIso_and_TrackIso_tight_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            }
        }
*/
        // reverse calo isolation
        if (calo_isolation > 0.20) {
            //h_bkg_template_fail_CaloIso_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            //h_bkg_template_fail_CaloIso_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            h_bkg_template_fail_CaloIso_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_CaloIso_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        }
        // reverse track isolation
        if (track_isolation > 0.15) {
            //h_bkg_template_fail_TrackIso_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            //h_bkg_template_fail_TrackIso_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            h_bkg_template_fail_TrackIso_only->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_TrackIso_only_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        }
        // reverse calo and track isolation only (variation1 bkg template)
        if (calo_isolation > 0.06 &&
            track_isolation > 0.06) {
            //h_bkg_template_fail_CaloIso_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            //h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
            h_bkg_template_fail_CaloIso_and_TrackIso->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
            h_bkg_template_fail_CaloIso_and_TrackIso_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        }

        // mll window
/*
        h_baseline_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
        h_baseline_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu));
        if (Mu_isSignal->at(n_mu)) {
            h_signal_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu) * Mu_IsoSFw->at(n_mu));
            h_signal_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * Mu_SFw->at(n_mu) * Mu_IsoSFw->at(n_mu));
        }
*/
        h_baseline_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        if (Mu_isSignal->at(n_mu)) {
            h_signal_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * signal_weight);
        }

        if (process == "Zmumu") {
            // Use probe muons only
            if (!Mu_isZProbe->at(n_mu))
                continue;
        }
        else if (process == "Zmumu_TandP_truth_matched") {
            // Use truth match on top of probe electron
            if (!Mu_isZProbe->at(n_mu))
                continue;
            if (!truth_match)
                continue;
        }
        else { // process == "GG_ttn1" || process == "ttbar" || process == "Zee_truth_match" || process == "Zmumu_truth_match"
            // Use truth match
            //cout << "process is " << process << endl;
            if (!truth_match)
                continue;
        }
/*
        // Define weight
        double baseline_weight = 1.0;
        double signal_weight = 1.0;
        baseline_weight = normalization * Mu_tag_trigger_SF->at(n_mu) * Mu_SFw->at(n_mu);
        signal_weight = normalization * Mu_tag_trigger_SF->at(n_mu) * Mu_SFw->at(n_mu) * Mu_IsoSFw->at(n_mu);
*/
        // 1-dim histograms
        //h_baseline_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000.);
        h_baseline_pt->Fill(Mu_pT->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_eta->Fill(fabs(Mu_eta->at(n_mu)), normalization * baseline_weight);
        h_baseline_d0pvtx->Fill(Mu_d0pvtx->at(n_mu), normalization * baseline_weight);
        h_baseline_sigd0->Fill(Mu_sigd0->at(n_mu), normalization * baseline_weight);
        h_baseline_d0err->Fill(Mu_d0pvtx->at(n_mu) / Mu_sigd0->at(n_mu), normalization * baseline_weight);
        h_baseline_z0sinTheta->Fill(Mu_z0sinTheta->at(n_mu), normalization * baseline_weight);
        h_baseline_ptvarcone20->Fill(Mu_ptvarcone20->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_ptvarcone30->Fill(Mu_ptvarcone30->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_topoetcone20->Fill(Mu_topoetcone20->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_nJets->Fill(NJet, normalization * baseline_weight);
        h_baseline_dRjet->Fill(Mu_DR_closest_Jet->at(n_mu), normalization * baseline_weight);
        h_baseline_Etmiss->Fill(Etmiss_TST_Et / 1000., normalization * baseline_weight);
        h_baseline_meff->Fill(meff / 1000., normalization * baseline_weight);
        // 2-dim histograms
        h_baseline_pt_eta->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), normalization * baseline_weight);
        h_baseline_pt_nJets->Fill(Mu_pT->at(n_mu) / 1000., NJet, normalization * baseline_weight);
        h_baseline_pt_dRjet->Fill(Mu_pT->at(n_mu) / 1000., Mu_DR_closest_Jet->at(n_mu), normalization * baseline_weight);
        h_baseline_pt_Etmiss->Fill(Mu_pT->at(n_mu) / 1000.,Etmiss_TST_Et / 1000., normalization * baseline_weight);
        h_baseline_pt_meff->Fill(Mu_pT->at(n_mu) / 1000., meff / 1000., normalization * baseline_weight);
        // 3-dim histograms
        //h_baseline_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        h_baseline_pt_eta_dRjet->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_DR_closest_Jet->at(n_mu), normalization * baseline_weight);
        h_baseline_pt_dRjet_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_DR_closest_Jet->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * baseline_weight);
        // Apply ptvarcone30/pt < 0.06
        if ((Mu_ptvarcone30->at(n_mu) / Mu_pT->at(n_mu)) < 0.06) {
            h_baseline_TrackIso_cut->Fill(Mu_pT->at(n_mu) / 1000., normalization * baseline_weight);
        }
        // Apply |z0*sin(theta)| < 0.5
        if (fabs(Mu_z0sinTheta->at(n_mu)) < 0.5) {
            h_baseline_z0_cut->Fill(Mu_pT->at(n_mu) / 1000., normalization * baseline_weight);
        }
        // Apply |d0sig| < 3
        if (fabs(Mu_sigd0->at(n_mu)) < 3) {
            h_baseline_sigd0_cut->Fill(Mu_pT->at(n_mu) / 1000., normalization * baseline_weight);
        }

        // All the muons here are signal muons
        if (Mu_isSignal->at(n_mu)) {
            // 1-dim histograms
            h_signal_mll->Fill(Mu_ZTandP_mll->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_pt->Fill(Mu_pT->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_eta->Fill(fabs(Mu_eta->at(n_mu)), normalization * signal_weight);
            h_signal_d0pvtx->Fill(Mu_d0pvtx->at(n_mu), normalization * signal_weight);
            h_signal_sigd0->Fill(Mu_sigd0->at(n_mu), normalization * signal_weight);
            h_signal_d0err->Fill(Mu_d0pvtx->at(n_mu) / Mu_sigd0->at(n_mu), normalization * signal_weight);
            h_signal_z0sinTheta->Fill(Mu_z0sinTheta->at(n_mu), normalization * signal_weight);
            h_signal_ptvarcone20->Fill(Mu_ptvarcone20->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_ptvarcone30->Fill(Mu_ptvarcone30->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_topoetcone20->Fill(Mu_topoetcone20->at(n_mu) / 1000., normalization * signal_weight);
            h_signal_nJets->Fill(NJet, normalization * signal_weight);
            h_signal_dRjet->Fill(Mu_DR_closest_Jet->at(n_mu), normalization * signal_weight);
            h_signal_Etmiss->Fill(Etmiss_TST_Et / 1000., normalization * signal_weight);
            h_signal_meff->Fill(meff / 1000., normalization * signal_weight);
            // 2-dim histograms
            h_signal_pt_eta->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), normalization * signal_weight);
            h_signal_pt_nJets->Fill(Mu_pT->at(n_mu) / 1000., NJet, normalization * signal_weight);
            h_signal_pt_dRjet->Fill(Mu_pT->at(n_mu) / 1000., Mu_DR_closest_Jet->at(n_mu), normalization * signal_weight);
            h_signal_pt_Etmiss->Fill(Mu_pT->at(n_mu) / 1000.,Etmiss_TST_Et / 1000., normalization * signal_weight);
            h_signal_pt_meff->Fill(Mu_pT->at(n_mu) / 1000., meff / 1000., normalization * signal_weight);
            // 3-dim histograms
            //h_signal_pt_eta_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_eta->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., signal_weight);
            h_signal_pt_eta_dRjet->Fill(Mu_pT->at(n_mu) / 1000., fabs(Mu_eta->at(n_mu)), Mu_DR_closest_Jet->at(n_mu), normalization * signal_weight);
            h_signal_pt_dRjet_mll->Fill(Mu_pT->at(n_mu) / 1000., Mu_DR_closest_Jet->at(n_mu), Mu_ZTandP_mll->at(n_mu) / 1000., normalization * signal_weight);
        }
    }
}



void ytRealLeptonsEfficiency::make_baseline_mll_plot()
{
    baseline_mll_plot = new TCanvas("baseline_mll", "Baseline M_{ll}", 500, 500);
    baseline_mll_plot->cd();

    TH1F *h_mll = (TH1F *)h_baseline_pt_eta_mll->ProjectionZ("");
    h_mll->SetLineColor(kBlack);
    h_mll->SetMarkerColor(kBlack);
    h_mll->SetMarkerStyle(kFullCircle);
    h_mll->SetStats(kFALSE);
    h_mll->GetXaxis()->SetRangeUser(60, 150);
    h_mll->SetTitle("");
    h_mll->SetXTitle("M_{ll}");
    h_mll->SetYTitle("Number of probe leptos");
    h_mll->Draw();

    wk()->addOutput(baseline_mll_plot);
}



void ytRealLeptonsEfficiency::make_cut_efficiency_plot()
{
    cut_efficiency_plot = new TCanvas("cut_efficiency", "Cut efficiency comparison", 500, 500);
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

    wk()->addOutput(cut_efficiency_plot);
}



void ytRealLeptonsEfficiency::make_electron_real_efficiency_plot()
{
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

    TH1F *ratio_1 = (TH1F *)h_signal_eta_range_1->Clone();
    TH1F *ratio_2 = (TH1F *)h_signal_eta_range_2->Clone();
    TH1F *ratio_3 = (TH1F *)h_signal_eta_range_3->Clone();

    ratio_1->SetName("ratio_1");
    ratio_2->SetName("ratio_2");
    ratio_3->SetName("ratio_3");

    ratio_1->Divide(h_baseline_eta_range_1);
    ratio_2->Divide(h_baseline_eta_range_2);
    ratio_3->Divide(h_baseline_eta_range_3);

    real_efficiency_plot = new TCanvas("real_efficiency_plot", "Electron Real Efficiency", 500, 500);
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

    wk()->addOutput(real_efficiency_plot);
}



void ytRealLeptonsEfficiency::make_muon_real_efficiency_plot()
{
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

    real_efficiency_plot = new TCanvas("real_efficiency_plot", "Muon Real Efficiency", 500, 500);
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

    wk()->addOutput(real_efficiency_plot);
}