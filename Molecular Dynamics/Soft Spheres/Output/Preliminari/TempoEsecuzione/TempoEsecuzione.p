

clear
reset



set title "Tempo Esecuzione vs L"
set key left top

set xlabel "N"
#set xrange [5:80]

set ylabel "t_esec (secondi)"
#set yrange [0:1]

plot "T_esec_Rho0_2D.dat" using 1:2 title "symbol r = "	lw 3
replot "T_esec_Rho1_2D.dat" using 1:2 title "symbol r = "	lw 3


