//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug  2 11:16:49 2016 by ROOT version 6.04/16
// from TTree AnaNtup/AnaNtup
// found on file: data_probes_all_periods.root
//////////////////////////////////////////////////////////

#ifndef Skimmed_Data_h
#define Skimmed_Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class Skimmed_Data : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Bool_t          HLT_e24_lhmedium_nod0_ivarloose;
   Bool_t          HLT_e24_lhtight_nod0_ivarloose;
   Bool_t          HLT_e24_lhmedium_nod0_L1EM20VH;
   Bool_t          HLT_e26_lhtight_iloose;
   Bool_t          HLT_e26_lhtight_ivarloose;
   Bool_t          HLT_e26_lhtight_nod0_iloose;
   Bool_t          HLT_e26_lhtight_nod0_ivarloose;
   Bool_t          HLT_e60_lhmedium;
   Bool_t          HLT_e60_lhmedium_nod0;
   Bool_t          HLT_e120_lhloose_nod0;
   Bool_t          HLT_e140_lhloose_nod0;
   Bool_t          HLT_2e17_lhvloose_nod0;
   Bool_t          HLT_2e15_lhvloose_nod0_L12EM13VH;
   Bool_t          HLT_e24_lhmedium_e9_lhmedium;
   Bool_t          HLT_e24_lhmedium_L1EM20VH;
   Bool_t          HLT_e12_lhvloose_L12EM10VH;
   Bool_t          HLT_e17_lhloose_2e9_lhloose;
   Bool_t          HLT_mu24_ivarmedium;
   Bool_t          HLT_mu24_imedium;
   Bool_t          HLT_mu24_ivarloose;
   Bool_t          HLT_mu24_iloose;
   Bool_t          HLT_mu26_ivarmedium;
   Bool_t          HLT_mu26_imedium;
   Bool_t          HLT_mu20_ivarmedium_L1MU15;
   Bool_t          HLT_mu20_imedium_L1MU15;
   Bool_t          HLT_mu20_ivarloose_L1MU15;
   Bool_t          HLT_mu20_iloose_L1MU15;
   Bool_t          HLT_mu20_L1MU15;
   Bool_t          HLT_mu20_mu8noL1;
   Bool_t          HLT_mu22_mu8noL1;
   Bool_t          HLT_mu20_2mu4noL1;
   Bool_t          HLT_mu22_2mu4noL1;
   Bool_t          HLT_mu40;
   Bool_t          HLT_mu50;
   Bool_t          HLT_2mu10;
   Bool_t          HLT_2mu10_nomucomb;
   Bool_t          HLT_2mu14;
   Bool_t          HLT_2mu14_nomucomb;
   Bool_t          HLT_3mu6;
   Bool_t          HLT_3mu6_msonly;
   Bool_t          HLT_xe100_L1XE50;
   Bool_t          HLT_xe80_mht_L1XE50;
   Bool_t          HLT_xe90_mht_L1XE50;
   Bool_t          HLT_xe100_mht_L1XE50;
   Bool_t          HLT_xe110_pueta_L1XE50;
   Bool_t          HLT_xe110_pufit_L1XE50;
   Bool_t          HLT_xe100_tc_em_L1XE50;
   Bool_t          HLT_xe80_tc_lcw_L1XE50;
   Bool_t          HLT_xe90_tc_lcw_L1XE50;
   Bool_t          HLT_xe80_tc_lcw_wEFMu_L1XE50;
   Bool_t          HLT_e7_lhmedium_mu24;
   Bool_t          HLT_e17_lhloose_nod0_mu14;
   Bool_t          HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;
   Bool_t          HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1;
   Bool_t          HLT_2e12_lhloose_L12EM10VH;
   Bool_t          HLT_e17_lhloose_mu14;
   Bool_t          HLT_mu18_mu8noL1;
   Bool_t          HLT_xe70;
   ULong64_t       EventNumber;
   Int_t           ChannelNumber;
   Double_t        AvgMu;
   Double_t        EventWeight;
   Double_t        PRWWeight;
   Int_t           PRWrandomRunNumber;
   Int_t           bcid;
   Int_t           LB;
   Int_t           RunNb;
   Int_t           DetError;
   Int_t           NMu;
   vector<double>  *Mu_eta;
   vector<double>  *Mu_phi;
   vector<double>  *Mu_pT;
   vector<double>  *Mu_SFw;
   vector<float>   *Mu_IsoSFw;
   vector<int>     *Mu_charge;
   vector<double>  *Mu_d0pvtx;
   vector<double>  *Mu_sigd0;
   vector<double>  *Mu_z0sinTheta;
   vector<bool>    *Mu_isBad;
   vector<bool>    *Mu_passOR;
   vector<bool>    *Mu_isTight;
   vector<bool>    *Mu_isCosmic;
   vector<double>  *Mu_ptcone20;
   vector<double>  *Mu_ptcone30;
   vector<double>  *Mu_ptcone40;
   vector<double>  *Mu_ptvarcone20;
   vector<double>  *Mu_ptvarcone30;
   vector<double>  *Mu_ptvarcone40;
   vector<double>  *Mu_topoetcone20;
   vector<double>  *Mu_topoetcone30;
   vector<double>  *Mu_topoetcone40;
   vector<bool>    *Mu_passIsoLooseTO;
   vector<bool>    *Mu_passIsoLoose;
   vector<bool>    *Mu_passIsoTight;
   vector<bool>    *Mu_passIsoGrad;
   vector<bool>    *Mu_passIsoGradCustomTight;
   vector<bool>    *Mu_passIsoGradCustom;
   vector<bool>    *Mu_passIsoGradLoose;
   Float_t         MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50;
   vector<bool>    *Mu_trigMatch_mu26_imedium;
   vector<bool>    *Mu_trigMatch_mu50;
   vector<bool>    *Mu_trigMatch_mu8noL1;
   vector<bool>    *Mu_trigMatch_mu14;
   vector<bool>    *Mu_trigMatch_mu18;
   vector<bool>    *Mu_trigMatch_mu18_mu8noL1;
   vector<bool>    *Mu_trigMatch_e17_lhloose_mu14;
   vector<bool>    *Mu_trigMatch_e17_lhloose_nod0_mu14;
   vector<bool>    *Mu_trigMatch_mu20_mu8noL1;
   vector<bool>    *Mu_trigMatch_mu22_mu8noL1;
   vector<bool>    *Mu_TrigMatch_mu24_iloose;
   vector<bool>    *Mu_TrigMatch_mu24_ivarloose;
   vector<bool>    *Mu_TrigMatch_mu24_iloose_L1MU15;
   vector<bool>    *Mu_TrigMatch_mu24_ivarloose_L1MU15;
   vector<vector<bool> > *Mu_trigMatchPair_mu18_mu8noL1;
   vector<vector<bool> > *Mu_trigMatchPair_mu20_mu8noL1;
   vector<vector<bool> > *Mu_trigMatchPair_mu22_mu8noL1;
   Int_t           NEl;
   vector<double>  *El_eta;
   vector<double>  *El_etaclus;
   vector<double>  *El_phi;
   vector<double>  *El_pT;
   vector<double>  *El_E;
   vector<int>     *El_charge;
   vector<double>  *El_sigd0;
   vector<double>  *El_z0sinTheta;
   vector<double>  *El_d0pvtx;
   vector<bool>    *El_passOR;
   vector<double>  *El_SFwMediumLH;
   vector<float>   *El_IsoSFwMediumLH;
   vector<double>  *El_SFwTightLH;
   vector<double>  *El_SFwLooseAndBLayerLH;
   vector<double>  *El_SFwTrigMediumLH_e12_lhloose_L1EM10VH;
   vector<double>  *El_SFwTrigMediumLH_e17_lhloose;
   vector<double>  *El_SFwTrigMediumLH_single;
   vector<double>  *El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH;
   vector<bool>    *El_isLooseAndBLayerLH;
   vector<bool>    *El_isMediumLH;
   vector<bool>    *El_isTightLH;
   vector<int>     *El_nBLayerHits;
   vector<int>     *El_expectBLayerHit;
   vector<double>  *El_ptcone20;
   vector<double>  *El_ptcone30;
   vector<double>  *El_ptcone40;
   vector<double>  *El_ptvarcone20;
   vector<double>  *El_ptvarcone30;
   vector<double>  *El_ptvarcone40;
   vector<double>  *El_topoetcone20;
   vector<double>  *El_topoetcone30;
   vector<double>  *El_topoetcone40;
   vector<bool>    *El_passIsoLooseTO;
   vector<bool>    *El_passIsoLoose;
   vector<bool>    *El_passIsoTight;
   vector<bool>    *El_passIsoGrad;
   vector<bool>    *El_passIsoGradCustomTight;
   vector<bool>    *El_passIsoGradCustom;
   vector<bool>    *El_passIsoGradLoose;
   vector<bool>    *El_trigMatch_e12_lhloose_L1EM10VH;
   vector<bool>    *El_trigMatch_e17_lhloose;
   vector<bool>    *El_trigMatch_e60_lhmedium;
   vector<bool>    *El_trigMatch_e24_lhmedium_iloose_L1EM20VH;
   vector<bool>    *El_trigMatch_2e12_lhloose_L12EM10VH;
   vector<bool>    *El_trigMatch_2e15_lhloose_L12EM10VH;
   vector<bool>    *El_trigMatch_2e15_lhvloose_L12EM13VH;
   vector<bool>    *El_trigMatch_2e15_lhvloose_nod0_L12EM13VH;
   vector<bool>    *El_trigMatch_2e17_lhvloose_nod0;
   vector<bool>    *El_trigMatch_e17_lhloose_mu14;
   vector<bool>    *El_trigMatch_e17_lhloose_nod0_mu14;
   vector<bool>    *El_TrigMatch_e24_lhmedium_nod0_ivarloose;
   vector<bool>    *El_TrigMatch_e24_lhtight_nod0_ivarloose;
   vector<bool>    *El_TrigMatch_e60_lhmedium_nod0;
   Int_t           NJet;
   vector<double>  *Jet_eta;
   vector<double>  *Jet_phi;
   vector<double>  *Jet_pT;
   vector<double>  *Jet_E;
   vector<double>  *Jet_quality;
   vector<double>  *Jet_JVT;
   vector<double>  *Jet_JVTsf;
   vector<double>  *Jet_MV2c20;
   vector<double>  *Jet_MV2c10;
   vector<double>  *Jet_SFw;
   vector<int>     *Jet_nTrk;
   vector<bool>    *Jet_passOR;
   Float_t         Etmiss_CST_Etx;
   Float_t         Etmiss_CST_Ety;
   Float_t         Etmiss_CST_Et;
   Float_t         Etmiss_TST_Etx;
   Float_t         Etmiss_TST_Ety;
   Float_t         Etmiss_TST_Et;
   Float_t         Etmiss_TSTterm_Etx;
   Float_t         Etmiss_TSTterm_Ety;
   Float_t         Etmiss_TSTterm_Et;
   Float_t         Etmiss_Truth_Etx;
   Float_t         Etmiss_Truth_Ety;
   Float_t         Etmiss_Truth_Et;
   Float_t         PV_z;
   Int_t           Nvtx;
   Float_t         TruthX1;
   Float_t         TruthX2;
   Float_t         TruthQ;
   Float_t         SherpaNjetWeight;
   Int_t           TruthPDGID1;
   Int_t           TruthPDGID2;
   vector<double>  *El_ZTandP_mll;
   vector<double>  *El_DR_closest_Jet;
   vector<bool>    *El_isBaseline;
   vector<bool>    *El_isSignal;
   vector<bool>    *El_isZProbe;
   vector<bool>    *El_isZProbe_TriggMatched;
   vector<bool>    *El_isTTbarProbe;
   vector<double>  *Mu_ZTandP_mll;
   vector<double>  *Mu_DR_closest_Jet;
   vector<bool>    *Mu_isBaseline;
   vector<bool>    *Mu_isSignal;
   vector<bool>    *Mu_isZProbe;
   vector<bool>    *Mu_isZProbe_TriggMatched;
   vector<bool>    *Mu_isTTbarProbe;
   vector<bool>    *Jet_Jet_isSignal;
   vector<bool>    *Jet_bJet_isSignal;
   Bool_t          isSS2l_trigger;
   Double_t        baseline_mll;
   Double_t        mll;
   Double_t        mjj;
   Double_t        meff;
   Double_t        Ht;
   Double_t        mT;
   Int_t           nBaseLeps;
   Int_t           nSigLeps;
   Double_t        lep1Pt;
   Double_t        lep2Pt;
   Double_t        lep3Pt;
   Double_t        lep1Eta;
   Double_t        lep2Eta;
   Double_t        lep3Eta;
   Int_t           nSigBJets;
   Int_t           nSigJets;
   Double_t        jet1Pt;
   Double_t        jet2Pt;
   Double_t        jet3Pt;
   Bool_t          isSS2l;
   Int_t           baseline_channel;
   Int_t           channel;

   // List of branches
   TBranch        *b_HLT_e24_lhmedium_nod0_ivarloose;   //!
   TBranch        *b_HLT_e24_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e24_lhmedium_nod0_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhtight_iloose;   //!
   TBranch        *b_HLT_e26_lhtight_ivarloose;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_iloose;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_e120_lhloose_nod0;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_HLT_2e15_lhvloose_nod0_L12EM13VH;   //!
   TBranch        *b_HLT_e24_lhmedium_e9_lhmedium;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e12_lhvloose_L12EM10VH;   //!
   TBranch        *b_HLT_e17_lhloose_2e9_lhloose;   //!
   TBranch        *b_HLT_mu24_ivarmedium;   //!
   TBranch        *b_HLT_mu24_imedium;   //!
   TBranch        *b_HLT_mu24_ivarloose;   //!
   TBranch        *b_HLT_mu24_iloose;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_mu26_imedium;   //!
   TBranch        *b_HLT_mu20_ivarmedium_L1MU15;   //!
   TBranch        *b_HLT_mu20_imedium_L1MU15;   //!
   TBranch        *b_HLT_mu20_ivarloose_L1MU15;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu20_L1MU15;   //!
   TBranch        *b_HLT_mu20_mu8noL1;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_mu20_2mu4noL1;   //!
   TBranch        *b_HLT_mu22_2mu4noL1;   //!
   TBranch        *b_HLT_mu40;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_2mu10;   //!
   TBranch        *b_HLT_2mu10_nomucomb;   //!
   TBranch        *b_HLT_2mu14;   //!
   TBranch        *b_HLT_2mu14_nomucomb;   //!
   TBranch        *b_HLT_3mu6;   //!
   TBranch        *b_HLT_3mu6_msonly;   //!
   TBranch        *b_HLT_xe100_L1XE50;   //!
   TBranch        *b_HLT_xe80_mht_L1XE50;   //!
   TBranch        *b_HLT_xe90_mht_L1XE50;   //!
   TBranch        *b_HLT_xe100_mht_L1XE50;   //!
   TBranch        *b_HLT_xe110_pueta_L1XE50;   //!
   TBranch        *b_HLT_xe110_pufit_L1XE50;   //!
   TBranch        *b_HLT_xe100_tc_em_L1XE50;   //!
   TBranch        *b_HLT_xe80_tc_lcw_L1XE50;   //!
   TBranch        *b_HLT_xe90_tc_lcw_L1XE50;   //!
   TBranch        *b_HLT_xe80_tc_lcw_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_ChannelNumber;   //!
   TBranch        *b_AvgMu;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_PRWWeight;   //!
   TBranch        *b_PRWrandomRunNumber;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_LB;   //!
   TBranch        *b_RunNb;   //!
   TBranch        *b_DetError;   //!
   TBranch        *b_NMu;   //!
   TBranch        *b_Mu_eta;   //!
   TBranch        *b_Mu_phi;   //!
   TBranch        *b_Mu_pT;   //!
   TBranch        *b_Mu_SFw;   //!
   TBranch        *b_Mu_IsoSFw;   //!
   TBranch        *b_Mu_charge;   //!
   TBranch        *b_Mu_d0pvtx;   //!
   TBranch        *b_Mu_sigd0;   //!
   TBranch        *b_Mu_z0sinTheta;   //!
   TBranch        *b_Mu_isBad;   //!
   TBranch        *b_Mu_passOR;   //!
   TBranch        *b_Mu_isTight;   //!
   TBranch        *b_Mu_isCosmic;   //!
   TBranch        *b_Mu_ptcone20;   //!
   TBranch        *b_Mu_ptcone30;   //!
   TBranch        *b_Mu_ptcone40;   //!
   TBranch        *b_Mu_ptvarcone20;   //!
   TBranch        *b_Mu_ptvarcone30;   //!
   TBranch        *b_Mu_ptvarcone40;   //!
   TBranch        *b_Mu_topoetcone20;   //!
   TBranch        *b_Mu_topoetcone30;   //!
   TBranch        *b_Mu_topoetcone40;   //!
   TBranch        *b_Mu_passIsoLooseTO;   //!
   TBranch        *b_Mu_passIsoLoose;   //!
   TBranch        *b_Mu_passIsoTight;   //!
   TBranch        *b_Mu_passIsoGrad;   //!
   TBranch        *b_Mu_passIsoGradCustomTight;   //!
   TBranch        *b_Mu_passIsoGradCustom;   //!
   TBranch        *b_Mu_passIsoGradLoose;   //!
   TBranch        *b_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50;   //!
   TBranch        *b_Mu_trigMatch_mu26_imedium;   //!
   TBranch        *b_Mu_trigMatch_mu50;   //!
   TBranch        *b_Mu_trigMatch_mu8noL1;   //!
   TBranch        *b_Mu_trigMatch_mu14;   //!
   TBranch        *b_Mu_trigMatch_mu18;   //!
   TBranch        *b_Mu_trigMatch_mu18_mu8noL1;   //!
   TBranch        *b_Mu_trigMatch_e17_lhloose_mu14;   //!
   TBranch        *b_Mu_trigMatch_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_Mu_trigMatch_mu20_mu8noL1;   //!
   TBranch        *b_Mu_trigMatch_mu22_mu8noL1;   //!
   TBranch        *b_Mu_TrigMatch_mu24_iloose;   //!
   TBranch        *b_Mu_TrigMatch_mu24_ivarloose;   //!
   TBranch        *b_Mu_TrigMatch_mu24_iloose_L1MU15;   //!
   TBranch        *b_Mu_TrigMatch_mu24_ivarloose_L1MU15;   //!
   TBranch        *b_Mu_trigMatchPair_mu18_mu8noL1;   //!
   TBranch        *b_Mu_trigMatchPair_mu20_mu8noL1;   //!
   TBranch        *b_Mu_trigMatchPair_mu22_mu8noL1;   //!
   TBranch        *b_NEl;   //!
   TBranch        *b_El_eta;   //!
   TBranch        *b_El_etaclus;   //!
   TBranch        *b_El_phi;   //!
   TBranch        *b_El_pT;   //!
   TBranch        *b_El_E;   //!
   TBranch        *b_El_charge;   //!
   TBranch        *b_El_sigd0;   //!
   TBranch        *b_El_z0sinTheta;   //!
   TBranch        *b_El_d0pvtx;   //!
   TBranch        *b_El_passOR;   //!
   TBranch        *b_El_SFwMediumLH;   //!
   TBranch        *b_El_IsoSFwMediumLH;   //!
   TBranch        *b_El_SFwTightLH;   //!
   TBranch        *b_El_SFwLooseAndBLayerLH;   //!
   TBranch        *b_El_SFwTrigMediumLH_e12_lhloose_L1EM10VH;   //!
   TBranch        *b_El_SFwTrigMediumLH_e17_lhloose;   //!
   TBranch        *b_El_SFwTrigMediumLH_single;   //!
   TBranch        *b_El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH;   //!
   TBranch        *b_El_isLooseAndBLayerLH;   //!
   TBranch        *b_El_isMediumLH;   //!
   TBranch        *b_El_isTightLH;   //!
   TBranch        *b_El_nBLayerHits;   //!
   TBranch        *b_El_expectBLayerHit;   //!
   TBranch        *b_El_ptcone20;   //!
   TBranch        *b_El_ptcone30;   //!
   TBranch        *b_El_ptcone40;   //!
   TBranch        *b_El_ptvarcone20;   //!
   TBranch        *b_El_ptvarcone30;   //!
   TBranch        *b_El_ptvarcone40;   //!
   TBranch        *b_El_topoetcone20;   //!
   TBranch        *b_El_topoetcone30;   //!
   TBranch        *b_El_topoetcone40;   //!
   TBranch        *b_El_passIsoLooseTO;   //!
   TBranch        *b_El_passIsoLoose;   //!
   TBranch        *b_El_passIsoTight;   //!
   TBranch        *b_El_passIsoGrad;   //!
   TBranch        *b_El_passIsoGradCustomTight;   //!
   TBranch        *b_El_passIsoGradCustom;   //!
   TBranch        *b_El_passIsoGradLoose;   //!
   TBranch        *b_El_trigMatch_e12_lhloose_L1EM10VH;   //!
   TBranch        *b_El_trigMatch_e17_lhloose;   //!
   TBranch        *b_El_trigMatch_e60_lhmedium;   //!
   TBranch        *b_El_trigMatch_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_El_trigMatch_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_El_trigMatch_2e15_lhloose_L12EM10VH;   //!
   TBranch        *b_El_trigMatch_2e15_lhvloose_L12EM13VH;   //!
   TBranch        *b_El_trigMatch_2e15_lhvloose_nod0_L12EM13VH;   //!
   TBranch        *b_El_trigMatch_2e17_lhvloose_nod0;   //!
   TBranch        *b_El_trigMatch_e17_lhloose_mu14;   //!
   TBranch        *b_El_trigMatch_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_El_TrigMatch_e24_lhmedium_nod0_ivarloose;   //!
   TBranch        *b_El_TrigMatch_e24_lhtight_nod0_ivarloose;   //!
   TBranch        *b_El_TrigMatch_e60_lhmedium_nod0;   //!
   TBranch        *b_NJet;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pT;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_quality;   //!
   TBranch        *b_Jet_JVT;   //!
   TBranch        *b_Jet_JVTsf;   //!
   TBranch        *b_Jet_MV2c20;   //!
   TBranch        *b_Jet_MV2c10;   //!
   TBranch        *b_Jet_SFw;   //!
   TBranch        *b_Jet_nTrk;   //!
   TBranch        *b_Jet_passOR;   //!
   TBranch        *b_Etmiss_CST_Etx;   //!
   TBranch        *b_Etmiss_CST_Ety;   //!
   TBranch        *b_Etmiss_CST_Et;   //!
   TBranch        *b_Etmiss_TST_Etx;   //!
   TBranch        *b_Etmiss_TST_Ety;   //!
   TBranch        *b_Etmiss_TST_Et;   //!
   TBranch        *b_Etmiss_TSTterm_Etx;   //!
   TBranch        *b_Etmiss_TSTterm_Ety;   //!
   TBranch        *b_Etmiss_TSTterm_Et;   //!
   TBranch        *b_Etmiss_Truth_Etx;   //!
   TBranch        *b_Etmiss_Truth_Ety;   //!
   TBranch        *b_Etmiss_Truth_Et;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_Nvtx;   //!
   TBranch        *b_TruthX1;   //!
   TBranch        *b_TruthX2;   //!
   TBranch        *b_TruthQ;   //!
   TBranch        *b_SherpaNjetWeight;   //!
   TBranch        *b_TruthPDGID1;   //!
   TBranch        *b_TruthPDGID2;   //!
   TBranch        *b_El_ZTandP_mll;   //!
   TBranch        *b_El_DR_closest_Jet;   //!
   TBranch        *b_El_isBaseline;   //!
   TBranch        *b_El_isSignal;   //!
   TBranch        *b_El_isZProbe;   //!
   TBranch        *b_El_isZProbe_TriggMatched;   //!
   TBranch        *b_El_isTTbarProbe;   //!
   TBranch        *b_Mu_ZTandP_mll;   //!
   TBranch        *b_Mu_DR_closest_Jet;   //!
   TBranch        *b_Mu_isBaseline;   //!
   TBranch        *b_Mu_isSignal;   //!
   TBranch        *b_Mu_isZProbe;   //!
   TBranch        *b_Mu_isZProbe_TriggMatched;   //!
   TBranch        *b_Mu_isTTbarProbe;   //!
   TBranch        *b_Jet_Jet_isSignal;   //!
   TBranch        *b_Jet_bJet_isSignal;   //!
   TBranch        *b_isSS2l_trigger;   //!
   TBranch        *b_baseline_mll;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_mjj;   //!
   TBranch        *b_meff;   //!
   TBranch        *b_Ht;   //!
   TBranch        *b_mT;   //!
   TBranch        *b_nBaseLeps;   //!
   TBranch        *b_nSigLeps;   //!
   TBranch        *b_lep1Pt;   //!
   TBranch        *b_lep2Pt;   //!
   TBranch        *b_lep3Pt;   //!
   TBranch        *b_lep1Eta;   //!
   TBranch        *b_lep2Eta;   //!
   TBranch        *b_lep3Eta;   //!
   TBranch        *b_nSigBJets;   //!
   TBranch        *b_nSigJets;   //!
   TBranch        *b_jet1Pt;   //!
   TBranch        *b_jet2Pt;   //!
   TBranch        *b_jet3Pt;   //!
   TBranch        *b_isSS2l;   //!
   TBranch        *b_baseline_channel;   //!
   TBranch        *b_channel;   //!

   Skimmed_Data(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Skimmed_Data() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Skimmed_Data,0);
};

#endif

#ifdef Skimmed_Data_cxx
void Skimmed_Data::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Mu_eta = 0;
   Mu_phi = 0;
   Mu_pT = 0;
   Mu_SFw = 0;
   Mu_IsoSFw = 0;
   Mu_charge = 0;
   Mu_d0pvtx = 0;
   Mu_sigd0 = 0;
   Mu_z0sinTheta = 0;
   Mu_isBad = 0;
   Mu_passOR = 0;
   Mu_isTight = 0;
   Mu_isCosmic = 0;
   Mu_ptcone20 = 0;
   Mu_ptcone30 = 0;
   Mu_ptcone40 = 0;
   Mu_ptvarcone20 = 0;
   Mu_ptvarcone30 = 0;
   Mu_ptvarcone40 = 0;
   Mu_topoetcone20 = 0;
   Mu_topoetcone30 = 0;
   Mu_topoetcone40 = 0;
   Mu_passIsoLooseTO = 0;
   Mu_passIsoLoose = 0;
   Mu_passIsoTight = 0;
   Mu_passIsoGrad = 0;
   Mu_passIsoGradCustomTight = 0;
   Mu_passIsoGradCustom = 0;
   Mu_passIsoGradLoose = 0;
   Mu_trigMatch_mu26_imedium = 0;
   Mu_trigMatch_mu50 = 0;
   Mu_trigMatch_mu8noL1 = 0;
   Mu_trigMatch_mu14 = 0;
   Mu_trigMatch_mu18 = 0;
   Mu_trigMatch_mu18_mu8noL1 = 0;
   Mu_trigMatch_e17_lhloose_mu14 = 0;
   Mu_trigMatch_e17_lhloose_nod0_mu14 = 0;
   Mu_trigMatch_mu20_mu8noL1 = 0;
   Mu_trigMatch_mu22_mu8noL1 = 0;
   Mu_TrigMatch_mu24_iloose = 0;
   Mu_TrigMatch_mu24_ivarloose = 0;
   Mu_TrigMatch_mu24_iloose_L1MU15 = 0;
   Mu_TrigMatch_mu24_ivarloose_L1MU15 = 0;
   Mu_trigMatchPair_mu18_mu8noL1 = 0;
   Mu_trigMatchPair_mu20_mu8noL1 = 0;
   Mu_trigMatchPair_mu22_mu8noL1 = 0;
   El_eta = 0;
   El_etaclus = 0;
   El_phi = 0;
   El_pT = 0;
   El_E = 0;
   El_charge = 0;
   El_sigd0 = 0;
   El_z0sinTheta = 0;
   El_d0pvtx = 0;
   El_passOR = 0;
   El_SFwMediumLH = 0;
   El_IsoSFwMediumLH = 0;
   El_SFwTightLH = 0;
   El_SFwLooseAndBLayerLH = 0;
   El_SFwTrigMediumLH_e12_lhloose_L1EM10VH = 0;
   El_SFwTrigMediumLH_e17_lhloose = 0;
   El_SFwTrigMediumLH_single = 0;
   El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH = 0;
   El_isLooseAndBLayerLH = 0;
   El_isMediumLH = 0;
   El_isTightLH = 0;
   El_nBLayerHits = 0;
   El_expectBLayerHit = 0;
   El_ptcone20 = 0;
   El_ptcone30 = 0;
   El_ptcone40 = 0;
   El_ptvarcone20 = 0;
   El_ptvarcone30 = 0;
   El_ptvarcone40 = 0;
   El_topoetcone20 = 0;
   El_topoetcone30 = 0;
   El_topoetcone40 = 0;
   El_passIsoLooseTO = 0;
   El_passIsoLoose = 0;
   El_passIsoTight = 0;
   El_passIsoGrad = 0;
   El_passIsoGradCustomTight = 0;
   El_passIsoGradCustom = 0;
   El_passIsoGradLoose = 0;
   El_trigMatch_e12_lhloose_L1EM10VH = 0;
   El_trigMatch_e17_lhloose = 0;
   El_trigMatch_e60_lhmedium = 0;
   El_trigMatch_e24_lhmedium_iloose_L1EM20VH = 0;
   El_trigMatch_2e12_lhloose_L12EM10VH = 0;
   El_trigMatch_2e15_lhloose_L12EM10VH = 0;
   El_trigMatch_2e15_lhvloose_L12EM13VH = 0;
   El_trigMatch_2e15_lhvloose_nod0_L12EM13VH = 0;
   El_trigMatch_2e17_lhvloose_nod0 = 0;
   El_trigMatch_e17_lhloose_mu14 = 0;
   El_trigMatch_e17_lhloose_nod0_mu14 = 0;
   El_TrigMatch_e24_lhmedium_nod0_ivarloose = 0;
   El_TrigMatch_e24_lhtight_nod0_ivarloose = 0;
   El_TrigMatch_e60_lhmedium_nod0 = 0;
   Jet_eta = 0;
   Jet_phi = 0;
   Jet_pT = 0;
   Jet_E = 0;
   Jet_quality = 0;
   Jet_JVT = 0;
   Jet_JVTsf = 0;
   Jet_MV2c20 = 0;
   Jet_MV2c10 = 0;
   Jet_SFw = 0;
   Jet_nTrk = 0;
   Jet_passOR = 0;
   El_ZTandP_mll = 0;
   El_DR_closest_Jet = 0;
   El_isBaseline = 0;
   El_isSignal = 0;
   El_isZProbe = 0;
   El_isZProbe_TriggMatched = 0;
   El_isTTbarProbe = 0;
   Mu_ZTandP_mll = 0;
   Mu_DR_closest_Jet = 0;
   Mu_isBaseline = 0;
   Mu_isSignal = 0;
   Mu_isZProbe = 0;
   Mu_isZProbe_TriggMatched = 0;
   Mu_isTTbarProbe = 0;
   Jet_Jet_isSignal = 0;
   Jet_bJet_isSignal = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HLT_e24_lhmedium_nod0_ivarloose", &HLT_e24_lhmedium_nod0_ivarloose, &b_HLT_e24_lhmedium_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e24_lhtight_nod0_ivarloose", &HLT_e24_lhtight_nod0_ivarloose, &b_HLT_e24_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e24_lhmedium_nod0_L1EM20VH", &HLT_e24_lhmedium_nod0_L1EM20VH, &b_HLT_e24_lhmedium_nod0_L1EM20VH);
   fChain->SetBranchAddress("HLT_e26_lhtight_iloose", &HLT_e26_lhtight_iloose, &b_HLT_e26_lhtight_iloose);
   fChain->SetBranchAddress("HLT_e26_lhtight_ivarloose", &HLT_e26_lhtight_ivarloose, &b_HLT_e26_lhtight_ivarloose);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_iloose", &HLT_e26_lhtight_nod0_iloose, &b_HLT_e26_lhtight_nod0_iloose);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_e120_lhloose_nod0", &HLT_e120_lhloose_nod0, &b_HLT_e120_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_2e17_lhvloose_nod0", &HLT_2e17_lhvloose_nod0, &b_HLT_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_2e15_lhvloose_nod0_L12EM13VH", &HLT_2e15_lhvloose_nod0_L12EM13VH, &b_HLT_2e15_lhvloose_nod0_L12EM13VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_e9_lhmedium", &HLT_e24_lhmedium_e9_lhmedium, &b_HLT_e24_lhmedium_e9_lhmedium);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e12_lhvloose_L12EM10VH", &HLT_e12_lhvloose_L12EM10VH, &b_HLT_e12_lhvloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_e17_lhloose_2e9_lhloose", &HLT_e17_lhloose_2e9_lhloose, &b_HLT_e17_lhloose_2e9_lhloose);
   fChain->SetBranchAddress("HLT_mu24_ivarmedium", &HLT_mu24_ivarmedium, &b_HLT_mu24_ivarmedium);
   fChain->SetBranchAddress("HLT_mu24_imedium", &HLT_mu24_imedium, &b_HLT_mu24_imedium);
   fChain->SetBranchAddress("HLT_mu24_ivarloose", &HLT_mu24_ivarloose, &b_HLT_mu24_ivarloose);
   fChain->SetBranchAddress("HLT_mu24_iloose", &HLT_mu24_iloose, &b_HLT_mu24_iloose);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_mu26_imedium", &HLT_mu26_imedium, &b_HLT_mu26_imedium);
   fChain->SetBranchAddress("HLT_mu20_ivarmedium_L1MU15", &HLT_mu20_ivarmedium_L1MU15, &b_HLT_mu20_ivarmedium_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_imedium_L1MU15", &HLT_mu20_imedium_L1MU15, &b_HLT_mu20_imedium_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_ivarloose_L1MU15", &HLT_mu20_ivarloose_L1MU15, &b_HLT_mu20_ivarloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_L1MU15", &HLT_mu20_L1MU15, &b_HLT_mu20_L1MU15);
   fChain->SetBranchAddress("HLT_mu20_mu8noL1", &HLT_mu20_mu8noL1, &b_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("HLT_mu20_2mu4noL1", &HLT_mu20_2mu4noL1, &b_HLT_mu20_2mu4noL1);
   fChain->SetBranchAddress("HLT_mu22_2mu4noL1", &HLT_mu22_2mu4noL1, &b_HLT_mu22_2mu4noL1);
   fChain->SetBranchAddress("HLT_mu40", &HLT_mu40, &b_HLT_mu40);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_2mu10", &HLT_2mu10, &b_HLT_2mu10);
   fChain->SetBranchAddress("HLT_2mu10_nomucomb", &HLT_2mu10_nomucomb, &b_HLT_2mu10_nomucomb);
   fChain->SetBranchAddress("HLT_2mu14", &HLT_2mu14, &b_HLT_2mu14);
   fChain->SetBranchAddress("HLT_2mu14_nomucomb", &HLT_2mu14_nomucomb, &b_HLT_2mu14_nomucomb);
   fChain->SetBranchAddress("HLT_3mu6", &HLT_3mu6, &b_HLT_3mu6);
   fChain->SetBranchAddress("HLT_3mu6_msonly", &HLT_3mu6_msonly, &b_HLT_3mu6_msonly);
   fChain->SetBranchAddress("HLT_xe100_L1XE50", &HLT_xe100_L1XE50, &b_HLT_xe100_L1XE50);
   fChain->SetBranchAddress("HLT_xe80_mht_L1XE50", &HLT_xe80_mht_L1XE50, &b_HLT_xe80_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_mht_L1XE50", &HLT_xe90_mht_L1XE50, &b_HLT_xe90_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_mht_L1XE50", &HLT_xe100_mht_L1XE50, &b_HLT_xe100_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_pueta_L1XE50", &HLT_xe110_pueta_L1XE50, &b_HLT_xe110_pueta_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_pufit_L1XE50", &HLT_xe110_pufit_L1XE50, &b_HLT_xe110_pufit_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_tc_em_L1XE50", &HLT_xe100_tc_em_L1XE50, &b_HLT_xe100_tc_em_L1XE50);
   fChain->SetBranchAddress("HLT_xe80_tc_lcw_L1XE50", &HLT_xe80_tc_lcw_L1XE50, &b_HLT_xe80_tc_lcw_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_tc_lcw_L1XE50", &HLT_xe90_tc_lcw_L1XE50, &b_HLT_xe90_tc_lcw_L1XE50);
   fChain->SetBranchAddress("HLT_xe80_tc_lcw_wEFMu_L1XE50", &HLT_xe80_tc_lcw_wEFMu_L1XE50, &b_HLT_xe80_tc_lcw_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_e7_lhmedium_mu24", &HLT_e7_lhmedium_mu24, &b_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1", &HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1, &b_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1", &HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1, &b_HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH, &b_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("ChannelNumber", &ChannelNumber, &b_ChannelNumber);
   fChain->SetBranchAddress("AvgMu", &AvgMu, &b_AvgMu);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("PRWWeight", &PRWWeight, &b_PRWWeight);
   fChain->SetBranchAddress("PRWrandomRunNumber", &PRWrandomRunNumber, &b_PRWrandomRunNumber);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("LB", &LB, &b_LB);
   fChain->SetBranchAddress("RunNb", &RunNb, &b_RunNb);
   fChain->SetBranchAddress("DetError", &DetError, &b_DetError);
   fChain->SetBranchAddress("NMu", &NMu, &b_NMu);
   fChain->SetBranchAddress("Mu_eta", &Mu_eta, &b_Mu_eta);
   fChain->SetBranchAddress("Mu_phi", &Mu_phi, &b_Mu_phi);
   fChain->SetBranchAddress("Mu_pT", &Mu_pT, &b_Mu_pT);
   fChain->SetBranchAddress("Mu_SFw", &Mu_SFw, &b_Mu_SFw);
   fChain->SetBranchAddress("Mu_IsoSFw", &Mu_IsoSFw, &b_Mu_IsoSFw);
   fChain->SetBranchAddress("Mu_charge", &Mu_charge, &b_Mu_charge);
   fChain->SetBranchAddress("Mu_d0pvtx", &Mu_d0pvtx, &b_Mu_d0pvtx);
   fChain->SetBranchAddress("Mu_sigd0", &Mu_sigd0, &b_Mu_sigd0);
   fChain->SetBranchAddress("Mu_z0sinTheta", &Mu_z0sinTheta, &b_Mu_z0sinTheta);
   fChain->SetBranchAddress("Mu_isBad", &Mu_isBad, &b_Mu_isBad);
   fChain->SetBranchAddress("Mu_passOR", &Mu_passOR, &b_Mu_passOR);
   fChain->SetBranchAddress("Mu_isTight", &Mu_isTight, &b_Mu_isTight);
   fChain->SetBranchAddress("Mu_isCosmic", &Mu_isCosmic, &b_Mu_isCosmic);
   fChain->SetBranchAddress("Mu_ptcone20", &Mu_ptcone20, &b_Mu_ptcone20);
   fChain->SetBranchAddress("Mu_ptcone30", &Mu_ptcone30, &b_Mu_ptcone30);
   fChain->SetBranchAddress("Mu_ptcone40", &Mu_ptcone40, &b_Mu_ptcone40);
   fChain->SetBranchAddress("Mu_ptvarcone20", &Mu_ptvarcone20, &b_Mu_ptvarcone20);
   fChain->SetBranchAddress("Mu_ptvarcone30", &Mu_ptvarcone30, &b_Mu_ptvarcone30);
   fChain->SetBranchAddress("Mu_ptvarcone40", &Mu_ptvarcone40, &b_Mu_ptvarcone40);
   fChain->SetBranchAddress("Mu_topoetcone20", &Mu_topoetcone20, &b_Mu_topoetcone20);
   fChain->SetBranchAddress("Mu_topoetcone30", &Mu_topoetcone30, &b_Mu_topoetcone30);
   fChain->SetBranchAddress("Mu_topoetcone40", &Mu_topoetcone40, &b_Mu_topoetcone40);
   fChain->SetBranchAddress("Mu_passIsoLooseTO", &Mu_passIsoLooseTO, &b_Mu_passIsoLooseTO);
   fChain->SetBranchAddress("Mu_passIsoLoose", &Mu_passIsoLoose, &b_Mu_passIsoLoose);
   fChain->SetBranchAddress("Mu_passIsoTight", &Mu_passIsoTight, &b_Mu_passIsoTight);
   fChain->SetBranchAddress("Mu_passIsoGrad", &Mu_passIsoGrad, &b_Mu_passIsoGrad);
   fChain->SetBranchAddress("Mu_passIsoGradCustomTight", &Mu_passIsoGradCustomTight, &b_Mu_passIsoGradCustomTight);
   fChain->SetBranchAddress("Mu_passIsoGradCustom", &Mu_passIsoGradCustom, &b_Mu_passIsoGradCustom);
   fChain->SetBranchAddress("Mu_passIsoGradLoose", &Mu_passIsoGradLoose, &b_Mu_passIsoGradLoose);
   fChain->SetBranchAddress("MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50", &MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50, &b_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50);
   fChain->SetBranchAddress("Mu_trigMatch_mu26_imedium", &Mu_trigMatch_mu26_imedium, &b_Mu_trigMatch_mu26_imedium);
   fChain->SetBranchAddress("Mu_trigMatch_mu50", &Mu_trigMatch_mu50, &b_Mu_trigMatch_mu50);
   fChain->SetBranchAddress("Mu_trigMatch_mu8noL1", &Mu_trigMatch_mu8noL1, &b_Mu_trigMatch_mu8noL1);
   fChain->SetBranchAddress("Mu_trigMatch_mu14", &Mu_trigMatch_mu14, &b_Mu_trigMatch_mu14);
   fChain->SetBranchAddress("Mu_trigMatch_mu18", &Mu_trigMatch_mu18, &b_Mu_trigMatch_mu18);
   fChain->SetBranchAddress("Mu_trigMatch_mu18_mu8noL1", &Mu_trigMatch_mu18_mu8noL1, &b_Mu_trigMatch_mu18_mu8noL1);
   fChain->SetBranchAddress("Mu_trigMatch_e17_lhloose_mu14", &Mu_trigMatch_e17_lhloose_mu14, &b_Mu_trigMatch_e17_lhloose_mu14);
   fChain->SetBranchAddress("Mu_trigMatch_e17_lhloose_nod0_mu14", &Mu_trigMatch_e17_lhloose_nod0_mu14, &b_Mu_trigMatch_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("Mu_trigMatch_mu20_mu8noL1", &Mu_trigMatch_mu20_mu8noL1, &b_Mu_trigMatch_mu20_mu8noL1);
   fChain->SetBranchAddress("Mu_trigMatch_mu22_mu8noL1", &Mu_trigMatch_mu22_mu8noL1, &b_Mu_trigMatch_mu22_mu8noL1);
   fChain->SetBranchAddress("Mu_TrigMatch_mu24_iloose", &Mu_TrigMatch_mu24_iloose, &b_Mu_TrigMatch_mu24_iloose);
   fChain->SetBranchAddress("Mu_TrigMatch_mu24_ivarloose", &Mu_TrigMatch_mu24_ivarloose, &b_Mu_TrigMatch_mu24_ivarloose);
   fChain->SetBranchAddress("Mu_TrigMatch_mu24_iloose_L1MU15", &Mu_TrigMatch_mu24_iloose_L1MU15, &b_Mu_TrigMatch_mu24_iloose_L1MU15);
   fChain->SetBranchAddress("Mu_TrigMatch_mu24_ivarloose_L1MU15", &Mu_TrigMatch_mu24_ivarloose_L1MU15, &b_Mu_TrigMatch_mu24_ivarloose_L1MU15);
   fChain->SetBranchAddress("Mu_trigMatchPair_mu18_mu8noL1", &Mu_trigMatchPair_mu18_mu8noL1, &b_Mu_trigMatchPair_mu18_mu8noL1);
   fChain->SetBranchAddress("Mu_trigMatchPair_mu20_mu8noL1", &Mu_trigMatchPair_mu20_mu8noL1, &b_Mu_trigMatchPair_mu20_mu8noL1);
   fChain->SetBranchAddress("Mu_trigMatchPair_mu22_mu8noL1", &Mu_trigMatchPair_mu22_mu8noL1, &b_Mu_trigMatchPair_mu22_mu8noL1);
   fChain->SetBranchAddress("NEl", &NEl, &b_NEl);
   fChain->SetBranchAddress("El_eta", &El_eta, &b_El_eta);
   fChain->SetBranchAddress("El_etaclus", &El_etaclus, &b_El_etaclus);
   fChain->SetBranchAddress("El_phi", &El_phi, &b_El_phi);
   fChain->SetBranchAddress("El_pT", &El_pT, &b_El_pT);
   fChain->SetBranchAddress("El_E", &El_E, &b_El_E);
   fChain->SetBranchAddress("El_charge", &El_charge, &b_El_charge);
   fChain->SetBranchAddress("El_sigd0", &El_sigd0, &b_El_sigd0);
   fChain->SetBranchAddress("El_z0sinTheta", &El_z0sinTheta, &b_El_z0sinTheta);
   fChain->SetBranchAddress("El_d0pvtx", &El_d0pvtx, &b_El_d0pvtx);
   fChain->SetBranchAddress("El_passOR", &El_passOR, &b_El_passOR);
   fChain->SetBranchAddress("El_SFwMediumLH", &El_SFwMediumLH, &b_El_SFwMediumLH);
   fChain->SetBranchAddress("El_IsoSFwMediumLH", &El_IsoSFwMediumLH, &b_El_IsoSFwMediumLH);
   fChain->SetBranchAddress("El_SFwTightLH", &El_SFwTightLH, &b_El_SFwTightLH);
   fChain->SetBranchAddress("El_SFwLooseAndBLayerLH", &El_SFwLooseAndBLayerLH, &b_El_SFwLooseAndBLayerLH);
   fChain->SetBranchAddress("El_SFwTrigMediumLH_e12_lhloose_L1EM10VH", &El_SFwTrigMediumLH_e12_lhloose_L1EM10VH, &b_El_SFwTrigMediumLH_e12_lhloose_L1EM10VH);
   fChain->SetBranchAddress("El_SFwTrigMediumLH_e17_lhloose", &El_SFwTrigMediumLH_e17_lhloose, &b_El_SFwTrigMediumLH_e17_lhloose);
   fChain->SetBranchAddress("El_SFwTrigMediumLH_single", &El_SFwTrigMediumLH_single, &b_El_SFwTrigMediumLH_single);
   fChain->SetBranchAddress("El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH", &El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH, &b_El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH);
   fChain->SetBranchAddress("El_isLooseAndBLayerLH", &El_isLooseAndBLayerLH, &b_El_isLooseAndBLayerLH);
   fChain->SetBranchAddress("El_isMediumLH", &El_isMediumLH, &b_El_isMediumLH);
   fChain->SetBranchAddress("El_isTightLH", &El_isTightLH, &b_El_isTightLH);
   fChain->SetBranchAddress("El_nBLayerHits", &El_nBLayerHits, &b_El_nBLayerHits);
   fChain->SetBranchAddress("El_expectBLayerHit", &El_expectBLayerHit, &b_El_expectBLayerHit);
   fChain->SetBranchAddress("El_ptcone20", &El_ptcone20, &b_El_ptcone20);
   fChain->SetBranchAddress("El_ptcone30", &El_ptcone30, &b_El_ptcone30);
   fChain->SetBranchAddress("El_ptcone40", &El_ptcone40, &b_El_ptcone40);
   fChain->SetBranchAddress("El_ptvarcone20", &El_ptvarcone20, &b_El_ptvarcone20);
   fChain->SetBranchAddress("El_ptvarcone30", &El_ptvarcone30, &b_El_ptvarcone30);
   fChain->SetBranchAddress("El_ptvarcone40", &El_ptvarcone40, &b_El_ptvarcone40);
   fChain->SetBranchAddress("El_topoetcone20", &El_topoetcone20, &b_El_topoetcone20);
   fChain->SetBranchAddress("El_topoetcone30", &El_topoetcone30, &b_El_topoetcone30);
   fChain->SetBranchAddress("El_topoetcone40", &El_topoetcone40, &b_El_topoetcone40);
   fChain->SetBranchAddress("El_passIsoLooseTO", &El_passIsoLooseTO, &b_El_passIsoLooseTO);
   fChain->SetBranchAddress("El_passIsoLoose", &El_passIsoLoose, &b_El_passIsoLoose);
   fChain->SetBranchAddress("El_passIsoTight", &El_passIsoTight, &b_El_passIsoTight);
   fChain->SetBranchAddress("El_passIsoGrad", &El_passIsoGrad, &b_El_passIsoGrad);
   fChain->SetBranchAddress("El_passIsoGradCustomTight", &El_passIsoGradCustomTight, &b_El_passIsoGradCustomTight);
   fChain->SetBranchAddress("El_passIsoGradCustom", &El_passIsoGradCustom, &b_El_passIsoGradCustom);
   fChain->SetBranchAddress("El_passIsoGradLoose", &El_passIsoGradLoose, &b_El_passIsoGradLoose);
   fChain->SetBranchAddress("El_trigMatch_e12_lhloose_L1EM10VH", &El_trigMatch_e12_lhloose_L1EM10VH, &b_El_trigMatch_e12_lhloose_L1EM10VH);
   fChain->SetBranchAddress("El_trigMatch_e17_lhloose", &El_trigMatch_e17_lhloose, &b_El_trigMatch_e17_lhloose);
   fChain->SetBranchAddress("El_trigMatch_e60_lhmedium", &El_trigMatch_e60_lhmedium, &b_El_trigMatch_e60_lhmedium);
   fChain->SetBranchAddress("El_trigMatch_e24_lhmedium_iloose_L1EM20VH", &El_trigMatch_e24_lhmedium_iloose_L1EM20VH, &b_El_trigMatch_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("El_trigMatch_2e12_lhloose_L12EM10VH", &El_trigMatch_2e12_lhloose_L12EM10VH, &b_El_trigMatch_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("El_trigMatch_2e15_lhloose_L12EM10VH", &El_trigMatch_2e15_lhloose_L12EM10VH, &b_El_trigMatch_2e15_lhloose_L12EM10VH);
   fChain->SetBranchAddress("El_trigMatch_2e15_lhvloose_L12EM13VH", &El_trigMatch_2e15_lhvloose_L12EM13VH, &b_El_trigMatch_2e15_lhvloose_L12EM13VH);
   fChain->SetBranchAddress("El_trigMatch_2e15_lhvloose_nod0_L12EM13VH", &El_trigMatch_2e15_lhvloose_nod0_L12EM13VH, &b_El_trigMatch_2e15_lhvloose_nod0_L12EM13VH);
   fChain->SetBranchAddress("El_trigMatch_2e17_lhvloose_nod0", &El_trigMatch_2e17_lhvloose_nod0, &b_El_trigMatch_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("El_trigMatch_e17_lhloose_mu14", &El_trigMatch_e17_lhloose_mu14, &b_El_trigMatch_e17_lhloose_mu14);
   fChain->SetBranchAddress("El_trigMatch_e17_lhloose_nod0_mu14", &El_trigMatch_e17_lhloose_nod0_mu14, &b_El_trigMatch_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("El_TrigMatch_e24_lhmedium_nod0_ivarloose", &El_TrigMatch_e24_lhmedium_nod0_ivarloose, &b_El_TrigMatch_e24_lhmedium_nod0_ivarloose);
   fChain->SetBranchAddress("El_TrigMatch_e24_lhtight_nod0_ivarloose", &El_TrigMatch_e24_lhtight_nod0_ivarloose, &b_El_TrigMatch_e24_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("El_TrigMatch_e60_lhmedium_nod0", &El_TrigMatch_e60_lhmedium_nod0, &b_El_TrigMatch_e60_lhmedium_nod0);
   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("Jet_eta", &Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", &Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pT", &Jet_pT, &b_Jet_pT);
   fChain->SetBranchAddress("Jet_E", &Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_quality", &Jet_quality, &b_Jet_quality);
   fChain->SetBranchAddress("Jet_JVT", &Jet_JVT, &b_Jet_JVT);
   fChain->SetBranchAddress("Jet_JVTsf", &Jet_JVTsf, &b_Jet_JVTsf);
   fChain->SetBranchAddress("Jet_MV2c20", &Jet_MV2c20, &b_Jet_MV2c20);
   fChain->SetBranchAddress("Jet_MV2c10", &Jet_MV2c10, &b_Jet_MV2c10);
   fChain->SetBranchAddress("Jet_SFw", &Jet_SFw, &b_Jet_SFw);
   fChain->SetBranchAddress("Jet_nTrk", &Jet_nTrk, &b_Jet_nTrk);
   fChain->SetBranchAddress("Jet_passOR", &Jet_passOR, &b_Jet_passOR);
   fChain->SetBranchAddress("Etmiss_CST_Etx", &Etmiss_CST_Etx, &b_Etmiss_CST_Etx);
   fChain->SetBranchAddress("Etmiss_CST_Ety", &Etmiss_CST_Ety, &b_Etmiss_CST_Ety);
   fChain->SetBranchAddress("Etmiss_CST_Et", &Etmiss_CST_Et, &b_Etmiss_CST_Et);
   fChain->SetBranchAddress("Etmiss_TST_Etx", &Etmiss_TST_Etx, &b_Etmiss_TST_Etx);
   fChain->SetBranchAddress("Etmiss_TST_Ety", &Etmiss_TST_Ety, &b_Etmiss_TST_Ety);
   fChain->SetBranchAddress("Etmiss_TST_Et", &Etmiss_TST_Et, &b_Etmiss_TST_Et);
   fChain->SetBranchAddress("Etmiss_TSTterm_Etx", &Etmiss_TSTterm_Etx, &b_Etmiss_TSTterm_Etx);
   fChain->SetBranchAddress("Etmiss_TSTterm_Ety", &Etmiss_TSTterm_Ety, &b_Etmiss_TSTterm_Ety);
   fChain->SetBranchAddress("Etmiss_TSTterm_Et", &Etmiss_TSTterm_Et, &b_Etmiss_TSTterm_Et);
   fChain->SetBranchAddress("Etmiss_Truth_Etx", &Etmiss_Truth_Etx, &b_Etmiss_Truth_Etx);
   fChain->SetBranchAddress("Etmiss_Truth_Ety", &Etmiss_Truth_Ety, &b_Etmiss_Truth_Ety);
   fChain->SetBranchAddress("Etmiss_Truth_Et", &Etmiss_Truth_Et, &b_Etmiss_Truth_Et);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
   fChain->SetBranchAddress("TruthX1", &TruthX1, &b_TruthX1);
   fChain->SetBranchAddress("TruthX2", &TruthX2, &b_TruthX2);
   fChain->SetBranchAddress("TruthQ", &TruthQ, &b_TruthQ);
   fChain->SetBranchAddress("SherpaNjetWeight", &SherpaNjetWeight, &b_SherpaNjetWeight);
   fChain->SetBranchAddress("TruthPDGID1", &TruthPDGID1, &b_TruthPDGID1);
   fChain->SetBranchAddress("TruthPDGID2", &TruthPDGID2, &b_TruthPDGID2);
   fChain->SetBranchAddress("El_ZTandP_mll", &El_ZTandP_mll, &b_El_ZTandP_mll);
   fChain->SetBranchAddress("El_DR_closest_Jet", &El_DR_closest_Jet, &b_El_DR_closest_Jet);
   fChain->SetBranchAddress("El_isBaseline", &El_isBaseline, &b_El_isBaseline);
   fChain->SetBranchAddress("El_isSignal", &El_isSignal, &b_El_isSignal);
   fChain->SetBranchAddress("El_isZProbe", &El_isZProbe, &b_El_isZProbe);
   fChain->SetBranchAddress("El_isZProbe_TriggMatched", &El_isZProbe_TriggMatched, &b_El_isZProbe_TriggMatched);
   fChain->SetBranchAddress("El_isTTbarProbe", &El_isTTbarProbe, &b_El_isTTbarProbe);
   fChain->SetBranchAddress("Mu_ZTandP_mll", &Mu_ZTandP_mll, &b_Mu_ZTandP_mll);
   fChain->SetBranchAddress("Mu_DR_closest_Jet", &Mu_DR_closest_Jet, &b_Mu_DR_closest_Jet);
   fChain->SetBranchAddress("Mu_isBaseline", &Mu_isBaseline, &b_Mu_isBaseline);
   fChain->SetBranchAddress("Mu_isSignal", &Mu_isSignal, &b_Mu_isSignal);
   fChain->SetBranchAddress("Mu_isZProbe", &Mu_isZProbe, &b_Mu_isZProbe);
   fChain->SetBranchAddress("Mu_isZProbe_TriggMatched", &Mu_isZProbe_TriggMatched, &b_Mu_isZProbe_TriggMatched);
   fChain->SetBranchAddress("Mu_isTTbarProbe", &Mu_isTTbarProbe, &b_Mu_isTTbarProbe);
   fChain->SetBranchAddress("Jet_Jet_isSignal", &Jet_Jet_isSignal, &b_Jet_Jet_isSignal);
   fChain->SetBranchAddress("Jet_bJet_isSignal", &Jet_bJet_isSignal, &b_Jet_bJet_isSignal);
   fChain->SetBranchAddress("isSS2l_trigger", &isSS2l_trigger, &b_isSS2l_trigger);
   fChain->SetBranchAddress("baseline_mll", &baseline_mll, &b_baseline_mll);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("mjj", &mjj, &b_mjj);
   fChain->SetBranchAddress("meff", &meff, &b_meff);
   fChain->SetBranchAddress("Ht", &Ht, &b_Ht);
   fChain->SetBranchAddress("mT", &mT, &b_mT);
   fChain->SetBranchAddress("nBaseLeps", &nBaseLeps, &b_nBaseLeps);
   fChain->SetBranchAddress("nSigLeps", &nSigLeps, &b_nSigLeps);
   fChain->SetBranchAddress("lep1Pt", &lep1Pt, &b_lep1Pt);
   fChain->SetBranchAddress("lep2Pt", &lep2Pt, &b_lep2Pt);
   fChain->SetBranchAddress("lep3Pt", &lep3Pt, &b_lep3Pt);
   fChain->SetBranchAddress("lep1Eta", &lep1Eta, &b_lep1Eta);
   fChain->SetBranchAddress("lep2Eta", &lep2Eta, &b_lep2Eta);
   fChain->SetBranchAddress("lep3Eta", &lep3Eta, &b_lep3Eta);
   fChain->SetBranchAddress("nSigBJets", &nSigBJets, &b_nSigBJets);
   fChain->SetBranchAddress("nSigJets", &nSigJets, &b_nSigJets);
   fChain->SetBranchAddress("jet1Pt", &jet1Pt, &b_jet1Pt);
   fChain->SetBranchAddress("jet2Pt", &jet2Pt, &b_jet2Pt);
   fChain->SetBranchAddress("jet3Pt", &jet3Pt, &b_jet3Pt);
   fChain->SetBranchAddress("isSS2l", &isSS2l, &b_isSS2l);
   fChain->SetBranchAddress("baseline_channel", &baseline_channel, &b_baseline_channel);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
}

Bool_t Skimmed_Data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Skimmed_Data_cxx
