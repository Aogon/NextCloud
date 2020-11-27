#!/usr/bin/gnuplot -persist

set logscale
set xlabel 'N'
set ylabel 'N!'

plot './factorial.dat' u 1:2 t 'log N!' w l

pause -1
#unset logscale


set ylabel '(log(N!)-(NlogN-N))/log(N!)'

plot'./factorial.dat' u 1:(abs(log($2)-($1*log($1)-$1))/log($2)) not w l

pause -1


#    EOF
