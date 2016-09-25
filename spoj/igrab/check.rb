arr=[1,2,5,9,8,6,10,11]

@inversed={1=>1,2=>2,5=>5,6=>9,8=>8,9=>6}

def checkAndReturn(num)
	# is number has inverse valid or not and if present return the valid inverted value
	rem=0
	div=num
	temp=""
while div!=0
	rem=div%10
	if @inversed.has_key?(rem.to_i) ==true
		temp=@inversed[rem].to_s + temp
	else return -1;
	end
	#print rem, " replaced ",inversed[rem.to_i],"\n"
	div=div/10
end
	return temp
end

puts checkAndReturn(6912)

