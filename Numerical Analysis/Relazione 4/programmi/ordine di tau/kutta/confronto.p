set term postscript eps enhanced color solid rounded
set output 'kut.eps'

set key top left
set title " Errore Metodo R-K 4^"
set style data lines 
set xlabel "Numero di iterazioni"
set ylabel "Dispersione dal Valore Atteso"

plot[0:1500][-0.000005:0.0001] "lineare" lw 3.0 ,"quadratico" lw 3.0 ,"cubico" lw 3.0,"quarto" lw 3.0,"quinto" lw 3.0

!epstopdf kut.eps && rm kut.eps
