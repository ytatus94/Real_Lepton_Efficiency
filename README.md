# Real_Lepton_Efficiency
This is the new real lepton efficiency framework.


### v20. Upload to ouhep05 and compile.
1. Fix errors after merging branches.


### v19. Correct the wrong merge parts.
1. In `ytRealLeptonsEfficiency_MC.cxx`.


### v18. Correct the wrong merge parts.
1. In `ytRealLeptonsEfficiency_MC.cxx` and `ytPlots.C`.


### v17. Correct the wrong merge parts.
1. In `ytEventSelection.cxx`, `run_Real_lepton_efficiency.py`, `ytPlots.C`


### v16. Merge ouhep05 branch into master branch.
1. Conflict files are:
   `ytRealLeptonsEfficiency_MC.h`, `Run.cxx`, `ytPlots.C`, `yt_cutflows.cxx`, 
   `ytRealLeptonsEfficiency_MC.cxx`, `ytEventSelection.cxx`, `README.md`
2. Auto-merging: `run_Real_lepton_efficiency.py`, 


### v01.(ouhep05 branch)-04. Move `share/*.*` to `misc/`
1. Move `share/*.*` to `misc/` and delete `share/`
2. Using markdown language in `README.md`


### v01.(ouhep05 branch)-03. Modify the `READMD.md`


### v01.(ouhep05 branch)-02. This are files on ouhep05.
The current results (20161006) are obtained using this version.


### v01.(ouhep05 branch)-01. This are files on ouhep05
The latest modified date of files is Sep./30/2016.


### v15. Correct the MC weight
1. `normalization * baseline_weight` and `normalization * signal_weight`.
2. Correct `EL_eta` and `Mu_eta` to `fabs(El_eta)` and `fabs(Mu_eta)`


### v14. Change the header size.


### v13. Apply markdown language on the `README.md`


### v12. Remove the wrong merge parts.
1. In `cutflow.cxx` and `ytRealLeptonsEfficiency_MC.cxx`


### v11. Merge ouhep04 branch into master branch.
1. Conflict files are:
   `ytEventSelection.h`, `cutflow.cxx`, `Run.cxx`, `ytEventSelection.cxx`, `README.md`
2. Auto-merging: `ytRealLeptonsEfficiency_MC.cxx`


### v01.(ouhep04 branch)-04. Move `share/*.*` to `misc/` and delete `share/`.


### v01.(ouhep04 branch)-03. Modify the `README.md`


### v01.(ouhep04 branch)-02. This is the version on ouhep04.
The latest modified data of files on ouhep04 is Sep./29/2016.


### v01.(ouhep04 branch)-01. This is the version on ouhep04.
The latest modified data of files on ouhep04 is Sep./22/2016.


### v10. Add 2 functions in ytPlot.C and add a python script.
1. Add `yt_kinematics_distribution()` and `yt_deltaR_and_NJets_distribution()`
2. Add `run_background_subtraction.py` in `python/`


### v09. Loose the template 1 requirements.
1. Both Calo and Track isolation variable require > 6% for template 1.
2. chmod 755 python scripts.
3. Fix bugs in `run_bkg_subtraction.sh`.
4. Change the input folder in `ytPlots.C` and `ytBackground_subtraction.C`.
5. Add `Xsec.txt` for the Sherpa samples.


### v08. Redirect the output of `run_bkg_subtraction.sh`.
1. Redirect the output so I can use another script to get the results.
2. Add `New_Skimmed` class


### v07. Correct background subtraction.
1. In the `ytBackground_subtraction.C`:
   a. Fix the bug when `N_sig = 0`.
   b. Add the error propagation.
   c. Finalize the background subtraction.
   d. Fix the norm < 0 bug which happens on 10 < pT < 15 and 0 < eta < 0.8. Add a patch to fix it.
2. Add function to save plots in `ytPlots.C`.
3. Add variations in `run_bkg_subtraction.sh`.


### v06. Add skim
1. Add `yt_skim in LinkDef.h`
2. Add new skim class: `yt_skim`.
3. Overload `fill_electrons()`, `fill_muons()`, and `fill_jets()` for data and MC in `ytEventSelection` class.
4. Add weight calculation methods in `ytEventSelection` class.


### v05. Add `retrieve.py`
1. Add retrieve.py to retrieve files from condor or grid.


### v04. Add Condor, PROOF driver
1. Add `EventLoopGrid` package in `Makefile.RootCore`.
2. Change to `rcSetup Base, 2.4.19` and add python path in `setupRealEfficiency.sh`.
3. Add a toy MC `compare_error_propagation.C` to check the error propagation.
4. Split `cutflow.cxx` to `cutflow.cxx` and `skim.cxx`.
5. Add Condor and PROOF drivers in `cutflow.cxx` and `Run.cxx`


### v03. Add GRL and PRW
1. Add `baseline_weight` and `signal_weight` in `ytRealLeptonsEfficiency_MC` class.
2. Add `data/GRL` and `data/PRW` and put the GRL and PRW files into thest two folders.
3. Modify the GRL and PRW path in the `yt_cutflows` class.
4. Change the type of `events_pass_cutflow` from int to double in order to keep `derivationStat_weight`.


### v02. Move `share/*` to `misc/`
1. Move `AnaNtup_Data`, `AnaNtup_MC`, `Skimmed_Data`, and `Skimmed_MC` from `share/` to `misc/`, then delete `share/`.


### v01. The initial commit.
1. The `ytRealLeptonsEfficiency_MC` still have some bugs about the MC normalization.
   The current version get Zee MC 20% more than data and Zmumu MC 10% more than data.
   But this might cause by the PRW input file in the skim. To be check...
2. Both `ytRealLeptonsEfficiency_MC` and `ytRealLeptonsEfficiency_Data` need to implement dilepton trigger in the future.
   The current version only supply single lepton trigger.
3. The `ytEventSelection` is under developing and it only supports MC sample now.
   Need to implement a way to get the `DerivationStat_Weight` from the histogram in the root file.
   Nils suggested two ways but I don't like them. :(
4. The python script `run_Real_lepton_efficiency.py` is under developing.
   Use the command line to run the framework for now.
5. It seems no one use `useful_functions.cxx`, so I move it from `Root/` to `misc/`.
6. The `ytBackground_subtraction.C` works well but the uncertainty proparagation need to be included.
   The current version doesn't consider the uncertainty proparagation.
7. `ytPlots.C` needs to add a function to make efficiency plots after applying background subtraction.
8. The TSelector codes of the analysis ntuples and skimmed ntuples are put in `share/`.
9. Both `cutflow.cxx` and `Run.cxx` only support to execute framework on local machine. Will implement the Grid in the future.
