set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "frequenza " 
set ylabel "modulo della trasformata" 
set pointsize 0.08


set output 'gaussiana.eps'
set title "Trasformata fourier Gaussiana" 
set notitle
plot  "gaussiana" ls 7
set output
!epstopdf gaussiana.eps && rm gaussiana.eps

set output 'gradino.eps'
set title "Trasformata fourier Gradino" 
set notitle
plot  "gradino" ls 8
set output
!epstopdf gradino.eps && rm gradino.eps

set output 'sinusoidale.eps'
set title "Trasformata fourier composizione di seni" 
set notitle
plot  "sinusoidale"
set output
!epstopdf sinusoidale.eps && rm sinusoidale.eps
