#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
#set style fill transparent pattern 3 bo border -1
set style fill transparent pattern 4 noborder
unset border

set xlabel " Libero Cammino [L]"
	set xrange [0:0.03]

set ylabel "P(Lc)"
set yrange [0:500]
set ytics 100

plot    "DistroLC_0.dat" title '{/Symbol h} = 0.75' with boxes lt 1 lc 1 lw 0.8
replot	"DistroLC_1.dat" title '{/Symbol h} = 0.70' with boxes lt 1 lc 2 lw 0.8
replot	"DistroLC_2.dat" title '{/Symbol h} = 0.55' with boxes lt 1 lc 3 lw 0.8
replot	"DistroLC_3.dat" title '{/Symbol h} = 0.3' with boxes lt 1 lc 4 lw 0.8

replot    "DistroLC_0.dat" smooth bezier notitle '{/Symbol h} = 0.72' with l lt 1 lc 1 lw 1.8
replot    "DistroLC_1.dat" smooth bezier notitle '{/Symbol h} = 0.52' with l lt 1 lc 2 lw 1.8
replot    "DistroLC_2.dat" smooth bezier notitle '{/Symbol h} = 0.32' with l lt 1 lc 3 lw 1.8
replot	"DistroLC_3.dat" smooth bezier notitle '{/Symbol h} = 0.32' with l lt 1 lc 4 lw 0.8

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'DistroLc2D.eps'
replot
set output '|epstopdf  DistroLc2D.eps'

set term x11
set output

