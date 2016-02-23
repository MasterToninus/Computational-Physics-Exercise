clear
reset
set size ratio -1




#particelle
plot 'Stato_Finale.dat' u 1:2:3 w circles  lc 1
replot 'MotoP5.dat' u 1:2  w l	lc 2 lt 1




L = 4.83046
R = 2**(1/5)
#set style circle radius graph R
set xrange [0:L]
set yrange [0:L]
replot
