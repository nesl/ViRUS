f0=load("prices_64K_0.txt")(2:end);
f1=load("prices_64K_1.txt")(2:end);
f2=load("prices_64K_2.txt")(2:end);
f3=load("prices_64K_3.txt")(2:end);

rmse1 = sqrt(sum((f0-f1).^2)/length(f0));
rmse2 = sqrt(sum((f0-f2).^2)/length(f0));
rmse3 = sqrt(sum((f0-f3).^2)/length(f0));

rmsen1 = rmse1/(max(f0)-min(f0))*100
rmsen2 = rmse2/(max(f0)-min(f0))*100
rmsen3 = rmse3/(max(f0)-min(f0))*100


