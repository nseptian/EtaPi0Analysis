// const TString mainDir = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/";
const TString mainDir = "/d/home/septian/EtaPi0Analysis/run/mass_dependent_fits/";
const TString dirRootFlatTree = "/d/home/septian/EtaPi0Analysis/run/rootFiles/";
const TString outDir = "/d/home/septian/EtaPi0Analysis/run/plots";
const TString bootstrapDir = "/d/home/septian/EtaPi0Analysis/run/bootstrap/";
// TString rootHistFitResult = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/etapi_plot_D2++_pD2++.root";
// TString dirRootFlatTree = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/rootFiles/t010020_m104172_test/";
const Int_t NPol = 4;
const TString polString[NPol] = {"pol000", "pol045", "pol090", "pol135"};

const Int_t NTBin = 5;
const TString tBinString[NTBin] = {"010020","0200325","0325050","050075","075100"};
const Float_t tMin[NTBin] = {0.1,0.2,0.325,0.5,0.75};
const Float_t tMax[NTBin] = {0.2,0.325,0.5,0.75,1.0};

// const Int_t NTBin = 1;
// const TString tBinString[NTBin] = {"0200325"};
// const Float_t tMin[NTBin] = {0.2};
// const Float_t tMax[NTBin] = {0.325};

// const Int_t NTBin = 5;
// const TString tBinString[NTBin] = {"010020","020030","030040","040050","050060"};
// const Float_t tMin[NTBin] = {0.1,0.2,0.3,0.4,0.5};
// const Float_t tMax[NTBin] = {0.2,0.3,0.4,0.5,0.6};

const TString mBinString = "m104172";

const TString extraTag = "wAccSub";
const TString dataTag = "2019_11";

// add phase 1 dataset (from Lawrence) for comparison 
const TString extraTagPhase1 = "nominal_wPhotonSyst";
const TString dataTagPhase1 = "Phase1";

// user config for plotting from flat trees
const Int_t NBranchFlatTree = 15;
const TString branchFlatTree[NBranchFlatTree] = {"Ebeam","Mpi0eta","Meta","Mpi0","Mpi0p","vanHove_omega","vanHove_x","vanHove_y","pVH","cosTheta_eta_gj","Weight","mismatchPairMass_13","mismatchPairMass_24","mismatchPairMass_14","mismatchPairMass_23"};
enum brVar{Ebeam,Mpi0eta,Meta,Mpi0,Mpi0p,vanHove_omega,vanHove_x,vanHove_y,pVH,cosTheta_eta_gj,Weight,mismatchPairMass_13,mismatchPairMass_24,mismatchPairMass_14,mismatchPairMass_23};
Float_t branchVar[NBranchFlatTree] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};

const Int_t NBranchFlatTreeThrown = 3;
const TString branchFlatTreeThrown[NBranchFlatTreeThrown] = {"Ebeam_thrown","Mpi0eta_thrown","cosTheta_eta_gj_thrown"};
enum brVarThrown{Ebeam_thrown,Mpi0eta_thrown,cosTheta_eta_gj_thrown};
Float_t branchVarThrown[NBranchFlatTreeThrown] = {1.0,1.0,1.0};

const Bool_t isPlotFromFlatTrees = kFALSE;
const Bool_t isPlotVanHopeAngle = kFALSE;
// const Bool_t isPlotMPi0Eta = kTRUE;

// user config for etapi_plotter
const Bool_t isRunEtaPiPlotter = kFALSE;
const Bool_t isPlotWaves = kFALSE;
const TString etaPiPlotterOutName = "etapi_plot";
const TString histBaseName[4] = {"EtaPi0_000_", "EtaPi0_045_", "EtaPi0_090_", "EtaPi0_135_"};
const TString dataAmpTools[4] = {"dat","bkg","acc","gen"};
const TString histMEtaPiAccName = "Metapi_40MeVBinacc";
const TString histMEtaPiSigName = "Metapi_40MeVBindat";
const TString histMetaPiBkgName = "Metapi_40MeVBinbkg";
const TString strWave[5] = {"S0+-_S0++",
                            "D1--_D0+-_D1+-_D0++_D1++_D2++",
                            "pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
                            "D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
                            "S0+-_S0++_D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++"
                           };
// const TString strWave = "D1--_D0+-_D1+-_D0++_D1++_D2++";
// const TString strWave = "S0+-_S0++";
const TString strFitFracWave = "D";

const Bool_t isPlotA2CS = kTRUE;
const Bool_t isA2CSBootstrap = kTRUE;
const Int_t NBootstrapSample = 100;
const TString etaPiPlotterOutLogName = "etapi_plotter_output.log";
const Double_t lum = 132.4; // pb^-1
const Double_t lumPhase1 = 125.0; // pb^-1
const TString fileNameA2CSTheory = "/d/home/septian/EtaPi0Analysis/run/theory_pred/Bands_TMD_A2_cs.txt";
const Float_t A2CSPhase1[5] = {0.2600,0.1173,0.0448,0.0521,0.0274};
const Float_t A2CSPhase1StatErr[5] = {0.0324,0.0166,0.0084,0.0067,0.0047};
const Float_t A2CSPhase1SystErr[5] = {0.0561,0.0285,0.0087,0.0074,0.0030};
const Float_t A2AccCorrYieldCenter[5] = {252491,99484,74132,77840,71284};

// waves=["S0+-_S0++",
//        "D1--_D0+-_D1+-_D0++_D1++_D2++",
//        "pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
//        "D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++",
//        "S0+-_S0++_D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++"
//       ]

void gluex_style();
void AssignSelectedBranches(TTree *tTree,const TString branchName[],Float_t branchVar[],Int_t NBrFlatTree);
void PlotFromFlatTree();
void etaPiPlotter(TString dirFit, TString fitName, TString outName, TString ampString, Bool_t isAccCorr, TString ampFitFracString, Bool_t isPlotAllVar, Bool_t isPlotGenHist);
vector<Double_t> GetAccCorrYield(TString fileName);
vector<vector<Double_t>> ReadCSV(TString fileName, Bool_t isPrint);
vector<Double_t> ReadFitsForBootstrap(Int_t NSample, Bool_t isRunEtaPiPlotter, Bool_t isReadFitFracWave);

// hist1DManager class for 1D histograms
class Hist1DManager {
    public:
        Hist1DManager();
        ~Hist1DManager();
        void Add(brVar brVar, TString XTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, TString extraName);
        void Add(TH1F* h1, brVar brVar, Int_t nBinsX, Float_t xMin, Float_t xMax);
        void Add(brVarThrown brVar, TString XTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, TString extraName);
        void Add(TH1F* h1, brVarThrown brVar, Int_t nBinsX, Float_t xMin, Float_t xMax);
        TH1F* GetHist(Int_t idxHist) {return vh1[idxHist];}
        void FillFromTree(TTree *tTree);
        void Print(Int_t idxHist, TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight);
        TH1F* GetHistSum();
        void PrintHistSum(TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight);
        Int_t GetSize() {return NHist;}
        brVar GetBrVar(Int_t idxHist) {return vBrVar[idxHist];}
        brVarThrown GetBrVarThrown(Int_t idxHist) {return vBrVarThrown[idxHist];}
        Int_t GetNBinsX(Int_t idxHist) {return vNBinsX[idxHist];}
        Float_t GetXMin(Int_t idxHist) {return vXMin[idxHist];}
        Float_t GetXMax(Int_t idxHist) {return vXMax[idxHist];}

    private:
        Int_t NHist;
        vector<TH1F*> vh1;
        vector<brVar> vBrVar;
        vector<TString> vBrName;
        vector<brVarThrown> vBrVarThrown;
        vector<TString> vBrNameThrown;
        vector<Int_t> vNBinsX;
        vector<Float_t> vXMin;
        vector<Float_t> vXMax;
};

Hist1DManager::Hist1DManager() {
    NHist = 0;
}

Hist1DManager::~Hist1DManager() {
    for (Int_t iHist=0;iHist<NHist;iHist++) delete vh1[iHist];
}

void Hist1DManager::Add(brVar brVar, TString XTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, TString extraName) {
    vh1.push_back(new TH1F(Form("h1_%s_%s",branchFlatTree[brVar].Data(),extraName.Data()),Form("%s",XTitle.Data()),nBinsX,xMin,xMax));
    vh1[NHist]->GetXaxis()->SetTitle(XTitle);
    TString strYTitle = "Events";
    if ((brVar==Mpi0eta) || (brVar==Mpi0p)) strYTitle += Form(" / %0.2f MeV",vh1[NHist]->GetBinWidth(1)*1000.0);
    vh1[NHist]->GetYaxis()->SetTitle(strYTitle);
    vh1[NHist]->SetMinimum(0.0);
    vBrVar.push_back(brVar);
    vBrName.push_back(branchFlatTree[brVar]);
    vNBinsX.push_back(nBinsX);
    vXMin.push_back(xMin);
    vXMax.push_back(xMax);
    NHist++;
}

void Hist1DManager::Add(TH1F* h1, brVar brVar, Int_t nBinsX, Float_t xMin, Float_t xMax) {
    vh1.push_back(static_cast<TH1F*>(h1->Clone()));
    vBrVar.push_back(brVar);
    vBrName.push_back(branchFlatTree[brVar]);
    vNBinsX.push_back(nBinsX);
    vXMin.push_back(xMin);
    vXMax.push_back(xMax);
    NHist++;
}

void Hist1DManager::Add(brVarThrown brVar, TString XTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, TString extraName) {
    vh1.push_back(new TH1F(Form("h1_%s_%s",branchFlatTreeThrown[brVar].Data(),extraName.Data()),Form("%s",XTitle.Data()),nBinsX,xMin,xMax));
    vh1[NHist]->GetXaxis()->SetTitle(XTitle);
    TString strYTitle = "Events";
    if (brVar==Mpi0eta_thrown) strYTitle += Form(" / %0.2f MeV",vh1[NHist]->GetBinWidth(1)*1000.0);
    vh1[NHist]->GetYaxis()->SetTitle(strYTitle);
    vh1[NHist]->SetMinimum(0.0);
    vBrVarThrown.push_back(brVar);
    vBrNameThrown.push_back(branchFlatTreeThrown[brVar]);
    vNBinsX.push_back(nBinsX);
    vXMin.push_back(xMin);
    vXMax.push_back(xMax);
    NHist++;
}

void Hist1DManager::Add(TH1F* h1, brVarThrown brVar, Int_t nBinsX, Float_t xMin, Float_t xMax) {
    vh1.push_back(static_cast<TH1F*>(h1->Clone()));
    vBrVarThrown.push_back(brVar);
    vBrNameThrown.push_back(branchFlatTreeThrown[brVar]);
    vNBinsX.push_back(nBinsX);
    vXMin.push_back(xMin);
    vXMax.push_back(xMax);
    NHist++;
}

void Hist1DManager::FillFromTree(TTree *tTree) {
    if (vBrVar.size()==0 && vBrVarThrown.size()==0) {
        cout << "ERROR: No branch variable is added!" << endl;
        return;
    }
    
    if (vBrVar.size()>0) {
        cout << "Filling histograms from flat tree with branch variable(s):" << endl;
        for (Int_t iBr=0;iBr<vBrVar.size();iBr++) cout << vBrName[iBr] << endl;
    }

    if (vBrVarThrown.size()>0) {
        cout << "Filling histograms from thrown flat tree with branch variable(s):" << endl;
        for (Int_t iBr=0;iBr<vBrVarThrown.size();iBr++) cout << vBrNameThrown[iBr] << endl;
    }
    
    for (Int_t iHist=0;iHist<NHist;iHist++) {
        for (Int_t iEvent=0;iEvent<tTree->GetEntries();iEvent++) {
            tTree->GetEntry(iEvent);
            if (vBrVar.size()>0) vh1[iHist]->Fill(branchVar[vBrVar[iHist]],branchVar[Weight]);
            if (vBrVarThrown.size()>0) {
                vh1[iHist]->Fill(branchVarThrown[vBrVarThrown[iHist]]);
            }
        }
    }
}

void Hist1DManager::Print(Int_t idxHist, TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight) {
    TCanvas *cHist1 = new TCanvas("cHist1", "cHist1",canvasWidth,canvasHeight);
    vh1[idxHist]->Draw(drawOption);
    cHist1->SaveAs(fileName);
    delete cHist1;
}

TH1F* Hist1DManager::GetHistSum() {
    if (NHist==0) {
        cout << "ERROR: No histogram is added!" << endl;
        return NULL;
    }
    TH1F *h1Sum = (TH1F*)vh1[0]->Clone();
    // check if all histograms have the same properties

    if (vBrVar.size()>0) {
        for (Int_t iHist=1;iHist<NHist;iHist++) {
            if (vBrVar[iHist]!=vBrVar[0]) {
                cout << "ERROR: Histograms have different branches!" << endl;
                return NULL;
            }
            if (vNBinsX[iHist]!=vNBinsX[0]) {
                cout << "ERROR: Histograms have different number of bins!" << endl;
                return NULL;
            }
            if (vXMin[iHist]!=vXMin[0]) {
                cout << "ERROR: Histograms have different minimum values!" << endl;
                return NULL;
            }
            if (vXMax[iHist]!=vXMax[0]) {
                cout << "ERROR: Histograms have different maximum values!" << endl;
                return NULL;
            }
        }
    }

    if (vBrVarThrown.size()>0) {
        for (Int_t iHist=1;iHist<NHist;iHist++) {
            if (vBrVarThrown[iHist]!=vBrVarThrown[0]) {
                cout << "ERROR: Histograms have different branches!" << endl;
                return NULL;
            }
            if (vNBinsX[iHist]!=vNBinsX[0]) {
                cout << "ERROR: Histograms have different number of bins!" << endl;
                return NULL;
            }
            if (vXMin[iHist]!=vXMin[0]) {
                cout << "ERROR: Histograms have different minimum values!" << endl;
                return NULL;
            }
            if (vXMax[iHist]!=vXMax[0]) {
                cout << "ERROR: Histograms have different maximum values!" << endl;
                return NULL;
            }
        }
    }
    
    for (Int_t iHist=1;iHist<NHist;iHist++) h1Sum->Add(vh1[iHist]);
    return h1Sum;
}

void Hist1DManager::PrintHistSum(TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight) {
    TCanvas *c = new TCanvas("c", "c",canvasWidth,canvasHeight);
    GetHistSum()->Draw(drawOption);
    c->SaveAs(fileName);
    delete c;
}

// hist2DManager class for 2D histograms
class Hist2DManager {
    public:
        Hist2DManager();
        ~Hist2DManager();
        void Add(brVar brVarX, brVar brVarY, TString XTitle, TString YTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, Int_t nBinsY, Float_t yMin, Float_t yMax, TString extraName);
        void Add(TH2F* h2, brVar brVarX, brVar brVarY, Int_t nBinsX, Float_t xMin, Float_t xMax, Int_t nBinsY, Float_t yMin, Float_t yMax);
        TH2F* GetHist(Int_t idxHist) {return vh2[idxHist];}
        void FillFromTree(TTree *tTree);
        void Print(Int_t idxHist, TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight);
        Int_t GetSize() {return NHist;}
        TH2F* GetHistSum();
        void PrintHistSum(TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight);
        brVar GetBrVarX(Int_t idxHist) {return vBrVarX[idxHist];}
        brVar GetBrVarY(Int_t idxHist) {return vBrVarY[idxHist];}
        Int_t GetNBinsX(Int_t idxHist) {return vNBinsX[idxHist];}
        Int_t GetNBinsY(Int_t idxHist) {return vNBinsY[idxHist];}
        Float_t GetXMin(Int_t idxHist) {return vXMin[idxHist];}
        Float_t GetYMin(Int_t idxHist) {return vYMin[idxHist];}
        Float_t GetXMax(Int_t idxHist) {return vXMax[idxHist];}
        Float_t GetYMax(Int_t idxHist) {return vYMax[idxHist];}

    private:
        Int_t NHist;
        vector<TH2F*> vh2;
        vector<brVar> vBrVarX;
        vector<brVar> vBrVarY;
        vector<TString> vBrNameX;
        vector<TString> vBrNameY;
        vector<Int_t> vNBinsX;
        vector<Int_t> vNBinsY;
        vector<Float_t> vXMin;
        vector<Float_t> vYMin;
        vector<Float_t> vXMax;
        vector<Float_t> vYMax;
        TH2F *h2Sum;
};

Hist2DManager::Hist2DManager() {
    NHist = 0;
}

Hist2DManager::~Hist2DManager() {
    for (Int_t iHist=0;iHist<NHist;iHist++) delete vh2[iHist];
}

void Hist2DManager::Add(brVar brVarX, brVar brVarY, TString XTitle, TString YTitle, Int_t nBinsX, Float_t xMin, Float_t xMax, Int_t nBinsY, Float_t yMin, Float_t yMax, TString extraName) {
    vh2.push_back(new TH2F(Form("h2_%s_%s_%s",branchFlatTree[brVarX].Data(),branchFlatTree[brVarY].Data(),extraName.Data()),Form("%s vs %s",XTitle.Data(),YTitle.Data()),nBinsX,xMin,xMax,nBinsY,yMin,yMax));
    vh2[NHist]->GetXaxis()->SetTitle(XTitle);
    vh2[NHist]->GetYaxis()->SetTitle(YTitle);
    vBrVarX.push_back(brVarX);
    vBrVarY.push_back(brVarY);
    vBrNameX.push_back(branchFlatTree[brVarX]);
    vBrNameY.push_back(branchFlatTree[brVarY]);
    vNBinsX.push_back(nBinsX);
    vNBinsY.push_back(nBinsY);
    vXMin.push_back(xMin);
    vYMin.push_back(yMin);
    vXMax.push_back(xMax);
    vYMax.push_back(yMax);
    NHist++;
}

void Hist2DManager::Add(TH2F* h2, brVar brVarX, brVar brVarY, Int_t nBinsX, Float_t xMin, Float_t xMax, Int_t nBinsY, Float_t yMin, Float_t yMax) {
    vh2.push_back(static_cast<TH2F*>(h2->Clone()));
    vBrVarX.push_back(brVarX);
    vBrVarY.push_back(brVarY);
    vBrNameX.push_back(branchFlatTree[brVarX]);
    vBrNameY.push_back(branchFlatTree[brVarY]);
    vNBinsX.push_back(nBinsX);
    vNBinsY.push_back(nBinsY);
    vXMin.push_back(xMin);
    vYMin.push_back(yMin);
    vXMax.push_back(xMax);
    vYMax.push_back(yMax);
    NHist++;
}

void Hist2DManager::FillFromTree(TTree *tTree) {
    if (vBrVarX.size()==0) {
        cout << "ERROR: No branch variable is added!" << endl;
        return;
    }
    if (vBrVarX.size()>0) {
        cout << "Filling histograms from flat tree with branch variable(s):" << endl;
        for (Int_t iBr=0;iBr<vBrVarX.size();iBr++) cout << vBrNameX[iBr] << "," << vBrNameY[iBr] << endl;
    }
    for (Int_t iHist=0;iHist<NHist;iHist++) {
        for (Int_t iEvent=0;iEvent<tTree->GetEntries();iEvent++) {
            tTree->GetEntry(iEvent);
            vh2[iHist]->Fill(branchVar[vBrVarX[iHist]],branchVar[vBrVarY[iHist]],branchVar[Weight]);
        }
    }
}

void Hist2DManager::Print(Int_t idxHist, TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight) {
    TCanvas *c = new TCanvas("c", "c",canvasWidth,canvasHeight);
    vh2[idxHist]->Draw(drawOption);
    c->SaveAs(fileName);
    delete c;
}

TH2F* Hist2DManager::GetHistSum() {
    h2Sum = (TH2F*)vh2[0]->Clone();
    // check if all histograms have the same properties
    for (Int_t iHist=1;iHist<NHist;iHist++) {
        if (vBrVarX[iHist]!=vBrVarX[0] || vBrVarY[iHist]!=vBrVarY[0]) {
            cout << "ERROR: Histograms have different branches!" << endl;
            return NULL;
        }
        if (vNBinsX[iHist]!=vNBinsX[0] || vNBinsY[iHist]!=vNBinsY[0]) {
            cout << "ERROR: Histograms have different number of bins!" << endl;
            return NULL;
        }
        if (vXMin[iHist]!=vXMin[0] || vYMin[iHist]!=vYMin[0]) {
            cout << "ERROR: Histograms have different minimum values!" << endl;
            return NULL;
        }
        if (vXMax[iHist]!=vXMax[0] || vYMax[iHist]!=vYMax[0]) {
            cout << "ERROR: Histograms have different maximum values!" << endl;
            return NULL;
        }
    }
    for (Int_t iHist=1;iHist<NHist;iHist++) h2Sum->Add(vh2[iHist]);
    return h2Sum;
}

void Hist2DManager::PrintHistSum(TString fileName, TString drawOption, Int_t canvasWidth, Int_t canvasHeight) {
    TCanvas *c = new TCanvas("c", "c",canvasWidth,canvasHeight);
    GetHistSum()->Draw(drawOption);
    c->SaveAs(fileName);
    delete c;
}

void drawHistPWA(){
    gluex_style();
    gROOT->ForceStyle();

    vector<vector<TString>> rootFlatTreeSignal;
    vector<vector<TString>> rootFlatTreeBkgnd;
    vector<vector<TString>> rootFlatTreeRecon;
    vector<vector<TString>> rootFlatTreeMCRecon;
    vector<vector<TString>> rootFlatTreeMCThrown;

    vector<vector<TString>> rootFlatTreeReconPhase1;
    
    vector<TString> fitResultDir;
    for (auto tbinstr: tBinString) fitResultDir.push_back(mainDir+tbinstr+"_"+extraTag+"_0/");
    // print fit result directory
    cout << endl << endl << "Printing fit result directory:" << endl;
    for (Int_t iTBin=0;iTBin<NTBin;iTBin++) cout << fitResultDir[iTBin] << endl;
    
    // TCanvas *c1 = new TCanvas("c1", "c1",1200,1200);
    // TCanvas *c2 = new TCanvas("c2", "c2",1600,800);
    // TCanvas *c_Mpi0Eta = new TCanvas("c_Mpi0Eta", "c_Mpi0Eta",1600,1200);
    // TCanvas *c_test = new TCanvas("c_test", "c_test",1600,1200);

    if (isPlotFromFlatTrees){
        PlotFromFlatTree();
    }
 
    if (isRunEtaPiPlotter) {
        // run etapi_plotter
        cout << endl << endl << "Running etapi_plotter..." << endl;
        for (Int_t iStrWave=0;iStrWave<5;iStrWave++) {
            for (Int_t iTBin=0;iTBin<NTBin;iTBin++) etaPiPlotter(fitResultDir[iTBin],"etapi_result.fit","etapi_plot",Form("'%s'",strWave[iStrWave].Data()),kTRUE,strFitFracWave,kFALSE,kTRUE);
        }
    }

    if (isPlotWaves) {
        // open root files from etapi_plotter
        TCanvas *cWaves = new TCanvas("cWaves", "cWaves",1600,800);
        cWaves->Divide(5,3,0.0,0.0);
        TLegend *leg[3];

        TFile *fHistFitResultS[NTBin];
        TFile *fHistFitResultD[NTBin];
        TFile *fHistFitResultpD[NTBin];
        Float_t yMaxx;
        cout << endl << endl << "Opening root files from etapi_plotter:" << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++) {
            cout << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
            TString rootFileName = fitResultDir[iTBin] + etaPiPlotterOutName + "_" + strWave[0] + ".root";
            cout << "Root file S-wave: " << rootFileName <<  endl;
            fHistFitResultS[iTBin] = TFile::Open(rootFileName, "READ");
            rootFileName = fitResultDir[iTBin] + etaPiPlotterOutName + "_" + strWave[1] + ".root";
            cout << "Root file D-wave: " << rootFileName <<  endl;
            fHistFitResultD[iTBin] = TFile::Open(rootFileName, "READ");
            rootFileName = fitResultDir[iTBin] + etaPiPlotterOutName + "_" + strWave[2] + ".root";
            cout << "Root file pD-wave: " << rootFileName <<  endl;
            fHistFitResultpD[iTBin] = TFile::Open(rootFileName, "READ");
        }

        TH1F *h1MEtaPiAccSSum[NTBin];
        TH1F *h1MEtaPiAccDSum[NTBin];
        TH1F *h1MEtaPiAccpDSum[NTBin+1];
        TH1F *h1MEtaPiSigSum[NTBin];
        TH1F *h1MEtaPiBkgSum[NTBin];
        THStack *hs[NTBin+1];
        TLatex *lLatex = new TLatex();
        lLatex->SetTextSize(0.08);
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            TH1F *h1MEtaPiAccS[NPol];
            TH1F *h1MEtaPiAccD[NPol];
            TH1F *h1MEtaPiAccpD[NPol];
            TH1F *h1MEtaPiSig[NPol];
            TH1F *h1MEtaPiBkg[NPol];
            for (Int_t iPol=0;iPol<NPol;iPol++){

                h1MEtaPiAccS[iPol] = (TH1F*)fHistFitResultS[iTBin]->Get(histBaseName[iPol]+histMEtaPiAccName);
                h1MEtaPiAccD[iPol] = (TH1F*)fHistFitResultD[iTBin]->Get(histBaseName[iPol]+histMEtaPiAccName);
                h1MEtaPiAccpD[iPol] = (TH1F*)fHistFitResultpD[iTBin]->Get(histBaseName[iPol]+histMEtaPiAccName);
                h1MEtaPiSig[iPol] = (TH1F*)fHistFitResultS[iTBin]->Get(histBaseName[iPol]+histMEtaPiSigName);
                h1MEtaPiBkg[iPol] = (TH1F*)fHistFitResultS[iTBin]->Get(histBaseName[iPol]+histMetaPiBkgName);

                if (iPol==0) {
                    h1MEtaPiAccSSum[iTBin] = new TH1F(*h1MEtaPiAccS[iPol]);
                    h1MEtaPiAccDSum[iTBin] = new TH1F(*h1MEtaPiAccD[iPol]);
                    h1MEtaPiAccpDSum[iTBin] = new TH1F(*h1MEtaPiAccpD[iPol]);
                    h1MEtaPiSigSum[iTBin] = new TH1F(*h1MEtaPiSig[iPol]);
                    h1MEtaPiBkgSum[iTBin] = new TH1F(*h1MEtaPiBkg[iPol]);
                }
                else {
                    h1MEtaPiAccSSum[iTBin]->Add(h1MEtaPiAccS[iPol]);
                    h1MEtaPiAccDSum[iTBin]->Add(h1MEtaPiAccD[iPol]);
                    h1MEtaPiAccpDSum[iTBin]->Add(h1MEtaPiAccpD[iPol]);
                    h1MEtaPiSigSum[iTBin]->Add(h1MEtaPiSig[iPol]);
                    h1MEtaPiBkgSum[iTBin]->Add(h1MEtaPiBkg[iPol]);
                }
                // cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
                // cout << "Acc: " << h1MEtaPiAcc[iPol]->Integral() << endl;
                // cout << "Sig: " << h1MEtaPiSig[iPol]->Integral() << endl;
                // cout << "Bkg: " << h1MEtaPiBkg[iPol]->Integral() << endl;        
            }
            
            // cout << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
            // cout << "Acc: " << h1MEtaPiAccSum[iTBin]->Integral() << endl;
            // cout << "Sig: " << h1MEtaPiSigSum[iTBin]->Integral() << endl;
            // cout << "Bkg: " << h1MEtaPiBkgSum[iTBin]->Integral() << endl;

            // subtract signal with background

            h1MEtaPiSigSum[iTBin]->Add(h1MEtaPiBkgSum[iTBin],-1.0);
            h1MEtaPiSigSum[iTBin]->GetXaxis()->SetRangeUser(1.04,1.65);
            h1MEtaPiSigSum[iTBin]->GetXaxis()->SetLabelSize(0.08);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetLabelSize(0.08);
            h1MEtaPiSigSum[iTBin]->GetXaxis()->SetTitleSize(0.1);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitleSize(0.1);
            if (iTBin==0) yMaxx = h1MEtaPiSigSum[iTBin]->GetMaximum()*1.2;
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetRangeUser(50,yMaxx);
            if (iTBin==NTBin-1) h1MEtaPiSigSum[iTBin]->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
            else h1MEtaPiSigSum[iTBin]->GetXaxis()->SetTitle("");
            h1MEtaPiSigSum[iTBin]->SetTitle(Form("%0.3f < |t| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));
            h1MEtaPiSigSum[iTBin]->SetLineColor(kBlack);
            h1MEtaPiSigSum[iTBin]->SetLineWidth(1);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitle("");
            // h1MEtaPiSigSum[iTBin]->DrawCopy("HIST");

            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitle("Events / 40 MeV");

            cWaves->cd(iTBin+1);
            h1MEtaPiSigSum[iTBin]->DrawCopy("HIST");
            h1MEtaPiAccSSum[iTBin]->SetLineColor(11);
            h1MEtaPiAccSSum[iTBin]->SetLineWidth(1);
            h1MEtaPiAccSSum[iTBin]->SetFillColor(11);
            h1MEtaPiAccSSum[iTBin]->SetFillStyle(1001);
            h1MEtaPiAccSSum[iTBin]->DrawCopy("HIST SAME");
            if (iTBin!=0) lLatex->DrawLatexNDC(0.3,0.9,Form("%0.3f < -t < %0.3f",tMin[iTBin],tMax[iTBin]));
            else lLatex->DrawLatexNDC(0.45,0.9,Form("%0.3f < -t < %0.3f",tMin[iTBin],tMax[iTBin]));
            if (iTBin==NTBin-1) {
                leg[0] = new TLegend(0.3,0.6,0.9,0.8);
                leg[0]->AddEntry(h1MEtaPiSigSum[iTBin],"Data","l");
                leg[0]->AddEntry(h1MEtaPiAccSSum[iTBin],"S-waves","f");
                leg[0]->SetBorderSize(0);
                leg[0]->SetTextSize(0.08);
                leg[0]->Draw();
            }
            gPad->RedrawAxis();

            cWaves->cd(iTBin+1+NTBin);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitle("");
            h1MEtaPiSigSum[iTBin]->DrawCopy("HIST");
            h1MEtaPiAccDSum[iTBin]->SetLineColor(kRed);
            h1MEtaPiAccDSum[iTBin]->SetLineWidth(1);
            h1MEtaPiAccDSum[iTBin]->SetFillColorAlpha(kRed,0.5);
            h1MEtaPiAccDSum[iTBin]->SetFillStyle(1001);
            h1MEtaPiAccDSum[iTBin]->DrawCopy("HIST SAME");
            if (iTBin==NTBin-1) {
                leg[1] = new TLegend(0.3,0.7,0.9,0.8);
                // leg[1]->AddEntry(h1MEtaPiSigSum[iTBin],"Data","l");
                leg[1]->AddEntry(h1MEtaPiAccDSum[iTBin],"a_{2}(1320)","f");
                leg[1]->SetBorderSize(0);
                leg[1]->SetTextSize(0.08);
                leg[1]->Draw();
            }

            cWaves->cd(iTBin+1+2*NTBin);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitle("");
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetLabelSize(0.06);
            h1MEtaPiSigSum[iTBin]->DrawCopy("HIST");
            h1MEtaPiAccpDSum[iTBin]->SetLineColor(11);
            h1MEtaPiAccpDSum[iTBin]->SetLineWidth(1);
            h1MEtaPiAccpDSum[iTBin]->SetFillColor(11);
            h1MEtaPiAccpDSum[iTBin]->SetFillStyle(1001);
            h1MEtaPiAccpDSum[iTBin]->DrawCopy("HIST SAME");
            if (iTBin==NTBin-1) {
                leg[2] = new TLegend(0.3,0.7,0.9,0.8);
                // leg[2]->AddEntry(h1MEtaPiSigSum[iTBin],"Data","l");
                leg[2]->AddEntry(h1MEtaPiAccpDSum[iTBin],"a_{2}(1700)","f");
                leg[2]->SetBorderSize(0);
                leg[2]->SetTextSize(0.062);
                leg[2]->Draw();
            }
            
            gPad->RedrawAxis();

            // hs[iTBin] = new THStack(Form("hs_%d",iTBin),"hs");
            // h1MEtaPiAccSSum[iTBin]->SetLineColor(11);
            // h1MEtaPiAccSSum[iTBin]->SetLineWidth(1);
            // h1MEtaPiAccSSum[iTBin]->SetFillColor(11);
            // h1MEtaPiAccSSum[iTBin]->SetFillStyle(1001);
            // hs[iTBin]->Add(static_cast<TH1*>(h1MEtaPiAccSSum[iTBin]->Clone()),"hist");
            // h1MEtaPiAccDSum[iTBin]->SetLineColor(kRed);
            // h1MEtaPiAccDSum[iTBin]->SetLineWidth(1);
            // h1MEtaPiAccDSum[iTBin]->SetFillColorAlpha(kRed,0.5);
            // h1MEtaPiAccDSum[iTBin]->SetFillStyle(1001);
            // hs[iTBin]->Add(static_cast<TH1*>(h1MEtaPiAccDSum[iTBin]->Clone()),"hist");
            // h1MEtaPiAccpDSum[iTBin]->SetLineColor(kGreen);
            // h1MEtaPiAccpDSum[iTBin]->SetFillColor(kGreen);
            // h1MEtaPiAccpDSum[iTBin]->SetFillStyle(3001);
            // hs[iTBin]->Add(static_cast<TH1*>(h1MEtaPiAccpDSum[iTBin]->Clone()),"hist");
            
            /* Draw stacked histograms
            hs[iTBin]->Draw("same");
            h1MEtaPiSigSum[iTBin]->DrawCopy("SAME");
            if (iTBin==NTBin-1) {
                TLegend *leg2 = new TLegend(0.3,0.65,0.9,0.95);
                leg2->AddEntry(h1MEtaPiSigSum[iTBin],"Data","pl");
                leg2->AddEntry(h1MEtaPiAccSSum[iTBin],"S-waves","f");
                leg2->AddEntry(h1MEtaPiAccDSum[iTBin],"a_{2}(1320)","f");
                leg2->SetBorderSize(0);
                leg2->SetTextSize(0.05);
                leg2->Draw();
            };
            */
            // h1MEtaPiAccDSum[iTBin]->DrawCopy("HIST SAME");
            // h1MEtaPiAccSum[iTBin]->SetFillColor(kRed);
            // h1MEtaPiAccSum[iTBin]->SetFillStyle(3002);
            // h1MEtaPiAccSum[iTBin]->DrawCopy("HIST SAME");
            // lLatex->DrawLatexNDC(0.5,0.85,Form("%0.3f<t<%0.3f",tMin[iTBin],tMax[iTBin]));
            if (iTBin!=NTBin-1) {
                delete h1MEtaPiAccSSum[iTBin];
                delete h1MEtaPiAccDSum[iTBin];
                delete h1MEtaPiAccpDSum[iTBin];
                delete h1MEtaPiSigSum[iTBin];
                delete h1MEtaPiBkgSum[iTBin];
            }
            // delete hs;
        }
        gSystem->cd(mainDir);
        cWaves->SaveAs(Form("%s/plot_waveset_%s_%s.pdf",outDir.Data(),strWave[4].Data(),extraTag.Data()));

        delete h1MEtaPiAccSSum[NTBin-1];
        delete h1MEtaPiAccDSum[NTBin-1];
        delete h1MEtaPiAccpDSum[NTBin-1];
        delete h1MEtaPiSigSum[NTBin-1];
        delete h1MEtaPiBkgSum[NTBin-1];
    }
    // cWaves->Clear();
    // cWaves->Divide(1,1);
    if (isPlotA2CS) {
        TCanvas *cA2CS = new TCanvas("cA2CS", "cA2CS",1600,800);
        vector<vector<Double_t>> vA2CS_theory = ReadCSV(fileNameA2CSTheory,kFALSE);
        TGraphAsymmErrors *gA2CS_theory = new TGraphAsymmErrors();
        
        for (Int_t iPoint=0;iPoint<vA2CS_theory.size();iPoint++) {
            gA2CS_theory->AddPoint(vA2CS_theory[iPoint][0],vA2CS_theory[iPoint][2]);
            gA2CS_theory->SetPointError(iPoint,0,0,vA2CS_theory[iPoint][2]-vA2CS_theory[iPoint][1],vA2CS_theory[iPoint][3]-vA2CS_theory[iPoint][2]);
        }
        TGraphErrors *gA2CS = new TGraphErrors();
        TGraphErrors *gA2CSStatErr = new TGraphErrors();
        TGraphErrors *gA2CSPhase1StatErr = new TGraphErrors();
        TGraphErrors *gA2CSPhase1SystErr = new TGraphErrors();
        vector<Double_t> A2CSStatErrBootstrap={0.0,0.0,0.0,0.0,0.0};
        
        if (isA2CSBootstrap) A2CSStatErrBootstrap = ReadFitsForBootstrap(NBootstrapSample,kFALSE,kTRUE);
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            TString fName = fitResultDir[iTBin] + etaPiPlotterOutLogName;
            vector<Double_t> accCorrYield = GetAccCorrYield(fName);
            Double_t dt = tMax[iTBin]-tMin[iTBin];
            Double_t dsigdt = accCorrYield[0]/(1000000*lum*dt*0.0565);
            Double_t dsigdtStatErr = 0.0;
            if (isA2CSBootstrap) dsigdtStatErr = A2CSStatErrBootstrap[iTBin]/(1000000*lum*dt*0.0565);
            else dsigdtStatErr = accCorrYield[1]/(1000000*lum*dt*0.0565);
            Double_t toffset = 0.006;
            gA2CS->AddPoint((tMin[iTBin]+tMax[iTBin])/2+toffset,dsigdt);
            // gA2CS->SetPointError(iTBin,0,dsigdtStatErr);
            gA2CSStatErr->AddPoint((tMin[iTBin]+tMax[iTBin])/2+toffset,dsigdt);
            gA2CSStatErr->SetPointError(iTBin,0.005,dsigdtStatErr);
            // cout << endl << (tMin[iTBin]+tMax[iTBin])/2 << " " << accCorrYield[0] << " +- " << accCorrYield[1] << endl;
            gA2CSPhase1StatErr->AddPoint((tMin[iTBin]+tMax[iTBin])/2-toffset,A2CSPhase1[iTBin]);
            gA2CSPhase1StatErr->SetPointError(iTBin,0.005,A2CSPhase1StatErr[iTBin]);
            gA2CSPhase1SystErr->AddPoint((tMin[iTBin]+tMax[iTBin])/2-toffset,A2CSPhase1[iTBin]);
            gA2CSPhase1SystErr->SetPointError(iTBin,0.005,A2CSPhase1SystErr[iTBin]);
        }

        cA2CS->cd();
        gA2CS_theory->SetLineColor(kBlue);
        gA2CS_theory->SetFillColor(kBlue);
        gA2CS_theory->SetFillStyle(3002);
        gA2CS_theory->GetXaxis()->SetRangeUser(0.1,1.0);
        gA2CS_theory->GetXaxis()->SetTitle("|t| (GeV^{2})");
        gA2CS_theory->GetXaxis()->SetTitleSize(0.05);
        gA2CS_theory->GetXaxis()->SetTitleOffset(1.2);
        gA2CS_theory->GetXaxis()->SetLabelSize(0.04);
        gA2CS_theory->GetYaxis()->SetRangeUser(0.0,gA2CS->GetHistogram()->GetMaximum()*1.1);
        gA2CS_theory->GetYaxis()->SetTitle("#frac{d#sigma}{dt} #left(#frac{#mub}{GeV^{2}}#right)");
        gA2CS_theory->GetYaxis()->SetTitleSize(0.05);
        gA2CS_theory->GetYaxis()->SetTitleOffset(1.2);
        gA2CS_theory->GetYaxis()->SetLabelSize(0.04);
        gA2CS_theory->Draw("ca3");

        gA2CS->SetMarkerStyle(47);
        gA2CS->SetMarkerSize(2);
        gA2CS->SetMarkerColor(kRed);
        gA2CS->SetLineColor(kRed);
        gA2CS->Draw("PSAME");

        gA2CSStatErr->SetLineWidth(0);
        gA2CSStatErr->SetFillColorAlpha(kRed,0.5);
        gA2CSStatErr->SetFillStyle(1001);
        gA2CSStatErr->Draw("2SAME");

        gA2CSPhase1StatErr->SetLineWidth(0);
        gA2CSPhase1StatErr->SetFillColorAlpha(kBlack,0.5);
        gA2CSPhase1StatErr->SetFillStyle(1001);
        gA2CSPhase1StatErr->Draw("2SAME");

        gA2CSPhase1SystErr->SetMarkerStyle(20);
        gA2CSPhase1SystErr->SetMarkerSize(2);
        gA2CSPhase1SystErr->SetMarkerColor(kBlack);
        gA2CSPhase1SystErr->SetLineColor(kBlack);
        gA2CSPhase1SystErr->Draw("PSAME");

        TLegend *legA2CS = new TLegend(0.6,0.5,0.8,0.85);
        legA2CS->AddEntry(gA2CS_theory,"#splitline{TMD predictions}{E_{#gamma}=8.5 GeV}","f");
        legA2CS->AddEntry(gA2CSPhase1SystErr,"#splitline{GlueX-I}{E_{#gamma}=[8.2,8.8] GeV}","pl");
        legA2CS->AddEntry(gA2CS,"#splitline{GlueX-II}{E_{#gamma}=[8.0,8.6] GeV}","p");
        legA2CS->AddEntry(gA2CSPhase1StatErr,"Statistical Unc.","f");
        legA2CS->SetTextSize(0.03);
        legA2CS->SetBorderSize(0);
        legA2CS->Draw();

        gSystem->cd(outDir);
        cA2CS->SaveAs(Form("plot_A2CS_%s.pdf",extraTag.Data()));
    }
}

void PlotFromFlatTree(){
    // vector to store root file names
    vector<vector<TString>> rootFlatTreeSignal;
    vector<vector<TString>> rootFlatTreeBkgnd;
    vector<vector<TString>> rootFlatTreeRecon;
    vector<vector<TString>> rootFlatTreeMCRecon;
    vector<vector<TString>> rootFlatTreeMCThrown;

    vector<vector<TString>> rootFlatTreeReconPhase1;
    vector<vector<TString>> rootFlatTreeMCReconPhase1;
    vector<vector<TString>> rootFlatTreeMCThrownPhase1;

    // open flat trees
    for (auto polstrs: polString) {
        vector<TString> rootFlatTreeSignalTemp;
        vector<TString> rootFlatTreeBkgndTemp;
        vector<TString> rootFlatTreeReconTemp;
        vector<TString> rootFlatTreeMCReconTemp;
        vector<TString> rootFlatTreeMCThrownTemp;
        vector<TString> rootFlatTreeReconPhase1Temp;
        vector<TString> rootFlatTreeMCReconPhase1Temp;
        vector<TString> rootFlatTreeMCThrownPhase1Temp;
       
        for (auto tbinstrs: tBinString) {
            TString dirTemp = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+extraTag+"/";
            rootFlatTreeSignalTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_D"+dataTag+"_selected_"+extraTag+"_data_flat.root");
            rootFlatTreeBkgndTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_D"+dataTag+"_selected_"+extraTag+"_bkgnd_flat.root");
            rootFlatTreeReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_D"+dataTag+"_selected_"+extraTag+"_acc_flat.root");
            rootFlatTreeMCReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_F"+dataTag+"_selected_"+extraTag+"_acc_flat.root");
            rootFlatTreeMCThrownTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_F"+dataTag+"_gen_data_flat.root");
            TString dirTempPhase1 = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_"+extraTagPhase1+"/";
            rootFlatTreeReconPhase1Temp.push_back(dirTempPhase1+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_selected_"+extraTagPhase1+"_acc_flat.root");
            rootFlatTreeMCReconPhase1Temp.push_back(dirTempPhase1+polstrs+"_t"+tbinstrs+"_"+mBinString+"_F"+dataTagPhase1+"_selected_"+extraTagPhase1+"_acc_flat.root");
            rootFlatTreeMCThrownPhase1Temp.push_back(dirTempPhase1+polstrs+"_t"+tbinstrs+"_"+mBinString+"_F"+dataTagPhase1+"_gen_data_flat.root");
        }
        rootFlatTreeSignal.push_back(rootFlatTreeSignalTemp);
        rootFlatTreeBkgnd.push_back(rootFlatTreeBkgndTemp);
        rootFlatTreeRecon.push_back(rootFlatTreeReconTemp);
        rootFlatTreeMCRecon.push_back(rootFlatTreeMCReconTemp);
        rootFlatTreeMCThrown.push_back(rootFlatTreeMCThrownTemp);
        rootFlatTreeReconPhase1.push_back(rootFlatTreeReconPhase1Temp);
        rootFlatTreeMCReconPhase1.push_back(rootFlatTreeMCReconPhase1Temp);
        rootFlatTreeMCThrownPhase1.push_back(rootFlatTreeMCThrownPhase1Temp);
    }
    // open flat trees
    TFile *fFlatTreeSignal[NPol][NTBin];
    TFile *fFlatTreeBkgnd[NPol][NTBin];
    TFile *fFlatTreeRecon[NPol][NTBin];
    TFile *fFlatTreeMCRecon[NPol][NTBin];
    TFile *fFlatTreeMCThrown[NPol][NTBin];
    TFile *fFlatTreeReconPhase1[NPol][NTBin];
    TFile *fFlatTreeMCReconPhase1[NPol][NTBin];
    TFile *fFlatTreeMCThrownPhase1[NPol][NTBin];
    cout << endl << endl << "Opening flat trees:" << endl;
    for (Int_t iPol=0;iPol<NPol;iPol++){
        cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            // cout << rootFlatTreeSignal[iPol][iTBin] << endl;
            // fFlatTreeSignal[iPol][iTBin] = TFile::Open(rootFlatTreeSignal[iPol][iTBin], "READ");
            // cout << rootFlatTreeBkgnd[iPol][iTBin] << endl;
            // fFlatTreeBkgnd[iPol][iTBin] = TFile::Open(rootFlatTreeBkgnd[iPol][iTBin], "READ");
            cout << rootFlatTreeRecon[iPol][iTBin] << endl;
            fFlatTreeRecon[iPol][iTBin] = TFile::Open(rootFlatTreeRecon[iPol][iTBin], "READ");
            cout << rootFlatTreeMCRecon[iPol][iTBin] << endl;
            fFlatTreeMCRecon[iPol][iTBin] = TFile::Open(rootFlatTreeMCRecon[iPol][iTBin], "READ");
            cout << rootFlatTreeMCThrown[iPol][iTBin] << endl;
            fFlatTreeMCThrown[iPol][iTBin] = TFile::Open(rootFlatTreeMCThrown[iPol][iTBin], "READ");
            cout << rootFlatTreeReconPhase1[iPol][iTBin] << endl;
            fFlatTreeReconPhase1[iPol][iTBin] = TFile::Open(rootFlatTreeReconPhase1[iPol][iTBin], "READ");
            cout << rootFlatTreeMCReconPhase1[iPol][iTBin] << endl;
            fFlatTreeMCReconPhase1[iPol][iTBin] = TFile::Open(rootFlatTreeMCReconPhase1[iPol][iTBin], "READ");
            cout << rootFlatTreeMCThrownPhase1[iPol][iTBin] << endl;
            fFlatTreeMCThrownPhase1[iPol][iTBin] = TFile::Open(rootFlatTreeMCThrownPhase1[iPol][iTBin], "READ");
        }
    }

    TCanvas *c_Mpi0Eta = new TCanvas("c_Mpi0Eta", "c_Mpi0Eta",1600,600);
    c_Mpi0Eta->Divide(5,2,0.0,0.0);
    TCanvas *c_mismatchMass = new TCanvas("c_mismatchMass", "c_mismatchMass",1200,600);
    c_mismatchMass->Divide(2,1);
    const Int_t NPlotSplitPol = 3;
    TCanvas *c_pol[NPlotSplitPol];
    for (Int_t i=0;i<NPlotSplitPol;i++) {
        c_pol[i] = new TCanvas(Form("c_pol_%d",i),Form("c_pol_%d",i),1600,1200);
        c_pol[i]->Divide(2,2);
    }

    TLatex *lLatex = new TLatex();
    lLatex->SetTextSize(0.06);
    lLatex->SetTextAlign(22);

    TLegend *leg = new TLegend(0.2,0.8,0.4,0.95);

    TH1F *h1_Mpi0eta_sum;
    TH1F *h1_Mpi0eta_phase1Sum;
    Hist2DManager *h2ManagerM13M24 = new Hist2DManager();
    Hist2DManager *h2ManagerM23M14 = new Hist2DManager();
    Hist2DManager *h2ManagerMEtaMPi0 = new Hist2DManager();

    Double_t Mpi0eta_max = 0.0;
    Double_t Mpi0eta_max_corr = 0.0;
    TLegend *leg2 = new TLegend(0.20,0.65,0.85,0.85);
    for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
        leg2->Clear();
        // manager for histograms for polarization sum
        Hist1DManager *h1ManagerMpieta = new Hist1DManager();
        Hist1DManager *h1ManagerCosThetaGJ = new Hist1DManager();
        Hist2DManager *h2ManagerMpi0etaPol = new Hist2DManager();
        Hist1DManager *h1ManagerMpietaMCRecon = new Hist1DManager();
        Hist1DManager *h1ManagerMpietaMCThrown = new Hist1DManager();

        // Phase1
        Hist1DManager *h1ManagerMpietaPhase1 = new Hist1DManager();
        Hist1DManager *h1ManagerCosThetaGJPhase1 = new Hist1DManager();
        Hist2DManager *h2ManagerMpietaPolPhase1 = new Hist2DManager();
        Hist1DManager *h1ManagerMpietaMCReconPhase1 = new Hist1DManager();
        Hist1DManager *h1ManagerMpietaMCThrownPhase1 = new Hist1DManager();

        cout << endl << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
        for (Int_t iPol=0;iPol<NPol;iPol++){
            cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
            // get trees
            // TTree *tFlatTreeSignal = (TTree*)fFlatTreeSignal[iPol][iTBin]->Get("kin");
            // TTree *tFlatTreeBkgnd = (TTree*)fFlatTreeBkgnd[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeRecon = (TTree*)fFlatTreeRecon[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCRecon = (TTree*)fFlatTreeMCRecon[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCThrown = (TTree*)fFlatTreeMCThrown[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeReconPhase1 = (TTree*)fFlatTreeReconPhase1[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCReconPhase1 = (TTree*)fFlatTreeMCReconPhase1[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCThrownPhase1 = (TTree*)fFlatTreeMCThrownPhase1[iPol][iTBin]->Get("kin");

            // get branches
            // AssignSelectedBranches(tFlatTreeSignal, branchFlatTree, branchVar);
            // AssignSelectedBranches(tFlatTreeBkgnd, branchFlatTree, branchVar);
            AssignSelectedBranches(tFlatTreeRecon, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerRecon = new Hist1DManager();

            h1ManagerRecon->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->Add(Ebeam,"E_{beam} (GeV)",50,7.8,9.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->FillFromTree(tFlatTreeRecon);

            // h1ManagerRecon->Print(0,Form("HistManagerPlot_Mpi0Eta_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"P",1600,1600);
            // h1ManagerCosThetaGJ->Add(h1ManagerRecon->GetHist(1),h1ManagerRecon->GetBrVar(1),h1ManagerRecon->GetNBinsX(1),h1ManagerRecon->GetXMin(1),h1ManagerRecon->GetXMax(1));

            Hist2DManager *h2ManagerRecon = new Hist2DManager();
            h2ManagerRecon->Add(mismatchPairMass_13,mismatchPairMass_24,"m_{#gamma_{1}#gamma_{3}} (GeV)","m_{#gamma_{2}#gamma_{4}} (GeV)",50,0.0,1.0,50,0.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h2ManagerRecon->Add(mismatchPairMass_23,mismatchPairMass_14,"m_{#gamma_{2}#gamma_{3}} (GeV)","m_{#gamma_{1}#gamma_{4}} (GeV)",50,0.0,1.0,50,0.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h2ManagerRecon->Add(Mpi0,Meta,"M_{#pi^{0}} (GeV)","M_{#eta} (GeV)",50,0.09,0.18,50,0.4,0.7,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h2ManagerRecon->FillFromTree(tFlatTreeRecon);

            h2ManagerM13M24->Add(h2ManagerRecon->GetHist(0),h2ManagerRecon->GetBrVarX(0),h2ManagerRecon->GetBrVarY(0),h2ManagerRecon->GetNBinsX(0),h2ManagerRecon->GetXMin(0),h2ManagerRecon->GetXMax(0),h2ManagerRecon->GetNBinsY(0),h2ManagerRecon->GetYMin(0),h2ManagerRecon->GetYMax(0));
            h2ManagerM23M14->Add(h2ManagerRecon->GetHist(1),h2ManagerRecon->GetBrVarX(1),h2ManagerRecon->GetBrVarY(1),h2ManagerRecon->GetNBinsX(1),h2ManagerRecon->GetXMin(1),h2ManagerRecon->GetXMax(1),h2ManagerRecon->GetNBinsY(1),h2ManagerRecon->GetYMin(1),h2ManagerRecon->GetYMax(1));
            h2ManagerMEtaMPi0->Add(h2ManagerRecon->GetHist(2),h2ManagerRecon->GetBrVarX(2),h2ManagerRecon->GetBrVarY(2),h2ManagerRecon->GetNBinsX(2),h2ManagerRecon->GetXMin(2),h2ManagerRecon->GetXMax(2),h2ManagerRecon->GetNBinsY(2),h2ManagerRecon->GetYMin(2),h2ManagerRecon->GetYMax(2));

            AssignSelectedBranches(tFlatTreeMCRecon, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerMCRecon = new Hist1DManager();
            h1ManagerMCRecon->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->Add(Ebeam,"E_{beam} (GeV)",50,7.8,9.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->FillFromTree(tFlatTreeMCRecon);

            AssignSelectedBranches(tFlatTreeMCThrown, branchFlatTreeThrown, branchVarThrown, NBranchFlatTreeThrown);
            Hist1DManager *h1ManagerMCThrown = new Hist1DManager();
            h1ManagerMCThrown->Add(Mpi0eta_thrown,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrown");
            h1ManagerMCThrown->Add(cosTheta_eta_gj_thrown,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrown");
            h1ManagerMCThrown->Add(Ebeam_thrown,"E_{beam} (GeV)",50,7.8,9.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrown");
            h1ManagerMCThrown->FillFromTree(tFlatTreeMCThrown);

            c_pol[0]->cd(iPol+1);
            h1ManagerRecon->GetHist(0)->SetTitle(Form("%s, %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            h1ManagerRecon->GetHist(0)->Draw("HIST");
            h1ManagerMCRecon->GetHist(0)->SetLineColor(kRed);
            h1ManagerMCRecon->GetHist(0)->Draw("HIST SAME");
            h1ManagerMCThrown->GetHist(0)->SetLineColor(kGreen);
            h1ManagerMCThrown->GetHist(0)->SetFillStyle(0);
            h1ManagerMCThrown->GetHist(0)->Draw("HIST SAME");
            h1ManagerRecon->GetHist(0)->GetYaxis()->SetRangeUser(0,h1ManagerMCThrown->GetHist(0)->GetMaximum()*1.2);
            lLatex->DrawLatexNDC(0.75,0.9,Form("%s, t = %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            leg->AddEntry(h1ManagerRecon->GetHist(0),"GlueX 2020","l");
            leg->AddEntry(h1ManagerMCRecon->GetHist(0),"MC Recon","l");
            leg->AddEntry(h1ManagerMCThrown->GetHist(0),"MC Thrown","l");
            leg->Draw();

            c_pol[1]->cd(iPol+1);
            h1ManagerRecon->GetHist(1)->SetTitle(Form("%s, %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            h1ManagerRecon->GetHist(1)->Draw("HIST");
            h1ManagerMCRecon->GetHist(1)->SetLineColor(kRed);
            h1ManagerMCRecon->GetHist(1)->Draw("HIST SAME");
            h1ManagerMCThrown->GetHist(1)->SetLineColor(kGreen);
            h1ManagerMCThrown->GetHist(1)->SetFillStyle(0);
            h1ManagerMCThrown->GetHist(1)->Draw("HIST SAME");
            h1ManagerRecon->GetHist(1)->GetYaxis()->SetRangeUser(0,h1ManagerMCThrown->GetHist(1)->GetMaximum()*1.2);
            lLatex->DrawLatexNDC(0.75,0.9,Form("%s, t = %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            leg->Clear();
            leg->AddEntry(h1ManagerRecon->GetHist(1),"GlueX 2020","l");
            leg->AddEntry(h1ManagerMCRecon->GetHist(1),"MC Recon","l");
            leg->AddEntry(h1ManagerMCThrown->GetHist(1),"MC Thrown","l");
            leg->Draw();

            c_pol[2]->cd(iPol+1);
            h1ManagerRecon->GetHist(2)->SetTitle(Form("%s, %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            h1ManagerRecon->GetHist(2)->Draw("HIST");
            h1ManagerMCRecon->GetHist(2)->SetLineColor(kRed);
            h1ManagerMCRecon->GetHist(2)->Draw("HIST SAME");
            h1ManagerMCThrown->GetHist(2)->SetLineColor(kGreen);
            h1ManagerMCThrown->GetHist(2)->SetFillStyle(0);
            h1ManagerMCThrown->GetHist(2)->Draw("HIST SAME");
            h1ManagerRecon->GetHist(2)->GetYaxis()->SetRangeUser(0,h1ManagerMCThrown->GetHist(2)->GetMaximum()*1.2);
            lLatex->DrawLatexNDC(0.75,0.9,Form("%s, t = %s",polString[iPol].Data(),tBinString[iTBin].Data()));
            leg->Clear();
            leg->AddEntry(h1ManagerRecon->GetHist(2),"GlueX 2020","l");
            leg->AddEntry(h1ManagerMCRecon->GetHist(2),"MC Recon","l");
            leg->AddEntry(h1ManagerMCThrown->GetHist(2),"MC Thrown","l");
            leg->Draw();

            h1ManagerMpieta->Add(h1ManagerRecon->GetHist(0),h1ManagerRecon->GetBrVar(0),h1ManagerRecon->GetNBinsX(0),h1ManagerRecon->GetXMin(0),h1ManagerRecon->GetXMax(0));
            h1ManagerMpietaMCRecon->Add(h1ManagerMCRecon->GetHist(0),h1ManagerMCRecon->GetBrVar(0),h1ManagerMCRecon->GetNBinsX(0),h1ManagerMCRecon->GetXMin(0),h1ManagerMCRecon->GetXMax(0));
            h1ManagerMpietaMCThrown->Add(h1ManagerMCThrown->GetHist(0),h1ManagerMCThrown->GetBrVarThrown(0),h1ManagerMCThrown->GetNBinsX(0),h1ManagerMCThrown->GetXMin(0),h1ManagerMCThrown->GetXMax(0));

            AssignSelectedBranches(tFlatTreeReconPhase1, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerReconPhase1 = new Hist1DManager();
            h1ManagerReconPhase1->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_ReconPhase1");
            h1ManagerReconPhase1->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_ReconPhase1");
            h1ManagerReconPhase1->FillFromTree(tFlatTreeReconPhase1);
            h1ManagerMpietaPhase1->Add(h1ManagerReconPhase1->GetHist(0),h1ManagerReconPhase1->GetBrVar(0),h1ManagerReconPhase1->GetNBinsX(0),h1ManagerReconPhase1->GetXMin(0),h1ManagerReconPhase1->GetXMax(0));

            AssignSelectedBranches(tFlatTreeMCReconPhase1, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerMCReconPhase1 = new Hist1DManager();
            h1ManagerMCReconPhase1->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCReconPhase1");
            h1ManagerMCReconPhase1->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCReconPhase1");
            h1ManagerMCReconPhase1->FillFromTree(tFlatTreeMCReconPhase1);
            h1ManagerMpietaMCReconPhase1->Add(h1ManagerMCReconPhase1->GetHist(0),h1ManagerMCReconPhase1->GetBrVar(0),h1ManagerMCReconPhase1->GetNBinsX(0),h1ManagerMCReconPhase1->GetXMin(0),h1ManagerMCReconPhase1->GetXMax(0));

            AssignSelectedBranches(tFlatTreeMCThrownPhase1, branchFlatTreeThrown, branchVarThrown, NBranchFlatTreeThrown);
            Hist1DManager *h1ManagerMCThrownPhase1 = new Hist1DManager();
            h1ManagerMCThrownPhase1->Add(Mpi0eta_thrown,"M_{#eta#pi^{0}} (GeV)",34,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrownPhase1");
            h1ManagerMCThrownPhase1->Add(cosTheta_eta_gj_thrown,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrownPhase1");
            h1ManagerMCThrownPhase1->FillFromTree(tFlatTreeMCThrownPhase1);
            h1ManagerMpietaMCThrownPhase1->Add(h1ManagerMCThrownPhase1->GetHist(0),h1ManagerMCThrownPhase1->GetBrVarThrown(0),h1ManagerMCThrownPhase1->GetNBinsX(0),h1ManagerMCThrownPhase1->GetXMin(0),h1ManagerMCThrownPhase1->GetXMax(0));


            // h1ManagerRecon->Print(0,Form("HistManagerPlot_Mpi0Eta_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"P",1600,1600);
            // h1ManagerMCRecon->GetHist(0)->SetLineColor(kRed);
            // h1ManagerMCRecon->GetHist(0)->Draw("HIST SAME");

            // c_pol[1]->cd(iPol+1);
            // h1ManagerRecon->GetHist(1)->Draw("HIST");
            // h1ManagerMCRecon->GetHist(1)->SetLineColor(kRed);
            // h1ManagerMCRecon->GetHist(1)->Draw("HIST SAME");


            // AssignSelectedBranches(tFlatTreeMCRecon, branchFlatTree, branchVar);
            // AssignSelectedBranches(tFlatTreeMCThrown, branchFlatTree, branchVar);
            // AssignSelectedBranches(tFlatTreeReconPhase1, branchFlatTree, branchVar);

            // define histograms
            // h1_Mpi0eta_sig[iPol][iTBin] = new TH1F(Form("h1_Mpi0eta_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,1.
        }
        c_pol[0]->SaveAs(Form("%s/plot_Mpi0Eta_Recon_SplitPol_%s_%s_%s.pdf",outDir.Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));
        c_pol[1]->SaveAs(Form("%s/plot_cosThetaGJ_Recon_SplitPol_%s_%s_%s.pdf",outDir.Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));
        c_pol[2]->SaveAs(Form("%s/plot_Ebeam_Recon_SplitPol_%s_%s_%s.pdf",outDir.Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));
        // if (iTBin==0) {
        //     h1_Mpi0eta_sum =  (TH1F*)h1ManagerMpieta->GetHistSum()->Clone();
        //     h1_Mpi0eta_phase1Sum = (TH1F*)h1ManagerMpietaPhase1->GetHistSum()->Clone();    
        // }
        // else {
        //     h1_Mpi0eta_sum->Add(h1ManagerMpieta->GetHistSum());
        //     h1_Mpi0eta_phase1Sum->Add(h1ManagerMpietaPhase1->GetHistSum());
        // }
        c_Mpi0Eta->cd(iTBin+1);
        if (iTBin==0) Mpi0eta_max = h1ManagerMpieta->GetHistSum()->GetMaximum();
        TH1F *h1temp = (TH1F*)h1ManagerMpieta->GetHistSum()->Clone();
        TH1F *h1Phase1temp = (TH1F*)h1ManagerMpietaPhase1->GetHistSum()->Clone();
        h1temp->GetYaxis()->SetRangeUser(0,Mpi0eta_max*1.2);
        h1temp->GetYaxis()->SetTitleOffset(1.2);
        h1temp->GetXaxis()->SetTitleSize(0.08);
        h1temp->GetXaxis()->SetTitleOffset(1.2);
        h1temp->GetXaxis()->SetLabelSize(0.06);
        h1temp->GetYaxis()->SetTitleSize(0.08);
        h1temp->GetYaxis()->SetLabelSize(0.06);

        h1temp->Draw("HIST");
        
        h1Phase1temp->SetLineColor(kRed);
        h1Phase1temp->DrawCopy("HIST SAME");

        TH1F *h1Acceptance = (TH1F*)h1ManagerMpietaMCRecon->GetHistSum()->Clone();
        h1Acceptance->Divide(h1ManagerMpietaMCThrown->GetHistSum());
        h1Acceptance->SetLineColor(kBlack);
        h1Acceptance->SetLineStyle(2);
        h1Acceptance->SetLineWidth(1);

        // scale h1acceptance to match h1temp and draw right axis for h1acceptance

        Double_t rightMax = 0.55;
        h1Acceptance->Scale(Mpi0eta_max*1.2/rightMax);
        h1Acceptance->GetYaxis()->SetRangeUser(0,Mpi0eta_max*1.2);
        h1Acceptance->GetYaxis()->SetTitleOffset(1.2);
        h1Acceptance->GetYaxis()->SetTitle("Acceptance");
        h1Acceptance->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");

        TH1F *h1AcceptancePhase1 = (TH1F*)h1ManagerMpietaMCReconPhase1->GetHistSum()->Clone();
        h1AcceptancePhase1->Divide(h1ManagerMpietaMCThrownPhase1->GetHistSum());
        h1AcceptancePhase1->SetLineColor(kRed);
        h1AcceptancePhase1->SetLineStyle(2);
        h1AcceptancePhase1->SetLineWidth(1);
        h1AcceptancePhase1->Scale(Mpi0eta_max*1.2/rightMax);
        
        // h1Acceptance->GetXaxis()->SetTitleSize(0.05);
        // h1Acceptance->GetXaxis()->SetTitleOffset(1.2);
        // h1Acceptance->GetXaxis()->SetLabelSize(0.04);
        // h1Acceptance->GetYaxis()->SetTitleSize(0.05);
        // h1Acceptance->GetYaxis()->SetLabelSize(0.04);
        // h1Acceptance->GetYaxis()->SetLabelFont(42);
        // h1Acceptance->GetYaxis()->SetTitleFont(42);
        // h1Acceptance->GetYaxis()->SetNdivisions(505);
        h1Acceptance->Smooth();
        h1Acceptance->DrawCopy("L HIST SAME");
        h1AcceptancePhase1->Smooth();
        h1AcceptancePhase1->DrawCopy("L HIST SAME");

        // draw right axis for h1acceptance
        TGaxis *axis = new TGaxis(1.72,-100,1.72,Mpi0eta_max*1.2,0,rightMax,510,"+L");
        axis->SetLineColor(kBlack);
        axis->SetLabelColor(kBlack);
        axis->SetLabelSize(0.06);
        axis->SetLabelOffset(0.01);
        axis->SetTitle("#epsilon (%)");
        axis->SetTitleSize(0.08);
        axis->SetTitleOffset(0.8);
        axis->Draw();

        if (iTBin==NTBin-1) {
            h1temp->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
            leg2->AddEntry(h1Phase1temp,"GlueX-I","l");
            leg2->AddEntry(h1temp,"GlueX-II","l");
            leg2->SetBorderSize(0);
            leg2->SetTextSize(0.08);
            leg2->Draw();
            gPad->SetRightMargin(0.15);
            gPad->Update();
        }
        else {
            h1temp->GetXaxis()->SetTitle("");
        }
        if (iTBin!=0) {
                if (iTBin==4) lLatex->DrawLatexNDC(0.45,0.95,Form("%0.3f < -t < %0.3f",tMin[iTBin],tMax[iTBin]));
                else lLatex->DrawLatexNDC(0.5,0.95,Form("%0.3f < -t < %0.3f",tMin[iTBin],tMax[iTBin]));
            }
        else lLatex->DrawLatexNDC(0.6,0.95,Form("%0.3f < -t < %0.3f",tMin[iTBin],tMax[iTBin]));

        c_Mpi0Eta->cd(iTBin+1+NTBin);
        TH1F *h1Corr = (TH1F*)h1temp->Clone();
        h1Corr->Divide(h1Corr,h1Acceptance,1.0,lum);
        
        if (iTBin==0) {
            Mpi0eta_max_corr = h1Corr->GetMaximum();
            h1Corr->GetYaxis()->SetTitle("Events / (0.02 GeV #times #epsilon #times #it{L} pb^{-1})");
            h1Corr->GetYaxis()->SetTitleOffset(1.5);
            h1Corr->GetYaxis()->SetTitleSize(0.06);
            h1Corr->GetYaxis()->SetLabelSize(0.05);
        }
        h1Corr->GetYaxis()->SetRangeUser(0,Mpi0eta_max_corr*1.2);
        h1Corr->GetXaxis()->SetLabelSize(0.06);
        h1Corr->Draw("HIST");

        TH1F *h1Phase1Corr = (TH1F*)h1Phase1temp->Clone();
        h1Phase1Corr->Divide(h1Phase1Corr,h1AcceptancePhase1,1.0,lumPhase1);
        h1Phase1Corr->SetLineColor(kRed);
        h1Phase1Corr->Draw("HIST SAME");

        if (iTBin==NTBin-1) {
            h1Corr->GetXaxis()->SetTitleSize(0.08);
            h1Corr->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
            // leg2->Draw();
            gPad->SetRightMargin(0.15);
            gPad->Update();
        }
        else {
            h1Corr->GetXaxis()->SetTitle("");
        }

    }
    
    // c_Mpi0Eta->cd();
    // h1_Mpi0eta_sum->Draw("HIST");
    // h1_Mpi0eta_phase1Sum->SetLineColor(kRed);
    // h1_Mpi0eta_phase1Sum->Draw("HIST SAME");
    // c_Mpi0Eta->SaveAs(Form("%s/plot_Mpi0Eta_Recon_SumT_%s_%s_%s.pdf",outDir.Data(),mBinString.Data(),dataTag.Data(),extraTag.Data()));
    c_Mpi0Eta->SaveAs(Form("%s/plot_Mpi0Eta_Recon_SumPol_%s_%s_%s_%s_%s.pdf",outDir.Data(),mBinString.Data(),dataTagPhase1.Data(),extraTagPhase1.Data(),dataTag.Data(),extraTag.Data()));
    
    cout << "Number of histogram in h2ManagerMEtaMPi0: " << h2ManagerMEtaMPi0->GetSize() << endl;
    for (Int_t iHist=0;iHist<h2ManagerMEtaMPi0->GetSize();iHist++) {
        cout << "iHist = " << iHist << endl;
        cout << "h2ManagerMEtaMPi0->GetHist(iHist)->GetName() = " << h2ManagerMEtaMPi0->GetHist(iHist)->GetName() << endl;
        cout << "h2ManagerMEtaMPi0->GetHist(iHist)->GetEntries() = " << h2ManagerMEtaMPi0->GetHist(iHist)->GetEntries() << endl;
    }
    cout << "Total entries in h2ManagerMEtaMPi0: " << h2ManagerMEtaMPi0->GetHistSum()->GetEntries() << endl;

    c_Mpi0Eta->Clear();
    c_Mpi0Eta->Divide(1,1);
    c_Mpi0Eta->SetWindowSize(400,800);
    c_Mpi0Eta->cd(1);
    TH2F *h2MEtaMpi0Draw = (TH2F*)h2ManagerMEtaMPi0->GetHistSum()->Clone();
    //set up the color z axis palette size and offset
    h2MEtaMpi0Draw->Draw("COLZ");

    c_Mpi0Eta->SaveAs(Form("%s/plot_Mpi0Eta_Recon_MEtaMPi0_%s_%s_%s.pdf",outDir.Data(),mBinString.Data(),dataTag.Data(),extraTag.Data()));

    // cout << "Number of histogram in h2ManagerM13M24: " << h2ManagerM13M24->GetSize() << endl;
    // for (Int_t iHist=0;iHist<h2ManagerM13M24->GetSize();iHist++) {
    //     cout << "iHist = " << iHist << endl;
    //     cout << "h2ManagerM13M24->GetHist(iHist)->GetName() = " << h2ManagerM13M24->GetHist(iHist)->GetName() << endl;
    //     cout << "h2ManagerM13M24->GetHist(iHist)->GetEntries() = " << h2ManagerM13M24->GetHist(iHist)->GetEntries() << endl;
    // }
    // cout << "Number of histogram in h2ManagerM23M14: " << h2ManagerM23M14->GetSize() << endl;
    // for (Int_t iHist=0;iHist<h2ManagerM23M14->GetSize();iHist++) {
    //     cout << "iHist = " << iHist << endl;
    //     cout << "h2ManagerM23M14->GetHist(iHist)->GetName() = " << h2ManagerM23M14->GetHist(iHist)->GetName() << endl;
    //     cout << "h2ManagerM23M14->GetHist(iHist)->GetEntries() = " << h2ManagerM23M14->GetHist(iHist)->GetEntries() << endl;
    // }

    // c_mismatchMass->cd(1);
    // h2ManagerM13M24->GetHistSum()->Draw("COLZ");
    // c_mismatchMass->cd(2);
    // h2ManagerM23M14->GetHistSum()->Draw("COLZ");

    // c_mismatchMass->SaveAs(Form("%s/plot_mismatchMass_Recon_%s_%s_%s.pdf",outDir.Data(),mBinString.Data(),dataTag.Data(),extraTag.Data()));
}

void AssignSelectedBranches(TTree *tTree,const TString branchName[],Float_t branchVar[],Int_t NBrFlatTree){
    tTree->SetBranchStatus("*",0);
    for (Int_t iBranch=0;iBranch<NBrFlatTree;iBranch++) {
        tTree->SetBranchStatus(branchName[iBranch],1);
        tTree->SetBranchAddress(branchName[iBranch],&branchVar[iBranch]);
    }
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
    // TString cmdCheckNan = "grep -i nan " + fitName;
    // cout << "Running command: " << cmdCheckNan << endl;
    // gSystem->Exec(cmdCheckNan);

    // if there is replace nan with zeros
    // TString cmdReplaceNan = "sed -i 's/nan/0.1/g' " + fitName;
    // cout << "Running command: " << cmdReplaceNan << endl;
    // gSystem->Exec(cmdReplaceNan);

    // run etapi_plotter
    TString cmd = "etapi_plotter " + fitName + " -o " + outName + " -s " + ampString + " -a " + isAccCorrString + " -F " + ampFitFracString + " -var " + isPlotAllVarString + " -gen " + isPlotGenHistString;
    cout << "Running command: " << cmd << endl;
    gSystem->Exec(cmd);
}

vector<Double_t> GetAccCorrYield(TString fileName){

    ifstream log(fileName.Data());
    TString line;

    list<TString> lines;
    while (log >> line) lines.push_back(line);
    Int_t totalEvents;
    Float_t totalEventsErr;
    Float_t fitFrac;
    Float_t fitFracErr;

    for (auto pline = lines.cbegin(); pline != lines.cend(); ++pline) {
        if (pline->EqualTo("EVENTS")) {
            // cout << "Found " << strTotalEvent << " in the file" << endl;
            TString tempStr = *(++(++pline));
            totalEvents = tempStr.Atoi();
            TString tempStrErr = *((++(++pline)));
            totalEventsErr = tempStrErr.Atof();
            // cout << tempStrErr << endl;
            break;
        }
    }
    // for (Int_t i=0;i<totalEvents.size();i++) cout << totalEvents[i] << endl;

    for (auto pline = lines.cbegin(); pline != lines.cend(); ++pline) {
        if (pline->EqualTo("D")) {
            cout << "Found " << "D" << " in the file" << endl;
            TString tempStr = *(++(++pline));
            fitFrac = tempStr.Atof();
            TString tempStrErr = *(++(++pline));
            fitFracErr = tempStrErr.Atof();
            break;
        }
    }
    // for (Int_t i=0;i<fitFrac.size();i++) cout << fitFrac[i] << endl;
    Double_t accCorrYield = totalEvents*fitFrac;
    Double_t accCorrYieldErr = accCorrYield*TMath::Sqrt((fitFracErr/fitFrac)*(fitFracErr/fitFrac) + (totalEventsErr/totalEvents)*(totalEventsErr/totalEvents));
    // Double_t accCorrYieldErr = TMath::Sqrt(fitFracErr*fitFracErr*totalEvents*totalEvents+totalEventsErr*totalEventsErr*fitFrac*fitFrac);

    cout << endl << "Reading values from " << fileName << endl;
    cout << "Total events: " << totalEvents << " +- " << totalEventsErr << endl;
    cout << "Fit fraction of D: " << fitFrac << " +- " << fitFracErr << endl;
    cout << "Acc. corr. yield: " << totalEvents*fitFrac << " +- " << accCorrYieldErr << endl;
    vector<Double_t> vAccCorrYield = {accCorrYield,accCorrYieldErr};
    return vAccCorrYield;
}

void FillHistogram2D(TTree* tTree, vector<TH2F*> vh2, vector<brVar> vbVarX, vector<brVar> vbVarY){
    for (Int_t iEvent=0;iEvent<tTree->GetEntries();iEvent++){
        tTree->GetEntry(iEvent);
        for (Int_t iH2=0;iH2<vh2.size();iH2++) {
            vh2[iH2]->Fill(branchVar[vbVarX[iH2]],branchVar[vbVarY[iH2]],branchVar[Weight]);
        }
    }
}

vector<vector<Double_t>> ReadCSV(TString fileName, Bool_t isPrint){
    vector<vector<Double_t>> vData;
    ifstream file(fileName.Data());
    string line;
    while (getline(file, line)) {
        vector<Double_t> vLine;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ' ')) {
            // cout << cell << endl;
            vLine.push_back(stod(cell));
        }
        vData.push_back(vLine);
    }

    if (isPrint) {
        for (Int_t i=0;i<vData.size();i++) {
            for (Int_t j=0;j<vData[i].size();j++) {
                cout << vData[i][j] << " ";
            }
            cout << endl;
        }
    }

    return vData;
}

vector<Double_t> ReadFitsForBootstrap(Int_t NSample, Bool_t isRunEtaPiPlotterBootstrap, Bool_t isReadFitFracWave){
    cout << endl << "Reading fits for bootstrap" << endl;
    vector<TString> vBootstrapDir;
    for (auto const t: tBinString){
        vBootstrapDir.push_back(Form("%st%s_%s/bootstrap_t%s/",bootstrapDir.Data(),t.Data(),extraTag.Data(),t.Data()));
        cout << Form("%st%s_%s/bootstrap_t%s/",bootstrapDir.Data(),t.Data(),extraTag.Data(),t.Data()) << endl;
    }

    vector<vector<TString>> vvFitBootstrapDir;
    for (Int_t iTBin=0;iTBin<vBootstrapDir.size();iTBin++){
        vector<TString> vFitBootstrapDir;
        for (Int_t iNSample=0;iNSample<NSample;iNSample++){
            vFitBootstrapDir.push_back(Form("%sbootstrap_%d/",vBootstrapDir[iTBin].Data(),iNSample));
        }
        vvFitBootstrapDir.push_back(vFitBootstrapDir);
    }

    TH1F *h1BootstrapAccCorrYieldT[5];
    TH1F *h1BootstrapAccCorrYieldRMST[5];
    if (isReadFitFracWave){
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            h1BootstrapAccCorrYieldT[iTBin] = new TH1F(Form("h1BootstrapAccCorrYieldT_%s",tBinString[iTBin].Data()),Form("Bootstrapped acc. corr. yield, t = %s",tBinString[iTBin].Data()),40,A2AccCorrYieldCenter[iTBin]-0.7*A2AccCorrYieldCenter[iTBin],A2AccCorrYieldCenter[iTBin]+1.3*A2AccCorrYieldCenter[iTBin]);
            h1BootstrapAccCorrYieldRMST[iTBin] = new TH1F(Form("h1BootstrapAccCorrYieldRMST_%s",tBinString[iTBin].Data()),Form("Bootstrapped acc. corr. yield RMS, t = %s",tBinString[iTBin].Data()),100,-0.5,100.5);
        }
    }
    TCanvas *c_a2AccCorrYield = new TCanvas("c_a2AccCorrYield","c_a2AccCorrYield",1200,800);
    c_a2AccCorrYield->Divide(3,2,0.00001,0.00001);
    TCanvas *c_a2AccCorrYieldRMS = new TCanvas("c_a2AccCorrYieldRMS","c_a2AccCorrYieldRMS",1200,800);
    c_a2AccCorrYieldRMS->Divide(3,2,0.00001,0.00001);
    TLatex *lLatex = new TLatex();
    vector<Double_t> vA2CSStatErrBootstrap;
    for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
        for (Int_t iNSample=0;iNSample<NSample;iNSample++){
            cout << "Reading " << vvFitBootstrapDir[iTBin][iNSample] << endl;
            if (isRunEtaPiPlotterBootstrap) {
                // run etapi_plotter
                cout << endl << endl << "Running etapi_plotter..." << endl;
                for (Int_t iStrWave=0;iStrWave<5;iStrWave++) {
                    for (Int_t iTBin=0;iTBin<NTBin;iTBin++) etaPiPlotter(vvFitBootstrapDir[iTBin][iNSample],"etapi_result.fit","etapi_plot",Form("'%s'",strWave[iStrWave].Data()),kTRUE,strFitFracWave,kFALSE,kTRUE);
                }
            }
            if (isReadFitFracWave) {
                // read fit fractions
                cout << endl << endl << "Reading fit fractions..." << endl;
                TString fileName = vvFitBootstrapDir[iTBin][iNSample] + etaPiPlotterOutLogName;
                cout << "Reading " << fileName << endl;
                vector<Double_t> vAccCorrYield = GetAccCorrYield(fileName);
                h1BootstrapAccCorrYieldT[iTBin]->Fill(vAccCorrYield[0]);
                h1BootstrapAccCorrYieldRMST[iTBin]->SetBinContent(iNSample+1,h1BootstrapAccCorrYieldT[iTBin]->GetRMS());
                if (iNSample==NSample-1) {
                    vA2CSStatErrBootstrap.push_back(h1BootstrapAccCorrYieldT[iTBin]->GetRMS());
                }
            }
        }
        c_a2AccCorrYield->cd(iTBin+1);
        h1BootstrapAccCorrYieldT[iTBin]->GetXaxis()->SetTitle("N_{a_{2(1320)}}/#epsilon");
        h1BootstrapAccCorrYieldT[iTBin]->GetYaxis()->SetTitle("Counts");
        h1BootstrapAccCorrYieldT[iTBin]->Draw();
        lLatex->SetTextSize(0.04);
        lLatex->DrawLatexNDC(0.65,0.9,Form("%0.3f<t<%0.3f",tMin[iTBin],tMax[iTBin]));
        // draw center line
        TLine *lCenter = new TLine(A2AccCorrYieldCenter[iTBin],0,A2AccCorrYieldCenter[iTBin],1.05*h1BootstrapAccCorrYieldT[iTBin]->GetMaximum());
        lCenter->SetLineColor(kRed);
        lCenter->SetLineStyle(2);
        lCenter->Draw();

        c_a2AccCorrYieldRMS->cd(iTBin+1);
        h1BootstrapAccCorrYieldRMST[iTBin]->GetXaxis()->SetTitle("Bootstrap sample");
        h1BootstrapAccCorrYieldRMST[iTBin]->GetYaxis()->SetTitle("#sigma (RMS)");
        h1BootstrapAccCorrYieldRMST[iTBin]->GetYaxis()->SetRangeUser(0,1.1*h1BootstrapAccCorrYieldRMST[iTBin]->GetMaximum());
        h1BootstrapAccCorrYieldRMST[iTBin]->GetYaxis()->SetTitleOffset(1.5);
        h1BootstrapAccCorrYieldRMST[iTBin]->Draw();
        lLatex->SetTextSize(0.04);
        lLatex->DrawLatexNDC(0.65,0.9,Form("%0.3f<t<%0.3f",tMin[iTBin],tMax[iTBin]));
    }
    c_a2AccCorrYield->SaveAs(Form("%s/plot_A2AccCorrYieldT_%s_%s.pdf",outDir.Data(),dataTag.Data(),extraTag.Data()));
    if (isReadFitFracWave) c_a2AccCorrYieldRMS->SaveAs(Form("%s/plot_A2AccCorrYieldRMS_%s_%s.pdf",outDir.Data(),dataTag.Data(),extraTag.Data()));
    return vA2CSStatErrBootstrap;
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
	// gluex_style->SetCanvasDefW(800);
	// gluex_style->SetCanvasDefH(600);

	// let's change the default margins
	gluex_style->SetPadBottomMargin(0.2);
	gluex_style->SetPadLeftMargin(0.2);
	gluex_style->SetPadTopMargin(0.05);
	gluex_style->SetPadRightMargin(0.1);

	// axis labels and settings
    gluex_style->SetStripDecimals(0);
 	gluex_style->SetLabelSize(0.04,"xyz"); // size of axis value font
 	gluex_style->SetTitleSize(0.06,"xyz"); // size of axis title font
 	gluex_style->SetTitleFont(42,"xyz"); // font option
 	gluex_style->SetLabelFont(42,"xyz"); 
 	gluex_style->SetTitleOffset(1.2,"y"); 
 	gluex_style->SetLabelOffset(0.01,"xyz");   // stop collisions of "0"s at the origin
 	
	// histogram settings
	gluex_style->SetOptStat(0);     // no stats box by default
	gluex_style->SetOptTitle(0);    // no title by default
	gluex_style->SetHistLineWidth(2); 
	gluex_style->SetNdivisions(508,"xyz"); // some ticks were very bunched, lets reduce the number of divisions to label 
	// gluex_style->SetOptFit(0111);

	// gluex_style->SetHistFillColor(920);   // grey
    gluex_style->SetFillStyle(0);
	// gluex_style->SetPalette(kRainBow); // kViridis is perceptually uniform and colorblind friendly
	gluex_style->cd();
}