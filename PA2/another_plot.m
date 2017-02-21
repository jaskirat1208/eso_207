close all; %close any previous figures 

fid=fopen("output_nearly_bal.txt"); % TODO: check if fid is -1 and give error 
line=0; %for storing the string value of each line of the file 

data=zeros(2,2); %will be faster if we know how many lines are in file 
%as this array will not have to be resized by octave 

line_i=1; 
while (-1 ~= (line=fgetl(fid))) 
        data(line_i++,:)=str2num(line); 
end 

fclose(fid); 

%displays data 
data 

plot(data(:,1),data(:,2)) 