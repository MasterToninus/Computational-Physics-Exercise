#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 10 bo border -1
unset border

set xlabel "Tempo Collisione [t]"
 set xrange [0:0.0001]

set ylabel "P(|Tc|)"
# set yrange [-2:2]

	plot    "DistroTc_0.dat" title 'eta = 0.72' with boxes #Solido
	replot	"DistroTc_1.dat" title 'eta = 0.62' with boxes 
	replot	"DistroTc_2.dat" title 'eta = 0.52' with boxes # MetaS 
	replot	"DistroTc_3.dat" title 'eta = 0.42' with boxes 
	replot	"DistroTc_4.dat" title 'eta = 0.32' with boxes #Liquido

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'distroTc2D.eps'
replot
set output '|epstopdf  distroTc2D.eps'

set term x11
set output

