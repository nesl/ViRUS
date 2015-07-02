f1="prices_64K_1un"
f2="prices_64K_2un"
f3="prices_64K_3un"

set xlabel "Original Result (a.u.)"
set ylabel "Approximate Result (a.u.)"
set yrange [0:30]
set xrange [0:30]
set terminal pdf font 'Helvetica,8'
set key bottom right

set output "blackscholes1.pdf"
plot f1 u  1:2 t 'Quality: 1'
set output "blackscholes2.pdf"
plot f2 u  1:2 t 'Quality: 2'
set output "blackscholes3.pdf"
plot f3 u  1:2 t 'Quality: 3'
