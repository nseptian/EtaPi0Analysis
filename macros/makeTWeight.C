

TString treename="kin";
TString workingDir="/d/grid17/septian/EtaPi0Analysis/run/rootFiles/t010020_m104172_Phase1_brufit/";
TString tBinString="t010020";
TString mBinString="m104172_Phase1_brufit";
// TString polString[4]={"pol000","pol045","pol090","pol135"};
vector <TString> polString={"polALL"};
TString tag="nominal_wPhotonSyst";


void makeTWeight(){
    vector <TString> datafiles;
    // vector <TString> runs={"2017_1","2018_1","2018_8"};
    vector<TString> runs = {"TOT"};

    for (auto run: runs){
        for (auto pol: polString){
            datafiles.push_back(pol+"_"+tBinString+"_"+mBinString+"_D"+run+"_selected_"+tag+"_acc_flat.root");
            // datafiles.push_back(pol+"_"+tBinString+"_"+mBinString+"_F"+run+"_selected_"+tag+"_acc_flat.root");
        }
    }

    for (auto data: datafiles) {
        cout << "Processing " << data << endl;
        TFile* treefileData=new TFile(workingDir+data);
        TTree* treeData=treefileData->Get<TTree>(treename);

        Weights* wgtsData = new Weights("weight");
        wgtsData->SetFile(workingDir+"weights_"+data);
        cout << "SetFile weight: " << workingDir+"weights_"+data << endl;
        wgtsData->SetSpecies("Acc");
        wgtsData->SetIDName("UID");
        
        for (Int_t iEntry=0; iEntry<treeData->GetEntries(); iEntry++){
            treeData->GetEntry(iEntry);
            Float_t weight = static_cast<Float_t>(treeData->GetLeaf("Weight")->GetValue());
            Float_t wID = treeData->GetLeaf("UID")->GetValue();
            wgtsData->FillWeight(wID,treeData->GetLeaf("Weight")->GetValue());
        }
        wgtsData->SortWeights();
        wgtsData->Save();
        delete wgtsData;
    }

    // TFile* treefileData=new TFile(datafile);
    // TTree* treeData=treefileData->Get<TTree>(treename);

    //create sideband weights object in outdir, with name SideBand and event id uniqueComboID. Note uniqueComboID is important every tree should have a unique integer associated with it so it can find the correct weight. If your tree does not have this you can create it with the helper macro : root '$BRUFIT/macros/AddIDBranch.C("TreeName","FileName.root")'  by default it will be stored in the branch "UID" rather than uniqueComboID.

    // Weights* wgtsSBData=new Weights("HSsWeights");
    // wgtsSBData->SetFile(outdir+"/SideBandData.root");
    // wgtsSBData->SetSpecies("SideBand");
    // wgtsSBData->SetIDName("uniqueComboID");

    //Take the weights from the tree, (photonBeamEnergy_kinfit>0.0) is just some cut, this can probably be left at "", but if it complains you can give it something that always gives 1(true). "scaledtimingWeight_measured" is the name of the weights branch you want to copy
    // wgtsSBData->WeightBySelection(treeData,"(photonBeamEnergy_kinfit>0.0)","scaledtimingWeight_measured");
    // wgtsSBData->SortWeights();
    // wgtsSBData->Save();//Save to disc
    // delete wgtsSBData; wgtsSBData=nullptr;
}