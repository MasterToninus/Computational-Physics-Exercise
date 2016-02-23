#confronto ditribuzioni raccolta dati H a vari beta
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

set title "ditribuzione delle misure di |M|/V (improved) a vari valori di beta"
set style fill transparent pattern 10 bo border -1
unset border

set xlabel "|M|/V"
# set xrange [0:5]

set ylabel "P(|M|)"
# set yrange [-2:2]

plot    "distroM_0.dat" title 'beta = 0.04' with boxes 
replot	"distroM_1.dat" title 'beta = 0.24' with boxes 
replot	"distroM_2.dat" title 'beta critica' with boxes 
replot	"distroM_3.dat" title 'beta = 0.64' with boxes 
replot	"distroM_4.dat" title 'beta = 0.84' with boxes 

