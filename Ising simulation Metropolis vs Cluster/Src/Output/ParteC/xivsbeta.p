## prototipo di grafico x y con barra di errore

clear
reset
const= log( 1.+ sqrt(2.))/2.
t(x) = const/x -1

plot[-0.5:8] "xivsbeta.dat" using (t($1)):2:3 notitle "L = 100" w yerrorbars lt 1 lc 3 lw 2.2
replot "xivsbeta.dat" using (t($1)):2:3 notitle "L = 100" w l

set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt 7 lw 1
unset border

set xlabel "t _{(temperatura ridotta)}" font "Times-Italic,28" offset 0, 0.5
set xrange [-0.5: 8]
set xtics 1
set mxtic 2

set ylabel "|M|" font "Times-Italic,28" offset 2,0 rotate by 0
set yrange [-19:305]
set ytics 50
set mytic 2

replot
