function k = pitch_acc(x)
% function k = pitch_acc(x)
%
% Returns the lag k for which (x(t)*x(t-k))^2 is the greatest

% Calculate autocorrelation
X = fft(x, length(x)*2);
x_acc = abs(ifft(X .* conj(X)));

%% So far, we have an autocorrelation function
%figure;
%plot(x_acc);

% It is actually unnecessary to keep track of
% x_acc0, but we may want to plot it later.
x_acc0 = zeros(1,floor(length(x_acc)/2));
max_so_far = -100;
max_i = 0;
for i = 20 : floor(length(x_acc0)/3);
  x_acc0(i) = x_acc(i) - x_acc(ceil(i/2));
  if x_acc0(i) > max_so_far
    max_so_far = x_acc0(i);
    max_i = i;
  end;
end


if max_i > 1
    X = [(max_i-1)^2 max_i-1 1;
         max_i^2 max_i 1;
         (max_i+1)^2 max_i+1 1];

    c = inv(X);
    y = [x_acc0(max_i-1); x_acc0(max_i); x_acc0(max_i+1)];
    coef = c * y;
    if coef(1) ~= 0
      max_i = -coef(2)/(2*coef(1));
    end
end


%figure;
%plot(x_acc0);
%hold on;
%plot(max_i, max_so_far, 'ro');
%pause;
k = max_i-1;
