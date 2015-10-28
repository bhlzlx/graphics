
REG_SCRIPT_BEGIN
	REG_NAMESPACE_BEGIN( std )
		REG_CLASS_BEGIN_EXT( std::vector<int>, "vec_int")
			REG_CLASS_DEFAULT_CONSTRUCTOR
			REG_CLASS_FUNC_EXT( std::vector<int> , push_back, void, const int& )
			REG_CLASS_FUNC( std::vector<int>, pop_back)
			REG_CLASS_FUNC( std::vector<int>, empty)
			REG_CLASS_FUNC( std::vector<int>, size)
			REG_CLASS_FUNC_EXT( std::vector<int> , at, std::vector<int>::reference , std::vector<int>::size_type )
		REG_CLASS_END
	REG_NAMESPACE_END
	REG_NAMESPACE_BEGIN( ow )
		REG_CLASS_BEGIN_EXT( ow::MemBuffer, "MemBuffer")
			REG_CLASS_FUNC( ow::MemBuffer, Size)
			REG_CLASS_FUNC( ow::MemBuffer, Seek)
			REG_CLASS_FUNC( ow::MemBuffer, Read)
			REG_CLASS_FUNC( ow::MemBuffer, Write)
			REG_CLASS_FUNC( ow::MemBuffer, Resize)
			REG_CLASS_FUNC( ow::MemBuffer, Eof)
			REG_CLASS_FUNC( ow::MemBuffer, GetCurr)
			REG_CLASS_FUNC( ow::MemBuffer, GetBuffer)
			REG_CLASS_FUNC( ow::MemBuffer, Release)
		REG_CLASS_END
		REG_FREE_FUNC(CreateMemBuffer)
	REG_NAMESPACE_END
REG_SCRIPT_END