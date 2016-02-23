set term postscript eps enhanced color solid rounded
set output 'eul.eps'

set key top left
set title " Errore Metodo Eulero"
set style data lines 
set xlabel "Numero di iterazioni"
set ylabel "Dispersione dal Valore Atteso"

plot[0:80][-0.1:1.2] "lineare" lw 1.7 ,"quadratico" lw 1.7 ,"cubico" lw 1.7
set output

!epstopdf eul.eps && rm eul.eps
