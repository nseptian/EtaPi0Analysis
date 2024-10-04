#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <TH1F.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TString.h>
#include <TFile.h>
#include <TTree.h>
#include <TLegend.h>

using json = nlohmann::json;

int DrawMoments(){
    const TString outPdfDir = "/d/home/septian/EtaPi0Plot/";
    // import true moment values from json file
    const TString inputFilePath = "/d/grid17/septian/EtaPi0Analysis/MomentMCStudy/trueMomentValues.json";

    std::ifstream inputFile(inputFilePath.Data());
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    // Read the JSON file into a json object
    json jsonData;
    inputFile >> jsonData;

    // Close the file
    inputFile.close();
    std::cout << "== Printing true moment values ==" << std::endl;
    std::cout << "Number of moments: " << jsonData.size() << std::endl;
    // Iterate over the JSON array
    for (const auto& item : jsonData) {
        int momentIndex = item["qn"]["momentIndex"];
        int L = item["qn"]["L"];
        int M = item["qn"]["M"];
        double val_Re = item["val_Re"];
        double val_Im = item["val_Im"];

        // Print the values
        std::cout << "momentIndex: " << momentIndex << ", L: " << L << ", M: " << M
                  << ", val_Re: " << val_Re << ", val_Im: " << val_Im << std::endl;
    }

    // Draw the moments
    TCanvas *c = new TCanvas("c", "c", 800, 600);
    c->SetGrid();
    gStyle->SetOptStat(0);

    TH1F *h = new TH1F("h", "h", jsonData.size(), 0, jsonData.size());
    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.5);
    h->SetMarkerColor(kBlue);

    vector <TString> momentLabels;

    int i = 1;
    for (const auto& item : jsonData) {
        int momentIndex = item["qn"]["momentIndex"];
        int L = item["qn"]["L"];
        int M = item["qn"]["M"];
        double val_Re = item["val_Re"];
        double val_Im = item["val_Im"];

        if (momentIndex < 2) h->SetBinContent(i, val_Re);
        else h->SetBinContent(i, val_Im);

        h->SetBinError(i, 0.0);

        momentLabels.push_back(Form("H_{%d}(%d,%d)", momentIndex, L, M));
        h->GetXaxis()->SetBinLabel(i, momentLabels[i-1]);
        i++;
    }

    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.0);
    h->SetLineColor(kBlue);
    h->SetTitle("Comparison of true and fit moments");
    h->Draw("HIST");

    // import fit moment values from root file
    const TString rootFilePath = "/d/grid17/septian/EtaPi0Analysis/MomentMCStudy/fitBruMomentsLM4/ResultsHSMinuit2.root";
    TFile *f = new TFile(rootFilePath.Data());
    if (!f->IsOpen()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    TTree *t = (TTree*)f->Get("ResultTree");

    // Read the tree
    vector <double> fitVal;
    vector <double> fitErr;
    vector <int> fitMomentIndex;
    vector <int> fitL;
    vector <int> fitM;

    double val;
    double err;
    int momentIndex;
    int L;
    int M;

    for (Int_t iBranch=0; iBranch<t->GetListOfBranches()->GetEntries(); iBranch++){
        TString branchName = t->GetListOfBranches()->At(iBranch)->GetName();
        std::cout << "Branch name: " << branchName << std::endl;
        
        if (branchName.Contains("H_")) {
            if (branchName.Contains("err")){
                t->SetBranchAddress(branchName, &err);
            }
            else {
                t->SetBranchAddress(branchName, &val);
            }
            // get the moment index, L, and M from H_index_L_M
            TString momentIndexStr = branchName;
            momentIndexStr.ReplaceAll("H_", "");
            momentIndexStr.ReplaceAll("_", " ");
            sscanf(momentIndexStr.Data(), "%d %d %d", &momentIndex, &L, &M);
        }
        t->GetEntry(0);
        // normalize H_0_0_0 to 1
        val /= 2.0;
        err /= 2.0;
        fitVal.push_back(val);
        fitErr.push_back(err);
        fitMomentIndex.push_back(momentIndex);
        fitL.push_back(L);
        fitM.push_back(M);
    }

    std::cout << "== Printing fit moment values ==" << std::endl;
    for (unsigned int i=0; i<fitVal.size(); i++){
        std::cout << "momentIndex: " << fitMomentIndex[i] << ", L: " << fitL[i] << ", M: " << fitM[i]
                  << ", val: " << fitVal[i] << ", err: " << fitErr[i] << std::endl;
    }

    // Draw the fit moments
    TH1F *hFit = new TH1F("hFit", "hFit", momentLabels.size(), 0, momentLabels.size());
    hFit->SetMarkerStyle(20);
    hFit->SetMarkerSize(1.0);
    hFit->SetMarkerColor(kRed);

    for (unsigned int i=0; i<fitVal.size(); i++){
        // cout << Form("H_{%d}(%d,%d)", fitMomentIndex[i], fitL[i], fitM[i]) << endl;
        for (unsigned int j=0; j<momentLabels.size(); j++){
            // cout << j << endl;
            if (momentLabels[j].Contains(Form("H_{%d}(%d,%d)", fitMomentIndex[i], fitL[i], fitM[i]))){
                hFit->SetBinContent(j+1, fitVal[i]);
                hFit->SetBinError(j+1, fitErr[i]);
            }
        }
    }

    hFit->Draw("E1 SAME");

    TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->AddEntry(h, "True moments", "l");
    leg->AddEntry(hFit, "Fit moments", "p");
    leg->Draw();

    c->SaveAs(outPdfDir + "MomentsComparison.pdf");
    return 0;
}