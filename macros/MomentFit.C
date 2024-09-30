{
    FitManager Fitter;// manage the fitting
    //set the output directory for the fit results files Results*.root
    Fitter.SetUp().SetOutDir("fitBruMoments/");

    //Use amlitude configue class to define model
    PhotoTwoSpin0Amps config("PWA");
    config.SetManager(&Fitter);
    //set data variables which must be in the input tree
    config.SetDecayAngleCosTh("cosTheta_eta_gj[0.21,-1,1]");
    config.SetDecayAnglePhi("phi_eta_gj[0.0,-3.14159,3.14159]");
    config.SetPolPhi("Phi[0.2,-3.14159,3.14159]");
    config.SetConstPolarisation("Pol[0.4]");

    Fitter.SetUp().SetIDBranchName("UID");
    Fitter.LoadSimulated("kin","/d/home/septian/EtaPi0Analysis/run/rootFiles/t010020_m104172_Phase1_brufit/polALL_t010020_m104172_Phase1_brufit_FTOT_selected_nominal_wPhotonSyst_acc_flat.root",config.GetName());
    Fitter.LoadData("kin","/d/home/septian/EtaPi0Analysis/run/rootFiles/t010020_m104172_Phase1_brufit/polALL_t010020_m104172_Phase1_brufit_DTOT_selected_nominal_wPhotonSyst_acc_flat.root");
    Fitter.Data().LoadWeights("Acc","/d/grid17/septian/EtaPi0Analysis/run/rootFiles/t010020_m104172_Phase1_brufit/weights_polALL_t010020_m104172_Phase1_brufit_DTOT_selected_nominal_wPhotonSyst_acc_flat.root","weight");

    config.SetLmax(1);
    config.SetMmax(1);
    config.SetNrefl(1);

    config.ConfigureMoments();
    config.LoadModelPDF();

    Fitter.SetUp().AddFitOption(RooFit::PrintEvalErrors(-1));
    Fitter.SetUp().AddFitOption(RooFit::NumCPU(32));
    Fitter.SetUp().ErrorsWrong();
    Here::Go(&Fitter);
}