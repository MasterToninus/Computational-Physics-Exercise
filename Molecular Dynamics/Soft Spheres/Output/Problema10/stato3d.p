##Stampo lo stato inziale le particelle come cerchietti e sovrappongo le velocità

clear
reset
set size ratio -1

L = 9.3
set xrange [0:L]
set yrange [0:L]
set zrange [0:L]

set pointsize 1

#particelle
splot 'Stato_Finale.dat' u 1:2:3  lt 1 pt 7
#velocità
	replot 'Stato_Finale.dat' using 1:2:3:4:5:6 with vectors head filled lt 1
#accelerazioni
#	replot 'Stato_Finale.dat' using 1:2:3:7:8:9 with vectors head filled lt 2




#R = 0.5 #Raggio del potenziale
#plot 'Stato_Finale.dat' u 1:2 w circles lt 3
#set style circle radius graph R

#plot 'Stato_Finale.dat' u 1:2:3 w circles lt 3

replot
