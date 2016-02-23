set xlabel "N : Numero di lanci"
set ylabel "Errore"
set term jpeg
set output 'ago_2.jpg'      
plot "ago_2.txt"
f(x)=A*x**B       
fit f(x) 'ago_2.txt' using 1:2  via A,B
replot f(x)
