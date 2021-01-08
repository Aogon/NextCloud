set title 'Monte Carlo method for caluclating Integral'
set xlabel 'I'
set ylabel 'Probability Density'
set xrange[-5:5]
set yrange[0:0.6]
plot 'report4-3-3.dat' index 0 u 2:3 title 'N = 100' with boxes, 'report4-3-3.dat' index 1 u 2:3 title 'N = 1000' with boxes, 'report4-3-3.dat' index 2 u 2:3 title 'N = 10000' with boxes, 'report4-3-3.dat' index 3 u 2:3 title 'N = 100000' with boxes, exp(-(x**2)/2)/sqrt(2*pi)