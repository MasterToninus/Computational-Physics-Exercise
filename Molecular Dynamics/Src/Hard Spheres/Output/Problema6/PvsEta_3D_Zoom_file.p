## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "{/Symbol h}" font "Times-Italic,28" offset 0,0.5
set xrange [0.48:0.565]

set ylabel "<Z>" font "Times-Italic,28" offset 1.5,0 #rotate by 0
set yrange [10:15]
set trange [0:20]

plot "PvsEta_3D.dat" using 1:2:3 title "N = 250" w yerrorlines  lt 1 lc 3 lw 2.2
replot "PvsEta_3D_ZonaMeta.dat" using 1:2:3 title "N = 250 (Metastabile)" w yerrorlines  lt 1 lc 1 lw 2.2


set parametric
const=0.685
replot 0.494,t lt 7 lw 1.5 lc 0 notitle "{/Symbol b}_{crit}"
replot 0.545,t lt 7 lw 1.5 lc 0 notitle "{/Symbol b}_{crit}"

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'PvsEta3DZoom.eps'
replot
set output '|epstopdf  PvsEta3DZoom.eps'

set term x11
set output
