set term postscript eps enhanced color solid rounded

set style data points
set style function lines 
set xlabel "angolo Theta(t) [rad]" 
set ylabel "velocità angolare Omega(t) [rad/s]"
set pointsize 0.08



set output 'F0_alta_fasi.eps'
plot[-pi:pi]  "F0_alta_+_fasi" , "F0_alta_fasi" , "F0_alta_-_fasi" 
set output
!epstopdf F0_alta_fasi.eps && rm F0_alta_fasi.eps

set notitle
set output 'F0_caos_fasi.eps'
plot[-pi:pi]  "F0_caos_fasi" 
set output
!epstopdf F0_caos_fasi.eps && rm F0_caos_fasi.eps

set output 'F0_bassa_fasi.eps'
plot[-pi/8:pi/8]  "F0_bassa_+_fasi" , "F0_bassa_fasi" , "F0_bassa_-_fasi"
set output
!epstopdf F0_bassa_fasi.eps && rm F0_bassa_fasi.eps




set output 'confrontoF0_fasi.eps'

set notitle
plot[-pi:pi]  "F0_alta_fasi" ,"F0_caos_fasi" ,"F0_bassa_fasi" 
set output

!epstopdf confrontoF0_fasi.eps && rm confrontoF0_fasi.eps







