// const TString mainDir = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/";
const TString mainDir = "/d/home/septian/EtaPi0Analysis/run/mass_dependent_fits/";
const TString dirRootFlatTree = "/d/home/septian/EtaPi0Analysis/run/rootFiles/";
const TString outDir = "/d/home/septian/EtaPi0Analysis/run/plots";
// TString rootHistFitResult = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/etapi_plot_D2++_pD2++.root";
// TString dirRootFlatTree = "/d/home/septian/EtaPi0Analysis/study_pwa/mass_dependent_fits/rootFiles/t010020_m104172_test/";
const Int_t NPol = 4;
const TString polString[NPol] = {"pol000", "pol045", "pol090", "pol135"};

const Int_t NTBin = 5;
const TString tBinString[NTBin] = {"010020","0200325","0325050","050075","075100"};
const Float_t tMin[NTBin] = {0.1,0.2,0.325,0.5,0.75};
const Float_t tMax[NTBin] = {0.2,0.325,0.5,0.75,1.0};

// const Int_t NTBin = 1;
// const TString tBinString[NTBin] = {"075100"};
// const Float_t tMin[NTBin] = {0.75};
// const Float_t tMax[NTBin] = {1.0};

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
const Int_t NBranchFlatTree = 9;
const TString branchFlatTree[NBranchFlatTree] = {"Ebeam","Mpi0eta","Mpi0p","vanHove_omega","vanHove_x","vanHove_y","pVH","cosTheta_eta_gj","Weight"};
enum brVar{Ebeam,Mpi0eta,Mpi0p,vanHove_omega,vanHove_x,vanHove_y,pVH,cosTheta_eta_gj,Weight};
Float_t branchVar[NBranchFlatTree] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};

const Int_t NBranchFlatTreeThrown = 3;
const TString branchFlatTreeThrown[NBranchFlatTreeThrown] = {"Ebeam_thrown","Mpi0eta_thrown","cosTheta_eta_gj_thrown"};
enum brVarThrown{Ebeam_thrown,Mpi0eta_thrown,cosTheta_eta_gj_thrown};
Float_t branchVarThrown[NBranchFlatTreeThrown] = {1.0,1.0,1.0};

const Bool_t isPlotFromFlatTrees = kFALSE;
const Bool_t isPlotVanHopeAngle = kFALSE;
const Bool_t isPlotMPi0Eta = kFALSE;

// user config for etapi_plotter
const Bool_t isRunEtaPiPlotter = kTRUE;
const Bool_t isPlotWaves = kTRUE;
const TString etaPiPlotterOutName = "etapi_plot";
const TString histBaseName[4] = {"EtaPi0_000_", "EtaPi0_045_", "EtaPi0_090_", "EtaPi0_135_"};
const TString dataAmpTools[4] = {"dat","bkg","acc","gen"};
const TString histMEtaPiAccName = "Metapi_40MeVBinacc";
const TString histMEtaPiSigName = "Metapi_40MeVBindat";
const TString histMetaPiBkgName = "Metapi_40MeVBinbkg";
const TString strWave = "D1--_D0+-_D1+-_D0++_D1++_D2++";
// const TString strWave = "S0+-_S0++_D1--_D0+-_D1+-_D0++_D1++_D2++_pD1--_pD0+-_pD1+-_pD0++_pD1++_pD2++";
const TString strFitFracWave = "D";

const Bool_t isPlotA2CS = kTRUE;
const TString etaPiPlotterOutLogName = "etapi_plotter_output.log";
const Double_t lum = 132.4; // pb^-1
const Bool_t isStudyGenMC = kFALSE;

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
Double_t GetAccCorrYield(TString fileName);
void FillHistogram2D(TTree *tTree, vector<TH2F*> vh2, vector<brVar> brVarX, vector<brVar> brVarY);


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
    TH1F *h1Sum = (TH1F*)vh1[0]->Clone();
    // check if all histograms have the same properties
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

void drawHist(){
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
    
    TCanvas *c1 = new TCanvas("c1", "c1",1200,1200);
    TCanvas *c2 = new TCanvas("c2", "c2",1600,800);
    TCanvas *c_Mpi0Eta = new TCanvas("c_Mpi0Eta", "c_Mpi0Eta",1600,1200);
    TCanvas *c_test = new TCanvas("c_test", "c_test",1600,1200);

    if (isPlotFromFlatTrees){
        PlotFromFlatTree();
        /*
        for (auto polstrs: polString) {
            vector<TString> rootFlatTreeSignalTemp;
            vector<TString> rootFlatTreeBkgndTemp;
            vector<TString> rootFlatTreeReconTemp;
            vector<TString> rootFlatTreeMCReconTemp;
            vector<TString> rootFlatTreeMCThrownTemp;

            vector<TString> rootFlatTreeReconPhase1Temp;

            for (auto tbinstrs: tBinString) {
                TString dirTemp = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+extraTag+"/";
                rootFlatTreeSignalTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_data_flat.root");
                rootFlatTreeBkgndTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_bkgnd_flat.root");
                rootFlatTreeReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_acc_flat.root");
                rootFlatTreeMCReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_F"+dataTag+"_selected_acc_flat.root");
                rootFlatTreeMCThrownTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_F"+dataTag+"_selected_gen_flat.root");

                TString dirTempPhase1 = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_"+extraTagPhase1+"/";
                rootFlatTreeReconPhase1Temp.push_back(dirTempPhase1+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_selected_"+extraTagPhase1+"_acc_flat.root");
            }
            rootFlatTreeSignal.push_back(rootFlatTreeSignalTemp);
            rootFlatTreeBkgnd.push_back(rootFlatTreeBkgndTemp);
            rootFlatTreeRecon.push_back(rootFlatTreeReconTemp);
            rootFlatTreeMCRecon.push_back(rootFlatTreeMCReconTemp);
            rootFlatTreeMCThrown.push_back(rootFlatTreeMCThrownTemp);
            rootFlatTreeReconPhase1.push_back(rootFlatTreeReconPhase1Temp);
        }

        // open flat trees
        TFile *fFlatTreeSignal[NPol][NTBin];
        TFile *fFlatTreeBkgnd[NPol][NTBin];
        TFile *fFlatTreeRecon[NPol][NTBin];
        TFile *fFlatTreeMCRecon[NPol][NTBin];
        TFile *fFlatTreeMCThrown[NPol][NTBin];

        TFile *fFlatTreeReconPhase1[NPol][NTBin];

        cout << endl << endl << "Opening flat trees:" << endl;
        for (Int_t iPol=0;iPol<NPol;iPol++){
            cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
            for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
                cout << rootFlatTreeSignal[iPol][iTBin] << endl;
                fFlatTreeSignal[iPol][iTBin] = TFile::Open(rootFlatTreeSignal[iPol][iTBin], "READ");
                cout << rootFlatTreeBkgnd[iPol][iTBin] << endl;
                fFlatTreeBkgnd[iPol][iTBin] = TFile::Open(rootFlatTreeBkgnd[iPol][iTBin], "READ");
                cout << rootFlatTreeRecon[iPol][iTBin] << endl;
                fFlatTreeRecon[iPol][iTBin] = TFile::Open(rootFlatTreeRecon[iPol][iTBin], "READ");
                cout << rootFlatTreeMCRecon[iPol][iTBin] << endl;
                fFlatTreeMCRecon[iPol][iTBin] = TFile::Open(rootFlatTreeMCRecon[iPol][iTBin], "READ");
                cout << rootFlatTreeMCThrown[iPol][iTBin] << endl;
                fFlatTreeMCThrown[iPol][iTBin] = TFile::Open(rootFlatTreeMCThrown[iPol][iTBin], "READ");
                cout << rootFlatTreeReconPhase1[iPol][iTBin] << endl;
                fFlatTreeReconPhase1[iPol][iTBin] = TFile::Open(rootFlatTreeReconPhase1[iPol][iTBin], "READ");
            }
        }

        // Declare histograms
        TH2F *h2_Mpi0Eta_VanHove_sig[NPol][NTBin];
        TH2F *h2_VanHove_XY_sig[NPol][NTBin];
        TH2F *h2_Mpi0Eta_VanHove_bkg[NPol][NTBin];
        TH2F *h2_VanHove_XY_bkg[NPol][NTBin];
        TH1F *h1_Mpi0p_sig[NPol][NTBin];
        TH1F *h1_Mpi0p_bkg[NPol][NTBin];
        TH1F *h1_Mpi0p_pVH_sig[NPol][NTBin];
        TH1F *h1_Mpi0p_pVH_bkg[NPol][NTBin];
        TH1F *h1_Mpi0eta_sig[NPol][NTBin];
        TH1F *h1_Mpi0eta_bkg[NPol][NTBin];

        TH2F *h2_Mpi0Eta_VanHove_sum[NTBin];
        TH2F *h2_VanHove_XY_sum[NTBin];
        TH1F *h1_Mpi0p_sum[NTBin];
        TH1F *h1_Mpi0p_pVH_sum[NTBin];
        TH1F *h1_Mpi0eta_sum[NTBin];

        TH2F *h2_Mpi0Eta_cosThetaGJ_Recon[NPol][NTBin];
        TH2F *h2_Mpi0Eta_cosThetaGJ_Recon_sum[NTBin];

        // Loop over signal flat tree
        cout << endl << endl << "Looping over signal tree:" << endl;
        c1->Clear();
        c1->Divide(3,2,0.0,0.0);
        c2->Divide(3,2,0.0,0.0);
        c_Mpi0Eta->Divide(3,2);
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            // manager for histograms for polarization sum
            Hist1DManager *h1ManagerMpieta = new Hist1DManager();
            Hist1DManager *h1ManagerCosThetaGJ = new Hist1DManager();
            Hist2DManager *h2ManagerMpi0etaPol = new Hist2DManager();

            Hist1DManager *h1ManagerMpietaPhase1 = new Hist1DManager();
            Hist1DManager *h1ManagerCosThetaGJPhase1 = new Hist1DManager();
            Hist2DManager *h2ManagerMpietaPolPhase1 = new Hist2DManager();

            cout << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
            for (Int_t iPol=0;iPol<NPol;iPol++){
                cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
                cout << rootFlatTreeSignal[iPol][iTBin] << endl;

                // TTree *tFlatTreeSignal = (TTree*)fFlatTreeSignal[iPol][iTBin]->Get("kin");
                // AssignSelectedBranches(tFlatTreeSignal, branchFlatTree, branchVar);

                // if (isPlotVanHopeAngle) {
                //     h2_Mpi0Eta_VanHove_sig[iPol][iTBin] = new TH2F(Form("h2_Mpi0Eta_VanHove_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} vs Van Hove angle (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,1.04,1.72,100,210,330);
                //     h2_VanHove_XY_sig[iPol][iTBin] = new TH2F(Form("h2_VanHove_XY_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("Van Hove X vs Y (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,-2.0,2.0,100,-2.0,2.0);
                //     h2_Mpi0Eta_VanHove_bkg[iPol][iTBin] = new TH2F(Form("h2_Mpi0Eta_VanHove_bkg_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} vs Van Hove angle (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,1.04,1.72,100,210,330);
                //     h2_VanHove_XY_bkg[iPol][iTBin] = new TH2F(Form("h2_VanHove_XY_bkg_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("Van Hove X vs Y (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,-2.0,2.0,100,-2.0,2.0);
                //     h1_Mpi0p_sig[iPol][iTBin] = new TH1F(Form("h1_Mpi0p_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{pi^{0}p} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),250,1.0,3.5);
                //     h1_Mpi0p_bkg[iPol][iTBin] = new TH1F(Form("h1_Mpi0p_bkg_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{pi^{0}p} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),250,1.0,3.5);
                //     h1_Mpi0p_pVH_sig[iPol][iTBin] = new TH1F(Form("h1_Mpi0p_pVH_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{pi^{0}p} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),250,1.0,3.5);
                //     h1_Mpi0p_pVH_bkg[iPol][iTBin] = new TH1F(Form("h1_Mpi0p_pVH_bkg_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{pi^{0}p} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),250,1.0,3.5);
                // }

                // if (isPlotMPi0Eta) {
                //     h1_Mpi0eta_sig[iPol][iTBin] = new TH1F(Form("h1_Mpi0Eta_sig_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),17,1.04,1.72);
                //     h1_Mpi0eta_bkg[iPol][iTBin] = new TH1F(Form("h1_Mpi0Eta_bkg_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),17,1.04,1.72);
                // }

                // for (Int_t iEvent=0;iEvent<tFlatTreeSignal->GetEntries();iEvent++){
                //     tFlatTreeSignal->GetEntry(iEvent);
                //     // cout << branchVar[Mpi0eta] << " " << branchVar[Weight] << endl;
                //     if (isPlotVanHopeAngle) {
                //         h2_Mpi0Eta_VanHove_sig[iPol][iTBin]->Fill(branchVar[Mpi0eta],branchVar[vanHove_omega],branchVar[Weight]);
                //         h2_VanHove_XY_sig[iPol][iTBin]->Fill(branchVar[vanHove_x],branchVar[vanHove_y],branchVar[Weight]);
                //         h1_Mpi0p_sig[iPol][iTBin]->Fill(branchVar[Mpi0p],branchVar[Weight]);
                //         if ((Bool_t)branchVar[pVH]) h1_Mpi0p_pVH_sig[iPol][iTBin]->Fill(branchVar[Mpi0p],branchVar[Weight]);
                //     }
                //     if (isPlotMPi0Eta) h1_Mpi0eta_sig[iPol][iTBin]->Fill(branchVar[Mpi0eta],branchVar[Weight]);
                // }

                // TTree *tFlatTreeBkgnd = (TTree*)fFlatTreeBkgnd[iPol][iTBin]->Get("kin");
                // AssignSelectedBranches(tFlatTreeBkgnd, branchFlatTree, branchVar);

                // for (Int_t iEvent=0;iEvent<tFlatTreeBkgnd->GetEntries();iEvent++){
                //     tFlatTreeBkgnd->GetEntry(iEvent);
                //     if (isPlotVanHopeAngle) {
                //         h2_Mpi0Eta_VanHove_bkg[iPol][iTBin]->Fill(branchVar[Mpi0eta],branchVar[vanHove_omega],branchVar[Weight]);
                //         h2_VanHove_XY_bkg[iPol][iTBin]->Fill(branchVar[vanHove_x],branchVar[vanHove_y],branchVar[Weight]);
                //         h1_Mpi0p_bkg[iPol][iTBin]->Fill(branchVar[Mpi0p],branchVar[Weight]);
                //         if ((Bool_t)branchVar[pVH]) h1_Mpi0p_pVH_bkg[iPol][iTBin]->Fill(branchVar[Mpi0p],branchVar[Weight]);
                //     }
                //     if (isPlotMPi0Eta) h1_Mpi0eta_bkg[iPol][iTBin]->Fill(branchVar[Mpi0eta],branchVar[Weight]);
                // }
           
                // if (isPlotVanHopeAngle) {
                //     h2_Mpi0Eta_VanHove_sig[iPol][iTBin]->Add(h2_Mpi0Eta_VanHove_bkg[iPol][iTBin]);
                //     h2_VanHove_XY_sig[iPol][iTBin]->Add(h2_VanHove_XY_bkg[iPol][iTBin]);
                //     gSystem->cd(fitResultDir[iTBin]);
                //     // h2_Mpi0Eta_VanHove_sig[iPol][iTBin]->Draw("COLZ");
                //     // c1->SaveAs(Form("plot_Mpi0Eta_VanHove_sig_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));
                //     // h2_VanHove_XY_sig[iPol][iTBin]->Draw("COLZ");
                //     // c1->SaveAs(Form("plot_VanHove_XY_sig_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));
                //     if (!iPol) {
                //         h2_Mpi0Eta_VanHove_sum[iTBin] = (TH2F*)h2_Mpi0Eta_VanHove_sig[iPol][iTBin]->Clone();
                //         h2_VanHove_XY_sum[iTBin] = (TH2F*)h2_VanHove_XY_sig[iPol][iTBin]->Clone();
                //         h1_Mpi0p_sum[iTBin] = (TH1F*)h1_Mpi0p_sig[iPol][iTBin]->Clone();
                //         h1_Mpi0p_pVH_sum[iTBin] = (TH1F*)h1_Mpi0p_pVH_sig[iPol][iTBin]->Clone();
                //     }
                //     else {
                //         h2_Mpi0Eta_VanHove_sum[iTBin]->Add(h2_Mpi0Eta_VanHove_sig[iPol][iTBin]);
                //         h2_VanHove_XY_sum[iTBin]->Add(h2_VanHove_XY_sig[iPol][iTBin]);
                //         h1_Mpi0p_sum[iTBin]->Add(h1_Mpi0p_sig[iPol][iTBin]);
                //         h1_Mpi0p_pVH_sum[iTBin]->Add(h1_Mpi0p_pVH_sig[iPol][iTBin]);
                //     }
                // }

                // if (isPlotMPi0Eta) {
                //     h1_Mpi0eta_sig[iPol][iTBin]->Add(h1_Mpi0eta_bkg[iPol][iTBin]);
                //     gSystem->cd(fitResultDir[iTBin]);

                //     if (!iPol) h1_Mpi0eta_sum[iTBin] = (TH1F*)h1_Mpi0eta_sig[iPol][iTBin]->Clone();
                //     else h1_Mpi0eta_sum[iTBin]->Add(h1_Mpi0eta_sig[iPol][iTBin]);
                // }

                TTree *tFlatTreeRecon = (TTree*)fFlatTreeRecon[iPol][iTBin]->Get("kin");
                AssignSelectedBranches(tFlatTreeRecon, branchFlatTree, branchVar);
                // h2_Mpi0Eta_cosThetaGJ_Recon[iPol][iTBin] = new TH2F(Form("h2_Mpi0Eta_cosThetaGJ_Recon_%s_%s",polString[iPol].Data(),tBinString[iTBin].Data()),Form("M_{#eta#pi^{0}} vs cos(#theta_{#eta#gamma_{J}}) (%s, %s)",polString[iPol].Data(),tBinString[iTBin].Data()),100,1.04,1.72,100,-1.0,1.0);
                
                // vector<TH2F*> vh2Recon;
                // vector<brVar> vBrXRecon;
                // vector<brVar> vBrYRecon;

                // vh2Recon.push_back(h2_Mpi0Eta_cosThetaGJ_Recon[iPol][iTBin]);
                // vBrXRecon.push_back(Mpi0eta);
                // vBrYRecon.push_back(cosTheta_eta_gj);
                // DefineHistogram2D(vh2Recon,vBrXRecon,vBrYRecon);
                // FillHistogram2D(tFlatTreeRecon,vh2Recon,vBrXRecon,vBrYRecon);



                // if (!iPol) h2_Mpi0Eta_cosThetaGJ_Recon_sum[iTBin] = (TH2F*)h2_Mpi0Eta_cosThetaGJ_Recon[iPol][iTBin]->Clone();
                // else h2_Mpi0Eta_cosThetaGJ_Recon_sum[iTBin]->Add(h2_Mpi0Eta_cosThetaGJ_Recon[iPol][iTBin]);
                // c_test->cd();
                // h2_Mpi0Eta_cosThetaGJ_Recon[iPol][iTBin]->Draw("COLZ");
                // c_test->SaveAs(Form("plot_Mpi0Eta_cosThetaGJ_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()));

                Hist1DManager *h1ManagerRecon = new Hist1DManager();
                
                h1ManagerRecon->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",50,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]);
                h1ManagerRecon->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]);
                h1ManagerRecon->FillFromTree(tFlatTreeRecon);
                h1ManagerMpieta->Add(h1ManagerRecon->GetHist(0),h1ManagerRecon->GetBrVar(0),h1ManagerRecon->GetNBinsX(0),h1ManagerRecon->GetXMin(0),h1ManagerRecon->GetXMax(0));
                h1ManagerCosThetaGJ->Add(h1ManagerRecon->GetHist(1),h1ManagerRecon->GetBrVar(1),h1ManagerRecon->GetNBinsX(1),h1ManagerRecon->GetXMin(1),h1ManagerRecon->GetXMax(1));
                h1ManagerRecon->Print(0,Form("HistManagerPlot_Mpi0Eta_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"P",1600,1600);
                h1ManagerRecon->Print(1,Form("HistManagerPlot_cosThetaGJ_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"P",1600,1600);
                // delete h1ManagerRecon;

                // Hist2DManager *h2ManagerRecon = new Hist2DManager();
                // h2ManagerRecon->Add(Mpi0eta,cosTheta_eta_gj,"M_{#eta#pi^{0}} (GeV)","cos(#theta_{GJ})",50,1.04,1.72,50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]);
                // h2ManagerRecon->FillFromTree(tFlatTreeRecon);
                // h2ManagerMpi0etaPol->Add(h2ManagerRecon->GetHist(0),h2ManagerRecon->GetBrVarX(0),h2ManagerRecon->GetBrVarY(0),h2ManagerRecon->GetNBinsX(0),h2ManagerRecon->GetXMin(0),h2ManagerRecon->GetXMax(0),h2ManagerRecon->GetNBinsY(0),h2ManagerRecon->GetYMin(0),h2ManagerRecon->GetYMax(0));
                // delete h2ManagerRecon;
                // h2ManagerRecon->Print(0,Form("HistManagerPlot_Mpi0Eta_cosThetaGJ_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"COLZ",1600,1200);
            
                // TTree *tFlatTreeReconPhase1 = (TTree*)fFlatTreeReconPhase1[iPol][iTBin]->Get("kin");
                // AssignSelectedBranches(tFlatTreeReconPhase1, branchFlatTree, branchVar);

                // Hist1DManager *h1ManagerReconPhase1 = new Hist1DManager();
                // h1ManagerReconPhase1->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",50,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_Phase1");
                // h1ManagerReconPhase1->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_Phase1");
                // h1ManagerReconPhase1->FillFromTree(tFlatTreeReconPhase1);
                // h1ManagerMpietaPhase1->Add(h1ManagerReconPhase1->GetHist(0),h1ManagerReconPhase1->GetBrVar(0),h1ManagerReconPhase1->GetNBinsX(0),h1ManagerReconPhase1->GetXMin(0),h1ManagerReconPhase1->GetXMax(0));
                // h1ManagerCosThetaGJPhase1->Add(h1ManagerReconPhase1->GetHist(1),h1ManagerReconPhase1->GetBrVar(1),h1ManagerReconPhase1->GetNBinsX(1),h1ManagerReconPhase1->GetXMin(1),h1ManagerReconPhase1->GetXMax(1));
                // delete h1ManagerReconPhase1;
            
            }

            // cout << "h2ManagerMpi0etaPol->GetSize() = " << h2ManagerMpi0etaPol->GetSize() << endl;
            // h1ManagerMpieta->PrintHistSum(Form("HistManagerPlot_Mpi0Eta_Recon_sum_%s_%s_%s_%s.pdf",tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data(),dataTag.Data()),"P",1600,1600);
            // h1ManagerCosThetaGJ->PrintHistSum(Form("HistManagerPlot_cosThetaGJ_Recon_sum_%s_%s_%s_%s.pdf",tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data(),dataTag.Data()),"P",1600,1600);
            // h2ManagerMpi0etaPol->PrintHistSum(Form("HistManagerPlot_Mpi0Eta_cosThetaGJ_Recon_sum_%s_%s_%s_%s.pdf",tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data(),dataTag.Data()),"COLZ",1600,1600);
            
            // c_test->cd();
            // TLegend *leg = new TLegend(0.7,0.8,0.8,0.9);
            // TH1F *h1_Mpi0eta_Recon_sum = (TH1F*)h1ManagerMpieta->GetHistSum();
            // TH1F *h1_Mpi0eta_Recon_sum_Phase1 = (TH1F*)h1ManagerMpietaPhase1->GetHistSum();
            // h1_Mpi0eta_Recon_sum_Phase1->Draw("P");
            // h1_Mpi0eta_Recon_sum->SetLineColor(kRed);
            // h1_Mpi0eta_Recon_sum->Draw("PSAME");
            // leg->AddEntry(h1_Mpi0eta_Recon_sum,"2019-11","pl");
            // leg->AddEntry(h1_Mpi0eta_Recon_sum_Phase1,"GlueX-I","pl");
            // leg->Draw();
            // c_test->SaveAs(Form("plot_Mpi0Eta_wPhase1_Recon_sum_%s_%s_%s_%s.pdf",tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data(),dataTag.Data()));

            // TH1F *h1_cosThetaGJ_Recon_sum = (TH1F*)h1ManagerCosThetaGJ->GetHistSum();
            // TH1F *h1_cosThetaGJ_Recon_sum_Phase1 = (TH1F*)h1ManagerCosThetaGJPhase1->GetHistSum();
            // h1_cosThetaGJ_Recon_sum_Phase1->Draw("P");
            // h1_cosThetaGJ_Recon_sum->SetLineColor(kRed);
            // h1_cosThetaGJ_Recon_sum->Draw("PSAME");
            // leg->Clear();
            // leg->AddEntry(h1_cosThetaGJ_Recon_sum,"2019-11","pl");
            // leg->AddEntry(h1_cosThetaGJ_Recon_sum_Phase1,"GlueX-I","pl");
            // leg->Draw();
            // c_test->SaveAs(Form("plot_cosThetaGJ_wPhase1_Recon_sum_%s_%s_%s_%s.pdf",tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data(),dataTag.Data()));

            TLatex *tbinLatex = new TLatex();
            tbinLatex->SetTextSize(0.04);
            tbinLatex->SetTextAlign(22);

            if (isPlotVanHopeAngle) {
                c1->cd(iTBin+1);
                h2_Mpi0Eta_VanHove_sum[iTBin]->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
                h2_Mpi0Eta_VanHove_sum[iTBin]->GetYaxis()->SetTitle("#omega (deg)");
                h2_Mpi0Eta_VanHove_sum[iTBin]->SetMinimum(0);
                h2_Mpi0Eta_VanHove_sum[iTBin]->Draw("COL");
                
                // draw tbin using TLatex
                tbinLatex->DrawLatexNDC(0.5,0.9,Form("%0.3f < |#it{t}| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));
                
                c2->cd(iTBin+1);
                h1_Mpi0p_sum[iTBin]->GetXaxis()->SetTitle("M_{#pi^{0}p} (GeV)");
                h1_Mpi0p_sum[iTBin]->GetYaxis()->SetTitle("Events / 10 MeV");
                h1_Mpi0p_sum[iTBin]->Draw("HIST");

                h1_Mpi0p_pVH_sum[iTBin]->SetLineColor(kRed);
                h1_Mpi0p_pVH_sum[iTBin]->SetLineWidth(2);
                h1_Mpi0p_pVH_sum[iTBin]->Draw("HIST SAME");
                tbinLatex->DrawLatexNDC(0.62,0.25,Form("%0.3f < |#it{t}| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));

                TLegend *leg = new TLegend(0.5,0.7,0.8,0.9);
                leg->AddEntry(h1_Mpi0p_sum[iTBin],"All selected events","l");
                leg->AddEntry(h1_Mpi0p_pVH_sum[iTBin],"+VH angle cut","l");
                leg->Draw();
            }

            if (isPlotMPi0Eta) {
                c_Mpi0Eta->cd(iTBin+1);
                h1_Mpi0eta_sum[iTBin]->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
                h1_Mpi0eta_sum[iTBin]->GetYaxis()->SetTitle("Events / 40 MeV");
                h1_Mpi0eta_sum[iTBin]->Draw("HIST");
            
                tbinLatex->DrawLatexNDC(0.45,0.25,Form("%0.3f < |#it{t}| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));
            }
        }
        gSystem->cd(mainDir);
        if (isPlotVanHopeAngle) {
            c1->SaveAs(Form("plot_Mpi0Eta_VanHove_sum_%s_%s_%s.pdf",mBinString.Data(),extraTag.Data(),dataTag.Data()));
            c2->SaveAs(Form("plot_Mpi0p_sum_%s_%s_%s.pdf",mBinString.Data(),extraTag.Data(),dataTag.Data()));
        }
        if (isPlotMPi0Eta) c_Mpi0Eta->SaveAs(Form("plot_Mpi0Eta_sum_%s_%s_%s.pdf",mBinString.Data(),extraTag.Data(),dataTag.Data()));
        */
    }
 
    if (isRunEtaPiPlotter) {
        // run etapi_plotter
        cout << endl << endl << "Running etapi_plotter..." << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++) etaPiPlotter(fitResultDir[iTBin],"etapi_result.fit","etapi_plot",Form("'%s'",strWave.Data()),kTRUE,strFitFracWave,kFALSE,kTRUE);
    }

    // TFile *fHistFitResult = TFile::Open(rootHistFitResult, "READ");
    // TFile *fFlatTreeSignal[NPol];
    // TFile *fFlatTreeBkgnd[NPol];
    // TFile *fFlatTreeMCRecon[NPol];
    // TFile *fFlatTreeMCThrown[NPol];

    if (isPlotWaves) {
        // open root files from etapi_plotter
        TFile *fHistFitResult[NTBin];
        cout << endl << endl << "Opening root files from etapi_plotter:" << endl;
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++) {
            cout << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
            TString rootFileName = fitResultDir[iTBin] + etaPiPlotterOutName + "_" + strWave + ".root";
            cout << "File: " << rootFileName <<  endl;
            fHistFitResult[iTBin] = TFile::Open(rootFileName, "READ");
        }
        c1->Clear();
        c1->Divide(3,2);
        c1->SetCanvasSize(1600,1200);

        TH1F *h1MEtaPiAccSum[NTBin];
        TH1F *h1MEtaPiSigSum[NTBin];
        TH1F *h1MEtaPiBkgSum[NTBin];
        TLatex *lLatex = new TLatex();
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            c1->cd(iTBin+1);
            TH1F *h1MEtaPiAcc[NPol];
            TH1F *h1MEtaPiSig[NPol];
            TH1F *h1MEtaPiBkg[NPol];
            for (Int_t iPol=0;iPol<NPol;iPol++){
                // fFlatTreeSignal[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeSignal[iPol], "READ");
                // fFlatTreeBkgnd[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeBkgnd[iPol], "READ");
                // fFlatTreeMCRecon[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeMCRecon[iPol], "READ");
                // fFlatTreeMCThrown[iPol] = TFile::Open(dirRootFlatTree+rootFlatTreeMCThrown[iPol], "READ");
                h1MEtaPiAcc[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMEtaPiAccName);
                h1MEtaPiSig[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMEtaPiSigName);
                h1MEtaPiBkg[iPol] = (TH1F*)fHistFitResult[iTBin]->Get(histBaseName[iPol]+histMetaPiBkgName);

                if (iPol==0) {
                    h1MEtaPiAccSum[iTBin] = new TH1F(*h1MEtaPiAcc[iPol]);
                    h1MEtaPiSigSum[iTBin] = new TH1F(*h1MEtaPiSig[iPol]);
                    h1MEtaPiBkgSum[iTBin] = new TH1F(*h1MEtaPiBkg[iPol]);
                }
                else {
                    h1MEtaPiAccSum[iTBin]->Add(h1MEtaPiAcc[iPol]);
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
            h1MEtaPiSigSum[iTBin]->GetXaxis()->SetRangeUser(1.04,1.72);
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetRangeUser(0,h1MEtaPiSigSum[iTBin]->GetMaximum()*1.2);
            h1MEtaPiSigSum[iTBin]->GetXaxis()->SetTitle("M_{#eta#pi^{0}} (GeV)");
            h1MEtaPiSigSum[iTBin]->GetYaxis()->SetTitle("Events / 40 MeV");
            h1MEtaPiSigSum[iTBin]->SetTitle(Form("%0.3f < |t| < %0.3f GeV^{2}",tMin[iTBin],tMax[iTBin]));
            h1MEtaPiSigSum[iTBin]->DrawCopy("HIST");
            h1MEtaPiAccSum[iTBin]->SetFillColor(kRed);
            h1MEtaPiAccSum[iTBin]->SetFillStyle(3002);
            h1MEtaPiAccSum[iTBin]->DrawCopy("HIST SAME");
            lLatex->DrawLatexNDC(0.5,0.85,Form("%0.3f<t<%0.3f",tMin[iTBin],tMax[iTBin]));
            delete h1MEtaPiAccSum[iTBin];
            delete h1MEtaPiSigSum[iTBin];
            delete h1MEtaPiBkgSum[iTBin];
        }
        gSystem->cd(mainDir);
        c1->SaveAs(Form("plot_waveset_%s_%s.pdf",strWave.Data(),extraTag.Data()));
    }
    c1->Clear();
    c1->Divide(1,1);
    if (isPlotA2CS) {
        c1->cd();
        TGraph *gA2CS = new TGraph();
        for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
            TString fName = fitResultDir[iTBin] + etaPiPlotterOutLogName;
            Double_t accCorrYield = GetAccCorrYield(fName);
            Double_t dt = tMax[iTBin]-tMin[iTBin];
            Double_t dsigdt = accCorrYield/(1000000*lum*dt*0.0565);
            gA2CS->AddPoint((tMin[iTBin]+tMax[iTBin])/2,dsigdt);
            cout << endl << (tMin[iTBin]+tMax[iTBin])/2 << " " << accCorrYield << endl;
            // Double_t AccCorrYields = GetAccCorrYield(fName);
        }
        gA2CS->SetMarkerStyle(20);
        gA2CS->SetMarkerSize(1.5);
        gA2CS->SetMarkerColor(kRed);
        gA2CS->SetLineColor(kRed);
        gA2CS->GetXaxis()->SetTitle("|t| (GeV^{2})");
        gA2CS->GetYaxis()->SetTitle("d#sigma/dt (#mu b/GeV^{2})");
        gA2CS->Draw("AP");
        gSystem->cd(mainDir);
        c1->SaveAs(Form("plot_A2CS_%s.pdf",extraTag.Data()));
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

    // open flat trees
    for (auto polstrs: polString) {
        vector<TString> rootFlatTreeSignalTemp;
        vector<TString> rootFlatTreeBkgndTemp;
        vector<TString> rootFlatTreeReconTemp;
        vector<TString> rootFlatTreeMCReconTemp;
        vector<TString> rootFlatTreeMCThrownTemp;
        vector<TString> rootFlatTreeReconPhase1Temp;
       
        for (auto tbinstrs: tBinString) {
            TString dirTemp = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+extraTag+"/";
            rootFlatTreeSignalTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_data_flat.root");
            rootFlatTreeBkgndTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_bkgnd_flat.root");
            rootFlatTreeReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_D"+dataTag+"_selected_acc_flat.root");
            rootFlatTreeMCReconTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_F"+dataTag+"_selected_acc_flat.root");
            rootFlatTreeMCThrownTemp.push_back(dirTemp+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+extraTag+"_F"+dataTag+"_gen_data_flat.root");
            TString dirTempPhase1 = dirRootFlatTree+"t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_"+extraTagPhase1+"/";
            rootFlatTreeReconPhase1Temp.push_back(dirTempPhase1+polstrs+"_t"+tbinstrs+"_"+mBinString+"_"+dataTagPhase1+"_selected_"+extraTagPhase1+"_acc_flat.root");
        }
        rootFlatTreeSignal.push_back(rootFlatTreeSignalTemp);
        rootFlatTreeBkgnd.push_back(rootFlatTreeBkgndTemp);
        rootFlatTreeRecon.push_back(rootFlatTreeReconTemp);
        rootFlatTreeMCRecon.push_back(rootFlatTreeMCReconTemp);
        rootFlatTreeMCThrown.push_back(rootFlatTreeMCThrownTemp);
        rootFlatTreeReconPhase1.push_back(rootFlatTreeReconPhase1Temp);
    }
    // open flat trees
    TFile *fFlatTreeSignal[NPol][NTBin];
    TFile *fFlatTreeBkgnd[NPol][NTBin];
    TFile *fFlatTreeRecon[NPol][NTBin];
    TFile *fFlatTreeMCRecon[NPol][NTBin];
    TFile *fFlatTreeMCThrown[NPol][NTBin];
    TFile *fFlatTreeReconPhase1[NPol][NTBin];
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
            // cout << rootFlatTreeReconPhase1[iPol][iTBin] << endl;
            // fFlatTreeReconPhase1[iPol][iTBin] = TFile::Open(rootFlatTreeReconPhase1[iPol][iTBin], "READ");
        }
    }

    TCanvas *c_ft1 = new TCanvas("c_ft","c_ft",1600,1200);
    c_ft1->Divide(2,2);
    const Int_t NPlotSplitPol = 3;
    TCanvas *c_pol[NPlotSplitPol];
    for (Int_t i=0;i<NPlotSplitPol;i++) {
        c_pol[i] = new TCanvas(Form("c_pol_%d",i),Form("c_pol_%d",i),1600,1200);
        c_pol[i]->Divide(2,2);
    }

    TLatex *lLatex = new TLatex();
    lLatex->SetTextSize(0.04);
    lLatex->SetTextAlign(22);

    TLegend *leg = new TLegend(0.2,0.8,0.4,0.95);

    for (Int_t iTBin=0;iTBin<NTBin;iTBin++){
        // manager for histograms for polarization sum
        Hist1DManager *h1ManagerMpieta = new Hist1DManager();
        Hist1DManager *h1ManagerCosThetaGJ = new Hist1DManager();
        Hist2DManager *h2ManagerMpi0etaPol = new Hist2DManager();

        // Phase1
        Hist1DManager *h1ManagerMpietaPhase1 = new Hist1DManager();
        Hist1DManager *h1ManagerCosThetaGJPhase1 = new Hist1DManager();
        Hist2DManager *h2ManagerMpietaPolPhase1 = new Hist2DManager();

        cout << endl << endl << "=============================" << tBinString[iTBin] << "=============================" << endl;
        for (Int_t iPol=0;iPol<NPol;iPol++){
            cout << endl << "=============================" << polString[iPol] << "=============================" << endl;
            // get trees
            // TTree *tFlatTreeSignal = (TTree*)fFlatTreeSignal[iPol][iTBin]->Get("kin");
            // TTree *tFlatTreeBkgnd = (TTree*)fFlatTreeBkgnd[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeRecon = (TTree*)fFlatTreeRecon[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCRecon = (TTree*)fFlatTreeMCRecon[iPol][iTBin]->Get("kin");
            TTree *tFlatTreeMCThrown = (TTree*)fFlatTreeMCThrown[iPol][iTBin]->Get("kin");
            // TTree *tFlatTreeReconPhase1 = (TTree*)fFlatTreeReconPhase1[iPol][iTBin]->Get("kin");

            // get branches
            // AssignSelectedBranches(tFlatTreeSignal, branchFlatTree, branchVar);
            // AssignSelectedBranches(tFlatTreeBkgnd, branchFlatTree, branchVar);
            AssignSelectedBranches(tFlatTreeRecon, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerRecon = new Hist1DManager();

            h1ManagerRecon->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",50,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->Add(Ebeam,"E_{beam} (GeV)",50,7.8,9.0,tBinString[iTBin]+"_"+polString[iPol]+"_Recon");
            h1ManagerRecon->FillFromTree(tFlatTreeRecon);
            // h1ManagerRecon->Print(0,Form("HistManagerPlot_Mpi0Eta_Recon_%s_%s_%s_%s.pdf",polString[iPol].Data(),tBinString[iTBin].Data(),mBinString.Data(),extraTag.Data()),"P",1600,1600);
            h1ManagerMpieta->Add(h1ManagerRecon->GetHist(0),h1ManagerRecon->GetBrVar(0),h1ManagerRecon->GetNBinsX(0),h1ManagerRecon->GetXMin(0),h1ManagerRecon->GetXMax(0));
            h1ManagerCosThetaGJ->Add(h1ManagerRecon->GetHist(1),h1ManagerRecon->GetBrVar(1),h1ManagerRecon->GetNBinsX(1),h1ManagerRecon->GetXMin(1),h1ManagerRecon->GetXMax(1));

            AssignSelectedBranches(tFlatTreeMCRecon, branchFlatTree, branchVar, NBranchFlatTree);
            Hist1DManager *h1ManagerMCRecon = new Hist1DManager();
            h1ManagerMCRecon->Add(Mpi0eta,"M_{#eta#pi^{0}} (GeV)",50,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->Add(cosTheta_eta_gj,"cos#theta_{GJ}",50,-1.0,1.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->Add(Ebeam,"E_{beam} (GeV)",50,7.8,9.0,tBinString[iTBin]+"_"+polString[iPol]+"_MCRecon");
            h1ManagerMCRecon->FillFromTree(tFlatTreeMCRecon);

            AssignSelectedBranches(tFlatTreeMCThrown, branchFlatTreeThrown, branchVarThrown, NBranchFlatTreeThrown);
            Hist1DManager *h1ManagerMCThrown = new Hist1DManager();
            h1ManagerMCThrown->Add(Mpi0eta_thrown,"M_{#eta#pi^{0}} (GeV)",50,1.04,1.72,tBinString[iTBin]+"_"+polString[iPol]+"_MCThrown");
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
            leg->AddEntry(h1ManagerRecon->GetHist(0),"GlueX 2019-11","l");
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
            leg->AddEntry(h1ManagerRecon->GetHist(1),"GlueX 2019-11","l");
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
            leg->AddEntry(h1ManagerRecon->GetHist(2),"GlueX 2019-11","l");
            leg->AddEntry(h1ManagerMCRecon->GetHist(2),"MC Recon","l");
            leg->AddEntry(h1ManagerMCThrown->GetHist(2),"MC Thrown","l");
            leg->Draw();

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
    }
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

Double_t GetAccCorrYield(TString fileName){

    ifstream log(fileName.Data());
    TString line;

    list<TString> lines;
    while (log >> line) lines.push_back(line);
    Int_t totalEvents;
    Float_t fitFrac;

    for (auto pline = lines.cbegin(); pline != lines.cend(); ++pline) {
        if (pline->EqualTo("EVENTS")) {
            // cout << "Found " << strTotalEvent << " in the file" << endl;
            TString tempStr = *(++(++pline));
            totalEvents = tempStr.Atoi();
            break;
        }
    }
    // for (Int_t i=0;i<totalEvents.size();i++) cout << totalEvents[i] << endl;

    for (auto pline = lines.cbegin(); pline != lines.cend(); ++pline) {
        if (pline->EqualTo("D")) {
            cout << "Found " << "D" << " in the file" << endl;
            TString tempStr = *(++(++pline));
            fitFrac = tempStr.Atof();
            break;
        }
    }
    // for (Int_t i=0;i<fitFrac.size();i++) cout << fitFrac[i] << endl;
    Double_t accCorrYield;
    cout << endl << "Reading values from " << fileName << endl;
    cout << "Total events: " << totalEvents << endl;
    cout << "Fit fraction of D: " << fitFrac << endl;
    cout << "Acc. corr. yield: " << totalEvents*fitFrac << endl;
    accCorrYield = totalEvents*fitFrac;
    
    return accCorrYield;
}

void FillHistogram2D(TTree* tTree, vector<TH2F*> vh2, vector<brVar> vbVarX, vector<brVar> vbVarY){
    for (Int_t iEvent=0;iEvent<tTree->GetEntries();iEvent++){
        tTree->GetEntry(iEvent);
        for (Int_t iH2=0;iH2<vh2.size();iH2++) {
            vh2[iH2]->Fill(branchVar[vbVarX[iH2]],branchVar[vbVarY[iH2]],branchVar[Weight]);
        }
    }
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
	gluex_style->SetPadBottomMargin(0.1);
	gluex_style->SetPadLeftMargin(0.15);
	gluex_style->SetPadTopMargin(0.05);
	gluex_style->SetPadRightMargin(0.1);

	// axis labels and settings
    gluex_style->SetStripDecimals(0);
 	gluex_style->SetLabelSize(0.03,"xyz"); // size of axis value font
 	gluex_style->SetTitleSize(0.04,"xyz"); // size of axis title font
 	gluex_style->SetTitleFont(42,"xyz"); // font option
 	gluex_style->SetLabelFont(42,"xyz"); 
 	gluex_style->SetTitleOffset(1.5,"y"); 
 	gluex_style->SetLabelOffset(0.01,"xyz");   // stop collisions of "0"s at the origin
 	
	// histogram settings
	gluex_style->SetOptStat(0);     // no stats box by default
	gluex_style->SetOptTitle(0);    // no title by default
	gluex_style->SetHistLineWidth(2); 
	gluex_style->SetNdivisions(508,"xyz"); // some ticks were very bunched, lets reduce the number of divisions to label 
	// gluex_style->SetOptFit(0111);

	// gluex_style->SetHistFillColor(920);   // grey
    gluex_style->SetFillStyle(0);
	gluex_style->SetPalette(kRainBow); // kViridis is perceptually uniform and colorblind friendly
	gluex_style->cd();
}