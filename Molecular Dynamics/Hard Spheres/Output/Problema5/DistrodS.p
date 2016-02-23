#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 10 #bo border -1
#unset border

L=1
set xlabel "Spostamento [L]"
	set xrange [0:sqrt(3)*L/2]

set ylabel "P(L)"
 set yrange [0:42]

plot    "DistrodS_eta0.dat" title '{/Symbol h} = 0.62' with boxes 
replot	"DistrodS_eta1.dat" title '{/Symbol h} = 0.52' with boxes 
replot	"DistrodS_Meta0.dat" title '{/Symbol h} = 0.505' with boxes 
replot	"DistrodS_eta2.dat" title '{/Symbol h} = 0.42' with boxes 



set parametric
set trange [0:60]
replot L*0.5,t lt 7 lw 0.7 lc 0 title "Metà del lato"
replot sqrt(3)*L/2,t lt 7 lw 0.7 lc 0 title "spostamento massimo"


