set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_1.eps'

set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle

unset ytics 
set xtics 0.005
unset mxtics
set grid
set key left

set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot


#  n=1000
set size 0.5,0.5
set origin 0.0,0.5

plot"n=1000" ls 1

#  n=15000
set size 0.5,0.5
set origin 0.0,0.0

plot"n=15000" ls 3

#
# n=5000
set size 0.5,0.5
set origin 0.5,0.5

plot"n=5000" ls 2

#
#  n=100000
set origin .5,0.

plot"n=100000" ls 0

unset multiplot

set output
!epstopdf quadro_1.eps && rm quadro_1.eps

