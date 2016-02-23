##Stampo lo stato inziale le particelle come cerchietti e sovrappongo le velocità

clear
reset
set size ratio -1

L = 22.36
R = 2**(1/5)
#set style circle radius graph R
set xrange [0:L]
set yrange [0:L]



#particelle
#	plot 'Stato2D_Inizio_2.dat' u 1:2:3 w circles lt 1 
#velocità
#	replot 'Stato2D_Inizio_2.dat' using 1:2:4:5 with vectors head filled lt 1
#accelerazioni
#	replot 'Stato2D_Inizio_2.dat' using 1:2:6:7 with vectors head filled lt 2

#particelle
	plot 'Stato2D_Fine_2.dat' u 1:2:3 w circles lt -1  
#velocità
	replot 'Stato2D_Fine_2.dat' using 1:2:4:5 with vectors head filled lt 5
#accelerazioni
	replot 'Stato2D_Fine_2.dat' using 1:2:6:7 with vectors head filled lt 6


