set xlabel "N : Numero di lanci"
set ylabel "Errore"
set term jpeg
set output 'confronto.jpg'      
f(x)=A*x**B       
fit f(x) 'ago_2.txt' using 1:2  via A,B
plot f(x)
replot 1/(2*x)
