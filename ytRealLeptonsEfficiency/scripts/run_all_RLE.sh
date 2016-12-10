#!/bin/bash
Run isData electron > RLE_Data_elec.log 2>&1 &
Run isData muon > RLE_Data_muon.log 2>&1 &
Run isMC Zee > RLE_MC_Zee.log 2>&1 &
Run isMC Zee_TandP_truth_match > RLE_MC_Zee_TandP_truth_match.log 2>&1 &
Run isMC Zee_truth_match > RLE_MC_Zee_truth_match.log 2>&1 &
Run isMC Zmumu > RLE_MC_Zmumu.log 2>&1 &
Run isMC Zmumu_TandP_truth_match > RLE_MC_Zmumu_TandP_truth_match.log 2>&1 &
Run isMC Zmumu_truth_match > RLE_MC_Zmumu_truth_match.log 2>&1 &
Run isMC ttbar electron > RLE_MC_ttbar_elec.log 2>&1 &
Run isMC ttbar muon > RLE_MC_ttbar_muon.log 2>&1 &
Run isMC GG_ttn1 electron > RLE_MC_GG_ttn1_elec.log 2>&1 &
Run isMC GG_ttn1 muon > RLE_MC_GG_ttn1_muon.log 2>&1 &