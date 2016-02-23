set term postscript eps enhanced color solid rounded "Helvetica" 8

set output 'confronto.eps'

unset title
set key
set xlabel "x0"
set ylabel  "xn"
set style data  lines
plot[0.4:0.9]   "n=1", "n=2", "n=3", "n=4", x ls -0


set output
!epstopdf confronto.eps && rm confronto.eps
