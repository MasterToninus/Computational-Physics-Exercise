set term postscript eps enhanced color solid rounded


set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle

 
set output 'zoom1.eps'
set xtics 0.02
set mxtics 4
set ytics 0.1
set mytics 5
plot[3.445:3.57][0.3:0.6]"zoom1" ls 3
set output
!epstopdf zoom1.eps && rm zoom1.eps

set output 'zoom2.eps'
set xtics 0.005
set mxtics 5
set ytics 0.2
set mytics 4
plot[3.5435:3.57][0.46:0.58]"zoom2" ls 3
set output
!epstopdf zoom2.eps && rm zoom2.eps

set output 'zoom3.eps'
set xtics 0.001
set mxtics 5
set ytics 0.01
set mytics 5
plot[3.5635:3.57][0.47:0.51]"zoom3" ls 3
set output
!epstopdf zoom3.eps && rm zoom3.eps

set output 'zoom4.eps'
set xtics 0.0002
set mxtics 4
set ytics 0.005
set mytics 5
plot[3.5687:3.57][0.495:0.512]"zoom4" ls 3
set output
!epstopdf zoom4.eps && rm zoom4.eps




