
clear
reset
set size ratio -1

L = 14.14
set xtics L
set ytics L



plot 'PIniziali.dat' 
replot 'PFinali.dat' w circles
replot 'Spostamento.dat' u 1:2:4:5 w vector
replot 'Box2D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)) w vector nohead lc 0


