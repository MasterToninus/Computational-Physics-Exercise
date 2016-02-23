set term postscript eps enhanced color solid rounded

set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle
set key left

set xtics 0.001 
set grid xtics


 
set output 'zoomcaos.eps'
plot[3.568:3.572] "zoomcaos"
set output
!epstopdf zoomcaos.eps && rm zoomcaos.eps

