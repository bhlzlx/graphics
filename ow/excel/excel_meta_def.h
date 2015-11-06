

TB_DEF_BEGIN( Users )
TB_DEF_VAR( int, iID )
TB_DEF_VAR( char*, szName)
TB_DEF_VAR( int, bSex)
TB_DEF_VAR( char*, szComment)
TB_DEF_END()

TB_DEF_BEGIN( Authors )
TB_DEF_VAR( int, nID )
TB_DEF_VAR( char*, szName)
TB_DEF_VAR( int, bSex)
TB_DEF_VAR( int, iAge)
TB_DEF_END()

TB_DEF_BEGIN( Preference )
TB_DEF_VAR( int, nID)
TB_DEF_VAR( int, iValue)
TB_DEF_VAR( float, fValue)
TB_DEF_END()

