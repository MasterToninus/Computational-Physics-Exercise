
clear
reset
set size ratio -1

L = 5.53
#	set xtics L
#	set ytics L



splot 'T2_Rho1_Fine.dat' pt 7
replot 'T2_Rho1_Spostamento.dat' u 1:2:3 pt 7
replot 'T2_Rho1_Spostamento.dat' u 1:2:3:5:6:7 w vector
replot 'Box3D.dat'	u (L*($1)):(L*($2)):(L*($3)):(L*($4)):(L*($5)):(L*($6))  w vector nohead lc 0


