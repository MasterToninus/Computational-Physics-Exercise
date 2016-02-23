clear
reset

L=6.58

set xlabel "Nstep (unità di 0.001 [t])"
#	set xrange [0: 0.9]

set ylabel " <dS^2>"
	set yrange [0:L]

plot 'dS_quad_T0.dat' notitle "T = 0.80" w l	lc 1
#	replot 'dS_quad_T0.dat' title "T = ?" w yerrorbars	lc 1

replot 'dS_quad_T1.dat' notitle  w l	lc 2
#	replot 'dS_quad_T1.dat' title "T = ?" w yerrorbars	lc 2

replot 'dS_quad_T2.dat' notitle  w l	lc 3
#	replot 'dS_quad_T2.dat' title "T = ?" w yerrorbars	lc 3

replot 'dS_quad_T3.dat' notitle  w l	lc 4
#	replot 'dS_quad_T3.dat' title "T = ?" w yerrorbars	lc 4

replot 'dS_quad_T4.dat' notitle  w l	lc 5
#	replot 'dS_quad_T4.dat' title "T = ?" w yerrorbars	lc 5

replot 'dS_quad_T5.dat' notitle  w l	lc 6
#	replot 'dS_quad_T5.dat' title "T = ?" w yerrorbars	lc 6


