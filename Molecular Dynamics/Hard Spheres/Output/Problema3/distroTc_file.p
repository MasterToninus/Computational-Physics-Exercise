#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 4 noborder
unset border

set xlabel "Tempo Collisione [t]" font "Times-Italic,24" #offset 0,1.5
 set xrange [0:0.00015]

set ylabel "P(|Tc|)" font "Times-Italic,28" offset 1.5,0
# set yrange [-2:2]

plot    "DistroTc_0.dat" title '{/Symbol h} = 0.75' with boxes lt 1 lc 1 lw 0.8
replot	"DistroTc_1.dat" title '{/Symbol h} = 0.7' with boxes lt 1 lc 2 lw 0.8
replot	"DistroTc_2.dat" title '{/Symbol h} = 0.55' with boxes lt 1 lc 3 lw 0.8
replot	"DistroTc_3.dat" title '{/Symbol h} = 0.3' with boxes lt 1 lc 4 lw 0.8


replot    "DistroTc_0.dat" smooth bezier notitle '{/Symbol h} = 0.75' with l lt 1 lc 1 lw 1.8
replot    "DistroTc_1.dat" smooth bezier notitle '{/Symbol h} = 0.67' with l lt 1 lc 2 lw 1.8
replot    "DistroTc_2.dat" smooth bezier notitle '{/Symbol h} = 0.58' with l lt 1 lc 3 lw 1.8
replot    "DistroTc_3.dat" smooth bezier notitle '{/Symbol h} = 0.5' with l lt 1 lc 4 lw 1.8





set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'DistroTc.eps'
replot
set output '|epstopdf  DistroTc.eps'

set term x11
set output

