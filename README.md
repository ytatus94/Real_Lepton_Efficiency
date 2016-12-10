# Real_Lepton_Efficiency
This is the new real lepton efficiency framework.


### v31-10. (combine branch) Add two methods in `yt_cutflows`.
* Add `get_AvgMu()` and `get_pileup_weight()` which recalculate AvgMu and PRWWeight.


### v31-09. (combine branch) Add OSee and OSmumu AvgMu histograms.
1. Add OSee and OSmumu AvgMu histograms for data and MC in `ytEventSelection`.
2. Correct the weight when dump MC AvgMu.
3. Change space in `yt_cutflows.cxx`


### v31-08. (combine branch) Add stripts to run all skim and all cutflow.
1. Add two scripts `run_all_cutflow.sh` and `run_all_skim.sh`
2. Let `run_all_RLE.sh` to run in the background.


### v31-07. (combine branch) Add script to run all RLE.


### v31-06. (combine branch) Move `ytRealLeptonsEfficiency` to `misc/`


### v31-05. (combine branch) Add new skim code
1. Modify `yt_skim`, comment out the unnecessary parts related to jet.
2. Add `tag_pt_threshold` in `yt_skim` and `ytEventSelection`
3. The cross section, k-Factor, filter efficiency are passed into `yt_skim`, they are removed from `skim.cxx`
4. Correction `normalization` in `yt_skim` and set `normalization = 1` to Data.
5. Add `yt_useful_functions`.
6. Add skim part in `ytEventSelection`.


### v31-04. (combine branch) Remove functions and add histograms in `ytEventSelection`.
1. Remove the calculate weight functions.
2. Add histograms for Nvtx, AvgMu, NLepts, and NJets.


### v31-03. (combine branch) Rewrite `ytEventSelection`.
1. Rewrite the structure of `ytEventSelection` so it can get the correct cutflow results as before.
2. Add SUSYTools in package dependence.
3. Add log files for 4topSM, Zee, Zmumu, ttbar, GG_ttn1.


### v31-02. (combine branch) Add `ytRealLeptonsEfficiency` class
* `ytRealLeptonsEfficiency` is used to replace `ytRealLeptonsEfficiency_Data` and `ytRealLeptonsEfficiency_MC`


### v31-01. (combine branch) Correct typos 
1. Correct typos in `ytRealLeptonsEfficiency_MC`.
2. Change space in `ytEventSelection.cxx`

### v31. Rebin
1. Add the rebin histograms in `ytRelative_difference_of_efficiency.C`
2. Change the y-axis to percentage in `run_relative_differences_of_efficiency.py`

### v30. Correct typo
1. Correct typo in `ytRealLeptonsEfficiency_Data` and `ytRealLeptonsEfficiency_MC`.
2. Change function names in `run_elec_systematics.py`
3. Add two scripts for calculating the relative differeice of efficiencies `ytRelative_difference_of_efficiency.C` and `run_relative_differences_of_efficiency.py`.
4. Add new function in `ytPlots.C`

### v29. Add 3 dim histogram pt_eta_dRjet
1. And new 3 dim histograms pt_eta_dRjet for baseline and signal in `ytRealLeptonsEfficiency_Data` and `ytRealLeptonsEfficiency_MC`.



### v28. Move files
1. Move `compare_error_propagation.C`, `fitExclude.C`, and `run_bkg_subtraction.sh` from scripts/ to misc/.
2. Add two functions in `ytPlots.C` to study how the Gtt_electron cuts affect the efficiency.

### v27. Commit the README.md and ytPlots.C
1. Didn't commit `README.md` and `ytPlots.C` in v26 so commit them in v27.


### v26. Add 3-dim `pt_dRjet_mll` histograms
1. Add `h_baseline_pt_dRjet_mll` and `h_signal_pt_dRjet_mll` into `ytRealLeptonsEfficiency_Data` and `ytRealLeptonsEfficiency_MC`.
2. Change the input file path in `Run.cxx`, `ytPlots.C`, and `ytBackground_subtraction.C`
3. Fix the Zmumu legend in `yt_deltaR_and_NJets_distribution()` in `ytPlots.C`
4. Fix the typo in `run_muon_efficiency.py`
5. Change the directory path in `run_making_plots.py`



### v25. Add new script to calculate the muon systematics.
1. `run_muon_efficiency.py`


### v24. Fix buts in `run_systematics.py` and rename to `run_elec_systematics.py`


### v23. Add scripts for systematic uncertianty calculation.


### v22. Add mll window region in the output filename of bkg subtraction pdf plots.


### v21. Add script to make plots
1. `run_making_plots.py` is used to make mll plots, efficiency plots without bkg subtraction, and kinematic distributions.
2. Fix bugs in `run_background_subtraction.py` and `ytPlots.C`.


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
