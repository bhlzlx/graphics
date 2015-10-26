##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=scriptEngine
ConfigurationName      :=Debug
WorkspacePath          := "E:\projects\graphics"
ProjectPath            := "E:\projects\graphics\scriptEngine"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=phantom
Date                   :=26/10/2015
CodeLitePath           :="D:\app\CodeLite"
LinkerName             :=F:/tdmgcc/bin/g++.exe
SharedObjectLinkerName :=F:/tdmgcc/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(BuildDir)/$(ProjectName)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="scriptEngine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/tdmgcc/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)F:/tdmgcclib/include $(IncludeSwitch)F:/tdmgcclib/include/freetype $(IncludeSwitch)E:/projects/graphics/ow  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)F:/tdmgcclib/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/tdmgcc/bin/ar.exe rcu
CXX      := F:/tdmgcc/bin/g++.exe
CC       := F:/tdmgcc/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/tdmgcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\app\CodeLite
BuildDir:=E:/projects/builds
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) $(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) $(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) $(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) $(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) $(IntermediateDirectory)/lua_print.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/scriptEngine/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix): lua/lapi.c $(IntermediateDirectory)/lua_lapi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lapi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lapi.c$(DependSuffix): lua/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lapi.c$(DependSuffix) -MM "lua/lapi.c"

$(IntermediateDirectory)/lua_lapi.c$(PreprocessSuffix): lua/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lapi.c$(PreprocessSuffix) "lua/lapi.c"

$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix): lua/lauxlib.c $(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lauxlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix): lua/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix) -MM "lua/lauxlib.c"

$(IntermediateDirectory)/lua_lauxlib.c$(PreprocessSuffix): lua/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lauxlib.c$(PreprocessSuffix) "lua/lauxlib.c"

$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix): lua/lbaselib.c $(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lbaselib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix): lua/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix) -MM "lua/lbaselib.c"

$(IntermediateDirectory)/lua_lbaselib.c$(PreprocessSuffix): lua/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lbaselib.c$(PreprocessSuffix) "lua/lbaselib.c"

$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix): lua/lcode.c $(IntermediateDirectory)/lua_lcode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lcode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lcode.c$(DependSuffix): lua/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lcode.c$(DependSuffix) -MM "lua/lcode.c"

$(IntermediateDirectory)/lua_lcode.c$(PreprocessSuffix): lua/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lcode.c$(PreprocessSuffix) "lua/lcode.c"

$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix): lua/ldblib.c $(IntermediateDirectory)/lua_ldblib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ldblib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldblib.c$(DependSuffix): lua/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldblib.c$(DependSuffix) -MM "lua/ldblib.c"

$(IntermediateDirectory)/lua_ldblib.c$(PreprocessSuffix): lua/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldblib.c$(PreprocessSuffix) "lua/ldblib.c"

$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix): lua/ldebug.c $(IntermediateDirectory)/lua_ldebug.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ldebug.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldebug.c$(DependSuffix): lua/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldebug.c$(DependSuffix) -MM "lua/ldebug.c"

$(IntermediateDirectory)/lua_ldebug.c$(PreprocessSuffix): lua/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldebug.c$(PreprocessSuffix) "lua/ldebug.c"

$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix): lua/ldo.c $(IntermediateDirectory)/lua_ldo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ldo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldo.c$(DependSuffix): lua/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldo.c$(DependSuffix) -MM "lua/ldo.c"

$(IntermediateDirectory)/lua_ldo.c$(PreprocessSuffix): lua/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldo.c$(PreprocessSuffix) "lua/ldo.c"

$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix): lua/ldump.c $(IntermediateDirectory)/lua_ldump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ldump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldump.c$(DependSuffix): lua/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldump.c$(DependSuffix) -MM "lua/ldump.c"

$(IntermediateDirectory)/lua_ldump.c$(PreprocessSuffix): lua/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldump.c$(PreprocessSuffix) "lua/ldump.c"

$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix): lua/lfunc.c $(IntermediateDirectory)/lua_lfunc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lfunc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lfunc.c$(DependSuffix): lua/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lfunc.c$(DependSuffix) -MM "lua/lfunc.c"

$(IntermediateDirectory)/lua_lfunc.c$(PreprocessSuffix): lua/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lfunc.c$(PreprocessSuffix) "lua/lfunc.c"

$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix): lua/lgc.c $(IntermediateDirectory)/lua_lgc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lgc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lgc.c$(DependSuffix): lua/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lgc.c$(DependSuffix) -MM "lua/lgc.c"

$(IntermediateDirectory)/lua_lgc.c$(PreprocessSuffix): lua/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lgc.c$(PreprocessSuffix) "lua/lgc.c"

$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix): lua/linit.c $(IntermediateDirectory)/lua_linit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/linit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_linit.c$(DependSuffix): lua/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_linit.c$(DependSuffix) -MM "lua/linit.c"

$(IntermediateDirectory)/lua_linit.c$(PreprocessSuffix): lua/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_linit.c$(PreprocessSuffix) "lua/linit.c"

$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix): lua/liolib.c $(IntermediateDirectory)/lua_liolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/liolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_liolib.c$(DependSuffix): lua/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_liolib.c$(DependSuffix) -MM "lua/liolib.c"

$(IntermediateDirectory)/lua_liolib.c$(PreprocessSuffix): lua/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_liolib.c$(PreprocessSuffix) "lua/liolib.c"

$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix): lua/llex.c $(IntermediateDirectory)/lua_llex.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/llex.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_llex.c$(DependSuffix): lua/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_llex.c$(DependSuffix) -MM "lua/llex.c"

$(IntermediateDirectory)/lua_llex.c$(PreprocessSuffix): lua/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_llex.c$(PreprocessSuffix) "lua/llex.c"

$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix): lua/lmathlib.c $(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lmathlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix): lua/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix) -MM "lua/lmathlib.c"

$(IntermediateDirectory)/lua_lmathlib.c$(PreprocessSuffix): lua/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lmathlib.c$(PreprocessSuffix) "lua/lmathlib.c"

$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix): lua/lmem.c $(IntermediateDirectory)/lua_lmem.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lmem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lmem.c$(DependSuffix): lua/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lmem.c$(DependSuffix) -MM "lua/lmem.c"

$(IntermediateDirectory)/lua_lmem.c$(PreprocessSuffix): lua/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lmem.c$(PreprocessSuffix) "lua/lmem.c"

$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix): lua/loadlib.c $(IntermediateDirectory)/lua_loadlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/loadlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_loadlib.c$(DependSuffix): lua/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_loadlib.c$(DependSuffix) -MM "lua/loadlib.c"

$(IntermediateDirectory)/lua_loadlib.c$(PreprocessSuffix): lua/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_loadlib.c$(PreprocessSuffix) "lua/loadlib.c"

$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix): lua/lobject.c $(IntermediateDirectory)/lua_lobject.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lobject.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lobject.c$(DependSuffix): lua/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lobject.c$(DependSuffix) -MM "lua/lobject.c"

$(IntermediateDirectory)/lua_lobject.c$(PreprocessSuffix): lua/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lobject.c$(PreprocessSuffix) "lua/lobject.c"

$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix): lua/lopcodes.c $(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lopcodes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix): lua/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix) -MM "lua/lopcodes.c"

$(IntermediateDirectory)/lua_lopcodes.c$(PreprocessSuffix): lua/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lopcodes.c$(PreprocessSuffix) "lua/lopcodes.c"

$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix): lua/loslib.c $(IntermediateDirectory)/lua_loslib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/loslib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_loslib.c$(DependSuffix): lua/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_loslib.c$(DependSuffix) -MM "lua/loslib.c"

$(IntermediateDirectory)/lua_loslib.c$(PreprocessSuffix): lua/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_loslib.c$(PreprocessSuffix) "lua/loslib.c"

$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix): lua/lparser.c $(IntermediateDirectory)/lua_lparser.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lparser.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lparser.c$(DependSuffix): lua/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lparser.c$(DependSuffix) -MM "lua/lparser.c"

$(IntermediateDirectory)/lua_lparser.c$(PreprocessSuffix): lua/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lparser.c$(PreprocessSuffix) "lua/lparser.c"

$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix): lua/lstate.c $(IntermediateDirectory)/lua_lstate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lstate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstate.c$(DependSuffix): lua/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstate.c$(DependSuffix) -MM "lua/lstate.c"

$(IntermediateDirectory)/lua_lstate.c$(PreprocessSuffix): lua/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstate.c$(PreprocessSuffix) "lua/lstate.c"

$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix): lua/lstring.c $(IntermediateDirectory)/lua_lstring.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lstring.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstring.c$(DependSuffix): lua/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstring.c$(DependSuffix) -MM "lua/lstring.c"

$(IntermediateDirectory)/lua_lstring.c$(PreprocessSuffix): lua/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstring.c$(PreprocessSuffix) "lua/lstring.c"

$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix): lua/lstrlib.c $(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lstrlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix): lua/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix) -MM "lua/lstrlib.c"

$(IntermediateDirectory)/lua_lstrlib.c$(PreprocessSuffix): lua/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstrlib.c$(PreprocessSuffix) "lua/lstrlib.c"

$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix): lua/ltable.c $(IntermediateDirectory)/lua_ltable.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ltable.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltable.c$(DependSuffix): lua/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltable.c$(DependSuffix) -MM "lua/ltable.c"

$(IntermediateDirectory)/lua_ltable.c$(PreprocessSuffix): lua/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltable.c$(PreprocessSuffix) "lua/ltable.c"

$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix): lua/ltablib.c $(IntermediateDirectory)/lua_ltablib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ltablib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltablib.c$(DependSuffix): lua/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltablib.c$(DependSuffix) -MM "lua/ltablib.c"

$(IntermediateDirectory)/lua_ltablib.c$(PreprocessSuffix): lua/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltablib.c$(PreprocessSuffix) "lua/ltablib.c"

$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix): lua/ltm.c $(IntermediateDirectory)/lua_ltm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/ltm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltm.c$(DependSuffix): lua/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltm.c$(DependSuffix) -MM "lua/ltm.c"

$(IntermediateDirectory)/lua_ltm.c$(PreprocessSuffix): lua/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltm.c$(PreprocessSuffix) "lua/ltm.c"

$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix): lua/lua.c $(IntermediateDirectory)/lua_lua.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lua.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lua.c$(DependSuffix): lua/lua.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lua.c$(DependSuffix) -MM "lua/lua.c"

$(IntermediateDirectory)/lua_lua.c$(PreprocessSuffix): lua/lua.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lua.c$(PreprocessSuffix) "lua/lua.c"

$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix): lua/lundump.c $(IntermediateDirectory)/lua_lundump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lundump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lundump.c$(DependSuffix): lua/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lundump.c$(DependSuffix) -MM "lua/lundump.c"

$(IntermediateDirectory)/lua_lundump.c$(PreprocessSuffix): lua/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lundump.c$(PreprocessSuffix) "lua/lundump.c"

$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix): lua/lvm.c $(IntermediateDirectory)/lua_lvm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lvm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lvm.c$(DependSuffix): lua/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lvm.c$(DependSuffix) -MM "lua/lvm.c"

$(IntermediateDirectory)/lua_lvm.c$(PreprocessSuffix): lua/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lvm.c$(PreprocessSuffix) "lua/lvm.c"

$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix): lua/lzio.c $(IntermediateDirectory)/lua_lzio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/lzio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lzio.c$(DependSuffix): lua/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lzio.c$(DependSuffix) -MM "lua/lzio.c"

$(IntermediateDirectory)/lua_lzio.c$(PreprocessSuffix): lua/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lzio.c$(PreprocessSuffix) "lua/lzio.c"

$(IntermediateDirectory)/lua_print.c$(ObjectSuffix): lua/print.c $(IntermediateDirectory)/lua_print.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/scriptEngine/lua/print.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_print.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_print.c$(DependSuffix): lua/print.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_print.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_print.c$(DependSuffix) -MM "lua/print.c"

$(IntermediateDirectory)/lua_print.c$(PreprocessSuffix): lua/print.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_print.c$(PreprocessSuffix) "lua/print.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


