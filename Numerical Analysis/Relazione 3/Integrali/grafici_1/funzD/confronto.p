set term jpeg size 850,350
set output 'confronto.jpg'
set style line 1 lw 1

set style data lines 
set xlabel "Numero di punti valutati"
set ylabel "differenza tra valore ottenuto e valore atteso"

plot[5:100][0:20] "Rettangoli\ Inferiore","Rettangoli\ Superiore","Rettangoli\ Medio" lw 1.7 ,"Trapezi" lw 1.7 ,"Simpson" lw 1.7 ,"MultiGaussordine5" lw 1.7 ,"MultiGaussordine10" lw 1.7 ,"MultiGaussordine20" lw 1.7 




