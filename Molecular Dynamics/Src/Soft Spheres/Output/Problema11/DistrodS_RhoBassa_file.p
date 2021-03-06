#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 9 noborder
unset border

L=1
set xlabel "Spostamento dS" font "Times-Italic,24" offset 0,0.5
	set xrange [0:sqrt(3)*L/2]

set ylabel "g_t( dS )" font "Times-Italic,28" offset 1.5,0
set yrange [0:22]

plot    "DistrodS_RhoBassa_TD0.dat" title 'T_D = 0.005' with boxes lt 1 lc 1 lw 0.8
replot	"DistrodS_RhoBassa_TD1.dat" title 'T_D = 0.45' with boxes  lt 1 lc 2 lw 0.8
	replot	"DistrodS_RhoBassa_TD2.dat" title 'T_D = 0.75' with boxes  lt 1 lc 3 lw 0.8
	replot	"DistrodS_RhoBassa_TD3.dat" title 'T_D = 1.005' with boxes lt 1 lc 4 lw 0.8


replot    "DistrodS_RhoBassa_TD0.dat" smooth bezier notitle  with l lt 1 lc 1 lw 1.8
replot	"DistrodS_RhoBassa_TD1.dat" smooth bezier notitle  with l lt 1 lc 2 lw 1.8
	replot	"DistrodS_RhoBassa_TD2.dat" smooth bezier notitle  with l  lt 1 lc 3 lw 0.8
	replot	"DistrodS_RhoBassa_TD3.dat" smooth bezier notitle  with l lt 1 lc 4 lw 0.8


set parametric
set trange [0:22]
replot L*0.5,t  title "L/2" lt 1 lw 1 lc 0
replot sqrt(3)*L/2,t  title "dS max" lt 1 lw 1 lc 0

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'DistrodS_RhoBassa_3D.eps'
replot
set output '|epstopdf  DistrodS_RhoBassa_3D.eps'

set term x11
set output

