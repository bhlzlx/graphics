
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
REG_SCRIPT_END