

clear
reset



#	set title "Tempo Esecuzione vs L"
set key left top
set grid
unset border
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror



set xlabel "L" offset 0,0.5
set xrange [0:80]

set ylabel "t_{esec} (secondi)" offset 1.5,0
set yrange [0:0.09]
set ytics 0.02

plot "Cluster_TimevsN.dat" using 1:2 title "Algoritmo Swenden Wang"	lw 3
replot "Metro_TimevsN.dat" using 1:2 title "Algoritmo Metropolis"	lw 3
#replot "Cluster_V2_TimevsN.dat" using 1:2 title "Algoritmo Swenden Wang versione 2"	

f1(x) = a1*(x**b1)            # define the function to be fit
      a1 = 1; b1 = 1;            # initial guess for a1 and b1
fit f1(x) 'Cluster_TimevsN.dat' using 1:2 via a1, b1
replot f1(x) lw 1.5


set terminal postscript eps size 18cm,8cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set output 'TempoEsecuzione.eps'

set tmargin 1
set bmargin 3
#set lmargin 4
set rmargin 1.2
replot
set output '|epstopdf TempoEsecuzione.eps'
set term x11
set output



