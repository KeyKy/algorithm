function [ ] = smoSolver( designMatrix, targetGroup )
numChanged = 0;
examineAll = 1;
n_samps = size(designMatrix,1);
kernelMatrix = zeros(n_samps, n_samps);
for i = 1 : n_samps
    for j = i : n_samps
        kernelMatrix(i,j) = dot(designMatrix(i,:), designMatrix(j,:));
        kernelMatrix(j,i) =  kernelMatrix(i,j);
    end
end
alphaArray = zeros(1, n_samps);
C = 1; b = 0;
u = alphaArray .* targetGroup * kernelMatrix - b;
E = u - targetGroup;
iter = 1 ;
while(numChanged > 0 || examineAll)
    numChanged = 0;
    if(examineAll)
        for i = 1 : n_samps
            numChanged = numChanged + examineExample(i);
        end
    else
        for i = 1 : n_samps
            if abs(alphaArray(i)) > 0.01 && abs(alphaArray(i)-C) > 0.01
                numChanged = numChanged + examineExample(i);
            end
        end
    end
    if(examineAll == 1)
        examineAll = 0;
    elseif (numChanged == 0)
        examineAll = 1;
    end
    iter = iter + 1;
    if iter > 2000
        ii = 1;
    end
    if iter > 5000
        break;
    end
end

function changed = examineExample(i)
    y2 = targetGroup(i);
    alpha2 = alphaArray(i);
    E2 = E(i);
    r2 = E2 * y2;
    if((r2 < -0.01 && alpha2 < C) || (r2 > 0.01 && alpha2 > 0))
        non_zero_non_c = find(abs(alphaArray)>0.01 & abs(alphaArray-C)>0.01);
        if length(non_zero_non_c) > 1
            maxIdx = 1; max = 0;
            for idx = 1 : n_samps
                if abs(E(idx) - E2) > max
                    max = abs(E(idx) - E2);
                    maxIdx = idx;
                end
            end
            if takeStep(maxIdx, i)
                changed = 1; return;
            end
        end
        
        for k = 1 : length(non_zero_non_c)
            i1 = non_zero_non_c(k);
            if takeStep(i1, i);
                changed = 1; return;
            end
        end
        
        for k = 1 : n_samps
            if takeStep(k, i)
                changed = 1; return;
            end
        end
    end
    changed = 0; return;
end

function tf = takeStep(i1, i2)
if i1 == i2
    tf = 0; return;
end

alpha1 = alphaArray(i1); a1 = 0;
alpha2 = alphaArray(i2); a2 = 0;
y1 = targetGroup(i1); y2 = targetGroup(i2);
E1 = E(i1); E2 = E(i2);
s = y1 * y2;
if s > 0
    L = max([0,alpha1+alpha2-C]);
    H = min([C,alpha1+alpha2]);
else
    L = max([0,alpha2-alpha1]);
    H = min([C, C+alpha2-alpha1]);
end

if L == H
    tf = 0; return;
end
k11 = kernelMatrix(i1,i1);
k12 = kernelMatrix(i1,i2);
k22 = kernelMatrix(i2,i2);
eta = k11 + k22 - 2*k12;
if(eta > 0)
    a2 = alpha2 + y2 * (E1-E2)/eta; 
    if(a2 < L) 
        a2 = L;
    elseif (a2 > H)
        a2 = H;
    end
else
    a2 = L;
    a1 = alpha1 + s*(alpha2-a2);
    alphaArrayTmp = alphaArray; alphaArrayTmp(i1) = a1; alphaArrayTmp(i2) = a2;
    alphaArrayTmp = alphaArrayTmp .* targetGroup;
    Lobj = alphaArrayTmp * kernelMatrix * alphaArrayTmp' - sum(alphaArrayTmp);
    
    a2 = H;
    a1 = alpha1 + s*(alpha2-a2);
    alphaArrayTmp = alphaArray; alphaArrayTmp(i1) = a1; alphaArrayTmp(i2) = a2;
    alphaArrayTmp = alphaArrayTmp .* targetGroup;
    Hobj = alphaArrayTmp * kernelMatrix * alphaArrayTmp' - sum(alphaArrayTmp);
    if(Lobj < Hobj - 0.01)
        a2 = L;
    elseif(Lobj > Hobj + 0.01)
        a2 = H;
    else
        a2 = alpha2;
    end
end
if (abs(a2-alpha2) < 0.01*(a2+alpha2+0.01))
    tf = 0; return;
end

a1 = alpha1 + s*(alpha2-a2);

b1 = E1 + y1*(a1 - alpha1)*kernelMatrix(i1,i1)+y2*(a2 - alpha2)*kernelMatrix(i1,i2)+b;
b2 = E2 + y1*(a1 - alpha1)*kernelMatrix(i1,i2)+y2*(a2 - alpha2)*kernelMatrix(i2,i2)+b;
if(a1 > 0 && a1 < C)
    b = b1;
elseif(a2 > 0 && a2 < C)
    b = b2;
else
    b = (b1+b2)/2;
end
alphaArray(i1) = a1; alphaArray(i2) = a2;

u = alphaArray .* targetGroup * kernelMatrix - b;
E = u - targetGroup;

tf = 1; return;
end

u = alphaArray .* targetGroup * kernelMatrix - b;
E = u - targetGroup;
end
