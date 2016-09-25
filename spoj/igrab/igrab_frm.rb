hash_col={0=>0,1=>1,2=>2,3=>5,4=>6,5=>8,6=>9,7=>10}
input=gets.to_i
input.times do |i|
	input1=gets.to_i
	div=input1/7
	rem=input1%7
	puts hash_col[rem].to_i+10*div
end