#!/bin/bash

# Standard setup of RealEfficiency
setupATLAS
if [ -e rcSetup.sh ]; then
	echo ">>>>> Using the existing rcSetup.sh."
	rcSetup # defaults to whatever was previously set up
else
	echo ">>>>> Setup rcSetup SUSY,2.4.17"
	rcSetup SUSY,2.4.17
fi

# Find and compile these packages
echo ">>>>> Compile the packages"
rc find_packages
rc clean
rc compile

# For config files
#export PYTHONPATH=$PYTHONPATH:$PWD/TagAndProbeFrame/config

# For config files in LH tuning package, if it is checked out
#if [ -d "ElectronIDDevelopment/" ]; then
#  export PYTHONPATH=$PYTHONPATH:$PWD/ElectronIDDevelopment/config
#fi
