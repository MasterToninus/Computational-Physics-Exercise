## -_-_-_

clear
reset

#set title "Funzione di correlazione CA(t) vs t con algoritmo Metropolis a BETA CRITICO"


set xlabel "t"
set xrange [0:75]

set ylabel "CA(t)"
set yrange [-0.1:1]
#set log y


plot "Metro_Tc_CAvst_N120.dat" title "N = 120" 		w l	lw 3 lt 1 lc 1
#replot "Metro_Tc_CAvst_N105.dat" title "N = 105" 	w l	lw 3 lt 1
replot "Metro_Tc_CAvst_N90.dat" title "N = 90" 		w l	lw 3 lt 1 lc 2
#replot "Metro_Tc_CAvst_N75.dat" title "N = 75" 	w l	lw 3 lt 1
replot "Metro_Tc_CAvst_N60.dat" title "N = 60" 		w l	lw 3 lt 1 lc 3
replot "Metro_Tc_CAvst_N45.dat" title "N = 45" 		w l	lw 3 lt 1 lc 4
#replot "Metro_Tc_CAvst_N30.dat" title "N = 30" 	w l	lw 3 lt 1
replot "Metro_Tc_CAvst_N15.dat" title "N = 15" 		w l	lw 3 lt 1 lc 5

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

set output 'Metro_Tc_CAvst.eps'
replot
set output '|epstopdf  Metro_Tc_CAvst.eps'

set term x11
set output


