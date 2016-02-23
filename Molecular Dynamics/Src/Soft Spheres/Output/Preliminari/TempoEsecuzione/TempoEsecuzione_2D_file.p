

clear
reset



#	set title "Tempo Esecuzione vs L"
set key left top
set grid
unset border
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror



set xlabel "N" font "Times-Italic,24" offset 0,0.5
#	set xrange [0:80]

set ylabel "t_{esec} (secondi)"  font "Times-Italic,24" offset 1.5#,0
#	set yrange [0: 0.00000000125]
#	set ytics 0.00000000025

plot "T_esec_Rho0_2D.dat" using 1:2 title "(2D) {/Symbol r} = 0.2 " w l	lt 1 lc 1 lw 3
replot "T_esec_Rho1_2D.dat" using 1:2 title "(2D) {/Symbol r} = 0.7 " w l	lt 1 lc 2 lw 3
replot "T_esec_Rho2_2D.dat" using 1:2 title "(2D) {/Symbol r} = 0.9 " w l	lt 1 lc 3 lw 3



set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'TempoEsecuzione2D.eps'
replot
set output '|epstopdf  TempoEsecuzione2D.eps'

set term x11
set output
