## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key right top

set xlabel "{/Symbol h}" font "Times-Italic,28" offset 0,1.5
#set xrange [0:0.8]


set ylabel "<Lc>" font "Times-Italic,28" offset 2,0 #rotate by 0
#set yrange [0:1.01]
set ytics 0.005
set trange [-0.01:1.01]

d=2
eta(x) = pi*x/(d*2)

plot "Lc_mediovsRho_2D.dat" u (eta($1)):2:3 title "N = 288"   lt 1 lc 3 lw 0.85 w yerrorbars
replot "Lc_mediovsRho_2D.dat" u (eta($1)):2:3  notitle "N = 288"   lt 1 lc 3 lw 2.2 w l


set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
#unset border

set xtics nomirror
set ytics nomirror

set output 'LcvsEta2D.eps'
replot
set output '|epstopdf  LcvsEta2D.eps'

set term x11
set output
