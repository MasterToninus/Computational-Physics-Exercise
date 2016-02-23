
set style data dots
set xlabel "parametro r"
set ylabel "Xn"
set notitle


unset ytics 
set xtics 0.01
unset mxtics

set grid
 

plot"n=1000","n=5000","n=25000","n=100000"
