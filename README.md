# Real_Lepton_Efficiency
This is the new real lepton efficiency framework.

v01.(ouhep04 branch)-03. Modify the README.md

v01.(ouhep04 branch)-02. This is the version on ouhep04.
The latest modified data of files on ouhep04 is Sep./29/2016.

v01.(ouhep04 branch)-01. This is the version on ouhep04.
The latest modified data of files on ouhep04 is Sep./22/2016.

v01. The initial commit.
1. The ytRealLeptonsEfficiency_MC still have some bugs about the MC normalization.
   The current version get Zee MC 20% more than data and Zmumu MC 10% more than data.
   But this might cause by the PRW input file in the skim. To be check...
2. Both ytRealLeptonsEfficiency_MC and ytRealLeptonsEfficiency_Data need to implement dilepton trigger in the future.
   The current version only supply single lepton trigger.
3. The ytEventSelection is under developing and it only supports MC sample now.
   Need to implement a way to get the DerivationStat_Weight from the histogram in the root file.
   Nils suggested two ways but I don't like them. :(
4. The python script run_Real_lepton_efficiency.py is under developing.
   Use the command line to run the framework for now.
5. It seems no one use useful_functions.cxx, so I move it from Root/ to misc/.
6. The ytBackground_subtraction.C works well but the uncertainty proparagation need to be included.
   The current version doesn't consider the uncertainty proparagation.
7. ytPlots.C needs to add a function to make efficiency plots after applying background subtraction.
8. The TSelector codes of the analysis ntuples and skimmed ntuples are put in share/.
9. Both cutflow.cxx and Run.cxx only support to execute framework on local machine. Will implement the Grid in the future.
