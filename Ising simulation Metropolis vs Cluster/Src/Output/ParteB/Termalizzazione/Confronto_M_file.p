## prototipo di grafico x y con barra di errore

clear
reset


plot "Confronto_Metro_M.dat" using 1:2 notitle "M metropolis" w l lc 1 
replot "Confronto_Metro_M.dat" title "M metropolis" lc 1 lw 2
replot "Confronto_Metro_M_abs.dat" using 1:2 notitle "|M| metropolis"  w l lc 2
replot "Confronto_Metro_M_abs.dat" title "|M| metropolis" 	lc 2 lw 2
replot "Confronto_Cluster_M.dat" using 1:2 notitle "M improved cluster" w l	lc 3
replot "Confronto_Cluster_M.dat" using 1:2 title  "M_{improved} Cluster"	lc 3 lw 2

replot 0 notitle lc -1 lt -1 lw 0.5

set terminal postscript eps size 12cm,9cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid

#set log x
set xlabel " step" font "Times-Italic,22" offset 0,0.5
set xrange [0:85]

set ylabel "M" font "Times-Italic,22" offset 3.5,0 rotate by 0
 set yrange [-0.05:0.075]
set xtics 25
set mxtic 5
set ytics 0.025
set mytic 0.005

set xtics nomirror
set ytics nomirror

set output 'Confronto_M_termal.eps'
replot
set output '|epstopdf  Confronto_M_termal.eps'

set term x11
set output
