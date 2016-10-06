#!/usr/bin/python
import ROOT

data_path = "/UserDisk2/yushen/Ximo_ntuples/v44/Data/"
mc_path = "/UserDisk2/yushen/Ximo_ntuples/v44/MC/"

f_data = ROOT.TFile(data_path + "merged_all_data.root")
data_derivation_stat_weights = f_data.Get("DerivationStat_Weights").GetBinContent(1)
print "data: ", data_derivation_stat_weights

f_Zee_merged = ROOT.TFile(mc_path + "Zee_merged.root")
Zee_merged_derivation_stat_weights = f_Zee_merged.Get("DerivationStat_Weights").GetBinContent(1)
print "Zee: ", Zee_merged_derivation_stat_weights

f_Zmumu_merged = ROOT.TFile(mc_path + "Zmumu_merged.root")
Zmumu_merged_derivation_stat_weights = f_Zmumu_merged.Get("DerivationStat_Weights").GetBinContent(1)
print "Zmumu: ", Zmumu_merged_derivation_stat_weights

f_ttbar_merged = ROOT.TFile(mc_path + "ttbar_merged.root")
ttbar_merged_derivation_stat_weights = f_ttbar_merged.Get("DerivationStat_Weights").GetBinContent(1)
print "ttbar: ", ttbar_merged_derivation_stat_weights

f_GG_ttn1_merged = ROOT.TFile(mc_path + "GG_ttn1_merged.root")
GG_ttn1_merged_derivation_stat_weights = f_GG_ttn1_merged.Get("DerivationStat_Weights").GetBinContent(1)
print "GG_ttn1: ", GG_ttn1_merged_derivation_stat_weights
