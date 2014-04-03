#define vmm1Calibration_cxx
#include <iostream>
#include <cmath>
#include "vmm1Calibration.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TGraph.h"
#include "TMath.h"
#include "TF1.h"
#include "TPaveText.h"
#include "TLegend.h"

enum {
  TIMECALIB=0,
  GAINCALIB=1
};

int calibMode=0;

int getMyColor(const int input) {
  const int n = input%8;
  if (n==0) return kBlack;
  if (n==1) return kRed;
  if (n==2) return kGreen+1;
  if (n==3) return kBlue;
  if (n==4) return kMagenta;
  if (n==5) return kCyan;
  if (n==6) return kOrange+2;
  if (n==7) return kGray+1;
  return kBlack;
}

double getChargeFromPulseDAC(const int dac) {
  const double testcap = 1.2;
  double v = 0.; // in mV
  if( dac < 400 ){
    v = 75.5455*exp(-1.*(dac-551.255)*(dac-551.255)/(2*164.074*164.074));
  } else if (dac >= 400 && dac < 500) {
    v = -76.4+0.316*dac;
  } else if (dac >= 500 && dac < 750) {
    v = -119.76+0.4044*dac;
  } else if (dac >= 750) {
    v = -161.683+0.461467*dac;
  }
  const double input_charge = v*testcap;

  return input_charge;
  // The correction on next line, with (0.912676+0.000495626*input_charge), is only relevant if pulsing 64 channels at a time, as pulse DAC response becomes non-linear
  //x[p] = input_charge*(0.912676+0.000495626*input_charge); //must correct for pulser here, old : input_voltage*testcap; //in fC Q = C*V
  //if(input_voltage < 100.){
  //e_x[p] = 0.1*testcap; //reasonable error on input charge
  //}else {
  //e_x[p] = 1.0*testcap; //reasonable error on input charge
  //}
  //y[p] = 1000.*mean[p][n]; //dac and channel number in mV
  //e_y[p] = 1000.*error[p][n]; //dac and channel number in mV
  //cout << "Input charge for DAC = " << input_dac << " is Q_in = " << x[p] <<  " +/- " << e_x[p] << endl;
  //cout << "Output voltage for DAC = " << input_dac << "is  V_out = " << 1000.*mean[p][n] << " +/- " << 1000.*error[p][n] << endl;
}

double leakCorrectPdo(const double pdo, const int ch) {
  // NEED TO FIX USE OF ch !!!
  const int oversampling = 1;
  const double chargeleakagerate = 0.001; // in % (or fraction?) per microsecond
  const double samplingtime = 0.250 + oversampling*0.500;
  //const double readouttime = (1.0*numprevch)*samplingtime + 0.250 + 0.5*(oversampling+1)*0.500;
  const double readouttime = (1.0*ch)*samplingtime + 0.250 + 0.5*(oversampling+1)*0.500;
  const double pdocorrection = 1.0/(1.0 - readouttime*chargeleakagerate);
 return (pdo*pdocorrection);
}
double leakCorrectTdo(const double tdo, const int ch) {
  // NEED TO FIX USE OF ch !!!
  const int oversampling = 1;
  const double chargeleakagerate = 0.001; // in % (or fraction?) per microsecond
  const double samplingtime = 0.250 + oversampling*0.500;
  //const double readouttime = (1.0*numprevch)*samplingtime + 0.250 + 0.5*(oversampling+1)*0.500;
  const double readouttime = (1.0*ch)*samplingtime + 0.250 + 0.5*(oversampling+1)*0.500;
  const double tdocorrection = 1.0/(1.0 - readouttime*chargeleakagerate);
 return (tdo*tdocorrection);
}

int main(const int argc, const char *const *const argv) {
  TTree *t = 0;
  // Contents of argv should be:
  //  [0]: executable name
  //  [1]: input .root file name
  //  [2]: mode (TIMECALIB or GAINCALIB)
  if (argc>1) {
    TFile *f = TFile::Open(argv[1]);
    if (f) {std::cout << "Opened file " << argv[1] << std::endl;}
    t = (TTree*)gDirectory->Get("vmm1Calibration");
    if (argc>2) {
      calibMode = atoi(argv[2]);
      std::cout << "calibMode set to " << calibMode << " from cmd line args" << std::endl;
    }
    std::cout << "Using calibMode=" << calibMode << std::endl;
  } else {
    std::cout << "Please give .root input file as 1st argument!" << std::endl;
    return 0;
  }
  vmm1Calibration blah(t);
  blah.Loop();
  return 0;
}

void vmm1Calibration::Loop()
{
  const int verbose = 0;
//   In a ROOT session, you can do:
//      Root > .L vmm1Calibration.C
//      Root > vmm1Calibration t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   const Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "nentries="<<nentries << std::endl;

   // UInt_t          pulser;
   // Double_t        gain;
   // UInt_t          board;
   // vector<double>  *channel;
   // vector<double>  *neighbor;
   // vector<double>  *pdo;
   // vector<double>  *tdo;
   // UInt_t          timeMode;

   const int numChannels = 64;

   int initialPulse=-1;
   int initialGain=-1;
   int initialWaittime=-1;

   int currentPulse=-1;
   int currentGain=-1;
   int currentWaittime=-1;

   int currentChannel=-1;

   // dimensions of these: channel, 
   std::vector< std::vector<float> > vectorOfXvalues(64);
   std::vector< std::vector<float> > vectorOfYvalues(64);
   std::vector< std::vector<float> > vectorOfYerrors(64);

   int nSamples = 0;
   double meanTdo = 0.;
   double meanPdo = 0.;

   // Create vector of TH1F objects, 1 per value of timeMode or pulser, per channel
   //std::vector< std::vector<TH1F*> > myHistos(64)(4);
   //for (channel=0; channel<64; channel++) {
   //  for (xpt=0,xpt<4) {//loop over the number of pulser values (or timeMode values) we have for each channel
   //    myHistos.at(i).at(j) = new TH1F("h_"+ch+"_"j,"h_"+ch+"_"+j,100,0,4000);
   //  }
   //  NOTE: this skeleton is not ideal... number of data points for each channel (4) is hard-coded
   //  Ideally we would create the TH1F instances inside the event loop below,
   //  and so get the number of histograms for each channel from the data
   //  so that if we change to 5 data points per channel, we get 5 histograms
   //  To do this, we could have code inside the event loop that creates a new
   //  new TH1F instance and does myHistos.at(ch).push_back(theNewTH1Finstance) below
   //  whenever we see a new timeMode or pulser value (depending on whether we're in TIMECALIB or GAINCALIB mode)
   //}

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if (jentry==0) {
	initialPulse = pulser;
	initialGain = gain;
	initialWaittime = timeMode;

	currentPulse = pulser;
	currentGain = gain;
	currentWaittime = timeMode;
	if (channel->size()>0) {currentChannel = channel->at(0);}

	initialGain = 9;
      }

      if (verbose==3) {
	std::cout << jentry << ": " << pulser << " " << timeMode
		  << ": " << channel->size() << " " << pdo->size() << " " << tdo->size();
	std::cout << "    " << channel->at(0) << " " << pdo->at(0) << " " << tdo->at(0);
	std::cout << std::endl;
      }

      //blah note for pdo:
      //1 lsb = 3.3/16384 (from George Iakovidis 2014/2/28)

      // We should have two modes: time calibration and gain calibration
      // Time calibration: X=pulseWidth(var:currentWaittime), Y=meanTdo
      // Gain calibration: X=pulseSize(var:pulser),           Y=meanPdo

      if (calibMode==TIMECALIB) {
	if ((int)pulser!=initialPulse) {
	  // check that we have the right pulser value, so that we perform
	  // all of the tdoVsWaittime calibration with a single value of pulser
	  continue;
	}
      }

      if (calibMode==GAINCALIB) {
	if ((int)gain!=initialGain || (int)timeMode!=initialWaittime) {
	  //std::cout << " WARNING on gain,timeMode: " << gain << "," << initialGain
	  //	    << ";   " << timeMode << "," << initialWaittime
	  //	    << std::endl;
	  continue;
	}
      }

      if (channel->size()>1) {
	//std::cout << "Ignore event with channel: ";
	//for (unsigned i=0; i<channel->size(); i++) {
	//std::cout << channel->at(i) << ",";
	//}
	//std::cout << std::endl;
	std::cout << "Ignore event with " << channel->size() << " channels" << std::endl;
	continue;
      }

      if (currentPulse==(int)pulser &&
	  (fabs(currentGain-gain)<0.001) &&
	  currentWaittime==(int)timeMode &&
	  ((fabs(currentChannel-channel->at(0)))<0.001) ) {
	// We're still reading all the samples with a single set of fixed values
	//std::cout << "Still on same " << pulser << ", " << gain
	//	  << ", " << timeMode << ", " << channel->at(0) << std::endl;
	nSamples++;
	meanTdo += tdo->at(0);//leakCorrectTdo(tdo->at(0), currentChannel);
	meanPdo += pdo->at(0);//leakCorrectPdo(pdo->at(0), currentChannel);
	// If doing TIMECALIB: Fill value tdo into the TH1F object appropriate for this channel and timeMode value
	//     e.g. myGraphs.at(ch).at(index value of this timeMode value)->Fill(tdo->at(0));
	//     The timeMode index should be 0,1,2,3, corresponding to actual timeMode values of 250,500,750,1000
	//     but ideally the code should be written so that the number of values (4), and the series of values
	//     (250,500,750,1000) are not hard-coded in this file, and instead detected automatically from the data!
	// If doing GAINCALIB: Fill value pdo into the TH1F object appropriate for this channel and pulser value
	if (jentry==nentries-1) {
	  // If this is the last event in the file:
	  meanTdo /= nSamples;
	  meanPdo /= nSamples;
	  std::cout << "=== " << jentry << ": " << nSamples << " samples with "
		    << " pulser="<<currentPulse << " timeMode="<<currentWaittime
		    << " on channel " << currentChannel << std::endl;
	  if (calibMode==TIMECALIB) {
	    if (nSamples>1) {
	      vectorOfXvalues.at(currentChannel).push_back(currentWaittime);
	      vectorOfYvalues.at(currentChannel).push_back(meanTdo *(3.3/16.384));
	      vectorOfYerrors.at(currentChannel).push_back( nSamples>0 ? (meanTdo*(3.3/16.384))/TMath::Sqrt(nSamples) : 0 );
	    }
	  }
	  if (calibMode==GAINCALIB) {
	    if (nSamples>1) {
	      vectorOfXvalues.at(currentChannel).push_back(getChargeFromPulseDAC(currentPulse));
	      vectorOfYvalues.at(currentChannel).push_back(meanPdo *(3.3/16.384));
	      vectorOfYerrors.at(currentChannel).push_back( nSamples>0 ? (meanPdo*(3.3/16.384))/TMath::Sqrt(nSamples) : 0 );
	    }
	  }
	  nSamples = 0;
	  meanTdo = 0.;
	  meanPdo = 0.;
	}
      } else {
	// We enter here if the settings and channel number have changed
	// wrt the previous event
	// First check whether the next event has the same channel etc as this
	if (0) {
	  // If the current event has different channel etc. than previous event
	  // and also different channel than next event, then ignore this event
	  // (assume it's just random noise)
	} else {
	  // We've got to the first event where one of the values changed, so
	  // we should record the data from previous nSamples into plot
	  meanTdo /= nSamples;
	  meanPdo /= nSamples;
	  std::cout << "=== " << jentry << ": " << nSamples << " samples with "
		    << " pulser="<<currentPulse << " timeMode="<<currentWaittime
		    << " on channel " << currentChannel << std::endl;
	  //if (vectorOfXvalues.find(currentWaittime)==vectorOfXvalues.end()) {
	  // if we haven't yet encountered this wait time, need to set up vectors to store the data
	  //Must also do (for n in channels) vectorOfYvalues.at(channel).at(the new currentWaittime).push_back(new vector);
	  //}
	  if (calibMode==TIMECALIB) {
	    if (nSamples>1) {
	      vectorOfXvalues.at(currentChannel).push_back(currentWaittime);
	      vectorOfYvalues.at(currentChannel).push_back(meanTdo *(3.3/16.384));
	      vectorOfYerrors.at(currentChannel).push_back( nSamples>0 ?
							    (meanTdo*(3.3/16.384))/TMath::Sqrt(nSamples) : 0 );
	    }
	  }
	  if (calibMode==GAINCALIB) {
	    if (nSamples>1) {
	      vectorOfXvalues.at(currentChannel).push_back(getChargeFromPulseDAC(currentPulse));
	      vectorOfYvalues.at(currentChannel).push_back(meanPdo *(3.3/16.384));
	      vectorOfYerrors.at(currentChannel).push_back( nSamples>0 ?
							    (meanPdo*(3.3/16.384))/TMath::Sqrt(nSamples) : 0 );
	    }
	  }
	  nSamples = 0;
	  meanTdo = 0.;
	  meanPdo = 0.;
	  // Now we've finished dealing with previous set of values, but still
	  // need to save the data from previous event
	  nSamples++;
	  meanTdo += tdo->at(0);//correctTdo(tdo->at(0), currentChannel);
	  meanPdo += pdo->at(0);//correctPdo(pdo->at(0), currentChannel);
	  // If doing TIMECALIB: Fill value tdo into the TH1F object appropriate for this channel and timeMode value
	  // If doing GAINCALIB: Fill value pdo into the TH1F object appropriate for this channel and pulser value
	}
      }

      currentPulse = pulser;
      currentGain = gain;
      currentWaittime = timeMode;
      currentChannel = channel->at(0);
   }

   std::cout << "Finished looping over events" << std::endl;

   std::cout << "Creating TCanvas" << std::endl;
   TCanvas *c1 = new TCanvas("c1","c1",700,700);
   c1->SetLeftMargin(0.15);
   c1->SetFillColor(kWhite);

   std::cout << "Will now look at histograms TH1Fs to study outliers" << std::endl;
   // Insert code for drawing TH1F objects etc.
   //for (ch=0; ch<10; ch++) {//At least to start, on
   //  for (xpt=0; xpt<myHistos.at(ch).size(); xpt++) {//loop over the number of pulser values (or timeMode values)  we have for each channel
   //    // Draw the TH1F object:
   //    myHistos.at(...).at(...)->Draw("hist");
   //    c1->Print(...);//Exports the plot to a .png or .eps file Look at similar c1->Print(... ) lines below to see how to use
   //    //Ideally save as both png and eps, and make the filename contain the type of calibration (time or gain), and the channel number, and the xpt value
   //  }
   //  NOTE: The above code skeleton is designed to draw a single histogram
   //  at a time, and save each individual histogram to a single file
   //  An alternative here, possibly nicer, is to have a file channel, with
   //  the 4 histograms plotted on top of each other, each different colour
   //  Code would be something like this:
   //  //Make each of the 4 histos different colour:
   //  myHistos.at(ch).at(0)->SetLineColor(getMyColor(0));
   //  myHistos.at(ch).at(0)->SetMarkerColor(getMyColor(0));
   //  myHistos.at(ch).at(1)->SetLineColor(getMyColor(1));
   //  myHistos.at(ch).at(1)->SetMarkerColor(getMyColor(1));
   //  myHistos.at(ch).at(2)->SetLineColor(getMyColor(2));
   //  myHistos.at(ch).at(2)->SetMarkerColor(getMyColor(2));
   //  myHistos.at(ch).at(3)->SetLineColor(getMyColor(3));
   //  myHistos.at(ch).at(3)->SetMarkerColor(getMyColor(3));
   //  // Now draw the 4 histos
   //  myHistos.at(ch).at(0)->Draw("hist");
   //  myHistos.at(ch).at(1)->Draw("hist same");// string "same" means overlay on existing axes
   //  myHistos.at(ch).at(2)->Draw("hist same");
   //  myHistos.at(ch).at(3)->Draw("hist same");// change so that we loop over 0,1,2,3,
   //                               //without hard-coding the number of histograms per channel!
   //  c1->Print(...);
   //}

   std::cout << "Will now create TGraphs" << std::endl;
   std::vector<TGraph*> myGraphs;
   for (int ch=0; ch<numChannels; ch++) {myGraphs.push_back(0);}
   
   for (int ch=0; ch<numChannels; ch++) {
     const unsigned nPoints = vectorOfXvalues.at(ch).size();
     if (nPoints!=vectorOfYvalues.at(ch).size()) {std::cout<<"Error with vector sizes"<<std::endl;return;}
     if (nPoints>0) {
       int xtmp[nPoints];
       int ytmp[nPoints];
       for (unsigned i=0; i<nPoints; i++) {xtmp[i]=vectorOfXvalues.at(ch).at(i); ytmp[i]=vectorOfYvalues.at(ch).at(i);}
       TGraph *g = new TGraph( nPoints, xtmp, ytmp );
       g->SetName(Form("graph_ch%i",ch));
       myGraphs.at(ch) = g;
       //std::cout << "Created TGraph for ch="<<ch << std::endl;
     }
   }

   // Set up aesthetic options for the graphs
   TLegend *myleg1 = new TLegend(0.20,0.49,0.33,0.94);
   TLegend *myleg2 = new TLegend(0.33,0.64,0.46,0.94);
   TLegend *myleg3 = new TLegend(0.46,0.79,0.59,0.94);
   myleg1->SetFillColor(kWhite);
   myleg1->SetBorderSize(1);
   myleg2->SetFillColor(kWhite);
   myleg2->SetBorderSize(1);
   myleg3->SetFillColor(kWhite);
   myleg3->SetBorderSize(1);
   for (int ch=0; ch<numChannels; ch++) {
     if (myGraphs.at(ch)) {
       // Use markers 20-27
       myGraphs.at(ch)->SetMarkerStyle(20 + ch%8);
       myGraphs.at(ch)->SetMarkerColor(getMyColor(ch));
       myGraphs.at(ch)->SetLineColor(kWhite);
       myGraphs.at(ch)->SetFillColor(kWhite);
       myGraphs.at(ch)->SetLineWidth(0);
       //std::cout << "GetMarkerSize:  " << myGraphs.at(ch)->GetMarkerSize() << std::endl;
       myGraphs.at(ch)->SetMarkerSize(1.2);
       if (ch<32) {
	 myleg1->AddEntry(myGraphs.at(ch),Form("Channel %i",ch));
       } else if (ch<53) {
	 myleg2->AddEntry(myGraphs.at(ch),Form("Channel %i",ch));
       } else {
	 myleg3->AddEntry(myGraphs.at(ch),Form("Channel %i",ch));
       }
     }
   }
   
   //std::cout << "Creating TCanvas" << std::endl;
   //TCanvas *c1 = new TCanvas("c1","c1",700,700);
   //c1->SetLeftMargin(0.15);
   //c1->SetFillColor(kWhite);
   if (!myGraphs.at(0)) {std::cout << "ERROR: myGraphs.at(0) is empty!!!" << std::endl;}
   // Find first non-NULL member of myGraphs
   int firstNonNullGraph = 0;
   for (int ch=0; ch<numChannels; ch++) {
     if (myGraphs.at(ch)) {
       firstNonNullGraph = ch;
       break;
     }
   }

   for (int ch=firstNonNullGraph; ch<numChannels; ch++) {
     if (!myGraphs.at(ch)) continue;
     myGraphs.at(ch)->SetTitle(0);
     myGraphs.at(ch)->SetMinimum(0);//y
     myGraphs.at(ch)->SetMaximum(1500.);//7000);//4000);//y
     if (calibMode==GAINCALIB) {
       myGraphs.at(ch)->GetXaxis()->SetLimits(0,100);//500);//x
       myGraphs.at(ch)->GetXaxis()->SetTitle("Induced charge from pulse (fC)");
       myGraphs.at(ch)->GetYaxis()->SetTitle("Mean PDO (mV)");
     } else if (calibMode==TIMECALIB) {
       myGraphs.at(ch)->GetXaxis()->SetLimits(0,1200);//500);//x
       myGraphs.at(ch)->GetXaxis()->SetTitle("Wait time (ns)");
       myGraphs.at(ch)->GetYaxis()->SetTitle("Mean TDO (mV)");
     }
     myGraphs.at(ch)->GetYaxis()->SetTitleOffset(1.7);
   }

   myGraphs.at(firstNonNullGraph)->Draw("AP");
   for (int ch=firstNonNullGraph+1; ch<numChannels; ch++) {
     if (myGraphs.at(ch)) myGraphs.at(ch)->Draw("P");
   }
   myleg1->Draw();
   myleg2->Draw();
   myleg3->Draw();
   c1->Print(Form("calib%s.png",(calibMode==GAINCALIB ? "Gain" : "Time")));
   c1->Print(Form("calib%s.eps",(calibMode==GAINCALIB ? "Gain" : "Time")));

   // Now fit the graphs!
   for (int ch=0; ch<numChannels; ch++) {
     if (vectorOfYvalues.at(ch).size()>1) {
       if (myGraphs.at(ch)) {
	 myGraphs.at(ch)->Fit("pol1","Q");
	 TF1 *myfit = myGraphs.at(ch)->GetFunction("pol1");
	 printf("Fitted channel %2i => p0=%5.0f, p1=%6.3f using %i points\n",
		ch, myfit->GetParameter(0), myfit->GetParameter(1),
		(int)vectorOfYvalues.at(ch).size());
	 myfit->SetLineColor(getMyColor(ch));
	 myfit->SetLineWidth(1);
       }
     }
   }
   c1->Print(Form("calib%sWithFits.png",(calibMode==GAINCALIB ? "Gain" : "Time")));
   c1->Print(Form("calib%sWithFits.eps",(calibMode==GAINCALIB ? "Gain" : "Time")));

   for (int ch=0; ch<numChannels; ch++) {
     if (!myGraphs.at(ch)) continue;
     myGraphs.at(ch)->Draw("AP");
     TF1 *myfit = myGraphs.at(ch)->GetFunction("pol1");
     //if (ch<32)        {myleg1->Draw();
     //} else if (ch<53) {myleg2->Draw();
     //} else            {myleg3->Draw();}
     TPaveText *t = new TPaveText(0.2,0.8,0.5,0.9,"NDC");
     t->AddText(Form("Channel %i with %i data points",
		     ch,(int)vectorOfYvalues.at(ch).size()));
     if (myfit) t->AddText(Form(" Fit params: p0=%5.0f, p1=%6.3f",
				myfit->GetParameter(0), myfit->GetParameter(1)));
     t->SetFillColor(kWhite);
     t->SetBorderSize(1);
     t->Draw();
     c1->Print(Form("calib%s_ch%02i.png",(calibMode==GAINCALIB ? "Gain" : "Time"),ch));
     c1->Print(Form("calib%s_ch%02i.eps",(calibMode==GAINCALIB ? "Gain" : "Time"),ch));
   }
}

