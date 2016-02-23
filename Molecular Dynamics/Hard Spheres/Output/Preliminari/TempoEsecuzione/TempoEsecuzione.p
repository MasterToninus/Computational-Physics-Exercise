

clear
reset



set title "Tempo Esecuzione vs L"
set key left top

set xlabel "N"
#set xrange [5:80]

set ylabel "t_esec (secondi)"
#set yrange [0:1]

plot "T_esec_vsN3D.dat" using 1:2 title "3D"	lw 3 w l
replot "T_esec_vsN2D.dat" using 1:2 title "2D"	lw 3 w l


