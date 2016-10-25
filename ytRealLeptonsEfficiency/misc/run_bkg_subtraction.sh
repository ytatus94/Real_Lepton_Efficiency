#!/bin/bash
# 0.1 < eta < 0.8
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,1,3)' > baseline_template_range_baseline_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,1,3)' > baseline_template_range1_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,1,3)' > baseline_template_range2_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,1,3)' > template1_range_baseline_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,1,3)' > template1_range1_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,1,3)' > template1_range2_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,1,3)'> template2_range_baseline_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,1,3)' > template2_range1_pT1015_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,1,3)' > template2_range2_pT1015_eta008.txt

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,1,3)' > baseline_template_range_baseline_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,1,3)' > baseline_template_range1_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,1,3)' > baseline_template_range2_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,1,3)' > template1_range_baseline_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,1,3)' > template1_range1_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,1,3)' > template1_range2_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,1,3)' > template2_range_baseline_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,1,3)' > template2_range1_pT1520_eta008.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,1,3)' > template2_range2_pT1520_eta008.txt

# 0.8 < eta < 1.37
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,4,5)' > baseline_template_range_baseline_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,4,5)' > baseline_template_range1_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,4,5)' > baseline_template_range2_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,4,5)' > template1_range_baseline_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,4,5)' > template1_range1_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,4,5)' > template1_range2_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,4,5)' > template2_range_baseline_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,4,5)' > template2_range1_pT1015_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,4,5)' > template2_range2_pT1015_eta08137.txt

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,4,5)' > baseline_template_range_baseline_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,4,5)' > baseline_template_range1_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,4,5)' > baseline_template_range2_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,4,5)' > template1_range_baseline_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,4,5)' > template1_range1_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,4,5)' > template1_range2_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,4,5)' > template2_range_baseline_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,4,5)' > template2_range1_pT1520_eta08137.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,4,5)' > template2_range2_pT1520_eta08137.txt

# 1.52 < eta < 2.01
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,7,8)' > baseline_template_range_baseline_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,7,8)' > baseline_template_range1_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,7,8)' > baseline_template_range2_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,7,8)' > template1_range_baseline_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,7,8)' > template1_range1_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,7,8)' > template1_range2_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,7,8)' > template2_range_baseline_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,7,8)' > template2_range1_pT1015_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,7,8)' > template2_range2_pT1015_eta152201.txt

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,7,8)' > baseline_template_range_baseline_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,7,8)' > baseline_template_range1_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,7,8)' > baseline_template_range2_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,7,8)' > template1_range_baseline_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,7,8)' > template1_range1_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,7,8)' > template1_range2_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,7,8)' > template2_range_baseline_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,7,8)' > template2_range1_pT1520_eta152201.txt
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,7,8)' > template2_range2_pT1520_eta152201.txt
