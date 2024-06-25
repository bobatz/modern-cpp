#!/bin/bash

wc -l data.dat
grep -G 'd[oa]lor' -c data.dat 
wc -w data.dat
grep -E '\bmol' -c data.dat
