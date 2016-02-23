set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadrodispense.eps'


set xlabel "x0"

reset
set style data  lines
set size 1.0, 0.5
set origin 0.0, 0.0
set multiplot
unset key


#   1
set size 0.5,0.5
set origin 0.0,0.0

set xlabel "x0"
set ylabel  "x2"
plot[0:1][0:0.85]   "r= 2.99" lw 2.5 lc 7, x lw 1.5 lc 1




#
#  Spettro Pendolo 4
set origin 0.5,0.

set xlabel "x0"
set ylabel  "x2"
plot[0:1][0:0.85]   "r= 3.2" lw 2.5 lc 7, x lw 1.5 lc 1


unset multiplot

set output
!epstopdf quadrodispense.eps && rm quadrodispense.eps

