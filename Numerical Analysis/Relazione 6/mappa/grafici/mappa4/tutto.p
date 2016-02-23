set term postscript eps enhanced color solid rounded


set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle
unset key

set output 'caos.eps'
set object 1 rect from 3.83,0.45 to 3.86,0.55
plot"vicinocaos"
set output
!epstopdf caos.eps && rm caos.eps


set output 'isola.eps'

set xtics 0.005
set mxtics 5
set ytics 0.05
set mytics 5
set object 1 rect from 3.845,0.45 to 3.86,0.48
plot[3.83:3.86][0.45:0.55]"vicinocaos"
set output
!epstopdf isola.eps && rm isola.eps


set output 'isola2.eps'
set xtics 0.005
set mxtics 5
set ytics 0.01
set mytics 5
set object 1 rect from 3.85361,0.4511 to 3.85412,0.452693 

plot[3.845:3.86][0.45:0.48]"vicinocaos2"

set output
!epstopdf isola2.eps && rm isola2.eps

set output 'isolaisola.eps'
set xtics 0.0001
set mxtics 5
set ytics 0.0005
set mytics 5
 

plot[3.85361:3.854][0.4511:0.4527]"vicinocaos3"
set output
!epstopdf isolaisola.eps && rm isolaisola.eps

