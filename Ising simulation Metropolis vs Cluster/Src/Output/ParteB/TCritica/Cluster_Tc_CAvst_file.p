## -_-_-_

clear
reset

#set title "Funzione di correlazione CA(t) vs t con algoritmo Swenden Wang a BETA CRITICO"




plot "Cluster_Tc_CAvst_N120.dat" title " L = 120" 		w l	lw 3 lt 1 lc 1 
#replot "Cluster_Tc_CAvst_N105.dat" title " L = 105" 	w l	lw 3 lt 1 
replot "Cluster_Tc_CAvst_N90.dat" title " L = 90" 		w l	lw 3 lt 1 lc 2 
#replot "Cluster_Tc_CAvst_N75.dat" title " L = 75" 		w l	lw 3 lt 1
replot "Cluster_Tc_CAvst_N60.dat" title " L = 60" 		w l	lw 3 lt 1 lc 3 
replot "Cluster_Tc_CAvst_N45.dat" title " L = 45" 		w l	lw 3 lt 1 lc 4 
#replot "Cluster_Tc_CAvst_N30.dat" title " L = 30" 		w l	lw 3 lt 1  
replot "Cluster_Tc_CAvst_N15.dat" title " L = 15" 		w l	lw 3 lt 1 lc 5 

replot exp(-2) title "e^{-2}" lt 8 lw 1 lc -1 

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
unset border

#set log x
set xlabel "t" font "Times-Italic,22" offset 0,1.5
set xrange [-1:35]
set xtics 5
set mxtic 5

set ylabel "CA(t)" font "Times-Italic,22" offset 2.5,0 rotate by 90
 set yrange [-0.05:1]
set ytics 0.2
set mytic 5

set xtics nomirror
set ytics nomirror

set output 'Cluster_Tc_CAvst.eps'
replot
set output '|epstopdf  Cluster_Tc_CAvst.eps'

set term x11
set output
