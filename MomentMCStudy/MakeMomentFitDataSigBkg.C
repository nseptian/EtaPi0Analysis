
int MakeMomentFitDataSigBkg(const TString inFileSig="/d/grid17/septian/EtaPi0Analysis/run/rootFiles/F2017_1_selected_TestMomentFit_data_flat.root.intensityWeighted.sig.root",
                            const TString inFileBkg="/d/grid17/septian/EtaPi0Analysis/run/rootFiles/F2017_1_selected_TestMomentFit_data_flat.root.intensityWeighted.bkg.root",
                            const TString outFile="/d/home/septian/EtaPi0Analysis/MomentMCStudy/data_sig_bkg.root")
{   
    Float_t in_cosTheta_eta_hel, in_phi_eta_hel, in_Phi, in_weight;
    Double_t massEta, massPi0;
    TChain *t = new TChain("kin");
    t->Add(inFileSig);
    t->Add(inFileBkg);
    t->SetBranchAddress("massEta",&massEta);
    t->SetBranchAddress("massPi0",&massPi0);
    t->SetBranchAddress("cosTheta_eta_hel",&in_cosTheta_eta_hel);
    t->SetBranchAddress("phi_eta_hel",&in_phi_eta_hel);
    t->SetBranchAddress("Phi",&in_Phi);
    t->SetBranchAddress("Weight",&in_weight);

    Double_t out_cosTheta_eta_hel, out_phi_eta_hel, out_Phi, out_weight, out_massEta, out_massPi0;
    TFile *fout = new TFile(outFile,"RECREATE");
    TTree *tOut = new TTree("kin","kin");
    tOut->Branch("massEta",&massEta);
    tOut->Branch("massPi0",&massPi0);
    tOut->Branch("cosTheta_eta_hel",&out_cosTheta_eta_hel);
    tOut->Branch("phi_eta_hel",&out_phi_eta_hel);
    tOut->Branch("Phi",&out_Phi);
    tOut->Branch("Weight",&out_weight);

    TDirectory *dirHist = fout->mkdir("Histograms");
    dirHist->cd();
    TH1D *hMassEtaSig = new TH1D("hMassEtaSig",";m_{#eta} [GeV];",100,0.4,0.7);
    TH1D *hMassPi0Sig = new TH1D("hMassPi0Sig",";m_{#pi^{0}} [GeV];",100,0.08,0.2);
    TH1D *hcosThetaEtaHelSig = new TH1D("hcosThetaEtaHelSig",";cos#theta_{#eta}^{hel};",100,-1,1);
    TH1D *hphiEtaHelSig = new TH1D("hphiEtaHelSig",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());
    TH1D *hPhiSig = new TH1D("hPhiSig",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());
    
    TH1D *hMassEtaSigBkg = new TH1D("hMassEtaSigBkg",";m_{#eta} [GeV];",100,0.4,0.7);
    TH1D *hMassPi0SigBkg = new TH1D("hMassPi0SigBkg",";m_{#pi^{0}} [GeV];",100,0.08,0.2);
    TH1D *hcosThetaEtaHelSigBkg = new TH1D("hcosThetaEtaHelSigBkg",";cos#theta_{#eta}^{hel};",100,-1,1);
    TH1D *hphiEtaHelSigBkg = new TH1D("hphiEtaHelSigBkg",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());
    TH1D *hPhiSigBkg = new TH1D("hPhiSigBkg",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());

    TH1D *hMassEtaSidebandSubtracted = new TH1D("hMassEtaSidebandSubtracted",";m_{#eta} [GeV];",100,0.4,0.7);
    TH1D *hMassPi0SidebandSubtracted = new TH1D("hMassPi0SidebandSubtracted",";m_{#pi^{0}} [GeV];",100,0.08,0.2);
    TH1D *hcosThetaEtaHelSidebandSubtracted = new TH1D("hcosThetaEtaHelSidebandSubtracted",";cos#theta_{#eta}^{hel};",100,-1,1);
    TH1D *hphiEtaHelSidebandSubtracted = new TH1D("hphiEtaHelSidebandSubtracted",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());
    TH1D *hPhiSidebandSubtracted = new TH1D("hPhiSidebandSubtracted",";#phi_{#eta} [rad];",100,-TMath::Pi(),TMath::Pi());

    const Double_t pi0_sigma = 0.0076;
    const Double_t pi0_mean = 0.135881;
    const Double_t eta_sigma = 0.0191;
    const Double_t eta_mean = 0.548625;

    const Double_t weight_pi0=-3.0/1.5;
    const Double_t weight_eta=-3.0/2.0;

    for (Int_t i=0; i<t->GetEntries(); i++){
        t->GetEntry(i);
        hMassEtaSigBkg->Fill(massEta,in_weight);
        hMassPi0SigBkg->Fill(massPi0,in_weight);
        hcosThetaEtaHelSigBkg->Fill(in_cosTheta_eta_hel,in_weight);
        hphiEtaHelSigBkg->Fill(TMath::DegToRad()*in_phi_eta_hel,in_weight);
        hPhiSigBkg->Fill(TMath::DegToRad()*in_Phi,in_weight);
        out_cosTheta_eta_hel = in_cosTheta_eta_hel;
        out_phi_eta_hel = TMath::DegToRad()*in_phi_eta_hel;
        out_Phi = TMath::DegToRad()*in_Phi;
        Bool_t isMassPi0InSidebandRegion = ((massPi0 > (pi0_mean + 4*pi0_sigma)) && (massPi0 < (pi0_mean + 5.5*pi0_sigma))) || (((massPi0 > (pi0_mean - 5.5*pi0_sigma)) && (massPi0 < (pi0_mean - 4*pi0_sigma))));
        Bool_t isMassPi0InSignalRegion = (massPi0 > (pi0_mean - 3*pi0_sigma)) && (massPi0 < (pi0_mean + 3*pi0_sigma));
        Bool_t isMassEtaInSidebandRegion = ((massEta > (eta_mean + 4*eta_sigma)) && (massEta < (eta_mean + 6.0*eta_sigma))) || (((massEta > (eta_mean - 6.0*eta_sigma)) && (massEta < (eta_mean - 4*eta_sigma))));
        Bool_t isMassEtaInSignalRegion = (massEta > (eta_mean - 3*eta_sigma)) && (massEta < (eta_mean + 3*eta_sigma));
        Double_t pi0_sbsweight = 1.0;
        Double_t eta_sbsweight = 1.0;
        if (isMassPi0InSidebandRegion) pi0_sbsweight = weight_pi0;
        else if (!isMassPi0InSignalRegion) continue;
        if (isMassEtaInSidebandRegion) eta_sbsweight = weight_eta;
        else if (!isMassEtaInSignalRegion) continue;
        out_weight = pi0_sbsweight*eta_sbsweight;
        hMassEtaSidebandSubtracted->Fill(massEta,eta_sbsweight);
        hMassPi0SidebandSubtracted->Fill(massPi0,pi0_sbsweight);
        hcosThetaEtaHelSidebandSubtracted->Fill(out_cosTheta_eta_hel,out_weight);
        hphiEtaHelSidebandSubtracted->Fill(out_phi_eta_hel,out_weight);
        hPhiSidebandSubtracted->Fill(out_Phi,out_weight);
        tOut->Fill();
    }

    TFile *fSig = new TFile(inFileSig);
    TTree *tSig = (TTree*)fSig->Get("kin");
    tSig->SetBranchAddress("massEta",&massEta);
    tSig->SetBranchAddress("massPi0",&massPi0);
    tSig->SetBranchAddress("cosTheta_eta_hel",&in_cosTheta_eta_hel);
    tSig->SetBranchAddress("phi_eta_hel",&in_phi_eta_hel);
    tSig->SetBranchAddress("Phi",&in_Phi);
    tSig->SetBranchAddress("Weight",&in_weight);

    for (Int_t i=0; i<tSig->GetEntries(); i++){
        tSig->GetEntry(i);
        hMassEtaSig->Fill(massEta,in_weight);
        hMassPi0Sig->Fill(massPi0,in_weight);
        hcosThetaEtaHelSig->Fill(in_cosTheta_eta_hel,in_weight);
        hphiEtaHelSig->Fill(TMath::DegToRad()*in_phi_eta_hel,in_weight);
        hPhiSig->Fill(TMath::DegToRad()*in_Phi,in_weight);
    }

    fout->Write();
    fout->Close();
    return 0;
}