

void DrawHistWithWeight(const TString dataPath="/d/home/septian/EtaPi0Analysis/MomentMCStudy/data_sig_bkg.root",
                        const TString weightFilePath="/d/home/septian/EtaPi0Analysis/MomentMCStudy/weights_data_sig_bkg.root")
{
    gStyle->SetOptStat(0);
    const TString outDir = "/d/home/septian/EtaPi0Plot/";
    TChain *t = new TChain("kin");
    t->Add(dataPath);

    Double_t massEta, massPi0;
    Double_t in_cosTheta_eta_hel, in_phi_eta_hel, in_Phi, UID, Weight;

    t->SetBranchAddress("massEta",&massEta);
    t->SetBranchAddress("massPi0",&massPi0);
    t->SetBranchAddress("cosTheta_eta_hel",&in_cosTheta_eta_hel);
    t->SetBranchAddress("phi_eta_hel",&in_phi_eta_hel);
    t->SetBranchAddress("Phi",&in_Phi);
    t->SetBranchAddress("UID",&UID);
    t->SetBranchAddress("Weight",&Weight);

    TH1D *hMassEtaSidebandSubtracted = new TH1D("hMassEtaSidebandSubtracted",";m_{#eta} [GeV];",100,0.4,0.7);
    TH1D *hMassPi0SidebandSubtracted = new TH1D("hMassPi0SidebandSubtracted",";m_{#pi^{0}} [GeV];",100,0.08,0.2);
    TH1D *hcosThetaEtaHelSidebandSubtracted = new TH1D("hcosThetaEtaHelSidebandSubtracted",";cos#theta_{#eta}^{hel};",100,-1,1);
    TH1D *hphiEtaHelSidebandSubtracted = new TH1D("hphiEtaHelSidebandSubtracted",";#phi_{#eta}^{hel} [rad];",100,-TMath::Pi(),TMath::Pi());
    TH1D *hPhiSidebandSubtracted = new TH1D("hPhiSidebandSubtracted",";#Phi [rad];",100,-TMath::Pi(),TMath::Pi());

    Weights* wgtsData = new Weights("weight");
    wgtsData->LoadSaved(weightFilePath,"weight");
    Int_t counter=0;
    for (Int_t iEntry=0; iEntry<t->GetEntries(); iEntry++){
        t->GetEntry(iEntry);
        if (wgtsData->GetEntryBinarySearch(UID)) {
            Double_t weight = wgtsData->GetWeight("Acc");
            // Double_t weight = Weight;
            if (weight!=0.0) {
                hMassEtaSidebandSubtracted->Fill(massEta,weight);
                hMassPi0SidebandSubtracted->Fill(massPi0,weight);
                hcosThetaEtaHelSidebandSubtracted->Fill(in_cosTheta_eta_hel,weight);
                hphiEtaHelSidebandSubtracted->Fill(in_phi_eta_hel,weight);
                hPhiSidebandSubtracted->Fill(in_Phi,weight);
            }
            counter++;
        }
    }
    cout << "Number of entries: " << counter << endl;

    TCanvas *c_sideband_subtracted = new TCanvas("c_sideband_subtracted","c_sideband_subtracted",1200,600);
    c_sideband_subtracted->Divide(3,2);

    c_sideband_subtracted->cd(1);
    hMassEtaSidebandSubtracted->Draw();
    hMassEtaSidebandSubtracted->GetYaxis()->SetRangeUser(hMassEtaSidebandSubtracted->GetMinimum()*1.1,hMassEtaSidebandSubtracted->GetMaximum()*1.1);
    hMassEtaSidebandSubtracted->SetLineColor(kRed);
    hMassEtaSidebandSubtracted->SetMarkerColor(kRed);
    c_sideband_subtracted->cd(2);
    hMassPi0SidebandSubtracted->Draw();
    hMassPi0SidebandSubtracted->GetYaxis()->SetRangeUser(hMassPi0SidebandSubtracted->GetMinimum()*1.1,hMassPi0SidebandSubtracted->GetMaximum()*1.1);
    hMassPi0SidebandSubtracted->SetLineColor(kRed);
    hMassPi0SidebandSubtracted->SetMarkerColor(kRed);
    c_sideband_subtracted->cd(3);
    hcosThetaEtaHelSidebandSubtracted->Draw();
    hcosThetaEtaHelSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hcosThetaEtaHelSidebandSubtracted->GetMaximum()*1.1);
    hcosThetaEtaHelSidebandSubtracted->SetLineColor(kRed);
    hcosThetaEtaHelSidebandSubtracted->SetMarkerColor(kRed);
    c_sideband_subtracted->cd(4);
    hphiEtaHelSidebandSubtracted->GetXaxis()->SetTitle("#phi_{#eta}^{hel} [rad]");
    hphiEtaHelSidebandSubtracted->Draw();
    hphiEtaHelSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hphiEtaHelSidebandSubtracted->GetMaximum()*1.1);
    hphiEtaHelSidebandSubtracted->SetLineColor(kRed);
    hphiEtaHelSidebandSubtracted->SetMarkerColor(kRed);
    c_sideband_subtracted->cd(5);
    hPhiSidebandSubtracted->GetXaxis()->SetTitle("#Phi [rad]");
    hPhiSidebandSubtracted->Draw();
    hPhiSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hPhiSidebandSubtracted->GetMaximum()*1.1);
    hPhiSidebandSubtracted->SetLineColor(kRed);
    hPhiSidebandSubtracted->SetMarkerColor(kRed);
    
    c_sideband_subtracted->SaveAs(outDir+"c_sideband_subtracted.pdf");
    
}