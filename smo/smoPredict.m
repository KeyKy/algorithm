function [ targetGroup ] = smoPredict( model, designMatrix )
n_samps = size(designMatrix, 1);
n_sup_samps = size(model.supVec, 1);
targetGroup = zeros(n_samp, 1);
kernelMatrix = zeros(n_samps, n_sup_samps);
for i = 1 : n_samps
    for j = 1 : n_sup_samps
        kernelMatrix(i,j) = 
    end
    
end

end

