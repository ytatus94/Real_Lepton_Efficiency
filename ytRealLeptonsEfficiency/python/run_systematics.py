#!/usr/bin/python
import os

templates = ['baseline_template', 'template1', 'template2']
fitting_ranges = ['range_baseline', 'range1', 'range2']
mll_windows = [[80, 100], [75, 105], [85, 95]]
pt_ranges = [10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 120, 150, 200]
el_eta_ranges = [0, 0.8, 1.37, 1.52, 2.01, 2.47]
mu_eta_ranges = [0, 0.6, 1.2, 1.8, 2.5]

# Get the output_filename
def mll_str(mll_window):
    print "_mll" + str(mll_window[0]) + str(mll_window[1])

def pt_str(pt_low, pt_up):
    print "_pT" + str(pt_low) + str(pt_up)

def eta_str(eta_low, eta_up):
    print "_eta" + str(eta_low) + str(eta_up)

for template in templates:
  for fitting_range in fitting_ranges:
    for mll_window in mll_windows:
      for pt_range in pt_ranges:
        for eta_range in el_eta_ranges:
          mll = "_mll" + str(mll_windows[0][0]) + str(mll_windows[0][1])
          pT = "_pT"
          pt_range_index = pt_ranges.index(pt_range)
          if pt_range_index < len(pt_ranges) - 1:
            pT += str(pt_range) + str(pt_ranges[pt_range_index + 1])
          eta = "_eta"
          eta_range_index = el_eta_ranges.index(eta_range)
          if eta_range_index < len(el_eta_ranges) - 1:
            eta += str(int(eta_range * 100)) + str(int(el_eta_ranges[eta_range_index + 1] * 100))
          output_filename = template + "_" + fitting_range + mll + pT + eta + ".txt"
          print output_filename