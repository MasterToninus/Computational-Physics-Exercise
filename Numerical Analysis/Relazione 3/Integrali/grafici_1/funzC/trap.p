set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Trapezi"
f(x)=A+B*x**(-C)
fit f(x) 'Trapezi' using 1:2 via A,B,C
replot f(x)



