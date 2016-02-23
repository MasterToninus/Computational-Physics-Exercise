## prototipo di grafico x y con barra di errore

clear
reset




plot "Mvst_N200.dat" using 1:2:3	 title "L = 200" w yerrorbars	lw 2 	lc 1
replot "Mvst_N200.dat" notitle w l										 	lc 1

#replot "Mvst_N120.dat" using 1:2:3 title "L = 120" w yerrorbars	lw 2 	lc 2
#replot "Mvst_N120.dat" notitle w l											lc 2

#replot "Mvst_N105.dat" using 1:2:3 title "L = 105" w yerrorbars	lw 2
replot "Mvst_N90.dat"	 using 1:2:3 title "L = 90"	w yerrorbars	lw 2 	lc 3
replot "Mvst_N90.dat" notitle w l											lc 3

#replot "Mvst_N75.dat"  using 1:2:3 title "L = 75" w yerrorbars	lw 2
replot "Mvst_N60.dat"  using 1:2:3 title "L = 60"	w yerrorbars	lw 2	lc 4
replot "Mvst_N60.dat" notitle 					w l						lc 4

#replot "Mvst_N45.dat"  using 1:2:3 title "L = 45"	w yerrorbars	lw 2
replot "Mvst_N30.dat"  using 1:2:3 title "L = 30"	w yerrorbars	lw 2	lc 9
replot "Mvst_N30.dat" notitle 					w l						lc 9
replot "Mvst_N15.dat"  using 1:2:3 title "L = 15"	w yerrorbars	lw 2	lc 2
replot "Mvst_N15.dat" notitle 					w l							lc 2




