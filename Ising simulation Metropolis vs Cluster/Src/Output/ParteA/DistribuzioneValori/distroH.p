#confronto ditribuzioni raccolta dati H a vari {/Symbol b}
#http://gnuplot.sourceforge.net/demo_4.6/index2.html

clear
reset

set title "ditribuzione delle misure di H/V a vari valori di {/Symbol b}"
set style fill transparent pattern 10 bo border -1

set xlabel "H"
set xrange [-2:0.05]

set ylabel "P(H)"
# set yrange [-2:2]

plot    "distroH_0.dat" title '{/Symbol b} = 0.04' with boxes 
replot	"distroH_1.dat" title '{/Symbol b} = 0.24' with boxes 
replot	"distroH_2.dat" title '{/Symbol b} = 0.42' with boxes 
replot	"distroH_3.dat" title '{/Symbol b} critica' with boxes 
replot	"distroH_4.dat" title '{/Symbol b} = 0.46' with boxes
replot	"distroH_5.dat" title '{/Symbol b} = 0.64' with boxes 
replot	"distroH_6.dat" title '{/Symbol b} = 0.84' with boxes  

