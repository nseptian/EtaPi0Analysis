#!/bin/bash

# Navigate to the directory containing the DrawMoments.C file
cd /d/home/septian/EtaPi0Analysis/MomentMCStudy/

# Start ROOT and compile the macro
root -l <<EOF
.L DrawMoments.C+
DrawMoments("/d/grid17/septian/EtaPi0Analysis/MomentMCStudy/fitBruMomentsPerfectAcceptance/ResultsHSMinuit2.root","GlueXAcceptance")
.q
EOF

# DrawMoments("/d/grid17/septian/EtaPi0Analysis/MomentMCStudy/fitBruMomentsLM4/ResultsHSMinuit2.root")
# DrawMoments("/d/grid17/septian/EtaPi0Analysis/MomentMCStudy/fitBruMomentsGlueXAcceptance/ResultsHSMinuit2.root")