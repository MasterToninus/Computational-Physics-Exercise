set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Trapezi"
f(x)=A*(1/x)+B*(1/x**2)+C*(1/x**0.5)
fit f(x) 'Trapezi' using 1:2 via A,B,C
replot f(x)



