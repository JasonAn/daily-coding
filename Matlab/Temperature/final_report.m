clear;

%call Explicit function
[Qs, Te] = Heatexplicit(0.5);

%generate three figures
figure
plot(Te(:, 5),  'LineWidth', 2);
title('Temperature distribution after 5 step, explicit');
xlabel('Grid');
ylabel('Temperature');

figure
plot(Te(:, floor(end/2)),  'LineWidth', 2);
title('Temperature distribution in the middle of process, explicit');
xlabel('Grid');
ylabel('Temperature');

figure
plot(Te(:, end),  'LineWidth', 2);
title('Temperature distribution at the stable state, explicit');
xlabel('Grid');
ylabel('Temperature');

%time_e is the time needed to approach the steady state
%Qs is the total heat being dissipated
d = size(Te);
time_e = d(2);



%call implicit function
Ti = Heatimplicit(0.5);

%generate three figures
figure
plot(Te(:, 5),  'LineWidth', 2);
title('Temperature distribution after 5 step, implicit');
xlabel('Grid');
ylabel('Temperature');

figure
plot(Te(:, floor(end/2)),  'LineWidth', 2);
title('Temperature distribution in the middle of process, implicit');
xlabel('Grid');
ylabel('Temperature');

figure
plot(Te(:, end),  'LineWidth', 2);
title('Temperature distribution at the stable state, implicit');
xlabel('Grid');
ylabel('Temperature');

%time_i is the time needed to approach the steady state
d = size(Ti);
time_i = d(2);

%find the optimal length

for i = 1 : 20
    len = 0.1 + 0.05 * i;
    [Q(i), T_temp] = Heatexplicit(len);
    Cost(i) = Q(i) * 1.68 - 0.02 * 0.004 * len * 2700 * 3.27;
end

%the optimal length is 0.1 + 0.05 * 7 = 0.45



%make the Animation

figure
%axis tight manual

for t = 1: time_e
    xlabel('Grid');
    ylabel('Temperature Distribution');
    plot(Te(:,t),'-','LineWidth', 2);
    %drawnow
    %set(gca,'xdir','reverse');
    %set(gca,'ydir','reverse');
    M(t)=getframe(gcf);
end

movie2avi(M, 'Temperature.avi', 'compression', 'None');


    






