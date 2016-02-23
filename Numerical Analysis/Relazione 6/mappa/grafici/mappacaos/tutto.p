set term postscript eps enhanced color solid rounded
set output 'istocaos.eps'

set style data boxes
set xtics 0.1
set mxtics 5
set xlabel "Xn"
set ylabel "% di uscite"
set notitle

plot"istocaos"
set output
!epstopdf istocaos.eps && rm istocaos.eps


set output 'istocaoszoom.eps'
set xtics 0.02
set mxtics 2

plot[0.4:0.6]"istocaos"
set output
!epstopdf istocaoszoom.eps && rm istocaoszoom.eps

set output 'superisto.eps'
set xtics 0.1
set mxtics 5

set style data lines
plot[0:1][0:0.3]"superisto" using 1:2 smooth bezier
set output
!epstopdf superisto.eps && rm superisto.eps

