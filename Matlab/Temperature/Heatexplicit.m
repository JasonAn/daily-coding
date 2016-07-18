function [Qs, Te] = Heatexplicit(len)
%parameter
df = 9.88 * 10 ^(-5);
dt = 0.01;
b = 62.5;
t = 1000000;
k = 240;
h = 25;
A_cro = 0.02 * 0.004;
Ta = 25;

dx = len / 40;
Te=zeros(40,length(t));

%initial condition
for i = 1 : 40
    Te(i,1) = 25;
end

%boundary condition
for i = 1 : t
    Te(1, i) = 100;
end

%dynamic equation
for i = 1 : t-1
    for j = 2 : 39
        dT = (Te(j+1,i) - 2 * Te(j,i)  + Te(j-1,i))/(dx)^2;
        Te(j,i+1) = Te(j,i) +  df * dt * (dT - b *(Te(j,i) - Ta));
    end

    dT = -(Te(40,i) - Te(39, i))/(dx^2) - (b + h / (k * dx))*(Te(40, i) - Ta);
    Te(40,i+1) = Te(40,i) +  df * dt * dT;
    
    %total heat dissipation
    Qs = - k * A_cro * (- Te(3, i) + 4 * Te(2, i) - 3 * Te(1, i)) / (2 * dx);
    
    % threshold (when to stop)
    if max(Te(:, i+1) - Te(:, i)) < 0.01 ^ 2
        Te = Te(:, 1:i);
        return
    end

end


end