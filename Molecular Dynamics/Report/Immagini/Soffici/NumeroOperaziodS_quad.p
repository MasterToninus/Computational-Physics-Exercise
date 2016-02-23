Nconfigurazioni = 2000
Nparticelle = 256

f(x)= Nparticelle*x*(Nconfigurazioni - x +1)
set xlabel "Nstep"
set ylabel "Noperazioni"
plot[0:Nconfigurazioni] f(x)

