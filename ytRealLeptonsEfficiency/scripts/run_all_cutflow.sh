#!/bin/bash
cutflow isData > cutflow_Data.log 2>&1 &
cutflow isMC Zee > cutflow_Zee.log 2>&1 &
cutflow isMC Zmumu > cutflow_Zmumu.log 2>&1 &
cutflow isMC ttbar > cutflow_ttbar.log 2>&1 &
cutflow isMC GG_ttn1 > cutflow_GG_ttn1.log 2>&1 &
