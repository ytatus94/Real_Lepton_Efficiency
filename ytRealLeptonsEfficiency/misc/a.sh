#!/bin/bash

root -q -b '../scripts/ytRelative_difference_of_efficiency.C(10, 20, true)' > relative_difference_of_efficiency_pt1020_eta020.txt
root -q -b '../scripts/ytRelative_difference_of_efficiency.C(20, 30, true)' > relative_difference_of_efficiency_pt2030_eta020.txt
root -q -b '../scripts/ytRelative_difference_of_efficiency.C(30, 50, true)' > relative_difference_of_efficiency_pt3050_eta020.txt
root -q -b '../scripts/ytRelative_difference_of_efficiency.C(50, 80, true)' > relative_difference_of_efficiency_pt5080_eta020.txt
root -q -b '../scripts/ytRelative_difference_of_efficiency.C(80, 200, true)' > relative_difference_of_efficiency_pt80200_eta020.txt
