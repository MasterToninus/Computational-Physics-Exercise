set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro.eps'


set xlabel "x0"

reset
set style data  lines
set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot
unset key


#   1
set size 0.5,0.5
set origin 0.0,0.5

set xlabel "x0"
set ylabel  "x1"
plot[0:1][0:1]   "n=1" ls 3, x ls -0


#   3
set size 0.5,0.5
set origin 0.0,0.0

set xlabel "x0"
set ylabel  "x3"
plot[0:1][0:1]   "n=3" ls 3, x ls -0

#  2
set size 0.5,0.5
set origin 0.5,0.5

set xlabel "x0"
set ylabel  "x2"
plot[0:1][0:1]   "n=2" ls 3, x ls -0

#
#  Spettro Pendolo 4
set origin .5,0.

set xlabel "x0"
set ylabel  "x4"
plot[0:1][0:1]   "n=4" ls 3, x ls -0


unset multiplot

set output
!epstopdf quadro.eps && rm quadro.eps

