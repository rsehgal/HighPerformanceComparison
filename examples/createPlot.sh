#!/bin/sh
paste timing.txt timingHeap.txt > comb.txt
/usr/bin/gnuplot plot.gnu
