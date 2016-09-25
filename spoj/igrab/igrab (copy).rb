repeattimes=gets.to_i
inversed={1=>1,2=>2,5=>5,6=>9,8=>8,9=>6}
repeattimes.times{ |i|
input=gets.to_i
rem=0
div=input
temp=""
while div!=0
	rem=div%10
	if inversed.has_key?(rem)
		temp=inversed[rem].to_s+temp
	else temp=rem.to_s+temp
	end
	#print rem, " replaced ",inversed[rem.to_i],"\n"
	div=div/10
end
puts temp 
}