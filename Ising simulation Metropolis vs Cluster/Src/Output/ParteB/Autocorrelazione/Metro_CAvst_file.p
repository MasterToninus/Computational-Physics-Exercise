## prototipo di grafico x y con barra di errore

clear
reset

#set title "Funzione di correlazione CA(t) vs t con algoritmo METROPOLIS (valore ottenuto con ~50000 campioni per punto, L = 100)"




plot "Metro_CAvst_0.dat" title "beta=0.32" 				w l	lw 3 lt 1 lc 1
replot "Metro_CAvst_1.dat" title "beta=0.39" 			w l	lw 3 lt 1 lc 2
replot "Metro_CAvst_2.dat" title "beta=0.41" 			w l	lw 3 lt 1 lc 3
replot "Metro_CAvst_3.dat" title "beta=0.425" 			w l	lw 3 lt 1 lc 4
replot "Metro_CAvst_4.dat" title "beta critico" 		w l	lw 3 lt 1 lc 5

replot exp(-2) title "e^{-2}" lt 8 lw 1 lc -1 


set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror


unset border

#set log x
set xlabel " t" font "Times-Italic,22" offset 0,1.5
set xrange [-2.5:150]
set xtics 20
set mxtic 5

set ylabel "CA(t)" font "Times-Italic,22" offset 2.5,0 rotate by 90
 set yrange [-0.05:1]
set ytics 0,0.2
set mytic 5



set output 'Metro_CAvst.eps'
replot
set output '|epstopdf  Metro_CAvst.eps'

set term x11
set output
