set term postscript eps enhanced color solid rounded
set output 'mappa_2.eps'

set pointsize 0.7
set xlabel "parametro r"
set ylabel "Xn"
set notitle

plot"caos"
set output
!epstopdf mappa_2.eps && rm mappa_2.eps

