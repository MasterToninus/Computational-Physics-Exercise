clear
reset
set size ratio -1




#particelle

splot 'MotoP5.dat' u 1:2:3  w l	lc 2 lt 1




L = 4.83046
R = 2**(1/5)
#set style circle radius graph R
set xrange [0:L]
set yrange [0:L]
set zrange [0:L]
replot
