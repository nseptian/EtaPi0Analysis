string ofolder="/d/home/septian/EtaPi0Analysis/run/rootFiles/brufit_data/";
string ifolder="/d/home/septian/EtaPi0Analysis/run/rootFiles/";
const Bool_t isSplitDataD = kFALSE;
const Bool_t isSplitBkgndD = kFALSE;
const Bool_t isSplitAccD = kTRUE;
const Bool_t isSplitDataMC = kFALSE;
const Bool_t isSplitBkgndMC = kFALSE;
const Bool_t isSplitAccMC = kTRUE;
const Bool_t isSplitGenMC = kFALSE;

bool filterOmega(float omega, float Mpi0eta){
    // omega should be in degrees and mass in GeV
    return -29.0*atan(-1.05*Mpi0eta+2.78)+328 > omega;
}

void split_flat_kinematics(string otag="", string itag=""){
    // ********************************************
    // THIS PROGRAM WILL SPLIT ROOT FILES INTO DIFFERENT BEAM ENERGY + T BINNINGS
    //    BOTH THE THROWN AND RECON VALUES WILL BE USED IN DETERMINING BINNING 
    //    IF THEY EXISTS. 
    //    I.E. RECONSTRUCTED MC WOULD HAVE BOTH.
    //         DATA WOULD ONLY HAVE RECON
    //         THROWN MC WOULD HAVE ONLY THROWN VALUES
    //    BY DEFAULT THERE IS ALWAYS A BINNING INTO SEPARATE POLARIZATIONS WHICH
    //         USED FOR AMPLITUDE FITS WITH POLARIZATION
    // ********************************************

    bool sumRuns=true;
    bool forceSplitting=true; // Should we run the splitting again? Or should we just sum runs if sumRuns=true
    bool remergePols=true; // should we remerge polarizations after splitting? 
    bool brufit_data=true;
    
    otag="Phase1_brufit";
    itag="nominal_wPhotonSyst";

    ifolder="/d/grid17/ln16/dselector_v3/phase1_selected_v4/";
    ofolder="/d/home/septian/EtaPi0Analysis/run/rootFiles/";
    vector<string> runs={"2017_1","2018_1","2018_8"};

    // string ifolder="/d/home/septian/EtaPi0Analysis/run/rootFiles/";
    bool ignorePolarization=false; // Kmatrix stuff has only one polarization, so ignore. No polarization in Flat MC so ignore also
    // vector<string> runs={"2019_11"};//{"2018_8"},"2018_1","2018_8"};
    vector<string> files;
    for (auto run: runs){
        if (isSplitDataD) files.push_back("D"+run+"_selected_"+itag+"_data_flat.root");
        if (isSplitBkgndD) files.push_back("D"+run+"_selected_"+itag+"_bkgnd_flat.root");
        if (isSplitAccD) files.push_back("D"+run+"_selected_"+itag+"_acc_flat.root");
        if (isSplitDataMC) files.push_back("F"+run+"_selected_"+itag+"_data_flat.root");
        if (isSplitBkgndMC) files.push_back("F"+run+"_selected_"+itag+"_bkgnd_flat.root");
        if (isSplitAccMC) files.push_back("F"+run+"_selected_"+itag+"_acc_flat.root");
        if (isSplitGenMC) files.push_back("F"+run+"_gen_data_flat.root");
        // files.push_back("D"+run+"_selected"+itag+"_acc_flat.root");
        // files.push_back("F"+run+"_selected"+itag+"_acc_flat.root");
        // files.push_back("F"+run+"_gen_data_flat.root");
        
        //files.push_back("K"+run+"_selected"+itag+"_data_flat.root");
        //files.push_back("K"+run+"_selected"+itag+"_bkgnd_flat.root");
        // files.push_back("F"+run+"_selected"+itag+"_acc_flat.root");
        // files.push_back("F"+run+"_selected"+itag+"_MC_acc_flat.root");
        // files.push_back("F"+run+"_gen_data_flat.root");
    }

    // ********************************************
    // HERE IS ALL THE BINNINGS WE WILL LOOP OVER
    // ********************************************
    int nFileTypes=((int)files.size())/((int)runs.size());

    map<int,int> pols={{0,0},{45,1},{90,2},{135,3},{-1,4}};//,{45,1},{90,2},{135,3},{-1,4}};
    vector<string> polstrings={"000","045","090","135","AMO"};//,"045","090","135","AMO"};

    map<string,int> ts={{"010020",0},{"0200325",1},{"0325050",2},{"050075",3},{"075100",4}}; // t 
    vector<float> mint={0.1,0.2,0.325,0.5,0.75}; // 
    vector<float> maxt={0.2,0.325,0.5,0.75,1.0}; //
    // map<string,int> ts={{"010020",0},{"020030",1},{"030040",2},{"040050",3},{"050060",4}}; // t 
    // vector<float> mint={0.1,0.2,0.3,0.4,0.5}; // 
    // vector<float> maxt={0.2,0.3,0.4,0.5,0.6}; // 
    map<string,int> mpi0etas={{"104172",0}}; // m 
    vector<float> minmpi0eta={1.04};
    vector<float> maxmpi0eta={1.72};
    // vector<float> minmpi0eta={0.0};
    // vector<float> maxmpi0eta={1.0};
    //map<string,int> ts={{"010100",1.0}}; // t
    // vector<float> mint={0};
    // vector<float> maxt={1.0};
    //map<string,int> mpi0etas={{"104156",0},{"104160",1},{"104164",2},{"104168",3},{"104172",4},{"104176",5},{"104180",6}}; // m 
    //vector<float> minmpi0eta={1.04,1.04,1.04,1.04,1.04,1.04,1.04};
    //vector<float> maxmpi0eta={1.56,1.60,1.64,1.68,1.72,1.76,1.80};

    const int nts=(const int)mint.size();
    const int nms=(const int)minmpi0eta.size();

    // ********************************************
    // CREATE SOME EXTRA FOLDERS FOR ORGANIZATION
    // ********************************************
    
    if (forceSplitting){
        for (auto const& t: ts){
            for (auto const& m: mpi0etas){
                string floc=ofolder+"t"+t.first+"_m"+m.first+"_"+otag+"/";
                gSystem->Exec(("mkdir -p "+floc).c_str()); } }

        for (auto file: files){
            cout << "================================================" << endl;
            cout << "FILE: " << file << endl;
            cout << "================================================" << endl;

            TFile *oldfile = new TFile((ifolder+file).c_str());
            TTree *oldtree = (TTree*)oldfile->Get("kin");
            Long64_t nentries = oldtree->GetEntries();

            // ********************************************
            /////// CREATE A BUNCH OF ROOT FILES AND TREES
            // ********************************************
            // The order of the array dimensions represents: #pols, #t, #e, #m
            TFile *newfile[5][nts][nms];
            TTree *newtree[5][nts][nms]; 
            int ip, it, im;
            ip=0;
            
            double cosTheta_eta_GJ;
            double phi_eta_GJ_rad;
            double Phi_rad;
            double TWeight;
            double DMpi0eta;

            for (auto const& pol: pols){ it=0;
                for (auto const& t: ts){ im=0;
                    for (auto const& m: mpi0etas){
                        string floc=ofolder+"t"+t.first+"_m"+m.first+"_"+otag+"/";
                        newfile[ip][it][im] = new TFile((floc+"pol"+polstrings[ip]+"_t"+t.first+"_m"+m.first+"_"+file).c_str(),"recreate");
                        if (!brufit_data) newtree[ip][it][im] = oldtree->CloneTree(0);
                        else {
                            newtree[ip][it][im] = new TTree("kin","kin");
                            newtree[ip][it][im]->Branch("cosTheta_eta_gj",&cosTheta_eta_GJ,"cosTheta_eta_gj/D");
                            newtree[ip][it][im]->Branch("phi_eta_gj",&phi_eta_GJ_rad,"phi_eta_gj/D");
                            newtree[ip][it][im]->Branch("Phi",&Phi_rad,"Phi/D");
                            newtree[ip][it][im]->Branch("Mpi0eta",&DMpi0eta,"Mpi0eta/D");
                            newtree[ip][it][im]->Branch("Weight",&TWeight,"Weight/D");
                        }
                        ++im;
                    } ++it;
                } ++ip;
            }

            // ********************************************
            /////// CHECKING TO WHICH BRANCHES EXIST - WHETHER DATA OR SIMULATIONS
            // ********************************************
            int BeamAngle;
            int beamAngle=0; // this is the angle that is actually used but will depend on ignorePolarization variable
            float mandelstam_t;
            float Ebeam;
            float mpi0eta;
            float mpi0p;
            float mandelstam_t_thrown;
            float Ebeam_thrown;
            float mpi0eta_thrown;
            float vanHove_omega;
            float VH;
            bool pVH;
            float pVH2;
            float cosTheta_eta_gj;
            float phi_eta_gj;
            float Phi;
            float weight;
            bool isCorrectCombo;
            // Check to see if we have the right branches for the different data,bkgnd,acc,gen trees
            //    Small caveat - thrown branches ALWAYS exist even for data,bkgnd trees but the branch will only contain 0s
            bool has_recon_branches = (bool)oldtree->GetListOfBranches()->FindObject("Ebeam"); // returned object decays to a boolean
            cout << "has proper recon branches: " << has_recon_branches << endl;
            
            oldtree->SetBranchAddress("BeamAngle",&BeamAngle);
            oldtree->SetBranchAddress("Weight",&weight);
            if (has_recon_branches){
                oldtree->SetBranchAddress("mandelstam_t",&mandelstam_t);
                oldtree->SetBranchAddress("Ebeam",&Ebeam);
                oldtree->SetBranchAddress("Mpi0eta",&mpi0eta);
                oldtree->SetBranchAddress("Mpi0p",&mpi0p);
                oldtree->SetBranchAddress("pVH",&VH);
                oldtree->SetBranchAddress("vanHove_omega",&vanHove_omega);
            }
            oldtree->SetBranchAddress("cosTheta_eta_gj",&cosTheta_eta_gj);
            oldtree->SetBranchAddress("phi_eta_gj",&phi_eta_gj);
            oldtree->SetBranchAddress("Phi",&Phi);
            oldtree->SetBranchAddress("Mpi0eta_thrown",&mpi0eta_thrown);
            oldtree->SetBranchAddress("mandelstam_t_thrown",&mandelstam_t_thrown);
            oldtree->SetBranchAddress("Ebeam_thrown",&Ebeam_thrown);
            oldtree->GetEntry(0);
            bool has_thrown_branches = (Ebeam_thrown!=0);
            cout << "has proper thrown branches: " << has_thrown_branches << endl;

            bool isData=!has_thrown_branches*has_recon_branches; // does not have thrown but has recon branches
            bool isAcc=has_recon_branches*has_thrown_branches; // has both recon and thrown branches
            bool isGen=!has_recon_branches*has_thrown_branches; // does not have recon branches but has thrown branches


            if (brufit_data*isAcc) oldtree->SetBranchAddress("isCorrectCombo",&isCorrectCombo);

            // ********************************************
            /////// FILL TREES IN THE CORRECT BINNING
            // ********************************************
            for (Long64_t i=0;i<nentries; i++) {
                 oldtree->GetEntry(i);
                 pVH=VH==1;
                 it=0;
                 if (!ignorePolarization)
                     beamAngle=BeamAngle;
                 for (auto const& t: ts){ im=-1;
                     for (auto const& m: mpi0etas){
                         ++im; // this has to be first otherwise it might never increment
                         //pVH2=filterOmega(vanHove_omega,mpi0eta);
                         //if (has_recon_branches*!pVH2) continue;
                         if (has_recon_branches*!pVH) continue;
                         //if (has_recon_branches*!(mpi0p>2.0)) continue;
                         if (has_recon_branches*!((mandelstam_t>mint[it])*(mandelstam_t<maxt[it]))) continue;
                         if (has_recon_branches*!((mpi0eta>minmpi0eta[im])*(mpi0eta<maxmpi0eta[im]))) continue;
                        //  if (has_recon_branches*!((Ebeam>8.2)*(Ebeam<8.6))) continue;
                        //  if (isAcc*!((Ebeam_thrown>8.2)*(Ebeam_thrown<8.6))) continue;
                         //if (has_thrown_branches*!((mandelstam_t_thrown>mint[it])*(mandelstam_t_thrown<maxt[it]))) continue;
                         //if (has_thrown_branches*!((mpi0eta_thrown>minmpi0eta[im])*(mpi0eta_thrown<maxmpi0eta[im]))) continue;
                         if (isGen*!((mandelstam_t_thrown>mint[it])*(mandelstam_t_thrown<maxt[it]))) continue;
                        //  cout << Ebeam_thrown << " " << mandelstam_t_thrown << " " << mpi0eta_thrown << " " << minmpi0eta[im] << endl;
                         if (isGen*!((mpi0eta_thrown>minmpi0eta[im])*(mpi0eta_thrown<maxmpi0eta[im]))) continue;
                        //  if (isGen*!((Ebeam_thrown>8.2)*(Ebeam_thrown<8.6))) continue;
                        //  check if weight is nan
                        if( weight != weight ) {
                            cout << "there is a nan weight =" << weight << endl;
                            weight = 0.0;
                            continue;
                        }
                        if (brufit_data*isAcc*!isCorrectCombo) continue;
                        TWeight = weight;
                        cosTheta_eta_GJ = cosTheta_eta_gj;
                        phi_eta_GJ_rad = phi_eta_gj*3.14159265358979323846/180.0;
                        Phi_rad = Phi*3.14159265358979323846/180.0;
                        DMpi0eta = mpi0eta;
                        newtree[pols[beamAngle]][it][im]->Fill();
                     } ++it;
                 }
            }


            // ********************************************
            /////// WRITE TREES TO THEIR ASSOCIATED FILES
            // ********************************************
            int post_nentries=0;
            int tmp_nentries;
            cout << "pols size = " << pols.size() << endl;
            for (int ip=0; ip<(int)pols.size(); ++ip){
                for (int it=0; it<(int)ts.size(); ++it){
                    for (int im=0; im<(int)mpi0etas.size(); ++im){
                        cout << ip << endl;
                        newfile[ip][it][im]->cd();
                        newtree[ip][it][im]->Write();
                        tmp_nentries=newtree[ip][it][im]->GetEntries();
                        post_nentries+=tmp_nentries;
                        cout << "Entries in [pol,tbin,mbin=" << polstrings[ip] << "," << it << "," << im << "] = " << tmp_nentries << endl;
                        newfile[ip][it][im]->Close();
            }}}
        } // close the forceSplitting condition
        cout << "close the forceSplitting condition" << endl;
    } // closes files loop
    cout << "closes files loop" << endl;

    // ********************************************
    /////// COMPLICATED FUNCTION TO HADD FILES FROM DIFFERENT RUNS
    // We will loop through all runs and create new files with TOT replacing the run tag
    // We do this by creating a giant hadd string and executing the system command
    // ********************************************
    int ip, it, im;
    if (sumRuns){
        it=0;
        for (auto const& t: ts){ im=0;
            for (auto const& m: mpi0etas){ 
                for (int j=0; j<nFileTypes; ++j){ ip=0;
                    string remergePolCmd="hadd -f ";
                    remergePolCmd+=ofolder+"t"+t.first+"_m"+m.first+"_"+otag+"/"+"polALL_t"+t.first+"_m"+m.first+"_"+otag+"_";
                    remergePolCmd+=files[j][0]+(string)"TOT"+files[j].substr(runs[0].size()+1,files[j].size());
                    for (auto const& pol: pols){
                        string cmd;
                        string target;
                        for (int i=0; (int)i<runs.size(); ++i){
                            if (i==0){
                                target=ofolder+"t"+t.first+"_m"+m.first+"_"+otag+"/"+"pol"+polstrings[ip]+"_t"+t.first+"_m"+m.first+"_"+otag+"_";
                                target+=files[j][0]+(string)"TOT"+files[j].substr(runs[0].size()+1,files[j].size());
                                cmd="hadd -f "+target;
                            }
                            cmd+=" "+ofolder+"t"+t.first+"_m"+m.first+"_"+otag+"/"+"pol"+polstrings[ip]+"_t"+t.first+"_m"+m.first+"_"+files[nFileTypes*i+j];
                        }
                        cout << endl << cmd << endl;
                        gSystem->Exec(cmd.c_str()); 
                        remergePolCmd+=" "+target;
                        ++ip;
                    }
                    if (remergePols){
                        cout << "\n---- REMERGING POLS ----\n" << remergePolCmd << endl;
                        gSystem->Exec(remergePolCmd.c_str()); 
                        cout << endl;
                    }
                } 
                ++im;
            } ++it;
        }
    }
}
