clear
reset

set key out

plot 'UvsStep.dat' title "U" w l	lt 1 lc 3

replot 'TvsStep.dat' title "T" w l  lt 1 lc 2

replot 'PvsStep.dat' title "P" w l  lt 1 lc 1

replot 1.22 title "Temp Desiderata"

set xlabel "tempo [t]" font "Times-Italic,24" offset 0,0.5
	set xrange [0: 50]
	set xtics 25
	set mxtics 2

set ylabel " O_i" font "Times-Italic,24" offset 1.5,1 rotate by 0
	set yrange [-3.25:1.5]
	set ytics 1

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'OvsStep.eps'
replot
set output '|epstopdf  OvsStep.eps'

set term x11
set output
