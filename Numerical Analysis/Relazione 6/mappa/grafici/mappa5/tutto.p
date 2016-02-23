set term postscript eps enhanced color solid rounded


set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle

unset ytics 
set xtics 0.005
unset mxtics
set grid
set key left
 
set output 'n=1000.eps'
plot"n=1000" ls 1
set output
!epstopdf n=1000.eps && rm n=1000.eps

set output 'n=5000.eps'
plot"n=5000" ls 2
set output
!epstopdf n=5000.eps && rm n=5000.eps

set output 'n=15000.eps'
plot"n=15000" ls 3
set output
!epstopdf n=15000.eps && rm n=15000.eps

set output 'n=100000.eps'
plot"n=100000" ls 0
set output
!epstopdf n=100000.eps && rm n=100000.eps



set output 'confronto_n.eps'
plot"n=1000","n=5000","n=15000","n=100000" ls 0
set output
!epstopdf confronto_n.eps && rm confronto_n.eps


