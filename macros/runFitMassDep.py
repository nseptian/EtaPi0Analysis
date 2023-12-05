#!/d/home/septian/anaconda3/bin/python

import os
import sys
import numpy as np
import subprocess
import random
import time
import argparse
from checkCfgFile import checkCfgFile

def has_numbers(inputString):
    return any(char.isdigit() for char in inputString)

def spawnProcessChangeSetting(old,new):
    '''
    Replace the value of varName to varValue in the file called fileName. Depending on the value type we can include quotes or not
    '''
    sedArgs=["sed","-i","s@"+old+"@"+new+"@g","setup_mass_dep_fits.py"]
    print(" ".join(sedArgs))
    subprocess.Popen(sedArgs, stdout=subprocess.PIPE, stderr=subprocess.STDOUT).wait()


def replaceStr(search,replace,fileName):
    print("replace str: "+replace)
    sedArgs=["sed","-i",'s@'+search+'@'+replace+'@g',fileName]
    subprocess.Popen(sedArgs, stdout=subprocess.PIPE, stderr=subprocess.STDOUT).wait()

def main():
    parser = argparse.ArgumentParser(description='Run mass dependent fits')
    parser.add_argument('--tag', type=str, required=True, help='tag for the output folder')
    args = parser.parse_args()
    tag=args.tag
    ##########################################
    # Basic setup
    ##########################################
    nprocesses=30
    fitFileName="etapi_result.fit"
    niters=[1,1] # [n,m] where n is #restarts and m is #iters per restart. In total we should have n*m iterations 
    workingDir=os.getcwd()

    # ts=["010020"] #
    # tmins=[0.1] #
    # tmaxs=[0.2] #

    # ts=["0200325"] #
    # tmins=[0.2] #
    # tmaxs=[0.325] #

    # ts=["0325050"] #
    # tmins=[0.325] #
    # tmaxs=[0.5] #

    # ts=["0325050","050075","075100"] #
    # tmins=[0.325,0.5,0.75] #
    # tmaxs=[0.5,0.75,1.0] #

    ts=["010020","0200325","0325050","050075","075100"] #
    tmins=[0.1,0.2,0.325,0.5,0.75] #
    tmaxs=[0.2,0.325,0.5,0.75,1.0] #
    # ts=["010020","020030","030040","040050","050060"] #
    # tmins=[0.1,0.2,0.3,0.4,0.5] #
    # tmaxs=[0.2,0.3,0.4,0.5,0.6] #
    ms=["104172"]
    mmins=[1.04]
    mmaxs=[1.72]
    pcwsBins=[17]
    #ms=["104156","104160","104164","104168","104172","104176","104180"]
    #mmins=[1.04,1.04,1.04,1.04,1.04,1.04,1.04]
    #mmaxs=[1.56,1.60,1.64,1.68,1.72,1.76,1.80]
    # pcwsBins=[13,14,15,16,17,18,19]

    baseCfgFile="/d/home/septian/EtaPi0Analysis/cfg/etapi_hybrid_full.cfg"
    # baseCfgFile="config_files/etapi_hybrid.cfg"
    
    baseFitDir="/d/home/septian/EtaPi0Analysis/run/mass_dependent_fits/"
    pycmd = "/d/home/septian/anaconda3/bin/python"
    setupcmd = "/d/home/septian/EtaPi0Analysis/macros/setup_mass_dep_fits.py"

    for i in range(niters[0]):
        for j, tmin, tmax in zip(range(len(ts)),tmins,tmaxs):
            t=ts[j]
        
            for ic,m,mmin,mmax,pcwsBin in zip(range(len(ms)),ms,mmins,mmaxs,pcwsBins):
                ofolder="/d/home/septian/EtaPi0Analysis/run/mass_dependent_fits/"+t+"_"+tag+"_"+str(i)
                os.system("mkdir -p "+ofolder)
                os.chdir(ofolder)
                os.system("rm -f "+fitFileName)
                os.system("rm -f fit*log")
                
                cfgFile=baseCfgFile.split("/")[-1].split(".")[0]+"_"+"m"+m+"_t"+t+"_"+tag
                setup_seed=-1
                cmd=f'{pycmd} {setupcmd} {baseCfgFile} {setup_seed} {pcwsBin} {mmin} {mmax} {tmin} {tmax} {tag} {t} {m}'
                print(cmd)
                os.system(cmd) # reinitialize
        
                if not checkCfgFile(cfgFile+".cfg"): 
                    print("\n**** SOMETHING WRONG WITH CONFIG! SEE ABOVE. EXITING ****\n")
                    exit(1)

                ### THIS IS USEFUL IF YOU WANT TO WRITE CFG FILES TO THIS DIRECTORY FOR MALTE ###
#                os.system(f'mv {cfgFile+".cfg"} {"etapi_hybrid_t"+t+"_m"+m+".cfg"}')
                #################################################################################
        
                print("Starting fits")
                # cmd="mpirun -np "+str(nprocesses)+" fitMPI -n -H -c "+cfgFile+".cfg -r "+str(niters[1])+" -m 1000000 -t 1.0 -x 1 -f 0.15" 
                cmd="mpirun -np "+str(nprocesses)+" fitMPI -c "+cfgFile+".cfg -r "+str(niters[1])+" -m 1000000 -t 1.0 -x 1 -f 0.15" 

                pipeCmd=' > fit.log'
                # cmd="fit -c "+cfgFile+".cfg -r "+str(niters[1])+" -m 1000000 -t 1.0 -x 1 -f 0.15"
                # cmd="mpirun -np "+str(nprocesses)+" fitMPI -c "+cfgFile+".cfg -r "+str(niters[1])+" -m 1000000 -t 1.0 -x 1 -f 0.15" 
                # pipeCmd=''
                print(cmd+pipeCmd)
                os.system(cmd+pipeCmd)
               
                # Move results to the desired folder
                # os.system("mv -f etapi_result*.fit "+ofolder+" 2>/dev/null")
                # os.system("mv -f "+cfgFile+"*.cfg "+ofolder+" 2>/dev/null")
                # os.system("mv -f *.log "+ofolder+" 2>/dev/null")
                # os.system("mv -f *.ni "+ofolder+" 2>/dev/null")
                #os.system("ln -snfr rootFiles "+ofolder+"/rootFiles")
        
            # _j=j+1 if j!=len(ts)-1 else 0
            # spawnProcessChangeSetting(ts[j],ts[_j]) # prepare for new t bin
    

if __name__ == "__main__":
    start_time=time.time()
    main()
    stop_time=time.time()
    print(f"Total elapsed time: {stop_time-start_time}s or {(stop_time-start_time)/60}m")
    
