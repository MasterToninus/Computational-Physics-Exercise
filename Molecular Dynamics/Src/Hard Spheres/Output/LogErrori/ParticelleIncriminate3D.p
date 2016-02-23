clear
reset
set size ratio -1

L = 1.
set xtics L
set ytics L

set xrange[0:1]
set yrange[0:1]


splot 'prova.dat' u 1:2:3:4 w errorbars
replot 'ParticelleSovrapposte3D.dat' u 1:2:3:5:6:7 w vectors
replot 'ParticelleSovrapposte3D.dat' u 1:2:3 pt 7

sigma = 2*0.10987
replot 'Box3D_P1.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0
replot 'Box3D_P1.dat'	u (sigma*($1)):(sigma*($2)):(sigma*($3)):(sigma*($4)):(sigma*($5)):(sigma*($6))  w vector nohead lc 7
