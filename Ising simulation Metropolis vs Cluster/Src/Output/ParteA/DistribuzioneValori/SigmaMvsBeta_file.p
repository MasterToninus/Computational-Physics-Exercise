## prototipo di grafico x y con barra di errore

clear
reset

#set title "Sigma_M vs beta ( con m=12 ampiezza campione di binning) L=80"
set key left top

set xlabel "{/Symbol b}" font "Times-Italic,28" offset 0,0.5
set xrange [0.2:0.7]
set xtics 0.1
set mxtic 2

set ylabel "{/Symbol s}_M" font "Times-Italic,28" offset 3,0.5 rotate by 0
set yrange [0:0.01125]
set ytics 0.0025
set mytic 2

plot "M_SigmaJackvsBeta_N80.dat" using 1:2 	title "Jacknife L = 80" w lines lw 3 lc 1   lt 2
replot "M_SigmaBinvsBeta_N80.dat" using 1:2	title "Binning L = 80" w lines lw 3 lc 1 		lt 1

replot "M_SigmaJackvsBeta_N60.dat" using 1:2 	title "Jacknife L = 60" w lines lw 3 lc 3  lt 2
replot "M_SigmaBinvsBeta_N60.dat" using 1:2	title "Binning L = 60" w lines lw 3 lc 3     lt 1

set parametric
set trange [0:0.012]
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

set output 'SigmaMvsBeta.eps'
replot
set output '|epstopdf  SigmaMvsBeta.eps'

set term x11
set output
