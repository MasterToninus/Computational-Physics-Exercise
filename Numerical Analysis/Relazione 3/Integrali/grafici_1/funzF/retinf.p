set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "Rettangoli\ Inferiore"
f(x)=A+x**(-B)
fit f(x) 'Rettangoli Inferiore' using 1:2 via A,B
replot f(x)

