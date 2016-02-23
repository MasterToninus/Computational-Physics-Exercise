set term postscript eps enhanced color solid rounded

set style data points
set style function lines 
set xlabel "angolo Theta(t) [rad]" 
set ylabel "velocità angolare Omega(t) [rad/s]"
set pointsize 0.03



set output 'omega_0_fasi.eps'
plot[-pi:pi]  "omega_0_fasi" 
set output
!epstopdf omega_0_fasi.eps && rm omega_0_fasi.eps

set output 'omega_+_fasi.eps'
plot[-pi:pi]  "omega_+_fasi" 
set output
!epstopdf omega_+_fasi.eps && rm omega_+_fasi.eps

set output 'omega_-_fasi.eps'
plot[-pi:pi]  "omega_-_fasi" 
set output
!epstopdf omega_-_fasi.eps && rm omega_-_fasi.eps




set output 'confrontoomega_fasi.eps'

set title "traiettoria di 3 pendoli con frequenza delle forzanti  variate di 0.0005 N  \n CASO CAOTICO" 
set notitle
plot[-pi:pi]  "omega_+_fasi" ,"omega_0_fasi" ,"omega_-_fasi" 
set output

!epstopdf confrontoomega_fasi.eps && rm confrontoomega_fasi.eps







