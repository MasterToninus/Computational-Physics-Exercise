set term postscript eps enhanced color solid rounded
set output 'caos.eps'

set title "3 traittorie con condizioni iniziali variate di 0.1 gradi \n CASO CAOTICO" 
set style data points
set style function lines 
set xlabel "angolo Theta(t) [rad]" 
set ylabel "velocità angolare Omega(t) [rad/s]"
set pointsize 0.01

plot  "spaziofasi" ,"spaziofasi+" ,"spaziofasi-" 

set output

!epstopdf caos.eps && rm caos.eps





