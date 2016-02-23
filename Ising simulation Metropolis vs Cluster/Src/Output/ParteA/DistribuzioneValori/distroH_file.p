#confronto ditribuzioni raccolta dati H a vari {/Symbol b}
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di H/V a vari valori di {/Symbol b}"
set style fill  pattern 4 bo  transparent border -1

set key top center

set xlabel "H"font "Times-Italic,26"
set xrange [-2:0]

set ylabel "P(H)" font "Times-Italic,26" offset 1,0
set yrange [0:30]

plot    "distroH_0.dat" title '{/Symbol b} = 0.04' with boxes 	lt 1 lc 1 lw 1.5 fill pattern 2
replot	"distroH_1.dat" title '{/Symbol b} = 0.24' with boxes 	lt 1 lc 2 lw 1.5 fill pattern 1
replot	"distroH_2.dat" title '{/Symbol b} = 0.42' with boxes 	lt 1 lc 3 lw 1.5 fill pattern 2
replot	"distroH_3.dat" title '{/Symbol b} critica' with boxes 	lt 1 lc 4 lw 1.5 fill pattern 3
replot	"distroH_4.dat" title '{/Symbol b} = 0.46' with boxes	lt 1 lc 5 lw 1.5 fill pattern 1
replot	"distroH_5.dat" title '{/Symbol b} = 0.64' with boxes 	lt 1 lc 9 lw 1.5 fill pattern 2
replot	"distroH_6.dat" title '{/Symbol b} = 0.84' with boxes  	lt 1 lc 7 lw 1.5 fill pattern 4

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror


set output 'distroH.eps'
replot
set output '|epstopdf  distroH.eps'

set term x11
set output
