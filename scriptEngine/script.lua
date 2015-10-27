function script_VoidFunction()
	print "VoidFunction"
end

function script_GetIntValue()
	return 100;
end
function script_GetFloatValue()
	return 1.6666;
end
function script_GetStringValue()
	return "Hello,World!"
end

function script_VoidParam1( value )
	print("passed value is : "..value);
end

function script_Param1( value )
	return value + 1;
end

function script_MemBufferRet()
	local memBuffer = ow.CreateMemBuffer(1024);
	memBuffer:Release();
	memBuffer:Resize(2046);
	--[[
	local str = "Hello,World!";
	local len = 13;
	memBuffer:Write(str, 13);
	return memBuffer;
	]]
end

function script_MemBufferRelease( memBuffer )
	memBuffer:Release();
end
