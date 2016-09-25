input=gets.to_i

input.times do |i|
  input1=gets.to_i
	hash_col={0=>0,1=>1,2=>2,3=>5,4=>9,5=>8,6=>6,7=>0}

	div=input1
	rem=input1

	ans=""

	while div!=0
		rem=div%7
		ans=ans+rem.to_s
		div=div/7
	end

	ans.each_char do|j,char|
		print hash_col[j.to_i]
	end
	puts ""
end