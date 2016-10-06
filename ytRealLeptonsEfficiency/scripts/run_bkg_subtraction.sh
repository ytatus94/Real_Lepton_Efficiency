#!/bin/bash
# 0.1 < eta < 0.8
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,1,3)'

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,1,3)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,1,3)'

# 0.8 < eta < 1.37
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,4,5)'

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,4,5)'

# 1.52 < eta < 2.01
root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,1,1,,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,1,1,4,5)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,1,1,4,5)'

root -q -b 'ytBackground_subtraction.C("baseline","range_baseline",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("baseline","range1",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("baseline","range2",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template1","range_baseline",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template1","range1",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template1","range2",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template2","range_baseline",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template2","range1",true,60,120,80,100,2,2,7,8)'
root -q -b 'ytBackground_subtraction.C("template2","range2",true,60,120,80,100,2,2,7,8)'
