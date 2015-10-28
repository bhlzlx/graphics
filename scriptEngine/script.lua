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

function script_MemBufferSize( _memBuffer )
	return _memBuffer:Size();
end

function script_MemBufferResize( _memBuffer, _size )
	_memBuffer:Resize(_size);
end

function script_MemBufferWrite( _memBuffer, _data, _len )
	_memBuffer:Write(_data, _len);
end
