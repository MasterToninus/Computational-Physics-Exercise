clear
reset
set size ratio -1

L = 1.
set xtics L
set ytics L

set xrange[0:1]
set yrange[0:1]


plot 'prova.dat' u 1:2:3 w circles
replot 'ParticelleSovrapposte2D.dat' u 1:2:3 w circles 
replot 'ParticelleSovrapposte2D.dat' u 1:2:4:5 w vector 

replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4))  w vector nohead lc 0
