clear
reset

L=6.58

set xlabel "Tempo di Evoluzione [t]" font "Times-Italic,24" offset 0,0.5
#	set xrange [0: 0.9]

set ylabel " <dS^2> [{/Symbol s}]" font "Times-Italic,24" offset 1.5,0
	set yrange [0:2]

plot 'dS_quad_vsDt_TD0.dat' title "T = 0.05" w l	lc 1 lt 1
#	replot 'dS_quad_vsDt_TD0.dat' title "T = ?" w yerrorbars	lc 1  lt 4

replot 'dS_quad_vsDt_TD1.dat' title "T = 0.4" w l	lc 2 lt 1
#	replot 'dS_quad_vsDt_TD1.dat' title "T = ?" w yerrorbars	lc 2

replot 'dS_quad_vsDt_TD2.dat' title "T = 0.8"  w l	lc 3 lt 1
#	replot 'dS_quad_vsDt_TD2.dat' title "T = ?" w yerrorbars	lc 3

replot 'dS_quad_vsDt_TD3.dat' title "T = 1.087"  w l	lc 4 lt 1
#	replot 'dS_quad_vsDt_TD3.dat' title "T = ?" w yerrorbars	lc 4


set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'dS_quadvsDt.eps'
replot
set output '|epstopdf  dS_quadvsDt.eps'

set term x11
set output

