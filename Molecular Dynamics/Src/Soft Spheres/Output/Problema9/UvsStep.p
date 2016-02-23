clear
reset

set xlabel "tempo [t]"
#	set xrange [0: 0.9]

set ylabel " U*/N istantaneo"
#	set yrange [-0.02:2.5]


plot 'UvsStep_N108.dat' title "U istantaneo N 108" w l	lc 1
replot 'UvsStep_N500.dat' title "U istantaneo N 500" w l	lc 2


replot -3.49772 title "U media N 108"
replot -3.48813 title "U media N 500"


set multiplot
set size 1,0.5
set origin 0.0,0.0
set lmargin 10
set rmargin 0
plot 'UvsStep_N108.dat' title "U istantaneo N 108" w l	lc 1
set origin 0,0.5
set format y ""
set lmargin 0
set rmargin 2
plot 'UvsStep_N500.dat' title "U istantaneo N 500" w l	lc 2
set nomultiplot
