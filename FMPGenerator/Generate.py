import GenerateFuncImpl as fi
import GenerateNodeFunc as nf
import GenerateLemonCode as lc
import os
import sys

args = sys.argv

fi.GenerateFuncImpl(args[1])
nf.GenerateNodeFunc(args[1])
lc.GenerateLemonCode(args[2])