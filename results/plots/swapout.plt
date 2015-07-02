f1="swaptionsout.txt"

set xlabel "Original Result (a.u.)"
set ylabel "Approximate Result (a.u.)"
set yrange [0:300]
set xrange [0:300]
set terminal pdf font 'Helvetica,8'
set key bottom right

set output "swap1.pdf"
plot f1 u  1:2 t 'Quality: 1'
set output "swap2.pdf"
plot f1 u  1:3 t 'Quality: 2'
set output "swap3.pdf"
plot f1 u  1:4 t 'Quality: 3'
