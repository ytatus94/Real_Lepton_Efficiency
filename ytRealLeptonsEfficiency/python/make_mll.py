#!/usr/bin/python
import os, ROOT
os.sys.argv.append( '-b-' ) #Batch mode, same as python <somescript>.py -b

fdata = ROOT.TFile("skimmed_Data/hist-Data.root")
fZee = ROOT.TFile("skimmed_MC_Zee/hist-MC.root")
fZmumu = ROOT.TFile("skimmed_MC_Zmumu/hist-MC.root")

h_data_baseline_OSee_mll = fdata.Get("h_baseline_OSee_mll")
h_data_baseline_OSmumu_mll = fdata.Get("h_baseline_OSmumu_mll")
h_data_signal_OSee_mll = fdata.Get("h_signal_OSee_mll")
h_data_signal_OSmumu_mll = fdata.Get("h_signal_OSmumu_mll")

h_Zee_baseline_OSee_mll_weighted = fZee.Get("h_baseline_OSee_mll_weighted")
h_Zee_signal_OSee_mll_weighted = fZee.Get("h_signal_OSee_mll_weighted")

h_Zmumu_baseline_OSmumu_mll_weighted = fZmumu.Get("h_baseline_OSmumu_mll_weighted")
h_Zmumu_signal_OSmumu_mll_weighted = fZmumu.Get("h_signal_OSmumu_mll_weighted")

c1 = ROOT.TCanvas("baseline_Mee")
h_data_baseline_OSee_mll.SetLineColor(0)
h_data_baseline_OSee_mll.SetMarkerColor(1)
h_data_baseline_OSee_mll.SetMarkerSize(1)
h_data_baseline_OSee_mll.SetMarkerStyle(20)
h_data_baseline_OSee_mll.Draw("E1")
h_Zee_baseline_OSee_mll_weighted.SetLineColor(2) #kRed
h_Zee_baseline_OSee_mll_weighted.Draw("hist,same")
c1.SaveAs("baseline_Mee.pdf")

c2 = ROOT.TCanvas("baseline_Mmumu")
h_data_baseline_OSmumu_mll.SetLineColor(0)
h_data_baseline_OSmumu_mll.SetMarkerColor(1))
h_data_baseline_OSmumu_mll.SetMarkerSize(1)
h_data_baseline_OSmumu_mll.SetMarkerStyle(20)
h_data_baseline_OSmumu_mll.Draw("E1")
h_Zmumu_baseline_OSmumu_mll_weighted.SetLineColor(3) #kRed
h_Zmumu_baseline_OSmumu_mll_weighted.Draw("hist,same")
c2.SaveAs("baseline_Mmumu.pdf")

c3 = ROOT.TCanvas("signal_Mee")
h_data_signal_OSee_mll.SetLineColor(0)
h_data_signal_OSee_mll.SetMarkerColor(1)
h_data_signal_OSee_mll.SetMarkerSize(1)
h_data_signal_OSee_mll.SetMarkerStyle(20)
h_data_signal_OSee_mll.Draw("E1")
h_Zee_signal_OSee_mll_weighted.SetLineColor(2) #kRed
h_Zee_signal_OSee_mll_weighted.Draw("hist,same")
c3.SaveAs("signal_Mee.pdf")

c4 = ROOT.TCanvas("signal_Mmumu")
h_data_signal_OSmumu_mll.SetLineColor(0)
h_data_signal_OSmumu_mll.SetMarkerColor(1)
h_data_signal_OSmumu_mll.SetMarkerSize(1)
h_data_signal_OSmumu_mll.SetMarkerStyle(20)
h_data_signal_OSmumu_mll.Draw("E1")
h_Zmumu_signal_OSmumu_mll_weighted.SetLineColor(3) #kRed
h_Zmumu_signal_OSmumu_mll_weighted.Draw("hist,same")
c4.SaveAs("signal_Mmumu.pdf")