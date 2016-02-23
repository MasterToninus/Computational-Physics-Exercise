set term postscript eps enhanced color solid rounded
set output 'semplice.eps'

set style data lines 
set xlabel "Tempo [s]"
set ylabel "Theta(t) [gradi]"

plot "semplice" lw 3 
set output

!epstopdf semplice.eps && rm semplice.eps


set output 'smorzato.eps'
plot "smorzato" lw 3 
set output

!epstopdf smorzato.eps && rm smorzato.eps


set output 'forzato.eps'
plot "forzato" lw 3 
set output

!epstopdf forzato.eps && rm forzato.eps

set output 'completo.eps'
plot "completo" lw 3 
set output

!epstopdf completo.eps && rm completo.eps


set output 'pendoli.eps'


set title " Confronto tra Pendoli"
set style data lines 
set xlabel "t: Tempo"
set ylabel "Theta(t) in gradi"

plot "semplice" lw 3 ,"smorzato" lw 3 , "forzato" lw 3 ,"completo" lw 3

set output

!epstopdf pendoli.eps && rm pendoli.eps
