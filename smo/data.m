function [ output_args ] = data( input_args )
fid = fopen('C:\Users\ky\Desktop\1.txt');
targetGroup = [];
designMatrix = [];
while ~feof(fid)
    line = fgetl(fid);
    splited = splitStr(line,' ');
    targetGroup = [targetGroup; str2num(splited{1})];
    designMatrix = [designMatrix ;[str2num(splited{2}(3:end)), str2num(splited{3}(3:end))]];
end
fclose(fid);
for i = 1 : length(targetGroup)
    if(targetGroup(i) == 1)
        plot(designMatrix(i,1),designMatrix(i,2),'r.'); hold on;
    else
        plot(designMatrix(i,1),designMatrix(i,2),'b.'); hold on;
    end
end

end

