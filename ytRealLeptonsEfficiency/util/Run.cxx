// Usage:
// Run isMC Zee/Zmumu/Zee_truth_match/Zmumu_truth_match/Zee_TandP_truth_match/Zmumu_TandP_truth_match [PROOF/Condor]
// Run isMC ttbar/GG_ttn1 electron/muon [PROOF/Condor]
// Run isData electron/muon [PROOF/Condor]

//#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/ProofDriver.h"
#include "EventLoop/CondorDriver.h"
#include "EventLoopGrid/PrunDriver.h"
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>


#include "ytRealLeptonsEfficiency/ytRealLeptonsEfficiency_Data.h"
#include "ytRealLeptonsEfficiency/ytRealLeptonsEfficiency_MC.h"

int main( int argc, char* argv[] ) {

	// Take the submit directory from the input if provided:
	//std::string submitDir = "submitDir";
	//if( argc > 1 ) submitDir = argv[ 1 ];
	std::string submitDir;

	bool isMC = false;
	bool isData = false;
	string process;
	string lepton_type;
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
		//else if (strcmp(key, "4topSM") == 0)
		//    process = "4topSM";
		else if (strcmp(key, "Zee") == 0)
			process = "Zee";
		else if (strcmp(key, "Zmumu") == 0)
			process = "Zmumu";
		else if (strcmp(key, "ttbar") == 0)
			process = "ttbar";
		else if (strcmp(key, "GG_ttn1") == 0)
			process = "GG_ttn1";
		else if (strcmp(key, "Zee_truth_match") == 0)
			process = "Zee_truth_match";
		else if (strcmp(key, "Zmumu_truth_match") == 0)
			process = "Zmumu_truth_match";
		else if (strcmp(key, "Zee_TandP_truth_match") == 0)
			process = "Zee_TandP_truth_match";
		else if (strcmp(key, "Zmumu_TandP_truth_match") == 0)
			process = "Zmumu_TandP_truth_match";
        else if (strcmp(key, "Zee_Sherpa") == 0)
            process = "Zee_Sherpa";
        else if (strcmp(key, "Zmumu_Sherpa") == 0)
            process = "Zmumu_Sherpa";
        else if (strcmp(key, "Zee_Sherpa_truth_match") == 0)
            process = "Zee_Sherpa_truth_match";
        else if (strcmp(key, "Zmumu_Sherpa_truth_match") == 0)
            process = "Zmumu_Sherpa_truth_match";
		// Choose the lepton type.
		else if (strcmp(key, "electron") == 0)
			lepton_type = "electron";
		else if (strcmp(key, "muon")== 0)
			lepton_type = "muon";
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
		printf("Submit jobs to CondorDriver.\n");
	}
	else if (use_Grid) {
		printf("Submit jobs to PrunDriver.\n");
	}
	else if (use_PROOF) {
		printf("Submit jobs to ProofDriver.\n");
	}
	else {
		printf("Submit jobs to DirectDriver.\n");
	}

	if (isMC && !process.empty())
		cout << "process = " << process << endl;

	if (isMC) {
		if (process == "Zee" || process == "Zmumu" ||
            process == "Zee_truth_match" || process == "Zmumu_truth_match" ||
            process == "Zee_TandP_truth_match" || process == "Zmumu_TandP_truth_match" ||
			process == "Zee_Sherpa" || process == "Zmumu_Sherpa" ||
			process == "Zee_Sherpa_truth_match" || process == "Zmumu_Sherpa_truth_match")
			submitDir = "submitDir_MC_" + process;
		else if (process == "ttbar" || process == "GG_ttn1")
			submitDir = "submitDir_MC_" + process + "_" + lepton_type;
	}
	else if (isData) {
		submitDir = "submitDir_Data_" + lepton_type;
	}

	// Set up the job for xAOD access:
	//xAOD::Init().ignore();

	// Construct the samples to run on:
	SH::SampleHandler sh;

	// use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
	//const char* inputFilePath = gSystem->ExpandPathName ("$ALRB_TutorialData/p2622/");
	//SH::ScanDir().filePattern("DAOD_SUSY1.08377960._000012.pool.root.1").scan(sh,inputFilePath);
	//const char* inputFilePath = "/UserDisk2/yushen/Ximo_ntuples/v44/Skimmed/Data";
	//SH::ScanDir().filePattern("data_probes_all_periods.root").scan(sh, inputFilePath);
	const char* inputFilePath;
	if (isMC) {
		inputFilePath = "/raid05/users/shen/Ximo_ntuples/v44/Skimmed";
		if (process == "Zee" ||
			process == "Zee_truth_match" ||
			process == "Zee_TandP_truth_match") {
			SH::ScanDir().filePattern("MC_probes_Zee.root").scan(sh, inputFilePath);
		}
		else if (process == "Zmumu" ||
				 process == "Zmumu_truth_match" ||
				 process == "Zmumu_TandP_truth_match") {
			SH::ScanDir().filePattern("MC_probes_Zmumu.root").scan(sh, inputFilePath);
		}
		else if (process == "Zee_Sherpa" ||
				 process == "Zee_Sherpa_truth_match") {
			SH::ScanDir().filePattern("MC_probes_Zee_Sherpa.root").scan(sh, inputFilePath);
		}
		else if (process == "Zmumu_Sherpa" ||
				 process == "Zmumu_Sherpa_truth_match") {
			SH::ScanDir().filePattern("MC_probes_Zmumu_Sherpa.root").scan(sh, inputFilePath);
		}
		else if (process == "ttbar") {
			SH::ScanDir().filePattern("MC_probes_ttbar.root").scan(sh, inputFilePath);
		}
		else if (process == "GG_ttn1") {
			SH::ScanDir().filePattern("MC_probes_GG_ttn1.root").scan(sh, inputFilePath);
		}
	}
	else if (isData) {
		inputFilePath = "/raid05/users/shen/Ximo_ntuples/v44/Skimmed";
		SH::ScanDir().filePattern("data_probes_all_periods.root").scan(sh, inputFilePath);
	}


	// Set the name of the input TTree. It's always "CollectionTree"
	// for xAOD files.
	//sh.setMetaString( "nc_tree", "CollectionTree" );
	sh.setMetaString( "nc_tree", "AnaNtup" );

	// Print what we found:
	sh.print();

	// Create an EventLoop job:
	EL::Job job;
	job.sampleHandler( sh );
	//job.options()->setDouble (EL::Job::optMaxEvents, 50000);

	// Add our analysis to the job:
	if (isMC) {
		ytRealLeptonsEfficiency_MC* alg = new ytRealLeptonsEfficiency_MC();
		alg->set_isMC(true);
		alg->set_isData(false);
		alg->set_trigger("single_lepton_trigger");
		if (process == "Zee" ||
            process == "Zee_truth_match" ||
            process == "Zee_TandP_truth_match" ||
			process == "Zee_Sherpa" ||
			process == "Zee_Sherpa_truth_match")
			alg->set_lepton("electron");
		else if (process == "Zmumu" ||
                 process == "Zmumu_truth_match" ||
                 process == "Zmumu_TandP_truth_match" ||
				 process == "Zmumu_Sherpa" ||
				 process == "Zmumu_Sherpatruth_match")
			alg->set_lepton("muon");
		else if (process == "ttbar" || process == "GG_ttn1")
			alg->set_lepton(lepton_type);
		alg->set_process(process);
		job.algsAdd( alg );
	}
	if (isData) {
		ytRealLeptonsEfficiency_Data* alg = new ytRealLeptonsEfficiency_Data();
		alg->set_isMC(false);
		alg->set_isData(true);
		alg->set_trigger("single_lepton_trigger");
		alg->set_lepton(lepton_type);
		job.algsAdd( alg );
	}
/*
	// Run the job using the local/direct driver:
	EL::DirectDriver driver;
	driver.submit( job, submitDir );
*/
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
