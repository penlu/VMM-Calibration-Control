//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 26 14:20:36 2014 by ROOT version 5.26/00
// from TTree vmm1Calibration/vmm1Calibration
// found on file: run_8022.root
//////////////////////////////////////////////////////////

#ifndef vmm1Calibration_h
#define vmm1Calibration_h

#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class vmm1Calibration {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          pulser;
   Double_t        gain;
   UInt_t          board;
   std::vector<double>  *channel;
   std::vector<double>  *neighbor;
   std::vector<double>  *pdo;
   std::vector<double>  *tdo;
   UInt_t          timeMode;

   // List of branches
   TBranch        *b_pulser;   //!
   TBranch        *b_gain;   //!
   TBranch        *b_board;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_neighbor;   //!
   TBranch        *b_pdo;   //!
   TBranch        *b_tdo;   //!
   TBranch        *b_timeMode;   //!

   vmm1Calibration(TTree *tree=0);
   virtual ~vmm1Calibration();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef vmm1Calibration_cxx
vmm1Calibration::vmm1Calibration(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run_8022.root");
      if (!f) {
         f = new TFile("run_8022.root");
      }
      tree = (TTree*)gDirectory->Get("vmm1Calibration");

   }
   Init(tree);
}

vmm1Calibration::~vmm1Calibration()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t vmm1Calibration::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t vmm1Calibration::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void vmm1Calibration::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   channel = 0;
   neighbor = 0;
   pdo = 0;
   tdo = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pulser", &pulser, &b_pulser);
   fChain->SetBranchAddress("gain", &gain, &b_gain);
   fChain->SetBranchAddress("board", &board, &b_board);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("neighbor", &neighbor, &b_neighbor);
   fChain->SetBranchAddress("pdo", &pdo, &b_pdo);
   fChain->SetBranchAddress("tdo", &tdo, &b_tdo);
   fChain->SetBranchAddress("timeMode", &timeMode, &b_timeMode);
   Notify();
}

Bool_t vmm1Calibration::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void vmm1Calibration::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t vmm1Calibration::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef vmm1Calibration_cxx
