function Ti = Heatimplicit(len)
    %parameter
    df = 9.88 * 10 ^(-5);
    dt = 0.01;
    b = 62.5;
    t = 1000000;
    k = 240;
    h = 25;
    A_cro = 0.02 * 0.004;
    
    Ta = 25;

    dx = len/40;
    
    beta = df * dt / (dx^2);

    Ti=zeros(40,length(t));
    
    %initial conditon
    for i = 1 : 40
        Ti(i,1) = 25;
    end

    %boundary condition
    for i = 1 : t
        Ti(1, i) = 100;
    end

    %coefficient matrix 
    % AX = Y
    
    A = zeros(39, 39);

    for i = 1 : 38
        A(i, i) = -2 * beta - b * df * dt - 1;
        A(i, i+1) = beta;
        A(i+1, i) = beta;
    end

    A(39, 39) = - beta - 1 - df * dt * (b + h / (k * dx));

    %inverse the matrix
    Ainv = inv(A);

    for i = 1 : t-1

        Y = zeros(39, 1);
        Y(1) = -b * df * dt * Ta - Ti(2, i) - beta * Ti(1, i+1);

        for j = 2: 38
            Y(j) = -b * df * dt * Ta - Ti(j+1, i);
        end

        Y(39) = -Ti(40, i) - df * dt * ((b + h / (k * dx)) * Ta);

        X = Ainv * Y;

        for j = 1 : 39
            Ti(j+1, i+1) = X(j);
        end

    end
    
    % threshold (when to stop)
    if max(Ti(:, i+1) - Ti(:, i)) < 0.01 ^ 2
        Ti = Ti(:, 1:i);
        return
    end
    
end