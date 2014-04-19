#!/bin/bash
g++ -Wall $(root-config --cflags --glibs) -o vmm1Calibration vmm1Calibration.C
