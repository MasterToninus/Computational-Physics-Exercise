## prototipo di grafico x y con barra di errore

clear
reset




plot "cvst_N200.dat" using 1:2:3	 title "L = 200" w yerrorbars	lw 2 	lc 1
replot "cvst_N200.dat" notitle w l										 	lc 1

#replot "cvst_N120.dat" using 1:2:3 title "L = 120" w yerrorbars	lw 2 	lc 2
#replot "cvst_N120.dat" notitle w l											lc 2

#replot "cvst_N105.dat" using 1:2:3 title "L = 105" w yerrorbars	lw 2
replot "cvst_N90.dat"	 using 1:2:3 title "L = 90"	w yerrorbars	lw 2 	lc 3
replot "cvst_N90.dat" notitle w l											lc 3

#replot "cvst_N75.dat"  using 1:2:3 title "L = 75" w yerrorbars	lw 2
#replot "cvst_N60.dat"  using 1:2:3 title "L = 60"	w yerrorbars	lw 2	lc 4
#replot "cvst_N60.dat" notitle 					w l						lc 4

#replot "cvst_N45.dat"  using 1:2:3 title "L = 45"	w yerrorbars	lw 2
replot "cvst_N30.dat"  using 1:2:3 title "L = 30"	w yerrorbars	lw 2	lc 11
replot "cvst_N30.dat" notitle 					w l						lc 11
replot "cvst_N15.dat"  using 1:2:3 title "L = 15"	w yerrorbars	lw 2	lc 4
replot "cvst_N15.dat" notitle 					w l							lc 4



set terminal postscript eps size 18cm,9cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

#set title "TauH vs X (serie trocata a step 10000)"

set xlabel "t _{(temperatura ridotta)}" font "Times-Italic,28" offset 0, 0.5
set xrange [-0.225: 0.225]
set xtics 0.05
set mxtic 2

set ylabel "c" font "Times-Italic,28" offset 2,0 rotate by 0
set yrange [0:3.5]
set ytics 0.5
set mytic 2

set xtics nomirror
set ytics nomirror

set grid
#set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt 7 lw 1


set output 'cvst.eps'
replot
set output '|epstopdf  cvst.eps'

set term x11
set output


