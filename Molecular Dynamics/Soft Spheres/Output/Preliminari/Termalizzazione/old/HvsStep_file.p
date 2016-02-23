
clear
reset


plot 'HmediovsStep_eta0.dat' title "H_{Medio} {/Symbol h} = 0.615 " w l lt 1 lc 1
replot 'HmediovsStep_eta1.dat'  title "H_{Medio} {/Symbol h} = 0.515 " w l lt 1 lc 2
replot 'HmediovsStep_eta2.dat'  title "H_{Medio} {/Symbol h} = 0.415 " w l lt 1 lc 3

replot 'HistvsStep_eta0.dat' title "H_{istantaneo} {/Symbol h} = 0.615 "  w l lt 2 lc 1
replot 'HistvsStep_eta1.dat'  title "H_{istantaneo} {/Symbol h} = 0.515 "  w l lt 2 lc 2
replot 'HistvsStep_eta2.dat'  title "H_{istantaneo} {/Symbol h} = 0.415 "  w l lt 2 lc 3

replot - sqrt(pi/2) title "H_{atteso} " lt 1 lc 0

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key right top

set xlabel "# Collisioni" font "Times-Italic,24" offset 0,0.5
set xrange [0:3500]

set ylabel "H_{Boltzman}" font "Times-Italic,24" offset 1.5,0 #rotate by 0
set yrange [-1.3:0]

set terminal postscript eps size 18cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid


set xtics nomirror
set ytics nomirror

set output 'HvsStep3D.eps'
replot
set output '|epstopdf  HvsStep3D.eps'

set term x11
set output
