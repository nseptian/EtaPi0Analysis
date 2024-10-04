#!/bin/bash

# Navigate to the directory containing the DrawMoments.C file
cd /d/home/septian/EtaPi0Analysis/MomentMCStudy/

# Start ROOT and compile the macro
root -l <<EOF
.L DrawMoments.C+
DrawMoments()
.q
EOF