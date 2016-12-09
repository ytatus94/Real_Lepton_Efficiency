#define YT_SKIM_CXX
#include "ytRealLeptonsEfficiency/yt_skim.h"

yt_skim::yt_skim()
{
    // Physics object variables
    EE_pair     = new vector<ZTandP_pair>();
    MuMu_pair   = new vector<ZTandP_pair>();

    El_isBaseline   = new vector<bool>();
    El_isSignal     = new vector<bool>();
    El_isZTag       = new vector<bool>();
    El_isZProbe     = new vector<bool>();
    El_ZTandP_mll   = new vector<double>();
    El_isZProbe_TriggerMatched = new vector<bool>();
    //El_DR_closest_Jet = new vector<double>();

    Mu_isBaseline   = new vector<bool>();
    Mu_isSignal     = new vector<bool>();
    Mu_isZTag       = new vector<bool>();
    Mu_isZProbe     = new vector<bool>();
    Mu_ZTandP_mll   = new vector<double>();
    Mu_isZProbe_TriggerMatched = new vector<bool>();
    //Mu_DR_closest_Jet = new vector<double>();

    //Jet_isBaseline  = new vector<bool>();
    //Jet_isSignal    = new vector<bool>();
    //bJet_isSignal   = new vector<bool>();

    // Events variables
    normalization = 1.;
    baseline_mll = 0.;
    signal_mll = 0.;
    //jets_mll = 0.;
    //Ht = 0.;
    //meff = 0.;

    // Counter
    N_at_least_two_baseline_lepton_events = 0;
    N_exactly_two_baseline_lepton_events = 0;
    N_tot_baseline_electrons = 0;
    N_tot_baseline_muons = 0;
    N_tot_TandP_pair_electron = 0;
    N_tot_TandP_pair_muon = 0;
}

void yt_skim::clear_all_object_vectors()
{
    // clear all vectors
    vec_elec.clear();
    vec_muon.clear();
    vec_lept.clear();
    vec_jets.clear();

    vec_baseline_elec.clear();
    vec_baseline_muon.clear();
    vec_baseline_lept.clear();
    vec_baseline_jets.clear();

    vec_signal_elec.clear();
    vec_signal_muon.clear();
    vec_signal_lept.clear();
    vec_signal_jets.clear();

    vec_signal_jets_no_eta_cut.clear();
    vec_signal_bjet.clear();
}

void yt_skim::fill_all_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                                      vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                                      vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets)
{
    // in event loop:
    // copy vectors from yt_selector.
    this->copy_raw_object_vectors(elec, muon, lept, jets);
    this->copy_baseline_object_vectors(baseline_elec, baseline_muon, baseline_lept, baseline_jets);
    this->copy_signal_object_vectors(signal_elec, signal_muon, signal_lept, signal_jets);
    //this->fill_signal_jets_no_eta_cut(jets);
    //this->fill_signal_bjet(signal_jets);
}

void yt_skim::copy_raw_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_elec = elec;
    vec_muon = muon;
    vec_lept = lept;
    vec_jets = jets;
}

void yt_skim::copy_baseline_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_baseline_elec = elec;
    vec_baseline_muon = muon;
    vec_baseline_lept = lept;
    vec_baseline_jets = jets;
}

void yt_skim::copy_signal_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_signal_elec = elec;
    vec_signal_muon = muon;
    vec_signal_lept = lept;
    vec_signal_jets = jets;
}
/*
void yt_skim::fill_signal_jets_no_eta_cut(vector<Jet> jets)
{
    for (auto & jet_itr : jets) {
        if (jet_itr.get_pt() > 20000. &&
            jet_itr.get_passOR() == true) {
            if (jet_itr.get_pt() < 60000. &&
                fabs(jet_itr.get_eta()) < 2.4 &&
                jet_itr.get_JVT() < 0.59) {
                continue;
            }
            else {
                if (jet_itr.get_quality() < 0.5)
                    vec_signal_jets_no_eta_cut.push_back(jet_itr);
            }
        }
    }
}

void yt_skim::fill_signal_bjet(vector<Jet> signal_jets)
{
    for (auto & signal_jets_itr : signal_jets) {
        if (signal_jets_itr.get_isBjet() == true)
            vec_signal_bjet.push_back(signal_jets_itr);
    }
}
*/
void yt_skim::initialize(TTree *tree, string process)
{
    // Declare the output
    TString output_path("/raid05/users/shen/Ximo_ntuples/v44/Skimmed/");
    if (process != "Data") {
        output_file = TFile::Open(output_path + "/MC_probes_" + process + ".root", "RECREATE");
    }
    else {
        output_file = TFile::Open(output_path + "/data_probes_all_periods.root", "RECREATE");
    }
    output_tree = (TTree*)tree->CloneTree(0);

    // Building the new branches
    // Normalization
    output_tree->Branch("normalization", &normalization);
    output_tree->Branch("luminosity", &luminosity);
    output_tree->Branch("cross_section", &cross_section);
    output_tree->Branch("k_factor", &k_factor);
    output_tree->Branch("filter_efficiency", &filter_efficiency);
    output_tree->Branch("cross_section_kfactor_efficiency", &cross_section_kfactor_efficiency);
    output_tree->Branch("event_weight_sum", &event_weight_sum);
    output_tree->Branch("event_weight", &event_weight);
    output_tree->Branch("pileup_weight", &pileup_weight);
    output_tree->Branch("baseline_weight", &baseline_weight);
    output_tree->Branch("signal_weight", &signal_weight);
    output_tree->Branch("run_number", &run_number);
    // Physics object variables
/*
    output_tree->Branch("tag_flavor", &tag_flavor);
    output_tree->Branch("tag_index", &tag_index);
    output_tree->Branch("tag_pt", &tag_pt);
    output_tree->Branch("tag_eta", &tag_eta);
    output_tree->Branch("tag_phi", &tag_phi);
    output_tree->Branch("tag_is_trigger_matched", &tag_is_trigger_matched);
    output_tree->Branch("tag_id_SFw", &tag_id_SFw);
    output_tree->Branch("tag_iso_SFw", &tag_iso_SFw);
    output_tree->Branch("tag_trigger_SFw", &tag_trigger_SFw);

    output_tree->Branch("probe_flavor", &probe_flavor);
    output_tree->Branch("probe_index", &probe_index);
    output_tree->Branch("probe_pt", &probe_pt);
    output_tree->Branch("probe_eta", &probe_eta);
    output_tree->Branch("probe_phi", &probe_phi);
    output_tree->Branch("probe_is_baseline", &probe_is_baseline);
    output_tree->Branch("probe_is_signal", &probe_is_signal);
    output_tree->Branch("probe_id_SFw", &probe_id_SFw);
    output_tree->Branch("probe_iso_SFw", &probe_iso_SFw);
    output_tree->Branch("probe_deltaR_closest_jet", &probe_deltaR_closest_jet);
    output_tree->Branch("TandP_baseline_mll", &baseline_mll);
    output_tree->Branch("TandP_signal_mll", &signal_mll);
*/
    output_tree->Branch("El_isBaseline",                &El_isBaseline);
    output_tree->Branch("El_isSignal",                  &El_isSignal);
    output_tree->Branch("El_isZTag",                    &El_isZTag);
    output_tree->Branch("El_isZProbe",                  &El_isZProbe);
    output_tree->Branch("El_ZTandP_mll",                &El_ZTandP_mll);
    output_tree->Branch("El_isZProbe_TriggerMatched",   &El_isZProbe_TriggerMatched);
    //output_tree->Branch("El_DR_closest_Jet",          &El_DR_closest_Jet);

    output_tree->Branch("Mu_isBaseline",                &Mu_isBaseline);
    output_tree->Branch("Mu_isSignal",                  &Mu_isSignal);
    output_tree->Branch("Mu_isZTag",                    &Mu_isZProbe);
    output_tree->Branch("Mu_isZProbe",                  &Mu_isZProbe);
    output_tree->Branch("Mu_ZTandP_mll",                &Mu_ZTandP_mll);
    output_tree->Branch("Mu_isZProbe_TriggerMatched",   &Mu_isZProbe_TriggerMatched);
    //output_tree->Branch("Mu_DR_closest_Jet",          &Mu_DR_closest_Jet);

    //output_tree->Branch("Jet_isBaseline",     &Jet_isBaseline);
    //output_tree->Branch("Jet_isSignal",   &Jet_isSignal);
    //output_tree->Branch("bJet_isSignal",  &bJet_isSignal);

    // Events numbers variables
    output_tree->Branch("normalization", &normalization);
    output_tree->Branch("baseline_mll", &baseline_mll);
    output_tree->Branch("signal_mll",   &signal_mll);
    //output_tree->Branch("jets_mll",   &jets_mll);
    //output_tree->Branch("Ht",         &Ht);
    //output_tree->Branch("meff",       &meff);

    // Events numbers variables
}

void yt_skim::execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                      vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                      vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets)
{
    // clear all the vector members
    this->clear_all_object_vectors();
    // fill all the vector members
    this->fill_all_object_vectors(elec, muon, lept, jets,
                                  baseline_elec, baseline_muon, baseline_lept, baseline_jets,
                                  signal_elec, signal_muon, signal_lept, signal_jets);
    // calculate normalization for this event
    if (isMC)
        normalization = luminosity * (cross_section_kfactor_efficiency * 1000.) * (event_weight / event_weight_sum) * pileup_weight;
    else if (isData)
        normalization = 1.;

    if (baseline_lept.size() >= 2) {
        N_at_least_two_baseline_lepton_events++;
        if (baseline_lept.size() == 2)
            N_exactly_two_baseline_lepton_events++;

        N_tot_baseline_electrons += vec_baseline_elec.size();
        N_tot_baseline_muons += vec_baseline_muon.size();

        this->reset_vectors();
        this->calculate_new_variables();
        this->tag_and_probe_Zee();

        // fill all new branches
        output_tree->Fill();
    }
}

void yt_skim::finalize()
{
    cout << "Write into file" << endl;
    output_file->cd();
    output_tree->Write();
    output_file->Close();

    // output information
}

void yt_skim::reset_vectors()
{
    // Create dummy instance of ZTandP_pair
    // Use dummy to file EE_pair and MuMu_pair
    ZTandP_pair dummy;
    dummy.tag_flavor = 0;
    dummy.tag_index = -1;
    dummy.tag_pt = 0.;
    dummy.tag_eta = 10.;
    dummy.tag_phi = 10.;
    dummy.tag_is_trigger_matched = false;
    dummy.tag_id_SFw = 1.;
    dummy.tag_iso_SFw = 1.;
    dummy.tag_trigger_SFw = 1.;
    dummy.probe_flavor = 0;
    dummy.probe_index = -1;
    dummy.probe_pt = 0.;
    dummy.probe_eta = 10.;
    dummy.probe_phi = 10.;
    dummy.probe_is_baseline = false;
    dummy.probe_is_signal = false;
    dummy.probe_id_SFw = 1.;
    dummy.probe_iso_SFw = 1.;
    //dummy.probe_deltaR_closest_jet = 100;
    dummy.baseline_mll = 0.;
    dummy.signal_mll = 0.;

    // reset vectors in event loop
    EE_pair->clear();
    MuMu_pair->clear();

    for (unsigned int i = 0; i < vec_elec.size(); i++) {
        EE_pair->push_back(dummy);
    }

    for (unsigned int i = 0; i < vec_muon.size(); i++) {
        MuMu_pair->push_back(dummy);
    }

    El_isBaseline->clear();
    El_isSignal->clear();
    El_isZTag->clear();
    El_isZProbe->clear();
    El_ZTandP_mll->clear();
    El_isZProbe_TriggerMatched->clear();
    //El_DR_closest_Jet->clear();

    Mu_isBaseline->clear();
    Mu_isSignal->clear();
    Mu_isZTag->clear();
    Mu_isZProbe->clear();
    Mu_ZTandP_mll->clear();
    Mu_isZProbe_TriggerMatched->clear();
    //Mu_DR_closest_Jet->clear();

    //Jet_isBaseline->clear();
    //Jet_isSignal->clear();
    //bJet_isSignal->clear();

    for (unsigned int i = 0; i < vec_elec.size(); i++) {
        El_isBaseline->push_back(false);
        El_isSignal->push_back(false);
        El_isZTag->push_back(false);
        El_isZProbe->push_back(false);
        El_ZTandP_mll->push_back(0);
        El_isZProbe_TriggerMatched->push_back(false);
        //El_DR_closest_Jet->push_back(100);
    }

    for (unsigned int i = 0; i < vec_muon.size(); i++) {
        Mu_isBaseline->push_back(false);
        Mu_isSignal->push_back(false);
        Mu_isZTag->push_back(false);
        Mu_isZProbe->push_back(false);
        Mu_ZTandP_mll->push_back(0);
        Mu_isZProbe_TriggerMatched->push_back(false);
        //Mu_DR_closest_Jet->push_back(100);
    } 
/*
    for (unsigned int i = 0; i < vec_jets.size(); i++) {
        Jet_isBaseline->push_back(false);
        Jet_isSignal->push_back(false);
        bJet_isSignal->push_back(false);
    } 
*/
}

void yt_skim::calculate_new_variables()
{
    baseline_mll = calculate_mll(vec_baseline_lept);
    signal_mll = calculate_mll(vec_signal_lept);
    //jets_mll = calculate_mjj(vec_signal_jets);
    //Ht = calculate_Ht(vec_signal_lept, vec_signal_jets);
    //meff = calculate_Meff(Ht, Etmiss);

    // Filling the baseline / signal objects indicators / DRjets
    for (auto & elec_itr : vec_baseline_elec) {
        int current_index = elec_itr.get_index();
        El_isBaseline->at(current_index) = true;
        //El_DR_closest_Jet->at(current_index) = calculate_deltaR(elec_itr, vec_signal_jets_no_eta_cut);
    }

    for (auto & muon_itr : vec_baseline_muon) {
        int current_index = muon_itr.get_index();
        Mu_isBaseline->at(current_index) = true;
        //Mu_DR_closest_Jet->at(current_index) = calculate_deltaR(muon_itr, vec_signal_jets_no_eta_cut);
    }

    for (auto & elec_itr : vec_signal_elec) {
        El_isSignal->at(elec_itr.get_index()) = true;
    }

    for (auto & muon_itr : vec_signal_muon) {
        Mu_isSignal->at(muon_itr.get_index()) = true;
    }
/*
    for (auto & jet_itr : vec_baseline_jets) {
        Jet_isBaseline->at(jet_itr.get_index()) = true;
    }

    for (auto & jet_itr : vec_signal_jets) {
        Jet_isSignal->at(jet_itr.get_index()) = true;
    }

    for (auto & bjet_itr : vec_signal_bjet) {
        bJet_isSignal->at(bjet_itr.get_index()) = true;
    }
*/
}

double yt_skim::calculate_mll(vector<Lepton> leptons)
{
    // calculate the invariant mass of the 2 leading leptons
    if (leptons.size() < 2)
        return -999.;

    TLorentzVector tlv_lept_0, tlv_lept_1;
    tlv_lept_0.SetPtEtaPhiM(leptons.at(0).get_pt(), leptons.at(0).get_eta(), leptons.at(0).get_phi(), leptons.at(0).get_M());
    tlv_lept_1.SetPtEtaPhiM(leptons.at(1).get_pt(), leptons.at(1).get_eta(), leptons.at(1).get_phi(), leptons.at(1).get_M());
    double mll = (tlv_lept_0 + tlv_lept_1).M();
    return mll;
}
/*
double yt_skim::calculate_mjj(vector<Jet> jets)
{
    // calculate the invariant mass of the 2 leading jets
    if (jets.size() < 2)
        return -999.;

    TLorentzVector tlv_jets_0, tlv_jets_1;
    tlv_jets_0.SetPtEtaPhiE(jets.at(0).get_pt(), jets.at(0).get_eta(), jets.at(0).get_phi(), jets.at(0).get_E());
    tlv_jets_1.SetPtEtaPhiE(jets.at(1).get_pt(), jets.at(1).get_eta(), jets.at(1).get_phi(), jets.at(1).get_E());
    double mjj = (tlv_jets_0 + tlv_jets_1).M();
    return mjj;
}

double yt_skim::calculate_Ht(vector<Lepton> leptons, vector<Jet> jets)
{
    double Ht = 0;
    for (auto & lep : leptons) {
        Ht = Ht + lep.get_pt();
    }
    for (auto & jet : jets) {
        Ht = Ht + jet.get_pt();
    }
    return Ht;
}

double yt_skim::calculate_Meff(double Ht, double Etmiss)
{
    // the scalar sum of the signal leptons pT, all signal jets pT, and ETmiss
    return  Ht + Etmiss;
}

double yt_skim::calculate_deltaR(Lepton lept, vector<Jet> jets)
{
    // Get the deltaR between the considered lepton and the closest jet

    double deltaR = 100.;
    int flavor = lept.get_flavor();
    for (auto & jet_itr : jets) {
        // computing deltaR
        TLorentzVector lep_tlv;
        TLorentzVector jet_tlv;
        if (flavor == 11)
            lep_tlv.SetPtEtaPhiE(lept.get_pt(), lept.get_eta(), lept.get_phi(), lept.get_E());
        else if (flavor == 13)
            lep_tlv.SetPtEtaPhiM(lept.get_pt(), lept.get_eta(), lept.get_phi(), lept.get_M());
        jet_tlv.SetPtEtaPhiE(jet_itr.get_pt(), jet_itr.get_eta(), jet_itr.get_phi(), jet_itr.get_E());
        double lep_rapidity = lep_tlv.Rapidity();
        double jet_rapidity = jet_tlv.Rapidity();
        double Deta = fabs(lep_rapidity - jet_rapidity);
        double Dphi = fabs(lept.get_phi() - jet_itr.get_phi());
        if (Dphi > TMath::Pi()) Dphi = 2 * TMath::Pi() - Dphi;
        double DR = sqrt(pow(Deta, 2) + pow(Dphi, 2));

        // DR cut
        if ( DR < deltaR ) {
            deltaR = DR;
        }
    }

    return deltaR;
}
*/
void yt_skim::tag_and_probe_Zee()
{
    // Z T&P method

    // Electrons:
    for (auto & probe_elec_itr : vec_baseline_elec) {
        double best_match_mll = 1000000.;
        for (auto & tag_elec_itr : vec_signal_elec) {
            if (tag_elec_itr.get_index() == probe_elec_itr.get_index())
                continue;
            if (tag_elec_itr.get_pt() < tag_pt_threshold)
                continue;
            if (fabs(tag_elec_itr.get_eta()) > 2.)
                continue;
            // Opposite Charge requirement
            if (tag_elec_itr.get_charge() == probe_elec_itr.get_charge())
                continue;
            // Check does the tag trigger matched
            // electrons:
            // 2015: HLT_e24_lhmedium_L1EM20VH
            // 2016: HLT_e24_lhtight_nod0_ivarloose
            bool is_tag_trigger_matched = false;
            if (run_number < 290000) { // 2015 data
                if (tag_elec_itr.get_trigMatch_e24_lhmedium_iloose_L1EM20VH())
                    is_tag_trigger_matched = true;
            }
            else if (run_number > 290000) {
                if (tag_elec_itr.get_trigMatch_e24_lhtight_nod0_ivarloose())
                    is_tag_trigger_matched = true;
            }

            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_elec_itr.get_pt(), tag_elec_itr.get_eta(), tag_elec_itr.get_phi(), tag_elec_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_elec_itr.get_pt(), probe_elec_itr.get_eta(), probe_elec_itr.get_phi(), probe_elec_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
            // mll window cut
            if (current_mll > 80000. && current_mll < 100000.) {
                El_isZTag->at(tag_elec_itr.get_index()) = true;
                El_isZProbe->at(probe_elec_itr.get_index()) = true;
                if (is_tag_trigger_matched)
                    El_isZProbe_TriggerMatched->at(probe_elec_itr.get_index()) = true;
                N_tot_TandP_pair_electron++;
            }
        }
        El_ZTandP_mll->at(probe_elec_itr.get_index()) = best_match_mll;

    }

    // Muons
    for (auto & probe_muon_itr : vec_baseline_muon) {
        double best_match_mll = 1000000.;
        for (auto & tag_muon_itr : vec_signal_muon) {
            if (tag_muon_itr.get_index() == probe_muon_itr.get_index())
                continue;
            if (tag_muon_itr.get_pt() < tag_pt_threshold)
                continue;
            // Opposite Charge requirement
            if (tag_muon_itr.get_charge() == probe_muon_itr.get_charge())
                continue;
            // Check does the tag tragger matched
            // muons:
            // 2015: HLT_mu20_iloose_L1MU15
            // 2016: HLT_mu24_ivarmedium
            bool is_tag_trigger_matched = false;
            if (run_number < 290000) { // 2015 data
                if (tag_muon_itr.get_trigMatch_mu24_iloose_L1MU15()) // no mu20 found, so use mu24
                    is_tag_trigger_matched = true;
            }
            else if (run_number > 290000) { // 2016 data
                if (tag_muon_itr.get_trigMatch_mu24_ivarloose()) // no ivarmedium found, so use ivarloose
                    is_tag_trigger_matched = true;
            }

            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_muon_itr.get_pt(), tag_muon_itr.get_eta(), tag_muon_itr.get_phi(), tag_muon_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_muon_itr.get_pt(), probe_muon_itr.get_eta(), probe_muon_itr.get_phi(), probe_muon_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
            // mll window cut
            if (current_mll > 80000. && current_mll < 100000.) {
                Mu_isZTag->at(tag_muon_itr.get_index()) = true;
                Mu_isZProbe->at(probe_muon_itr.get_index()) = true;
                if (is_tag_trigger_matched)
                    Mu_isZProbe_TriggerMatched->at(probe_muon_itr.get_index()) = true;
                N_tot_TandP_pair_muon++;
            }
        }
        Mu_ZTandP_mll->at(probe_muon_itr.get_index()) = best_match_mll;
    }
}

void yt_skim::debug_print()
{
    cout << "isMC=" << isMC << endl;
    cout << "isData=" << isData << endl;
    cout << "process=" << process << endl;
    cout << "luminosity=" << luminosity << endl;
    cout << "cross_section=" << cross_section << endl;
    cout << "k_factor=" << k_factor << endl;
    cout << "filter_efficiency=" << filter_efficiency << endl;
    cout << "derivation_stat_weights=" << event_weight_sum << endl;

    cout << "N_at_least_two_baseline_lepton_events=" << N_at_least_two_baseline_lepton_events << endl;
    cout << "N_exactly_two_baseline_lepton_events=" << N_exactly_two_baseline_lepton_events << endl;
    cout << "N_tot_baseline_electrons=" << N_tot_baseline_electrons << endl; 
    cout << "N_tot_baseline_muons=" << N_tot_baseline_muons << endl;
    cout << "N_tot_TandP_pair_electron=" << N_tot_TandP_pair_electron << endl;
    cout << "N_tot_TandP_pair_muon=" << N_tot_TandP_pair_muon << endl;
}