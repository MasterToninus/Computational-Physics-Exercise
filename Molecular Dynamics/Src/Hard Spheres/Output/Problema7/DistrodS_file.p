#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 4 noborder
unset border

L=1
set xlabel "Spostamento dS" font "Times-Italic,24" offset 0,0.5
	set xrange [0:sqrt(3)*L/2]

set ylabel "g_t( dS )" font "Times-Italic,24" offset 1.5,0
 set yrange [0:40]
set ytics 10

plot    "DistrodS_eta0.dat" title '{/Symbol h} = 0.62' with boxes lt 1 lc 1 lw 0.8
replot	"DistrodS_eta1.dat" title '{/Symbol h} = 0.52' with boxes  lt 1 lc 2 lw 0.8
replot	"DistrodS_Meta0.dat" title '{/Symbol h} = 0.505' with boxes  lt 1 lc 3 lw 0.8
replot	"DistrodS_eta2.dat" title '{/Symbol h} = 0.42' with boxes lt 1 lc 4 lw 0.8

replot    "DistrodS_eta0.dat" smooth bezier notitle  with l lt 1 lc 1 lw 1.8
replot	"DistrodS_eta1.dat" smooth bezier notitle  with l lt 1 lc 2 lw 1.8
replot	"DistrodS_Meta0.dat" smooth bezier notitle  with l lt 1 lc 3 lw 1.8
replot	"DistrodS_eta2.dat" smooth bezier notitle  with l lt 1 lc 4 lw 1.8


set parametric
set trange [0:60]
replot L*0.5,t lt 7 lw 0.7 lc 0 title "L/2"
replot sqrt(3)*L/2,t lt 7 lw 0.7 lc 0 title "dS max"

set terminal postscript eps size 18cm,12cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'DistrodS_3D.eps'
replot
set output '|epstopdf  DistrodS_3D.eps'

set term x11
set output

