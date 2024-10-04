
void DoMomentFit()
{
    FitManager Fitter;// manage the fitting
    //set the output directory for the fit results files Results*.root
    Fitter.SetUp().SetOutDir("fitBruMomentsLM4/");

    //Use amlitude configue class to define model
    PhotoTwoSpin0Amps config("TestMomentFit");
    config.SetManager(&Fitter);
    //set data variables which must be in the input tree
    config.SetDecayAngleCosTh("cosTheta[0.21,-1,1]");
    config.SetDecayAnglePhi("phi[0.1,-3.14159,3.14159]");
    config.SetPolPhi("Phi[0.2,-3.14159,3.14159]");
    config.SetConstPolarisation("Pol[1.0]");

    Fitter.SetUp().SetIDBranchName("UID");
    // Fitter.Bins().LoadBinVar("Mpi0eta",17,1.04,1.72);
    Fitter.LoadSimulated("data","/d/home/septian/EtaPi0Analysis/run/fitBruMoments/plotsTestNizar/efficiencyReco.photoProd.root",config.GetName());
    Fitter.LoadData("data","/d/home/septian/EtaPi0Analysis/run/fitBruMoments/plotsTestNizar/intensity.photoProd.root");
    // Fitter.Data().LoadWeights("Acc","/d/grid17/septian/EtaPi0Analysis/run/rootFiles/t010020_m104172_Phase1_brufit/weights_polALL_t010020_m104172_Phase1_brufit_DTOT_selected_nominal_wPhotonSyst_acc_flat.root","weight");

    config.SetLmax(4);
    config.SetMmax(4);
    config.SetNrefl(2);

    config.ConfigureMoments();
    config.LoadModelPDF();

    Fitter.SetUp().AddFitOption(RooFit::PrintEvalErrors(-1));
    Fitter.SetUp().AddFitOption(RooFit::NumCPU(64));
    Fitter.SetUp().ErrorsWrong();
    Here::Go(&Fitter);

}

void TestMomentFit()
{
    DoMomentFit();
}