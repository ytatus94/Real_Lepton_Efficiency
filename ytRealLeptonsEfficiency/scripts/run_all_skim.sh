#!/bin/bash
skim isData > skim_Data.log 2>&1 &
skim isMC Zee > skim_Zee.log 2>&1 &
skim isMC Zmumu > skim_Zmumu.log 2>&1 &
skim isMC ttbar > skim_ttbar.log 2>&1 &
skim isMC GG_ttn1 > skim_GG_ttn1.log 2>&1 &