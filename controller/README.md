VMM-Calibration-Control
=======================

Code for ATLAS VMM control. This project is solely to develop calibration controls/routines for calibrating the micromega ASIC (on time and gain).

FEATURES LEFT TO IMPLEMENT:
 
 1) Specify time at which the calibration must begin/end
 
 2) Time or gain calibration run (should be able to select in UI)
 
 3) When calibrating times, specify beginning/ending pulse lengths (t=2 to t=13 in 25 ns increments                            starting from 50). 
 
 	-Step-size 2-4 is probably sufficient (2 6 10 14 etc.) . Hardcode is sufficient: FIXED pulse-size, 		 different timings.
	
 4) Gain calibration - only doing one right now. Fix time, loop over gains 0.5, 1, 3, 9. Figure out actual gain from that plot (9, for instance, might actually be 8.5). 
 
 	-Do this for many pulse sizes: DAC= 250, 300, 350, 400 (...500). FC: 20, 30, 45, 60. (This could possibly be UI, probably not though- hardcode is probably sufficient.) 
 
MORE NOTES ABOUT WHAT IS HAPPENING: 
 
1) startDi --> click() -->connected to dataDAQPending()
