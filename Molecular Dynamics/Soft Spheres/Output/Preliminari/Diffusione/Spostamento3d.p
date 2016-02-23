
clear
reset
set size ratio -1

L = 5.85
set xtics L
set ytics L



splot 'PIniziali.dat' pt 7
replot 'PFinali.dat' pt 7
replot 'Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0


