#!/usr/bin/python
import os, ROOT, math, array

#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(10, 20)' > relative_difference_of_efficiency_pt1020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(20, 30)' > relative_difference_of_efficiency_pt2030.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(30, 50)' > relative_difference_of_efficiency_pt3050.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(50, 80)' > relative_difference_of_efficiency_pt5080.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(80, 200)' > relative_difference_of_efficiency_pt80200.txt")

# 0 < |eta| < 2 for electron
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(10, 20, true, true)' > ../scripts/relative_difference_of_efficiency_pt1020_eta020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(20, 30, true, true)' > ../scripts/relative_difference_of_efficiency_pt2030_eta020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(30, 50, true, true)' > ../scripts/relative_difference_of_efficiency_pt3050_eta020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(50, 80, true, true)' > ../scripts/relative_difference_of_efficiency_pt5080_eta020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(80, 200, true, true)' > ../scripts/relative_difference_of_efficiency_pt80200_eta020.txt")

dR_bin1 = []
dR_bin2 = []
dR_bin3 = []
dR_bin4 = []
dR_bin5 = []
dR_bin6 = []

dR_bin1_err = []
dR_bin2_err = []
dR_bin3_err = []
dR_bin4_err = []
dR_bin5_err = []
dR_bin6_err = []

#filelist = ['relative_difference_of_efficiency_pt1020.txt',
#            'relative_difference_of_efficiency_pt2030.txt',
#            'relative_difference_of_efficiency_pt3050.txt',
#            'relative_difference_of_efficiency_pt5080.txt',
#            'relative_difference_of_efficiency_pt80200.txt']

filelist = ['../scripts/relative_difference_of_efficiency_pt1020_eta020.txt',
            '../scripts/relative_difference_of_efficiency_pt2030_eta020.txt',
            '../scripts/relative_difference_of_efficiency_pt3050_eta020.txt',
            '../scripts/relative_difference_of_efficiency_pt5080_eta020.txt',
            '../scripts/relative_difference_of_efficiency_pt80200_eta020.txt']

for filename in filelist:
    with open(filename) as fopen:
        lines = fopen.readlines()
        for line in lines:
            if "bin=1:" in line: 
                dR_bin1.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin1_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)
            elif "bin=2:" in line:
                dR_bin2.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin2_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)
            elif "bin=3:" in line:
                dR_bin3.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin3_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)
            elif "bin=4:" in line:
                dR_bin4.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin4_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)
            elif "bin=5:" in line:
                dR_bin5.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin5_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)
            elif "bin=6:" in line:
                dR_bin6.append(float(line[line.find(":")+2: line.find("$pm$")-1]) * 100.)
                dR_bin6_err.append(float(line[line.find("$pm$")+5: len(line)-1]) * 100.)

ttbar_elec_dR_bin1 = dR_bin1[0::4]
ttbar_elec_dR_bin2 = dR_bin2[0::4]
ttbar_elec_dR_bin3 = dR_bin3[0::4]
ttbar_elec_dR_bin4 = dR_bin4[0::4]
ttbar_elec_dR_bin5 = dR_bin5[0::4]
ttbar_elec_dR_bin6 = dR_bin6[0::4]

ttbar_elec_dR_bin1_err = dR_bin1_err[0::4]
ttbar_elec_dR_bin2_err = dR_bin2_err[0::4]
ttbar_elec_dR_bin3_err = dR_bin3_err[0::4]
ttbar_elec_dR_bin4_err = dR_bin4_err[0::4]
ttbar_elec_dR_bin5_err = dR_bin5_err[0::4]
ttbar_elec_dR_bin6_err = dR_bin6_err[0::4]

ttbar_muon_dR_bin1 = dR_bin1[1::4]
ttbar_muon_dR_bin2 = dR_bin2[1::4]
ttbar_muon_dR_bin3 = dR_bin3[1::4]
ttbar_muon_dR_bin4 = dR_bin4[1::4]
ttbar_muon_dR_bin5 = dR_bin5[1::4]
ttbar_muon_dR_bin6 = dR_bin6[1::4]

ttbar_muon_dR_bin1_err = dR_bin1_err[1::4]
ttbar_muon_dR_bin2_err = dR_bin2_err[1::4]
ttbar_muon_dR_bin3_err = dR_bin3_err[1::4]
ttbar_muon_dR_bin4_err = dR_bin4_err[1::4]
ttbar_muon_dR_bin5_err = dR_bin5_err[1::4]
ttbar_muon_dR_bin6_err = dR_bin6_err[1::4]

Gtt_elec_dR_bin1 = dR_bin1[2::4]
Gtt_elec_dR_bin2 = dR_bin2[2::4]
Gtt_elec_dR_bin3 = dR_bin3[2::4]
Gtt_elec_dR_bin4 = dR_bin4[2::4]
Gtt_elec_dR_bin5 = dR_bin5[2::4]
Gtt_elec_dR_bin6 = dR_bin6[2::4]

Gtt_elec_dR_bin1_err = dR_bin1_err[2::4]
Gtt_elec_dR_bin2_err = dR_bin2_err[2::4]
Gtt_elec_dR_bin3_err = dR_bin3_err[2::4]
Gtt_elec_dR_bin4_err = dR_bin4_err[2::4]
Gtt_elec_dR_bin5_err = dR_bin5_err[2::4]
Gtt_elec_dR_bin6_err = dR_bin6_err[2::4]

Gtt_muon_dR_bin1 = dR_bin1[3::4]
Gtt_muon_dR_bin2 = dR_bin2[3::4]
Gtt_muon_dR_bin3 = dR_bin3[3::4]
Gtt_muon_dR_bin4 = dR_bin4[3::4]
Gtt_muon_dR_bin5 = dR_bin5[3::4]
Gtt_muon_dR_bin6 = dR_bin6[3::4]

Gtt_muon_dR_bin1_err = dR_bin1_err[3::4]
Gtt_muon_dR_bin2_err = dR_bin2_err[3::4]
Gtt_muon_dR_bin3_err = dR_bin3_err[3::4]
Gtt_muon_dR_bin4_err = dR_bin4_err[3::4]
Gtt_muon_dR_bin5_err = dR_bin5_err[3::4]
Gtt_muon_dR_bin6_err = dR_bin6_err[3::4]

ttbar_elec_dR_bins = [ttbar_elec_dR_bin1, ttbar_elec_dR_bin2, ttbar_elec_dR_bin3, ttbar_elec_dR_bin4, ttbar_elec_dR_bin5, ttbar_elec_dR_bin6]
ttbar_elec_dR_bins_err = [ttbar_elec_dR_bin1_err, ttbar_elec_dR_bin2_err, ttbar_elec_dR_bin3_err, ttbar_elec_dR_bin4_err, ttbar_elec_dR_bin5_err, ttbar_elec_dR_bin6_err]
ttbar_muon_dR_bins = [ttbar_muon_dR_bin1, ttbar_muon_dR_bin2, ttbar_muon_dR_bin3, ttbar_muon_dR_bin4, ttbar_muon_dR_bin5, ttbar_muon_dR_bin6]
ttbar_muon_dR_bins_err = [ttbar_muon_dR_bin1_err, ttbar_muon_dR_bin2_err, ttbar_muon_dR_bin3_err, ttbar_muon_dR_bin4_err, ttbar_muon_dR_bin5_err, ttbar_elec_dR_bin6_err]

Gtt_elec_dR_bins = [Gtt_elec_dR_bin1, Gtt_elec_dR_bin2, Gtt_elec_dR_bin3, Gtt_elec_dR_bin4, Gtt_elec_dR_bin5, Gtt_elec_dR_bin6]
Gtt_elec_dR_bins_err = [Gtt_elec_dR_bin1_err, Gtt_elec_dR_bin2_err, Gtt_elec_dR_bin3_err, Gtt_elec_dR_bin4_err, Gtt_elec_dR_bin5_err, Gtt_elec_dR_bin6_err]
Gtt_muon_dR_bins = [Gtt_muon_dR_bin1, Gtt_muon_dR_bin2, Gtt_muon_dR_bin3, Gtt_muon_dR_bin4, Gtt_muon_dR_bin5, Gtt_muon_dR_bin6]
Gtt_muon_dR_bins_err = [Gtt_muon_dR_bin1_err, Gtt_muon_dR_bin2_err, Gtt_muon_dR_bin3_err, Gtt_muon_dR_bin4_err, Gtt_muon_dR_bin5_err, Gtt_muon_dR_bin6_err]


def make_plot(canvas_name, y, y_err):
    # Split into 5 dR bins
    dR_bin_1 = array.array("d", y[0])
    dR_bin_2 = array.array("d", y[1])
    dR_bin_3 = array.array("d", y[2])
    dR_bin_4 = array.array("d", y[3])
    dR_bin_5 = array.array("d", y[4])
    dR_bin_6 = array.array("d", y[5])

    dR_bin_1_err = array.array("d", y_err[0])
    dR_bin_2_err = array.array("d", y_err[1])
    dR_bin_3_err = array.array("d", y_err[2])
    dR_bin_4_err = array.array("d", y_err[3])
    dR_bin_5_err = array.array("d", y_err[4])
    dR_bin_6_err = array.array("d", y_err[5])

    pt_bin_center = array.array("d", [(10.+20.)/2., (20.+30.)/2., (30.+50.)/2, (50.+80.)/2, (80.+200.)/2])
    pt_bin_err = array.array("d", [(20.-10.)/2., (30.-20.)/2, (50.-30.)/2, (80.-50.)/2, (200.-80.)/2])

    canvas = ROOT.TCanvas("canvas_" + canvas_name, "Relative differences", 600, 600)
    mg = ROOT.TMultiGraph()
    mg.SetTitle("")

    gr1 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_1, pt_bin_err, dR_bin_1_err)
    gr1.SetName("gr1")
    gr1.SetMarkerColor(1) #kBlack
    gr1.SetMarkerStyle(20) #kFullCircle
    gr1.SetLineColor(1)

    gr2 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_2, pt_bin_err, dR_bin_2_err)
    gr2.SetName("gr2")
    gr2.SetMarkerColor(2) #kRed
    gr2.SetMarkerStyle(21) #kFullSquare
    gr2.SetLineColor(2)

    gr3 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_3, pt_bin_err, dR_bin_3_err)
    gr3.SetName("gr3")
    gr3.SetMarkerColor(3) #kGreen
    gr3.SetMarkerStyle(22) #kFullTriangleUp
    gr3.SetLineColor(3)

    gr4 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_4, pt_bin_err, dR_bin_4_err)
    gr4.SetName("gr4")
    gr4.SetMarkerColor(4) #kBlue
    gr4.SetMarkerStyle(23) #kFullTriangleDown
    gr4.SetLineColor(4)

    gr5 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_5, pt_bin_err, dR_bin_5_err)
    gr5.SetName("gr5")
    gr5.SetMarkerColor(6) #kMagenta
    gr5.SetMarkerStyle(33) #kFullDiamond
    gr5.SetLineColor(6)

    gr6 = ROOT.TGraphErrors(len(pt_bin_center), pt_bin_center, dR_bin_6, pt_bin_err, dR_bin_6_err)
    gr6.SetName("gr6")
    gr6.SetMarkerColor(42) #
    gr6.SetMarkerStyle(34) #kFullCross
    gr6.SetLineColor(42)

    #mg.Add(gr1)
    mg.Add(gr2)
    mg.Add(gr3)
    mg.Add(gr4)
    mg.Add(gr5)
    mg.Add(gr6)
    mg.Draw("AP")
    mg.GetXaxis().SetTitle("p_{T} [GeV]")
    mg.GetYaxis().SetTitle("Relative differences of efficiency (%)")
    mg.SetMaximum(99.)
    mg.SetMinimum(0.)

    leg = ROOT.TLegend(0.6, 0.6, 0.9, 0.9)
    #leg.AddEntry("gr1", "0. < #Delta R < 0.2", "LP")
    leg.AddEntry("gr2", "0.2 < #Delta R < 0.4", "LP")
    leg.AddEntry("gr3", "0.4 < #Delta R < 0.6", "LP")
    leg.AddEntry("gr4", "0.6 < #Delta R < 1.0", "LP")
    leg.AddEntry("gr5", "1.0 < #Delta R < 2.0", "LP")
    leg.AddEntry("gr6", "2.0 < #Delta R < 4.0", "LP")

    leg.SetBorderSize(0);
    leg.SetTextFont(42);
    leg.SetTextSize(0.03);
    leg.SetFillColor(0);
    leg.SetFillStyle(0);
    leg.Draw("same")

    #canvas.SaveAs(canvas_name + ".pdf", "pdf")
    canvas.SaveAs(canvas_name + "_eta020.pdf", "pdf")

make_plot("Zee_ttbar_differences", ttbar_elec_dR_bins, ttbar_elec_dR_bins_err)
make_plot("Zee_GG_ttn1_differences", Gtt_elec_dR_bins, Gtt_elec_dR_bins_err)
make_plot("Zmumu_ttbar_differences", ttbar_muon_dR_bins, ttbar_muon_dR_bins_err)
make_plot("Zmumu_GG_ttn1_differences", Gtt_muon_dR_bins, Gtt_muon_dR_bins_err)
