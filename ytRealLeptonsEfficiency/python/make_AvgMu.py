#!/usr/bin/python
sys.argv.append( '-b-' ) #Batch mode, same as python <somescript>.py -b
import ROOT
fdata = ROOT.TFile("skimmed_Data/hist-Data.root")
fZee = ROOT.TFile("skimmed_MC_Zee/hist-MC.root")
fZmumu = ROOT.TFile("skimmed_MC_Zmumu/hist-MC.root")

h_data_AvgMu_OSee = fdata.Get("h_AvgMu_OSee")
h_data_AvgMu_OSmumu = fdata.Get("h_AvgMu_OSmumu")
h_Zee_AvgMu_OSee = fZee.Get("h_AvgMu_OSee_weighted")
h_Zmumu_AvgMu_OSmumu = fZmumu.Get("h_AvgMu_OSmumu_weighted")

c1 = ROOT.TCanvas("ee")
c1.SetLogy()
h_data_AvgMu_OSee.SetLineColor(1) #kBlack
h_data_AvgMu_OSee.SetMarkerColor(1)
h_data_AvgMu_OSee.SetMarkerSize(1)
h_data_AvgMu_OSee.SetMarkerStyle(20)
h_data_AvgMu_OSee.Draw("E1")
h_Zee_AvgMu_OSee.SetLineColor(2) #kRed
h_Zee_AvgMu_OSee.Draw("hist,same")
c1.SaveAs("AvgMu_OSee.pdf")

c2 = ROOT.TCanvas("mumu")
c2.SetLogy()
h_data_AvgMu_OSmumu.SetLineColor(1)
h_data_AvgMu_OSmumu.SetMarkerColor(1)
h_data_AvgMu_OSmumu.SetMarkerSize(1)
h_data_AvgMu_OSmumu.SetMarkerStyle(20)
h_data_AvgMu_OSmumu.Draw("E1")
h_Zmumu_AvgMu_OSmumu.SetLineColor(4) #kBlue
h_Zmumu_AvgMu_OSmumu.Draw("hist,same")
c2.SaveAs("AvgMu_OSmumu.pdf")
