#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

#set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 10 bo border -1
unset border

set xlabel "Libero Cammino [L]"
	set xrange [0:0.05]

set ylabel "P(L)"
# set yrange [-2:2]

plot    "DistroLC_0.dat" title '{/Symbol h} = 0.72' with boxes 
replot	"DistroLC_1.dat" title '{/Symbol h} = 0.62' with boxes 
replot	"DistroLC_2.dat" title '{/Symbol h} = 0.52' with boxes 
replot	"DistroLC_3.dat" title '{/Symbol h} = 0.42' with boxes 
replot	"DistroLC_4.dat" title '{/Symbol h} = 0.32' with boxes 

