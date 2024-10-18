
void MakeTWeight(const TString inFileName="/d/home/septian/EtaPi0Analysis/MomentMCStudy/data_sig_bkg.root", 
                const TString treeName="kin",
                const TString weightBranchName="Weight",
                const TString outFileName="/d/home/septian/EtaPi0Analysis/MomentMCStudy/weights_data_sig_bkg.root")
{
    cout << "Processing " << inFileName << endl;
    TFile* treefileData=new TFile(inFileName);
    TTree* treeData=treefileData->Get<TTree>(treeName);
    Weights* wgtsData = new Weights("weight");
    wgtsData->SetFile(outFileName);
    cout << "SetFile weight: " << outFileName << endl;
    wgtsData->SetSpecies("Acc");
    wgtsData->SetIDName("UID");
    
    for (Int_t iEntry=0; iEntry<treeData->GetEntries(); iEntry++){
        treeData->GetEntry(iEntry);
        Double_t weight = static_cast<Float_t>(treeData->GetLeaf(weightBranchName)->GetValue());
        Double_t wID = treeData->GetLeaf("UID")->GetValue();
        wgtsData->FillWeight(wID,weight);
    }

    wgtsData->SortWeights();
    wgtsData->Save();
    delete wgtsData;
}