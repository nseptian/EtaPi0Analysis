TString mainDir = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/";
// TString rootHistFitResult = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/etapi_plot_D2++_pD2++.root";
// TString dirRootFlatTree = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/rootFiles/t010020_m104172_test/";
const Int_t NPol = 4;
TString polString[NPol] = {"pol000", "pol045", "pol090", "pol135"};
const Int_t NTBin = 5;
TString tBinString[NTBin] = {"010020","0200325","0325050","050075","075100"};
Float_t tMin[NTBin] = {0.1,0.2,0.325,0.5,0.75};
Float_t tMax[NTBin] = {0.2,0.325,0.5,0.75,1.0};
TString mBinString = "m104172";
TString extraTag = "test";
TString dataTag = "2019_11";
Bool_t isRunEtaPiPlotter = kTRUE;
TString etaPiPlotterOutName = "etapi_plot";
TString histBaseName[4] = {"EtaPi0_000_", "EtaPi0_045_", "EtaPi0_090_", "EtaPi0_135_"};
TString histMEtaPiAccName = "Metapi_40MeVBinacc";
TString histMEtaPiSigName = "Metapi_40MeVBindat";
TString histMetaPiBkgName = "Metapi_40MeVBinbkg";
TString strWave = "pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++";
TString strFitFracWave = "pD";
// waves=["S0+-_S0++",
//        "D1--_D0+-_D1+-_D0++_D1++_D2++",
//        "pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
//        "D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
//        "S0+-_S0++_D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++"
//       ]
// TString rootFlatTreeSignal[NPol] = {"pol000_t010020_m104172_test_D2019_11_selected_data_flat.root",
//                                 "pol045_t010020_m104172_test_D2019_11_selected_data_flat.root",
//                                 "pol090_t010020_m104172_test_D2019_11_selected_data_flat.root",
//                                 "pol135_t010020_m104172_test_D2019_11_selected_data_flat.root"};
// TString rootFlatTreeBkgnd[NPol] = {"pol000_t010020_m104172_test_D2019_11_selected_bkgnd_flat.root",
//                                 "pol045_t010020_m104172_test_D2019_11_selected_bkgnd_flat.root",
//                                 "pol090_t010020_m104172_test_D2019_11_selected_bkgnd_flat.root",
//                                 "pol135_t010020_m104172_test_D2019_11_selected_bkgnd_flat.root"};
// TString rootFlatTreeMCRecon[NPol] = {"pol000_t010020_m104172_test_F2019_11_selected_acc_flat.root",
//                                 "pol045_t010020_m104172_test_F2019_11_selected_acc_flat.root",
//                                 "pol090_t010020_m104172_test_F2019_11_selected_acc_flat.root",
//                                 "pol135_t010020_m104172_test_F2019_11_selected_acc_flat.root"};
// TString rootFlatTreeMCThrown[NPol] = {"pol000_t010020_m104172_test_F2019_11_selected_gen_flat.root",
//                                 "pol045_t010020_m104172_test_F2019_11_selected_gen_flat.root",
//                                 "pol090_t010020_m104172_test_F2019_11_selected_gen_flat.root",
//                                 "pol135_t010020_m104172_test_F2019_11_selected_gen_flat.root"};

void gluex_style();
void etaPiPlotter(TString dirFit, TString fitName, TString outName, TString ampString, Bool_t isAccCorr, TString ampFitFracString, Bool_t isPlotAllVar, Bool_t isPlotGenHist);
void drawHist(){
    vector<vector<TString>> rootFlatTreeSignal;
    vector<vector<TString>> rootFlatTreeBkgnd;
    vector<vector<TString>> rootFlatTreeMCRecon;
    vector<vector<TString>> rootFlatTreeMCThrown;
    vector<TString> fitResultDir;

    for (auto polstrs: polString) {
        vector<TString> rootFlatTreeSignalTemp;
        vector<TString> rootFlatTreeBkgndTemp;
        vector<TString> rootFlatTreeMCReconTemp;
        vector<TString> rootFlatTreeMCThrownTemp;
        for (auto tbinstrs: tBinString) {
            rootFlatTreeSignalTemp.push_back(polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"D"+dataTag+"selected_data_flat.root");
            rootFlatTreeBkgndTemp.push_back(polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"D"+dataTag+"selected_bkgnd_flat.root");
            rootFlatTreeMCReconTemp.push_back(polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"F"+dataTag+"selected_acc_flat.root");
            rootFlatTreeMCThrownTemp.push_back(polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"F"+dataTag+"selected_gen_flat.root");
        }
        rootFlatTreeSignal.push_back(rootFlatTreeSignalTemp);
        rootFlatTreeBkgnd.push_back(rootFlatTreeBkgndTemp);
        rootFlatTreeMCRecon.push_back(rootFlatTreeMCReconTemp);
        rootFlatTreeMCThrown.push_back(rootFlatTreeMCThrownTemp);
    }

    // print data input
    cout << "Printing input files:" << endl;
    for (Int_t iPol=0;iPol<NPol;iPol++){
        cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            cout << rootFlatTreeSignal[iPol][iTBin] << endl;
            cout << rootFlatTreeBkgnd[iPol][iTBin] << endl;
            cout << rootFlatTreeMCRecon[iPol][iTBin] << endl;
            cout << rootFlatTreeMCThrown[iPol][iTBin] << endl;
        }
    }

    for (auto tbinstr: tBinString) fitResultDir.push_back(mainDir+tbinstr+"_0/");
    // print fit result directory
    cout << endl << endl << "Printing fit result directory:" << endl;
    for (Int_t iTBin=0;iTBin<NTBin;iTBin++) cout << fitResultDir[iTBin] << endl;
    
    if (isRunEtaPiPlotter) {
        // run etapi_plotter
        cout << endl << endl << "Running etapi_plotter..." << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++) etaPiPlotter(fitResultDir[iTBin],"etapi_result.fit","etapi_plot",Form("'%s'",strWave.Data()),kTRUE,strFitFracWave,kFALSE,kTRUE);
    }

    // open root files from etapi_plotter
    TFile *fHistFitResult[NTBin];
    cout << endl << endl << "Opening root files from etapi_plotter:" << endl;
    for (Int_t iTBin=0;iTBin<NTBin;iTBin++) {
        TString rootFileName = fitResultDir[iTBin] + etaPiPlotterOutName + "_" + strWave + ".root";
        cout << "File: " << rootFileName <<  endl;
        fHistFitResult[iTBin] = TFile::Open(rootFileName, "READ");
    }

    gluex_style();
    gROOT->ForceStyle();

    // TFile *fHistFitResult = TFile::Open(rootHistFitResult, "READ");
    // TFile *fFlatTreeSignal[NPol];
    // TFile *fFlatTreeBkgnd[NPol];
    // TFile *fFlatTreeMCRecon[NPol];
    // TFile *fFlatTreeMCThrown[NPol];

    TCanvas *c1 = new TCanvas("c1", "c1",1600,1200);
    c1->Divide(2,2);
    for (Int_t iTBin=0;iTBin<NTBin-1;iTBin++){
        c1->cd(iTBin+1);
        TH1F *h1MEtaPiAcc[NPol];
        TH1F *h1MEtaPiAccSum;
        TH1F *h1MEtaPiSig[NPol];
        TH1F *h1MEtaPiSigSum;
        TH1F *h1MEtaPiBkg[NPol];
        TH1F *h1MEtaPiBkgSum;
        for (Int_t iPol=0;iPol<NPol;iPol++){
            // fFlatTreeSignal[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeSignal[iPol], "READ");
            // fFlatTreeBkgnd[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeBkgnd[iPol], "READ");
            // fFlatTreeMCRecon[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeMCRecon[iPol], "READ");
            // fFlatTreeMCThrown[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeMCThrown[iPol], "READ");
            h1MEtaPiAcc[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMEtaPiAccName);
            h1MEtaPiSig[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMEtaPiSigName);
            h1MEtaPiBkg[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMetaPiBkgName);

            if (iPol==0) {
                h1MEtaPiAccSum = (TH1F*)h1MEtaPiAcc[iPol]->Clone();
                h1MEtaPiSigSum = (TH1F*)h1MEtaPiSig[iPol]->Clone();
                h1MEtaPiBkgSum = (TH1F*)h1MEtaPiBkg[iPol]->Clone();
            }
            else {
                h1MEtaPiAccSum->Add(h1MEtaPiAcc[iPol]);
                h1MEtaPiSigSum->Add(h1MEtaPiSig[iPol]);
                h1MEtaPiBkgSum->Add(h1MEtaPiBkg[iPol]);
            }        
        }
        
        // subtract signal with background
        h1MEtaPiSigSum->Add(h1MEtaPiBkgSum,-1.0);
        h1MEtaPiSigSum->GetXaxis()->SetRangeUser(1.04,1.72);
        h1MEtaPiSigSum->GetYaxis()->SetRangeUser(0,h1MEtaPiSigSum->GetMaximum()*1.2);
        h1MEtaPiSigSum->GetXaxis()->SetTitle("m_{#eta#pi^{0}} (GeV)");
        h1MEtaPiSigSum->GetYaxis()->SetTitle("Events / 40 MeV");
        h1MEtaPiSigSum->SetTitle(Form("%0.3f < |t| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));
        h1MEtaPiSigSum->Draw("HIST");
        h1MEtaPiAccSum->SetFillColor(kRed);
        h1MEtaPiAccSum->SetFillStyle(3002);
        h1MEtaPiAccSum->Draw("HIST SAME");
    }
    gSystem->cd(mainDir);
    c1->SaveAs(Form("plot_%s_%s.pdf",strWave.Data(),extraTag.Data()));

}

void etaPiPlotter(TString dirFit, TString fitName, TString outName, TString ampString, Bool_t isAccCorr, TString ampFitFracString, Bool_t isPlotAllVar, Bool_t isPlotGenHist){
    TString isAccCorrString;
    TString isPlotAllVarString;
    TString isPlotGenHistString;
    if (isAccCorr) isAccCorrString = "true";
    else isAccCorrString = "false";
    if (isPlotAllVar) isPlotAllVarString = "true";
    else isPlotAllVarString = "false";
    if (isPlotGenHist) isPlotGenHistString = "true";
    else isPlotGenHistString = "false";
    // cd into dirFit
    gSystem->cd(dirFit);
    cout << "Current directory: " << gSystem->pwd() << endl;

    // check if there is nan inside fit file
    TString cmdCheckNan = "grep -i nan " + fitName;
    cout << "Running command: " << cmdCheckNan << endl;
    gSystem->Exec(cmdCheckNan);

    // if there is replace nan with zeros
    TString cmdReplaceNan = "sed -i 's/nan/0/g' " + fitName;
    cout << "Running command: " << cmdReplaceNan << endl;
    gSystem->Exec(cmdReplaceNan);

    // run etapi_plotter
    TString cmd = "etapi_plotter " + fitName + " -o " + outName + " -s " + ampString + " -a " + isAccCorrString + " -F " + ampFitFracString + " -var " + isPlotAllVarString + " -gen " + isPlotGenHistString;
    cout << "Running command: " << cmd << endl;
    gSystem->Exec(cmd);
}

void gluex_style() {
	///////// 
	// Make the plots prettier with bigger fonts
	// Original code is https://halldweb.jlab.org/wiki-private/index.php/Guidance_for_Presentations 
	// 	slightly modified
	/////////
	auto gluex_style = new TStyle("GlueX","Default GlueX Style");

        gluex_style->SetCanvasBorderMode(0);
        gluex_style->SetPadBorderMode(0);
        gluex_style->SetPadColor(0);
        gluex_style->SetCanvasColor(0);
        gluex_style->SetStatColor(0);

	// some default window sizes
	gluex_style->SetCanvasDefW(800);
	gluex_style->SetCanvasDefH(600);

	// let's change the default margins
	gluex_style->SetPadBottomMargin(0.15);
	gluex_style->SetPadLeftMargin(0.2);
	gluex_style->SetPadTopMargin(0.08);
	gluex_style->SetPadRightMargin(0.15);

	// axis labels and settings
    gluex_style->SetStripDecimals(0);
 	gluex_style->SetLabelSize(0.045,"xyz"); // size of axis value font
 	gluex_style->SetTitleSize(0.06,"xyz"); // size of axis title font
 	gluex_style->SetTitleFont(42,"xyz"); // font option
 	gluex_style->SetLabelFont(42,"xyz"); 
 	gluex_style->SetTitleOffset(1.5,"y"); 
 	gluex_style->SetLabelOffset(0.01,"xyz");   // stop collisions of "0"s at the origin
 	
	// histogram settings
	gluex_style->SetOptStat(0);     // no stats box by default
	gluex_style->SetOptTitle(1);    // no title by default
	gluex_style->SetHistLineWidth(2); 
	gluex_style->SetNdivisions(508,"xyz"); // some ticks were very bunched, lets reduce the number of divisions to label 
	// gluex_style->SetOptFit(0111);

	gluex_style->SetHistFillColor(920);   // grey
	gluex_style->SetPalette(kViridis); // kViridis is perceptually uniform and colorblind friendly
	gluex_style->cd();
}