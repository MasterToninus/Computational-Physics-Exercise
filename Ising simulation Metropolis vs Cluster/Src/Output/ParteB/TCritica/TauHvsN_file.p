## prototipo di grafico x y con barra di errore

clear
reset

set key top left
set logscale xy

plot "Metro_Tc_TauHvsN.dat" title "Metropolis" 	
replot "Cluster_Tc_TauHvsN.dat" title "Swen.-Wang" 
a=0.0125
b=2
f(x)=a*x**b
fit f(x) 'Metro_Tc_TauHvsN.dat' using 1:2 via a,b
b=2
a=0.0125

a2=0.0125
b2=2
g(x)=a2*x**b2
fit g(x) 'Cluster_Tc_TauHvsN.dat' using 1:2 via a2,b2



set xrange [20:150]
set xtics 10

set yrange [1:1000]
replot f(x)
replot g(x)


set terminal postscript eps size 15cm,10cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set pointsize 1.45

set xlabel "L" #offset 0, 0.5
#set xrange [-0.3: 0.3]

set ylabel "{/Symbol t}" offset 2,0 rotate by 0
#set yrange [0:3.5]
set ytics 0.5

set xtics nomirror
set ytics nomirror

set log xy

set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1


set output 'TauHvsN.eps'
replot
set output '|epstopdf  TauHvsN.eps'

set term x11
set output




