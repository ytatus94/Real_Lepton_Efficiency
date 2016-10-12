#!/usr/bin/python
import os

print "1.) Skim data and MC"
print "2.) Calculate real lepton efficiency"
print "What you want to do?"
do_job = raw_input()

if int(do_job) == 1:
  print "Skim data and MC:"
  print "1.) cutflow isData"
  print "2.) cutflow isMC Zee"
  print "3.) cutflow isMC Zmumu"
  print "4.) cutflow isMC ttbar"
  print "5.) cutflow isMC GG_ttn1 (default is boosted with mass difference > 1 TeV)"
  print "6.) cutflow isMC GG_ttn1 compressed"
  print "What you want to do?"
  skim_job = raw_input()
  if int(skim_job) == 1:
    print "cutflow isData"
    os.system("time cutflow isData")
  elif int(skim_job) == 2:
    print "cutflow isMC Zee"
    os.system("time cutflow isMC Zee")
  elif int(skim_job) == 3:
    print "cutflow isMC Zmumu"
    os.system("time cutflow isMC Zmumu")
  elif int(skim_job) == 4:
    print "cutflow isMC ttbar"
    os.system("time cutflow isMC ttbar")
  elif int(skim_job) == 5:
    print "cutflow isMC GG_ttn1"
    os.system("time cutflow isMC GG_ttn1")
  elif int(skim_job) == 6:
    print "Sorry, didn't implement this yet."
    #print "cutflow isMC GG_ttn1 compressed"
    #os.system("time cutflow isMC GG_ttn1 compressed")
elif int(do_job) == 2:
  print "Calculate real lepton efficiency:"
  print "1.) Run isData electron"
  print "2.) Run isData muon"
  print "3.) Run isMC Zee"
  print "4.) Run isMC Zmumu"
  print "5.) Run isMC Zee_truth_match"
  print "6.) Run isMC Zmumu_truth_match"
  print "7.) Run isMC Zee_TandP_truth_match"
  print "8.) Run isMC Zmumu_TandP_truth_match"
  print "9.) Run isMC ttbar electron"
  print "10.) Run isMC ttbar muon"
  print "11.) Run isMC GG_ttn1 electron"
  print "12.) Run isMC GG_ttn1 muon"
  print "What you want to do?"
  rle_job = raw_input()
  if int(rle_job) == 1:
    print "Run isData electron"
    os.system("Run isData electron")
  elif int(rle_job) == 2:
    print "Run isData muon"
    os.system("Run isData muon")
  elif int(rle_job) == 3:
    print "Run isMC Zee"
    os.system("Run isMC Zee")
  elif int(rle_job) == 4:
    print "Run isMC Zmumu"
    os.system("Run isMC Zmumu")
  elif int(rle_job) == 5:
    print "Run isMC Zee_truth_match"
    os.system("Run isMC Zee_truth_match")
  elif int(rle_job) == 6:
    print "Run isMC Zmumu_truth_match"
    os.system("Run isMC Zmumu_truth_match")
  elif int(rle_job) == 7:
    print "Run isMC Zee_TandP_truth_match"
    os.system("Run isMC Zee_TandP_truth_match")
  elif int(rle_job) == 8:
    print "Run isMC Zmumu_TandP_truth_match"
    os.system("Run isMC Zmumu_TandP_truth_match")
  elif int(rle_job) == 9:
    print "Run isMC ttbar electron"
    os.system("Run isMC ttbar electron")
  elif int(rle_job) == 10:
    print "Run isMC ttbar muon"
    os.system("Run isMC ttbar muon")
  elif int(rle_job) == 11:
    print "Run isMC GG_ttn1 electron"
    os.system("Run isMC GG_ttn1 electron")
  elif int(rle_job) == 12:
    print "Run isMC GG_ttn1 muon"
    os.system("Run isMC GG_ttn1 muon")

