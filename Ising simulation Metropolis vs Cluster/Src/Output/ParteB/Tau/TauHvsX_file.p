## prototipo di grafico x y con barra di errore

clear
reset




plot "Metro_TauHvsX.dat" title "Metropolis" 	w l	lw 2
replot "Cluster_TauHvsX.dat" title "Swen.-Wang" w l	lw 2
f(x)=1./abs(x)
#replot f(x)

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45
set pointsize 1.45
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

#set title "TauH vs X (serie trocata a step 10000)"

set xlabel "X" offset 0, 0.5
set xrange [-0.15: 0.15]

set ylabel "{/Symbol t}" offset 4,0 rotate by 0
set yrange [-10:170]
set ytics 50

set xtics nomirror
set ytics nomirror


set grid
replot 0 notitle lc -1 lt -1 lw 0.5

#set log x

set output 'TauHvsX.eps'
replot
set output '|epstopdf  TauHvsX.eps'

set term x11
set output


