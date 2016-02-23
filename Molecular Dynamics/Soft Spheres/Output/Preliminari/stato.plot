##Stampo lo stato inziale le particelle come cerchietti e sovrappongo le velocità

clear
reset
set size ratio -1




#particelle
plot 'Stato.dat' u 1:2:3 w circles lt 3
#velocità
replot 'Stato.dat' using 1:2:4:5 with vectors head filled lt 1
#accelerazioni
replot 'Stato.dat' using 1:2:6:7 with vectors head filled lt 2

L = 8.45154
R = 2**(1/5)
#set style circle radius graph R
#set xrange [0:L]
#set yrange [0:L]

