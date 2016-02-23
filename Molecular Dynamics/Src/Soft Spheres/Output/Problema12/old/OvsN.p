clear
reset

set xlabel "N "
#	set xrange [0: 0.9]

set ylabel " <O>"
#	set yrange [-0.02:2.5]

plot 'UvsN.dat' title "U" w yerrorbars	lc 1
replot 'UvsN.dat' notitle w l	lc 1

replot 'TvsN.dat' title "T" w yerrorbars lc 2
replot 'TvsN.dat' notitle w l	lc 2

replot 'PvsN.dat' title "P" w yerrorbars lc 3
replot 'PvsN.dat' notitle w l	lc 3
