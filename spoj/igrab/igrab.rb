repeattimes=gets.to_i
arr=[1,2,5,9,8,6,10,11]

@inversed={0=>0,1=>1,2=>2,5=>5,6=>9,8=>8,9=>6}

def checkAndReturn(num)
	# is number has inverse valid or not and if present return the valid inverted value
	rem=0
	div=num
	temp=""
while div!=0
	rem=div%10
	if @inversed.has_key?(rem.to_i) ==true
		temp= @inversed[rem].to_s + temp
	else return -1;
	end
	#print rem, " replaced ",@inversed[rem.to_i],"\n"
	div=div/10
end
	return temp
end

repeattimes.times{ |i|
input=gets.to_i

if input<=arr.length
	puts input," : ",arr[input-1],"\n"
else count=arr.length
	lastvalue=arr[-1]
	while arr.length<input
		lastvalue=lastvalue+1
		if (temp1 = checkAndReturn(lastvalue) )!= -1
			count=count+1
			arr[count-1]=temp1.to_i
		end
	end

	print input," : ",arr[-1].to_s.reverse,"\n"

end

#puts arr.inspect
}
