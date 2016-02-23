
clear
reset
set size ratio -1

L = 5.36
set xtics L
set ytics L



splot 'Stato_Fine3D.dat' pt 7
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0


