set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'quadro_1.eps'

set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle
unset key

set size 1.0, 1.0
set origin 0.0, 0.0
set multiplot


#  caos
set size 0.5,0.5
set origin 0.0,0.5

set object 1 rect from 3.83,0.45 to 3.86,0.55
plot"vicinocaos"

#  isola2
set size 0.5,0.5
set origin 0.0,0.0

set xtics 0.005
set mxtics 5
set ytics 0.01
set mytics 5
set object 1 rect from 3.85361,0.4511 to 3.85412,0.452693 

plot[3.845:3.86][0.45:0.48]"vicinocaos2"

# isola1
set size 0.5,0.5
set origin 0.5,0.5

set xtics 0.005
set mxtics 5
set ytics 0.05
set mytics 5
set object 1 rect from 3.845,0.45 to 3.86,0.48
plot[3.83:3.86][0.45:0.55]"vicinocaos"

#
#  isolaisola
set origin .5,0.

set xtics 0.0001
set mxtics 5
set ytics 0.0005
set mytics 5
 

plot[3.85361:3.854][0.4511:0.4527]"vicinocaos3"

unset multiplot

set output
!epstopdf quadro_1.eps && rm quadro_1.eps

