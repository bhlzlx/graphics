
REG_SCRIPT_BEGIN
	REG_NAMESPACE_BEGIN( std )
		REG_CLASS_BEGIN_EXT( std::vector<int>, "vec_int")
			REG_CLASS_DEFAULT_CONSTRUCTOR
			REG_CLASS_FUNC_EXT( std::vector<int> , push_back, void, const std::vector<int>::value_type& )
			REG_CLASS_FUNC( std::vector<int>, pop_back)
			REG_CLASS_FUNC( std::vector<int>, empty)
			REG_CLASS_FUNC( std::vector<int>, size)
			REG_CLASS_FUNC_EXT( std::vector<int> , at, std::vector<int>::reference , std::vector<int>::size_type )
		REG_CLASS_END
	REG_NAMESPACE_END
	REG_NAMESPACE_BEGIN( ow )
		REG_CLASS_BEGIN_EXT( ow::owBuffer, "owBuffer" )
			REG_CLASS_FUNC( ow::owBuffer, Size)
			REG_CLASS_FUNC( ow::owBuffer, Seek)
			REG_CLASS_FUNC( ow::owBuffer, Read)
			REG_CLASS_FUNC( ow::owBuffer, Write)
			REG_CLASS_FUNC( ow::owBuffer, Resize)
			REG_CLASS_FUNC( ow::owBuffer, Eof)
			REG_CLASS_FUNC( ow::owBuffer, GetCurr)
			REG_CLASS_FUNC( ow::owBuffer, GetBuffer)
			REG_CLASS_FUNC( ow::owBuffer, Release)
		REG_CLASS_END
		REG_FREE_FUNC(CreateMemBuffer)
	REG_NAMESPACE_END
REG_SCRIPT_END