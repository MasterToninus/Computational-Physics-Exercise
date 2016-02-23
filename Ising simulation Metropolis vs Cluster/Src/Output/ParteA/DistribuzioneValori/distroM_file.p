#confronto ditribuzioni raccolta dati H a vari {/Symbol b}
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di {/Symbol b}"
set style fill  pattern 4 bo  transparent border -1


set key top center

set xlabel "|M|" font "Times-Italic,26"
set xrange [0:1]
set xtics 0.20
set mxtic 2

set ylabel "P(|M|)" font "Times-Italic,26" offset 1,0
set yrange [0:30]

#plot    "distroM_0.dat" title '{/Symbol b} = 0.04' with boxes lt 1 lc 1 lw 1.5 fill pattern 1
plot	"distroM_1.dat" title '{/Symbol b} = 0.24' with boxes lt 1 lc 2 lw 1.5 fill pattern 1
replot	"distroM_2.dat" title '{/Symbol b} = 0.42' with boxes lt 1 lc 3 lw 1.5 fill pattern 2
replot	"distroM_3.dat" title '{/Symbol b}_{critica}' with boxes lt 1 lc 4 lw 1.5	fill pattern 3
replot	"distroM_4.dat" title '{/Symbol b} = 0.46' with boxes lt 1 lc 5 lw 1.5	fill pattern 1
replot	"distroM_5.dat" title '{/Symbol b} = 0.64' with boxes lt 1 lc 8 lw 1.5	fill pattern 2
#replot	"distroM_6.dat" title '{/Symbol b} = 0.84' with boxes lt 1 lc 5 lw 1.5	fill pattern 1

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror


set output 'distroM.eps'
replot
set output '|epstopdf  distroM.eps'

set term x11
set output
