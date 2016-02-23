set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro.eps'


#set xlabel "frequenza [Hz]"
#set ylabel  "|H(f)|"


reset
set style data impulses
set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot
set size 0.5,0.5
set origin 0.0,0.5


#  Spettro Pendolo 1


set pointsize 0.7

plot[0:0.8][0:400]   "spettro_pendolo1" ls 1


#  Spettro Pendolo 3
set size 0.5,0.5
set origin 0.0,0.0
set pointsize 0.7
plot[0:0.8][0:400]   "spettro_pendolo3" ls 3

# Spettro Pendolo 2
set size 0.5,0.5
set origin 0.5,0.5


set pointsize 0.7
plot[0:0.8][0:400]   "spettro_pendolo2" ls 2


#
#  Spettro Pendolo 4
set origin .5,0.


set pointsize 0.7
plot[0:0.8][0:400]   "spettro_pendolo4" ls 5

unset multiplot

set output
!epstopdf quadro.eps && rm quadro.eps

