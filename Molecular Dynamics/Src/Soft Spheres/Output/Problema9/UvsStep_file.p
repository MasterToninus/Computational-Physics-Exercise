clear
reset


set xlabel "tempo [t]" font "Times-Italic,24" offset 0,0.5
	set xrange [0: 600]

set ylabel " U*/N istantaneo" font "Times-Italic,24" offset 1.5,0 #rotate by 0
#	set yrange [-0.02:2.5]


plot 'UvsStep_N108.dat' title "U istantaneo N 108" w l	lc 1
replot 'UvsStep_N500.dat' title "U istantaneo N 500" w l	lc 2


replot -3.49772 title "U media N 108"
replot -3.48813 title "U media N 500"




set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'UvsStep.eps'
replot
set output '|epstopdf  UvsStep.eps'

set term x11
set output
