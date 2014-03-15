plot "comb.txt" using 1:2 title "Vector3DFast-With-DataArray" with lp,"comb.txt" using 1:3 title "Blaze-With-DataArray" with lp,"comb.txt" using 1:5 title "Vector3DFast-With-Heap" with lp,"comb.txt" using 1:6 title "Blaze-With-Heap" with lp
set xlabel "No. Of 3D Vector"
set ylabel "Time"
set title "Comparison of Vector3DFast and Blaze using SSE"
set term jpeg size 800,600
set output "daxpySSE.jpeg"
replot
