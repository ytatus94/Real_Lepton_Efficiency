#!/usr/bin/python
import os

commands = []
# Fixed template (baseine_template), fitting range (range_baseline) and mll windows (80 ~ 100).
# 10 < pT < 15: 0.1 < eta < 0.8, 0.8 < eta < 1.37, and 1.52 < eta < 2.01
command1 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,1,3)\' > baseline_template_range_baseline_pT1015_eta008.txt'
command2 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,4,5)\' > baseline_template_range_baseline_pT1015_eta08137.txt'
command3 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,7,8)\' > baseline_template_range_baseline_pT1015_eta152201.txt'
# 15 < pT < 20: 0.1 < eta < 0.8, 0.8 < eta < 1.37, and 1.52 < eta < 2.01
command4 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,1,3)\' > baseline_template_range_baseline_pT1520_eta008.txt'
command5 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,4,5)\' > baseline_template_range_baseline_pT1520_eta08137.txt'
command6 = 'root -q -b \'../scripts/ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,7,8)\' > baseline_template_range_baseline_pT1520_eta152201.txt'

commands.append(command1)
commands.append(command2)
commands.append(command3)
commands.append(command4)
commands.append(command5)
commands.append(command6)

for command in commands:
  #print command
  os.system(command)
