#!/bin/sh
paste timingDaxpy.txt timingHeapDaxpy.txt > comb.txt
/usr/bin/gnuplot plot.gnu
