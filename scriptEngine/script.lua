
function trace()
	local obj = Object();
	obj.m_type = 1;
	obj:trace();
	print("trace from script!");
end