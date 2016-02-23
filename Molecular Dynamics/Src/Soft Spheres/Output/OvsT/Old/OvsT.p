clear
reset


plot 'UvsT500.dat' title "U" w yerrorbars	lc 1
replot 'UvsT500.dat' notitle w l	lc 1

replot 'TvsT500.dat' title "T" w yerrorbars lc 2
replot 'TvsT500.dat' notitle w l	lc 2

replot 'PvsT500.dat' title "P" w yerrorbars lc 3
replot 'PvsT500.dat' notitle w l	lc 3
