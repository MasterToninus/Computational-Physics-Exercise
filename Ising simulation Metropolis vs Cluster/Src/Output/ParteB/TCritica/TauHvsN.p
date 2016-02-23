## prototipo di grafico x y con barra di errore

clear
reset

set title "TauH (beta critica) vs N (serie trocata a step 10000)"


set xlabel "N"
# set xrange [0:5]

set ylabel "Tau"
# set yrange [-2:2]

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



