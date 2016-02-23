set term postscript eps enhanced color solid rounded
set output 'cor.eps'

set key top left
set title " Errore Metodo Correttore"
set style data lines 
set xlabel "Numero di iterazioni"
set ylabel "Dispersione dal Valore Atteso"

plot[0:50][-0.0001:0.0015] "lineare" lw 3 ,"quadratico" lw 3 ,"cubico" lw 3

set output

!epstopdf cor.eps && rm cor.eps
