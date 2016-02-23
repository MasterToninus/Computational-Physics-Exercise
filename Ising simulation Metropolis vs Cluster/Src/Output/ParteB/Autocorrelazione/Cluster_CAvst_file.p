## prototipo di grafico x y con barra di errore

clear
reset

#set title "Funzione di correlazione CA(t) vs t con algoritmo SWENDEN-WANG (valore ottenuto con ~5000 campioni per punto)"

plot "Cluster_CAvst_0.dat" title "beta=0.32" 				w l	lw 3 lt 1 lc 1 
replot "Cluster_CAvst_1.dat" title "beta=0.39" 				w l	lw 3 lt 1 lc 2
replot "Cluster_CAvst_2.dat" title "beta=0.41" 				w l	lw 3 lt 1 lc 3
replot "Cluster_CAvst_3.dat" title "beta=0.425" 			w l	lw 3 lt 1 lc 4
replot "Cluster_CAvst_4.dat" title "beta critico" 			w l	lw 3 lt 1 lc 5

replot exp(-2) title "e^{-2}" lt 8 lw 1 lc -1 

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
unset border

#set log x
set xlabel " t" font "Times-Italic,22" offset 0,1.5
set xrange [-1:35]
set xtics 5
set mxtic 5

set ylabel "CA(t)" font "Times-Italic,22" offset 2.5,0 rotate by 90
 set yrange [-0.05:1]
set ytics 0.2
set mytic 5

set xtics nomirror
set ytics nomirror

set output 'Cluster_CAvst.eps'
replot
set output '|epstopdf  Cluster_CAvst.eps'

set term x11
set output
