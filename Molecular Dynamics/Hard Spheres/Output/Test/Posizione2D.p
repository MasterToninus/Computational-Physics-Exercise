
clear
reset
set size ratio -1

L = 1.
set xtics L
set ytics L
set xrange[-0.2:1.2]
set yrange[-0.2:1.2]


plot 'prova0.dat' u 1:2:3 w circles lc 1
replot 'prova0.dat' u 1:2:4:5 w vectors lc 1

replot 'prova1.dat' u 1:2:3 w circles lc 2
replot 'prova1.dat' u 1:2:4:5 w vector lc 2


#	replot 'prova2.dat' u 1:2:3 w circles lc 0
#	replot 'prova2.dat' u 1:2:4:5 w vector lc 0


#replot 'prova.dat' u 1:2:4:5 w vector
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)) notitle w vector nohead lc 0
#replot './ParticelleSovrapposte.dat' u 1:2:3 w circles
#replot './ParticelleSovrapposte.dat' u 1:2:4:5 w vectors 

