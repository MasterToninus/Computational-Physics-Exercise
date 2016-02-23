## prototipo di grafico x y con barra di errore

clear
reset

##set title "Sigma_H vs beta ( con m=12 ampiezza campione di binning)"


set xlabel "{/Symbol b}" font "Times-Italic,28" offset 0,0.5
set xrange [0.2:0.7]
 set xtics 0.1
 set mxtic 2

set ylabel "{/Symbol s}_H" font "Times-Italic,28" offset 3,1 rotate by 0
set yrange [0:0.004]
set ytics 0.001
set mytic 2

plot "H_SigmaJackvsBeta_N80.dat" using 1:2 	title "Jacknife L = 80" w lines lw 3 lc 1   lt 2
replot "H_SigmaBinvsBeta_N80.dat" using 1:2	title "Binning L = 80" w lines lw 3 lc 1   lt 1

replot "H_SigmaJackvsBeta_N60.dat" using 1:2 	title "Jacknife L = 60" w lines lw 3 lc 3   lt 2
replot "H_SigmaBinvsBeta_N60.dat" using 1:2	title "Binning L = 60" w lines lw 3 lc 3   lt 1

set parametric
set trange [0:0.0045]
const=0.4406868
replot const,t lt 7 lw 1.7 lc 0 title "{/Symbol b}_{crit}"

set terminal postscript eps size 16cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.45

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1

set xtics nomirror
set ytics nomirror

set output 'SigmaHvsBeta.eps'
replot
set output '|epstopdf  SigmaHvsBeta.eps'

set term x11
set output
