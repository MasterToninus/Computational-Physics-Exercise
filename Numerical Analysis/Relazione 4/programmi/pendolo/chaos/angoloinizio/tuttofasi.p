set term postscript eps enhanced color solid rounded

set style data points
set style function lines 
set xlabel "angolo Theta(t) [rad]" 
set ylabel "velocità angolare Omega(t) [rad/s]"
set pointsize 0.03



set output 'theta_0_fasi.eps'
plot[-pi:pi]  "theta_0_fasi" 
set output
!epstopdf theta_0_fasi.eps && rm theta_0_fasi.eps

set output 'theta_+_fasi.eps'
plot[-pi:pi]  "theta_+_fasi" 
set output
!epstopdf theta_+_fasi.eps && rm theta_+_fasi.eps

set output 'theta_-_fasi.eps'
plot[-pi:pi]  "theta_-_fasi" 
set output
!epstopdf theta_-_fasi.eps && rm theta_-_fasi.eps




set output 'confrontotheta_fasi.eps'

set title "3 traittorie con angolo iniziale variato di 0.005 rad \n CASO CAOTICO" 
set notitle
plot[-pi:pi]  "theta_+_fasi" ,"theta_0_fasi" ,"theta_-_fasi" 
set output

!epstopdf confrontotheta_fasi.eps && rm confrontotheta_fasi.eps







