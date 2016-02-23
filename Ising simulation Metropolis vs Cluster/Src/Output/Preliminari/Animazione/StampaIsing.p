## prototipo di plot stato di ising

clear
reset
set size ratio -1

N= 120.0000

set title "colore linee di livello"

set view map
unset surface
set style data pm3d

set xlabel "x" 
set xrange [ 0 : N ] noreverse nowriteback
set ylabel "y" 
set yrange [ 0 : N ] noreverse nowriteback

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'prova0.dat'	

