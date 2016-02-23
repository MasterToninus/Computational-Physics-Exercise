set term postscript eps enhanced color solid rounded

set style data points
set style function lines 
set xlabel "angolo F0(t) [rad]" 
set ylabel "velocitaà angolare Omega(t) [rad/s]"
set pointsize 0.03



set output 'F0_0_fasi.eps'
plot[-pi:pi]  "F0_0_fasi" 
set output
!epstopdf F0_0_fasi.eps && rm F0_0_fasi.eps

set output 'F0_+_fasi.eps'
plot[-pi:pi]  "F0_+_fasi" 
set output
!epstopdf F0_+_fasi.eps && rm F0_+_fasi.eps

set output 'F0_-_fasi.eps'
plot[-pi:pi]  "F0_-_fasi" 
set output
!epstopdf F0_-_fasi.eps && rm F0_-_fasi.eps




set output 'confrontoF0_fasi.eps'

set title "traiettoria di 3 pendoli con forzanti  variate di 0.005  \n CASO CAOTICO" 
set notitle
plot[-pi:pi]  "F0_+_fasi" ,"F0_0_fasi" ,"F0_-_fasi" 
set output

!epstopdf confrontoF0_fasi.eps && rm confrontoF0_fasi.eps







