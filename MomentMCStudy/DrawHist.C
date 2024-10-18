

void DrawHist(const TString dataPath="/d/home/septian/EtaPi0Analysis/MomentMCStudy/data_sig_bkg.root")
{
    gStyle->SetOptStat(0);
    const TString outDir = "/d/home/septian/EtaPi0Plot/";
    TFile *f = TFile::Open(dataPath);
    TDirectoryFile *dir = (TDirectoryFile*)f->Get("Histograms");
    
    TH1D *hMassEtaSig = (TH1D*)dir->Get("hMassEtaSig");
    TH1D *hMassPi0Sig = (TH1D*)dir->Get("hMassPi0Sig");
    TH1D *hcosThetaEtaHelSig = (TH1D*)dir->Get("hcosThetaEtaHelSig");
    TH1D *hphiEtaHelSig = (TH1D*)dir->Get("hphiEtaHelSig");
    TH1D *hPhiSig = (TH1D*)dir->Get("hPhiSig");

    TH1D *hMassEtaSigBkg = (TH1D*)dir->Get("hMassEtaSigBkg");
    TH1D *hMassPi0SigBkg = (TH1D*)dir->Get("hMassPi0SigBkg");
    TH1D *hcosThetaEtaHelSigBkg = (TH1D*)dir->Get("hcosThetaEtaHelSigBkg");
    TH1D *hphiEtaHelSigBkg = (TH1D*)dir->Get("hphiEtaHelSigBkg");
    TH1D *hPhiSigBkg = (TH1D*)dir->Get("hPhiSigBkg");

    TH1D *hMassEtaSidebandSubtracted = (TH1D*)dir->Get("hMassEtaSidebandSubtracted");
    TH1D *hMassPi0SidebandSubtracted = (TH1D*)dir->Get("hMassPi0SidebandSubtracted");
    TH1D *hcosThetaEtaHelSidebandSubtracted = (TH1D*)dir->Get("hcosThetaEtaHelSidebandSubtracted");
    TH1D *hphiEtaHelSidebandSubtracted = (TH1D*)dir->Get("hphiEtaHelSidebandSubtracted");
    TH1D *hPhiSidebandSubtracted = (TH1D*)dir->Get("hPhiSidebandSubtracted");

    TCanvas *c_signal = new TCanvas("c_signal","c_signal",1200,600);
    c_signal->Divide(3,2);

    c_signal->cd(1);
    hMassEtaSig->Draw();
    c_signal->cd(2);
    hMassPi0Sig->Draw();
    c_signal->cd(3);
    hcosThetaEtaHelSig->Draw();
    c_signal->cd(4);
    hphiEtaHelSig->GetXaxis()->SetTitle("#phi_{#eta}^{hel} [rad]");
    hphiEtaHelSig->Draw();
    c_signal->cd(5);
    hPhiSig->GetXaxis()->SetTitle("#Phi [rad]");
    hPhiSig->Draw();

    c_signal->SaveAs(outDir+"c_signal.pdf");

    TCanvas *c_signal_bkg = new TCanvas("c_signal_bkg","c_signal_bkg",1200,600);
    c_signal_bkg->Divide(3,2);

    TLegend *leg = new TLegend(0.4,0.75,0.6,0.9);

    c_signal_bkg->cd(1);
    hMassEtaSigBkg->GetYaxis()->SetRangeUser(0,hMassEtaSigBkg->GetMaximum()*1.1);
    hMassEtaSigBkg->SetLineColor(kRed);
    hMassEtaSigBkg->Draw();
    hMassEtaSig->Draw("SAME");
    c_signal_bkg->cd(2);
    hMassPi0SigBkg->GetYaxis()->SetRangeUser(0,hMassPi0SigBkg->GetMaximum()*1.1);
    hMassPi0SigBkg->SetLineColor(kRed);
    hMassPi0SigBkg->Draw();
    hMassPi0Sig->Draw("SAME");
    c_signal_bkg->cd(3);
    hcosThetaEtaHelSigBkg->GetYaxis()->SetRangeUser(0,hcosThetaEtaHelSigBkg->GetMaximum()*1.1);
    hcosThetaEtaHelSigBkg->SetLineColor(kRed);
    hcosThetaEtaHelSigBkg->Draw();
    hcosThetaEtaHelSig->Draw("SAME");
    c_signal_bkg->cd(4);
    hphiEtaHelSigBkg->GetYaxis()->SetRangeUser(0,hphiEtaHelSigBkg->GetMaximum()*1.1);
    hphiEtaHelSigBkg->GetXaxis()->SetTitle("#phi_{#eta}^{hel} [rad]");
    hphiEtaHelSigBkg->SetLineColor(kRed);
    hphiEtaHelSigBkg->Draw();
    hphiEtaHelSig->Draw("SAME");
    c_signal_bkg->cd(5);
    hPhiSigBkg->GetYaxis()->SetRangeUser(0,hphiEtaHelSigBkg->GetMaximum()*1.1);
    hPhiSigBkg->GetXaxis()->SetTitle("#Phi [rad]");
    hPhiSigBkg->SetLineColor(kRed);
    hPhiSigBkg->Draw();
    hPhiSig->Draw("SAME");
    leg->AddEntry(hPhiSig,"Signal","l");
    leg->AddEntry(hPhiSigBkg,"Signal+Bkg","l");
    leg->Draw();

    c_signal_bkg->SaveAs(outDir+"c_signal_bkg.pdf");

    TCanvas *c_sideband_subtracted = new TCanvas("c_sideband_subtracted","c_sideband_subtracted",1200,600);
    c_sideband_subtracted->Divide(3,2);

    c_sideband_subtracted->cd(1);
    hMassEtaSidebandSubtracted->Draw();
    hMassEtaSidebandSubtracted->GetYaxis()->SetRangeUser(hMassEtaSidebandSubtracted->GetMinimum()*1.1,hMassEtaSidebandSubtracted->GetMaximum()*1.1);
    hMassEtaSidebandSubtracted->SetLineColor(kRed);
    hMassEtaSidebandSubtracted->SetMarkerColor(kRed);
    hMassEtaSig->Draw("SAME");
    c_sideband_subtracted->cd(2);
    hMassPi0SidebandSubtracted->Draw();
    hMassPi0SidebandSubtracted->GetYaxis()->SetRangeUser(hMassPi0SidebandSubtracted->GetMinimum()*1.1,hMassPi0SidebandSubtracted->GetMaximum()*1.1);
    hMassPi0SidebandSubtracted->SetLineColor(kRed);
    hMassPi0SidebandSubtracted->SetMarkerColor(kRed);
    hMassPi0Sig->Draw("SAME");
    c_sideband_subtracted->cd(3);
    hcosThetaEtaHelSidebandSubtracted->Draw();
    hcosThetaEtaHelSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hcosThetaEtaHelSidebandSubtracted->GetMaximum()*1.1);
    hcosThetaEtaHelSidebandSubtracted->SetLineColor(kRed);
    hcosThetaEtaHelSidebandSubtracted->SetMarkerColor(kRed);
    hcosThetaEtaHelSig->Draw("SAME");
    c_sideband_subtracted->cd(4);
    hphiEtaHelSidebandSubtracted->GetXaxis()->SetTitle("#phi_{#eta}^{hel} [rad]");
    hphiEtaHelSidebandSubtracted->Draw();
    hphiEtaHelSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hphiEtaHelSidebandSubtracted->GetMaximum()*1.1);
    hphiEtaHelSidebandSubtracted->SetLineColor(kRed);
    hphiEtaHelSidebandSubtracted->SetMarkerColor(kRed);
    hphiEtaHelSig->Draw("SAME");
    c_sideband_subtracted->cd(5);
    hPhiSidebandSubtracted->GetXaxis()->SetTitle("#Phi [rad]");
    hPhiSidebandSubtracted->Draw();
    hPhiSidebandSubtracted->GetYaxis()->SetRangeUser(0.0,hPhiSidebandSubtracted->GetMaximum()*1.1);
    hPhiSidebandSubtracted->SetLineColor(kRed);
    hPhiSidebandSubtracted->SetMarkerColor(kRed);
    hPhiSig->Draw("SAME");

    leg->Clear();
    leg->SetX1NDC(0.35);
    leg->SetX2NDC(0.65);
    leg->SetY1NDC(0.15);
    leg->SetY2NDC(0.3);
    leg->AddEntry(hPhiSig,"Signal","l");
    leg->AddEntry(hPhiSidebandSubtracted,"Signal+Bkg-Sideband","lp");
    leg->Draw();
    
    c_sideband_subtracted->SaveAs(outDir+"c_sideband_subtracted.pdf");
    
}