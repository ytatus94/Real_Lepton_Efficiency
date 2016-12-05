// Usage:
// skim isData [PROOF/Condor]
// skim isMC Zee/Zmumu/ttbar [PROOF/Condor]
// skim isMC GG_ttn1 [PROOF/Condor]: uses boosed region of Gtt
// skim isMC GG_ttn1 compressed [PROOF/Condor]: uses compressed region of Gtt

#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/Sample.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/ProofDriver.h"
#include "EventLoop/CondorDriver.h"
#include "EventLoopGrid/PrunDriver.h"
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>
#include <TH1.h>

#include "ytRealLeptonsEfficiency/ytEventSelection.h"

#include <iostream>
#include <string>
using namespace std;

float boosted_mass = 1000.; // unit: GeV

int main( int argc, char* argv[] ) {

    bool isMC = false;
    bool isData = false;

    string process;

    bool isBoosted = true; // default use boosted Gtt

    bool use_Condor = false;
    bool use_Grid = false;
    bool use_PROOF = false;

    for (int i = 1; i < argc; i++) {
        const char *key = argv[i];
        // Check MC or data.
        if (strcmp(key, "isMC") == 0)
            isMC = true;
        else if (strcmp(key, "isData") == 0)
            isData = true;
        // Choose samples to run.
        else if (strcmp(key, "4topSM") == 0)
            process = "4topSM";
        else if (strcmp(key, "Zee") == 0)
            process = "Zee";
        else if (strcmp(key, "Zmumu") == 0)
            process = "Zmumu";
        else if (strcmp(key, "ttbar") == 0)
            process = "ttbar";
        else if (strcmp(key, "GG_ttn1") == 0)
            process = "GG_ttn1";
        // Run boosted or compressed for GG_ttn1?
        else if (strcmp(key, "compressed") == 0)
            isBoosted = false;
        // Specify the driver to run.
        else if (strcmp(key, "Condor") == 0)
            use_Condor = true;
        else if (strcmp(key, "Grid") == 0)
            use_Grid = true;
        else if (strcmp(key, "PROOF") == 0)
            use_PROOF = true;
    }

    printf("isMC = %s, isData = %s\n", isMC ? "true" : "false", isData ? "true" : "false");

    if (use_Condor) {
        printf("Submit jobs to CondorDriver...\n");
    }
    else if (use_Grid) {
        printf("Submit jobs to PrunDriver...\n");
    }
    else if (use_PROOF) {
        printf("Submit jobs to ProofDriver...\n");
    }
    else {
        printf("Submit jobs to DirectDriver...\n");
    }

    if (isMC && !process.empty())
        cout << "process = " << process << endl;

    string submitDir;
    if (isMC)
        submitDir = "skimmed_MC_" + process;
    else if (isData)
        submitDir = "skimmed_Data";

    // Construct the samples to run on:
    SH::SampleHandler sh;

    // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
    const char* inputFilePath;

    const double luminosity = 13.2; // unit: 1/fb, Ximo: the lumi is 13.2 for the ichep analysis
    // cross section, k factor, and filter efficiency are obtained from
    // https://svnweb.cern.ch/trac/atlasphys-susy/browser/Physics/SUSY/Analyses/SameSignLeptonsJets/trunk/Data/ss3l_xsect.txt
    double cross_section = 1.;
    double k_factor = 1.;
    double filter_efficiency = 1.;
    double derivation_stat_weights = 1.;

	if (isMC) {
		cout << "Read MC files..." << endl;
		inputFilePath = "/raid05/users/shen/Ximo_ntuples/v44/MC"; // no slash (/) at the end.
		// For cutflow study
		if (process == "4topSM") {
			//inputFilePath = "/UserDisk2/yushen/Ximo_ntuples/v44/MC/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root";
			//SH::ScanDir().filePattern("user.jpoveda.9048853._000001.output.root").scan(sh, inputFilePath);
			SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*4topSM*").scan(sh, inputFilePath); // Get all root files in this dataset

			cross_section = 0.0091622 * 1000.; // in fb
			k_factor = 1.0042;
			filter_efficiency = 1.;
			derivation_stat_weights = 1.988000e+05;	
		}
		// For real lepton efficiency study
		else if (process == "Zee") {
			//SH::ScanDir().filePattern("Zee_merged.root").scan(sh, inputFilePath); // Get specific root file
			SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*Zee*").scan(sh, inputFilePath); // Get all root files in this dataset

			cross_section = 1901.2 * 1000.; // in fb
			k_factor = 1.026;
			filter_efficiency = 1.;
			derivation_stat_weights = 37868855526.2;
		}
		else if (process == "Zmumu") {
			//SH::ScanDir().filePattern("Zmumu_merged.root").scan(sh, inputFilePath); // Get specific root file
			SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*Zmumu*").scan(sh, inputFilePath); // Get all root files in this dataset

			cross_section = 1901.2 * 1000.; // in fb
			k_factor = 1.026;
			filter_efficiency = 1.;
			derivation_stat_weights = 34148906472.4;
		}
		else if (process == "ttbar") {
			//SH::ScanDir().filePattern("ttbar_merged.root").scan(sh, inputFilePath); // Get specific root file
			SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*ttbar*nonallhad*").scan(sh, inputFilePath); // Get all root files in this dataset

			cross_section = 696.11 * 1000.; // in fb
			k_factor = 1.1949;
			filter_efficiency = 0.543;
			derivation_stat_weights = 49386600.0;
		}
		else if (process == "GG_ttn1") {
			//SH::ScanDir().filePattern("GG_ttn1_merged.root").scan(sh, inputFilePath); // Get specific root file
			//SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*GG_ttn1_*.root").scan(sh, inputFilePath); // Get all root files in this dataset

			// First do an inclusive scan
			SH::SampleHandler sh_gtt;
			SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*GG_ttn1_*.root").scan(sh_gtt, inputFilePath); // Get all root files in this dataset	

			for (auto & sample : sh_gtt) {
				// Get the full path of root file: /path/data_set/root_file
				// We only need to know the data_set name, so the index file of fileName uses 0 is enough.
				string filename = sample->fileName(0);
				//cout << filename << endl;
				int pos_GG_ttn1 = filename.find("GG_ttn1");
				string str("GG_ttn1_");
				int length_GG_ttn1_ = str.length();
				int begin_pos = pos_GG_ttn1 + length_GG_ttn1_;
				int pos_DAOD = filename.find(".DAOD"); // includes the "."
				int length_to_retrieve = pos_DAOD - begin_pos;
				string mass_values = filename.substr(begin_pos, length_to_retrieve);
				int length_mass_values = mass_values.length();
				int pos_delimiter1 = mass_values.find("_");
				float m1 = stof(mass_values.substr(0, pos_delimiter1));
				int pos_delimiter2 = mass_values.find("_", pos_delimiter1 + 1);
				//float m2 = stof(mass_values.substr(pos_delimiter1 + 1, pos_delimiter2 - (pos_delimiter1 + 1)));
				float m3 = stof(mass_values.substr(pos_delimiter2 + 1, length_mass_values - (pos_delimiter2 + 1)));
				float delta_mass = m1 - m3;
				//cout << "delta_mass=" << delta_mass << endl;
				// Then filter the samples
				if (isBoosted && // Boosted region
					delta_mass > boosted_mass) {
					sh.add(sample);
				}
				else if (!isBoosted) { // Compressed region
					cout << "What is the definition of compressed region?" << endl;
					// To be implemented.
				}
			}
			// Couldn't find information. Set to 1.
			cross_section = 1.;
			k_factor = 1.;
			filter_efficiency = 1.;
			derivation_stat_weights = 4521452.27602;
		}
	}
	else if (isData) {
		cout << "Read Data files..." << endl;
		inputFilePath = "/raid05/users/shen/Ximo_ntuples/v44/Data"; // no slash (/) at the end.
		//SH::ScanDir().scan(sh, inputFilePath); // Get all datasets in inputFilePath
		//SH::ScanDir().filePattern("merged_all_data.root").scan(sh, inputFilePath); // Get specific root file
		SH::ScanDir().samplePattern("user.jpoveda.t0789_v44.*.physics_Main.DAOD_SUSY2.*").scan(sh, inputFilePath); // Get all root files in this dataset
		// Set to 1 for data.
		cross_section = 1.;
		k_factor = 1.;
		filter_efficiency = 1.;
		derivation_stat_weights = 3587333027.0;
	}

	// Set the name of the input TTree.
	sh.setMetaString("nc_tree", "AnaNtup");

	// Print what we found:
	sh.print();
/*
	for (unsigned int sample_itr = 0; sample_itr < sh.size(); sample_itr++) {
		SH::Sample *sample = sh.at(sample_itr);
		cout << sample << endl;
		cout << sample->name() << endl;
		cout << sample->numFiles() << endl;
		cout << sample->fileName(0) << endl;
		// retrieve the histogram
		//TH1D *hist = (TH1D *)sample->readHist("DerivationStat_Weights");
		TH1D *hist = (TH1D *)sample->readHist("DerivationStat_Weights");
		cout << hist << endl;
		//cout << hist->GetBinContent(1) << endl;
	}
*/

	// Create an EventLoop job:
	EL::Job job;
	job.sampleHandler( sh );
	//job.options()->setDouble (EL::Job::optMaxEvents, 50);

	// Add our analysis to the job:
	ytEventSelection *alg = new ytEventSelection();
	alg->set_isMC(isMC);
	alg->set_isData(isData);
	alg->set_isSkim(true);
	if (isMC && !process.empty())
		alg->set_process(process);
	if (isData)
		alg->set_process("Data");
	alg->set_luminosity(luminosity);
	alg->set_cross_section(cross_section);
	alg->set_k_factor(k_factor);
	alg->set_filter_efficiency(filter_efficiency);
	alg->set_derivation_stat_weights(derivation_stat_weights);
	job.algsAdd( alg );

	if (use_Condor) {
		// Run the jobs using the Condor driver:
		EL::CondorDriver driver;
		// some commands for setting up root on the nodes
		driver.shellInit = "export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase ; source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh ; rcSetup Base,2.4.19";
		driver.submitOnly( job, submitDir );
	}
	else if (use_Grid) {
		// Run the jobs using the Grid driver:
		EL::PrunDriver driver;
		// Specify how to name the grid output datasets
		// Note that %nickname% is populated when you do voms-proxy init, so this does not have to be replaced by hand
		driver.options()->setString("nc_outputSampleName", "user.%nickname%.%in:name[2]%.%in:name[3]%.%in:name[6]%.");
		driver.submitOnly( job, submitDir );
	}
	else if (use_PROOF) {
		EL::ProofDriver driver;
		driver.submit( job, submitDir );
	}
	else {
		// Run the job using the local/direct driver:
		EL::DirectDriver driver;
		driver.submit( job, submitDir );
	}

	return 0;
}
