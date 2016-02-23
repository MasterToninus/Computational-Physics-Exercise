set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_1.eps'

set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle

unset ytics 
set xtics 0.005
unset mxtics
set key left

set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot

#
#  zoom1
set size 0.5,0.5
set origin 0.0,0.5

set xtics 0.02
set mxtics 4
set ytics 0.1
set mytics 5
plot[3.445:3.57][0.3:0.6]"zoom1" ls 3

#
#  zoom3
set size 0.5,0.5
set origin 0.0,0.0

set xtics 0.001
set mxtics 5
set ytics 0.01
set mytics 5
plot[3.5635:3.57][0.47:0.51]"zoom3" ls 3

#
# zoom2
set size 0.5,0.5
set origin 0.5,0.5

set xtics 0.005
set mxtics 5
set ytics 0.02
set mytics 4
plot[3.5435:3.57][0.46:0.58]"zoom2" ls 3

#
#  zoom4
set origin .5,0.

set xtics 0.0002
set mxtics 4
set ytics 0.005
set mytics 5
plot[3.5687:3.57][0.495:0.512]"zoom4" ls 3

unset multiplot

set output
!epstopdf quadro_1.eps && rm quadro_1.eps

